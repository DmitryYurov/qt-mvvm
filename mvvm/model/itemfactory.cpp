// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "itemfactory.h"
#include "compounditem.h"
#include "itemcatalogue.h"
#include "propertyitem.h"
#include "sessionitem.h"
#include "vectoritem.h"

using namespace ModelView;

ItemFactory::ItemFactory(std::unique_ptr<ItemCatalogue> catalogue)
    : m_catalogue(std::move(catalogue))
{
}

ItemFactory::~ItemFactory() = default;

std::unique_ptr<SessionItem> ItemFactory::createItem(const model_type& modelType) const
{
    return m_catalogue->create(modelType);
}

std::unique_ptr<SessionItem> ItemFactory::createEmptyItem() const
{
    return std::make_unique<SessionItem>();
}
