#include "funcionesdespensa.h"
#include "funcionesfinanzas.h"
#include "FUNCIONESDISENO.h"
using namespace std;

Alimentos alimento[MAX_ALIMENTOS] = {
    {"Tomates", 40, 0.2}, // 0
    {"Lechugas", 5, 1}, // 1
    {"Bolsas de harina", 20, 3.5}, // 2
    {"Carnes", 20, 9}, // 3
    {"Litros de gaseosa", 20, 4}, //4
    {"Litros de agua", 20, 2.5}, //5
    {"Queso", 10, 15}
};

void ordenarPorMasUsados(GastoAlimento arr[], int n) {
	GastoAlimento aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].cantidadUsada < arr[j].cantidadUsada) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void ordenarPorMenosUsados(GastoAlimento arr[], int n) {
    GastoAlimento aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].cantidadUsada > arr[j].cantidadUsada) {
                // Intercambiar productos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void AgregarAlimentos(){
	float c=0;
	int opcion;
	float minimoAlmacen = 0;
	int n=0;
	int aux=0;
	
	string texto;
	char s;
	float porcentajePantalla;
	porcentajePantalla = 45;
	if (minimoAlmacen <= limiteAlmacen){
		s='*';
		color(hConsole, 6);
		texto = "AGREGAR ALIMENTOS";
		enlinearYEnjaular(texto, s);
		color(hConsole, 7);
		cout << endl << endl << endl;
		
		color(hConsole, 3);
		s='=';
		texto = "Lista de alimentos para el negocio";
		centrarYSubrayar(texto, s);
		cout << endl << endl;
		color(hConsole, 7);
		
		for(int i=0; i<MAX_ALIMENTOS; i++){
			texto = " ";
            imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			cout << i+1 << ". " << alimento[i].nombre << "(" << alimento[i].cantidad << ")." << endl;
		}
		
		cout << endl << endl;
		
        while (true) {
        	color(hConsole, 7);
            texto = "-----";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> opcion;
			
			cout << endl << endl << endl;
			
            if(opcion<=MAX_ALIMENTOS && opcion>0){
            	texto = " ";
            	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla); // ajustando
	            cout << "Agregando '" << alimento[opcion-1].nombre << "'...";
				cout << endl << endl << endl;
	            while(c<=0){
	            	color(hConsole, 7);
	            	texto = " ";
            		imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
	            	cout << "Cantidad: ";
		            cin >> c;
		            
		            cout << endl << endl << endl;
		            if(c>0){
		            	alimento[opcion-1].cantidad += c;
		            	texto = " ";
            			imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
            			color(hConsole, 8);
		            	cout << "Se agregaron " << c << " '" << alimento[opcion-1].nombre << "' a la despensa.";
		            	
		            	cout << endl << endl << endl << endl;
		            	
		            	c='-';
		            	color(hConsole, 10);
		                texto = "> ALIMENTOS AGREGADOS SATISFACTORIAMENTE <";
		                enlinear(texto, c);
		                
		                cout << endl << endl;
		                
		                color(hConsole, 8);
						texto = "| VOLVIENDO AL MENU DESPENSA... |";
						enlinear(texto, c);
						color(hConsole, 7);
						
		            	break;
		            }else {
		            	color(hConsole, 4);
		            	texto = "Ingrese una cantidad valida.";
		            	centrar(texto);
		            	cout << endl << endl << endl;
					}
				}
	            break;
            } else {
            	color(hConsole, 4);
                texto = "Alimento no encontrado. Intente de nuevo. ";
                centrar(texto);
                espacio();
            }
        }
    } else {
        cout << "Limite maximo de alimentos." << endl << endl;
    }
    cout << endl;
}

