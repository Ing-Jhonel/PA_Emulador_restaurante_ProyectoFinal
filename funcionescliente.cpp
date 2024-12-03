#include <iostream>
#include <string>
#include "funcionescliente.h"
#include "FUNCIONESDISENO.h"
using namespace std;

char c;
string texto;
float porcentajePantalla;
//FUNCION PARA AGREGAR CLIENTES
void agregarCliente(Cliente clientes[50], int &cantidadActualClientes) {
	color(hConsole, 3);
	cantidadActualClientes++;
	c='*';
	texto = "AGREGUE UN CLIENTE";
	enlinearYEnjaular(texto, c); cout << endl << endl << endl;

	color(hConsole, 12);
	c='=';
	texto = "DATOS DEL CLIENTE";
	centrarYSubrayar(texto, c); cout << endl << endl;
	color(hConsole, 7);
	
	porcentajePantalla = 30;
	texto = "|	Nombre del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[cantidadActualClientes].nombre); //entrada
	texto = "|	Numero del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin >> clientes[cantidadActualClientes].telefono;  //entrada
	cout << endl << endl << endl;
	
	color(hConsole, 12);
	c='=';
	texto = "DIRECCION DEL CLIENTE";
	centrarYSubrayar(texto, c); cout << endl << endl;
	color(hConsole, 7);
	
	texto = "|	Distrito: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[cantidadActualClientes].direccionCliente.distrito); //entrada
	texto = "|	Calle: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[cantidadActualClientes].direccionCliente.calle); //entrada
	texto = "|	Manzana: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[cantidadActualClientes].direccionCliente.manzana); //entrada
	texto = "|	Lote: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[cantidadActualClientes].direccionCliente.lote); //entrada
	
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> CLIENTE AGREGADO CORRECTAMENTE <";
	enlinear(texto, c);
	
	cout << endl << endl;
	
	c='-';
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU CLIENTE... |";
	enlinear(texto, c);
}

//FUNCION PARA EDITAR DATOS DEL CLIENTES
void editarDatosCliente(Cliente clientes[50], int &cantidadActualClientes) {
	int clienteEditar; //POSICION DE MEMORIA QUE LUEGO SERA EL CLIENTE QUE SE VA A EDITAR
	
	color(hConsole, 3);
	cantidadActualClientes++;
	c='*';
	texto = "EDITE UN CLIENTE";
	enlinearYEnjaular(texto, c); 
	color(hConsole, 7);
	cout << endl << endl << endl;	
	
	do { //DO WHILE PARA REPETIR EN TAL CASO EL USUARIO INGRESE NUMEROS QUE NO ESTEN ENTRE 1 Y 20
		color(hConsole, 7);
		texto = "Ingrese la posicion del usuario que desea editar (1-";
		centrar(texto); cout << cantidadActualClientes + 1 << ")";
		cout << endl;
		texto = "-----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> clienteEditar;
		
		cout << endl << endl;
		color(hConsole, 8);
		if ( clienteEditar >= 1 && clienteEditar <= cantidadActualClientes + 1 ) {
			texto = "POSICION ENCONTRADA"; 
		} else {
			texto = "ERROR: POSICION NO ENCONTRADA";
		}
		centrar(texto);
		cout << endl << endl << endl;
	} while ( clienteEditar < 1 || clienteEditar > cantidadActualClientes + 1);
	cout << endl;
	clienteEditar--; //SE REDUCE EN 1 PARA QUE SEA LA POSICION CORRECTA, YA QUE SE CUENTA LA POSICION 0
	
	color(hConsole, 12);
	c='=';
	texto = "DATOS DEL CLIENTE A EDITAR";
	centrarYSubrayar(texto, c); cout << endl << endl;
	color(hConsole, 7);
	
	porcentajePantalla = 30;
	texto = "|	Nombre del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[clienteEditar].nombre);
	texto = "|	Numero del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin >> clientes[clienteEditar].telefono;
	cout << endl << endl << endl;
	
	color(hConsole, 12);
	c='=';
	texto = "DIRECCION DEL CLIENTE";
	centrarYSubrayar(texto, c); cout << endl << endl;
	color(hConsole, 7);
	
	texto = "|	Distrito: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[clienteEditar].direccionCliente.distrito);
	texto = "|	Calle: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[clienteEditar].direccionCliente.calle);
	texto = "|	Manzana: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[clienteEditar].direccionCliente.manzana);
	texto = "|	Lote: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin.ignore();
	getline(cin, clientes[clienteEditar].direccionCliente.lote);
	
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> CLIENTE EDITADO CORRECTAMENTE <";
	enlinear(texto, c);
	
	cout << endl << endl;
	
	c='-';
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU CLIENTE... |";
	enlinear(texto, c);
}

