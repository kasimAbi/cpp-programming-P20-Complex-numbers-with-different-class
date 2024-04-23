#include"fehler_abfangen.h"
#include"header.h"
#include"Komplexe_Zahl.h"
// standardkonstruktor.
Komplexe_Zahl::Komplexe_Zahl()
{
}
// Initialisierungen. damit sagt man nur: das mein attribut in der klasse den wert meiner variable aus der main haben soll.
Komplexe_Zahl::Komplexe_Zahl(float realteil, float immaginaerteil, float phase, float amplitude)
{
	Komplexe_Zahl::realteil = realteil;
	Komplexe_Zahl::immaginaerteil = immaginaerteil;
	Komplexe_Zahl::amplitude = amplitude;
	Komplexe_Zahl::phase = phase;
}
// mit was man die funktion aufruft, in dem werden die werte auch gespeichert. zB. man ruft mit konstruktor für zahl1 die funktion auf,
// dann werden die werte auch in zahl1 eingetragen.
void Komplexe_Zahl::set_attribute(float immaginaerteil, float realteil)
{
	Komplexe_Zahl::realteil = realteil;
	Komplexe_Zahl::immaginaerteil = immaginaerteil;
}



// operatoraufruf wenn + eingegeben wird irgendwo. zahl davor ruft die funktion auf und zahl nach + wird übergeben.
Komplexe_Zahl Komplexe_Zahl::operator+(const Komplexe_Zahl &zahl)
{
	Komplexe_Zahl ergebnis;
	// zahl1 + = damit ruft man die funktion auf und zahl2 wird mit übergeben. damit weiß die funktion direkt welcher realteil zu welchem gehört.
	ergebnis.realteil = realteil + zahl.realteil;
	ergebnis.immaginaerteil = immaginaerteil + zahl.immaginaerteil;

	return ergebnis;
}
// wie oben mit -
Komplexe_Zahl Komplexe_Zahl::operator-(const Komplexe_Zahl &zahl)
{
	Komplexe_Zahl ergebnis;
	// zahl1 + = damit ruft man die funktion auf und zahl2 wird mit übergeben. damit weiß die funktion direkt welcher realteil zu welchem gehört.
	ergebnis.realteil = realteil - zahl.realteil;
	ergebnis.immaginaerteil = immaginaerteil - zahl.immaginaerteil;

	return ergebnis;
}
// wie oben mit *
Komplexe_Zahl Komplexe_Zahl::operator*(const Komplexe_Zahl &zahl)
{
	Komplexe_Zahl ergebnis;
	// zahl1 + = damit ruft man die funktion auf und zahl2 wird mit übergeben. damit weiß die funktion direkt welcher realteil zu welchem gehört.
	ergebnis.realteil = (realteil * zahl.realteil) - (immaginaerteil * zahl.immaginaerteil);
	ergebnis.immaginaerteil = (realteil * zahl.immaginaerteil) + (immaginaerteil * zahl.realteil);

	return ergebnis;
}
// wie oben mit /
Komplexe_Zahl Komplexe_Zahl::operator/(const Komplexe_Zahl &zahl)
{
	Komplexe_Zahl ergebnis;
	// zahl1 + = damit ruft man die funktion auf und zahl2 wird mit übergeben. damit weiß die funktion direkt welcher realteil zu welchem gehört.
	ergebnis.realteil = ((realteil * zahl.realteil) + (immaginaerteil * zahl.immaginaerteil)) / (pow(zahl.realteil, 2.0) + pow(zahl.immaginaerteil, 2.0));
	ergebnis.immaginaerteil = ((realteil * zahl.immaginaerteil) + (immaginaerteil * zahl.realteil)) / (pow(zahl.realteil, 2.0) + pow(zahl.immaginaerteil, 2.0));

	return ergebnis;
}



// zum ausgeben. oder wert speichern weil die ja privat sind.
float Komplexe_Zahl::get_realteil(void)
{
	return realteil;
}
// zum ausgeben. oder wert speichern weil die ja privat sind.
float Komplexe_Zahl::get_immaginaerteil(void)
{
	return immaginaerteil;
}

//__________________________________________________________________________________________________________
// zum ausgeben. oder wert speichern weil die ja privat sind.
float Komplexe_Zahl::get_amplitude(void)
{
	return amplitude;
}
// zum ausgeben. oder wert speichern weil die ja privat sind.
float Komplexe_Zahl::get_phase(void)
{
	return phase;
}

//__________________________________________________________________________________________________________
// formel für die amplitude: r(amplitude) = wurzel(x² + y²)
// formel für die phase: §(phase) = arctan(y / x)
void Komplexe_Zahl::kartesisch_zu_polar(void)
{
	amplitude = sqrt(pow(realteil, 2) + pow(immaginaerteil, 2));
	// atan2() berechnet den Arcus Tangens des übergebenen Parameters
	// ich hab 4 quadranten, damit ich weiß in welchem ich bin. 1 koordinatensystem hat 4 quadranten.
	phase = atan2(immaginaerteil, realteil);
}
// formel für realteil: x(realteil) = r(amplitude) * cos(§(phase)).
// formel für immaginärteil: y(immaginärteil) = r(amplitude) * sin(§(phase))
void Komplexe_Zahl::polar_zu_kartesisch(void)
{
	realteil = amplitude * cos(phase);
	immaginaerteil = amplitude * sin(phase);
}
// für die rechnungen weil die funktionen privat sind.
void Komplexe_Zahl::wurzelziehen()
{
	// funktionsaufrufe.
	kartesisch_zu_polar();
	// das ergebnis muss nochmal wurzel gezogen werden
	amplitude = sqrt(amplitude);
	// phase / 2.0.
	phase = phase / 2.0;
	polar_zu_kartesisch();
}