#include "funcionescarta.h"
#include <iostream>
#include "FUNCIONESDISENO.h"
using namespace std;

Producto hamburguesas[MAX_ITEMS] = {
    {"Hamburguesa de pollo", 5.0},
    {"Hamburguesa de carne", 6.0}
};

Producto pizzas[MAX_ITEMS] = {
    {"Pizza personal", 10.0},
    {"Pizza mediana", 15.0},
    {"Pizza familiar", 25.0}
};

Producto conos[MAX_ITEMS] = {
    {"Cono de pollo", 5.0},
    {"Cono de salchicha", 6.0},
    {"Cono mixto", 7.0}
};

Producto gaseosas[MAX_ITEMS] = {
    {"Coca-Cola", 3.0},
    {"Inca-Kola", 3.0}
};

Producto aguas[MAX_ITEMS] = {
    {"Agua sin gas", 1.0},
    {"Agua con gas", 1.5}
};

int numHamburguesas = 2;
int numPizzas = 3;
int numConos = 3;
int numGaseosas = 2;
int numAguas = 2;


// FUNCION MOSTRAR CARTA
void mostrarCarta() {
	char c;
	string texto;
	float porcentajePantalla;
	color(hConsole, 14);
	c='*';
	texto = "CARTA DE HOY";
	enlinearYEnjaular(texto, c); cout << endl << endl << endl;
	color(hConsole, 7);
	cout << endl;
	
	c='#';
	porcentajePantalla = 35;
	texto = "Hamburguesas";
	enjaular(texto, c); cout << endl << endl;
    for (int i = 0; i < numHamburguesas; i++) {
    	texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
        cout << "   " << hamburguesas[i].nombre << "_______________________________" << " S/. " << hamburguesas[i].precio << endl;
    }
    cout << endl << endl;
    texto = "Pizzas";
	enjaular(texto, c); cout << endl << endl;
    for (int i = 0; i < numPizzas; i++) {
    	texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
        cout << "   " << pizzas[i].nombre << "___________________________________" << " S/. " << pizzas[i].precio << endl;
    }
    cout << endl << endl;
    texto = "Conos";
	enjaular(texto, c); cout << endl << endl;
    for (int i = 0; i < numConos; i++) {
    	texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
        cout << "   " << conos[i].nombre << "_________________________________" << " S/. " << conos[i].precio << endl;
    }
    cout << endl << endl << endl;
    texto = "BEBIDAS";
    centrar(texto); cout << endl << endl << endl;
    texto = "Conos";
	enjaular(texto, c); cout << endl << endl;
    for (int i = 0; i < numGaseosas; i++) {
    	texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
        cout << "      " << gaseosas[i].nombre << "________________________________" << " S/. " << gaseosas[i].precio << endl;
    }
    cout << endl << endl;
    texto = "Conos";
	enjaular(texto, c); cout << endl << endl;
    for (int i = 0; i < numAguas; i++) {
    	texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
        cout << "      " << aguas[i].nombre << "_______________________________" << " S/. " << aguas[i].precio << endl;
    }
    
    espacio();
	c='-';
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU CARTA... |";
	enlinear(texto, c);
}
//FUNCION PARA EDITAR CARTA
void editarCarta() {
    int  item;
    char c;
    string texto;
    float porcentajePantalla;
	char categoria;
	
    do {
		c='*';
		color(hConsole, 14);
		texto = "EDITAR CARTA";
		enlinearYEnjaular(texto, c); 
		color(hConsole, 7);
		cout << endl << endl << endl;
		
		c='=';
		texto = "Seleccione la categoria para editar:";
		centrarYSubrayar(texto, c); cout << endl << endl << endl;
		
		c='.';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "a) Hamburguesas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "b) Pizzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "c) Conos.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "d) Gaseosas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "e) Aguas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "f) Volver al menu anterior.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "-----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> categoria;
		
	    cout << endl << endl << endl;
	    
	    porcentajePantalla=45;
	    c='-';
	    switch (categoria) {
	        case 'a':
	        	texto = "Seleccione el producto a editar:";
	    		centrarYSubrayar(texto, c); cout << endl << endl << endl;
	            for (int i = 0; i < numHamburguesas; i++) {
	            	texto = " ";
	            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
	            }
	            cout << endl;
	            texto = "-----";
				centrar(texto); cout << endl;
				centrarCin(1);
				cin >> item;
				
				espacio();
				
	            item -= 1;
	            if (item >= 0 && item < numHamburguesas) {
	                cin.ignore(); // Ignorar el primer valor
	                texto =  "| Nuevo nombre: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                getline(cin, hamburguesas[item].nombre); cout << endl;
	                texto =  "| Nuevo precio: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cin >> hamburguesas[item].precio;
	                
	                espacio();
	                
	                color(hConsole, 10);
					texto = "> PRODUCTO EDITADO SATISFACTORIAMENTE <";
					enlinear(texto, c);
	            } else {
	                color(hConsole, 4);
	                texto = "NO VALIDO. NO ES POSIBLE EDITAR EL PRODUCTO";
					enlinear(texto, c);
	            }
	            espacio();
	            break;
			case 'b':
	
	        	texto = "Seleccione el producto a editar:";
	    		centrarYSubrayar(texto, c); cout << endl << endl << endl;
	    		
	            for (int i = 0; i < numPizzas; i++) {
	            	texto = " ";
	            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
	            }
	            cout << endl;
	            texto = "-----";
				centrar(texto); cout << endl;
				centrarCin(1);
				cin >> item;
				
				espacio();
				
	            item -= 1;
	            if (item >= 0 && item < numPizzas) {
	                cin.ignore(); // Ignorar el primer valor
	                texto =  "| Nuevo nombre: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                getline(cin, pizzas[item].nombre); cout << endl;
	                texto =  "| Nuevo precio: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cin >> pizzas[item].precio;
	                
	                espacio();
	                
	                color(hConsole, 10);
					texto = "> PRODUCTO EDITADO SATISFACTORIAMENTE <";
					enlinear(texto, c);
	            } else {
	            	color(hConsole, 4);
	                texto = "PRODUCTO NO VALIDO";
					enlinear(texto, c);
	            }
	            espacio();
	            break;
	        case 'c':
	        	
	        	texto = "Seleccione el producto a editar:";
	    		centrarYSubrayar(texto, c); cout << endl << endl << endl;
	    		
	            for (int i = 0; i < numConos; i++) {
	            	texto = " ";
	            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
	            }
	            cout << endl;
	            texto = "-----";
				centrar(texto); cout << endl;
				centrarCin(1);
				cin >> item;
				
				espacio();
				
	            item -= 1;
	            if (item >= 0 && item < numConos) {
	                cin.ignore(); // Ignorar el primer valor
	                texto =  "| Nuevo nombre: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                getline(cin, conos[item].nombre); cout << endl;
	                texto =  "| Nuevo precio: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cin >> conos[item].precio;
	                
	                espacio();
	                
	                color(hConsole, 10);
					texto = "> PRODUCTO EDITADO SATISFACTORIAMENTE <";
					enlinear(texto, c);
	            } else {
	            	color(hConsole, 4);
	                texto = "PRODUCTO NO VALIDO";
					enlinear(texto, c);
	            }
	            espacio();
	            break;
	        case 'd':
	        	
	        	texto = "Seleccione el producto a editar:";
	    		centrarYSubrayar(texto, c); cout << endl << endl << endl;
	    		
	            for (int i = 0; i < numGaseosas; i++) {
	            	texto = " ";
	            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
	            }
	            cout << endl;
	            texto = "-----";
				centrar(texto); cout << endl;
				centrarCin(1);
				cin >> item;
				
				espacio();
				
	            item -= 1;
	            if (item >= 0 && item < numGaseosas) {
	                cin.ignore(); // Ignorar el primer valor
	                texto =  "| Nuevo nombre: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                getline(cin, gaseosas[item].nombre); cout << endl;
	                texto =  "| Nuevo precio: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cin >> gaseosas[item].precio;
	                
	                espacio();
	                
	                color(hConsole, 10);
					texto = "> PRODUCTO EDITADO SATISFACTORIAMENTE <";
					enlinear(texto, c);
	            } else {
	            	color(hConsole, 4);
	                texto = "PRODUCTO NO VALIDO";
					enlinear(texto, c);
	            }
	            espacio();
	            break;
	        case 'e':
	        	
	        	texto = "Seleccione el producto a editar:";
	    		centrarYSubrayar(texto, c); cout << endl << endl << endl;
	    		
	            for (int i = 0; i < numAguas; i++) {
	            	texto = " ";
	            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
	            }
	            cout << endl;
	            texto = "-----";
				centrar(texto); cout << endl;
				centrarCin(1);
				cin >> item;
				
				espacio();
				
	            item -= 1;
	            if (item >= 0 && item < numAguas) {
	                cin.ignore(); // Ignorar el primer valor
	                texto =  "| Nuevo nombre: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                getline(cin, aguas[item].nombre); cout << endl;
	                texto =  "| Nuevo precio: ";
	                imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	                cin >> aguas[item].precio;
	                
	                espacio();
	                
	                color(hConsole, 10);
					texto = "> PRODUCTO EDITADO SATISFACTORIAMENTE <";
					enlinear(texto, c);
	            } else {
	            	color(hConsole, 4);
	                texto = "PRODUCTO NO VALIDO";
					enlinear(texto, c);
	            }
	            espacio();
	            break;
	        case 'f':
	        	break;
	        default:
	        	cout << endl << endl;
				color(hConsole, 4);
				texto = "CATEGORIA NO ENCONTRADA.INTENTE DE NUEVO";
				enlinear(texto, c);
				espacio();
	        	break;
	    }
	cout << endl << endl;
    }while (categoria != 'f');
		color(hConsole, 10);
		texto = "| EDICION DE CARTA TERMINADA |";
		enlinear(texto, c);
		color(hConsole, 7);
		
		cout << endl << endl;

		color(hConsole, 8);
		texto = "| VOLVIENDO AL MENU CARTA... |";
		enlinear(texto, c);
}
//FUNCION PARA AGREGAR A LA CARTA
void agregarCarta() {
    char categoria;
    string texto;
    char c;
    float porcentajePantalla;
    Producto nuevoProducto;
    	
    do{
    	c='*';
		color(hConsole, 14);
		texto = "AGREGAR PRODUCTO A LA CARTA";
		enlinearYEnjaular(texto, c); 
		color(hConsole, 7);
		cout << endl << endl << endl;
		
    	color(hConsole, 7);
	    c='=';
		texto = "Seleccione la categoria para agregar un nuevo producto: ";
		centrarYSubrayar(texto, c);
		cout << endl << endl;
		
    	c='.';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Hamburguesas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Pizzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Conos.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Gaseosas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Aguas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "F) Volver al menu anterior.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "-----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> categoria;
		cout << endl << endl << endl;
	   
	   porcentajePantalla=40;
	   c='-';
	     switch (categoria) {
	     	
	        case 'A':	
	        	texto =  "Ingrese el nombre del nuevo producto: ";
	        	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	        	cin.ignore();
			    getline(cin, nuevoProducto.nombre); cout << endl;
			    
			    texto =  "Ingrese el precio del nuevo producto: ";
			    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			    cin >> nuevoProducto.precio;
			    
			    cout << endl << endl << endl;
	            if (numHamburguesas < MAX_ITEMS) {
	                hamburguesas[numHamburguesas] = nuevoProducto;
	                numHamburguesas++;
	            
	            cout << endl;
	            
	            color(hConsole, 10);
				texto = "> PRODUCTO AGREGADO EXITOSAMENTE <";
				enlinear(texto, c);
	            } else {
	               
	            	(hConsole, 4);
				texto = "NO SE PUEDE AGREGAR MAS";
				enlinear(texto, c);
	            }
	            cout << endl << endl << endl;
	            break;
	        case 'B':	
	        	texto =  "Ingrese el nombre del nuevo producto: ";
	        	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	        	cin.ignore();
			    getline(cin, nuevoProducto.nombre); cout << endl;
			    
			    texto =  "Ingrese el precio del nuevo producto: ";
			    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			    cin >> nuevoProducto.precio;
			    
			    cout << endl << endl << endl;
	            if (numPizzas < MAX_ITEMS) {
	                pizzas[numPizzas] = nuevoProducto;
	                numPizzas++;
	            
	            cout << endl;
	            
	            color(hConsole, 10);
				texto = "> PRODUCTO AGREGADO EXITOSAMENTE <";
				enlinear(texto, c);
	            } else {
	                
	            	(hConsole, 4);
				texto = "NO SE PUEDE AGREGAR MAS";
				enlinear(texto, c);
	            }
	            cout << endl << endl << endl;
	            break;
	        case 'C':	
	        	texto =  "Ingrese el nombre del nuevo producto: ";
	        	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	        	cin.ignore();
			    getline(cin, nuevoProducto.nombre); cout << endl;
			    
			    texto =  "Ingrese el precio del nuevo producto: ";
			    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			    cin >> nuevoProducto.precio;
			    
			    cout << endl << endl << endl;
	            if (numConos < MAX_ITEMS) {
	                conos[numConos] = nuevoProducto;
	                numConos++;
	            
	            cout << endl;
	            
	            color(hConsole, 10);
				texto = "> PRODUCTO AGREGADO EXITOSAMENTE <";
				enlinear(texto, c);
	            } else {
	                
	            	(hConsole, 4);
				texto = "NO SE PUEDE AGREGAR MAS";
				enlinear(texto, c);
	            }
	            cout << endl << endl << endl;
	            break;
	        case 'D':	
	        	texto =  "Ingrese el nombre del nuevo producto: ";
	        	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	        	cin.ignore();
			    getline(cin, nuevoProducto.nombre); cout << endl;
			    
			    texto =  "Ingrese el precio del nuevo producto: ";
			    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			    cin >> nuevoProducto.precio;
			    
			    cout << endl << endl << endl;
	            if (numGaseosas < MAX_ITEMS) {
	                gaseosas[numGaseosas] = nuevoProducto;
	                numGaseosas++;
	            
	            cout << endl;
	            
	            color(hConsole, 10);
				texto = "> PRODUCTO AGREGADO EXITOSAMENTE <";
				enlinear(texto, c);
	            } else {
	                
	            	(hConsole, 4);
				texto = "NO SE PUEDE AGREGAR MAS";
				enlinear(texto, c);
	            }
	            cout << endl << endl << endl;
	            break;
	        case 'E':	
	        	texto =  "Ingrese el nombre del nuevo producto: ";
	        	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	        	cin.ignore();
			    getline(cin, nuevoProducto.nombre); cout << endl;
			    
			    texto =  "Ingrese el precio del nuevo producto: ";
			    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			    cin >> nuevoProducto.precio;
			    
			    cout << endl << endl << endl;
	            if (numAguas < MAX_ITEMS) {
	                aguas[numAguas] = nuevoProducto;
	                numAguas++;
	            
	            cout << endl;
	            
	            color(hConsole, 10);
				texto = "> PRODUCTO AGREGADO EXITOSAMENTE <";
				enlinear(texto, c);
	            } else {
	                
	            	(hConsole, 4);
				texto = "NO SE PUEDE AGREGAR MAS";
				enlinear(texto, c);
	            }
	            cout << endl << endl << endl;
	            break;
	    	case 'F':
	    		break;
	        default:
	            cout << endl << endl;
				color(hConsole, 4);
				texto = "CATEGORIA NO ENCONTRADA. INTENTE DE NUEVO";	
				enlinear(texto, c);
				cout << endl << endl << endl;
	            break;
	    }
	    cout << endl << endl << endl;
	}while (categoria !='F');
	
		color(hConsole, 10);
		texto = "| EDICION DE CARTA TERMINADA |";
		enlinear(texto, c);
		color(hConsole, 7);
	
		cout << endl << endl;
	
		color(hConsole, 8);
		texto = "| VOLVIENDO AL MENU CARTA... |";
		enlinear(texto, c);
		color(hConsole, 7);
}
//FUNCION ORDENAR CARTA
void ordenarCarta() {
   char categoria;
   char c;
   string texto;
   float pantallaCompleta;
   do {
   	c='*';
   	color(hConsole, 14);
    texto = "ORDENAR CARTA";
    enlinearYEnjaular(texto, c); 
	cout << endl << endl << endl;
    
    color(hConsole, 7);
    c='=';
    texto = "Seleccione la categoría para ordenar por precio decendente:";
    centrarYSubrayar(texto, c);
    cout << endl << endl;
    
    	c='.';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "A) Hamburguesas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "B) Pizzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "C) Conos.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "D) Gaseosas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "E) Aguas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "F) Volver al menu anterior.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "-----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> categoria;
    
	cout <<endl << endl << endl;
	
	c='-';
	color(hConsole, 8);
    switch (categoria) {
        case 'A':
            for (int i = 0; i < numHamburguesas - 1; i++) {
                for (int j = 0; j < numHamburguesas - i - 1; j++) {
                    if (hamburguesas[j].precio > hamburguesas[j + 1].precio) {
                        swap(hamburguesas[j], hamburguesas[j + 1]);
                    }
                }
            }
            texto= "> Hamburguesas ordenadas satisfactoriamente <";
            enlinear(texto, c);
            break;
        case 'B':
            for (int i = 0; i < numPizzas - 1; i++) {
                for (int j = 0; j < numPizzas - i - 1; j++) {
                    if (pizzas[j].precio > pizzas[j + 1].precio) {
                        swap(pizzas[j], pizzas[j + 1]);
                    }
                }
            }
            texto= "> Pizzas ordenadas satisfactoriamente <";
            enlinear(texto, c);
            break;
        case 'C':
            for (int i = 0; i < numConos - 1; i++) {
                for (int j = 0; j < numConos - i - 1; j++) {
                    if (conos[j].precio > conos[j + 1].precio) {
                        swap(conos[j], conos[j + 1]);
                    }
                }
            }
            texto = "> Conos ordenados satisfactoriamente <";
            enlinear(texto, c);
            break;
        case 'D':
            for (int i = 0; i < numGaseosas - 1; i++) {
                for (int j = 0; j < numGaseosas - i - 1; j++) {
                    if (gaseosas[j].precio > gaseosas[j + 1].precio) {
                        swap(gaseosas[j], gaseosas[j + 1]);
                    }
                }
            }
            texto = "> Gaseosas ordenadas satisfactoriamente <";
            enlinear(texto, c);
            break;
        case 'E':
            for (int i = 0; i < numAguas - 1; i++) {
                for (int j = 0; j < numAguas - i - 1; j++) {
                    if (aguas[j].precio > aguas[j + 1].precio) {
                        swap(aguas[j], aguas[j + 1]);
                    }
                }
            }
            texto = "> Aguas ordenadas satisfactoriamente <";
            enlinear(texto, c);
            break;
        case 'F':
        	break;
        default:
        	color(hConsole, 4);
           	texto = "Categoria no encontrada. Intente de nuevo.";
            enlinear(texto, c);
            break;
    }
    espacio();
    } while (categoria != 'F');
    
    	color(hConsole, 10);
		texto = "| SE ORDENO LA CARTA SATISFACTORIAMENTE |";
		enlinear(texto, c);
		color(hConsole, 7);
	
		cout << endl << endl;
	
		color(hConsole, 8);
		texto = "| VOLVIENDO AL MENU CARTA... |";
		enlinear(texto, c);
		color(hConsole, 7);
}
//FUNCION PARA ELIMINAR PRODUCTOS DE LA CARTA
void eliminarCarta() {
    int item;
    char c;
    char categoria;
    string texto;
    float porcentajePantalla;
    do {
    c='*';
   	color(hConsole, 14);
    texto = "ELIMINAR PRODUCTO";
    enlinearYEnjaular(texto, c); 
	cout << endl << endl << endl;
    
	    color(hConsole, 7);
	    c='.';
	    
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "a) Hamburguesas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "b) Pizzas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "c) Conos.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "d) Gaseosas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "e) Aguas.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "f) Volver al menu anterior.";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "-----";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> categoria;
		
	cout << endl << endl << endl;
	c='=';
	porcentajePantalla = 45;
    switch (categoria) {
        case 'a':
            texto = "Seleccione el producto a eliminar:";
            centrarYSubrayar(texto, c);
            cout << endl << endl << endl;
            
            for (int i = 0; i < numHamburguesas; i++) {
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
                cout << i + 1 << ". " << hamburguesas[i].nombre << " S/. " << hamburguesas[i].precio << endl;
            }
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> item;
            item -= 1;
            
            espacio();
            c='-';
            if (item >= 0 && item < numHamburguesas) {
                for (int i = item; i < numHamburguesas - 1; i++) {
                    hamburguesas[i] = hamburguesas[i + 1];
                }
                numHamburguesas--;
                
                color(hConsole, 10);
                texto = "> PRODUCTO ELIMINADO SATISFACTORIAMENTE <";
                enlinear(texto, c);
            } else {
                color(hConsole, 4);
                texto = "PRODUCTO NO ENCONTRADA. INTENTE DE NUEVO.";
                enlinear(texto, c);
            }
            break;
        case 'b':
            texto = "Seleccione el producto a eliminar:";
            centrarYSubrayar(texto, c);
            cout << endl << endl << endl;
            
            for (int i = 0; i < numPizzas; i++) {
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
                cout << i + 1 << ". " << pizzas[i].nombre << " S/. " << pizzas[i].precio << endl;
            }
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> item;
            item -= 1;
            
            espacio();
            c='-';
            if (item >= 0 && item < numPizzas) {
                for (int i = item; i < numPizzas - 1; i++) {
                    pizzas[i] = pizzas[i + 1];
                }
                numPizzas--;
                
                color(hConsole, 10);
                texto = "> PRODUCTO ELIMINADO SATISFACTORIAMENTE <";
                enlinear(texto, c);
            } else {
                color(hConsole, 4);
                texto = "PRODUCTO NO ENCONTRADA. INTENTE DE NUEVO.";
                enlinear(texto, c);
            }
            break;
        case 'c':
        	texto = "Seleccione el producto a eliminar:";
            centrarYSubrayar(texto, c);
            cout << endl << endl << endl;
            
            for (int i = 0; i < numConos; i++) {
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
                cout << i + 1 << ". " << conos[i].nombre << " S/. " << conos[i].precio << endl;
            }
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> item;
            item -= 1;
            
            espacio();
            c='-';
            if (item >= 0 && item < numConos) {
                for (int i = item; i < numConos - 1; i++) {
                    conos[i] = conos[i + 1];
                }
                numConos--;
                
                color(hConsole, 10);
                texto = "> PRODUCTO ELIMINADO SATISFACTORIAMENTE <";
                enlinear(texto, c);
            } else {
                color(hConsole, 4);
                texto = "PRODUCTO NO ENCONTRADO. INTENTE DE NUEVO.";
                enlinear(texto, c);
            }
            break;
        case 'd':
            texto = "Seleccione el producto a eliminar:";
            centrarYSubrayar(texto, c);
            cout << endl << endl << endl;
            
            for (int i = 0; i < numGaseosas; i++) {
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
                cout << i + 1 << ". " << gaseosas[i].nombre << " S/. " << gaseosas[i].precio << endl;
            }
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> item;
            item -= 1;
            
            espacio();
            c='-';    
			       
            if (item >= 0 && item < numGaseosas) {
                for (int i = item; i < numGaseosas - 1; i++) {
                    gaseosas[i] = gaseosas[i + 1];
                }
                numGaseosas--;

                color(hConsole, 10);
                texto = "> PRODUCTO ELIMINADO SATISFACTORIAMENTE <";
                enlinear(texto, c);
            } else {
                color(hConsole, 4);
                texto = "PRODUCTO NO ENCONTRADO. INTENTE DE NUEVO.";
                enlinear(texto, c);
            }
            break;
        case 'e':
            texto = "Seleccione el producto a eliminar:";
            centrarYSubrayar(texto, c);
            cout << endl << endl << endl;
            
            for (int i = 0; i < numAguas; i++) {
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
                cout << i + 1 << ". " << aguas[i].nombre << " S/. " << aguas[i].precio << endl;
            }
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> item;
            item -= 1;
            
            espacio();
            c='-';
            
            if (item >= 0 && item < numAguas) {
                for (int i = item; i < numAguas - 1; i++) {
                    aguas[i] = aguas[i + 1];
                }
                numAguas--;
            
                color(hConsole, 10);
                texto = "> PRODUCTO ELIMINADO SATISFACTORIAMENTE <";
                enlinear(texto, c);
            } else {
                color(hConsole, 4);
                texto = "PRODUCTO NO ENCONTRADO. INTENTE DE NUEVO.";
                enlinear(texto, c);
            }
            break;
        case 'f':
        	break;
        default:
        	c='-';
        	color(hConsole, 4);
            texto = "CATEGORIA NO ENCONTRADA. INTENTE DE NUEVO.";
            enlinear(texto, c);
            break;
    }
    espacio();
    } while (categoria!='f');
    	
    	c='-';
    	
		color(hConsole, 10);
		texto = "| PRODUCTOS ELIMINADOS SATISFACTORIAMENTE |";
		enlinear(texto, c);
		color(hConsole, 7);
	
		cout << endl << endl;
	
		color(hConsole, 8);
		texto = "| VOLVIENDO AL MENU CARTA... |";
		enlinear(texto, c);
		color(hConsole, 7);    
}

