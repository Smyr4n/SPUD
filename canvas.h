#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QLabel>

class Canvas : public QLabel
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

signals:
};

#endif // CANVAS_H
