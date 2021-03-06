// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef DRAGVIEWMODEL_H
#define DRAGVIEWMODEL_H

#include "propertytableviewmodel.h"

namespace ModelView
{
class SessionModel;
}

//! View model with drag-and-drop support. Relies on PropertyTableViewModel to show
//! properties of DemoItem in table-like views.

class DragViewModel : public ModelView::PropertyTableViewModel
{
public:
    DragViewModel(ModelView::SessionModel* model = nullptr, QObject* parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QMimeData* mimeData(const QModelIndexList& index_list) const override;
    Qt::DropActions supportedDragActions() const override;
    Qt::DropActions supportedDropActions() const override;
    bool canDropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column,
                         const QModelIndex& parent) const override;
    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column,
                      const QModelIndex& parent) override;
};

#endif // DRAGVIEWMODEL_H
