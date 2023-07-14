#include "Prodavac.h"

Prodavac& Prodavac::dodajTrojku(Artikal& a1, double mar, int br) {
	Katalog k1(a1, mar, br);
	lk1 += k1;
	return *this;
}

Posiljka& Prodavac::obradaPosiljke(Posiljka& p1) {
	for (int i = 0; i < lk1.getBrElemenata(); i++) {
		if (lk1[i].art == p1.getArtikal()) {
			p1.setbrDana(p1.det.brDana + lk1[i].brDanaK);
			p1.setCena(p1.det.cenaPosiljke + p1.getArtikal().getNabavna() * lk1[i].marza / 100);
		}
	}
	return p1;
}
