// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_PROPERTYTABLEVIEWMODEL_H
#define MVVM_PROPERTYTABLEVIEWMODEL_H

#include "abstractviewmodel.h"

namespace ModelView
{

/*!
@class PropertyTableViewModel
@brief View model to show content of SessionModel in Qt widgets: all item properties as a table row.

Given view model is intended to show registered properties of items in table-like view.
Registered properties will form columns of the table, top level items will form table rows.
*/

class CORE_EXPORT PropertyTableViewModel : public AbstractViewModel
{
public:
    PropertyTableViewModel(SessionModel* model = nullptr, QObject* parent = nullptr);
};

} // namespace ModelView

#endif // MVVM_PROPERTYTABLEVIEWMODEL_H
