#ifndef FUNCIONESMENUFINANZAS_H
#define FUNCIONESMENUFINANZAS_H
#include "funcionesMenuCarta.h"

class Finanza{
	private:
		double gananciasTotales, perdidasTotales, netoTotal;
	public:
		Finanza() : gananciasTotales(0.0), perdidasTotales(0.0), netoTotal(0.0) {}
		Finanza(double, double, double);
		
		void leerEstadisticasDesdeArchivoBinario();
		void guardarEstadisticasEnArchivoBinario();
		
		virtual void actualizarEstadisticas();
		void mostrarGastosYGanancias();
		void ordenarMasVendido();
		void mostrarEstadisticasGenerales();
		void mostrarFacturas();
};

#endif
