#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QLabel>

class Toolbar : public QLabel
{
    Q_OBJECT
public:
    explicit Toolbar(QWidget *parent = nullptr);

signals:
};

#endif // TOOLBAR_H
