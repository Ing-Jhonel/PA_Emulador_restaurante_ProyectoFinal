#include "funcionesMenuClientes.h"
#include <fstream>
#include <iostream>

using namespace std;

Personas::Personas(string n, int dni, int e) {
    nombre = n;
    DNI = dni;
    edad = e;
}

Cliente::Cliente(string n, int dni, int e, string t, string c, string d) : Personas(n, dni, e) {
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

void Cliente::guardarEnArchivo() {
	
	ofstream archivo;
	archivo.open("Clientes_Registrados.txt");

    if (archivo.is_open()) {
        for (int i = 0; i < cantClientes; i++) {
            archivo << "Nombre: " << clientes[i].nombre << endl;
            archivo << "DNI: " << clientes[i].DNI << endl;
            archivo << "Edad: " << clientes[i].edad << endl;
            archivo << "Telefono: " << clientes[i].telefono << endl;
            archivo << "Correo: " << clientes[i].correo << endl;
            archivo << "Direccion: " << clientes[i].direccion << endl;
            archivo << "-----------------------" << endl;
        }
        archivo.close();
        cout << "Clientes guardados en el archivo 'Clientes_Registrados.txt'." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void Cliente::agregarCliente() {
    if (cantClientes < maxClientes) {
        cout << "Agregar Cliente" << endl << endl;
        string nombre, telefono, correo, direccion;
        int edad, DNI;

        cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "Edad: "; cin >> edad;
        cout << "DNI: "; cin >> DNI;
        cin.ignore();
        cout << "Telefono: "; getline(cin, telefono);
        cout << "Correo: "; getline(cin, correo);
        cout << "Direccion: "; getline(cin, direccion);

        clientes[cantClientes] = Cliente(nombre, DNI, edad, telefono, correo, direccion);
        cantClientes++;

        guardarEnArchivo(); // Guardar en archivo después de agregar
    } else {
        cout << "No puede agregar más clientes." << endl;
    }
}

void Cliente::editarCliente() {
	ofstream archivo;
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
            cout << "Nombre: "; cin.ignore(); getline(cin, clientes[i].nombre);
            cout << "Edad: "; cin >> clientes[i].edad;
            cout << "DNI: "; cin >> clientes[i].DNI;
            cin.ignore();
            cout << "Telefono: "; getline(cin, clientes[i].telefono);
            cout << "Correo: "; getline(cin, clientes[i].correo);
            cout << "Direccion: "; getline(cin, clientes[i].direccion);

            cout << "Cliente actualizado correctamente." << endl;
            guardarEnArchivo(); // Guardar en archivo después de editar
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
            guardarEnArchivo(); // Guardar en archivo después de eliminar
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

