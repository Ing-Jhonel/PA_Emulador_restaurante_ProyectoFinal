#include "funcionesMenuFinanzas.h"
#include "funcionesMenuCarta.h"
#include "funcionesDiseno.h"
#include <fstream>
#include <iostream>
using namespace std;

string texto; char c;
Finanza::Finanza(double g, double p, double n){
	gananciasTotales=g;
	perdidasTotales=p;
	netoTotal=n;
}

void Finanza::actualizarEstadisticas(){
	gananciasTotales=0.0;
	perdidasTotales=0.0;
	for(int i=0; i<cantFacturas; i++){
		gananciasTotales+=facturas[i].getTotalPagar();
		perdidasTotales+=facturas[i].getTotalInvertido();
	}
	netoTotal = gananciasTotales - perdidasTotales;
}

void Finanza::mostrarGastosYGanancias(){
	actualizarEstadisticas();
	
	c='$';
	texto="CALCULANDO GASTOS Y GANANCIAS";
	enjaular(texto, c);
	
	cout << endl << endl << endl;
	
	texto="Ganancias totales: S/. ";
	centrar(texto); cout << gananciasTotales << endl << endl;
	
	texto="Perdidas totales: S/. ";
	centrar(texto); cout << perdidasTotales << endl << endl;
	
	texto="Ganancia neta: S/. ";
	centrar(texto); cout << netoTotal << endl << endl;
	
}
void Finanza::ordenarMasVendido() {
    Comida copia[maxComidas];
    if (cantComidas == 0) {
        c='-';
			texto="No hay comidas registradas.";
			enlinear(texto, c);
        return;
    }

    for (int i = 0; i < cantComidas; i++) {
        copia[i] = comidas[i];
    }

    for (int i = 0; i < cantComidas - 1; i++) {
        for (int j = 0; j < cantComidas - i - 1; j++) {
            if (copia[j].getUnidadesVendidas() < copia[j+1].getUnidadesVendidas()) {
                Comida aux = copia[j];
                copia[j] = copia[j+1];
                copia[j+1] = aux;
            }
        }
    }
	c='$';
    texto="Comidas mas vendidas (ordenado de mayor a menor)";
    enjaular(texto, c);
    
    cout << endl << endl << endl;
    int por=33;
    for (int i = 0; i < cantComidas; i++) {
    	imprimirEnEspaciadoPorcentaje("", por);
        cout << copia[i].getNombre() << " ----> " << copia[i].getUnidadesVendidas() << endl << endl;
    }
}

void Finanza::guardarEstadisticasEnArchivoBinario() {
	actualizarEstadisticas();
    ofstream archivo("Estadisticas_Generales.dat", ios::binary);
    
    double ticketPromedio = gananciasTotales / cantFacturas;
    double margenGananciaNeta = (netoTotal / gananciasTotales) * 100;
    double ROI = (netoTotal / perdidasTotales) * 100;
    double RIG = gananciasTotales / perdidasTotales;
    
    if (archivo.is_open()) {
        archivo.write((char*)&gananciasTotales, sizeof(gananciasTotales));
        archivo.write((char*)&perdidasTotales, sizeof(perdidasTotales));
        archivo.write((char*)&netoTotal, sizeof(netoTotal));
        archivo.write((char*)&ticketPromedio, sizeof(ticketPromedio));
        archivo.write((char*)&margenGananciaNeta, sizeof(margenGananciaNeta));
        archivo.write((char*)&ROI, sizeof(ROI));
        archivo.write((char*)&RIG, sizeof(RIG));

        archivo.close();
    } else {
        cerr << "Error al abrir el archivo para escribir." << endl;
    }
    
    ofstream archivo2("Estadisticas_Generales.txt", ios::binary);
    archivo2 << "*****************************************************" << endl
    		<< "	E S T A D I S T I C A S   G E N E R A L E S		" << endl
    		<< "*****************************************************" << endl << endl;
    if(archivo2.is_open()){
    	archivo2 << "Ingresos brutos ----------> S/. " << gananciasTotales << endl
             << "Egresos brutos -----------> S/. " << perdidasTotales << endl
             << "Ingresos netos -----------> S/. " << netoTotal << endl
             << "Ticket promedio ----------> S/. " << ticketPromedio << endl
             << "Margen de ganancia neta --> " << margenGananciaNeta << "%" << endl
             << "ROI ----------------------> " << ROI << "%" << endl
             << "RIG ----------------------> " << RIG << endl;
             archivo2.close();
	} else {
		cerr << "Error al abrir el archivo para escribir." << endl;
	}
}

void Finanza::leerEstadisticasDesdeArchivoBinario() {
    ifstream archivo("Estadisticas_Generales.dat", ios::binary);
    if (archivo.is_open()) {
        archivo.read((char*)&gananciasTotales, sizeof(gananciasTotales));
        archivo.read((char*)&perdidasTotales, sizeof(perdidasTotales));
        archivo.read((char*)&netoTotal, sizeof(netoTotal));

        double ticketPromedio;
        double margenGananciaNeta;
        double ROI;
        double RIG;

        archivo.read((char*)&ticketPromedio, sizeof(ticketPromedio));
        archivo.read((char*)&margenGananciaNeta, sizeof(margenGananciaNeta));
        archivo.read((char*)&ROI, sizeof(ROI));
        archivo.read((char*)&RIG, sizeof(RIG));

        archivo.close();
		
		int por=25;
		imprimirEnEspaciadoPorcentaje("",por);
        cout << "Ingresos brutos ---------> S/. " << gananciasTotales << endl << endl;
        imprimirEnEspaciadoPorcentaje("",por);
             cout << "Egresos brutos -----------> S/. " << perdidasTotales << endl << endl;
             imprimirEnEspaciadoPorcentaje("",por);
             cout<< "Ingresos netos -----------> S/. " << netoTotal << endl << endl;
             imprimirEnEspaciadoPorcentaje("",por);
             cout<< "Ticket promedio ----------> S/. " << ticketPromedio << endl << endl;
             imprimirEnEspaciadoPorcentaje("",por);
             cout<< "Margen de ganancia neta --> " << margenGananciaNeta << "%" << endl << endl;
             imprimirEnEspaciadoPorcentaje("",por);
             cout<< "ROI ----------------------> " << ROI << "%" << endl << endl;
             imprimirEnEspaciadoPorcentaje("",por);
             cout<< "RIG ----------------------> " << RIG << endl << endl;
    } else {
        c='-';
			texto="Error al abrir el archivo.";
			enlinear(texto, c);
    }
}

void Finanza::mostrarEstadisticasGenerales(){
	guardarEstadisticasEnArchivoBinario();
	leerEstadisticasDesdeArchivoBinario();
}

void Finanza::mostrarFacturas(){
	
	texto="F A C T U R A S   R E G I S T R A D A S";
	c='$';
	enjaular(texto, c);
	
	cout << endl << endl << endl;
	int porcentajePantalla=25;
	for(int i=0; i<cantFacturas; i++){
		texto= "FACTURA ";
		centrar(texto); cout << i+1 << endl << endl;
		
		texto = "|	A nombre de: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << facturas[i].getNombreCliente() << endl;
		
		texto = "|	Comida: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << facturas[i].getNombreComida() << endl;
		
		texto = "|	Cantidad: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << facturas[i].getCantidad() << endl;
		
		texto = "|	Total pagado: ";
		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); cout << "\t" << facturas[i].getTotalPagar() << endl;
	}
}
