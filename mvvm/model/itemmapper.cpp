// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "itemmapper.h"

using namespace ModelView;

ItemMapper::ItemMapper(SessionItem* item)
    : m_active(true), m_item(item)
{

}

void ItemMapper::setOnItemDestroy(ItemMapper::func_item_t f, ItemMapper::caller_t caller)
{
    m_on_item_destroy.push_back(std::make_pair(f, caller));
}

void ItemMapper::setOnDataChange(ItemMapper::func_item_int_t f, ItemMapper::caller_t caller)
{
    m_on_data_change.push_back(std::make_pair(f, caller));
}


//! Sets activity flag to given value. Will disable all callbacks if false.

void ItemMapper::setActive(bool value)
{
    m_active = value;
}

//! Removes given caller from all subscriptions.

void ItemMapper::unsubscribe(ItemMapper::caller_t caller)
{
    clean_container(m_on_item_destroy, caller);
    clean_container(m_on_data_change, caller);
}

//! Calls all callbacks subscribed to "item is destroyed" event.

void ItemMapper::callOnItemDestroy()
{
    if (m_active)
        for (auto f : m_on_item_destroy)
            f.first(m_item);
}

//! Calls all callbacks subscribed to "item data is changed" event.

void ItemMapper::callOnDataChange(int role)
{
    if (m_active)
        for (auto f : m_on_data_change)
            f.first(m_item, role);
}
