#include "header.h"
#include"fehler_abfangen.h"
#include"Komplexe_Zahl.h"
// main
void main(void)
{
	// initialisierungen/ deklaration
	char eingabe[GROESSE];
	int wahl = 0, ok = 0;
	Komplexe_Zahl zahl1, zahl2, erg;
	// 2 ist endbedingung
	while (wahl != 2)
	{
		// menü
		cout << "waehlen sie:\n (1) wellenberechnung.\n (2) Programm beenden.\n" << endl;
		cin >> eingabe;
		// -1 für -wert und +1 für +wert. 0 für fehler: rückgabewerte
		ok = pruefen_gueltig_integer(eingabe);
		if (ok == 1)
		{
			// wandelt zahl in integer wert um.
			wahl = wandeln_integer(eingabe);
			if (wahl == 1)
			{
				// 4 mitgeben weil vorheriges Programm hatte 4 bei division. für den fall das hier auhc nciht durch 0 teibar ist.
				eingeben(&zahl1, &zahl2, 4);		
			}
		}
		switch (wahl)
		{
		case 1:
			// funktionsaufrufe, operatoraufruf. zahl1 ruft / auf und übergibt zahl2.
			erg = zahl1 / zahl2;
			erg.wurzelziehen();
			// ausgeben funktion
			get_result(zahl1, zahl2, erg, wahl);
			break;
		case 2:
			// programm beenden
			cout << "Programm wird nun beendet.\n" << endl;
			break;
		default:
			system("cls");
			// fehlermeldung
			cout << "Fehleingabe.\n" << endl;
		}
	}
}