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

void onItemClicked (const QModelIndex& index)
{
    QString itemText = index.data(Qt::DisplayRole).toString();

    switch (itemText)
    {
        case "Class":
            emit addUMLClass();
            break;

        case "Abstract Class":
            emit addUMLAbstract();
            break;

        case "Interface":
            emit addUMLInterface();
            break;

        case "Enum":
            emit addUMLEnum();
            break;

        default:
            break;
    }
}
