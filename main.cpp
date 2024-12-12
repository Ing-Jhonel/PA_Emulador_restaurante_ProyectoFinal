#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
using namespace std;

int main(){
	Factura registroFacturas;
	registroFacturas.leerDatosFacturaEnArchivoBase(facturas, cantFacturas);
	Cliente registroCliente;
	registroCliente.leerDatosClienteEnArchivoBase(clientes, cantClientes);
	Carta registroComidas;
	registroComidas.leerDatosComidasEnArchivoBase(comidas, cantComidas); 
	/*
	cout << endl << endl << cantComidas << endl << endl;
	for(int i=0; i<cantClientes; i++){
		cout << clientes[i].getNombre() << endl;
	}*/
	cout << endl;
	int opcion;
	do{
		cout << "Menu Principal" << endl << endl
			<< "1) Clientes" << endl
			<< "2) Carta" << endl
			<< "3) Finanzas" << endl
			<< "4) Administracion" << endl 
			<< "5) Salir "<< endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 1:
					menuClientes();
					break;
				case 2:
					menuCarta();
					break;
				case 3:
					menuFinanzas();
					break;
				case 4:
					//menuAdministracion();
					break;
				case 5:
					cout << "Saliendo del programa." << endl;
					break;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while (opcion != 5);
	/*cout << endl << endl << cantComidas << endl << endl;
	for(int i=0; i<cantComidas; i++){
		cout << comidas[i].getNombre() << endl;
	}
	cout << endl;*/
	
	//registroCliente.guardarDatosClienteEnArchivoFinal();
	return 0;
}
