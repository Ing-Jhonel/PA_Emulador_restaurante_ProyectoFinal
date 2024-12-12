#include "funcionesMenuCarta.h"
#include "funcionesMenuClientes.h"
#include "funcionesMenuFinanzas.h"
#include <fstream>
#include <iostream>
using namespace std;

int cantComidas=0;
int cantFacturas=0;
Factura facturas[maxFacturas];
Comida comidas[maxComidas];

Factura::Factura(string nCli, string nCo, int c, double tP, double tI){
	nombreCliente=nCli;
	nombreComida=nCo;
	cantidad=c;
	totalPagar=tP;
	totalInvertido=tI;
}
Carta::Carta(){
}

Comida::Comida(string n, string i, double p, double c, int u, int uv, double gan, double per, double net){
	nombre=n;
	ingredientes=i;
	precio=p;
	costo=c;
	unidades=u;
	unidadesVendidas=uv;
	ganancia=gan;
	perdida=per;
	neto=net;
}

void Carta::leerDatosComidasEnArchivoBase(Comida comidas[], int& cantComidas) { //
    ifstream archivo;
    archivo.open("infoComidas.txt");
    cantComidas=0;
    string linea, nombre, ingredientes;
	double precio, costo;
	int unidades, unidadesVendidas;
	double ganancias, perdidas, neto;
    if(archivo.is_open()){
    	archivo.ignore();
		while(getline(archivo, linea)){
			
			getline(archivo, nombre);
			getline(archivo, ingredientes);
			archivo >> precio >> costo >> unidades >> unidadesVendidas >> ganancias >> perdidas >> neto;
			
			archivo.ignore();
			
			comidas[cantComidas]=Comida(nombre, ingredientes, precio, costo, unidades, unidadesVendidas, ganancias, perdidas, neto);
			
			cantComidas++;
		}
		archivo.close();
	} else {
		
	}
	/*cout << endl << endl;
	for(int i=0; i<cantComidas; i++){
		cout << comidas[i].getNombre() << endl;
	}
	cout << endl;*/
	
}

