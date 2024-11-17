#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QGraphicsView{parent}
    , world(new QGraphicsScene(this))
{
    setScene(world);
    addClass();
}

void Canvas::addClass()
{
    QGraphicsRectItem* umlClass = new QGraphicsRectItem(width()/2, height()/2, 100, 50);
    umlClass->setFlags
    (
        QGraphicsItem::ItemIsMovable |
        QGraphicsItem::ItemIsSelectable |
        QGraphicsItem::ItemSendsGeometryChanges
    );

    QGraphicsTextItem* classText = new QGraphicsTextItem("New Class", umlClass);
    classText->setPos(umlClass->rect().center() - classText->boundingRect().center());
    classText->setTextInteractionFlags(Qt::TextEditorInteraction);

    umlClass->setData(0, QVariant::fromValue(classText));
    world->addItem(umlClass);
}
