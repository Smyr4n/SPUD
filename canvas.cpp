#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QGraphicsView{parent}
    , world(new QGraphicsScene(this))
{
    setScene(world);
}

void Canvas::addClass()
{
    QGraphicsRectItem* umlClass = makeClassTemplate("New Class");

    world->addItem(umlClass);
}

void Canvas::addAbstractClass()
{

}

void Canvas::addInterface()
{

}

void Canvas::addEnum()
{

}

QGraphicsRectItem* Canvas::makeClassTemplate(const QString& defaultText)
{
    QGraphicsRectItem* templateClass = new QGraphicsRectItem(width()/2, height()/2, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);

    templateClass->setFlags
    (
        QGraphicsItem::ItemIsMovable |
        QGraphicsItem::ItemIsSelectable |
        QGraphicsItem::ItemSendsGeometryChanges
    );

    QGraphicsTextItem* templateText = new QGraphicsTextItem(defaultText, templateClass);
    templateText->setPos(templateClass->rect().center() - templateText->boundingRect().center());
    templateText->setTextInteractionFlags(Qt::TextEditorInteraction);
    templateClass->setData(0, QVariant::fromValue(templateText));

    return templateClass;
}
