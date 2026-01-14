#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//DEFINIMOS NUESTRA ESTRUCTURA
struct Menu {
    int id;
    std::string nombre;
    std::string categoria;
    std::string descripcion;
    float precio;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
