// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "tagrow.h"

//! Returns TagRow corresponding to the append to tag_name.
//! If tag_name =="" the default name will be used in SessionItemTags context.

ModelView::TagRow ModelView::TagRow::append(const std::string& tag_name)
{
    return {tag_name, -1};
}

//! Returns TagRow corresponding to prepending to tag_name.
//! If tag_name =="" the default name will be used in SessionItemTags context.

ModelView::TagRow ModelView::TagRow::prepend(const std::string& tag_name)
{
    return {tag_name, 0};
}

bool operator==(const ModelView::TagRow& left, const ModelView::TagRow& right)
{
    return left.row == right.row && left.tag==right.tag;
}

bool operator!=(const ModelView::TagRow& left, const ModelView::TagRow& right)
{
    return !(left == right);
}

