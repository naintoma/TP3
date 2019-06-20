#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "cSmartphone.h"



void cSmartphone::SetRingtone()
{
	cout << "Ingrese la cancion que quiere utilizar como ringtone(Cancion-Artista):" << endl;
	getchar();
	getline(cin, ringtone);
	system("cls");
}

void cSmartphone::SetVolumen()
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

string cSmartphone::GetIMEI()
{
	return IMEI;
}

void cSmartphone::Sonar()
{
	cout << ringtone << endl;
	system("pause");
	system("cls");
}

void cSmartphone::Menu()
{
	char j = '0';
	while (j != '9')
	{
		cout << "Probar telefono" << endl;
		cout << "Menu:" << endl;
		cout << "1) Informacion del telefono" << endl;
		cout << "2) Modificar volumen" << endl;
		cout << "3) Modificar tono de llamada" << endl;
		cout << "4) Recibir llamada" << endl;
		cout << "5) Conectar/Desconectar el internet" << endl;
		cout << "6) Agregar aplicacion" << endl;
		cout << "7) Usar aplicacion" << endl;
		cout << "8) Eliminar aplicacion" << endl;
		cout << "9) Dejar de probar" << endl;
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
			Conectar_A_Internet();
			break;
		case '6':
			Agregar_Aplicacion();
			break;
		case '7':
			Usar_Aplicacion();
			break;
		case '8':
			Eliminar_Aplicacion();
			break;
		default:
			break;
		}
	}
}

void cSmartphone::Imprimir()
{
	cout << "Informacion del telefono:" << endl;
	cout << "Modelo: " << IMEI << endl;
	cout << "Sistema operativo: " << sistema_operativo << endl;
	cout << "Capacidad de bateria: " << capacidad_de_bateria << "mAh" << endl;
	cout << "Espacio del dispositivo: " << N << "GB" << endl;
	cout << "Espacio ocupado: " << cantidad_de_aplicaciones << "GB" << endl;
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

void cSmartphone::Conectar_A_Internet()
{
	if (internet == false)
	{
		int l = rand() % 2;
		if (l == 0)
		{
			internet = true;
			cout << "Internet conectado" << endl;
			senial = rand() % 4 + 1;
		}
		else
			cout << "La conexion ha fallado" << endl;
	}
	else
	{
		internet = false;
		cout << "Internet desconectado" << endl;
		senial = 0;
	}
	system("pause");
	system("cls");
}

void cSmartphone::Agregar_Aplicacion()
{
	if (internet == false)
	{
		cout << "No esta conectado a internet." << endl;
		system("pause");
		system("cls");
		return;
	}
	if (cantidad_de_aplicaciones == N)
	{
		cout << "No hay mas espacio." << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Ingrese el nombre de la aplicacion que desea descagar:" << endl;
	getchar();
	getline(cin, aplicaciones[cantidad_de_aplicaciones]);
	cantidad_de_aplicaciones++;
	system("cls");
}

void cSmartphone::Usar_Aplicacion()
{
	if (cantidad_de_aplicaciones == 0)
	{
		cout << "No hay aplicaciones" << endl;
		system("pause");
		system("cls");
		return;
	}
	int j = 0;
	while (j != cantidad_de_aplicaciones + 1)
	{
		cout << "Elija la aplicacion que quiere usar:" << endl;
		for (int i = 0; i < cantidad_de_aplicaciones; i++)
			cout << i + 1 << ")" << aplicaciones[i] << endl;
		cout << cantidad_de_aplicaciones + 1 << ")Salir" << endl;
		cin >> j;
		system("cls");
		for (int i = 0; i < N; i++)
		{
			if (j >= 1 && j <= cantidad_de_aplicaciones + 1)
			{
				if (j != cantidad_de_aplicaciones + 1)
				{
					if (j == i + 1)
					{
						cout << "Usando: " << aplicaciones[i] << endl;
						system("pause");
						system("cls");
					}
				}
			}
		}
	}
	system("cls");
}

void cSmartphone::Eliminar_Aplicacion()
{
	int a;
	if (cantidad_de_aplicaciones == 0)
	{
		cout << "No hay aplicaciones" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Que aplicacion quieres eliminar?" << endl;
	for (int i = 0; i < cantidad_de_aplicaciones; i++)
		cout << i + 1 << ")" << aplicaciones[i] << endl;
	cout << cantidad_de_aplicaciones + 1 << ")Salir" << endl;
	cin >> a;
	if (a == cantidad_de_aplicaciones + 1)
	{
		system("cls");
		return;
	}
	if (a < 1 || a > cantidad_de_aplicaciones + 1)
	{
		cout << "Hubo un error" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = a - 1; i < cantidad_de_aplicaciones - 1; i++)
		aplicaciones[i] = aplicaciones[i + 1];
	cantidad_de_aplicaciones--;
	system("cls");
}

void cSmartphone::ImprimirIMEI(int i)
{
	cout << i << ")" << IMEI << endl;
}

cSmartphone::cSmartphone(bool Pantalla, bool Pantalla_Tactil, int Capacidad_De_Bateria, int Volumen, int Volumen_Minimo, int Volumen_Maximo, bool Teclado, string Sistema_Operativo, string imei)
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
	ringtone = "I Gotta Feeling-The Black Eyed Peas";
	cantidad_de_aplicaciones = 0;
	internet = false;
	senial = 0;
}


cSmartphone::~cSmartphone()
{
}