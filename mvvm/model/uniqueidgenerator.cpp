// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "uniqueidgenerator.h"
#include <QUuid>

using namespace ModelView;

identifier_type UniqueIdGenerator::generate()
{
    return  QUuid::createUuid().toString().toStdString();
}
