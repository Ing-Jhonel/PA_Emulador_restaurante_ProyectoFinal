#include "funcionesMenuCarta.h"
using namespace std;

Factura factura[1000];

Carta::Carta(string n, string i, double p, int cant, double co, int cantpe){
	nombre=n;
	ingredientes=i;
	precio=p;
	cantidad=cant;
	costo=co;
	cantPedidos=cantpe;
}

Factura::Factura(string n, int c, int t){
	nombre=n;
	cantPedido=c;
	totalPagar=t;
}

Carta comida[maxComidas] = { //NO HAY QUE TOCAR, NI MOVER
    Carta("Pizza", "Tomate, queso mozzarella, harina", 10.0, 5, 5.0, 0),
    Carta("Hamburguesa", "Carne, lechuga, tomate, pan, queso", 5.0, 10, 2.5, 0),
    Carta("Tacos de Carne", "Harina de trigo, carne, cebolla, salsa", 2.5, 20, 1.0, 0),
    Carta("Pollo frito", "Pollo, papas, sal, aceite", 10.0, 5, 5.0, 0),
};

int cantComidas=4;
int numFacturas=0;

void validarEntrada(const string& mensaje, double& valor) {
    do {
        cout << mensaje;
        cin >> valor;
        if (valor <= 0) {
            cout << "No valido. Indique de nuevo." << endl;
    	}
    } while (valor <= 0);
}

void Carta::agregarComida() {
    if (cantComidas < maxComidas) {
        cout << "Agregar Comida" << endl << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingredientes: ";
        getline(cin, ingredientes);

        validarEntrada("Precio: ", precio);
        validarEntrada("Costo: ", costo);
        validarEntrada("Cantidad: ", cantidad);

        cantComidas++;
    } else {
        cout << "No puede agregar más comidas." << endl;
    }
}

void Carta::editarCarta() {
    string buscar;
    bool encontrado = false; int indice;
	cout << "Editar Comida" << endl << endl;
	verCarta(); cout << endl
	<< "Ingrese el numero: "; cin >> indice;
	buscar = comida[indice-1].getNombre();
	
    // Buscar la comida por nombre
    for (int i = 0; i < cantComidas; i++) {
        if (comida[i].getNombre() == buscar) {
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
	string nombreEliminar; int indice;
    cout << "Eliminar Comida" << endl << endl;
	verCarta(); cout << endl
	<< "Ingrese el numero: "; cin >> indice;
	nombreEliminar = comida[indice-1].getNombre();
	
    bool encontrado = false;
    for (int i=0; i<cantComidas; i++) {
        if (comida[i].getNombre() == nombreEliminar) {
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

void Carta::ordenarComida(){
	int pedir; double unidades; bool seguir;
	cout << "Ordenar Comida" << endl << endl;
	verCarta(); cout << endl
	<< "Ingrese el numero: "; cin >> pedir;
    
    pedir--;
	do {
        seguir = false;  // Asumimos que la entrada será correcta a menos que se indique lo contrario

        cout << endl << endl
        	<< "Ingrese la cantidad: "; cin >> unidades;
        // Si la cantidad es mayor que la disponible, debemos repetir el ciclo
        if (unidades <= 0 || unidades > comida[pedir].getCantidad()) {
            cout << "No disponible. Indique de nuevo." << endl;
          	 // Indicamos que queremos repetir el ciclo
        } else {
        	seguir = true;
		}
    } while (!seguir);
	
	comida[pedir].setCantidad(comida[pedir].getCantidad() - unidades);
    comida[pedir].setCantPedidos(comida[pedir].getCantPedidos() + unidades);
    
	cout << endl << endl
	<< "G e n e r a n d o   f a c t u r a . . ." << endl << endl;
	system("pause");
	cout << "F A C T U R A " << numFacturas+1 << endl << endl
	<< "Comida: " << comida[pedir].getNombre() << endl
	<< "Cantidad: " << unidades << endl
	<< "Total a pagar: " << unidades*comida[pedir].getPrecio() << endl;
	system("pause");
	factura[numFacturas].setNombre(comida[pedir].getNombre());
    factura[numFacturas].setCantPedido(unidades);
    factura[numFacturas].setTotalPagar(unidades * comida[pedir].getPrecio());

	
	numFacturas++;
}

void Carta::verCarta() {
    if (cantComidas == 0) {
        cout << "El menu está vacío.\n";
    } else {
        cout << "Carta de Comidas" << endl;
        for (int i = 0; i < cantComidas; i++) {
            cout << "Comida " << i + 1 << endl << endl;
            cout << "Nombre: " << comida[i].getNombre() << endl;
            cout << "Ingredientes: " << comida[i].getIngredientes() << endl;
            cout << "Precio: " << comida[i].getPrecio() << endl;
            cout << "Costo: " << comida[i].getCosto() << endl;
            cout << "Cantidad: " << comida[i].getCantidad() << endl;
        }
    }
}
