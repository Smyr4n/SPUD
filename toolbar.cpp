#include "toolbar.h"

Toolbar::Toolbar(QWidget *parent)
    : QListView{parent}
{
    items = {
        "Class",
        "Abstract Class",
        "Interface",
        "Enum"
    };

    listModel = new QStringListModel(items, this);

    setModel(listModel);
    setDragEnabled(true);
    setSelectionMode(QAbstractItemView::SingleSelection);

    connect(this, &QListView::clicked, this, &Toolbar::onItemClicked);
}

void Toolbar::onItemClicked (const QModelIndex& index)
{
    QString itemText = index.data(Qt::DisplayRole).toString();

    if (itemText == "Class")
    {
        emit addClass();
    }
    else if (itemText == "Abstract Class")
    {
        emit addAbstractClass();
    }
    else if (itemText == "Interface")
    {
        emit addInterface();
    }
    else if (itemText == "Enum")
    {
        emit addEnum();
    }

}
