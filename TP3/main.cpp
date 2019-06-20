#pragma once
#include <string>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "cTelefono.h"
#include "cCelular.h"
#include "cSmartphone.h"
#include "cDispositivo.h"
#define NMAX 10

using namespace std;
template<class T>
class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;


	void Redimensionalizar();
public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T* item);
	bool AgregarItemOrdenado(const T* item);

	T* Quitar(string clave);
	T* Quitar(const T* item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void Eliminar(const T* item);
	void Eliminar(unsigned int pos);

	void Listar();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();
};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}
template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}
///////////
template<class T>
void cListaT<T>::Redimensionalizar()
{
}


template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;


}
template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}


}

template<class T>
void cListaT<T>::Listar()
{

	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir(i+1);// imprimir
	}
}

template<class T>
bool cListaT<T>::AgregarItem(T * item)
{

	T* i_f = BuscarItem(item->GetIMEI());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tamanio suficiente para agregar el item");;
	return true;
}
template<class T>

bool cListaT<T>::AgregarItemOrdenado(const T * item)
{
	/*for (unsigned int i = 0; i < CA; i++)
	{
	if (vector[i]->getclave() == clave)
	return vector[i];
	}
	*/
	return false;
}
template<class T>
T* cListaT<T>::Quitar(string clave) {

	unsigned int pos = getItemPos(clave);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}
template<class T>
T* cListaT<T>::Quitar(const T * item) {
	unsigned int pos = getItemPos(item->getclave());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}
template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	T * aux = vector[pos];

	for (unsigned int i = 0; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}


template<class T>
void cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);

	if (pos < CA)
		Eliminar(pos);
	//sino algo

}
template<class T>
void cListaT<T>::Eliminar(const T * item) {

	Eliminar(item->getclave());
}
template<class T>
void cListaT<T>::Eliminar(unsigned int pos) {
	if (pos >= CA)return;// o Throw no pude eliminar

	T * dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
	else
	{
		throw new exception("no encontrado");
	}
}

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->GetIMEI() == clave)
			return vector[i];
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}
template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return i;
	}

	return INT_MAX;
}

int main()
{
	srand(time(NULL));
	cListaT<cDispositivo>* Lista = new cListaT<cDispositivo>();

	cTelefono* T;
	cCelular* C;
	cSmartphone* S;
	cDispositivo* D;

	unsigned int i;

	string imei;
	string sistema_operativo;

	char j = '0';

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//1
	imei = "Telefono normal 1";

	T = new cTelefono(false, false, 0, 2, 0, 4, false, imei);
	D = new cDispositivo(T);
	Lista->AgregarItem(D);

	//2

	imei = "Telefono normal 2";

	T = new cTelefono(true, false, 0, 2, 0, 4, false, imei);
	D = new cDispositivo(T);
	Lista->AgregarItem(D);

	//3

	sistema_operativo = "Propietario OS";
	imei = "Nokia 1100";

	C = new cCelular(true, false, 850, 3, 0, 6, false, sistema_operativo, imei, false, false);
	D = new cDispositivo(C);
	Lista->AgregarItem(D);

	//4

	sistema_operativo = "Propietario OS";
	imei = "Motorala Star Tac 85";

	C = new cCelular(true, false, 500, 2, 0, 4, false, sistema_operativo, imei, true, true);
	D = new cDispositivo(C);
	Lista->AgregarItem(D);

	//5

	sistema_operativo = "BlackBerry OS 6.0";
	imei = "BlackBerry Curve 3G 9300";

	S = new cSmartphone(true, false, 1150, 4, 0, 8, true, sistema_operativo, imei);
	D = new cDispositivo(S);
	Lista->AgregarItem(D);

	//6

	sistema_operativo = "BlackBerry OS 6.0";
	imei = "BlackBerry Touch 9800";

	S = new cSmartphone(true, true, 1300, 5, 0, 10, true, sistema_operativo, imei);
	D = new cDispositivo(S);
	Lista->AgregarItem(D);

	//7

	sistema_operativo = "ios 12";
	imei = "iPhone XS";

	S = new cSmartphone(true, true, 2658, 8, 0, 16, false, sistema_operativo, imei);
	D = new cDispositivo(S);
	Lista->AgregarItem(D);

	//8

	sistema_operativo = "Android 7.0 Nougat";
	imei = "Samsung Galaxy note 7";

	S = new cSmartphone(true, true, 3500, 6, 0, 12, false, sistema_operativo, imei);
	D = new cDispositivo(S);
	Lista->AgregarItem(D);

	//9

	sistema_operativo = "Android 9.0 Pie";
	imei = "Samsung Galaxy S10 5G";

	S = new cSmartphone(true, true, 4500, 7, 0, 14, false, sistema_operativo, imei);
	D = new cDispositivo(S);
	Lista->AgregarItem(D);

	//10

	sistema_operativo = "Android 9.0 Pie";
	imei = "OnePlus 6T";
	S = new cSmartphone(true, true, 3700, 7, 0, 14, false, sistema_operativo, imei);
	D = new cDispositivo(S);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Lista->AgregarItem(D);
	while (j != '2')
	{
		cout << "Que dispositivo desea fabricar?" << endl;
		Lista->Listar();
		cin >> i;
		system("cls");
		if (i <= 10 && i >= 1)
		{
			D = Lista->getItem(i - 1);
			if (D->GetClase() == 1)
			{
				if (D->GetIMEI() == "Telefono normal 1")
				{
					if (rand() % 10 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						T = new cTelefono(D->GetT());
						T->Menu();
					}
				}
				if (D->GetIMEI() == "Telefono normal 2")
				{
					if (rand() % 9 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						T = new cTelefono(D->GetT());
						T->Menu();
					}
				}
			}
			if (D->GetClase() == 2)
			{
				if (D->GetIMEI() == "Nokia 1100")
				{
					if (rand() % 100 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						C = new cCelular(D->GetC());
						C->Menu();
					}
				}
				if (D->GetIMEI() == "Motorala Star Tac 85")
				{
					if (rand() % 50 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						C = new cCelular(D->GetC());
						C->Menu();
					}
				}
			}
			if (D->GetClase() == 3)
			{
				if (D->GetIMEI() == "iPhone XS")
				{
					if (rand() % 1000 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						S = new cSmartphone(D->GetS());
						S->Menu();
					}
				}
				if (D->GetIMEI() == "Samsung Galaxy note 7")
				{
					if (rand() % 2 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						S = new cSmartphone(D->GetS());
						S->Menu();
					}
				}
				if (D->GetIMEI() == "Samsung Galaxy S10 5G")
				{
					if (rand() % 999 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						S = new cSmartphone(D->GetS());
						S->Menu();
					}
				}
				if (D->GetIMEI() == "OnePlus 6T")
				{
					if (rand() % 999 == 0)
					{
						cout << "BOOM" << endl;
						cout << "El dispositivo exploto" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Dispositivo fabricado" << endl;
						system("pause");
						system("cls");
						S = new cSmartphone(D->GetS());
						S->Menu();
					}
				}

			}
		}
		else
		{
			cout << "No es una opcion" << endl;
			system("pause");
			system("cls");
		}
		j = '0';
		while (j != '2' && j != '1')
		{
			cout << "Quiere Seguir?" << endl;
			cout << "1)Si" << endl;
			cout << "2)No" << endl;
			cin >> j;
			system("cls");
		}
	}
	T = NULL;
	C = NULL;
	S = NULL;
	D = NULL;
	delete Lista;
	delete T;
	delete C;
	delete S;
	delete D;
}