#include "funcionesMenuClientes.h"
#include "funcionesDiseno.h"
#include "menus.h"
#include <fstream>
#include <iostream>
using namespace std;


int cantClientes=0;
Cliente clientes[maxClientes];

Cliente::Cliente(string n, string t, string c, int e, int dni, string d): Personas(n,t,c,e,dni){
	direccion=d;
}

void Cliente::leerDatosClienteEnArchivoBase(Cliente arr[], int &cantClientes) {
    
	ifstream archivo;
    archivo.open("infoClientes.txt");
	string linea;
	cantClientes=0;
	string nombre, telefono, correo, direccion;
	int edad, dni;
    if (archivo.is_open()) {
        while(getline(archivo, linea)){
        	
        	getline(archivo, nombre);
        	
            archivo >> edad >> dni;
            
            archivo.ignore();
            
            getline(archivo, telefono);
            getline(archivo, correo);
            getline(archivo, direccion);
            
            arr[cantClientes] = Cliente(nombre, telefono, correo, edad, dni, direccion); //inicializa en 0
            cantClientes++;
		}
        archivo.close();
    } else {
        //cout << "Error al abrir el archivo." << endl;
    }
}
void Cliente::pedirDatosClienteParaArchivo(int posicion){ //funcion que pide datos de un arreglo para meterlos en una posicion especifica
	ofstream archivo; 
	archivo.open("infoClientes.txt", ios::app);
	string nombre, telefono, correo, direccion;
	int edad, dni;
	string texto; char c;
	int porcentajePantalla = 30;
	
	cin.ignore();
	
	texto = "|	Nombre del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	getline(cin, nombre);
	
	texto = "|	Edad del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin >> edad;
	
	texto = "|	DNI del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	cin >> dni;
	
	cin.ignore();
	
	texto = "|	Telofono del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	getline(cin, telefono);
	
	texto = "|	Correo del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	getline(cin, correo);
	
	texto = "|	Direccion del cliente: ";
	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	getline(cin, direccion);
	
	clientes[posicion]=Cliente(nombre, telefono, correo, edad, dni, direccion);
	archivo.close();
}
void Cliente::guardarDatosClienteEnArchivo(int k){ // son dos funciones de guardar datos; k=0 si es agregar; k= si es alterar el archivo
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::trunc); //guarda la info en el archivo base, que el usuario no debe ver, puro info para datos
	if (archivo.is_open()) {
		for(int i=0; i<=cantClientes-k; i++){
			archivo << i << endl
        			<< clientes[i].nombre << endl
        			<< clientes[i].edad << endl
        			<< clientes[i].DNI << endl
        			<< clientes[i].telefono << endl
        			<< clientes[i].correo << endl
        			<< clientes[i].direccion << endl;
		}	
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
	archivo.close();
	
	archivo.open("Clientes_Registrados.txt", ios::trunc); //guarda la info en el archivo que el usuario vera
	archivo << "*****************************************************" << endl
		<< "        C L I E N T E S   R E G I S T R A D O S		 " << endl
		<< "*****************************************************" << endl << endl;
	//int i=cantClientes;
	for(int i=0; i<=cantClientes-k; i++){
		archivo << endl << "CLIENTE " << i+1 << endl << endl
			<< "Nombre: " << clientes[i].nombre << endl
			<< "Edad: " << clientes[i].edad << endl
			<< "DNI: " << clientes[i].DNI << endl
			<< "Telefono: " << clientes[i].telefono << endl
			<< "Correo: " << clientes[i].correo << endl
			<< "Direccion: " << clientes[i].direccion << endl
			<< "-------------------------------------------" << endl;
	}
    		
	archivo.close();
}

