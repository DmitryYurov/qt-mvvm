#include "MockWidgets.h"
#include "compounditem.h"
#include "google_test.h"
#include "itemmapper.h"
#include "sessionitem.h"
#include "sessionmodel.h"

using namespace ModelView;
using ::testing::_;

class TestItemMapper : public ::testing::Test
{
public:
    ~TestItemMapper();
};

TestItemMapper::~TestItemMapper() = default;

//! Check that mapper works only in model context.

TEST(TestItemMapper, initialState)
{
    // item outside model context can't have a mapper
    std::unique_ptr<SessionItem> item = std::make_unique<SessionItem>();
    EXPECT_THROW(item->mapper(), std::runtime_error);

    // item in model context does have a mapper
    SessionModel model;
    auto item2 = model.insertItem<SessionItem>(model.rootItem(), "", 0);
    EXPECT_NO_THROW(item2->mapper());
}

//! Destroying item, expecting single call of onItemDestroy in MockWidget.

TEST(TestItemMapper, onItemDestroy)
{
    SessionModel model;
    auto item = model.insertItem<SessionItem>(model.rootItem(), "", 0);

    MockWidgetForItem widget(item);

    auto expected_item = item;
    EXPECT_CALL(widget, onItemDestroy(expected_item)).Times(1);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // performing action
    model.removeItem(model.rootItem(), "",  0);
}

//! Setting data to item, expecting onDataChange callback.

TEST(TestItemMapper, onDataChange)
{
    SessionModel model;
    auto item = model.insertItem<SessionItem>(model.rootItem(), "", 0);

    MockWidgetForItem widget(item);

    auto expected_role = ItemDataRole::DATA;
    auto expected_item = item;
    EXPECT_CALL(widget, onDataChange(expected_item, expected_role)).Times(1);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform action
    item->setData(42.0);
}

//! Setting same data to item, expecting no callbacks on onDataChange.

TEST(TestItemMapper, onDataChangeDuplicate)
{
    SessionModel model;
    auto item = model.insertItem<SessionItem>(model.rootItem(), "", 0);

    MockWidgetForItem widget(item);

    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(1);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform actions, only one call should be triggered
    item->setData(42.0);
    item->setData(42.0); // same data
}

//! Setting mapper activity to false, change the data, expect no callbacks.

TEST(TestItemMapper, setActivity)
{
    SessionModel model;
    auto item = model.insertItem<SessionItem>(model.rootItem(), "", 0);

    MockWidgetForItem widget(item);

    item->mapper()->setActive(false);

    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform actions, no calls should be triggered
    item->setData(42.0);
}

//! Unsubscribing from item, expecting no callbacks.

TEST(TestItemMapper, unsubscribe)
{
    SessionModel model;
    auto item = model.insertItem<SessionItem>(model.rootItem(), "", 0);

    MockWidgetForItem widget1(item);
    MockWidgetForItem widget2(item);

    item->mapper()->unsubscribe(&widget1);

    EXPECT_CALL(widget1, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget2, onDataChange(_, _)).Times(1);

    // perform action, only one widget should be triggered
    item->setData(42.0);
}

//! Changing item property.

TEST(TestItemMapper, onPropertyChange)
{
    SessionModel model;
    auto item = model.insertItem<CompoundItem>();
    EXPECT_TRUE(item != nullptr);

    auto property = item->addProperty<PropertyItem>("height", 42.0);

    MockWidgetForItem widget(item);

    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(item, "height")).Times(1);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform action
    item->setProperty("height", 43.0);
    EXPECT_EQ(item->property("height"), 43.0);
    EXPECT_EQ(property->data().toDouble(), 43.0);
}

//! Changing item property.

TEST(TestItemMapper, onChildPropertyChange)
{
    SessionModel model;
    auto compound1 = model.insertItem<CompoundItem>();
    compound1->registerTag(TagInfo::universalTag("tag1"), /*set_as_default*/true);
    auto compound2 = model.insertItem<CompoundItem>(compound1);

    auto property = compound2->addProperty<PropertyItem>("height", 42.0);

    MockWidgetForItem widget(compound1);

    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(compound2, "height")).Times(1);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform action
    compound2->setProperty("height", 43.0);
    EXPECT_EQ(compound2->property("height"), 43.0);
    EXPECT_EQ(property->data().toDouble(), 43.0);
}

//! Inserting item to item.

TEST(TestItemMapper, onRowInsert)
{
    SessionModel model;
    auto compound1 = model.insertItem<CompoundItem>();
    compound1->registerTag(TagInfo::universalTag("tag1"), /*set_as_default*/true);

    MockWidgetForItem widget(compound1);

    const int expected_row = 0;
    std::string expected_tag = "tag1";
    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(compound1, expected_tag, expected_row)).Times(1);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(_, _, _)).Times(0);

    // perform action
    model.insertItem<CompoundItem>(compound1, expected_tag, expected_row);
}

//! Inserting item to item.

TEST(TestItemMapper, onRowAboutToRemove)
{
    const int expected_row = 0;
    std::string expected_tag = "tag1";

    SessionModel model;
    auto compound1 = model.insertItem<CompoundItem>();
    compound1->registerTag(TagInfo::universalTag("tag1"), /*set_as_default*/true);
    model.insertItem<CompoundItem>(compound1, expected_tag, expected_row);

    MockWidgetForItem widget(compound1);

    EXPECT_CALL(widget, onItemDestroy(_)).Times(0);
    EXPECT_CALL(widget, onDataChange(_, _)).Times(0);
    EXPECT_CALL(widget, onPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onChildPropertyChange(_, _)).Times(0);
    EXPECT_CALL(widget, onRowInserted(_, _, _)).Times(0);
    EXPECT_CALL(widget, onRowAboutToBeRemoved(compound1, expected_tag, expected_row)).Times(1);

    // perform action
    model.removeItem(compound1, expected_tag, expected_row);
}
