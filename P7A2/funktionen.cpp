#include"fehler_abfangen.h"
#include"header.h"
#include"Komplexe_Zahl.h"
// zum eingeben der zahlen.
void eingeben(Komplexe_Zahl* zahl1, Komplexe_Zahl* zahl2, int wahl)
{
	// initialisierungen/ deklarationen.
	char eingabe[GROESSE];
	int ok = 0;
	float realteil = 0.0, immaginaerteil = 0.0, frequenz = 0.0, w = 0.0;
	system("cls");
	// endlosschleife. ok = 0.
	while (ok == 0)
	{
		cout << "geben sie frequenz ein:\t\t";
		cin >> eingabe;
		cout << endl;
		// gibt -1 für -wert und +1 für +wert und 0 für fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um.
			frequenz = wandeln_float(eingabe);
		}
		else
		{
			system("cls");
			// fehlermeldung
			cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
		}
	}
	// formel für w. vorgegeben.
	w = 2.0 * pi * frequenz;
	ok = 0;
	// ok = 0 setzen für die while.
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl \"L\" ein:\t";
		cin >> eingabe;
		// gibt -1 für -wert und +1 für +wert und 0 für fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um.
			immaginaerteil = wandeln_float(eingabe);
			// formel: immaginärteil * w
			immaginaerteil = w * immaginaerteil;
			ok = 0;
			// ok = 0 setzen und damit weiterarbeiten
			while (ok == 0)
			{
				cout << "geben sie realteil von Zahl \"R\" ein:\t\t";
				cin >> eingabe;
				// gibt -1 für -wert und +1 für +wert und 0 für fehler.
				ok = pruefen_gueltig_float(eingabe);
				if (ok != 0)
				{
					// wandelt zahl um.
					realteil = wandeln_float(eingabe);
					// mit zahl1 ruft man die funktion auf das heißt für konstruktor zahl1 werden die werte auch drin gespeichert.
					zahl1->set_attribute(realteil, immaginaerteil);
				}
				else
				{
					system("cls");
					// fehlermeldung
					cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
				}
			}
		}
		else
		{
			system("cls");
			// fehlermeldung
			cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
		}
	}
	// ok = 0 setzen damit man damit weiterarbeiten kann.
	// ist einfacher weil mein prüfen()-funktion 0 für fehler gibt.
	ok = 0;
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl \"C\" ein:\t";
		cin >> eingabe;
		// gibt -1 für -wert und +1 für +wert und 0 für fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um
			immaginaerteil = wandeln_float(eingabe);
			// formel: immaginärteil * w
			immaginaerteil = w * immaginaerteil;
			// ok zurücksetzen für die nächste eingabe
			ok = 0;
			if (wahl == 4 && immaginaerteil == 0.0)
			{
				system("cls");
				// fehlermeldung. durch 0 geht nciht.
				cout << "division ohne 0.\nerneut eingeben.\n\n" << endl;
			}
			else
			{
				while (ok == 0)
				{
					cout << "geben sie realteil von Zahl \"G\" ein:\t\t";
					cin >> eingabe;
					// gibt -1 für -wert und +1 für +wert und 0 für fehler.
					ok = pruefen_gueltig_float(eingabe);
					if (ok != 0)
					{
						// wandelt zahl um
						realteil = wandeln_float(eingabe);
						if (wahl == 4 && realteil == 0.0)
						{
							system("cls");
							// fehlermeldung. durch 0 geht nciht.
							cout << "division ohne 0.\nerneut eingeben.\n\n" << endl;
						}
						else
						{
							// mit zahl2 ruft man die funktion auf das heißt für konstruktor zahl1 werden die werte auch drin gespeichert.
							zahl2->set_attribute(realteil, immaginaerteil);
							system("cls");
						}
					}
					else
					{
						system("cls");
						// fehlermeldung
						cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
					}
				}
			}
		}
		else
		{
			system("cls");
			// fehlermeldung
			cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
		}
	}
}
// asugeben funktion
void get_result(Komplexe_Zahl zahl1, Komplexe_Zahl zahl2, Komplexe_Zahl ergebnis, int wahl)
{
	// ergebniswerte für kartesisch und polarform ausgeben.
	cout << "\nWellenwiderstand lautet: " << ergebnis.get_realteil() << " + " << ergebnis.get_immaginaerteil() << " OHM" << endl;
	cout << "Amplitude: " << ergebnis.get_amplitude() << " + Phase: e ^" << ergebnis.get_phase() << " i" << endl << endl << endl;
}