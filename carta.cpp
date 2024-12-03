#include "menus.h"
#include "funcionescarta.h"
#include <iostream>
#include "FUNCIONESDISENO.h"
#include <locale.h>
using namespace std;

//FUNCION MENU CARTA
void menuCarta() {
	
	char c;
	string texto;
	setlocale(LC_ALL, "");
    char opcion;

    do {
    	color(hConsole, 224);
		c='*';
		separador(c);
		texto = "MENU CARTA";
		centrarParaPintar(texto);
		separador(c);
		color(hConsole, 7);
    	cout << endl << endl << endl;
    	
		texto = "Estas en el menu del area de la carta";
		enjaular(texto, c); cout << endl << endl << endl;
		c='=';
		texto = "Elija que accion va a realizar";
		centrarYSubrayar(texto, c);
		cout << endl << endl;
		
    	c='*';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Mostrar carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Editar carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Agregar comida a la carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Ordenar carta segun el precio.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Eliminar producto.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "F) Salir del menu carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		espacio();
        // SWITCH PARA SELECIONAR LAS DIFERENTES OPCIONES DEL MENU CARTA
        switch (opcion) {
            case 'A':
            	mostrarCarta();
                break;
            case 'B':
                editarCarta();
                break;
            case 'C':
            	agregarCarta();
                break;
            case 'D':
                ordenarCarta();
                break;
            case 'E':
                eliminarCarta();
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
    } while (opcion != 'F'); //EN CASO SELECCIONAR EL NUMERO 6 REGRESA AL MENU ANTERIOR

		color(hConsole, 8);
		texto = "| SALIENDO DEL MENU CARTA... |";
		enlinear(texto, c);
		
		cout << endl << endl;
		
		texto = "| VOLVIENDO AL MENU PRINCIPAL... |";
		enlinear(texto, c);
		cout << endl << endl << endl;
		color(hConsole, 7);
}
