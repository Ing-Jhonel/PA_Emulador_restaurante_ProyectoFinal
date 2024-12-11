#include "funcionesMenuCarta.h"
#include <fstream>
#include <iostream>
using namespace std;

int cantComidas=0;

Carta::Carta(){
	cantComidas=0;
}

Comida::Comida(string n, string i, double p, double c, int u){
	nombre=n;
	ingredientes=i;
	precio=p;
	costo=c;
	unidades=u;
}

void Carta::leerDatosComidasEnArchivoBase(Comida arr[], int &cantComidas) {
    ifstream archivo;
    archivo.open("infoComidas.txt", ios::app);
    string linea, nombre, ingredientes;
	double precio, costo;
	int unidades;
	cantComidas=0;
    if(archivo.is_open()){
		archivo.ignore();
		while(getline(archivo, linea)){
			
			getline(archivo, nombre);
			getline(archivo, ingredientes);
			archivo >> precio >> costo >> unidades;
			
			archivo.ignore();
			
			arr[cantComidas]=Comida(nombre, ingredientes, precio, costo, unidades);
			cantComidas++;
		}
		archivo.close();
	} else {
		
	}
	
}
void Carta::pedirDatosCartaParaArchivo(int posicion){
	ofstream archivo;
	archivo.open("infoComidas.txt", ios::app);
	string nombre, ingredientes; double costo, precio; int unidades;
	cin.ignore();
	cout << "Nombre: "; getline(cin, nombre);
	cout << "Ingredientes: "; getline(cin, ingredientes);
	cout << "Costo: "; cin >> costo;
	cout << "Precio: "; cin >> precio;
	cout << "Unidades: "; cin >> unidades;
	comidas[posicion]=Comida(nombre, ingredientes, costo, precio, unidades);
	archivo.close();
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
        			<< comidas[i].getUnidades() << endl;
		}	
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
	archivo.close();
	
	archivo.open("Comidas_Registradas.txt", ios::trunc); //guarda la info en el archivo que el usuario vera
	archivo << "*****************************************************" << endl
		<< "        C O M I D A S   R E G I S T R A D A S		 " << endl
		<< "*****************************************************" << endl << endl;
	//int i=cantClientes;
	for(int i=0; i<=cantComidas-k; i++){
		archivo << endl << "COMIDA " << i+1 << endl << endl
			<< "Nombre: " << comidas[i].getNombre() << endl
			<< "Ingredientes: " << comidas[i].getIngredientes() << endl
			<< "Precio: " << comidas[i].getPrecio() << endl
			<< "Costo: " << comidas[i].getCosto() << endl
			<< "Unidades: " << comidas[i].getUnidades() << endl
			<< "-------------------------------------------" << endl;
	}
	archivo.close();
	
	archivo.open("Carta_Del_Restaurante.txt", ios::trunc); //guarda la info en el archivo que el usuario vera
	archivo << "*****************************************************" << endl
		<< "        C A R T A   D E L   R E S T A U R A N T E		 " << endl
		<< "*****************************************************" << endl << endl;
	//int i=cantClientes;
	archivo << endl << endl;
	archivo << "\tNombre" << "\t\t\t\t\tPrecio\t\t\tUnidades" << endl << endl;
	for(int i=0; i<=cantComidas-k; i++){
		archivo << comidas[i].getNombre() << "______________________ S/. " << comidas[i].getPrecio() << " ------------> " << comidas[i].getUnidades() << endl << endl;
	}
	archivo.close();
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
