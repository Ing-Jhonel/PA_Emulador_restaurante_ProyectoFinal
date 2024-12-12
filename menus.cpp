#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
#include "funcionesMenuFinanzas.h"
using namespace std;

Personas::Personas(string n, string t, string c, int e, int dni){
	nombre=n;
	telefono=t;
	correo=c;
	edad=e;
	DNI=dni;
}
void Personas::mostrarDatos(){
	cout << "Nombre: " << nombre << endl
		<< "Edad: " << edad << endl
		<< "DNI: " << DNI << endl
		<< "Telefono: " << telefono << endl
		<< "Correo: " << correo << endl;
}


void menuClientes(){
	char opcion;
	do{
		cout << "Menu Cliente" << endl << endl
			<< "A) Agregar cliente" << endl
			<< "B) Editar cliente" << endl
			<< "C) Eliminar cliente" << endl
			<< "D) Ver clientes ordenados alfabeticamente" << endl
			<< "E) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 'A':
					clientes[cantClientes].agregarClientes();
					break;
				case 'B':
					clientes[cantClientes].editarClientes();
					break;
				case 'C':
					clientes[cantClientes].eliminarClientes();
					break;
				case 'D':
					clientes[cantClientes].mostrarOrdenadosClientes();
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
	Carta cartas;
	do{
		cout << "Menu Carta" << endl << endl
			<< "A) Agregar comida" << endl
			<< "B) Editar comida" << endl
			<< "C) Eliminar carta" << endl
			<< "D) Ordenar comida" << endl
			<< "E) Ver carta" << endl
			<< "F) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			cout << endl << endl;
			switch(opcion){
				case 'A':
					cartas.agregarComida();
					break;
				case 'B':
					cartas.editarComida();
					break;
				case 'C':
					cartas.eliminarComida();
					break;
				case 'D':
					cartas.ordenarComida();
					break;
				case 'E':
					cartas.mostrarCarta();
					break;
				case 'F':
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
			cout << endl << endl;
	} while(opcion!='F');
}

void menuFinanzas(){
	Finanza finanzas;
	char opcion;
	do{
		cout << "Menu Finanzas" << endl << endl
			<< "A) Gastos y ganancias" << endl
			<< "B) Ordenar mas vendido" << endl
			<< "C) Estadisticas generales" << endl
			<< "D) Mostrar facturas" << endl
			<< "E) Volver menu principal" << endl << endl
			<< "= "; cin >> opcion;
			
			cout << endl << endl;
			switch(opcion){
				case 'A':
					finanzas.mostrarGastosYGanancias();
					break;
				case 'B':
					finanzas.ordenarMasVendido();
					break;
				case 'C':
					finanzas.mostrarEstadisticasGenerales();
					break;
				case 'D':
					finanzas.mostrarFacturas();
					break;
				case 'E':
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
			cout << endl << endl;
	} while(opcion!='E');
}

void menuAdministracion(){
	char opcion;
	do{
		cout << "Menu Administracion" << endl << endl
			<< "A) Contratar personal" << endl
			<< "B) Despedir personal" << endl
			<< "C) Ver personal" << endl
			<< "D) Informacion general" << endl
			<< "E) Cambiar nombre de empresa" << endl
			<< "F) Reiniciar datos de empresa" << endl
			<< "G) Volver menu principal" << endl << endl
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
				case 'D':
					Administracion::estadisticasGenerales();
					break;
				case 'D':
					Administracion::estadisticasGenerales();
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
	} while(opcion!='G');
}