void Carta::pedirDatosCartaParaArchivo(int posicion){//
	/*ofstream archivo;
	archivo.open("infoComidas.txt", ios::app);*/
	string nombre, ingredientes; double costo, precio; int unidades;
	cin.ignore();
	cout << "Nombre: "; getline(cin, nombre);
	cout << "Ingredientes: "; getline(cin, ingredientes);
	cout << "Precio: "; cin >> precio;
	cout << "Costo: "; cin >> costo;
	cout << "Unidades: "; cin >> unidades;
	//comidas[posicion]=Comida(nombre, ingredientes, costo, precio, unidades);
	comidas[posicion].setDatosPrimarios(nombre, ingredientes, precio, costo, unidades);
	//archivo.close();
}
void Carta::guardarDatosCartaEnArchivo(int k){ // son dos funciones de guardar datos; k=0 si es agregar; k= si es alterar el archivo
	ofstream archivo;
	archivo.open("infoComidas.txt", ios::trunc); //guarda la info en el archivo base, que el usuario no debe ver, puro info para datos
	if (archivo.is_open()) {
		for(int i=0; i<=cantComidas-k; i++){
			archivo << i << endl
        			<< comidas[i].getNombre() << endl
        			<< comidas[i].getIngredientes() << endl
        			<< comidas[i].getPrecio() << endl
        			<< comidas[i].getCosto() << endl
        			<< comidas[i].getUnidades() << endl
        			<< comidas[i].getUnidadesVendidas() << endl
        			<< comidas[i].getPrecio()*comidas[i].getUnidadesVendidas() << endl
        			<< comidas[i].getCosto()*comidas[i].getUnidadesVendidas() << endl
        			<< comidas[i].getGanancia() - comidas[i].getPerdida() << endl;
		}	
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
	archivo.close();
	
	archivo.open("Comidas_Registradas.txt", ios::trunc); //guarda la info en el archivo que el usuario vera
	if(archivo.is_open()){
		archivo << "*****************************************************" << endl
		<< "        C O M I D A S   R E G I S T R A D A S		 " << endl
		<< "*****************************************************" << endl << endl;
		//int i=cantClientes;
		for(int i=0; i<=cantComidas-k; i++){
			archivo << endl << "COMIDA " << i+1 << endl << endl
				<< "Nombre: " << comidas[i].getNombre() << endl
				<< "Ingredientes: " << comidas[i].getIngredientes() << endl
				<< "Precio: S/. " << comidas[i].getPrecio() << endl
				<< "Costo: S/. " << comidas[i].getCosto() << endl
				<< "Unidades: " << comidas[i].getUnidades() << endl
				<< "Unidades vendidas: " << comidas[i].getUnidadesVendidas() << endl
				<< "Ganancias: S/. " << comidas[i].getGanancia() << endl
				<< "Perdidas: S/. " << comidas[i].getPerdida() << endl
				<< "Neto: S/. " << comidas[i].getNeto() << endl
				<< "-------------------------------------------" << endl;
		}
	} else {
        cout << "Error al abrir el archivo." << endl;
    }
	archivo.close();
	
	archivo.open("Carta_Del_Restaurante.txt", ios::trunc); //guarda la info en el archivo que el usuario vera
	if (archivo.is_open()) {
		archivo << "*****************************************************" << endl
			<< "        C A R T A   D E L   R E S T A U R A N T E		 " << endl
			<< "*****************************************************" << endl << endl;
		//int i=cantClientes;
		archivo << endl << endl;
		archivo << "\tNombre" << "\t\t\tPrecio\t\tUnidades" << endl << endl;
		for(int i=0; i<=cantComidas-k; i++){
			archivo << comidas[i].getNombre() << "______________________ S/. " << comidas[i].getPrecio() << " ------------> " << comidas[i].getUnidades() << endl << endl;
		}
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
	archivo.close();
}

void mostrarComidas(){
	cout << "Comidas Registradas" << endl << endl;
	for(int i=0; i<cantComidas; i++){
		cout << "COMIDA " << i+1 << endl << endl
			<< "Nombre: " << comidas[i].getNombre() << endl
			<< "Ingredientes: " << comidas[i].getIngredientes() << endl
			<< "Precio: " << comidas[i].getPrecio() << endl
			<< "Costo: " << comidas[i].getCosto() << endl
			<< "Unidades: " << comidas[i].getUnidades() << endl << endl;
	}
}
void Factura::guardarDatosFacturaEnArchivo(int k){
	ofstream archivo;
	archivo.open("infoFactura.txt", ios::trunc);
	if(archivo.is_open()){
		for(int i=0; i<=cantFacturas-k; i++){
			archivo << i << endl
					<< facturas[i].nombreCliente << endl
					<< facturas[i].nombreComida << endl
					<< facturas[i].cantidad << endl
					<< facturas[i].totalPagar << endl
					<< facturas[i].totalInvertido << endl;
		}
		archivo.close();
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
	
	archivo.open("Facturas_Registradas.txt", ios::trunc);
	if(archivo.is_open()){
		archivo << "*****************************************************" << endl
			<< "        F A C T U R A S   R E G I S T R A D A S		 " << endl
			<< "*****************************************************" << endl << endl;
		
		for(int i=0; i<=cantFacturas-k; i++){
			archivo << "FACTURA " << i+1 << endl << endl
					<< "A nombre de: " << facturas[i].nombreCliente << endl
					<< "Comida: " << facturas[i].nombreComida << endl
					<< "Cantidad: " << facturas[i].cantidad << endl << endl
					<< " - Total a pagar --> S/. " << facturas[i].totalPagar << endl
					<< "_______________________________________" << endl << endl;
		}
		archivo.close();
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
}
void Factura::leerDatosFacturaEnArchivoBase(Factura facturas[], int& cantFacturas){
	ifstream archivo;
    archivo.open("infoFactura.txt");
    string linea, nombreCliente, nombreComida;
	double totalPagar, totalInvertido;
	int cantidad;
	cantComidas=0;
    if(archivo.is_open()){
		archivo.ignore();
		while(getline(archivo, linea)){
			
			getline(archivo, nombreCliente);
			getline(archivo, nombreComida);
			archivo >> cantidad >> totalPagar >> totalInvertido;
			
			archivo.ignore();
			
			facturas[cantFacturas]=Factura(nombreCliente, nombreComida, cantidad, totalPagar, totalInvertido);
			cantFacturas++;
		}
		archivo.close();
	} else {
		
	}
}

void Carta::agregarComida(){
	ofstream archivo;
	archivo.open("infoClientes.txt", ios::app);
	if(archivo.is_open()){
		if(cantComidas < maxComidas){
			cout << "Agregando Comida" << endl << endl;
			pedirDatosCartaParaArchivo(cantComidas);
			guardarDatosCartaEnArchivo(0);
			
			cantComidas++;	
			cout << "Comida agregada exitosamente." << endl;
		} else{
			cout << "No puede agregar mas. Actualice el limite." << endl;
		}
	} else {
		cout << "Error al abrir el archivo." << endl;
	}
}
void Carta::editarComida(){
	
	int num; bool seguir;
	cout << "Editando Comida" << endl << endl
		<< "Elija la comida" << endl << endl;
	mostrarComidas();
	do{
		cout << "Indique el numero: "; cin >> num;
		if( 0<num && num<=cantComidas){
			seguir=true;
			pedirDatosCartaParaArchivo(num-1);
			guardarDatosCartaEnArchivo(1);
		} else {
			seguir=false;
			cout << "Numero de comida no encontrado. Intente de nuevo." << endl;
		}
	} while ( !seguir);
	cout << "Comida editara exitosamente.";
}
void Carta::eliminarComida(){
	
	int num; bool seguir;
	cout << "Eliminando Comida" << endl << endl
		<< "Elija la comida" << endl << endl;
	mostrarComidas();
	do{
		cout << "Indique el numero: "; cin >> num;
		if( 0<num && num<=cantComidas){
			seguir=true;
			for (int i = num-1; i<cantComidas-1; i++) {
		        comidas[i] = comidas[i+1];
		    }
		    cantComidas--;
		    guardarDatosCartaEnArchivo(1);
		} else {
			seguir=false;
			cout << "Numero de comida no encontrado. Intente de nuevo." << endl;
		}
	} while (!seguir);
	cout << "Comida eliminada exitosamente.";
}
void Carta::ordenarComida(){
	int num, cant; string nombre; bool seguir;
	cout << "Ordenando Comida..." << endl << endl
		<< "Elija la comida a pedir" << endl << endl;
	mostrarComidas();
	do{
		seguir=false;
		cout << "Indique el numero: "; cin >> num; //indice-1 de la comida
		if( 0<num && num<=cantComidas){
			//seguir=true;
			do{
				seguir=false;
				cout << "Indique la cantidad: "; cin >> cant;
				if(0<cant && cant<=comidas[num-1].getUnidades()){
					//seguir=true;
					do{
						seguir=false;
						cout << "Indique a que nombre: "; cin >> nombre;
						for(int i=0; i<cantClientes; i++){
							if(clientes[i].getNombre() == nombre){
								seguir=true;
								cout << "G E N E R A N D O   F A C T U R A . . ." << endl << endl;
								facturas[cantFacturas]=Factura(clientes[i].getNombre(), comidas[num-1].getNombre(), cant, comidas[num-1].getPrecio()*cant, comidas[num-1].getCosto()*cant);
								Factura fact;
								fact.guardarDatosFacturaEnArchivo(0);
								
								int unidadesAntes=comidas[num-1].getUnidades();
								comidas[num-1].setUnidades(unidadesAntes - cant);
								
								int vendidoAntes=comidas[num-1].getUnidadesVendidas();
								comidas[num-1].setUnidadesVendidas(vendidoAntes + cant);
								
								double gananciasAntes=comidas[num-1].getGanancia();
								double gananciasAhora=cant*comidas[num-1].getPrecio();
								comidas[num-1].setGanancia(gananciasAntes+gananciasAhora);
								
								double perdidaAntes=comidas[num-1].getPerdida();
								double perdidaAhora=cant*comidas[num-1].getCosto();
								comidas[num-1].setPerdida(perdidaAntes+perdidaAhora);
								
								double netoNuevo=comidas[num-1].getGanancia() - comidas[num-1].getPerdida();
								comidas[num-1].setNeto(netoNuevo);
								
								guardarDatosCartaEnArchivo(1);
								Finanza finanzas;
								finanzas.actualizarEstadisticas();
								//VERIFICAR que todos los datos de ganncias, perdidas, neto se guarden correctamente en infoCOmida
								//Asegurarse que factura registre todas las facturas por siempre, que no se reinicie
								//
								break;
							}
						}
						if(!seguir){
							cout << "Cliente no encontrado. Intente de nuevo." << endl;
						}
					} while(!seguir);
				} else if (comidas[num-1].getUnidades()==0){
					cout << "Comida sin unidades. Pruebe con otra comida." << endl << endl;
					cout << "Indique el numero: "; cin >> num;
				}else {
					cout << "Cantidad no disponible. Intente de nuevo." << endl << endl;
				}
			} while(!seguir);
		} else {
			cout << "Numero de comida no encontrado. Intente de nuevo." << endl << endl;
		}
	} while (!seguir);
}
void Carta::mostrarCarta(){
	cout << "Carta del restaurante" << endl << endl;
	cout << "Nombre" << "\t\t\tPrecio\t\tDisponibles" << endl << endl;
	for(int i=0; i<cantComidas; i++){
		cout << comidas[i].getNombre() << " ------------>  S/. " << comidas[i].getPrecio() << "\t  " << comidas[i].getUnidades() << endl;
	}
}
