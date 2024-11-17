#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

#include <QString>

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include <QMouseEvent>

class Canvas : public QGraphicsView
{
    Q_OBJECT

public:

    explicit Canvas(QWidget *parent = nullptr);

public slots:

    void addClass();

    void addAbstractClass();

    void addInterface();

    void addEnum();

signals:

private:

    const int DEFAULT_BOX_WIDTH = 150;
    const int DEFAULT_BOX_HEIGHT = 50;

    QGraphicsScene* world;

    QGraphicsRectItem* makeClassTemplate(const QString& defaultText);

};

#endif // CANVAS_H
