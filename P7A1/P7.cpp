#include "header.h"
#include"fehler_abfangen.h"
#include"Komplexe_Zahl.h"
// main
void main(void)
{
	// initialisierungen/deklkaration.
	char eingabe[GROESSE];
	int wahl = 0, ok = 0;
	Komplexe_Zahl zahl1, zahl2, erg;
	// endlosschleife
	while (wahl != 5)
	{
		// menü
		cout << "waehlen sie:\n (1) addition.\n (2) subtraktion.\n (3) multiplikation.\n (4) geteilt.\n (5) Programm beenden.\n" << endl;
		cin >> eingabe;
		// prüfen ob werte gültig sind.
		ok = pruefen_gueltig_integer(eingabe);
		if (ok == 1)
		{
			wahl = wandeln_integer(eingabe);
			// werte innerhalb menü?
			if (wahl <= 4 && wahl >= 1)
			{
					eingeben(&zahl1, &zahl2, wahl);
			}
		}
		// wahl auswählen.
		switch (wahl)
		{
		case 1:
			// zahl1 + = damit ruft man die funktion auf und zahl2 wird mit übergeben.
			erg = zahl1 + zahl2;
			get_result(zahl1, zahl2, erg, wahl);
			break;
		case 2:
			// zahl1 - = damit ruft man die funktion auf und zahl2 wird mit übergeben.
			erg = zahl1 - zahl2;
			get_result(zahl1, zahl2, erg, wahl);
			break;
		case 3:
			// zahl1 * = damit ruft man die funktion auf und zahl2 wird mit übergeben.
			erg = zahl1 * zahl2;
			get_result(zahl1, zahl2, erg, wahl);
			break;
		case 4:
			// zahl1 / = damit ruft man die funktion auf und zahl2 wird mit übergeben.
			erg = zahl1 / zahl2;
			get_result(zahl1, zahl2, erg, wahl);
			break;
		case 5:
			// ausgabe von beenden.
			cout << "Programm wird nun beendet.\n" << endl;
			break;
		default:
			// fehlerausgabe
			system("cls");
			cout << "Fehleingabe.\n" << endl;
		}
	}
}