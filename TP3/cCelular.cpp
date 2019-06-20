#pragma once
#include <iostream>
#include <string>
#include "cCelular.h"



void cCelular::SetRingtone()
{
	char i = '0';
	cout << "Elegir ringtone:" << endl;
	cout << "0)Aperura" << endl;
	cout << "1)Radar" << endl;
	cout << "2)Alarma" << endl;
	cout << "3)Marimba" << endl;
	cout << "4)Telefono antiguo" << endl;
	cout << "5)Sonda" << endl;
	cout << "6)Presto" << endl;
	cout << "7)Olas" << endl;
	cout << "8)Faro" << endl;
	cout << "9)Boing" << endl;
	cin >> i;
	switch (i)
	{
	case '0':
		//char a[] = "Apertura";
		//ringtone = a;
		ringtone = "Apertura";
		break;
	case '1':
		//char a[] = "Radar";
		//ringtone = a;
		ringtone = "Radar";
		break;
	case '2':
		//char a[] = "Alarma";
		//ringtone = a;
		ringtone = "Alarma";
		break;
	case '3':
		//char a[] = "Marimba";
		//ringtone = a;
		ringtone = "Marimba";
		break;
	case '4':
		//char a[] = "Telefono antiguo";
		//ringtone = a;
		ringtone = "Telefono antiguo";
		break;
	case '5':
		//char a[] = "Sonda";
		//ringtone = a;
		ringtone = "Sonda";
		break;
	case '6':
		//char a[] = "Presto";
		//ringtone = a;
		ringtone = "Presto";
		break;
	case '7':
		//char a[] = "Olas";
		//ringtone = a;
		ringtone = "Olas";
		break;
	case '8':
		//char a[] = "Faro";
		//ringtone = a;
		ringtone = "Faro";
		break;
	case '9':
		//char a[] = "Boing";
		//ringtone = a;
		ringtone = "Boing";
		break;
	default:
		system("cls");
		SetRingtone();
		break;
	}
	system("cls");
}

void cCelular::SetVolumen()
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

string cCelular::GetIMEI()
{
	return IMEI;
}

void cCelular::Sonar()
{
	cout << ringtone << endl;
	system("pause");
	system("cls");
}

void cCelular::Menu()
{
	char j = '0';
	while (j != '6')
	{
		cout << "Probar telefono" << endl;
		cout << "Menu:" << endl;
		cout << "1) Informacion del telefono" << endl;
		cout << "2) Modificar volumen" << endl;
		cout << "3) Modificar tono de llamada" << endl;
		cout << "4) Recibir llamada" << endl;
		cout << "5) Cerrar tapa" << endl;
		cout << "6) Dejar de probar" << endl;
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
		case '5':
			Abrir_Tapa();
			Abrir_Tapa();
			break;
		default:
			break;
		}
	}
}

void cCelular::Imprimir()
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
	if (tapa == true)
		cout << "-Con tapa" << endl;
	else
		cout << "-Sin tapa" << endl;
	if (antena_externa == true)
		cout << "-Con antena externa" << endl;
	else
		cout << "-Sin antena externa" << endl;
	system("pause");
	system("cls");
}

void cCelular::Abrir_Tapa()
{
	if (tapa_abierta == true)
	{
		tapa_abierta = false;
		cout << "Tapa cerrada" << endl;
	}
	else
	{
		tapa_abierta = true;
		cout << "Tapa abierta" << endl;
	}
	system("pause");
	system("cls");
}

void cCelular::ImprimirIMEI(int i)
{
	cout << i << ")" << IMEI << endl;
}

cCelular::cCelular(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string Sistema_Operativo, string imei, bool Antena_Externa, bool Tapa)
{
	pantalla = Pantalla;
	pantalla_tactil = Pantalla_Tactil;
	capacidad_de_bateria = Capacidad_De_Bateria;
	volumen = Volumen;
	volumen_minimo = Volumen_Minimo;
	volumen_maximo = Volumen_Maximo;
	teclado = Teclado;
	sistema_operativo = Sistema_Operativo;
	IMEI = imei;
	ringtone = "Apertura";
	antena_externa = Antena_Externa;
	tapa = Tapa;
	tapa_abierta = false;
}


cCelular::~cCelular()
{
}
