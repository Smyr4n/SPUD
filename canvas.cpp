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

    setItalic(abstractText);

    QGraphicsRectItem* umlAbstract = makeClassTemplate(abstractText);

    setDashed(umlAbstract);

    world->addItem(umlAbstract);
}

void Canvas::addInterface()
{
    QGraphicsTextItem* interfaceText = new QGraphicsTextItem("New Interface");

    setItalic(interfaceText);

    QGraphicsRectItem* umlInterface = makeClassTemplate(interfaceText);

    setDashed(umlInterface);

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

    templateText->setTextInteractionFlags(Qt::TextEditorInteraction);

    // Recenters the text when it is updated
    QObject::connect(templateText->document(), &QTextDocument::contentsChanged, [templateText, templateClass]()
    {
        templateText->setPos(templateClass->rect().center() - templateText->boundingRect().center());
    });

    templateClass->setData(0, QVariant::fromValue(templateText));

    return templateClass;
}

void Canvas::setItalic(QGraphicsTextItem* text)
{
    QFont font = text->font();
    font.setItalic(true);
    text->setFont(font);
}

void Canvas::setDashed(QGraphicsRectItem* box)
{
    QPen dashedPen(Qt::black);
    dashedPen.setStyle(Qt::DashLine);
    box->setPen(dashedPen);
}
