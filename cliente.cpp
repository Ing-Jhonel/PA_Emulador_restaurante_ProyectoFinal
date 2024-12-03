#include <iostream>
#include "menus.h"
#include "funcionescliente.h"

#include "FUNCIONESDISENO.h"
#include <locale.h> //libreria para incluir el idioma espa?ol
using namespace std;


//FUNCION DEL MENU CLIENTE
void menuCliente() {
	char opcion;
	char c;
	string texto;
	int cantidadActualClientes = 9; //SON 10 PERO AL SER UN ARREGLO EMPIEZA POR "0"
	//SE AGREGAN 10 CLIENTES PREDEFINIDOS
	Cliente clientes[50] = {
		{"Carlos Flores", "827364958", {"Miraflores", "Av. Pardo", "Mz. B", "Lt. 12"}}, //POSICION 0
		{"Juan Perez", "817361123", {"San Isidro", "Calle Las Flores", "Mz. F", "Lt. 8"}}, //POSICION 1
		{"Maria Lopez", "917345991", {"Barranco", "Av. Grau", "Mz. C", "Lt. 5"}}, //POSICION 2
		{"Carlos Gomez", "611230194", {"Surco", "Calle Los Alamos", "Mz. D", "Lt. 3"}}, //POSICION 3
		{"Laura Fernandez", "471623090", {"La Molina", "Av. La Universidad", "Mz. A", "Lt. 1"}}, //POSICION 4
		{"Luis Martinez", "918453124", {"San Borja", "Calle Los Laureles", "Mz. J", "Lt. 9"}}, //POSICION 5
		{"Sofia Torres", "019434198", {"Vitacura", "Av. Bolivar", "Mz. E", "Lt. 6"}}, //POSICION 6
		{"Pedro Meza", "981450001", {"Magdalena", "Calle San Martin", "Mz. H", "Lt. 2"}}, //POSICION 7
		{"Elena Mamani", "934217501", {"Polanco", "Av. Arequipa", "Mz. G", "Lt. 7"}}, //POSICION 8
		{"Jorge Morales", "091245762", {"Palermo", "Calle Salaverry", "Mz. L", "Lt. 3"}} //POSICION 9
	};
	
	//DO WHILE QUE REPITE EL MENU HASTA QUE SE SELECCIONE LA OPCION 6
	do {
		color(hConsole, 48);
		c='*';
		separador(c);
		texto = "AREA DE CLIENTE";
		centrarParaPintar(texto);
		separador(c);
		
		color(hConsole, 7);
		cout << endl << endl << endl;
		texto = "Estas en el menu del area de cliente";
		enjaular(texto, c); cout << endl << endl << endl;
		
		c='=';
		texto = "Elija que accion va a realizar";
		centrarYSubrayar(texto, c);
		cout << endl << endl;
		
		c='*';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Agregar cliente.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Editar datos del cliente.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Ordenar y mostrar clientes alfabeticamente.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Eliminar clientes.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Volver al menu principal.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "---------------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		espacio();
		//SWITCH PARA LAS DISTINTAS FUNCIONES DEL MENU CLIENTE
		switch ( opcion ) {
			case 'A':
				agregarCliente(clientes, cantidadActualClientes);
				break;
			case 'B':
				editarDatosCliente(clientes, cantidadActualClientes);
				break;
			case 'C':
				ordenarClientesAlfabeticamente(clientes, cantidadActualClientes);
				break;
			case 'D':
				eliminarClientes(clientes, cantidadActualClientes);
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
	} while ( opcion != 'E' );

		color(hConsole, 8);
		texto = "| SALIENDO DEL MENU CLIENTE... |";
		enlinear(texto, c);
		
		cout << endl << endl;
		
		texto = "| VOLVIENDO AL MENU PRINCIPAL... |";
		enlinear(texto, c);
		cout << endl << endl << endl;
		color(hConsole, 7);
}
