// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "topitemsviewmodel.h"
#include "childrenstrategies.h"
#include "labeldatarowconstructor.h"

using namespace ModelView;

TopItemsViewModel::TopItemsViewModel(SessionModel* model, QObject* parent)
    : AbstractViewModel(parent)
{
    setRowConstructor(std::make_unique<LabelDataRowConstructor>());
    setChildrenStrategy(std::make_unique<TopItemsStrategy>());
    setSessionModel(model);
}
