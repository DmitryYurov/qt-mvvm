// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_DOUBLEEDITOR_H
#define MVVM_DOUBLEEDITOR_H

#include "customeditor.h"

class QDoubleSpinBox;

namespace ModelView
{

//! Custom editor for QVariant based on double with possibility to set limits.

class CORE_EXPORT DoubleEditor : public CustomEditor
{
public:
    explicit DoubleEditor(QWidget* parent = nullptr);

    void setRange(double minimum, double maximum);

    void setDecimals(int decimals);

    void setSingleStep(double value);

private slots:
    void onEditingFinished();

private:
    void update_components() override;
    QDoubleSpinBox* m_doubleEditor;
};

} // namespace ModelView

#endif // MVVM_DOUBLEEDITOR_H
