// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef CUSTOMCELLDECORATION_H
#define CUSTOMCELLDECORATION_H

#include "defaultcelldecoration.h"

class QModelIndex;

//! Generates cell decorations for MaterialEditor.
//! Current implementation just removes color name and leaves only color pixmap.

class CustomCellDecoration : public ModelView::DefaultCellDecoration
{
public:
    bool hasCustomDecoration(const QModelIndex& index) const;
    std::string cellText(const QModelIndex& index) const;
};

#endif //  CUSTOMCELLDECORATION_H
