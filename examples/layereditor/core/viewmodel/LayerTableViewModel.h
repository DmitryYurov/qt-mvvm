// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef LAYERTABLEVIEWMODEL_H
#define LAYERTABLEVIEWMODEL_H

#include "abstractviewmodel.h"

namespace ModelView
{
class SessionModel;
} // namespace ModelView

/*!
@class LayerTableViewModel
@brief View model to display content of MultiLayerItem in table like views.
*/

class LayerTableViewModel : public ModelView::AbstractViewModel
{
public:
    LayerTableViewModel(ModelView::SessionModel* model = nullptr, QObject* parent = nullptr);
};

#endif //  LAYERTABLEVIEWMODEL_H
