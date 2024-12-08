#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
#include "funcionesMenuAdministracion.h"

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
			<< "D) Ordenar comida" << endl
			<< "E) Ver carta" << endl
			<< "F) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 'A':
					comida[cantComidas].agregarComida();
					break;
				case 'B':
					comida[cantComidas].editarCarta();
					break;
				case 'C':
					comida[cantComidas].eliminarComida();
					break;
				case 'D':
					comida[cantComidas].ordenarComida();
					break;
				case 'E':
					comida[cantComidas].verCarta();
					break;
				case 'F':
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while(opcion!='F');
}

void menuAdministracion(){
	char opcion;
	do{
		cout << "Menu Administracion" << endl << endl
			<< "A) Mostr<ar facturas" << endl
			<< "B) Gastos y ganancias" << endl
			<< "C) Ordenar mas vendido" << endl
			<< "D) Estadisticas generales" << endl
			<< "E) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 'A':
					Administracion::mostrarFacturas();
					break;
				case 'B':
					Administracion::gastosYGanancias();
					break;
				case 'C':
					Administracion::ordenarMasVendido();
					break;
				case 'D':
					Administracion::estadisticasGenerales();
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
