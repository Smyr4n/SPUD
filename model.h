#ifndef MODEL_H
#define MODEL_H

#include "canvas.h"
#include "toolbar.h"

#include <QObject>

class Model : public QObject
{
    Q_OBJECT

private:

    Canvas* canvas;
    Toolbar* toolbar;

public:

    explicit Model(Canvas* canvas, Toolbar* toolbar, QObject *parent = nullptr);

signals:

};

#endif // MODEL_H
