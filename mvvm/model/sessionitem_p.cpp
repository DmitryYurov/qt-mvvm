// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "sessionitem_p.h"
#include "itemmapper.h"
#include "sessionitemdata.h"
#include "sessionitemtags.h"

using namespace ModelView;

SessionItemPrivate::SessionItemPrivate()
    : m_parent(nullptr), m_model(nullptr), m_data(std::make_unique<SessionItemData>()),
      m_tags(std::make_unique<SessionItemTags>())
{
}

SessionItemPrivate::~SessionItemPrivate() = default;
