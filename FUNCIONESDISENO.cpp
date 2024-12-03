#include "FUNCIONESDISENO.h"
#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// Funci?n para obtener el ancho de la consola

void espacio(){
	cout << endl << endl << endl << endl << endl;
}
int anchoConsola() {
    CONSOLE_SCREEN_BUFFER_INFO csbi; //declara variable de tipo CONSOLE_SCREEN_BUFFER_INFO (es una estructura definida en la libreria windows.h)
    // esta contiene info sobre el bufer de la pantalla de consola, como las dimensiones (lo que necesitamos)
    int columnas; //declara una variable "columnas" de tipo int

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //con "GetStdHandle(STD_OUTPUT_HANDLE)" obtenemos un identificador para el bufer
    //de
    // Esta funci?n obtiene informaci?n detallada sobre el b?fer de pantalla de la consola y la guarda en la estructura csbi.
    columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1; //csbi.srWindow.Right y csbi.srWindow.Left: Estas son propiedades de la estructura CONSOLE_SCREEN_BUFFER_INFO. 
	// srWindow es una estructura dentro de csbi que representa la ventana de visualizaci?n actual de la consola.
	// csbi.srWindow.Right representa la coordenada m?s a la derecha de la ventana de la consola.
	// csbi.srWindow.Left representa la coordenada m?s a la izquierda de la ventana de la consola.
	
	//ej
	
	// si la consola mide 100 caracteres, para que la pc lo sepa, entonces:
	// csbi.srWindow.Right = 99
	// csbi.srWindow.Left = 0
	// 	columnas = 99 +1 = 100, 
    return columnas;
}
// Funcion para imprimir un espacio entre el lado izquierdo de la pantalla hasta donde se indique
void imprimirEspacio(int n){
	for(int i=0; i<n; i++){
		cout << " ";
	}
}
// Funcion para centrar el texto que se pintara (titulos grandes)
void centrarParaPintar(const string& text) {
    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int tamanotexto = text.length(); //"text.lenght()" halla el tama?o del texto en caracteres. le asignamos una variable de tipo int a la anchura del texto
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
    // Imprimir el texto
    cout << text;
    
    imprimirEspacio(espaciado);
    
}
// Funcion para centrar un texto que no se pintara
void centrar(const string& text) {
    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int tamanotexto = text.length(); //"text.lenght()" halla el tama?o del texto en caracteres. le asignamos una variable de tipo int a la anchura del texto
    int espaciado = (tamanoconsola - tamanotexto) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
    // Imprimir el texto
    cout << text;
     
}
// Funcion para centrar una entrada "cin"
void centrarCin(int tamanoAproxEntrada){

    int tamanoconsola = anchoConsola(); // ya que hallamos columnas con la funcion, le asignamos una variable al retorno
    int espaciado = (tamanoconsola - tamanoAproxEntrada) / 2; // la diferencia de ambos entre 2 es la distancia para centrar un texto
    // Imprimir espacios en blanco antes del texto
    imprimirEspacio(espaciado);
}
// Funcion para generar una linea larga entre ambos extremos de la pantalla, ideal para separar secciones
void separador(char caracter){
	int tamanoconsola = anchoConsola();
	cout << endl;
	for(int i=0; i<tamanoconsola; i++){
		cout << caracter;
	}
}
// Funcion para enjaular un texto (genera un marco alrededor de el), solo una linea de texto, no varias
void enjaular(string text, char caracter){
	
	int tamanotexto = text.length(); //genera el tamaño del texto
	int anchojaula = tamanotexto+4; //el ancho de la jaula es el tamano del texto + 4 (el mas 4 es para que halla un espacio entre la pared de la jaula y el texto
	//ej:
	/*
	"Hola"
	tamanotexto = 4
	anchojaula = 4 + 4 = 8
	
	********  ---> 8 
	* Hola *
	********
	
	*/
	
	int tamanoconsola = anchoConsola(); // genera el tamaño de la consola o ventana del ejecutador
	int espaciado = (tamanoconsola - anchojaula)/2; // es el espacio del lado izquierdo del programa, hacia donde va a empezar la jaula
	/*
	
	 ---------- = 10 espaciado
	 
	|          * Hola *
	
	*/
	imprimirEspacio(espaciado); // se imprime espacio
	
	for(int i=0; i<anchojaula; i++){ //despues de imprimir el espacio, imprimimos el caracter hasta completa el ancho de la jaula
		cout << caracter;
	}
	//  |          ********          |
	cout << endl;
	//  |          ********          |	
	//  |                            |	 
	imprimirEspacio(espaciado);
	
	cout << caracter << " " << text << " " << caracter;
	//  |          ********          |
	//  |		   * Hola *			 |
	cout << endl;
	//  |          ********          |
	//  |		   * Hola *			 |
	//  |                            |
	imprimirEspacio(espaciado);
	
	for(int i=0; i<anchojaula; i++){
		cout << caracter;
	}
	//  |          ********          |
	//  |		   * Hola *			 |
	//  |          ********          |
}
// Funcion para subrayar un texto
void centrarYSubrayar(string text, char caracter){
	
	int tamanoconsola = anchoConsola(); //genera el tamano de la consola o ventana del ejecutador
	int tamanotexto = text.length(); // halla el tamano del texto
	int espaciado = (tamanoconsola - tamanotexto)/2; // resta el tamano de la consola - el texto para hallar el espaciado de la izquierda hasta el texto
	
	imprimirEspacio(espaciado); //imprime el espacio
	
	cout << text << endl; //imprime el texto y salta de linea
	
	imprimirEspacio(espaciado); //imprime el espacio
	
	for(int i=0; i<tamanotexto; i++){ //imprime el caracter hasta el el tamano del texto, abajo de este mismo
		cout << caracter;
	}
	
	/*ej
	
	espaciado = 10
	|          Hola          |
	|          ****          |
	*/

}
// Funcion para generar una linea de un tamano especifico, si hay un "salto" de linea, generara entre ambos extremos de la linea un caracter mas, para generar una jaula en ese caso
void linea(int tamano, char caracter, int saltoDeLinea){
	int tamanoconsola = anchoConsola();
	int espaciado = (tamanoconsola - tamano)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<tamano; i++){
		cout << caracter;
	}
	
	// ej:   ******************	 ; salto = 0
	// 		 *				  *  ; salto = 1
	if(saltoDeLinea>0){
		cout << endl;
		
		imprimirEspacio(espaciado);
		
		cout << caracter;
		int espaciojaula = tamano-2;
		
		imprimirEspacio(espaciojaula);
		
		cout << caracter;
	} 
}
// Funcion para generar el contenido de una jaula, esto funcion se complementa con la funcion "linea"
void contenidoJaula(string text, int tamanoJaula, char caracter, int saltoDeLinea){
	int tamanoconsola = anchoConsola(); //halla el tamano de la consola
	int espaciado = (tamanoconsola - tamanoJaula)/2; //espaciado desde la izquierda hasta el inicio de la jaula
	
	// ej = espaciado 10
	// tamanoJaula = 15
	imprimirEspacio(espaciado);
	
	cout << caracter; // imprime caracter, siendo este la pared de ese contenido de Jaula
	
	// 	|          *
	
	int tamanotexto = text.length(); //halla el tamano del texto
	int entrelineas = tamanoJaula-2-tamanotexto; //genera la suma de las 2 entrelineas
	int entrelinea1 = (tamanoJaula-2-tamanotexto)/2; //genera la primer entrelinea
	int entrelinea2 = entrelineas - entrelinea1; // genera la segunda entrelinea, siendo esta la que queda de espacio
	
	// hola = 4
	//ej: entrelineas = 15-2-4 = 9 
	// ej: entrelinea1 = 4.5 = 4
	// ej = entrelinea2 = 9-4  = 5
	imprimirEspacio(entrelinea1); // imprime la primera entrelinea
	
	cout << text;

	imprimirEspacio(entrelinea2);
	
	cout << caracter;
	
	imprimirEspacio(espaciado);

//  |          *    Hola     *          |

	if(saltoDeLinea>0){
		for(int i=0; i<saltoDeLinea; i++){
			cout << endl;
			
			imprimirEspacio(espaciado);
			
			cout << caracter;
			
			int espaciojaula= tamanoJaula-2;
			
			imprimirEspacio(espaciojaula);
			
			cout << caracter;
		}
		// |          *    Hola     *          | ; salto = 0
		// |          *			    *          | ; salto = 1
	}
	
}
// Funcion para enlinear un texto en el centro de la pantalla
void enlinear(string text, char caracter){
	int tamanoconsola = anchoConsola();
	int tamanotexto = text.length();
	int tamanolinea = (tamanoconsola - tamanotexto)/2;
	
	for(int i=0; i<tamanolinea; i++){
		cout << caracter;
	}
	cout << " " << text << " ";
	
	for(int i=1; i<tamanolinea; i++){
		cout << caracter;
	}
	
	// ej: 		*********** text ************
}

void enlinearYEnjaular(string text, char caracter){
	int tamanoconsola = anchoConsola();
	int tamanotexto = text.length();
	int espaciado = (tamanoconsola - tamanotexto-3)/2;
	int tamanoJaula = tamanotexto + 3;
	int tamanoLinea = (tamanoconsola - tamanoJaula)/2;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<tamanoJaula; i++){
		cout << caracter;
	}
	
	cout << caracter <<endl;
	
	for(int i=0; i<tamanoLinea+1; i++){
		cout << caracter;
	}
	
	cout << " " << text << " ";
	
	for(int i=0; i<tamanoLinea; i++){
		cout << caracter;
	}
	
	cout << endl;
	
	imprimirEspacio(espaciado);
	
	for(int i=0; i<tamanoJaula; i++){
		cout << caracter;
	}
	cout << caracter;
}

void imprimirEnEspaciadoPorcentaje(string text, float porcentaje){
	int tamanoconsola = anchoConsola();
	int espaciado = tamanoconsola*porcentaje/100;
	
	imprimirEspacio(espaciado);
	
	cout << text;
}

int nada();
