#include "searchid.h"
#include "ui_searchid.h"

SearchId::SearchId(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchId)
{
    ui->setupUi(this);
}

SearchId::~SearchId()
{
    delete ui;
}
