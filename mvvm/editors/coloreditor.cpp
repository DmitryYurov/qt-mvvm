// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#include "coloreditor.h"
#include "customeventfilters.h"
#include "customvariants.h"
#include "styleutils.h"
#include <QColor>
#include <QColorDialog>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>

using namespace ModelView;

ColorEditor::ColorEditor(QWidget* parent)
    : CustomEditor(parent), m_textLabel(new QLabel), m_pixmapLabel(new QLabel),
      m_focusFilter(new LostFocusFilter(this))

{
    setMouseTracking(true);
    setAutoFillBackground(true);

    auto layout = new QHBoxLayout;
    layout->setContentsMargins(4, 0, 0, 0);

    layout->addWidget(m_pixmapLabel);
    layout->addWidget(m_textLabel);
    layout->addStretch(1);
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);

    setLayout(layout);
}

void ColorEditor::mousePressEvent(QMouseEvent*)
{
    // temporarily installing filter to prevent loss of focus caused by too insistent dialog
    installEventFilter(m_focusFilter);

    auto new_color = QColorDialog::getColor(currentColor());

    removeEventFilter(m_focusFilter);

    if (new_color.isValid()) {
        setDataIntern(new_color);
        update_components();
    }
}

QColor ColorEditor::currentColor() const
{
    return m_data.value<QColor>();
}

void ColorEditor::update_components()
{
    if (!Utils::IsColorVariant(m_data))
        throw std::runtime_error("ColorEditor::update_components() -> Error. Wrong variant type");

    QPixmap pixmap(Style::DefaultPixmapSize(), Style::DefaultPixmapSize());
    pixmap.fill(currentColor());
    m_textLabel->setText(currentColor().name());
    m_pixmapLabel->setPixmap(pixmap);
}
