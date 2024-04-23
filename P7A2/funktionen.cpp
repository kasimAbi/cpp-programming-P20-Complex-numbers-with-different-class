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
		// gibt -1 f�r -wert und +1 f�r +wert und 0 f�r fehler.
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
	// formel f�r w. vorgegeben.
	w = 2.0 * pi * frequenz;
	ok = 0;
	// ok = 0 setzen f�r die while.
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl \"L\" ein:\t";
		cin >> eingabe;
		// gibt -1 f�r -wert und +1 f�r +wert und 0 f�r fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um.
			immaginaerteil = wandeln_float(eingabe);
			// formel: immagin�rteil * w
			immaginaerteil = w * immaginaerteil;
			ok = 0;
			// ok = 0 setzen und damit weiterarbeiten
			while (ok == 0)
			{
				cout << "geben sie realteil von Zahl \"R\" ein:\t\t";
				cin >> eingabe;
				// gibt -1 f�r -wert und +1 f�r +wert und 0 f�r fehler.
				ok = pruefen_gueltig_float(eingabe);
				if (ok != 0)
				{
					// wandelt zahl um.
					realteil = wandeln_float(eingabe);
					// mit zahl1 ruft man die funktion auf das hei�t f�r konstruktor zahl1 werden die werte auch drin gespeichert.
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
	// ist einfacher weil mein pr�fen()-funktion 0 f�r fehler gibt.
	ok = 0;
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl \"C\" ein:\t";
		cin >> eingabe;
		// gibt -1 f�r -wert und +1 f�r +wert und 0 f�r fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um
			immaginaerteil = wandeln_float(eingabe);
			// formel: immagin�rteil * w
			immaginaerteil = w * immaginaerteil;
			// ok zur�cksetzen f�r die n�chste eingabe
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
					// gibt -1 f�r -wert und +1 f�r +wert und 0 f�r fehler.
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
							// mit zahl2 ruft man die funktion auf das hei�t f�r konstruktor zahl1 werden die werte auch drin gespeichert.
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
	// ergebniswerte f�r kartesisch und polarform ausgeben.
	cout << "\nWellenwiderstand lautet: " << ergebnis.get_realteil() << " + " << ergebnis.get_immaginaerteil() << " OHM" << endl;
	cout << "Amplitude: " << ergebnis.get_amplitude() << " + Phase: e ^" << ergebnis.get_phase() << " i" << endl << endl << endl;
}