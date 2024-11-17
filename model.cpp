#include "model.h"

Model::Model(Canvas* canvas, Toolbar* toolbar, QObject *parent)
    : QObject{parent}
    , canvas(canvas)
    , toolbar(toolbar)
{

}
