// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef MVVM_GRAPHVIEWPORTPLOTCONTROLLER_H
#define MVVM_GRAPHVIEWPORTPLOTCONTROLLER_H

#include "itemcontroller.h"

class QCustomPlot;

namespace ModelView
{

class GraphViewportItem;

/*!
@class GraphViewportPlotController
@brief Establishes communications and mutual updates for GraphViewportItem and QCutomPlot.

Populates custom plot with all graphs found in GraphViewportItem.
*/

class CORE_EXPORT GraphViewportPlotController : public ItemController<GraphViewportItem>
{
public:
    explicit GraphViewportPlotController(QCustomPlot* plot);
    ~GraphViewportPlotController() override;

protected:
    void subscribe() override;

private:
    struct GraphViewportPlotControllerPrivate;
    std::unique_ptr<GraphViewportPlotControllerPrivate> p_impl;
};

} // namespace ModelView

#endif // MVVM_GRAPHVIEWPORTPLOTCONTROLLER_H
