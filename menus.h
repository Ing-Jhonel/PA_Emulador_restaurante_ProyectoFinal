#ifndef MENUS_H
#define MENUS_H
#include <string>
using namespace std;

void menuClientes();
void menuCarta();
void menuFinanzas();

class Restaurante{
	private:
		string nombre;
		//Carta carta;
		//Finanzas finanzas;
		//Personal personal;
		//Due�o due�o;
	public:
		Restaurante(string);
		void mostrarInfoEmpresa();
};

class Personas{
	protected:
		string nombre, telefono, correo;
		int DNI, edad;
	public:
		Personas(string, string, string, int, int);
		void mostrarDatos();
		
};


#endif
