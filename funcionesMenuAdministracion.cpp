#include "funcionesMenuAdministracion.h"
#include "funcionesMenuCarta.h"

using namespace std;

// Constructor de Administracion con los parámetros para inicializar la clase base (Carta) y las variables propias.
Administracion::Administracion(string n, string i, double p, int cant, double co, int cantpe, double net, double gan, double per): Carta(n, i, p, cant, co, cantpe) {  // Inicializa la clase base Carta
    neto = net;
    ganancias = gan;
    perdidas = per;
}

// Constructor de Administracion que solo recibe los tres valores adicionales para recaudado, ganancias y perdidas.
Administracion::Administracion(double net, double gan, double per): neto(net), ganancias(gan), perdidas(per) {}

// Arreglo de objetos de la clase Administracion
Administracion finanzas[maxComidas] = {
    Administracion(0.0, 0.0, 0.0),  // Este usa el constructor con tres parámetros (recaudado, ganancias, perdidas)
    Administracion(0.0, 0.0, 0.0),
    Administracion(0.0, 0.0, 0.0),
    Administracion(0.0, 0.0, 0.0),
};

void Administracion::mostrarFacturas() {
	cout << "FACTURAS REGISTRADAS" << endl << endl;
    for(int i=0; i<numFacturas; i++){
    	cout << "F A C T U R A " << i+1 << endl << endl
    		<< "Comida: " << factura[i].getNombre() << endl
    		<< "Cantidad: " << factura[i].getCantPedido() << endl
    		<< "Total pagado: " << factura[i].getTotalPagar() << endl << endl;
	}
}

void Administracion::gastosYGanancias() {
    cout << "Gastos y ganancias" << endl << endl;
    double sumaGanancias=0, sumaGastos=0, neto;
    for(int i=0; i<cantComidas; i++){
    	finanzas[i].setGanancias(0.0);
		finanzas[i].setPerdidas(0.0);
		finanzas[i].setNeto(0.0);

    	finanzas[i].setGanancias(comida[i].getPrecio() * comida[i].getCantPedidos()); //ganancias de la "n" comida
    	sumaGanancias+=finanzas[i].getGanancias();
    	finanzas[i].setPerdidas(comida[i].getCosto() * comida[i].getCantPedidos());//gastos de la "n" comida
    	sumaGastos+=finanzas[i].getPerdidas();
    	finanzas[i].setNeto(finanzas[i].getGanancias() - finanzas[i].getPerdidas());
	}
	neto = sumaGanancias - sumaGastos;
	cout << "Ganancias Totales: " << sumaGanancias << endl
		<< "Gastos Totales: " << sumaGastos << endl
		<< "Neto: " << neto << endl;
}

void Administracion::ordenarMasVendido() {
    Carta copia[maxComidas];  // Crea una copia del menú actual de comidas
    
    // Copia los datos del menú original al array copia
    for (int i = 0; i < cantComidas; i++) {
        copia[i] = comida[i];
    }
    
    // Ordenar las comidas por la cantidad de pedidos (de mayor a menor)
    for (int i = 0; i < cantComidas - 1; i++) {
        for (int j = i + 1; j < cantComidas; j++) {
            if (copia[i].getCantPedidos() < copia[j].getCantPedidos()) {
                // Intercambiar las comidas si la de la posición i tiene menos pedidos que la de la j
                Carta temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    // Imprimir el menú ordenado
    cout << "Comidas ordenadas por mas vendidas: " << endl;
    for (int i = 0; i < cantComidas; i++) {
        cout << "Comida: " << copia[i].getNombre() << ", Cantidad vendida: " << copia[i].getCantPedidos() << endl;
    }
}

void Administracion::estadisticasGenerales() {
	gastosYGanancias();
	double sumaGanancias=0, sumaGastos=0, neto;
    for(int i=0; i<cantComidas; i++){
    	sumaGanancias+=finanzas[i].getGanancias();
    	sumaGastos+=finanzas[i].getPerdidas();
	}
	neto = sumaGanancias - sumaGastos;
    cout << "Ingresos brutos: " << sumaGanancias << endl
    	<< "Egresos brutos: " << sumaGastos << endl
    	<< "Ingresos netos: " << neto << endl
    	<< "Ticket Promedio: " << sumaGanancias/numFacturas << endl
    	<< "Margen de ganancia neta: " << neto/sumaGanancias*100 << "%" << endl
    	<< "ROI: " << neto/sumaGastos  << "%" << endl
    	<< "RIG: S/. " << sumaGanancias/sumaGastos << endl;
}

bool login(){
	string contrasena, contrasenaJhonel = "2024-119026", contrasenaNayeli = "2024-119022";
	cout << "Indique la contrasenia: "; cin >> contrasena; cout << endl << endl;
	if(contrasena==contrasenaJhonel || contrasena==contrasenaNayeli){
		if(contrasena==contrasenaJhonel){
			cout <<"|  ¡Bienvenido Ingeniero Jhonel, revise como va el negocio!  |" << endl;
		} else {
			cout <<"|  ¡Bienvenida Ingeniera Nayeli, revise como va el negocio!  |" << endl;
		}
		return true;
	} else {
		return false;
	}
}
