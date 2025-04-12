#include "chatwidget.h"
#include "ui_chatwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QDebug>
#include <QScreen>
ChatWidget::ChatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget)
{

    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true); // 마우스 움직일 때 커서 모양 바뀌게

    setMinimumSize(400, 300); // 최소 크기 지정
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
void ChatWidget::setText(QString sendCli,QString sendMsg)//바꿀필요있을듯!!!!!!!!!!1
{
    QList<QString> checkme = sendMsg.split(':');
    QString msg;

    msg = sendMsg.remove(0,checkme[0].size()+1);

    if(checkme[0] == "me")
    {

        ui->textEdit->append(sendCli+": "+msg);
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat textBlockFormat = cursor.blockFormat();
        textBlockFormat.setAlignment(Qt::AlignRight);
        cursor.mergeBlockFormat(textBlockFormat);
        ui->textEdit->setTextCursor(cursor);
    }
    else{
    ui->textEdit->append(sendCli+": "+msg);
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignLeft);
    cursor.mergeBlockFormat(textBlockFormat);
    ui->textEdit->setTextCursor(cursor);
    }



}
QString ChatWidget::getText()
{
    QString msg;
    msg = ui->textEdit_2->toPlainText();
    qDebug()<< msg;
    ui->textEdit_2->setText("");
    return msg;
}
void ChatWidget::on_pushButton_clicked()
{
    //QString newMsg = ui->textEdit->text();
    emit signal_newMsg(this->windowTitle());
}


void ChatWidget::on_pushButton_2_clicked()
{
    this->hide();
}

void ChatWidget::setChatroomName(QString friendName)
{
    ui->label_2->setText(friendName);
}

//ui
void ChatWidget::mousePressEvent(QMouseEvent *event)
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

void ChatWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    resizing = false;
    dragging = false;
    currentRegion = None;
    QApplication::restoreOverrideCursor();
}

void ChatWidget::mouseMoveEvent(QMouseEvent *event)
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

void ChatWidget::mouseDoubleClickEvent(QMouseEvent *event)
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

ChatWidget::ResizeRegion ChatWidget::getResizeRegion(const QPoint &pos)
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

void ChatWidget::updateCursorShape(const QPoint &pos)
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
void ChatWidget::paintEvent(QPaintEvent *event) //위젯이나 다이얼로그의 테두리 그리기
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

