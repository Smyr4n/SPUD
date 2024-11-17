#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

#include <QString>

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

class Canvas : public QGraphicsView
{
    Q_OBJECT

public:

    /// @brief Constructor for the Canvas widget.
    ///
    /// @param parent - The parent of this widget.
    explicit Canvas(QWidget *parent = nullptr);

public slots:

    /// @brief Creates a box on the canvas representing
    ///        a basic object/class.
    void addClass();

    /// @brief Creates a box on the canvas representing
    ///        an abstract class.
    void addAbstractClass();

    /// @brief Creates a box on the canvas representing
    ///        an interface.
    void addInterface();

    /// @brief Creates a box on the canvas representing
    ///        an enum.
    void addEnum();

    /// @brief Creates a box on the canvas representing
    ///        a package.
    void addPackage();

signals:

private:

    /// @brief Defines the size of boxes when they are created.
    const int DEFAULT_BOX_WIDTH = 150;
    const int DEFAULT_BOX_HEIGHT = 50;

    /// @brief The scene this widget uses to draw on.
    QGraphicsScene* world;

    /// @brief Creates and returns a pointer to a template box on the Canvas.
    QGraphicsRectItem* makeClassTemplate(QGraphicsTextItem* templateText);

};

#endif // CANVAS_H
