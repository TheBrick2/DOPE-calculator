
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dose_calac.h"
#include <QtCore>
#include <QtGui>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), pdoseIn(new DOSE_Calac)

{
    ui->setupUi(this);

    setMouseTracking(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // calculate button

    // get info from text boxes.

    QString input;

    input = ui->lineEdit->text();
    this->pdoseIn->SetDyspnoeaScale(input.toInt());

    input = ui->lineEdit_3->text();
    this->pdoseIn->SetFev1(input.toInt());

    input = ui->lineEdit_4->text();
    this->pdoseIn->SetAnualExacerbations(input.toInt());

    // QMessageBox::information(this,"About DOSE Calc",input);





    // calulate score
    int err;

    err = this->pdoseIn->CalcDOSEPoints();

    QString errorMessage;

    switch ( err )
    {
        case 1 :
            errorMessage = "Error:Dyspnea scale must be between 0 and 4.";
            break;
        case 2 :
            errorMessage = "Error: fev1% must be greater than zero.";
            break;
        default :
            if (err!=0)
            {
                errorMessage = "An error occured. Please check input values";
            }
    }

   // Deal with error via error box rather than console.

   if (err!=0)
   {
       QMessageBox::warning(this,"Help!",errorMessage);
   }

    // update label

    QString result;

    //result = QString::number(2.2);
    result = QString::number(pdoseIn->GetdoseIndexPoints());

    ui->label->setText(result);


}

void MainWindow::on_label_6_linkHovered(const QString &link)
{
    // MRC abreviation
    ui->label_6->setToolTip("MRC Dyspnoea Scale Score");
}

void MainWindow::on_label_7_linkHovered(const QString &link)
{
    // FEV1% abrevation.
    ui->label_7->setToolTip("MRC Dyspnoea Scale Score");
}

void MainWindow::on_label_2_linkHovered(const QString &link)
{
    // smoker. Ticked = smoker
    ui->label_2->setToolTip("MRC Dyspnoea Scale Score");
}

void MainWindow::on_label_9_linkHovered(const QString &link)
{
    // Dose Index Points. Click calulate.
    ui->label_9->setToolTip("MRC Dyspnoea Scale Score");
}

void MainWindow::on_actionHelp_triggered()
{
    // load help info
    QMessageBox::information(this,"Help!","Comming soon.");


}

void MainWindow::on_actionAbout_DOSE_calc_triggered()
{
    // pop-up info.
    QMessageBox::information(this,"About DOSE Calc","Written by me");
}
