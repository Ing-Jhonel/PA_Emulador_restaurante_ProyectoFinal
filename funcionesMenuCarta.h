#ifndef FUNCIONESMENUCARTA_H
#define FUNCIONESMENUCARTA_H
#include <string>
using namespace std;
const int maxComidas=20;
extern int cantComidas;

class Comida{
	protected:
		string nombre, ingredientes;
		double precio, costo;
		int unidades;
		double ganancia, perdida;
	public:
		Comida(string, string, double, double, int, double, double);
		Comida() : nombre(""), ingredientes(""), precio(0), costo(0), unidades(0) {}
		
		string getNombre() const { return nombre;}
		string getIngredientes() const { return ingredientes;}
		double getPrecio() const { return precio;}
		double getCosto() const { return costo;}
		int getUnidades() const { return unidades;}
};

class Carta{

	public:
		Carta();
		
		void leerDatosComidasEnArchivoBase(Comida*, int&);
		void guardarDatosCartaEnArchivo(int);
		void pedirDatosCartaParaArchivo(int);
		
		void agregarComida();
		void editarComida();
		void eliminarComida();
		void ordenarComida();
		void mostrarCarta();
};

class Factura{
	protected:
		string nombre;
		int cantidad;
		double totalPagar;
};
extern Comida comidas[maxComidas];
#endif
