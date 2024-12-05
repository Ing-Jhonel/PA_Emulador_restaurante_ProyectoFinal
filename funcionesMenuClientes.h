#ifndef FUNCIONESMENUCLIENTE_H
#define FUNCIONESMENUCLIENTE_H

#include <string>
#include <iostream>
using namespace std;

const int maxClientes = 100;  // Definir el límite de clientes
extern int cantClientes;

class Cliente {
	private:
	    string nombre, telefono, correo, direccion;
	    int DNI;
	public:
	    // Constructor por defecto
	    Cliente() : nombre(""), telefono(""), correo(""), direccion(""), DNI(0) {}
	    
	    // Constructor con parámetros
	    Cliente(string n, int dni, string t, string c, string d);
	    
	    // Métodos para manejar la lógica de clientes
	    //void asignarDatos(string, string, string, string, int);
	    
	    void agregarCliente();
	    void editarCliente();
	    void ordenarCliente();
	    void eliminarCliente();
	    //void mostrarClientes();
};

extern Cliente clientes[maxClientes];

#endif


