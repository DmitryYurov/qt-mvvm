// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "viewportitem.h"
#include "axisitems.h"

using namespace ModelView;

ViewportItem::ViewportItem(const ModelView::model_type& model) : CompoundItem(model) {}

ViewportAxisItem* ViewportItem::xAxis() const
{
    return item<ViewportAxisItem>(P_XAXIS);
}

ViewportAxisItem* ViewportItem::yAxis() const
{
    return item<ViewportAxisItem>(P_YAXIS);
}

//! Updates range of x,y window to show all data.

void ViewportItem::update_viewport()
{
    auto [xmin, xmax] = data_xaxis_range();
    xAxis()->set_range(xmin, xmax);

    auto [ymin, ymax] = data_yaxis_range();
    yAxis()->set_range(ymin, ymax);
}

void ViewportItem::register_xy_axes()
{
    addProperty<ViewportAxisItem>(P_XAXIS)->setDisplayName("X axis");
    addProperty<ViewportAxisItem>(P_YAXIS)->setDisplayName("Y axis");
}
