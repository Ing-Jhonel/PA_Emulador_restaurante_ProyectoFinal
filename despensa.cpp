#include <iostream>
#include "menus.h"
#include "funcionesdespensa.h"
#include "FUNCIONESDISENO.H"
using namespace std;

void menuDespensa(){
	
	char opcion;
	char c;
	string texto;
	
	do{
		color(hConsole, 111);
		c='*';
		separador(c);
		texto = "MENU DESPENSA";
		centrarParaPintar(texto);
		separador(c);
		color(hConsole, 7);
    	cout << endl << endl << endl;
    	
    	color(hConsole, 7);
		texto = "Estas en el menu del area de despensa";
		enjaular(texto, c); cout << endl << endl << endl;
		
		c='=';
		texto = "Elija que accion va a realizar";
		centrarYSubrayar(texto, c);
		cout << endl << endl;
		
    	c='*';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Agregar alimentos a la despensa.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Actualizar alimentos de la despensa.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Mostrar stock de alimentos.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Mostrar alimentos mas y menos usados.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Volver al menu principal.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		espacio();

		switch(opcion){
			
			case 'A':
				AgregarAlimentos();
				break;
			case 'B':
				actualizarAlimentos();
				break;
			case 'C':
				mostrarStock();
				break;
			case 'D':
				mostrarMasMenosUsados();
				break;
			case 'E':
				break;
			default:
				cout << endl;
				color(hConsole, 4);
				texto = "Opcion no valida. Intente de nuevo";	
				centrar(texto);
				break;
		}
		espacio();
	} while(opcion!='E');
	
		color(hConsole, 8);
		texto = "| SALIENDO DEL MENU DESPENSA... |";
		enlinear(texto, c);
		
		cout << endl << endl;
		
		texto = "| VOLVIENDO AL MENU PRINCIPAL... |";
		enlinear(texto, c);
		cout << endl << endl << endl;
		color(hConsole, 7);
} 
