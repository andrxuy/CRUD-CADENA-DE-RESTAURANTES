#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<Menu> listaMenus;
string ruta="menus.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaMenus= cargarMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//CARGAR
vector<Menu> MainWindow::cargarMenu() {
    vector<Menu> menus;
    ifstream archivo(ruta);

    if (!archivo) {
        cerr << "Archivo no encontrado. Se iniciará una nueva lista.\n";
        return menus;
    }

    string linea;
    while (getline(archivo, linea)) {
        Menu m;
        int pos = 0;
        int campo = 0;
        string token;

        while ((pos = linea.find('|')) != string::npos) {
            token = linea.substr(0, pos);
            if (campo == 0) m.id = stoi(token);
            else if (campo == 1) m.nombre = token;
            else if (campo == 2) m.categoria = token;
            else if (campo == 3) m.descripcion = token;
            linea.erase(0, pos + 1);
            campo++;
        }
        m.precio = stod(linea);
        menus.push_back(m);
    }
    return menus;
}

//AGREGAR
Menu MainWindow::agregarMenu() {
    Menu nuevo;

    nuevo.id = ui->digitar_id->text().toInt();

    for (const auto& m : listaMenus) { //PARA VER SI YA EXISTE UN ID IGUAL
        if (nuevo.id == m.id) {
            ui->mostrar->setText("El ID ya existe");
            return {};
        }
    }
    nuevo.nombre      = ui->digitar_nombre->text().toStdString();
    nuevo.categoria   = ui->categoria_item->currentText().toStdString();
    nuevo.descripcion = ui->escribir_descripcion->text().toStdString();
    nuevo.precio      = ui->escribir_precio->text().toDouble();
    return nuevo;
}

//PARA GUARDAR
void MainWindow::guardarMenu() {
    ofstream archivo(ruta);

    if (!archivo) {
        cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& m : listaMenus) {
        archivo << m.id << "|"
                << m.nombre << "|"
                << m.categoria << "|"
                << m.descripcion << "|"
                << m.precio << "\n";
    }

    ui->mostrar->setText("Menú guardado correctamente");
}

//PARA MOSTAR TODOS LOS MENUS
void MainWindow::leerMenu() {
    ui->tabla_registros->setRowCount(0);
    int fila = 0;
    
    for (const auto& m : listaMenus) {
        ui->tabla_registros->insertRow(fila);
        ui->tabla_registros->setItem(fila, 0, new QTableWidgetItem(QString::number(m.id)));
        ui->tabla_registros->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(m.nombre)));
        ui->tabla_registros->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(m.categoria)));
        ui->tabla_registros->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(m.descripcion)));
        ui->tabla_registros->setItem(fila, 4,new QTableWidgetItem(QString("$ %1").arg(m.precio, 0, 'f', 2)));
        fila++;
    }
}

//CONECCIÓN  A BOTONES
void MainWindow::on_agregar_clicked()
{
    Menu nuevo = agregarMenu();
    if (nuevo.id != 0) {
        listaMenus.push_back(nuevo);
        guardarMenu();
        leerMenu();
    }
}
