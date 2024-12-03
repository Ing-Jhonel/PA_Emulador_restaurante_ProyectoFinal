#ifndef FUNCIONESDESPENSA_H
#define FUNCIONESDESPENSA_H
#include <string>
#include <iostream>
using namespace std;

const int MAX_ALIMENTOS=7;


struct Alimentos{
	string nombre;
	float cantidad;
	float precio;
};
extern Alimentos alimento[MAX_ALIMENTOS];

const int limiteAlmacen = 100;

//Hamburguesa = 1 tomate, 0.1 lechuga, 0.25 bolsaharina, 0.15 carnes, 0.05 queso
//Pizzas = 4 tomate, 0.7 bolsaharina, 0.3 carnes, 0,2 queso
//Conos = 2 tomate, 0.5 lechuga, 0.25 bolsaharina 0.2 carnes, 0.1 queso
//Gaseosas = 0.5 litrogaseosa
//Agua = 0.5 litroagua

/*
Alimentos alimento[MAX_ALIMENTOS] = {
    {"Tomates", 40, 0.2}, // 0
    {"Lechugas", 5, 1}, // 1
    {"Bolsas de harina", 20, 3.5}, // 2
    {"Carnes", 20, 9}, // 3
    {"Litros de gaseosa", 20, 4}, //4
    {"Litros de agua", 20, 2.5}, //5
    {"Queso", 10, 15}
};
*/
// Cantidad de Ingredientes en una Hamburguesa
const float CTH = 1; //tomate
const float CLH = 0.1; //lechuga
const float CBH = 0.25; //bolsa de harina
const float CCH = 0.15; //carnes
const float CQH = 0.05; //queso
// 1(0.2) + 0.1(1) + 0.25(3.5) + 0.15(9) + 0.05(15) = 3.275


// Cantidad de Ingredientes en una Pizza
const float CTP = 4; //tomate
const float CBP = 0.7; //bolsa de harina
const float CCP = 0.3; //carnes
const float CQP = 0.2; //queso
// 4(0.2) + 0.75(3.5) + 0.3(9) + 0.2(15) = 8.95

// Cantidad de Ingredientes en Conos
const float CTC = 2; //tomate
const float CLC = 0.5; //lechuga
const float CBC = 0.25; //bolsa de harina
const float CCC = 0.2; //carnes
const float CQC = 0.1; //queso


// 2(0.2) + 0.5(1) + 0.25(3.5) + 0.2(9) + 0.1(15) = 4.2875

// Cantidad de litros de bebidas = CTH
const float CG = 0.5; //gaseosa
const float CA = 0.5; //agua


extern float tomatesTotalUsados;
extern float lechugasTotalUsadas;
extern float bolsasharinaTotalUsadas;
extern float carnesTotalUsadas;
extern float quesosTotalUsados;
extern float gaseosasTotalUsadas;
extern float aguasTotalUsadas;

void AgregarAlimentos();
void actualizarAlimentos();
void mostrarStock();
void mostrarMasMenosUsados();
#endif
