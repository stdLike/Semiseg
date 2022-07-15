#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QImage resizePic(QImage* img);

private slots:
    void on_pushButtonPic_clicked();

    void on_pushButtonGt_clicked();

    void on_pushButtonCmiou_clicked();

    void on_pushButtonPri_clicked();

private:
    Ui::Widget *ui;
    QString picPath;
    QImage *img;
};

#endif // WIDGET_H
