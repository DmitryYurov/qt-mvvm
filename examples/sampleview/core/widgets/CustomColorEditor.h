// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef CUSTOMCOLOREDITOR_H
#define CUSTOMCOLOREDITOR_H

#include <QColorDialog>

/*!
@class CustomColorEditor
@brief QColorDialog with additional functionality for QStyledItemDelegate.
*/

class CustomColorEditor : public QColorDialog
{
    Q_OBJECT
    Q_PROPERTY(QColor userColor READ userColor WRITE setUserColor NOTIFY userColorChanged USER true)

public:
    explicit CustomColorEditor(QWidget* parent = nullptr);

    QColor userColor() const;
    void setUserColor(const QColor& color);

signals:
    void userColorChanged(const QColor& color);
};

#endif // CUSTOMCOLOREDITOR_H
