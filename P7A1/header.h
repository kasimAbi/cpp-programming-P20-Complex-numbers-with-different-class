#pragma once

// fehlerabfangen library einf�gen.
#pragma comment(lib, "FehlerAbfangen")
#include"fehler_abfangen.h"
#include"Komplexe_Zahl.h"
// funktionsdeklarationen.
void eingeben(Komplexe_Zahl*, Komplexe_Zahl*, int);
// ausgeben funktion.
void get_result(Komplexe_Zahl, Komplexe_Zahl, Komplexe_Zahl, int);