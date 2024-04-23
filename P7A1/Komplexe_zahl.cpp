#include"fehler_abfangen.h"
#include"header.h"
#include"Komplexe_Zahl.h"
// standardkonstruktor.
Komplexe_Zahl::Komplexe_Zahl()
{
}
// Initialisierungen. damit sagt man nur: das mein attribut in der klasse den wert meiner variable aus der main haben soll.
Komplexe_Zahl::Komplexe_Zahl(float realteil, float immaginaerteil)
{
	Komplexe_Zahl::realteil = realteil;
	Komplexe_Zahl::immaginaerteil = immaginaerteil;
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
	ergebnis.immaginaerteil = (-(realteil * zahl.immaginaerteil) + (immaginaerteil * zahl.realteil)) / (pow(zahl.realteil, 2.0) + pow(zahl.immaginaerteil, 2.0));

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