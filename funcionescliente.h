#ifndef FUNCIONESCLIENTE_H
#define FUNCIONESCLIENTE_H
#include <iostream>
using namespace std;

//REGISTRO DE DIRECCION
struct Direccion {
	string distrito;
	string calle;
	string manzana;
	string lote;
};

//REGISTRO DE CLIENTE
struct Cliente {
	string nombre;
	string telefono;
	Direccion direccionCliente;
};

//FUNCION PARA AGREGAR CLIENTES
void agregarCliente(Cliente clientes[50], int &cantidadActualClientes);
//FUNCION PARA EDITAR DATOS DEL CLIENTES
void editarDatosCliente(Cliente clientes[50], int &cantidadActualClientes);
//FUNCION PARA ORDENAR ALFABETICAMENTE LOS CLIENTES
void ordenarClientesAlfabeticamente(Cliente clientes[50], int &cantidadActualClientes);
//FUNCION PARA ELIMINAR CLIENTES
void eliminarClientes(Cliente clientes[50], int &cantidadActualClientes);
#endif
