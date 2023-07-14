#ifndef _Posiljka_h_
#define _Posiljka_h_
#include "Artikal.h"
#include "Lista.h"
#include "Rukovalac.h"
#include "Greske.h"
using namespace std;

class Posiljka {

	struct Detalji {
		int brDana;
		double cenaPosiljke;
		Detalji(int br = 0, double br1 = 0) : brDana(br), cenaPosiljke(br1) {}
	};

	Artikal artikl;
	static int ID;
	int id;
	Lista<Rukovalac*>l1;
	bool poslato;
	Detalji det;
	friend class Prodavac;
public:
	explicit Posiljka(Artikal& a1): artikl(a1) {
		id++;
		poslato = false;
	};

	Posiljka& operator+=(Rukovalac& r1);

	Posiljka& izracunajDetalje();

	Artikal getArtikal()const { return artikl; }

	int getId() const { return id; }

	int getBrDana() const;

	double getCenaPosiljke() const;

	Posiljka& setCena(double cena);

	Posiljka& setbrDana(int dani);

	friend ostream& operator<<(ostream& os, Posiljka& p1);
};

#endif // !_Posiljka_h_
