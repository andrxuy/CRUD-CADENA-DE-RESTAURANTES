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


int main(){
	setlocale(LC_ALL, "");
	vector<Menu>menus; 

	return 0;
}
