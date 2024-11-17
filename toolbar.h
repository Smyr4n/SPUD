#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QStackedWidget>

class Toolbar : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Toolbar(QWidget *parent = nullptr);

signals:
};

#endif // TOOLBAR_H
