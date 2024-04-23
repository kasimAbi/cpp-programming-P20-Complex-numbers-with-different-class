#include"fehler_abfangen.h"
#include"header.h"
#include"Komplexe_Zahl.h"
// zum eingeben der zahlen.
void eingeben(Komplexe_Zahl* zahl1, Komplexe_Zahl* zahl2, int wahl)
{
	// initialisierungen/ deklarationen.
	char eingabe[GROESSE];
	int ok = 0;
	float realteil = 0.0, immaginaerteil = 0.0;
	system("cls");
	// endlosschleife. ok = 0.
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl 1 ein:\n" << endl;
		cin >> eingabe;
		// gibt -1 für -wert und +1 für +wert und 0 für fehler.
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			// wandelt zahl um.
			immaginaerteil = wandeln_float(eingabe);
			// ok = 0 setzen damit man das wieder für die endlosschleife nutzen kann.
			ok = 0;
			while (ok == 0)
			{
				system("cls");
				cout << "geben sie realteil von Zahl 1 ein:\n" << endl;
				cin >> eingabe;
				// wie oben auch.
				ok = pruefen_gueltig_float(eingabe);
				if (ok != 0)
				{
					realteil = wandeln_float(eingabe);
					// mit zahl1 ruft man die funktion auf das heißt für konstruktor zahl1 werden die werte auch drin gespeichert.
					zahl1->set_attribute(realteil, immaginaerteil);

				}
				else
				{
					system("cls");
					// fehlerausgabe
					cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
				}
			}
		}
		else
		{
			system("cls");
			// fehlerausgabe
			cout << "fehleingabe.\nerneut eingeben.\n\n" << endl;
		}
	}
	// geiches spiel für die nächsten werte.
	ok = 0;
	system("cls");
	while (ok == 0)
	{
		cout << "geben sie immaginaerteil von Zahl 2 ein:\n" << endl;
		cin >> eingabe;
		ok = pruefen_gueltig_float(eingabe);
		if (ok != 0)
		{
			immaginaerteil = wandeln_float(eingabe);
			// wieder ok = 0 setzen für nächsten wert.
			ok = 0;
			// wenn wahl = 4(division) und wert = 0.0 ist, dann fehlermeldung weil durhc 0.0 nciht teilbar.
			if (wahl == 4 && immaginaerteil == 0.0)
			{
				system("cls");
				// fehlermeldung.
				cout << "division ohne 0.\nerneut eingeben.\n\n" << endl;
			}
			else
			{
				system("cls");
				while (ok == 0)
				{
					cout << "geben sie realteil von Zahl 2 ein:\n" << endl;
					cin >> eingabe;
					ok = pruefen_gueltig_float(eingabe);
					if (ok != 0)
					{
						// das selbe für realteil von zahl2 auch. wert darf nciht 0 sein.
						realteil = wandeln_float(eingabe);
						if (wahl == 4 && realteil == 0.0)
						{
							system("cls");
							cout << "division ohne 0.\nerneut eingeben.\n\n" << endl;
						}
						else
						{
							// mit zahl2 ruft man die funktion auf und die werte werden darum in zahl2 gespeichert.
							zahl2->set_attribute(realteil, immaginaerteil);
						}
					}
				}
			}
		}
	}
}
// ausgabe funktion.
void get_result(Komplexe_Zahl zahl1, Komplexe_Zahl zahl2, Komplexe_Zahl ergebnis, int wahl)
{
	cout << endl;
	// ausgabe von den werten für ordnung.
	cout << "(" << zahl1.get_realteil() << " + " << zahl1.get_immaginaerteil() << "i)";
	// wahl zeigt auch gleichzeitig den operator
	switch (wahl)
	{
	case 1:
		// für plus
		cout << " + ";
		break;
	case 2:
		// minus
		cout << " - ";
		break;
	case 3:
		// mal
		cout << " * ";
		break;
	case 4:
		// geteilt
		cout << "  / ";
		break;
	}
	cout << "(" << zahl2.get_realteil() << " + " << zahl2.get_immaginaerteil() << "i)";
	cout << " = ";
	// ergebnis wird ausgegeben.
	cout << "(" << ergebnis.get_realteil() << " + " << ergebnis.get_immaginaerteil() << "i)" << endl;
}