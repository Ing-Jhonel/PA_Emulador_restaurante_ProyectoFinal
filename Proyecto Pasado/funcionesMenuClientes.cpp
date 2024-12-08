#include "funcionesMenuClientes.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Personas::Personas(string n, int dni, int e) {
    nombre = n;
    DNI = dni;
    edad = e;
}

Cliente::Cliente(string n, int dni, int e, string t, string c, string d) : Personas(n,dni,e) {
    telefono = t;
    correo = c;
    direccion = d;
}

Cliente clientes[maxClientes]; /*= {
    Cliente("Juan Perez", 12345, 30, "+51 934 567 899", "juanperez@email.com", "Calle Falsa 123"),
    Cliente("Maria Lopez", 23456, 25, "+58 967 234 563", "maria@email.com", "Avenida Siempre Viva 742"),
    Cliente("Carlos Garcia", 34567, 35, "+57 956 123 435", "carlos@email.com", "Calle Real 456"),
    Cliente("Ana Fernandez", 45678, 28, "+1 936 324 923", "ana@email.com", "Calle A 789")
};*/

int cantClientes = 0;  // Inicializar el contador de clientes

void Cliente::mostrarDatosClientes(){
	ofstream archivo;
	archivo.open("Clientes_Registrados.txt");
	if(!archivo.fail()){
		for(int i=0; i<cantClientes; i++){
		cout << "Cliente " << i+1 << endl << endl
			<< "Nombre: " << nombre << endl
			<< "DNI: " << DNI << endl
			<< "Edad: " << edad << endl
			<< "Telefono: " << telefono << endl
			<< "Correo: " << correo << endl
			<< "Direccion: " << direccion << endl << endl;
		}
		archivo.close();
	} else {
		cout << "No se pudo abrir el archivo." << endl;
	}
}
void Cliente::guardarEnArchivo(string n, string t, string c, string d, int e, int dni) {
	
	ofstream archivo;
	archivo.open("Clientes_Registrados.txt", ios::app);

    if (archivo.is_open()) {
            archivo << "Nombre: " << n << endl;
            archivo << "DNI: " << dni << endl;
            archivo << "Edad: " << e << endl;
            archivo << "Telefono: " << t << endl;
            archivo << "Correo: " << c << endl;
            archivo << "Direccion: " << d << endl;
            archivo << "-----------------------" << endl;
        archivo.close();
        cout << "Clientes guardados en el archivo 'Clientes_Registrados.txt'." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void Cliente::agregarCliente() {
	ifstream archivo;
	archivo.open("Clientes_Registrados.txt", ios::out);
	if(archivo.is_open()){
		if (cantClientes < maxClientes) {
	        cout << "Agregar Cliente" << endl << endl;
	       string nombre, telefono, correo, direccion; int edad, DNI;
	
	        cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
	        cout << "Edad: "; cin >> edad;
	        cout << "DNI: "; cin >> DNI;
	        cin.ignore();
	        cout << "Telefono: "; getline(cin, telefono);
	        cout << "Correo: "; getline(cin, correo);
	        cout << "Direccion: "; getline(cin, direccion);
	
	        clientes[cantClientes] = Cliente(nombre, DNI, edad, telefono, correo, direccion);
	        cantClientes++;
        	guardarEnArchivo(nombre, telefono, correo, direccion, edad, DNI); // Guardar en archivo después de agregar
        	archivo.close();
	    } else {
	        cout << "No puede agregar más clientes." << endl;
	    }
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
}

void Cliente::editarCliente() {
	ifstream archivo;
	archivo.open("Clientes_Registrados.txt");
    int buscar;
    bool encontrado = false;
    cout << "Editar Cliente" << endl << endl;
    cout << "Ingrese el DNI: "; 
    cin >> buscar;

    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].DNI == buscar) {
            encontrado = true;
            string nombre, telefono, correo, direccion;
            int edad;

            cout << "Ingrese los nuevos datos" << endl << endl;
            cout << "Nombre: "; cin.ignore(); getline(archivo, clientes[i].nombre);
            cout << "Edad: "; archivo >> clientes[i].edad;
            cout << "DNI: "; archivo >> clientes[i].DNI;
            cin.ignore();
            cout << "Telefono: "; getline(archivo, clientes[i].telefono);
            cout << "Correo: "; getline(archivo, clientes[i].correo);
            cout << "Direccion: "; getline(archivo, clientes[i].direccion);

            cout << "Cliente actualizado correctamente." << endl;
           // guardarEnArchivo(); // Guardar en archivo después de editar
            return;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    }
    archivo.close();
}

void Cliente::ordenarCliente() {
    Cliente copia[maxClientes];
    for (int i = 0; i < cantClientes; i++) {
        copia[i] = clientes[i];
    }

    for (int i = 0; i < cantClientes - 1; ++i) {
        for (int j = i + 1; j < cantClientes; ++j) {
            if (copia[i].nombre > copia[j].nombre) {
                Cliente temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    cout << "Clientes ordenados alfabéticamente:" << endl;
    for (int i = 0; i < cantClientes; ++i) {
        cout << copia[i].nombre << " (DNI: " << copia[i].DNI << ")" << endl;
    }
}

void Cliente::eliminarCliente() {
    int clienteEliminar;
    cout << "Eliminar Cliente" << endl << endl;
    cout << "Ingrese el DNI: "; cin >> clienteEliminar;

    bool encontrado = false;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].DNI == clienteEliminar) {
            for (int j = i; j < cantClientes - 1; j++) {
                clientes[j] = clientes[j + 1]; // Desplazar todos los clientes hacia atrás
            }
            --cantClientes;
            encontrado = true;
            cout << "Cliente eliminado." << endl;
            //guardarEnArchivo(); // Guardar en archivo después de eliminar
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    }
}

void Cliente::mostrarCliente() const {
    cout << "Nombre: " << nombre << endl;
    cout << "DNI: " << DNI << endl;
    cout << "Edad: " << edad << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "-----------------------" << endl;
}

