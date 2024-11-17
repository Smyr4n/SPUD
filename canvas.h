#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include <QMouseEvent>

class Canvas : public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene* world;

public:

    explicit Canvas(QWidget *parent = nullptr);

public slots:

    void addClass();

    void addAbstractClass();

    void addInterface();

    void addEnum();

signals:
};

#endif // CANVAS_H
