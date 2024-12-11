#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
using namespace std;

int main(){
	Cliente registroCliente;
	registroCliente.leerDatosClienteEnArchivoBase(clientes, cantClientes);
	Carta registroComidas;
	registroComidas.leerDatosComidasEnArchivoBase(comidas, cantComidas);

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
					//menuFinanzas();
					break;
				case 4:
					//menuAdministracion();
					break;
				case 5:
					cout << "Saliendo del programa." << endl;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while (opcion != 5);
	//registroCliente.guardarDatosClienteEnArchivoFinal();
	return 0;
}
