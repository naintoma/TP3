#pragma once
#include <iostream>
#include <string>
#include "cTelefono.h"

class cCelular :
	public cTelefono
{
private:
	bool antena_externa;//tiene o no
	bool tapa;//tiene o no
	bool tapa_abierta;//abierta o no

public:
	void SetRingtone();
	void SetVolumen();

	string GetIMEI();

	void Sonar();
	void Menu();
	void Imprimir();
	void Abrir_Tapa();
	void ImprimirIMEI(int i);

	cCelular(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string Sistema_Operativo, string imei, bool Antena_Externa, bool Tapa);
	~cCelular();
};



