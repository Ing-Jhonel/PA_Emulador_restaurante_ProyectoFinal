#ifndef FUNCIONESMENUADMINISTRACION_H
#define FUNCIONESMENUADMINISTRACION_H
#include "funcionesMenuCarta.h"

class Administracion : public Carta{ //esta linealmente relacionado con las comidas de Carta
	private:
		double neto, ganancias, perdidas;
		
	public:
		
		Administracion() : neto(0.0), ganancias(0.0), perdidas(0.0) {}
		Administracion(string, string, double, int, double, int, double, double, double);
		Administracion(double net, double gan, double per);
		
		double getRecaudado() const { return neto; }
	    double getGanancias() const { return ganancias; }
	    double getPerdidas() const { return perdidas; }
	    
	    void setNeto(double net) { neto = net; }
	    void setGanancias(double gan) { ganancias = gan; }
	    void setPerdidas(double per) { perdidas = per; }
	    
		static void mostrarFacturas();
		static void gastosYGanancias();
		static void ordenarMasVendido();
		static void estadisticasGenerales();
};
bool login();
extern Administracion finanzas[maxComidas]; 
#endif
