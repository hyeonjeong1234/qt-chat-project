#ifndef SEARCHID_H
#define SEARCHID_H

#include <QWidget>

namespace Ui {
class SearchId;
}

class SearchId : public QWidget
{
    Q_OBJECT

public:
    explicit SearchId(QWidget *parent = nullptr);
    ~SearchId();

private:
    Ui::SearchId *ui;
};

#endif // SEARCHID_H
