#ifndef FUNCIONESCARTA_H
#define FUNCIONESCARTA_H
#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
    int cantidadVendida;
};

const int MAX_ITEMS = 100;

extern Producto hamburguesas[MAX_ITEMS];
extern int numHamburguesas;
extern Producto pizzas[MAX_ITEMS];
extern int numPizzas;
extern Producto conos[MAX_ITEMS];
extern int numConos;
extern Producto gaseosas[MAX_ITEMS];
extern int numGaseosas;
extern Producto aguas[MAX_ITEMS];
extern int numAguas;

// FUNCION MOSTRAR CARTA
void mostrarCarta();
//FUNCION PARA EDITAR CARTA
void editarCarta();
//FUNCION PARA AGREGAR A LA CARTA
void agregarCarta();
//FUNCION PARA ORDENAR CARTA
void ordenarCarta();
//FUNCION PARA ELIMNAR ALGUN PRODUCTO DE LA CARTA
void eliminarCarta();

#endif
