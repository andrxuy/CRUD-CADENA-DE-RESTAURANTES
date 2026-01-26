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

void buscarMenu() {
    int id;
    cout << "Ingrese el ID del menú a buscar: ";
    cin >> id;
    ifstream archivo(ruta);
    if (!archivo) {
        cerr << "\nNo se pudo abrir el archivo menus.txt\n";
        return;
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
        if (m.id == id) {
            cout << "\n=================== MENÚ ENCONTRADO =============== \n";
            cout << "ID: " << m.id << endl;
            cout << "Nombre: " << m.nombre << endl;
            cout << "Descripción: " << m.descripcion << endl;
            cout << "Categoría: " << m.categoria << endl;
            cout << "Precio: $" << m.precio<< endl;
            return;
        }
    }
    cout << "\nMenú no encontrado\n";
}

void leerMenu() {
    if (listaMenus.empty()) {
        cout << "\nNo hay menús registrados\n";
    } else {
        cout << "\n*=*=*=*=*=*=*=*=*=* LISTA DE MENÚS REGISTRADOS *=*=*=*=*=*=*=*=*=*\n";
        for (const auto& m : listaMenus) {
            cout <<"ID: "<< m.id << "\nNombre: " << m.nombre << "\nDescripción: "
                 << m.descripcion << "\nCategoria: " << m.categoria
                 << "\nPrecio: $" << m.precio << endl;
        }
    }
}

//LO DE ABAJO DESDE LA 159 HASTA LA 189, SIGUE SIENDO EN CONSOLA
void actualizar() {
    vector<Menu> menus = cargarMenu(); // cargar desde archivo
    int idBuscar;
    bool encontrado = false;

    cout << "\nIngrese el ID del menú a actualizar: ";
    cin >> idBuscar;
    cin.ignore();

    for (Menu &m : menus) {
        if (m.id == idBuscar) {
            cout << "\n=== MENÚ ENCONTRADO ===\n";
            cout << "ID: " << m.id << endl;
            cout << "Nombre actual: " << m.nombre << endl;
            cout << "Descripción actual: " << m.descripcion << endl;
            cout << "Categoría actual: " << m.categoria << endl;
            cout << "Precio actual: $" << m.precio << endl;

            cout << "\nIngrese el nuevo nombre: ";
            getline(cin, m.nombre);

            cout << "Ingrese la nueva descripción: ";
            getline(cin, m.descripcion);

            cout << "Ingrese la nueva categoría: ";
            getline(cin, m.categoria);

            cout << "Ingrese el nuevo precio: ";
            cin >> m.precio;

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontró un menú con ese ID\n";
        return;
    }

    // Reescribir archivo con datos actualizados
    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "\nError al abrir el archivo para actualizar.\n";
        return;
    }

    for (const auto& m : menus) {
        archivo << m.id << "|"
                << m.nombre << "|"
                << m.descripcion << "|"
                << m.categoria << "|"
                << m.precio << "\n";
    }

    cout << "\nMENÚ ACTUALIZADO CORRECTAMENTE\n";

    // sincroniza la lista en memoria
    listaMenus = menus;
}
void eliminarMenu() {
    vector<Menu> menus = cargarMenu();
    int idEliminar;
    bool encontrado = false;

    cout << "\nIngrese el ID del menú a eliminar: ";
    cin >> idEliminar;

    auto it = remove_if(menus.begin(), menus.end(),
                        [idEliminar](const Menu& m) {
                            return m.id == idEliminar;
                        });

    if (it != menus.end()) {
        menus.erase(it, menus.end());
        encontrado = true;
    }

    if (!encontrado) {
        cout << "\nNo se encontró un menú con ese ID\n";
        return;
    }

    ofstream archivo(ruta);
    if (!archivo) {
        cerr << "\nError al abrir el archivo para eliminar\n";
        return;
    }

    for (const auto& m : menus) {
        archivo << m.id << "|"
                << m.nombre << "|"
                << m.descripcion << "|"
                << m.categoria << "|"
                << m.precio << "\n";
    }

    listaMenus = menus;
    cout << "\nMENÚ ELIMINADO CORRECTAMENTE\n";
}

//SOLO LA OPCION (case: 1) está con archivos, tomar en cuenta
int main() {
    setlocale(LC_ALL, "");

    listaMenus = cargarMenu();

    int opcion=-1;

    while (true) {
        cout << "\n*=*=*=*=*=*=*=*=*=* APP REGISTRO MENÚS *=*=*=*=*=*=*=*=*=*\n";
        cout << "1. Registrar nuevo menú.\n";
        cout << "2. Buscar un menú.\n";
		cout << "3. Actualizar Menú." << endl;
		cout << "4. Eliminar Menú."<<endl
        cout << "5. Mostrar todos los menús.\n";
        cout << "0. Salir.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Menu nuevo = agregarMenu();
                if (nuevo.id != 0) {  
                    listaMenus.push_back(nuevo);
                    guardarMenu();
                }
            }
                break;
			case 2:
				buscarMenu();
				break;
			case 3:
				actualizar();
				break;
			case 4:
			    eliminarMenu();
			    break;
			case 5:
				leerMenu();
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





