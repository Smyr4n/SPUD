#include "canvas.h"

Canvas::Canvas(QWidget *parent)
    : QGraphicsView{parent}
    , world(new QGraphicsScene(this))
{
    setScene(world);
}

void Canvas::addClass()
{
    QGraphicsTextItem* classText = new QGraphicsTextItem("New Class");

    QGraphicsRectItem* umlClass = makeClassTemplate(classText);

    world->addItem(umlClass);
}

void Canvas::addAbstractClass()
{
    QGraphicsTextItem* abstractText = new QGraphicsTextItem("New Abstract Class");

    // Change font to italic
    QFont font = abstractText->font();
    font.setItalic(true);
    abstractText->setFont(font);

    QGraphicsRectItem* umlAbstract = makeClassTemplate(abstractText);

    world->addItem(umlAbstract);
}

void Canvas::addInterface()
{
    QGraphicsTextItem* interfaceText = new QGraphicsTextItem("New Interface");

    // Change font to italic
    QFont font = interfaceText->font();
    font.setItalic(true);
    interfaceText->setFont(font);

    QGraphicsRectItem* umlInterface = makeClassTemplate(interfaceText);

    world->addItem(umlInterface);
}

void Canvas::addEnum()
{
    QGraphicsTextItem* enumText = new QGraphicsTextItem("New Enum");

    QGraphicsRectItem* umlEnum = makeClassTemplate(enumText);

    world->addItem(umlEnum);
}

void Canvas::addPackage()
{
    QGraphicsTextItem* packageText = new QGraphicsTextItem("New Package");

    QGraphicsRectItem* umlPackage = makeClassTemplate(packageText);

    world->addItem(umlPackage);
}

QGraphicsRectItem* Canvas::makeClassTemplate(QGraphicsTextItem* templateText)
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

    // Center text
    templateText->setParentItem(templateClass);
    templateText->setPos(templateClass->rect().center() - templateText->boundingRect().center());

    // Define text characteristics
    templateText->setTextInteractionFlags(Qt::TextEditorInteraction);
    templateClass->setData(0, QVariant::fromValue(templateText));

    return templateClass;
}
