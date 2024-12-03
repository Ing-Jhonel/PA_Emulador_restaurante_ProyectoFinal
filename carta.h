#ifndef CARTA_H
#define CARTA_H
#include <iostream>

using namespace std;
struct Producto {
    string nombre;
    float precio;
};
void menuCarta();
void mostrarCarta();
void editarCarta();
void agregarCarta();
void inicializarproductos();
void ordenarCarta();
void eliminarCarta();


#endif
