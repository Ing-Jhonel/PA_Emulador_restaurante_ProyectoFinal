#include "funcionesfinanzas.h"
#include "funcionescarta.h"
#include "funcionesdespensa.h"
#include <iostream>
#include <string>
#include "FUNCIONESDISENO.h"
using namespace std;

float montoFinalGanancias = 0;
float montoFinalGastos = 0;
int ordenesTotales=0;

const float costeHamburguesas = alimento[0].precio*CTH + alimento[1].precio*CLH + alimento[2].precio*CBH + alimento[3].precio*CCH + alimento[6].precio*CQH;
const float costePizzas = alimento[0].precio*CTP + alimento[2].precio*CBP + alimento[3].precio*CCP + alimento[6].precio*CQP;
const float costeConos = alimento[0].precio*CTC + alimento[1].precio*CLC + alimento[2].precio*CBC + alimento[3].precio*CCC + alimento[6].precio*CQC;
const float costeGaseosas = alimento[4].precio*CG;
const float costeAguas = alimento[5].precio*CA;

const int totalComidas = numHamburguesas + numPizzas + numConos + numGaseosas + numAguas;

float aguasTotalUsadas = 0;
float gaseosasTotalUsadas = 0;
float quesosTotalUsados = 0;
float carnesTotalUsadas = 0;
float bolsasharinaTotalUsadas = 0;
float lechugasTotalUsadas = 0;
float tomatesTotalUsados = 0;
GastoAlimento gastos[MAX_ALIMENTOS] = {
                    {"Tomate", tomatesTotalUsados * alimento[0].precio},
                    {"Lechugas", lechugasTotalUsadas * alimento[1].precio},
                    {"Bolsas de harina", bolsasharinaTotalUsadas * alimento[2].precio},
                    {"Carnes", carnesTotalUsadas * alimento[3].precio},
                    {"Litros de gaseosa", gaseosasTotalUsadas * alimento[4].precio},
                    {"Litros de agua", aguasTotalUsadas * alimento[5].precio},
                    {"Queso", quesosTotalUsados * alimento[6].precio}
                };
// Tomate: 0.2   lechuga: 0.3  bolsaharina: 1.5   carnes: 2   				//Costo
// litrosgaseosa: 3   litrosagua: 2.5														
//Hamburguesa = 1 tomate, 0.25 lechuga, 0.5 bolsaharina, 0.15 carnes; 		// 1*0.2 + 0.25*0.3 + 0.5
//Pizzas = 4 tomate, 2 bolsaharina, 2 carnes
//Conos = 2 tomate, 0.5 lechuca, 1 bolsaharina 1 carnes
//Gaseosas = 0.5 litrogaseosa
//Agua = 0.5 litroagua
	//{"Tomates" // 0  				= 40u en despensa
   // {"Lechugas" // 1|				= 5u en despoensa
   // {"Bolsas de harina", // 2		= 20u en despensa
   // {"Carnes" // 3				= 20u en despensa
   // {"Litros de gaseosa" //4		= 20u en despensa
    //{"Litros de agua" //5			= 20u en despensa
int numFactura = 0;// iniciamos variable con 0
int ordenesPorFactura[MAX_FACTURAS] = {0}; // iniciamos arreglo con 0
paraOrdenarVentas ordenarVentas[MAX_ITEMS];
ventasDeComidas ventasComidas[MAX_FACTURAS];
Ordenes orden[MAX_FACTURAS][MAX_FACTURAS];//definimos matriz de orden "MAX_FACTURAS" 
//filas: N* factura
//columna: N* orden
float montoDeFactura[MAX_FACTURAS] = {0};// arreglo que contiene todas los montos de cada factura iniciamos arreglo con 0
int copiaParaOrdenarVentas[MAX_ITEMS];
 //Funcion para que cada orden adquiere nombre y producto, ademas se suma por cada orden el precio de la orden + monto.
