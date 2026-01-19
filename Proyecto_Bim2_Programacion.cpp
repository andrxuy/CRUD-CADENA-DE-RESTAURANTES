/* PROYECTO SEGUNDO BIMESTRE "MENUS EN CADENA DE RESTAURANTES"
VERSIÓN DE ARCHIVOS
Andrés Oto
Matías Borja
David Pilatuña*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include <locale>
using namespace std;
//estructura

struct Menu {
    int id;
    string nombre;
    string descripcion;
    string categoria;
    double precio;
};

vector<Menu> listaMenus;
string ruta = "menus.txt";

vector<Menu> cargarMenu() {
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
            if (campo == 0) {
                m.id = stoi(token);
            } else if (campo == 1) {
                m.nombre = token;
            } else if (campo == 2) {
                m.descripcion = token;
            } else if (campo == 3) {
                m.categoria = token;
            }
            linea.erase(0, pos + 1);
            campo++;
        }
        m.precio = stod(linea);

        menus.push_back(m);
    }
    return menus;
}

Menu agregarMenu() {
    Menu nuevoMenu;
    cout << "Ingrese el ID del menú: ";
    cin >> nuevoMenu.id;

    for (const auto& menu : listaMenus) {
        if (nuevoMenu.id == menu.id) {
            cout << "\nEl menú ya existe (ID duplicado).\n";
            return {}; 
        }
    }
    cin.ignore(); 
    cout << "Ingrese el nombre del menú: ";
    getline(cin, nuevoMenu.nombre);
    cout << "Ingrese la descripción del menú: ";
    getline(cin, nuevoMenu.descripcion);
    cout << "Ingrese la categoría del menú: ";
    getline(cin, nuevoMenu.categoria);
    cout << "Ingrese el precio del menú: ";
    cin >> nuevoMenu.precio;
	cout<<"\nMenu Registrado Con Éxito.\n";
    return nuevoMenu;
}

void buscar(vector<Menu>& menus) {
    int idBuscar;
    bool encontrado = false;
    
    cout << "\nIngrese el ID del menú a buscar: ";
    cin >> idBuscar;
    
    for (Menu &m : menus) {
        if (m.id == idBuscar) {
            cout << "\n=== MENÚ ENCONTRADO ===";
            m.mostrar();
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "\nNo se encontró un menú con el ID: " << idBuscar << endl;
    }
}

void guardarMenu(){
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "\nError al abrir el archivo para guardar.\n";
        return;
    }
    for (const auto& m : listaMenus) {
        archivo << m.id << "|"
                << m.nombre << "|"
                << m.descripcion << "|"
                << m.categoria << "|"
                << m.precio << "\n";
    }
}
//LO DE ABAJO DESDE LA 122 HASTA LA 156, SIGUE SIENDO EN CONSOLA
void actualizar(vector<Menu>& menus){
	int idBuscar;
	bool encontrado = false;

	cout << "\nIngrese el ID del menú a actualizar: ";
	cin >> idBuscar;
	cin.ignore();

	for (Menu &m : menus){
		if (m.id == idBuscar){
			cout << "\n=== MENÚ ENCONTRADO ===";
			m.mostrar();

			cout << "\nIngrese el nuevo nombre: ";
			getline(cin, m.nombre);

			cout << "Ingrese la nueva descripción: ";
			getline(cin, m.descripcion);

			cout << "Ingrese la nueva categoría: ";
			getline(cin, m.categoria);

			cout << "Ingrese el nuevo precio: ";
			cin >> m.precio;

			cout << "\nMENÚ ACTUALIZADO CORRECTAMENTE\n";
			encontrado = true;
			break;
		}
	}

	if (!encontrado){
		cout << "\nNo se encontró un menú con ese ID\n";
	}
}

//SOLO LA OPCION (case: 1) está con archivos, tomar en cuenta
int main() {
    setlocale(LC_ALL, "");

    listaMenus = cargarMenu();

    int opcion=-1;

    while (true) {
        cout << "\n*=*=*=*=*=*=*=*=*=* APP REGISTRO MENÚS *=*=*=*=*=*=*=*=*=*\n";
        cout << "1. Registrar nuevo menú\n";
        cout << "2. Buscar un menú\n";
		cout << "3. Actualizar Menú" << endl;
        //cout << "5. Mostrar todos los menús\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Menu nuevo = agregarMenu();
                if (nuevo.id != 0) {  
                    listaMenus.push_back(nuevo);
                    guardarMenu();
                }
                break;
			case 2:
				buscar(menus);
				break;
			case 3:
				actualizar(menus);
				break;
            case 0:
                cout << "\nSALIENDO DEL SISTEMA...\n";
                return 0;

            default:
                cout << "\nOPCIÓN INVÁLIDA. DÍGITE UNA OPCIÓN CORRECTA\n";
        }
    }
    return 0;
}



