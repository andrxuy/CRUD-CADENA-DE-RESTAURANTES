#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QMessageBox>   //LO PUSE PPARA MENSAJES
using namespace std;

vector<Menu> listaMenus;
string ruta="menus.txt";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listaMenus = cargarMenu();
}

MainWindow::~MainWindow(){
    delete ui;
}

vector<Menu> MainWindow::cargarMenu() {     //CARGAR
    vector<Menu> menus;
    ifstream archivo(ruta);
    if (!archivo) {
        QMessageBox::information(this, "Información","Archivo no encontrado. Se iniciará una nueva lista.");
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

bool esNumeroEntero(const QString& texto) {     //PARA VALIDAR SI SON NUMEROS INT(ID)
    bool ok;
    texto.toInt(&ok);
    return ok && texto.toInt() > 0;
}

bool esNumeroDecimalPositivo(const QString& texto) {        //PARA VALIDAR SI SON NUMEROS DOUBLE (PRECIO)
    bool ok;
    double valor = texto.toDouble(&ok);
    return ok && valor > 0;
}

Menu MainWindow::agregarMenu() {        //AGREGAR
    Menu nuevo;
    QString idTexto = ui->digitar_id->text();
    QString precioTexto = ui->escribir_precio->text();
    if (idTexto.isEmpty()) {
        QMessageBox::warning(this, "Advertencia","El campo ID no puede estar vacío.");
        return {};
    }
    if (!esNumeroEntero(idTexto)) {
        QMessageBox::warning(this, "Advertencia","El ID debe ser un número entero positivo.");
        return {};
    }
    nuevo.id = idTexto.toInt();
    for (const auto& m : listaMenus) {
        if (nuevo.id == m.id) {
            QMessageBox::critical(this, "Error", "El ID ya existe. Por favor, use un ID diferente.");
            return {};
        }
    }
    if (ui->digitar_nombre->text().isEmpty()) {
        QMessageBox::warning(this, "Advertencia","El campo Nombre no puede estar vacío.");
        return {};
    }
    nuevo.nombre = ui->digitar_nombre->text().toStdString();

    if (ui->categoria_item->currentText().isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar una categoría.");
        return {};
    }
    nuevo.categoria = ui->categoria_item->currentText().toStdString();

    if (ui->escribir_descripcion->text().isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "El campo Descripción no puede estar vacío.");
        return {};
    }
    nuevo.descripcion = ui->escribir_descripcion->text().toStdString();
    
    if (precioTexto.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "El campo Precio no puede estar vacío.");
        return {};
    }
    if (!esNumeroDecimalPositivo(precioTexto)) {
        QMessageBox::warning(this, "Advertencia", "El precio no puede ser un valor negativo ni cero. $0");
        return {};
    }
    nuevo.precio = precioTexto.toDouble();
    return nuevo;
}

void MainWindow::guardarMenu() {        //PARA GUARDAR
    ofstream archivo(ruta);
    if (!archivo) {
        QMessageBox::critical(this, "Error","Error al abrir el archivo para guardar.");
        return;
    }
    for (const auto& m : listaMenus) {
        archivo << m.id << "|"<< m.nombre << "|"<< m.categoria << "|"
                << m.descripcion << "|"<< m.precio << "\n";
    }
    QMessageBox::information(this, "Éxito","Menú guardado correctamente.");
}

void MainWindow::leerMenu() {       //PARA MOSTRAR TODOS LOS MENUS
    ui->tabla_registros->setRowCount(0);
    if (listaMenus.empty()) {
        QMessageBox::information(this, "Información","No hay menús registrados.");
        return;
    }
    int fila = 0;
    for (const auto& m : listaMenus) {
        ui->tabla_registros->insertRow(fila);
        ui->tabla_registros->setItem(fila, 0, new QTableWidgetItem(QString::number(m.id)));
        ui->tabla_registros->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(m.nombre)));
        ui->tabla_registros->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(m.categoria)));
        ui->tabla_registros->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(m.descripcion)));
        ui->tabla_registros->setItem(fila, 4, new QTableWidgetItem(QString("$ %1").arg(m.precio, 0, 'f', 2)));
        fila++;
    }
}

void MainWindow::buscarMenu(){ //PARA BUSCAR POR ID
    QString idTexto = ui->digitar_id->text();
    if (idTexto.isEmpty()) {
        QMessageBox::warning(this, "Advertencia","Debe ingresar un ID para buscar.");
        return;
    }
    if (!esNumeroEntero(idTexto)) {
        QMessageBox::warning(this, "Advertencia","El ID debe ser un número entero positivo.");
        return;
    }
    int idBuscar = idTexto.toInt();
    ui->tabla_registros->setRowCount(0);
    bool encontrado = false;
    for (const auto& m : listaMenus) {
        if (m.id == idBuscar) {
            int fila = ui->tabla_registros->rowCount();
            ui->tabla_registros->insertRow(fila);
            ui->tabla_registros->setItem(fila, 0, new QTableWidgetItem(QString::number(m.id)));
            ui->tabla_registros->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(m.nombre)));
            ui->tabla_registros->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(m.categoria)));
            ui->tabla_registros->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(m.descripcion)));
            ui->tabla_registros->setItem(fila, 4, new QTableWidgetItem(QString("$ %1").arg(m.precio, 0, 'f', 2)));
            QMessageBox::information(this, "Éxito", "Menú encontrado.");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        QMessageBox::warning(this, "No encontrado","ID no encontrado en los registros.");
    }
}

