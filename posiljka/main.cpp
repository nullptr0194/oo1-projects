#include"Artikal.h"
#include "Lista.h"
#include "Posiljka.h"
#include "Prodavac.h"
using namespace std;

int main() {
	try {
		/*Artikal a1("Banana", 1, 50);
		Artikal a2("jabuka", 322, 30);
		Artikal a3("ajdara", 322, 20);
		Artikal a4("breskvica", 6969, 100);

		int x = a1 == a2;
		int y = a2 == a3;
		cout << x;
		cout << endl << y;

		Lista<Artikal>l1;
		l1 += a1;
		l1 += a2;

		cout <<endl<< l1[1].getBarkod();

		Posiljka pos1(a2);
		Prodavac prodavacMile("Mile");

		prodavacMile.dodajTrojku(a3, 22.5, 5);

		pos1 += prodavacMile;

		cout << pos1;

		pos1.izracunajDetalje();
*/
		Artikal art1("predmet", 69, 1000);
		Lista<Artikal> lista1;
		Posiljka izKine(art1);
		Prodavac mika("Mirko");

		mika.dodajTrojku(art1, 10, 5);
		izKine += mika;


		izKine.izracunajDetalje();

		cout << izKine<< izKine.getCenaPosiljke();


	}
	catch (GNePostojiElNaPoziciji& g1) {
		cout << g1;
	}
	catch (GRanoDohvatanjeDetalja & g2) {
		cout << g2;
	}
	catch (GKasnoDodavanjeRukovaoca & g3) {
		cout << g3;
	}
	catch (...) {
		cout << "GRESKA:Nepredvidjena greska";
	}
}