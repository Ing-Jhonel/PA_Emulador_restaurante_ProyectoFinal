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
	public:
		Comida(string, string, double, double, int);
		Comida() : nombre(""), ingredientes(""), precio(0), costo(0), unidades(0) {}
		
		string getNombre() const { return nombre;}
		string getIngredientes() const { return ingredientes;}
		double getPrecio() const { return precio;}
		double getCosto() const { return costo;}
		int getUnidades() const { return unidades;}
};

class Carta{
	public:
		Comida comidas[maxComidas];
	public:
		Carta();
		
		void leerDatosComidasEnArchivoBase(Comida, int&);
		void guardarDatosCartaEnArchivo(int);
		void pedirDatosCartaParaArchivo(int);
		Comida* getComidas() { return comidas; }
		
		void agregarComida();
		void editarComida();
		void eliminarComida();
		void ordenarComida();
		void mostrarCarta();
};

#endif
