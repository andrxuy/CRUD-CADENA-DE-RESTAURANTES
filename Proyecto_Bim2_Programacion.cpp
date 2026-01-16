/* PROYECTO SEGUNDO BIMESTRE "MENUS EN CADENA DE RESTAURANTES"
Andrés Oto
Matías Borja
David Pilatuña*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <locale>
using namespace std;
//estructura

struct Menu{
	int id;
	string nombre;
	string descripcion;
	string categoria;
	double precio;
	
	void mostrar(){
		cout << "\nID: " << id << "\n" << "Nombre: " << nombre << "\n"
	    << "Descripción: " << descripcion << "\n"
	    << "Categoría: " << categoria << "\n"
	    << "Precio: $" << precio << "\n";
	}	
};

void recorrer(vector<Menu>& menus){
	for(Menu m:menus){
		m.mostrar();
	}
}

void agregar(vector<Menu>& menus) {
    Menu m;
    bool idDuplicado;
    
    do {
        idDuplicado = false;
        cout << "\nIngrese el ID del menú: ";
        cin >> m.id;
        
        for(int i = 0; i < menus.size(); i++) {
            if(menus[i].id == m.id) {
            	cout<<"\n";
                cout << "El ID ingresado ya existe. Intente con otro";
                cout<<"\n";
                idDuplicado = true;
                break;
            }
        }
    } while(idDuplicado);  
    
    cin.ignore();
    cout<<"Ingrese el nombre del menú: ";
	getline(cin, m.nombre);
	cout<<"Ingrese la descripcion del menú: ";
	getline(cin, m.descripcion);
	cout<<"Ingrese la categoria del menú: ";
	getline(cin, m.categoria);
	cout<<"Ingrese el precio del menú: ";
	cin>>m.precio;
	cout<<endl;
	menus.push_back(m);
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

int main(){
	setlocale(LC_ALL, "");
	
	int op=-1;
	vector<Menu>menus; 
	
	while(op!=-0){
	cout << "\n*=*=*=*=*=*=*=*=*=*APP REGISTRO MENÚS*=*=*=*=*=*=*=*=*=*"<<endl;
	cout << "\n1. Mostrar Menús"<<endl;
	cout << "2. Insertar nuevo Menú"<<endl;;
	cout << "3. Actualizar Menú" << endl;
	cout << "4. Buscar Menú"<<endl;
	cout << "0. Salir del sistema"<<endl;;
	cout << "Digite opcion: ";
	cin >> op;	
	
	switch(op){
		case 1:
			recorrer(menus);
			break;
		case 2:
			agregar(menus);
			break;
		case 3:
			actualizar(menus);
			break;
		case 4:
			buscar(menus);
			break;	
		case 0:
			cout<<"\nSALIENDO DEL SISTEMA...."<<endl;
			break;
		default:
			cout<<"\nOPCIÓN INCORRECTA"<<endl;		
	}
	}
	

	
	return 0;
}



