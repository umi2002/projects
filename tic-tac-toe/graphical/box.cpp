#include "box.h"

Box::Box(int x, int y, QWidget* parent)
    : QLabel(parent), x_(x), y_(y) {}

Box::~Box() {}

void Box::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit isClicked(x_, y_);
    }
}