//FUNCION PARA ORDENAR LOS CLIENTES ALFABETICAMENTE
void ordenarClientesAlfabeticamente(Cliente clientes[50], int &cantidadActualClientes) {
	//AUXILIARES PARA CADA DATO DEL CLIENTE QUE SE VA A ORDENAR
	string auxiliar1, auxiliar2, auxiliar3, auxiliar4, auxiliar5, auxiliar6;
	//BUCLE FOR PARA ORDENAR DE LA A-Z
	for ( int i = 0; i <= cantidadActualClientes; i++ ) {
		for ( int j = i + 1; j <= cantidadActualClientes; j++ ) {
			if ( clientes[i].nombre > clientes[j].nombre ) {
				//GUARDANDO TODOS LOS DATOS DEL CLIENTE EN LOS AUXILIARES
				auxiliar1 = clientes[i].nombre;
				auxiliar2 = clientes[i].telefono;
				auxiliar3 = clientes[i].direccionCliente.distrito;
				auxiliar4 = clientes[i].direccionCliente.calle;
				auxiliar5 = clientes[i].direccionCliente.manzana;
				auxiliar6 = clientes[i].direccionCliente.lote;
				
				//REEMPLAZAMOS LOS DATOS DEL CLIENTE "i" POR LOS DATOS DEL CLIENTE "j"
				clientes[i].nombre = clientes[j].nombre;
				clientes[i].telefono = clientes[j].telefono;
				clientes[i].direccionCliente.distrito = clientes[j].direccionCliente.distrito;
				clientes[i].direccionCliente.calle = clientes[j].direccionCliente.calle;
				clientes[i].direccionCliente.manzana = clientes[j].direccionCliente.manzana;
				clientes[i].direccionCliente.lote = clientes[j].direccionCliente.lote;
				
				//REEMPLAZAMOS LOS DATOS DEL CLIENTE "j" POR LOS QUE ALMACENAMOS EN LOS AUXILIARES
				clientes[j].nombre = auxiliar1; 
				clientes[j].telefono = auxiliar2;
				clientes[j].direccionCliente.distrito = auxiliar3;
				clientes[j].direccionCliente.calle = auxiliar4;
				clientes[j].direccionCliente.manzana = auxiliar5;
				clientes[j].direccionCliente.lote = auxiliar6;
			}
		}
	}
	
	//BUCLE PARA MOSTRAR LOS CLIENTES ORDENADOS Y SUS DATOS
	color(hConsole, 3);
	c='*';
	texto = "CLIENTES ORDENADOS ALFABETICAMENTE";
	enlinearYEnjaular(texto, c); 
	cout << endl << endl << endl;
	color(hConsole, 7);
	
	c='-';
	porcentajePantalla = 30;
	for ( int i = 0; i <= cantidadActualClientes; i++ ) {
		color(hConsole, 12);
		texto = "CLIENTE ";
		centrar(texto);cout << i+1 << endl;
		linea(10, c, 0); cout << endl << endl;
		color(hConsole, 7);
		
		texto = "|	Nombre: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].nombre << endl;
		texto = "|	Telefono: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].telefono << endl << endl;
		
		texto = "Direccion del cliente:";
		centrar(texto); cout << endl << endl;
		
		texto = "|	Distrito: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].direccionCliente.distrito << endl;
		texto = "|	Calle: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].direccionCliente.distrito << endl;
		texto = "|	Manzana: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].direccionCliente.manzana << endl;
		texto = "|	Lote: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << clientes[i].direccionCliente.lote << endl;
	}
	
	espacio();
	c='-';
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU CLIENTE... |";
	enlinear(texto, c);
}

//FUNCION PARA ELIMINAR CLIENTES
void eliminarClientes(Cliente clientes[50], int &cantidadActualClientes) {
	//POSICION QUE EL USUARIO VA A ELIMINAR
	int posicionEliminar;
	
	c='*';
	color(hConsole, 3);
	texto = "ELIMINE UN CLIENTE";
	enlinearYEnjaular(texto, c); 
	cout << endl << endl << endl;
	color(hConsole, 7);
	
	texto = "Eliga que cliente desea eliminar (1-";
		centrar(texto); cout << cantidadActualClientes + 1 << ")";//SE SUMA MÁS UNO PORQUE EL 0 CUENTA COMO UNA POSICIÓN DE UN CLIENTE
		cout << endl;
		texto = "----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> posicionEliminar;
		
		c='-';
		espacio();

	//VERIFICAR QUE LA POSICIÓN ESTÁ DENTRO DEL RANGO
	if ( posicionEliminar >= 1 && posicionEliminar <= cantidadActualClientes + 1 ) {
		//BUCLE FOR PARA SUSTITUIR LA POSICION ELIMINADA
		for ( int i = posicionEliminar - 1; i < cantidadActualClientes - 1; i++ ) { //SE LE RESTA 1 A "POSICIONELIMINAR" PARA QUE ENCAJE CON LA POSICIÓN ESCOGIDA, PORQUE COMO EL 0 CUENTA COMO POSICIÓN DE MEMORIA, EL 0 CUENTA Y SI EL USUARIO ESCOGE 1, SE REFIERE A LA POSICIÓN 0
			clientes[i].nombre = clientes[i + 1].nombre;
			clientes[i].telefono = clientes[i + 1].telefono;
			clientes[i].direccionCliente.distrito = clientes[i + 1].direccionCliente.distrito;
			clientes[i].direccionCliente.calle = clientes[i + 1].direccionCliente.calle;
			clientes[i].direccionCliente.manzana = clientes[i + 1].direccionCliente.manzana;
			clientes[i].direccionCliente.lote = clientes[i + 1].direccionCliente.lote;
		}
		cantidadActualClientes--; //SE LE RESTA UNO PORQUE SE ELIMINO UN CLIENTE Y LA CANTIDAD ACTUAL SE REDUCE
		
		color(hConsole, 10);
		texto = "> CLIENTE ELIMINADO CORRECTAMENTE <";
	} else {
		color(hConsole, 4);
		texto = "CLIENTE NO ENCONTRADO. NO SE PUEDE CONTINUAR.";
	}
	enlinear(texto, c);
	
	cout << endl << endl;
	
	c='-';
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU CLIENTE... |";
	enlinear(texto, c);
}
