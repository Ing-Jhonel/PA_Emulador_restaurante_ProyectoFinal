#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
#include "funcionesDiseno.h"
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
	system("pause");
	do{
		string texto; char c;
		system("cls");
		system("COLOR 70");
		texto="E S I S'S   R E S T A U R A N T E";
		c='*';
		separador(c);
		separador(c);
		centrarParaPintar(texto); 
		separador(c);
		separador(c);
		cout << endl << endl << endl;
		
		c='*';
		texto = "Elija a que menu va a entrar";
		enjaular(texto, c);
		cout << endl << endl;
			
			int anchoJaula=40;
		int salto=2;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "1. Clientes.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "2. Carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "3. Finanzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "4. Salir del programa.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		
		cin >> opcion;
		
		system("cls");
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
					c='-';
					texto="Saliendo del programa.";
					enlinear(texto, c);
					break;
				default:
					c='-';
					texto="Indique una opcion valida.";
					enlinear(texto, c);
					break;
			}
			system("cls");
	} while (opcion != 5);
	return 0;
}
