#ifndef FUNCIONESMENUCLIENTES_H
#define FUNCIONESMENUCLIENTES_H
#include "menus.h"
using namespace std;

const int maxClientes=1000;
extern int cantClientes;

class Cliente: public Personas{
	private:
		string direccion;
	public:
		Cliente() : Personas("", "", "", 0, 0) {  // Llama al constructor de la clase base
        direccion = "";
    }
		Cliente(string, string, string, int, int, string);
		void mostrarDatosClientes();
	
		void leerDatosClienteEnArchivoBase(Cliente*, int&);
		void guardarDatosClienteEnArchivo(int);
		void pedirDatosClienteParaArchivo(int);
		
		void agregarClientes();
		void editarClientes();
		void eliminarClientes();
		void mostrarOrdenadosClientes();
		
		string getNombre() const { return nombre; }
		
};

extern Cliente clientes[maxClientes];

#endif
