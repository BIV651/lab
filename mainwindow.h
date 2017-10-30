#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <vector>
#include <QVector>
#include <ctime>
#include <cstdlib>
#include <QString>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    QPushButton generation;
    QPushButton sort;
    QPushButton bubble;
    QTextEdit after;
    QTextEdit before;
    QTextEdit tme;
public:
    QVector<int> vec = QVector <int> (9000);
    QString str;
    QString timesec;
private slots:
    void on_bubble_clicked();
    void on_sort_clicked();
    void on_generation_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
