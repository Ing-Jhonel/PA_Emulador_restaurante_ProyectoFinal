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
	string nombre, telefono, correo, direccion;
	int edad, dni;
	cantClientes=0;
    if (archivo.is_open()) {
        while(getline(archivo, linea)){
        	
        	getline(archivo, nombre);
        	
            archivo >> edad;
            archivo >> dni;
            
            archivo.ignore();
            
            getline(archivo, telefono);
            getline(archivo, correo);
            getline(archivo, direccion);
            
            arr[cantClientes] = Cliente(nombre, telefono, correo, edad, dni, direccion);
            cantClientes++;
		}
        archivo.close();
    } else {
        //cout << "Error al abrir el archivo." << endl;
    }
}
void Cliente::pedirDatosClienteParaArchivo(){
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	
	cin.ignore();
	cout << "Nombre: "; getline(cin, clientes[cantClientes].nombre);
	cout << "Edad: "; cin >> clientes[cantClientes].edad;
	cout << "DNI: "; cin >> clientes[cantClientes].DNI;
	cin.ignore();
	cout << "Telofono: "; getline(cin, clientes[cantClientes].telefono);
	cout << "Correo: "; getline(cin, clientes[cantClientes].correo);
	cout << "Direccion: "; getline(cin, clientes[cantClientes].direccion);
	
	archivo.close();
}
void Cliente::guardarDatosClienteEnArchivoBase(){
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	if (archivo.is_open()) {
        	archivo << cantClientes+1 << endl
        			<< clientes[cantClientes].nombre << endl
        			<< clientes[cantClientes].edad << endl
        			<< clientes[cantClientes].DNI << endl
        			<< clientes[cantClientes].telefono << endl
        			<< clientes[cantClientes].correo << endl
        			<< clientes[cantClientes].direccion << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}
void Cliente::guardarDatosClienteEnArchivoFinal() {
	ofstream archivo;
	archivo.open("Clientes_Registrados.txt", ios::app);
	int i=cantClientes;
	//for(int i=0; i<cantClientes;i++){
		archivo << endl << "Cliente " << i+1 << endl << endl
			<< "Nombre: " << clientes[i].nombre << endl
			<< "Edad: " << clientes[i].edad << endl
			<< "DNI: " << clientes[i].DNI << endl
			<< "Telefono: " << clientes[i].telefono << endl
			<< "Correo: " << clientes[i].correo << endl
			<< "Direccion: " << clientes[i].direccion << endl;
	//}
    		
	archivo.close();
}

void Cliente::agregarClientes(){
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	if(archivo.is_open()){
		if(cantClientes < maxClientes){
			//cantClientes=retornarContador();
			cout << "Agregando Cliente" << endl << endl;
			
			pedirDatosClienteParaArchivo();
			guardarDatosClienteEnArchivoBase();
			guardarDatosClienteEnArchivoFinal();
			
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
	
	cout << endl << endl;
	ifstream archivo;
	archivo.open("Clientes_Registrados.txt");
	
	int buscarDni;
	cout << "Editando Cliente" << endl << endl
		<< "Indique DNI: "; cin >> buscarDni;
	for(int i=0; i<cantClientes; i++){
		if(clientes[i].DNI == buscarDni){
			cout << "Cliente encontrado. Indique sus datos nuevos." << endl << endl;
			pedirDatosClienteParaArchivo();
			guardarDatosClienteEnArchivoBase();
			guardarDatosClienteEnArchivoFinal();
			cout << "Cliente editado exitosamente." << endl << endl;
			archivo.close();
			break;
		}
	}
	cout << "Cliente no encontrado." << endl << endl;
}

void Cliente::eliminarClientes(){
	
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


