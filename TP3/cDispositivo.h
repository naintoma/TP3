#pragma once
#include <string>
#include <iostream>
#include "cTelefono.h"
#include "cCelular.h"
#include "cSmartphone.h"

class cDispositivo
{
private:
	cTelefono* T;
	cCelular* C;
	cSmartphone* S;
	int Clase;//1-cTelefono, 2-cCelular, 3-cSmartphone

public:
	cTelefono GetT();
	cCelular GetC();
	cSmartphone GetS();
	int GetClase();

	string GetIMEI();

	void Imprimir(int i);

	cDispositivo(cTelefono* t);
	cDispositivo(cCelular* c);
	cDispositivo(cSmartphone* s);
	cDispositivo();
	~cDispositivo();
};

