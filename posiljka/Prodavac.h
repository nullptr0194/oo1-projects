#ifndef _Prodavac_h_
#define _Prodavac_h_
#include"Artikal.h"
#include"Posiljka.h"



class Prodavac:public Rukovalac  {
	struct Katalog{
		Artikal art;
		double marza;
		int brDanaK;

		Katalog(Artikal& a1, double mar, int br):art(a1), marza(mar), brDanaK(br) {}
	};
	string naziv;
	Lista<Katalog> lk1;

public:

	explicit Prodavac(string naz): naziv(naz){}

	string getNaziv() const { return naziv; }

	Prodavac& dodajTrojku(Artikal& a1, double mar, int br);

	Posiljka& obradaPosiljke(Posiljka& p1) override;




};

#endif // !_Prodavac_h_
