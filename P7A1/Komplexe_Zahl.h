#pragma once

#ifndef Komplexe_Zahlen
#define Komplexe_Zahlen

#include"fehler_abfangen.h"
#include"header.h"
// klasse 
class Komplexe_Zahl
{
private:
	// initialisierungen.
	float immaginaerteil, realteil;
	int test;
public:
	// standardkonstruktor aufruf.
	Komplexe_Zahl(void);
	Komplexe_Zahl(float, float);
	// funktionen. mit public funktionen kann man die privat werte ändern.
	void set_attribute(float, float);
	float get_realteil(void);
	float get_immaginaerteil(void);
	// operatoren.
	Komplexe_Zahl operator+(const Komplexe_Zahl&);
	Komplexe_Zahl operator-(const Komplexe_Zahl&);
	Komplexe_Zahl operator*(const Komplexe_Zahl&);
	Komplexe_Zahl operator/(const Komplexe_Zahl&);
};

#endif // !Komplexe_Zahlen