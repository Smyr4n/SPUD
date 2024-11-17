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
    QGraphicsRectItem* umlAbstract = makeClassTemplate("New Abstract Class");

    world->addItem(umlAbstract);
}

void Canvas::addInterface()
{
    QGraphicsRectItem* umlInterface = makeClassTemplate("New Interface");

    world->addItem(umlInterface);
}

void Canvas::addEnum()
{
    QGraphicsRectItem* umlEnum = makeClassTemplate("New Enum");

    world->addItem(umlEnum);
}

void Canvas::addPackage()
{
    QGraphicsRectItem* umlPackage = makeClassTemplate("New Package");

    world->addItem(umlPackage);
}

QGraphicsRectItem* Canvas::makeClassTemplate(const QString& defaultText)
{
    // Create a new box centered on the screen
    QGraphicsRectItem* templateClass = new QGraphicsRectItem(width()/2, height()/2, DEFAULT_BOX_WIDTH, DEFAULT_BOX_HEIGHT);

    // Define box characteristics
    templateClass->setFlags
    (
        QGraphicsItem::ItemIsMovable |
        QGraphicsItem::ItemIsSelectable |
        QGraphicsItem::ItemSendsGeometryChanges
    );

    // Create and center text
    QGraphicsTextItem* templateText = new QGraphicsTextItem(defaultText, templateClass);
    templateText->setPos(templateClass->rect().center() - templateText->boundingRect().center());
    templateText->setTextInteractionFlags(Qt::TextEditorInteraction);
    templateClass->setData(0, QVariant::fromValue(templateText));

    return templateClass;
}
