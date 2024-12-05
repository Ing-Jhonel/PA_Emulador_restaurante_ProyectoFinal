#include "funcionesMenuClientes.h"
using namespace std;

Cliente::Cliente(string n, int dni, string t, string c, string d) {
    nombre = n;
    telefono = t;
    correo = c;
    direccion = d;
    DNI = dni;
}   
Cliente clientes[maxClientes] = {
    Cliente("Juan Perez", 12345, "+51 934 567 899", "juanperez@email.com", "Calle Falsa 123"),
    Cliente("Maria Lopez", 23456, "+58 967 234 563", "maria@email.com", "Avenida Siempre Viva 742"),
    Cliente("Carlos Garcia", 34567, "+57 956 123 435", "carlos@email.com", "Calle Real 456"),
    Cliente("Ana Fernandez", 45678, "+1 936 324 923", "ana@email.com", "Calle A 789")
};

int cantClientes = 4;  // Inicializar el contador de clientes

/*
void Cliente::asignarDatos(string n, string t, string d, string c, int dni) {
    nombre = n;
    telefono = t;
    direccion = d;
    correo = c;
    DNI = dni;
}*/

void Cliente::agregarCliente() {
    if (cantClientes < maxClientes) {
        cout << "Agregar Cliente" << endl << endl;

        cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "DNI: ";cin >> DNI;
		cin.ignore();
        cout << "Telefono: "; getline(cin, telefono);
        cout << "Correo: "; getline(cin, correo);
        cout << "Direccion: "; getline(cin, direccion);

        // Usar el método asignarDatos para asignar los datos al nuevo cliente
        //clientes[cantClientes].asignarDatos(nombre, telefono, direccion, correo, DNI);
        cantClientes++;
    } else {
        cout << "No puede agregar más clientes." << endl;
    }
}

void Cliente::editarCliente(){
	int buscar, indiceEncontrado; bool encontrado=false;
	cout << "Editar Cliente" << endl << endl;
	cout << "Ingrese el DNI: "; cin >> buscar;
	for(int i=0; i<cantClientes; i++){
		if(clientes[i].DNI == buscar){
			encontrado=true;
			indiceEncontrado=i;
		}
	}
	
	if(encontrado){
		cout << "Ingrese los nuevos datos" << endl << endl;
		cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
        cout << "DNI: ";cin >> DNI;
		cin.ignore();
        cout << "Telefono: "; getline(cin, telefono);
        cout << "Correo: "; getline(cin, correo);
        cout << "Direccion: "; getline(cin, direccion);
	} else {
		cout << "Cliente no encontrado." << endl;
	}
}

void Cliente::ordenarCliente() {
	
	Cliente copia[cantClientes];
	for(int i=0; i<cantClientes; i++){
		copia[i]=clientes[i];
	}
	
    for (int i = 0; i < cantClientes - 1; ++i) {
        for (int j = i + 1; j < cantClientes; ++j) {
            if (copia[i].nombre > copia[j].nombre) {
                // Intercambiar los clientes
                Cliente temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    cout << "Clientes ordenados alfabéticamente:" << endl;
    for (int i = 0; i < cantClientes; ++i) {
        cout << copia[i].nombre << endl;
    }
}

void Cliente::eliminarCliente() {
    int clienteEliminar;
    cout << "Eliminar Cliente" << endl << endl;
    cout << "Ingrese el DNI: "; cin >> clienteEliminar;

    bool encontrado = false;
    for (int i=0; i<cantClientes; i++) {
        if (clientes[i].DNI == clienteEliminar) {
            for (int j=i; j<cantClientes-1; j++) {
                clientes[j] = clientes[j+1]; // Desplazar todos los clientes hacia atrás
            }
            --cantClientes;
            encontrado = true;
            cout << "Cliente eliminado." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    }
}

/*void Cliente::mostrarClientes() {
    if (cantClientes > 0) {
        cout << "Clientes actuales:" << endl;
        for (int i = 0; i < cantClientes; ++i) {
            cout << clientes[i].nombre << ", " << clientes[i].edad << " años, Tel: " << clientes[i].telefono << endl;
        }
    } else {
        cout << "No hay clientes registrados." << endl;
    }
}
*/


