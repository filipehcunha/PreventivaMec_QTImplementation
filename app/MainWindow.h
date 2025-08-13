#pragma once
#include <QMainWindow>
#include <QStandardItemModel>
#include "ServiceLocator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public: MainWindow(QWidget *parent=nullptr); ~MainWindow();
private slots: void on_btnSchedule_clicked();
private:
    Ui::MainWindow *ui;
    ServiceLocator services;
    QStandardItemModel m_model;
    void refreshMachines();
};
