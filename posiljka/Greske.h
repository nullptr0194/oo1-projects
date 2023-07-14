#ifndef _Greske_h_
#define _Greske_h_
#include <iostream>
using namespace std;

class GNePostojiElNaPoziciji {
	friend ostream& operator<<(ostream& os,GNePostojiElNaPoziciji& g1) {
		return os << "GRESKA:Podatak na zadatoj poziciji ne postoji " << endl;
	}
};
class GRanoDohvatanjeDetalja {
	friend ostream& operator<<(ostream& os, GRanoDohvatanjeDetalja& g2) {
		return os << "GRESKA:Detalji posiljke jos nisu izracunati, ne mogu se dohvatiti " << endl;
	}
};
class GKasnoDodavanjeRukovaoca {
	friend ostream& operator<<(ostream& os, GKasnoDodavanjeRukovaoca& g3) {
		return os << "GRESKA:Detalji su vec izracunati, ne moze se dodati rukovodilac " << endl;
	}
};

#endif // !_Greske_h_
