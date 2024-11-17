#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include <QMouseEvent>

class Canvas : public QGraphicsView
{
    Q_OBJECT

private:

    QGraphicsScene* world;


public:

    explicit Canvas(QWidget *parent = nullptr);

public slots:

    void addClass (float xPos, float yPos);

signals:
};

#endif // CANVAS_H
