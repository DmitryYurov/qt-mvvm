// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_MODELUTILS_H
#define MVVM_MODELUTILS_H

#include "itemutils.h"
#include "mvvm_export.h"
#include "sessionitem.h"
#include "sessionmodel.h"
#include <vector>

namespace ModelView
{

class SessionItem;
class SessionModel;

namespace Utils
{

//! Returns all top level items of given type.

template <typename T = SessionItem> std::vector<T*> TopItems(const SessionModel* model)
{
    std::vector<T*> result;
    for (auto child : model->rootItem()->children()) {
        if (auto item = dynamic_cast<T*>(child))
            result.push_back(item);
    }

    return result;
}

//! Returns top level item of given type.

template <typename T = SessionItem> T* TopItem(const SessionModel* model)
{
    auto items = TopItems<T>(model);
    return items.empty() ? nullptr : items.front();
}

//! Returns all items in a tree of given type.

template <typename T = SessionItem> std::vector<T*> FindItems(const SessionModel* model)
{
    std::vector<T*> result;

    auto func = [&result](SessionItem* item) {
        if (auto concrete = dynamic_cast<T*>(item))
            result.push_back(concrete);
    };

    iterate(model->rootItem(), func);

    return result;
}

//! Removes and deletes item from its model.

void CORE_EXPORT DeleteItemFromModel(SessionItem* item);

} // namespace Utils
} // namespace ModelView

#endif // MVVM_MODELUTILS_H
