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
}
