// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef TOYITEMS_H
#define TOYITEMS_H

#include "compounditem.h"
#include "groupitem.h"
#include <string>

//! Collection of toy items and models for testing purposes.

namespace ToyItems
{

class MultiLayerItem : public ModelView::CompoundItem
{
public:
    static const std::string T_LAYERS;
    MultiLayerItem();
};

// ----------------------------------------------------------------------------

class LayerItem : public ModelView::CompoundItem
{
public:
    static const std::string P_THICKNESS;
    static const std::string P_COLOR;
    static const std::string T_PARTICLES;
    LayerItem();
};

// ----------------------------------------------------------------------------

class ParticleItem : public ModelView::CompoundItem
{
public:
    static const std::string P_POSITION;
    static const std::string P_SHAPES;
    ParticleItem();
};

// ----------------------------------------------------------------------------

class InterferenceFunctionItem : public ModelView::CompoundItem
{
public:
    static const std::string P_ROTATION_ANLE;
    static const std::string P_INTEGRATION;
    static const std::string P_LATTICE_TYPE;

    InterferenceFunctionItem();

    void activate() override;

private:
    void update_appearance();
};

// ----------------------------------------------------------------------------

class CylinderItem : public ModelView::CompoundItem
{
public:
    static const std::string P_RADIUS;
    static const std::string P_HEIGHT;
    CylinderItem();
};

class SphereItem : public ModelView::CompoundItem
{
public:
    static const std::string P_RADIUS;
    SphereItem();
};

class AnysoPyramidItem : public ModelView::CompoundItem
{
public:
    static const std::string P_LENGTH;
    static const std::string P_WIDTH;
    static const std::string P_HEIGHT;
    static const std::string P_ALPHA;
    AnysoPyramidItem();
};

class ShapeGroupItem : public ModelView::GroupItem
{
public:
    ShapeGroupItem();
};

} // namespace ToyItems

#endif // TOYITEMS_H