void actualizarAlimentos(){
	int opcion;
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
		c='*';
		color(hConsole, 6);
		texto = "ACTUALIZAR ALIMENTOS";
		enlinearYEnjaular(texto, c);
		color(hConsole, 7);
		cout << endl << endl << endl;
		
		c='=';
		texto = "Indique el alimento a actualizar";
		centrarYSubrayar(texto, c);
		cout << endl << endl << endl;
	for(int i=0; i<MAX_ALIMENTOS; i++){
		c='-';
		texto = " ";
        imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla+1);
		cout << i+1 << ". " << alimento[i].nombre << endl;
		linea(50, c, 0);
		texto = " ";
		cout << endl << endl;
        imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
		cout << "Unidades disponibles: " << alimento[i].cantidad << endl;
		texto = " ";
        imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
		cout << "Precio unitario: S/. " << alimento[i].precio << endl << endl;
	}
	cout << endl;
	do{
		color(hConsole, 7);
		texto = "Indique";
	    centrar(texto);
	    cout << endl;
		texto = "------";
		centrar(texto); 
		cout << endl;
		centrarCin(1);
		cin >> opcion;
		if(opcion > MAX_ALIMENTOS || opcion <=0){
			cout << endl << endl << endl;
			color(hConsole, 4);
			texto = "Alimento no encontrado. Intente de nuevo.";
			centrar(texto);
			cout << endl << endl << endl;
		}
	} while(opcion > MAX_ALIMENTOS || opcion <=0);
	
	cout << endl << endl << endl;
	color(hConsole, 8);
	texto = " ";
    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-4);
	cout << "Actualizando datos de '" << alimento[opcion-1].nombre << "'..." << endl << endl << endl << endl;
	
	do{
		color(hConsole, 7);
		texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
		cout << "Unidades disponibles: ";
		cin >> alimento[opcion-1].cantidad;
		if(alimento[opcion-1].cantidad<=0){
			cout << endl << endl << endl;
			color(hConsole, 4);
			texto = "Ingrese una cantidad valida.";
			centrar(texto);
			cout << endl << endl << endl;
		}
	} while(alimento[opcion-1].cantidad <= 0);
	
	cout << endl;
	do{
		color(hConsole, 7);
		texto = " ";
    	imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
		cout << "Precio unitario: S/. ";
		cin >> alimento[opcion-1].precio;
		if(alimento[opcion-1].precio<=0){
			cout << endl << endl << endl;
			color(hConsole, 4);
			texto = "Ingrese un precio valido.";
			centrar(texto);
			cout << endl << endl << endl;
		}
	} while(alimento[opcion-1].precio <= 0);
	
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> ALIMENTO ACTUALIZADO CON EXITO <";
	enlinear(texto, c);
	
	cout << endl << endl;
		                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DESPENSA... |";
	enlinear(texto, c);

}

void mostrarStock(){
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	Alimentos copia[MAX_ALIMENTOS];
	
	c='*';
	color(hConsole, 6);
	texto = "STOCK DE LOS ALIMENTOS";
	enlinearYEnjaular(texto, c);
	color(hConsole, 7);
	cout << endl << endl << endl;

	for(int i=0; i<MAX_ALIMENTOS; i++){
		copia[i] = alimento[i];
	}
	
	Alimentos mayor;
	for(int i=0; i<MAX_ALIMENTOS-1; i++){
		for(int j=0; j<MAX_ALIMENTOS-1-i; j++){
			if (copia[j].cantidad < copia[j + 1].cantidad) { 
				mayor = copia[j];
				copia[j] = copia[j+1];
				copia[j+1] = mayor;
			}
		}
	}
	cout << endl;
	color(hConsole, 8);
	texto = "(Ordenados de mayor a menor)";
	centrar(texto);
	cout << endl << endl << endl;
	
	color(hConsole, 7);
	for(int i=0; i<MAX_ALIMENTOS; i++){
		texto = " ";
        imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-1);
		cout << "(" << copia[i].cantidad << ") " << copia[i].nombre << "." << endl << endl;
	}
	
	espacio();
	c='-';	                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DESPENSA... |";
	enlinear(texto, c);
}

void mostrarMasMenosUsados(){
	
	char opcion;
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	/*
	struct GastoAlimento {
    string nombre;
    float gastos;
    float cantidadUsada;
	};	
	*/
	c='*';
	color(hConsole, 6);
	texto = "ORDENAR ALIMENTOS USADOS";
	enlinearYEnjaular(texto, c);
	cout << endl << endl << endl;
	
	color(hConsole, 14);
	int anchoJaula=25;
		int salto=2;
		linea(anchoJaula, c, 1); cout << endl;
		texto = "a) De mayor a menor";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "b) De menor a mayor";
		contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		
	do{
		color(hConsole, 7);
		c='.';
		texto = "------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		
		cout << endl << endl << endl;
		switch(opcion){
			case 'a':
				c='=';
				texto = "Ordenados de mayor a menor uso";
				centrarYSubrayar(texto, c);
				cout << endl << endl << endl;
				ordenarPorMasUsados(gastos, MAX_ALIMENTOS);
				break;
			case 'b':
				c='=';
				texto = "Ordenados de menor a mayor uso";
				centrarYSubrayar(texto, c);
				cout << endl << endl << endl;
				ordenarPorMenosUsados(gastos, MAX_ALIMENTOS);
				break;
			default:
				color(hConsole, 4);
				texto = "Opcion no valida. Intente de nuevo.";
				centrar(texto);
				cout << endl << endl << endl;
				break;
		}
	}while(opcion!='a'&& opcion!='b');
	cout << endl << endl << endl;
		for(int i=0; i<MAX_ALIMENTOS; i++){
			texto = " ";
			imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla);
			cout << i+1 << ". " << " (" << gastos[i].cantidadUsada << ")" << gastos[i].nombre << endl;
		}
	
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> ALIMENTOS USADOS ORDENADOS SATISFACTORIAMENTE <";
	enlinear(texto, c);
	
	cout << endl << endl;
		                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DESPENSA... |";
	enlinear(texto, c);
}

