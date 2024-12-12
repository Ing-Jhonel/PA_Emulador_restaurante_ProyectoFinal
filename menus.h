#ifndef MENUS_H
#define MENUS_H
#include <string>
using namespace std;

void menuClientes();
void menuCarta();
void menuFinanzas();
void menuAdministracion();

class Restaurante{
	private:
		string nombre;
		//Carta carta;
		//Finanzas finanzas;
		//Personal personal;
		//Dueño dueño;
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

/*
class Dueño: public Personas{
	private:
		string carrera, double sueldo;
	public:
		Dueño(string, string, string, int, int, string, double);
		void mostrarDatosDueño();
};*/

#endif