void MainWindow::actualizarMenu() {       //PARA ACTUALIZAR LOS MENUS
   vector<Menu> menus = cargarMenu(); // cargar desde archivo
    QString idTexto = ui->digitar_id->text();
    bool encontrado = false;

    if (idTexto.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Ingrese el ID del menú a actualizar.");
        return;
    }

    if (!esNumeroEntero(idTexto)) {
        QMessageBox::warning(this, "Advertencia", "El ID debe ser un número entero positivo.");
        return;
    }

    int idBuscar = idTexto.toInt();

    for (Menu &m : menus) {
        if (m.id == idBuscar) {

            // Validaciones similares al agregar
            if (ui->digitar_nombre->text().isEmpty() ||
                ui->escribir_descripcion->text().isEmpty() ||
                ui->categoria_item->currentText().isEmpty() ||
                ui->escribir_precio->text().isEmpty()) {

                QMessageBox::warning(this, "Advertencia",
                                     "Todos los campos deben estar llenos.");
                return;
            }

            if (!esNumeroDecimalPositivo(ui->escribir_precio->text())) {
                QMessageBox::warning(this, "Advertencia",
                                     "El precio debe ser un número positivo.");
                return;
            }

            // === ACTUALIZACIÓN (igual a tu ejemplo) ===
            m.nombre = ui->digitar_nombre->text().toStdString();
            m.descripcion = ui->escribir_descripcion->text().toStdString();
            m.categoria = ui->categoria_item->currentText().toStdString();
            m.precio = ui->escribir_precio->text().toDouble();

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        QMessageBox::warning(this, "No encontrado",
                             "No se encontró un menú con ese ID.");
        return;
    }

    // Reescribir archivo con datos actualizados
    ofstream archivo(ruta);
    if (!archivo) {
        QMessageBox::critical(this, "Error",
                              "Error al abrir el archivo para actualizar.");
        return;
    }

    for (const auto& m : menus) {
        archivo << m.id << "|"
                << m.nombre << "|"
                << m.categoria << "|"
                << m.descripcion << "|"
                << m.precio << "\n";
    }

    QMessageBox::information(this, "Éxito",
                             "MENÚ ACTUALIZADO CORRECTAMENTE");

    // sincroniza la lista en memoria
    listaMenus = menus;

    leerMenu();
}

void MainWindow::eliminarMenu() {
    QString idTexto = ui->digitar_id->text();

    if (idTexto.isEmpty()) {
        QMessageBox::warning(this, "Advertencia",
                             "Ingrese el ID del menú a eliminar.");
        return;
    }

    if (!esNumeroEntero(idTexto)) {
        QMessageBox::warning(this, "Advertencia",
                             "El ID debe ser un número entero positivo.");
        return;
    }

    int id = idTexto.toInt();
    bool encontrado = false;

    for (auto it = listaMenus.begin(); it != listaMenus.end(); ++it) {
        if (it->id == id) {
            listaMenus.erase(it);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        QMessageBox::warning(this, "Error",
                             "No se encontró un menú con ese ID.");
        return;
    }
    QMessageBox::information(this, "Éxito",
                             "Menú eliminado correctamente.");

    guardarMenu();

    leerMenu();
    ui->digitar_id->clear();
}

//CONEXIÓN DE BOTONES
void MainWindow::on_agregar_clicked(){
    Menu nuevo = agregarMenu();
    if (nuevo.id != 0) {
        listaMenus.push_back(nuevo);
        guardarMenu();
        leerMenu();
        ui->digitar_id->clear();
        ui->digitar_nombre->clear();
        ui->escribir_descripcion->clear();
        ui->escribir_precio->clear();
        ui->categoria_item->setCurrentIndex(0);
    }
}

void MainWindow::on_buscar_clicked(){
    buscarMenu();
    ui->digitar_id->clear();
    ui->digitar_nombre->clear();
    ui->escribir_descripcion->clear();
    ui->escribir_precio->clear();
    ui->categoria_item->setCurrentIndex(0);
}

void MainWindow::on_mostrar_clicked(){
    leerMenu();
}

void MainWindow::on_actualizar_clicked(){
    actualizarMenu();
    ui->digitar_id->clear();
    ui->digitar_nombre->clear();
    ui->escribir_descripcion->clear();
    ui->escribir_precio->clear();
    ui->categoria_item->setCurrentIndex(0);
}

void MainWindow::on_eliminar_clicked(){
    eliminarMenu();
    ui->digitar_id->clear();
    ui->digitar_nombre->clear();
    ui->escribir_descripcion->clear();
    ui->escribir_precio->clear();
    ui->categoria_item->setCurrentIndex(0);
}

