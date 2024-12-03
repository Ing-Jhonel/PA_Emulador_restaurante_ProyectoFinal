#ifndef FUNCIONESFINANZAS_H
#define FUNCIONESFINANZAS_H
#include "funcionescarta.h"
#include "funcionesdespensa.h"
using namespace std;

const int MAX_FACTURAS = 100; //tambien se usa para el maximo de ordenes en una factura
extern int numFactura;

struct Ordenes{
	string nombre;
	int cantidad;
	float monto;
};


struct GastoAlimento {
    string nombre;
    float gastos;
    float cantidadUsada;
};

struct paraOrdenarVentas{
	string nombre;
	float total;
	float RIG;
	float coste;
};

extern paraOrdenarVentas ordenarVentas[MAX_ITEMS];
extern Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];
extern GastoAlimento gastos[MAX_ALIMENTOS];
extern float montoDeFactura[MAX_FACTURAS];
extern int ordenesPorFactura[MAX_FACTURAS];
extern float montoFinalGanancias;
extern float montoFinalGastos;
extern int ordenesTotales;

struct ventasDeComidas{
	string nombre;
	int cantidad;
	int monto;
};

extern ventasDeComidas ventasComidas[MAX_FACTURAS];
// ventasComidas[0].comidas[0].nombre
void registrarVenta();
void mostrarOrdenes();
void gastosGanancias();
void ordenarMasVendido();
void estadisticasGenerales();
void agregarMontoArreglo();

#endif


