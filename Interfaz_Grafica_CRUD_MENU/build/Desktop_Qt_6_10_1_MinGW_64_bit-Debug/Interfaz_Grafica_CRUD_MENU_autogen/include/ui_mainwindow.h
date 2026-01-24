/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titulo;
    QLabel *saludo;
    QPushButton *agregar;
    QPushButton *buscar;
    QPushButton *actualizar;
    QPushButton *eliminar;
    QPushButton *mostrar;
    QLabel *nombre_menu;
    QLabel *categoria;
    QLineEdit *digitar_nombre;
    QLabel *id_menu;
    QLineEdit *digitar_id;
    QLineEdit *escribir_descripcion;
    QLabel *descripcion;
    QLineEdit *escribir_precio;
    QLabel *precio;
    QComboBox *categoria_item;
    QTableWidget *tabla_registros;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(958, 939);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titulo = new QLabel(centralwidget);
        titulo->setObjectName("titulo");
        titulo->setGeometry(QRect(200, 20, 701, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(48);
        font.setBold(true);
        font.setItalic(false);
        titulo->setFont(font);
        saludo = new QLabel(centralwidget);
        saludo->setObjectName("saludo");
        saludo->setGeometry(QRect(350, 100, 351, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(36);
        saludo->setFont(font1);
        agregar = new QPushButton(centralwidget);
        agregar->setObjectName("agregar");
        agregar->setGeometry(QRect(10, 410, 151, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setItalic(false);
        agregar->setFont(font2);
        buscar = new QPushButton(centralwidget);
        buscar->setObjectName("buscar");
        buscar->setGeometry(QRect(180, 410, 151, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(15);
        font3.setBold(true);
        buscar->setFont(font3);
        actualizar = new QPushButton(centralwidget);
        actualizar->setObjectName("actualizar");
        actualizar->setGeometry(QRect(350, 410, 181, 71));
        actualizar->setFont(font3);
        eliminar = new QPushButton(centralwidget);
        eliminar->setObjectName("eliminar");
        eliminar->setGeometry(QRect(550, 410, 151, 71));
        eliminar->setFont(font3);
        mostrar = new QPushButton(centralwidget);
        mostrar->setObjectName("mostrar");
        mostrar->setGeometry(QRect(720, 410, 221, 71));
        mostrar->setFont(font3);
        nombre_menu = new QLabel(centralwidget);
        nombre_menu->setObjectName("nombre_menu");
        nombre_menu->setGeometry(QRect(430, 190, 161, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(18);
        font4.setBold(true);
        nombre_menu->setFont(font4);
        categoria = new QLabel(centralwidget);
        categoria->setObjectName("categoria");
        categoria->setGeometry(QRect(110, 260, 111, 31));
        categoria->setFont(font4);
        digitar_nombre = new QLineEdit(centralwidget);
        digitar_nombre->setObjectName("digitar_nombre");
        digitar_nombre->setGeometry(QRect(600, 190, 231, 26));
        id_menu = new QLabel(centralwidget);
        id_menu->setObjectName("id_menu");
        id_menu->setGeometry(QRect(110, 190, 111, 31));
        id_menu->setFont(font4);
        digitar_id = new QLineEdit(centralwidget);
        digitar_id->setObjectName("digitar_id");
        digitar_id->setGeometry(QRect(230, 190, 91, 26));
        escribir_descripcion = new QLineEdit(centralwidget);
        escribir_descripcion->setObjectName("escribir_descripcion");
        escribir_descripcion->setGeometry(QRect(580, 260, 351, 91));
        descripcion = new QLabel(centralwidget);
        descripcion->setObjectName("descripcion");
        descripcion->setGeometry(QRect(430, 260, 141, 31));
        descripcion->setFont(font4);
        escribir_precio = new QLineEdit(centralwidget);
        escribir_precio->setObjectName("escribir_precio");
        escribir_precio->setGeometry(QRect(200, 330, 111, 26));
        precio = new QLabel(centralwidget);
        precio->setObjectName("precio");
        precio->setGeometry(QRect(110, 330, 91, 31));
        precio->setFont(font4);
        categoria_item = new QComboBox(centralwidget);
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->addItem(QString());
        categoria_item->setObjectName("categoria_item");
        categoria_item->setGeometry(QRect(230, 260, 111, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Times New Roman")});
        font5.setPointSize(13);
        categoria_item->setFont(font5);
        tabla_registros = new QTableWidget(centralwidget);
        if (tabla_registros->columnCount() < 5)
            tabla_registros->setColumnCount(5);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Times New Roman")});
        font6.setPointSize(12);
        font6.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font6);
        tabla_registros->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font6);
        tabla_registros->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font6);
        tabla_registros->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font6);
        tabla_registros->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font6);
        tabla_registros->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tabla_registros->setObjectName("tabla_registros");
        tabla_registros->setGeometry(QRect(20, 500, 911, 391));
        tabla_registros->horizontalHeader()->setCascadingSectionResizes(false);
        tabla_registros->horizontalHeader()->setDefaultSectionSize(180);
        tabla_registros->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tabla_registros->verticalHeader()->setVisible(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 958, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CRUD Men\303\272\360\237\223\213\360\237\221\250\342\200\215\360\237\215\263\360\237\215\275\357\270\217", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213CRUD MEN\303\232\360\237\221\250\342\200\215\360\237\215\263\360\237\215\275\357\270\217", nullptr));
        saludo->setText(QCoreApplication::translate("MainWindow", "\302\241BIENVENIDO!", nullptr));
        agregar->setText(QCoreApplication::translate("MainWindow", "\342\234\250AGREGAR ", nullptr));
        buscar->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 BUSCAR ", nullptr));
        actualizar->setText(QCoreApplication::translate("MainWindow", "\360\237\233\240\357\270\217ACTUALIZAR ", nullptr));
        eliminar->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 ELIMINAR ", nullptr));
        mostrar->setText(QCoreApplication::translate("MainWindow", "\360\237\221\200MOSTRAR MEN\303\232S", nullptr));
        nombre_menu->setText(QCoreApplication::translate("MainWindow", "Nombre Men\303\272:", nullptr));
        categoria->setText(QCoreApplication::translate("MainWindow", "Categor\303\255a:", nullptr));
        id_menu->setText(QCoreApplication::translate("MainWindow", "ID Men\303\272 :", nullptr));
        descripcion->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n:", nullptr));
        precio->setText(QCoreApplication::translate("MainWindow", "Precio:", nullptr));
        categoria_item->setItemText(0, QString());
        categoria_item->setItemText(1, QCoreApplication::translate("MainWindow", "Desayuno", nullptr));
        categoria_item->setItemText(2, QCoreApplication::translate("MainWindow", "Almuerzo", nullptr));
        categoria_item->setItemText(3, QCoreApplication::translate("MainWindow", "Merienda", nullptr));
        categoria_item->setItemText(4, QCoreApplication::translate("MainWindow", "Postres", nullptr));
        categoria_item->setItemText(5, QCoreApplication::translate("MainWindow", "C\303\263cteles", nullptr));
        categoria_item->setItemText(6, QCoreApplication::translate("MainWindow", "Bebidas", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tabla_registros->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabla_registros->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NOMBRE", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabla_registros->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "CATEGOR\303\215A", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabla_registros->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "DESCRIPCI\303\223N", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabla_registros->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "PRECIO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
