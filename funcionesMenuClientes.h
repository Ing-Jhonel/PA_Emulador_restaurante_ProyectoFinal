#ifndef FUNCIONESMENUCLIENTE_H
#define FUNCIONESMENUCLIENTE_H

#include <string>
#include <iostream>
using namespace std;

const int maxClientes = 100;  // Definir el límite de clientes
extern int cantClientes;

class Personas {
	protected:
	    string nombre;
	    int DNI, edad;
	public:
	    // Constructor por defecto
	    Personas(string, int, int);
};

class Cliente : public Personas {
	private:
	    string telefono, correo, direccion;
	
	public:
		Cliente() : Personas("", 0, 0), telefono(""), correo(""), direccion("") {}
		Cliente(string, int, int, string, string, string);
		
	    void agregarCliente();
	    void editarCliente();
	    void ordenarCliente();
	    void eliminarCliente();
};

extern Cliente clientes[maxClientes];

#endif

