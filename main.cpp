#include <iostream>
#include "menus.h"
using namespace std;

int main(){
	
	int opcion;
	do{
		cout << "Menu Principal" << endl << endl
			<< "1) Cliente" << endl
			<< "2) Carta" << endl
			<< "3) Finanza" << endl 
			<< "4) Salir "<< endl << endl
			<< "= "; cin >> opcion;
			
			switch(opcion){
				case 1:
					menuCliente();
					break;
				case 2:
					menuCarta();
					break;
				case 3:
					//menuFinanza();
					break;
				case 4:
					cout << "Saliendo del programa." << endl;
				default:
					cout << "Indique una opcion valida." << endl;
					break;
			}
	} while (opcion != 4);
	return 0;
}
