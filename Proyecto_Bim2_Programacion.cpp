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

void agregar(vector<Menu>& menus){
	Menu m;
	cout<<"\nIngrese el ID del menú: ";
	cin>>m.id;
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

int main(){
	setlocale(LC_ALL, "");
	vector<Menu>menus; 

	return 0;
}