void Cliente::agregarClientes(){
	string texto; char c;
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	if(archivo.is_open()){
		if(cantClientes < maxClientes){
			c='+';
			texto="A G R E G A N D O   C L I E N T E . . .";
			enjaular(texto, c);
			
			cout << endl << endl << endl;
			
			pedirDatosClienteParaArchivo(cantClientes);
			guardarDatosClienteEnArchivo(0);
			
			cout << endl << endl << endl;
			archivo.close();
			cantClientes++;
			c='-';
			texto="Cliente agregado exitosamente.";
			enlinear(texto, c);
		} else {
			c='-';
			texto="No puede agregar mas. Actualice el limite de clientes.";
			enlinear(texto, c);
		}
	} else {
		c='-';
		texto="Error al abrir el archivo.";
		enlinear(texto, c);
	}
}
void Cliente::editarClientes(){
	string texto; char c;
	/*ifstream archivo;
	archivo.open("Clientes_Registrados.txt");*/
	
	int buscarDni;
	c='+';
	texto="E D I T A N D O   C L I E N T E . . .";
	enjaular(texto, c);
	
	cout << endl << endl << endl;
	
	centrar(texto); cout << endl;
	centrarCin(1); cin >> buscarDni;
	
	cout << endl << endl << endl;
	for(int i=0; i<cantClientes; i++){
		if(clientes[i].DNI == buscarDni){
			c='-';
			texto="Cliente encontrado. Indique sus datos nuevos.";
			enlinear(texto, c);
			
			cout << endl << endl;
			
			pedirDatosClienteParaArchivo(i);
			guardarDatosClienteEnArchivo(1);
			
			cout << endl << endl << endl;
			
			c='-';
			texto="Cliente encontrado. Indique sus datos nuevos.";
			enlinear(texto, c);
			
			//archivo.close();
			break;
		}
	}
	c='-';
	texto="Cliente no encontrado.";
	enlinear(texto, c);
}
void Cliente::eliminarClientes(){
    int buscarDni;string texto; char c;
	c='+';
	texto="E L I M I N A N D O   C L I E N T E . . .";
	enjaular(texto, c);
	
	cout << endl << endl << endl;
	
	centrar(texto); cout << endl;
	centrarCin(1); cin >> buscarDni;
	
	cout << endl << endl << endl;
	
    int indiceEliminar = -1;
    for (int i = 0; i < cantClientes; ++i) {
        if (clientes[i].DNI == buscarDni) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1) {
        c='-';
		texto="Cliente no encontrado.";
		enlinear(texto, c);
        return;
    }

    c='!';
	texto="Cliente encontrado. Eliminacion en proceso.";
	enlinear(texto, c);

    // Desplazar los elementos posteriores al cliente eliminado
    for (int i = indiceEliminar; i < cantClientes - 1; ++i) {
        clientes[i] = clientes[i + 1];
    }
    cantClientes--;
    guardarDatosClienteEnArchivo(1);
}
void Cliente::mostrarOrdenadosClientes() {
    string texto; char c;
	if (cantClientes == 0) {
        c='-';
		texto="No hay cliente registrados.";
		enlinear(texto, c);
        return;
    }

    // Crear una copia del arreglo original
    Cliente copiaClientes[maxClientes];
    for (int i = 0; i < cantClientes; ++i) {
        copiaClientes[i] = clientes[i];
    }

    // Ordenar el arreglo copia usando Bubble Sort
    for (int i = 0; i < cantClientes - 1; ++i) {
        for (int j = 0; j < cantClientes - i - 1; ++j) {
            if (copiaClientes[j].nombre > copiaClientes[j + 1].nombre) {
                // Intercambio de elementos
                Cliente temp = copiaClientes[j];
                copiaClientes[j] = copiaClientes[j + 1];
                copiaClientes[j + 1] = temp;
            }
        }
    }

    // Mostrar los clientes ordenados
    c='+';
    texto="Clientes ordenados por nombre: ";
    enjaular(texto, c);
    
    cout << endl << endl << endl;
    
    int porcentajePantalla = 30;
    c='_';
    for(int i=0; i<cantClientes; i++){
		
		texto = "|	Nombre: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].nombre << endl;
		texto = "|	Edad: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].edad << endl;
		texto = "|	DNI: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].DNI << endl;
		texto = "|	Telefono: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].telefono << endl;
		texto = "|	Correo: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].correo << endl;
		texto = "|	Direccion: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << copiaClientes[i].direccion << endl;
		linea(30, c, 0);
		cout << endl << endl;
	}                
} 
	

