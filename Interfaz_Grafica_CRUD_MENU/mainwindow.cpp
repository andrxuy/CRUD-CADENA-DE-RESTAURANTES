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
