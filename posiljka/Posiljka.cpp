#include "Posiljka.h"
int Posiljka::ID = 0;

Posiljka& Posiljka::operator+=(Rukovalac& r1) {
	if (poslato) throw GKasnoDodavanjeRukovaoca();
	else {
		l1 += &r1;
	}
	return *this;
}

Posiljka& Posiljka::izracunajDetalje() {
	for (int i = 0; i < l1.getBrElemenata(); i++) {
		*this = l1[i]->obradaPosiljke(*this);
	}
	poslato = true;
	return *this;
}

int Posiljka::getBrDana() const {
	if (!poslato) throw GRanoDohvatanjeDetalja();
	return det.brDana;
}

double Posiljka::getCenaPosiljke() const {
	if (!poslato) throw GRanoDohvatanjeDetalja();
	return det.cenaPosiljke;
}

Posiljka& Posiljka::setCena(double cena) {
	det.cenaPosiljke = cena;
	return *this;
}

Posiljka& Posiljka::setbrDana(int dani) {
	det.brDana = dani;
	return *this;
}

ostream& operator<<(ostream& os, Posiljka& p1) {
	os << "Posiljka[" << p1.id << "," << p1.artikl.getNaziv() << "]";
	return os;
}
