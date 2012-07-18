#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include "dose_calac.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_label_6_linkHovered(const QString &link);

    void on_label_7_linkHovered(const QString &link);

    void on_label_2_linkHovered(const QString &link);

    void on_label_9_linkHovered(const QString &link);

    void on_actionHelp_triggered();

    void on_actionAbout_DOSE_Calculator_triggered();

    void on_actionAbout_DOSE_calc_triggered();

private:
    Ui::MainWindow *ui;

    /*
      Object for storage of data and calculation of DOSE index score.
    */

    std::auto_ptr<DOSE_Calac> pdoseIn; // Original code, error found here at first.
};

#endif // MAINWINDOW_H
