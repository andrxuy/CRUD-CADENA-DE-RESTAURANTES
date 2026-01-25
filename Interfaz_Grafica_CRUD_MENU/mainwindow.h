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


    void on_agregar_clicked();

    void on_buscar_clicked();

    void on_mostrar_clicked();

    void on_actualizar_clicked();

    void on_eliminar_clicked();

private:
    Ui::MainWindow *ui;

    //definimos funciones
    std::vector<Menu> cargarMenu();
    Menu  agregarMenu();
    void  guardarMenu();
    void  leerMenu();
    void  buscarMenu();
    void actualizarMenu();
    void eliminarMenu();

};
#endif // MAINWINDOW_H