void ordenRegistro(Ordenes orden[], Producto producto[],  int item, int c, int cantidad){
// FACTURA = conjutno de ordeenes	
	orden[c].nombre = producto[item - 1].nombre;
    orden[c].cantidad = cantidad;
    orden[c].monto = producto[item - 1].precio * cantidad;
}
//el & es para que la funcion modifique el valor de una variable
void montoPorFactura(Ordenes orden[], int n, float& montoDeFactura) {
    for (int i = 0; i < n; i++) {
        montoDeFactura += orden[i].monto;
    }
}
void ordenarGastos(GastoAlimento arr[], int n) {
	GastoAlimento aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].gastos < arr[j].gastos) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void ordenarGanancias(Producto arr[], int n) {
    Producto aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].precio < arr[j].precio) {
                // Intercambiar productos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}         	
void ordenarPorMasVendidos(paraOrdenarVentas arr[], int n) {
	paraOrdenarVentas aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].total < arr[j].total) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void ordenarPorMenosVendidos(paraOrdenarVentas arr[], int n) {
    paraOrdenarVentas aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].total > arr[j].total) {
                // Intercambiar productos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void gastosTotales(){
	montoFinalGastos=0;
	for(int i=0; i<MAX_ALIMENTOS; i++){
		montoFinalGastos += gastos[i].cantidadUsada*alimento[i].precio;
	}
}
void generarRIG(paraOrdenarVentas arr[], ventasDeComidas arr2[], int n){
	
	for (int i = 0; i < n; i++) {
    	arr[i].RIG = 0; // Inicializar RIG
    // Inicializar otros campos si es necesario
	}
	
	for(int i=0; i<n; i++){
		// arr[i].coste != 0      <----
		arr[i].RIG = arr[i].total / arr[i].coste*arr2[i].cantidad;
	}
}
void ordenarPorRIG(paraOrdenarVentas arr[], int n){
	paraOrdenarVentas aux;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i].RIG < arr[j].RIG) {
                // Intercambiar gastos
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void gananciasTotales(Ordenes orden[][MAX_FACTURAS], float& montoFinalGanancias) {
	montoFinalGanancias = 0;
    for (int i = 0; i <MAX_FACTURAS; i++) {
        for (int j = 0; j <MAX_FACTURAS; j++) {
            montoFinalGanancias += orden[i][j].monto;
        }
    }
}
void agregarMontoArreglo(){
    int idx = 0; // Índice para recorrer el arreglo ordenarVentas

    // Agregar hamburguesas
    for(int i = 0; i < numHamburguesas; i++){
        ordenarVentas[idx].nombre = hamburguesas[i].nombre;
        ordenarVentas[idx].total = hamburguesas[i].cantidadVendida * hamburguesas[i].precio;
        ordenarVentas[idx].coste = costeHamburguesas;
        idx++;
    }

    // Agregar pizzas
    for(int i = 0; i < numPizzas; i++){
        ordenarVentas[idx].nombre = pizzas[i].nombre;
        ordenarVentas[idx].total = pizzas[i].cantidadVendida * pizzas[i].precio;
        ordenarVentas[idx].coste = costePizzas;
        idx++;
    }

    // Agregar conos
    for(int i = 0; i < numConos; i++){
        ordenarVentas[idx].nombre = conos[i].nombre;
        ordenarVentas[idx].total = conos[i].cantidadVendida * conos[i].precio;
        ordenarVentas[idx].coste = costeConos;
        idx++;
    }

    // Agregar gaseosas
    for(int i = 0; i < numGaseosas; i++){
        ordenarVentas[idx].nombre = gaseosas[i].nombre;
        ordenarVentas[idx].total = gaseosas[i].cantidadVendida * gaseosas[i].precio;
        ordenarVentas[idx].coste = costeGaseosas;
        idx++;
    }

    // Agregar aguas
    for(int i = 0; i < numAguas; i++){
        ordenarVentas[idx].nombre = aguas[i].nombre;
        ordenarVentas[idx].total = aguas[i].cantidadVendida * aguas[i].precio;
        ordenarVentas[idx].coste = costeAguas;
        idx++;
    }
}


void registrarVenta(){
	int categoria;
	int item;
	string nombre;
	int cantidad;
	string respuesta;
	int ordenesTotales=0; //para dar el orden a cada Orden
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45-2;
	
	c='*';
	color(hConsole, 2);
	texto = "REGISTRE ORDENES";
	enlinearYEnjaular(texto, c);
	cout << endl << endl << endl;
	
	do{ // MENU INTERFAZ
		color(hConsole, 7);
		c='=';
		cout << endl;
		color(hConsole, 6);
		texto = "Elija la categoria.";
		centrarYSubrayar(texto, c);
		cout << endl << endl << endl;
		color(hConsole, 7);
		
		c='.';
		int anchoJaula=50;
		int salto=1;
		linea(anchoJaula, c, salto); cout << endl;
		texto = "1. Hamburguesas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "2. Pizzas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "3. Conos";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "4. Gaseosas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "5. Aguas";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "6. Terminar orden";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		linea(anchoJaula, c, 0); cout << endl;
		texto = "-------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> categoria;
		
		bool continuar = false; //si es que no cumple una condicion, no podra continuar agregando en la orden
		bool suficiente = true;
		
		cout << endl << endl << endl;
		
	    switch (categoria) {
	        case 1:
	        	do{
	        		color(hConsole, 7);
	        		c='-';
	        		texto = "Seleccione la hamburguesa: ";
	        		centrarYSubrayar(texto, c);
	        		cout << endl << endl;
	        		
		            for (int i = 0; i < numHamburguesas; i++) {
		            	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-3);
		                cout << i + 1 << ". " << hamburguesas[i].nombre << "------> S/. " << hamburguesas[i].precio << endl;
		            }
		            cout << endl << endl;
		            texto = "-------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> item;
		            
					cout << endl << endl << endl;
					
			        if(0<item && item<=numHamburguesas){
			        	
			            texto = "Cantidad: ";
			            centrar(texto);
						cin >> cantidad;
						
						if(alimento[0].cantidad>=CTH*cantidad && alimento[1].cantidad>=CLH*cantidad && alimento[2].cantidad>=CBH*cantidad && alimento[3].cantidad>=CCH*cantidad && alimento[6].cantidad >= CQH*cantidad){ // ingredientes para cocinar una hamburguesa
			            	ordenRegistro(orden[numFactura], hamburguesas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
							ordenesTotales++;
							ordenesPorFactura[numFactura]++;
							continuar = true;
							//restando ingredientes usados
							gastos[0].cantidadUsada += CTH*cantidad;
							gastos[1].cantidadUsada += CLH*cantidad;
							gastos[2].cantidadUsada += CBH*cantidad;
							gastos[3].cantidadUsada += CCH*cantidad;
							gastos[6].cantidadUsada += CQH*cantidad;
							
							alimento[0].cantidad -= CTH*cantidad; // tomate
							alimento[1].cantidad -= CLH*cantidad; // lechuga
							alimento[2].cantidad -= CBH*cantidad; //harina
							alimento[3].cantidad -= CCH*cantidad; //carnes
							alimento[6].cantidad -= CQH*cantidad; // queso
							
							hamburguesas[item-1].cantidadVendida += cantidad;
							
						} else {
							suficiente = false;
							continuar = false;
						}
					} else {
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl << endl;
					}
				} while(item>numHamburguesas || item<=0);
				break;
	        case 2:
	        	do{
	        		color(hConsole, 7);
		            c='-';
	        		texto = "Seleccione la pizza: ";
	        		centrarYSubrayar(texto, c);
	        		cout << endl << endl;
	        		
		            for (int i = 0; i < numPizzas; i++) {
		            	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-3);
		                cout << i + 1 << ". " << pizzas[i].nombre << "------> S/. " << pizzas[i].precio << endl;
		            }
		            cout << endl << endl;
		            texto = "-------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> item;
		            
					cout << endl << endl << endl;
			        
					if(0<item && item<=numPizzas){
			        	
			            texto = "Cantidad: ";
			            centrar(texto);
						cin >> cantidad;
						
						if(alimento[0].cantidad>=CTP*cantidad &&  alimento[2].cantidad>=CBP*cantidad && alimento[3].cantidad>=CCP*cantidad && alimento[6].cantidad >= CQP*cantidad){ // ingredientes para cocinar una hamburguesa
			            	ordenRegistro(orden[numFactura], pizzas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
							ordenesTotales++;
							ordenesPorFactura[numFactura]++;
							continuar = true;
							//restando ingredientes usados
							gastos[0].cantidadUsada += CTP*cantidad;
							gastos[2].cantidadUsada += CBP*cantidad;
							gastos[3].cantidadUsada += CCP*cantidad;
							gastos[6].cantidadUsada += CQP*cantidad;
							 
							alimento[0].cantidad -= CTP*cantidad;
							alimento[2].cantidad -= CBP*cantidad;
							alimento[3].cantidad -= CCP*cantidad;
							alimento[6].cantidad -= CQP*cantidad;
							
							pizzas[item-1].cantidadVendida += cantidad;
							
						} else {
							suficiente = false;
							continuar = false;
						}
					} else {
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl << endl;
					}
				} while(item>numPizzas || item<=0);
	            break;  
	        case 3:
	        	do{
		            color(hConsole, 7);
		            c='-';
	        		texto = "Seleccione el cono: ";
	        		centrarYSubrayar(texto, c);
	        		cout << endl << endl;
	        		
		            for (int i = 0; i < numConos; i++) {
		            	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-3);
		                cout << i + 1 << ". " << conos[i].nombre << " ------> S/. " << conos[i].precio << endl;
		            }
		            
		            cout << endl << endl;
		            texto = "-------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> item;
					cout << endl << endl << endl;
					
				    if(0<item && item<=numConos){
				    	
			            texto = "Cantidad: ";
			            centrar(texto);
						cin >> cantidad;
						
						if(alimento[0].cantidad>=CTC*cantidad && alimento[1].cantidad>=CLC*cantidad && alimento[2].cantidad>=CBC*cantidad && alimento[3].cantidad>=CCC*cantidad && alimento[6].cantidad >= CQC*cantidad){ // ingredientes para cocinar una hamburguesa
			            	ordenRegistro(orden[numFactura], conos, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
							ordenesTotales++;
							ordenesPorFactura[numFactura]++;
							continuar = true;
							//restando ingredientes usados
							gastos[0].cantidadUsada += CTC*cantidad;
							gastos[1].cantidadUsada += CLC*cantidad;
							gastos[2].cantidadUsada += CBC*cantidad;
							gastos[3].cantidadUsada += CCC*cantidad;
							gastos[6].cantidadUsada += CQC*cantidad;
							
							alimento[0].cantidad -= CTC*cantidad; // tomate
							alimento[1].cantidad -= CLC*cantidad; // lechuga
							alimento[2].cantidad -= CBC*cantidad; //harina
							alimento[3].cantidad -= CCC*cantidad; //carnes
							alimento[6].cantidad -= CQC*cantidad; // queso
							
							conos[item-1].cantidadVendida += cantidad;	
						} else {
							suficiente = false;
							continuar = false;
						}
					} else {
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl << endl;
					}
				} while(item>numConos || item<=0);
	            break;
	        case 4:
	        	do{
		            color(hConsole, 7);
		            c='-';
	        		texto = "Seleccione la gaseosa: ";
	        		centrarYSubrayar(texto, c);
	        		cout << endl << endl;
	        		
		            for (int i = 0; i < numGaseosas; i++) {
		            	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-3);
		                cout << i + 1 << ". " << gaseosas[i].nombre << "-------> S/. " << gaseosas[i].precio << endl;
		            }
		            
		            cout << endl << endl;
		            texto = "-------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> item;
					cout << endl << endl << endl;
		            if(0<item && item<=numGaseosas){
		            	
			            texto = "Cantidad: ";
			            centrar(texto);
						cin >> cantidad;
						
						if(alimento[4].cantidad>=CG*cantidad){ // ingredientes para cocinar una hamburguesa
			            	ordenRegistro(orden[numFactura], gaseosas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
							ordenesTotales++;
							ordenesPorFactura[numFactura]++;
							continuar = true;
							//restando ingredientes usados
							gastos[4].cantidadUsada += CG*cantidad;
							
							alimento[4].cantidad -= CG*cantidad;
							
							gaseosas[item-1].cantidadVendida += cantidad;
							
						} else {
							suficiente = false;
							continuar = false;
						}
					} else {
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl << endl;
					}
				} while(item>numGaseosas || item<=0);
	            break;
	        case 5:
	        	do{
		            color(hConsole, 7);
		            c='-';
	        		texto = "Seleccione el agua: ";
	        		centrarYSubrayar(texto, c);
	        		cout << endl << endl;
	        		
		            for (int i = 0; i < numAguas; i++) {
		            	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-3);
		                cout << i + 1 << ". " << aguas[i].nombre << "------> S/. " << aguas[i].precio << endl;
		            }
		            
		            cout << endl << endl;
		            texto = "-------";
					centrar(texto); cout << endl;
					centrarCin(1);
					cin >> item;
					cout << endl << endl << endl;
					
				    if(0<item && item<=numAguas){
				    	
			            texto = "Cantidad: ";
			            centrar(texto);
						cin >> cantidad;
						
						if(alimento[5].cantidad>=CA*cantidad){ // ingredientes para cocinar una hamburguesa
			            	ordenRegistro(orden[numFactura], aguas, item, ordenesTotales, cantidad); // funcion para generar nombre y el monto de cada orden, asi poder presentarlo en la factura
							ordenesTotales++;
							ordenesPorFactura[numFactura]++;
							continuar = true;
							//restando ingredientes usados
							gastos[5].cantidadUsada += CA*cantidad;
							
							alimento[5].cantidad -= CA*cantidad;
							
							aguas[item-1].cantidadVendida += cantidad;
							
						} else {
							suficiente = false;
							continuar = false;
						}
					} else {
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl << endl;
					}
				} while(item>numAguas || item<=0);
	            break;
	        case 6:
	        	break;
	        default:
	            color(hConsole, 4);
				texto = "Categoria no encontrada. Intente de nuevo.";
				centrar(texto);
				cout << endl << endl << endl << endl;
	            break;
	    }
	    cout << endl;
	    if(!suficiente){
	    	cout << endl << endl << endl;
	    	c='-';
	    	color(hConsole, 4);
	    	texto = "No hay suficientes ingredientes.";
	    	enlinear(texto, c);
	    	cout << endl << endl << endl;
	    	color(hConsole, 7);
		}
	    if(continuar){
	    	cout << endl << endl << endl;
	    	color(hConsole, 8);
	    	texto = "¿Va a agregar algo mas a la orden?(si/no)";
	    	centrar(texto);
	    	color(hConsole, 7);
	    	cout << endl << endl;
		    texto = "-------";
			centrar(texto); cout << endl;
			centrarCin(2);
			cin >> respuesta;
			espacio();
		}
	} while(respuesta!= "no" &&categoria!=6);
	
	color(hConsole, 8);
	texto = "G e n e r a n d o   f a c t u r a . . .";
	centrar(texto);
	cout <<endl << endl << endl;
	
	color(hConsole, 7);
	
	c= '-';
	separador(c);
	c= '$';
	separador(c);
   texto = "F  A  C  T  U  R  A";
   centrar(texto);
   c= '$';
	separador(c);
   cout << endl << endl << endl;
   
   c='=';
   texto = "Productos en la orden:";
   centrarYSubrayar(texto, c);
   cout << endl << endl << endl;
   
   int j=0;
   for(int i=0; i<ordenesPorFactura[numFactura]; i++){
   		texto = " ";
        imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
   		cout << j+1 << ". " << "(" << orden[numFactura][i].cantidad << ") " << orden[numFactura][i].nombre << "--> S/. " << orden[numFactura][i].monto << endl;
   		j++;
   }
   
   montoPorFactura(orden[numFactura], ordenesPorFactura[numFactura], montoDeFactura[numFactura]);
   
   cout << endl << endl;
   c='-';
   separador(c);
   texto= "Total a pagar --> S/. "; centrar(texto); cout << montoDeFactura[numFactura];
   separador(c);
   c= '$';
	separador(c);
	c= '-';
	separador(c);
   numFactura++;
   cout << endl << endl;
   texto = " ";
    imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	system("pause");
	
	espacio();
	
	c='-';               
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DEL AREA DE FINANZAS... |";
	enlinear(texto, c);
}
void mostrarOrdenes(){
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	c='*';
	color(hConsole, 2);
	texto = "MOSTRAR FACTURAS REGISTRADAS";
	enlinearYEnjaular(texto, c);
	color(hConsole, 7);
	
	
	if(numFactura>0){
		for(int i=0; i<numFactura; i++){

			c='-';
			separador(c);
			espacio();
			texto = " ";
			imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla+2);
			cout << i+1 << ". FACTURA" << endl;
			c='=';
			linea(15, c, 0); cout << endl << endl;
			
			
			c='-';
			texto = ">> Productos <<";
			centrarYSubrayar(texto, c);
			cout << endl << endl;
			
			for(int j=0; j<ordenesPorFactura[i]; j++){
				texto = " ";
				imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-6);
				cout << "(" << orden[i][j].cantidad << ") " << orden[i][j].nombre << "_____S/. " << orden[i][j].monto << endl;
			}
			cout << endl << endl;
			c='.';
			separador(c); cout << endl;
			centrarCin(20); cout << "Monto final----> S/. " << montoDeFactura[i];
			separador(c); 
		}
	} else{
		espacio();
		texto = "NO HAY FACTURAS REGISTRADAS";
		color(hConsole, 4);
		centrar(texto);
	}
	
	espacio();
	
	c='-';               
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DEL AREA DE FINANZAS... |";
	enlinear(texto, c);
}
void gastosGanancias(){
	gastosTotales();
	montoFinalGanancias=0;
	cout << endl;
	char respuesta;
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	c='*';
	color(hConsole, 2);
	texto = "GASTOS Y GANANCIAS";
	enlinearYEnjaular(texto, c);
	color(hConsole, 7);
	
	cout << endl << endl << endl;
	
	c='=';
	texto = "¿Que quieres ver?";
	centrarYSubrayar(texto, c);
	cout << endl << endl << endl;
	
	c='.';
	color(hConsole, 14);
	int anchoJaula=25;
		int salto=2;
		linea(anchoJaula, c, 1); cout << endl;
		texto = "-) Gastos";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "+) Ganancias";
		contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
		linea(anchoJaula, c, 0);

		color(hConsole, 7);
		do{
			color(hConsole, 7);
			cout << endl << endl;
			texto = "------";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> respuesta;
			
			cout << endl << endl << endl;
			
			switch(respuesta){
				case '-':
					c='=';
					texto = "Gastos consumidos hasta el momento (mayor a menor)";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl << endl;
					
	                ordenarGastos(gastos, MAX_ALIMENTOS);
	                
	                for(int i=0; i<MAX_ALIMENTOS; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-7);
	                	cout << "S/. " << -gastos[i].cantidadUsada*alimento[i].precio << "______"<< gastos[i].nombre << " (" << gastos[i].cantidadUsada << ")"<<endl;
					}
					cout << endl << endl << endl;
					texto = " ";
					imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
					cout << "Gastos totales: S/." << montoFinalGastos << endl;
	 				break;
				case '+':
					c='=';
					texto = "Ganancias por categoria";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl << endl;
					
					c='-';
					texto = "HAMBURGUESAS";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl;
					
	                for(int i=0; i<numHamburguesas; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	                	cout <<"S/. " << hamburguesas[i].cantidadVendida*hamburguesas[i].precio << "_______" << hamburguesas[i].nombre << endl;
					}
					
					cout << endl << endl << endl;
					
					c='-';
					texto = "PIZZAS";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl;
					
					for(int i=0; i<numPizzas; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	                	cout <<"S/. " << pizzas[i].cantidadVendida*pizzas[i].precio << "_______" << pizzas[i].nombre << endl;
					}
					
					cout << endl << endl << endl;
					
					c='-';
					texto = "CONOS";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl;
					
	                for(int i=0; i<numConos; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	                	cout <<"S/. " << conos[i].cantidadVendida*conos[i].precio << "_______" << conos[i].nombre << endl;
					}
					
					cout << endl << endl << endl;

					c='-';
					texto = "GASEOSAS";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl;
					
	                for(int i=0; i<numGaseosas; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	                	cout <<"S/. " << gaseosas[i].cantidadVendida*gaseosas[i].precio << "_______" << gaseosas[i].nombre << endl;
					}
					
					cout << endl << endl << endl;

					c='-';
					texto = "AGUAS";
					centrarYSubrayar(texto, c);
					
					cout << endl << endl;
					
	                for(int i=0; i<numAguas; i++){
	                	texto = " ";
						imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
	                	cout <<"S/. " << aguas[i].cantidadVendida*aguas[i].precio << "_______" << aguas[i].nombre << endl;
					}
					
					cout << endl << endl << endl;
					
					gananciasTotales(orden, montoFinalGanancias);
					texto = " ";
					imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-5);
					cout << "Ganancias totales: S/." << montoFinalGanancias << endl;
					break;
					default:
						cout << endl << endl;
						color(hConsole, 4);
						texto = "Opcion no valida. Intente de nuevo.";
						centrar(texto);
						cout << endl << endl << endl;
					break;
			}
		}while(respuesta!='+' && respuesta != '-');
	
	espacio();
	
	c='-';                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DEL AREA DE FINANZAS... |";
	enlinear(texto, c);
}
void ordenarMasVendido(){
	cout << endl;
	char opcion;
	agregarMontoArreglo();
	
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	c='*';
	color(hConsole, 2);
	texto = "ORDENAR POR GANANCIAS";
	enlinearYEnjaular(texto, c);
	color(hConsole, 7);
	
	cout << endl << endl << endl;
	c='.';
	color(hConsole, 14);
	int anchoJaula=25;
		int salto=2;
		linea(anchoJaula, c, 1); cout << endl;
		texto = "a) De mayor a menor";
		contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
		texto = "b) De menor a mayor";
		contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
		linea(anchoJaula, c, 0);
		cout << endl << endl << endl;
	
	do{
		color(hConsole, 7);
		cout << endl << endl;
		texto = "------";
		centrar(texto); cout << endl;
		centrarCin(1);
		cin >> opcion;
		
		cout << endl << endl << endl;
		switch(opcion){
			case 'a':
				c='=';
				texto = "Ordenado de mayor a menor ganancias";
				centrarYSubrayar(texto, c);
				ordenarPorMasVendidos(ordenarVentas, totalComidas);
				break;
			case 'b':
				c='=';
				texto = "Ordenado de menor a mayor ganancias";
				centrarYSubrayar(texto, c);
				ordenarPorMenosVendidos(ordenarVentas, totalComidas);
				break;
			default:
				cout << endl << endl << endl;
				color(hConsole, 4);
				texto = "Opcion no valida. Intente de nuevo.";
				centrar(texto);
				cout << endl << endl << endl;
				break;
		}
	}while(opcion!='a'&& opcion!='b');
	
	cout << endl << endl << endl;
	
		for(int i=0; i<totalComidas; i++){
			texto = " ";
			imprimirEnEspaciadoPorcentaje(texto, porcentajePantalla-7);
			ordenarVentas[i].RIG = ordenarVentas[i].total / ordenarVentas[i].coste;
			cout << "S/. " << ordenarVentas[i].total << "__________" << ordenarVentas[i].nombre << endl;
		}
		
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> PLATOS DE COMIDA ORDENADOS SATISFACTORIAMENTE <";
	enlinear(texto, c);
	
	cout << endl << endl;
		                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DEL AREA DE FINANZAS... |";
	enlinear(texto, c);
}
void estadisticasGenerales(){
	gastosTotales();
	gananciasTotales(orden, montoFinalGanancias);
	generarRIG(ordenarVentas, ventasComidas, totalComidas);
	ordenarPorRIG(ordenarVentas, totalComidas);
	cout << endl;
	string contrasenaJhonel="2024-119026";
	string contrasenaAlex="2024-119042";
	string contrasenaDante="2024-119039";
	string contrasena;
	char opcion;
	
	int aux;
	string texto;
	char c;
	float porcentajePantalla;
	porcentajePantalla = 45;
	
	c='*';
	color(hConsole, 2);
	texto = "ESTADISTICAS GENERALES";
	enlinearYEnjaular(texto, c);
	color(hConsole, 7);
	
	cout << endl << endl << endl;
	c='.';
	texto = "INDIQUE LA CONTRASEÑA";
	enjaular(texto, c);
	
	color(hConsole, 7);
	cout << endl << endl;
	texto = "--------------";
	centrar(texto); cout << endl;
	centrarCin(10);
	cin >> contrasena;
	
	float gananciaNeta = montoFinalGanancias - montoFinalGastos;
	float margenGananciaNeta = (gananciaNeta/montoFinalGanancias)*100;
	float ROI = (gananciaNeta/montoFinalGastos)*100;
	float RIG = (montoFinalGanancias/montoFinalGastos);
	float RIGcomidas;
	
	espacio();
	
	if(contrasena==contrasenaJhonel || contrasena==contrasenaAlex || contrasena==contrasenaDante ){
		if(contrasena==contrasenaJhonel){
			texto = "|  ¡Bienvenido Ingeniero Jhonel, revise como va su negocio!  |";
		} else if(contrasena==contrasenaAlex){
			texto = "|  ¡Bienvenido Ingeniero Alex, revise como va su negocio!  |";
		} else {
			texto = "|  ¡Bienvenido Ingeniero Dante, revise como va su negocio!  |";
		}
		
		color(hConsole, 241);
		c= '-';
		separador(c); cout << endl;
		enlinear(texto, c);
		separador(c);
		color(hConsole, 7);	
		
		do{
			cout << endl << endl << endl;
			
			c='$';
			texto = "Indique que estadistica quiere ver";
			enjaular(texto, c);
			
			cout << endl << endl << endl;
			
			c='.';
			color(hConsole, 14);
			int anchoJaula=45;
			int salto=2;
			linea(anchoJaula, c, 1); cout << endl;
			texto = "a) Ingresos brutos";
			contenidoJaula(texto, anchoJaula, c, salto); cout << endl;
			texto = "b) Egresos brutos";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "c) Ingresos netos";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "d) Ticket promedio de factura";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "e) Margen de Ganancia Neta";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "f) ROI (Retorno sobre la inversion)";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "g) RIG (Ratio de Ingresos sobre Gastos)";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "h) Ver todas las metricas juntas";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			texto = "i) Salir al menu de finanzas";
			contenidoJaula(texto, anchoJaula, c, 1); cout << endl;
			linea(anchoJaula, c, 0);
			
			color(hConsole, 7);
			cout << endl << endl;
			texto = "------";
			centrar(texto); cout << endl;
			centrarCin(1);
			cin >> opcion;
			
			cout << endl << endl << endl;
			
			switch(opcion){
				case 'a':
					c='*';
					texto = "Ingresos brutos (totales) del negocio";
					centrarYSubrayar(texto, c);
					cout << endl << endl << endl;
					
					centrarCin(10);
					cout << "--> " << montoFinalGanancias << endl;
					
					break;
				case 'b':
					
					c='*';
					texto = "Egresos brutos (totales) del negocio";
					centrarYSubrayar(texto, c);
					cout << endl << endl << endl;
					
					centrarCin(10);
					cout << "--> " << montoFinalGastos << endl;

					break;
				case 'c':
					
					c='=';
					texto = "Ingresos netos del negocio";
					centrarYSubrayar(texto, c);
					cout << endl << endl << endl;
					
					centrarCin(20);
					cout << "Ingresos totales --> " << montoFinalGanancias << endl;
					centrarCin(20);
					cout << "Egresos totales ---> " << montoFinalGastos << endl << endl;
					centrarCin(20);
					cout << "Ingresos netos ----> " << gananciaNeta << endl;
					
					break;
				case 'd':
					if(numFactura>0){
						c='=';
						texto = "Ticket promedio de factura";
						centrarYSubrayar(texto, c);
						cout << endl << endl << endl;
						
						centrarCin(10);
						cout << "--> " << montoFinalGanancias/numFactura << endl;
					
					}else{
						color(hConsole, 4);
						texto = "No hay facturas por analizar.";
						centrar(texto);
						color(hConsole, 4);
					}
					break;
				case 'e':
						c='=';
						texto = "Margen de ganancia neta del negocio es:";
						centrarYSubrayar(texto, c);
						cout << endl << endl << endl;
						
						centrarCin(10);
						cout << "--> " << margenGananciaNeta << "%" << endl;
						
					break;
				case 'f':
					
					c='=';
						texto = "El ROI de su negocio es";
						centrarYSubrayar(texto, c);
						cout << endl << endl << endl;
						
						centrarCin(10);
						cout << "--> " << ROI << "%";
						cout << endl << endl << endl;
						
						centrarCin(90);
						cout << "Eso quiere decir que por cada S/.1 gastado, usted esta ganando " << ROI << "% adicional, osea S/. " << 1+ROI/100 << endl;
					break;
				case 'g':
					
					c='=';
						texto = "El RIG de su negocio es";
						centrarYSubrayar(texto, c);
						cout << endl << endl << endl;
						
						centrarCin(10);
						cout << "--> " << RIG;
						cout << endl << endl << endl;
						
						centrarCin(60);
						cout << "Eso quiere decir que por cada S/. 1 gastado, usted gana S/. " << RIG << endl;
						
					break;
				case 'h':
					c='=';
					 aux=40;
					centrarCin(aux);
					cout << "Ingresos brutos ----------------- S/. " << montoFinalGanancias << endl<< endl;
					centrarCin(aux);
					cout << "Egresos brutos ------------------ S/. " << montoFinalGastos << endl<< endl;
					centrarCin(aux);
					cout << "Ingresos netos ------------------ S/. " << gananciaNeta << endl<< endl;
					centrarCin(aux);
					cout << "Ticket promedio de factura ------ S/. " << montoFinalGanancias/numFactura << endl<< endl;
					centrarCin(aux);
					cout << "Margen de Ganancia Neta --------- " << margenGananciaNeta << "%" << endl<< endl;
					centrarCin(aux);
					cout << "ROI ----------------------------- " << ROI << "%" << endl<< endl;
					centrarCin(aux);
					cout << "RIG ----------------------------- S/. " << RIG << endl;
					
					break;
				case 'i':
					break;
				default:
					color(hConsole, 4);
					texto = "Opcion no valida. Intente de nuevo.";
					centrar(texto);
					cout << endl << endl << endl;
					break;
			}
		}while(opcion!='i');
	} else {
		color(hConsole, 4);
		texto = "Contraseña incorrecta. No puede ingresar, lo siento.";
		centrar(texto);
	}
	
	espacio();
	
	c='-';
	color(hConsole, 10);
	texto = "> SALIENDO DEL AREA DE ESTADISTICAS GENERALES <";
	enlinear(texto, c);
	
	cout << endl << endl;
		                
	color(hConsole, 8);
	texto = "| VOLVIENDO AL MENU DEL AREA DE FINANZAS... |";
	enlinear(texto, c);
}
