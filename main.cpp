#include <iostream>
#include "menus.h"

#include "FUNCIONESDISENO.h"
#include <locale.h> //libreria para incluir el idioma espa?ol

using namespace std;

int main() {
	
	system("pause");
	setlocale(LC_ALL, ""); //parte de la liberia locale.h
	
	int opcion;
	string texto;
	char c;
	
	do {
		//OPCIONES A ESCOGER
		color(hConsole, 79);
		c = '-';
		separador(c);
		c='*';
		separador(c);
		texto = "ESIS'S RESTAURANT MANAGEMENT";
		centrarParaPintar(texto);
		separador(c);
		c='-';
		separador(c);
		color(hConsole, 7);
		cout << endl << endl << endl;
		
		c='*';
		texto = "Elija que va a administrar";
		enjaular(texto, c);
		cout << endl << endl;
		
		
		int anchoJaula=40;
		int salto=2;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "1. Cliente.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "2. Carta.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "3. Despensa.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "4. Finanzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "5. Salir del programa.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		
		cin >> opcion;
		espacio();
		
		//SWITCH CON EL MENU A ESCOGER
		switch (opcion){
			case 1:
				menuCliente();
				break;
			case 2:
				menuCarta();
				break;
			case 3:
				menuDespensa();
				break;
			case 4:
				menuFinanzas();
				break;
			case 5:
				break;
			default:
				cout << endl;
				color(hConsole, 4);
				texto = "Valor ingresado incorrecto, vuelva a ingresar otro valor";	
				centrar(texto);
				cout << endl << endl << endl;
		}

	} while ( opcion !=5 );
		cout << endl;
		color(hConsole, 2);
		texto = "| PROGRAMA FINALIZADO, GRACIAS POR SU USO |";
		enlinear(texto, c);
		cout << endl;
		color(hConsole, 7);
	return 0;
}
