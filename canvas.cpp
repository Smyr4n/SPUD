#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QLabel{parent}
{
    setAcceptDrops(true);
}
