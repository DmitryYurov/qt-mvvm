// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_TOPITEMSVIEWMODEL_H
#define MVVM_TOPITEMSVIEWMODEL_H

#include "abstractviewmodel.h"

namespace ModelView
{

//! View model to show content of SessionModel in Qt widgets.
//! Only top level items are shown, all property items are filtered out.

class CORE_EXPORT TopItemsViewModel : public AbstractViewModel
{
public:
    TopItemsViewModel(SessionModel* model, QObject* parent = nullptr);
};

} // namespace ModelView

#endif // MVVM_TOPITEMSVIEWMODEL_H
