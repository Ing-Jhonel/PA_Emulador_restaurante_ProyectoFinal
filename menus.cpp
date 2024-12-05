#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
using namespace std;

void menuCliente(){
	char opcion;
	do{
		cout << "Menu Cliente" << endl << endl
			<< "A) Agregar cliente" << endl
			<< "B) Editar cliente" << endl
			<< "C) Ver clientes ordenados alfabeticamente" << endl
			<< "D) Eliminar cliente" << endl
			<< "E) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 'A':
					clientes[cantClientes].agregarCliente();
					break;
				case 'B':
					clientes[cantClientes].editarCliente();
					break;
				case 'C':
					clientes[cantClientes].ordenarCliente();
					break;
				case 'D':
					clientes[cantClientes].eliminarCliente();
					break;
				case 'E':
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while(opcion!='E');
}

void menuCarta(){
	char opcion;
	do{
		cout << "Menu Carta" << endl << endl
			<< "A) Agregar comida" << endl
			<< "B) Eliminar comida" << endl
			<< "C) Editar carta" << endl
			<< "D) Ver carta" << endl
			<< "E) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 'A':
					clientes[cantClientes].agregarCliente();
					break;
				case 'B':
					clientes[cantClientes].editarCliente();
					break;
				case 'C':
					clientes[cantClientes].ordenarCliente();
					break;
				case 'D':
					clientes[cantClientes].eliminarCliente();
					break;
				case 'E':
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while(opcion!='E');
}

void menuFinanza(){
	
}
