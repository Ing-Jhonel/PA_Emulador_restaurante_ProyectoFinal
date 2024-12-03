#include <iostream>
#include "menus.h"
#include "funcionesfinanzas.h"
#include "FUNCIONESDISENO.h"
using namespace std;

void menuFinanzas(){
	char opcion;
	char c;
	string texto;

	do{
		color(hConsole, 160);
		c='*';
		separador(c);
		texto = "$$$ AREA DE FINANZAS $$$";
		centrarParaPintar(texto);
		separador(c);
		color(hConsole, 7);
    	cout << endl << endl << endl;

		texto = "Estas en el menu del area de finanzas";
		enjaular(texto, c); cout << endl << endl << endl;
		c='=';
		color(hConsole, 2);
		texto = "Elija que accion va a realizar";
		centrarYSubrayar(texto, c);
		cout << endl << endl;
		
		color(hConsole, 7);
    	c='*';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Registrar ordenes.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Mostrar facturas de ordenes registradas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Gastos y ganancias.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Ordenar por lo mas o menos vendido.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Estadisticas generales.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "F) Salir del area de finanzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		
		espacio();
		
		switch(opcion){
			case 'A':
				registrarVenta();
				break;
			case 'B':
				mostrarOrdenes();
				break;
			case 'C':
				gastosGanancias();
				break;
			case 'D':
				ordenarMasVendido();
				break;
			case 'E':
				estadisticasGenerales();
				break;
			case 'F':
				break;
			default:
				cout << endl;
				color(hConsole, 4);
				texto = "Opcion no valida. Intente de nuevo";	
				centrar(texto);
				break;
		}
		espacio();
	}while(opcion!='F');
	
		color(hConsole, 8);
		texto = "| SALIENDO DEL MENU DE FINANZAS... |";
		enlinear(texto, c);
		
		cout << endl << endl;
		
		texto = "| VOLVIENDO AL MENU PRINCIPAL... |";
		enlinear(texto, c);
		cout << endl << endl << endl;
		color(hConsole, 7);
}
