// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef CONTAINEREDITORWIDGET_H
#define CONTAINEREDITORWIDGET_H

#include <QWidget>
#include <memory>
#include <vector>

class SampleModel;
class QTreeView;
class QBoxLayout;
class QItemSelectionModel;

namespace ModelView
{
class AbstractViewModel;
class ViewModelDelegate;
class SessionItem;
} // namespace ModelView

/*!
@class ContainerEditor
@brief Shows content of container and provide functionality to add, copy and move items.
*/

class ContainerEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ContainerEditorWidget(QWidget* parent = nullptr);
    ~ContainerEditorWidget();

    void setModel(SampleModel* model, ModelView::SessionItem* root_item = nullptr);

private slots:
    void onAdd();
    void onCopy();
    void onRemove();
    void onMoveDown();
    void onMoveUp();

private:
    std::vector<ModelView::SessionItem*> selected_items() const;
    QBoxLayout* create_button_layout();

    QTreeView* m_treeView;
    std::unique_ptr<ModelView::AbstractViewModel> m_viewModel;
    std::unique_ptr<ModelView::ViewModelDelegate> m_delegate;
    ModelView::SessionItem* m_container;
    SampleModel* m_model;
};

#endif // CONTAINEREDITORWIDGET_H
