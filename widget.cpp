#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButtonCmiou->hide();
    ui->tableWidgetMiou->hide();
    ui->tableWidgetClass->hide();
}

Widget::~Widget()
{
    delete ui;
    delete img;
}

void Widget::on_pushButtonPic_clicked()
{

   QString path = QFileDialog::getOpenFileName(this, tr("选择输入图像"), ".", tr("Image Files(*.jpg *.tif)"));
   picPath = path;
   img = new QImage() ;
   if(!(img->load(path)))
   {
       ui->labelPic->setText("你必须输入一个原始图像！");
    }else {
       QImage scaledimg=resizePic(img);
       ui->labelPic->setPixmap(QPixmap::fromImage(scaledimg));
   }
}

void Widget::on_pushButtonPri_clicked()
{
    img = new QImage() ;
    if(!(img->load(picPath)))
    {
        ui->labelPri->setText("无输入图像,无法预测！");
     }else {
        ui->labelPri->setText("正在预测！，这里做执行函数");
        qDebug()<<picPath;

    }
}

void Widget::on_pushButtonGt_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("选择Ground Truth"), ".", tr("Image Files(*.png)"));
    img = new QImage() ;
    if(!(img->load(path)))
    {
        ui->labelGt->setText("输入Ground Truth图像,可解锁预测结果计算！");
     }else {
        QImage scaledimg=resizePic(img);
        ui->labelGt->setPixmap(QPixmap::fromImage(scaledimg));
        ui->pushButtonCmiou->show();
    }
}

void Widget::on_pushButtonCmiou_clicked()
{
    ui->tableWidgetMiou->show();
    ui->tableWidgetClass->show();
}

QImage Widget::resizePic(QImage* img)
{
    QImage scaledimg;
    int Owidth=img->width(),Oheight=img->height();
    int Fwidth,Fheight;       //缩放图片大小
    int Mul;            //缩放比例
    if(Owidth/384>=Oheight/384)
        Mul=Owidth/384;
    else
        Mul=Oheight/384;
   Fwidth=Owidth/Mul;
   Fheight=Oheight/Mul;
   scaledimg=img->scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    return scaledimg;
}
