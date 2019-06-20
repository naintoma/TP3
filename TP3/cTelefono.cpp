#pragma once
#include <iostream>
#include <string>
#include "cTelefono.h"



void cTelefono::SetRingtone()
{
	cout << "Ingrese la onomatopeya que desea utlizar de tono de llamada:";
	cin >> ringtone;
	system("cls");
}

void cTelefono::SetVolumen()
{
	char i = '0';
	while (i != '=')
	{
		cout << "Volumen actual: " << volumen << endl;
		cout << "+: Subir volumen" << endl;
		cout << "-: Bajar volumen" << endl;
		cout << "=: Salir" << endl;
		cin >> i;
		if (i == '+')
		{
			if (volumen != volumen_maximo)
				volumen = volumen + 1;
			else
			{
				cout << "El volumen esta al maximo" << endl;
				system("pause");
			}
		}
		if (i == '-')
		{
			if (volumen != volumen_minimo)
				volumen = volumen - 1;
			else
			{
				cout << "El volumen esta al minimo" << endl;
				system("pause");
			}
		}
		system("cls");
	}
}

string cTelefono::GetIMEI()
{
	return IMEI;
}

void cTelefono::Sonar()
{
	cout << ringtone << endl;
	system("pause");
	system("cls");
}

void cTelefono::Menu()
{
	char j = '0';
	while (j != '5')
	{
		cout << "Probar telefono" << endl;
		cout << "Menu:" << endl;
		cout << "1) Informacion del telefono" << endl;
		cout << "2) Modificar volumen" << endl;
		cout << "3) Modificar tono de llamada" << endl;
		cout << "4) Recibir llamada" << endl;
		cout << "5) Dejar de probar" << endl;
		cin >> j;
		system("cls");
		switch (j)
		{
		case '1':
			Imprimir();
			break;
		case '2':
			SetVolumen();
			break;
		case '3':
			SetRingtone();
			break;
		case '4':
			Sonar();
			break;
		default:
			break;
		}
	}
}

void cTelefono::Imprimir()
{
	cout << "Informacion del telefono:" << endl;
	cout << "Modelo: " << IMEI << endl;
	cout << "Sistema operativo: " << sistema_operativo << endl;
	cout << "Capacidad de bateria: " << capacidad_de_bateria << "mAh" << endl;
	cout << "Descripcion:" << endl;
	if (pantalla == true)
	{
		if (pantalla_tactil == true)
			cout << "-Pantalla tactil" << endl;
		else
			cout << "-Pantalla normal" << endl;
	}
	else
		cout << "-Sin Pantalla" << endl;
	if (teclado == true)
		cout << "-Con teclado" << endl;
	else
		cout << "-Sin teclado" << endl;
	system("pause");
	system("cls");
}

void cTelefono::ImprimirIMEI(int i)
{
	cout << i << ")" << IMEI << endl;
}

cTelefono::cTelefono()
{
}

cTelefono::cTelefono(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string imei)
{
	pantalla = Pantalla;
	pantalla_tactil = Pantalla_Tactil;
	capacidad_de_bateria = Capacidad_De_Bateria;
	volumen = Volumen;
	volumen_minimo = Volumen_Minimo;
	volumen_maximo = Volumen_Maximo;
	teclado = Teclado;
	sistema_operativo = "normal";
	IMEI = imei;
	ringtone = "ring";
}


cTelefono::~cTelefono()
{
	sistema_operativo = "normal";
	ringtone = "ring";
}

