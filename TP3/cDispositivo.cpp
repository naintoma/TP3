#include "cDispositivo.h"



cTelefono cDispositivo::GetT()
{
	return *T;
}

cCelular cDispositivo::GetC()
{
	return *C;
}

cSmartphone cDispositivo::GetS()
{
	return *S;
}

int cDispositivo::GetClase()
{
	return Clase;
}

string cDispositivo::GetIMEI()
{
	if (Clase == 1)
		return T->GetIMEI();
	if (Clase == 2)
		return C->GetIMEI();
	if (Clase == 3)
		return S->GetIMEI();
	return 0;
}

void cDispositivo::Imprimir(int i)
{
	if (Clase == 1)
		T->ImprimirIMEI(i);
	if (Clase == 2)
		C->ImprimirIMEI(i);
	if (Clase == 3)
		S->ImprimirIMEI(i);
}

cDispositivo::cDispositivo(cTelefono* t)
{
	Clase = 1;
	T = new cTelefono(*t);
}

cDispositivo::cDispositivo(cCelular* c)
{
	Clase = 2;
	C = new cCelular(*c);
}

cDispositivo::cDispositivo(cSmartphone* s)
{
	Clase = 3;
	S = new cSmartphone(*s);
}

cDispositivo::cDispositivo()
{
}


cDispositivo::~cDispositivo()
{
	delete T;
	delete C;
	delete S;
}
