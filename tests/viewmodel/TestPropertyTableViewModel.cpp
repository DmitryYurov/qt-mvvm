#include "google_test.h"
#include "propertytableviewmodel.h"
#include "sessionmodel.h"
#include "sessionitem.h"
#include "propertyitem.h"
#include "taginfo.h"
#include "vectoritem.h"

using namespace ModelView;

class TestPropertyTableViewModel : public ::testing::Test
{
public:
    ~TestPropertyTableViewModel();
};

TestPropertyTableViewModel::~TestPropertyTableViewModel() = default;

TEST_F(TestPropertyTableViewModel, initialState)
{
    PropertyTableViewModel viewModel;
    EXPECT_EQ(viewModel.rowCount(), 0);
    EXPECT_EQ(viewModel.columnCount(), 0);
    EXPECT_EQ(viewModel.sessionItemFromIndex(QModelIndex()), nullptr);
}

TEST_F(TestPropertyTableViewModel, baseItem)
{
    SessionModel model;
    model.insertItem<SessionItem>();

    PropertyTableViewModel viewModel;
    viewModel.setSessionModel(&model);

    EXPECT_EQ(viewModel.rowCount(), 0);
    EXPECT_EQ(viewModel.columnCount(), 0);
}

TEST_F(TestPropertyTableViewModel, propertyItem)
{
    SessionModel model;
    auto parent = model.insertItem<SessionItem>();

    parent->registerTag(TagInfo::universalTag("universal_tag"));
    parent->registerTag(TagInfo::propertyTag("property_tag", Constants::PropertyType));

    model.insertItem<SessionItem>(parent, "universal_tag");
    model.insertItem<PropertyItem>(parent, "property_tag");
    model.insertItem<SessionItem>(parent, "universal_tag");

    PropertyTableViewModel viewModel;
    viewModel.setSessionModel(&model);

    // one cell corresponding to single item at property_tag of our parent
    EXPECT_EQ(viewModel.rowCount(), 1);
    EXPECT_EQ(viewModel.columnCount(), 1);

    viewModel.setRootSessionItem(parent);
    EXPECT_EQ(viewModel.rowCount(), 0);
    EXPECT_EQ(viewModel.columnCount(), 0);
}

//! VectorItem in a model.

TEST_F(TestPropertyTableViewModel, vectorItem)
{
    SessionModel model;
    auto parent = model.insertItem<VectorItem>();

    PropertyTableViewModel viewModel;
    viewModel.setSessionModel(&model);

    EXPECT_EQ(viewModel.rowCount(), 1);
    EXPECT_EQ(viewModel.columnCount(), 3);

    // switching to vectorItem and checking that it has 3 properties
    viewModel.setRootSessionItem(parent);
    EXPECT_EQ(viewModel.rowCount(), 0);
    EXPECT_EQ(viewModel.columnCount(), 0);
}
