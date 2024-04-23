#pragma once

#ifndef Komplexe_Zahlen
#define Komplexe_Zahlen

#include"fehler_abfangen.h"
#include"header.h"
// klasse
class Komplexe_Zahl
{
private:
	// initialisierungen
	float immaginaerteil, realteil, phase, amplitude;
	// funktionsdeklaration in private. für P7A2
	void kartesisch_zu_polar(void);
	void polar_zu_kartesisch(void);

public:
	// standardkonstruktor aufruf.
	Komplexe_Zahl(void);
	Komplexe_Zahl(float, float, float, float);
	// funktionen. mit public funktionen kann man die privat werte ändern.
	void set_attribute(float, float);
	float get_realteil(void);
	float get_immaginaerteil(void);
	// für P7A2- funktionen
	float get_amplitude(void);
	float get_phase(void);
	void wurzelziehen(void);
	// operatoren.
	Komplexe_Zahl operator+(const Komplexe_Zahl&);
	Komplexe_Zahl operator-(const Komplexe_Zahl&);
	Komplexe_Zahl operator*(const Komplexe_Zahl&);
	Komplexe_Zahl operator/(const Komplexe_Zahl&);
};

#endif // !Komplexe_Zahlen