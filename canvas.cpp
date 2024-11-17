#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QGraphicsView{parent}
    , world(new QGraphicsScene(this))
{
    setScene(world);
    addClass(100, 100);
}

void Canvas::addClass(float xPos, float yPos)
{
    QGraphicsRectItem* umlClass = new QGraphicsRectItem(xPos, yPos, 50, 50);
    umlClass->setFlag(QGraphicsItem::ItemIsMovable);
    umlClass->setFlag(QGraphicsItem::ItemIsSelectable);
    world->addItem(umlClass);
}
