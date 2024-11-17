#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QVBoxLayout>

class ToolBar : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit ToolBar(QWidget *parent = nullptr);

signals:
};

#endif // TOOLBAR_H
