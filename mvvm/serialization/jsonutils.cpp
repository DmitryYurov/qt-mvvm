// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "jsonutils.h"
#include "sessionmodel.h"
#include "jsonconverterinterfaces.h"
#include "jsonmodel.h"
#include "reallimits.h"
#include <QJsonDocument>
#include <QJsonObject>

namespace {
const std::string text_limitless = "limitless";
const std::string text_positive = "positive";
const std::string text_nonnegative = "nonnegative";
const std::string text_lowerlimited = "lowerlimited";
const std::string text_upperlimited = "upperlimited";
const std::string text_limited = "limited";
const std::string separator = " ";
}
using namespace ModelView;

std::string JsonUtils::ModelToJsonString(const ModelView::SessionModel& model)
{
    QJsonObject json_source;
    JsonModel converter;
    converter.model_to_json(model, json_source);
    QJsonDocument document(json_source);
    return QString(document.toJson(QJsonDocument::Indented)).toStdString();

}

std::string JsonUtils::ToString(const ModelView::RealLimits& limits)
{
    if (limits.isLimitless())
        return text_limitless;
    else if (limits.isPositive())
        return text_positive;
    else if (limits.isNonnegative())
        return text_nonnegative;
    else if(limits.isLowerLimited())
        return text_lowerlimited;
    else if(limits.isUpperLimited())
        return text_upperlimited;
    else if(limits.isLimited())
        return text_limited;
    else
        throw std::runtime_error("JsonUtils::ToString() -> Unknown type");
}

RealLimits JsonUtils::CreateLimits(const std::string& text, double min, double max)
{
    if (text == text_limitless)
        return RealLimits();
    else if (text == text_positive)
        return RealLimits::positive();
    else if (text == text_nonnegative)
        return RealLimits::nonnegative();
    else if(text == text_lowerlimited)
        return RealLimits::lowerLimited(min);
    else if(text == text_upperlimited)
        return RealLimits::upperLimited(max);
    else if(text == text_limited)
        return RealLimits::limited(min, max);
    else
        throw std::runtime_error("JsonUtils::CreateLimits -> Unknown type");
}
