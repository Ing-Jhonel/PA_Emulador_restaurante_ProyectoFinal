#ifndef FUNCIONESDISENO_H
#define FUNCIONESDISENO_H
#include <string>
#include <windows.h>
#define color SetConsoleTextAttribute

using namespace std;

extern HANDLE hConsole;

void espacio();

int anchoConsola(); //devuelve el ancho real de la pantalla en ese momento.

void imprimirEspacio(int espacios); //n representa la cantidad de espacios que se hara desde el lado izquierdo de la pantalla, hasta imprimir "n" espacios
//Es perfecto cuando queremos poner en el medio una cadena de texto o simbolos.

void centrarParaPintar(const string& text); //pone en el centro de la pantalla un texto

void centrar(const string& text);

void centrarCin(int tamanoAproxEntrada);//pone en el centro de la pantalla el "cin" (se indica cuanto aprox. sera la entrada, para que este en el centro lo mas posible

void separador(char caracter); //Genera una linea que corta el programa en dos, perfecto para separar secciones (caracter se refiere a que simbolo quiere que sea la linea, * - + /  etc )

void enjaular(string text, char caracter); //

void centrarYSubrayar(string text, char caracter); //Imrpime un texto  en el centro de la consola y lo subraya

void linea(int tamano, char caracter, int saltoDeLinea); //Generar una linea de un tamano especifico, si hay un "salto" de linea, generara entre ambos extremos de la linea un caracter mas, para generar una jaula en ese caso

void contenidoJaula(string text, int tamanoJaula, char caracter, int saltoDeLinea); // genera el contenido de una jaula

void enlinear(string text, char caracter); // ej: 		*********** text ************

void enlinearYEnjaular(string text, char caracter); //enlinea y enjaula un texto a la vez

void imprimirEnEspaciadoPorcentaje(string text, float porcentaje);
#endif
