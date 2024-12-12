#ifndef FUNCIONESMENUCARTA_H
#define FUNCIONESMENUCARTA_H
#include <string>
using namespace std;
const int maxComidas=20;
const int maxFacturas=1000;
extern int cantComidas;
extern int cantFacturas;

class Comida{
	protected:
		string nombre, ingredientes;
		double precio, costo;
		int unidades, unidadesVendidas;
		double ganancia, perdida, neto;
	public:
		Comida(string, string, double, double, int, int, double, double, double);
		Comida() : nombre(""), ingredientes(""), precio(0), costo(0), unidades(0), unidadesVendidas(0), ganancia(0.0), perdida(0.0), neto(0.0) {}
		
		string getNombre() const { return nombre; }
		string getIngredientes() const { return ingredientes; }
		double getPrecio() const { return precio; }
		double getCosto() const { return costo; }
		int getUnidades() const { return unidades; }
		int getUnidadesVendidas() const { return unidadesVendidas; }
		double getGanancia() const { return ganancia; }
		double getPerdida() const { return perdida; }
		double getNeto() const { return neto; }
		
		// Métodos set
		void setNombre(string n) { nombre = n; }
		void setIngredientes(string i) { ingredientes = i; }
		void setPrecio(double p) { precio = p; }
		void setCosto(double c) { costo = c; }
		void setUnidades(int u) { unidades = u; }
		void setUnidadesVendidas(int uV) { unidadesVendidas = uV; }
		void setGanancia(double g) { ganancia = g; }
		void setPerdida(double p) { perdida = p; }
		void setNeto(double net) { neto = net; }
		void setDatosPrimarios(string n, string i, double p, double c, int u){
			nombre=n;
			ingredientes=i;
			precio=p;
			costo=c;
			unidades=u;
		}
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
		string nombreCliente, nombreComida;
		int cantidad;
		double totalPagar, totalInvertido;
	public:
		Factura(string, string, int, double, double);
		Factura() : nombreCliente(""), nombreComida(""), cantidad(0), totalPagar(0.0), totalInvertido(0.0) {}
		
		void leerDatosFacturaEnArchivoBase(Factura*, int&);
		void guardarDatosFacturaEnArchivo(int);
		
		string getNombreCliente() const { return nombreCliente; }
		string getNombreComida() const { return nombreComida; }
		int getCantidad() const { return cantidad;}
		double getTotalPagar() const { return totalPagar;}
		double getTotalInvertido() const { return totalInvertido;}
};

extern Comida comidas[maxComidas];
extern Factura facturas[maxFacturas];
#endif
