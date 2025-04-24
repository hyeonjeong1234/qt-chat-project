#include "chatlistwidget.h"
#include "ui_chatlistwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QDebug>
#include <QScreen>

ChatListWidget::ChatListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatListWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true); // 마우스 움직일 때 커서 모양 바뀌게

    setMinimumSize(400, 300); // 최소 크기 지정
}

ChatListWidget::~ChatListWidget()
{
    delete ui;
}

void ChatListWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    emit click_chatroom(item->text());
}


void ChatListWidget::on_pushButton_3_clicked()
{
    QString search_Id = ui->lineEdit_3->text();
    emit click_search(search_Id);

}

void ChatListWidget::addchatroom(QString addroomname)
{

    QListWidgetItem *pItem=new QListWidgetItem;
    pItem->setText(addroomname);
    QFont font("BM JUA", 25);
//    font.setStyleHint (QFont::Monospace);
//    font.setPointSize (20);
//    font.setFixedPitch (true);
    pItem->setFont (font);
    // 글씨 꼬리까지 여유 공간 확보 (기존보다 조금 더)
    pItem->setSizeHint(QSize(200, 60));  // 보통 50~60px 사이 추천

    ui->listWidget->addItem(pItem);


}

void ChatListWidget::on_pushButton_clicked()
{
    emit make_groupchat();
}


//ui
void ChatListWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        currentRegion = getResizeRegion(event->pos());

        if (currentRegion != None) {
            resizing = true;
            originalGeometry = geometry();
            dragStartPos = event->globalPos();
        } else {
            dragging = true;
            dragStartPos = event->globalPos() - frameGeometry().topLeft();
        }
    }
}

void ChatListWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    resizing = false;
    dragging = false;
    currentRegion = None;
    QApplication::restoreOverrideCursor();
}

void ChatListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (resizing) {
        QPoint delta = event->globalPos() - dragStartPos;
        QRect geom = originalGeometry;

        switch (currentRegion) {
            case Left:      geom.setLeft(geom.left() + delta.x()); break;
            case Right:     geom.setRight(geom.right() + delta.x()); break;
            case Top:       geom.setTop(geom.top() + delta.y()); break;
            case Bottom:    geom.setBottom(geom.bottom() + delta.y()); break;
            case TopLeft:
                geom.setTop(geom.top() + delta.y());
                geom.setLeft(geom.left() + delta.x());
                break;
            case TopRight:
                geom.setTop(geom.top() + delta.y());
                geom.setRight(geom.right() + delta.x());
                break;
            case BottomLeft:
                geom.setBottom(geom.bottom() + delta.y());
                geom.setLeft(geom.left() + delta.x());
                break;
            case BottomRight:
                geom.setBottom(geom.bottom() + delta.y());
                geom.setRight(geom.right() + delta.x());
                break;
            default: break;
        }

        if (geom.width() >= minimumWidth() && geom.height() >= minimumHeight()) {
            setGeometry(geom);
        }
    }
    else if (dragging) {
        move(event->globalPos() - dragStartPos);
    }
    else {
        updateCursorShape(event->pos());
    }
}

void ChatListWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (!maximized) {
            normalGeometry = geometry();
            QRect screenGeometry = screen()->availableGeometry();
            setGeometry(screenGeometry);
            maximized = true;
        } else {
            setGeometry(normalGeometry);
            maximized = false;
        }
    }
}

ChatListWidget::ResizeRegion ChatListWidget::getResizeRegion(const QPoint &pos)
{
    const int x = pos.x();
    const int y = pos.y();
    const int w = width();
    const int h = height();

    bool left = x < resizeMargin;
    bool right = x > w - resizeMargin;
    bool top = y < resizeMargin;
    bool bottom = y > h - resizeMargin;

    if (top && left) return TopLeft;
    if (top && right) return TopRight;
    if (bottom && left) return BottomLeft;
    if (bottom && right) return BottomRight;
    if (left) return Left;
    if (right) return Right;
    if (top) return Top;
    if (bottom) return Bottom;

    return None;
}

void ChatListWidget::updateCursorShape(const QPoint &pos)
{
    ResizeRegion region = getResizeRegion(pos);

    switch (region) {
        case Top: case Bottom:
            setCursor(Qt::SizeVerCursor);
            break;
        case Left: case Right:
            setCursor(Qt::SizeHorCursor);
            break;
        case TopLeft: case BottomRight:
            setCursor(Qt::SizeFDiagCursor);
            break;
        case TopRight: case BottomLeft:
            setCursor(Qt::SizeBDiagCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
            break;
    }
}
void ChatListWidget::paintEvent(QPaintEvent *event) //위젯이나 다이얼로그의 테두리 그리기
{
    QPainter painter(this);  // 현재 위젯을 대상으로 QPainter 사용
       painter.setRenderHint(QPainter::Antialiasing);  // 곡선을 부드럽게

       int radius = 10;  // 둥근 모서리의 반지름
       painter.setPen(Qt::NoPen);   // 검은색 테두리
       painter.setBrush(QColor(116, 88, 80));  // 연한 파란색 배경

       // 모서리를 둥글게 설정 (반지름 15)
       painter.drawRoundedRect(0, 0, width(), height(), radius, radius);

       QWidget::paintEvent(event);  // 기본 위젯 이벤트 호출
}
