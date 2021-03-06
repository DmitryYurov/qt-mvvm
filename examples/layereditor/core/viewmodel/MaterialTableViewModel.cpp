// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "MaterialTableViewModel.h"
#include "standardviewmodelcontrollers.h"

using namespace ModelView;

MaterialTableViewModel::MaterialTableViewModel(ModelView::SessionModel* model, QObject* parent)
    : AbstractViewModel(std::make_unique<PropertyTableViewModelController>(this), parent)
{
    setSessionModel(model);
}
