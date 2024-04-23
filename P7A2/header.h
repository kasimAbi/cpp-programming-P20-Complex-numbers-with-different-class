#pragma once

// fehlerabfangen library einfügen.
#pragma comment(lib, "FehlerAbfangen")
#include"fehler_abfangen.h"
#include"Komplexe_Zahl.h"
// definiere pi
#define pi 3.141592
// funktionsdeklarationen.
void eingeben(Komplexe_Zahl*, Komplexe_Zahl*, int);
// ausgeben funktion.
void get_result(Komplexe_Zahl, Komplexe_Zahl, Komplexe_Zahl, int);