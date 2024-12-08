#ifndef FUNCIONESMENUCARTA_H
#define FUNCIONESMENUCARTA_H
#include <string>
#include <iostream>
using namespace std;

const int maxComidas=10;
extern int cantComidas;
extern int numFacturas;

class Carta{
	private:
		string nombre, ingredientes;
		double precio, cantidad, costo;
		int cantPedidos;
	public:
		// Constructor por defecto
	    Carta() : nombre(""), ingredientes(""), precio(0.0), cantidad(0.0), costo(0.0), cantPedidos(0) {}
	    
	    // Constructor con parámetros
	    Carta(string n, string i, double p, int cant, double co, int cantpe);
	    
	    string getNombre() const { return nombre; }
	    string getIngredientes() const { return ingredientes; }
	    double getPrecio() const { return precio; }
	    double getCantidad() const { return cantidad; }
	    double getCosto() const { return costo; }
	    int getCantPedidos() const { return cantPedidos; }
	
	    // Métodos set (modificación)
	    void setNombre(const string& n) { nombre = n; }
	    void setIngredientes(const string& i) { ingredientes = i; }
	    void setPrecio(double p) { precio = p; }
	    void setCantidad(double cant) { cantidad = cant; }
	    void setCosto(double co) { costo = co; }
	    void setCantPedidos(int cantpe) { cantPedidos = cantpe; }
    
	    void agregarComida();
	    void editarCarta();
	    void eliminarComida();
	    void ordenarComida();
	    void verCarta();
};

class Factura{
	private:
		string nombre; int cantPedido, totalPagar;
	public:
		Factura() : nombre(""), cantPedido(0), totalPagar(0) {}
		
		Factura(string n, int c, int t);
		
		string getNombre() const { return nombre; }
	    int getCantPedido() const { return cantPedido; }
	    int getTotalPagar() const { return totalPagar; }
    
		void setNombre(const string& n) { nombre = n; }
	    void setCantPedido(int c) { cantPedido = c; }
	    void setTotalPagar(int t) { totalPagar = t; }
};
extern Carta comida[maxComidas];
extern Factura factura[1000];
#endif
