#ifndef FUNCIONESMENUCARTA_H
#define FUNCIONESMENUCARTA_H
#include <string>
#include <iostream>
using namespace std;

const int maxComidas=10;
extern int cantComidas;

class Carta{
	private:
		string nombre, ingredientes;
		double precio, costo;
		int cantidad;
	public:
		// Constructor por defecto
	    Carta() : nombre(""), ingredientes(""), precio(0.0), cantidad(0.0), costo(0.0) {}
	    
	    // Constructor con parámetros
	    Carta(string n, string i, double p, int cant, double co);
	    
	    void agregarComida();
	    void editarCarta();
	    void eliminarComida();
	    void verCarta();
};

extern Carta comida[maxComidas];
#endif
