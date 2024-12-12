#include <iostream>
#include "menus.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuCarta.h"
#include "funcionesMenuFinanzas.h"
#include "funcionesDiseno.h"
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
	char opcion; string texto; char c;
	do{
		separador(c);
		texto="MENU CLIENTE";
		c='+';
		separador(c);
		centrarParaPintar(texto); 
		separador(c);
		cout << endl << endl << endl;
		
		c='.';
		texto = "Indique la accion a realizar";
		enjaular(texto, c);
		cout << endl << endl;
			
		int anchoJaula=50;
		int salto=2;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Agregar cliente";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Editar cliente";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Eliminar cliente";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Ver clientes ordenados alfabeticamente";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Volver menu principal";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		
		system("cls");
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
					c='-';
					texto="Volviendo al menu principal.";
					enlinear(texto, c);
					break;
				default:
					c='-';
					texto="Indique una opcion valida.";
					enlinear(texto, c);
					break;
			}cout << endl << endl;system("pause");system("cls");
	} while(opcion!='E');
}

void menuCarta(){
	char opcion;
	Carta cartas;
	char c; string texto;
	do{
		c='/';
		separador(c);
		texto="MENU CARTA";
		separador(c);
		centrarParaPintar(texto); 
		separador(c);
		cout << endl << endl << endl;
		
		c='.';
		texto = "Indique la accion a realizar";
		enjaular(texto, c);
		cout << endl << endl;
			
		int anchoJaula=50;
		int salto=2;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Agregar comida";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Editar carta";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Eliminar comida";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Ordenar comida";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Ver carta";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "F) Volver menu principal";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
			system("cls");
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
					c='-';
					texto="Volviendo al menu principal.";
					enlinear(texto, c);
					break;
				default:
					c='-';
					texto="Indique una opcion valida.";
					enlinear(texto, c);
					break;
			}
			cout << endl << endl;system("pause");system("cls");
	} while(opcion!='F');
}

void menuFinanzas(){
	Finanza finanzas;
	char opcion; char c; string texto;
	do{
		c='$';
		separador(c);
		texto="MENU FINANZAS";
		separador(c);
		centrarParaPintar(texto); 
		separador(c);
		cout << endl << endl << endl;
		
		c='.';
		texto = "Indique la accion a realizar";
		enjaular(texto, c);
		cout << endl << endl;
			
		int anchoJaula=50;
		int salto=2;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Gastos y ganancias";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Ordenar mas vendido";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Estadisticas generales";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Mostrar facturas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Volver menu principal";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		
		system("cls");
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
					c='-';
					texto="Volviendo al menu principal.";
					enlinear(texto, c);
					break;
				default:
					c='-';
					texto="Indique una opcion valida.";
					enlinear(texto, c);
					break;
			}
			cout << endl << endl;system("pause");system("cls");
	} while(opcion!='E');
}
