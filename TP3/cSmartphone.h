#pragma once
#include <iostream>
#include <string>
#include "cTelefono.h"

const int N = 20;

using namespace std;

class cSmartphone :
	public cTelefono
{
private:
	int cantidad_de_aplicaciones;
	bool internet;//conectado o no
	int senial;//cantidad de barras de senial e internet (0 a 4)
	string aplicaciones[N];

public:
	void SetRingtone();//
	void SetVolumen();//

	string GetIMEI();

	void Sonar();//
	void Menu();
	void Imprimir();//
	void Conectar_A_Internet();//conecta y desconecta el internet//
	void Agregar_Aplicacion();
	void Usar_Aplicacion();
	void Eliminar_Aplicacion();
	void ImprimirIMEI(int i);

	cSmartphone(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string Sistema_Operativo, string imei);
	~cSmartphone();
};



