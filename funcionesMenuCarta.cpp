#include "funcionesMenuCarta.h"
using namespace std;

Carta::Carta(string n, string i, double p, int cant, double co){
	nombre=n;
	ingredientes=i;
	precio=p;
	cantidad=cant;
	costo=co;
}

Carta comida[maxComidas] = {
    Carta("Pizza", "Tomate, queso mozzarella, harina", 10.0, 5, 5.0),
    Carta("Hamburguesa", "Carne, lechuga, tomate, pan, queso", 5.0, 10, 2.5),
    Carta("Tacos de Carne", "Harina de trigo, carne, cebolla, salsa", 2.5, 20, 1.0),
    Carta("Pollo frito", "Pollo, papas, sal, aceite", 10.0, 5, 5.0),
};

int cantComidas=4;

void Carta::agregarComida(){
	if(cantComidas<maxComidas){
		cout << "Agregar Comida" << endl << endl;
		cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
		cout << "Ingredientes: "; getline(cin, ingredientes);
		cout << "Precio: "; cin >> precio;
		cout << "Costo: "; cin >> costo;
		cout << "Cantidad: "; cin >> cantidad;	
		cantComidas++;
	} else {
		cout << "No puede agregar mas comidas." << endl;
	}
}

void Carta::editarCarta() {
    string buscar;
    bool encontrado = false;
    cout << "Editar Comida" << endl << endl;
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, buscar);

    // Buscar la comida por nombre
    for (int i = 0; i < cantComidas; i++) {
        if (comida[i].nombre == buscar) {
            encontrado = true;

            // Actualizar los datos de la comida encontrada
            cout << "Ingrese los nuevos datos" << endl << endl;
            cout << "Nombre: "; cin.ignore(); getline(cin, comida[i].nombre);
            cout << "Ingredientes: "; getline(cin, comida[i].ingredientes);
            cout << "Precio: "; cin >> comida[i].precio;
            cout << "Costo: "; cin >> comida[i].costo;
            cout << "Cantidad: "; cin >> comida[i].cantidad;

            cout << "Comida actualizada correctamente." << endl;
            return; // Salir después de actualizar
        }
    }

    if (!encontrado) {
        cout << "Comida no encontrada." << endl;
    }
}

void Carta::eliminarComida(){
	string nombreEliminar;
    cout << "Eliminar Comida" << endl << endl;
    cout << "Ingrese el nombre: "; cin.ignore(); cin >> nombreEliminar;

    bool encontrado = false;
    for (int i=0; i<cantComidas; i++) {
        if (comida[i].nombre == nombreEliminar) {
            for (int j=i; j<cantComidas-1; j++) {
                comida[j] = comida[j+1]; // Desplazar todas las comidas hacia atrás
            }
            --cantComidas;
            encontrado = true;
            cout << "Cliente eliminado." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Cliente no encontrado." << endl;
    }
}

void Carta::verCarta(){
    if (cantComidas == 0) {
        cout << "El menú está vacío.\n";
    } else {
		cout << "Carta de Comidas" << endl;
	    for (int i = 0; i < cantComidas; i++) {
	    	cout << "Comida " << i+1 << endl << endl;
	        cout << "Nombre: " << comida[i].nombre << endl;
	        cout << "Ingredientes: " << comida[i].ingredientes << endl;
	        cout << "Precio: " << comida[i].precio << endl;
	        cout << "Costo: " << comida[i].costo << endl;
	        cout << "Cantidad: " << comida[i].cantidad << endl;
    	}
	} 
}
