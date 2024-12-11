#include "funcionesMenuClientes.h"
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
	cin.ignore();
	cout << "Nombre: "; getline(cin, nombre);
	cout << "Edad: "; cin >> edad;
	cout << "DNI: "; cin >> dni;
	cin.ignore();
	cout << "Telofono: "; getline(cin, telefono);
	cout << "Correo: "; getline(cin, correo);
	cout << "Direccion: "; getline(cin, direccion);
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
	
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	if(archivo.is_open()){
		if(cantClientes < maxClientes){
			//cantClientes=retornarContador();
			cout << "Agregando Cliente" << endl << endl;
			
			pedirDatosClienteParaArchivo(cantClientes);
			guardarDatosClienteEnArchivo(0);
			
			archivo.close();
			cantClientes++;
			cout << "Cliente agregado exitosamente." << endl;
		} else {
			cout << "No puede agregar mas. Actualice el limite de clientes." << endl;
		}
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
}
void Cliente::editarClientes(){
	
	/*ifstream archivo;
	archivo.open("Clientes_Registrados.txt");*/
	
	int buscarDni;
	cout << "Editando Cliente" << endl << endl
		<< "Indique DNI: "; cin >> buscarDni;
	for(int i=0; i<cantClientes; i++){
		if(clientes[i].DNI == buscarDni){
			cout << "Cliente encontrado. Indique sus datos nuevos." << endl << endl;
			pedirDatosClienteParaArchivo(i);
			guardarDatosClienteEnArchivo(1);
			cout << "Cliente editado exitosamente." << endl << endl;
			//archivo.close();
			break;
		}
	}
	cout << "Cliente no encontrado." << endl << endl;
}
void Cliente::eliminarClientes(){
    int buscarDni;
    cout << "Eliminando Cliente" << endl
         << "Indique DNI: ";
    cin >> buscarDni;

    // Buscar el cliente a eliminar
    int indiceEliminar = -1;
    for (int i = 0; i < cantClientes; ++i) {
        if (clientes[i].DNI == buscarDni) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar == -1) {
        cout << "Cliente no encontrado." << endl;
        return;
    }

    cout << "Cliente encontrado. Eliminacion en proceso..." << endl;

    // Desplazar los elementos posteriores al cliente eliminado
    for (int i = indiceEliminar; i < cantClientes - 1; ++i) {
        clientes[i] = clientes[i + 1];
    }
    cantClientes--;
    guardarDatosClienteEnArchivo(1);
}
void Cliente::mostrarOrdenadosClientes() {
    if (cantClientes == 0) {
        cout << "No hay clientes registrados para mostrar." << endl;
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
    cout << "Clientes ordenados por nombre: " << endl << endl;
    for (int i = 0; i < cantClientes; ++i) {
        cout << "Nombre: " << copiaClientes[i].nombre << endl;
        cout << "Edad: " << copiaClientes[i].edad << endl;
        cout << "DNI: " << copiaClientes[i].DNI << endl;
        cout << "Telefono: " << copiaClientes[i].telefono << endl;
        cout << "Correo: " << copiaClientes[i].correo << endl;
        cout << "Direccion: " << copiaClientes[i].direccion << endl;
        cout << "----------------------------------" << endl;
    }
}


