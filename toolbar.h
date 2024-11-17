#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QListView>

#include <QStringList>
#include <QStringListModel>

class Toolbar : public QListView
{
    Q_OBJECT

private:

    QStringList items;
    QStringListModel* listModel;

public:

    explicit Toolbar(QWidget *parent = nullptr);

signals:
};

#endif // TOOLBAR_H
