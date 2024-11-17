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

private slots:

    void onItemClicked (const QModelIndex& index);

public slots:



signals:

    void addClass();

    void addAbstractClass();

    void addInterface();

    void addEnum();
};

#endif // TOOLBAR_H
