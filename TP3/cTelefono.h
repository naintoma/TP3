#pragma once
#include <iostream>
#include <string>

using namespace std;

class cTelefono
{
protected:
	bool pantalla;//tiene o no
	bool pantalla_tactil;//tactil o no
	int capacidad_de_bateria;
	int volumen;
	int volumen_minimo;
	int volumen_maximo;
	bool teclado;//tiene o no
	string sistema_operativo;
	string IMEI;
	string ringtone;

public:
	void SetRingtone();
	void SetVolumen();

	string GetIMEI();

	void Sonar();
	void Menu();
	void Imprimir();
	void ImprimirIMEI(int i);

	cTelefono();
	cTelefono(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string imei);
	~cTelefono();
};

