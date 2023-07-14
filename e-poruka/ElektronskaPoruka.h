#ifndef _ElektronskaPoruka_h_
#define _ElektronskaPoruka_h_
#include "Korisnik.h"
#include<string>
using namespace std;

enum Stanje{ U_PRIPREMI, POSLATA, PRIMLJENA };

class ElektronskaPoruka{
private:
	Korisnik& posiljaoc, &primalac;
	string naslov;
protected:
	Stanje stanje;
public:

	ElektronskaPoruka(Korisnik& k1, Korisnik& k2, string ime): posiljaoc(k1), primalac(k2), naslov(ime) {
		stanje = U_PRIPREMI;
	}
	Korisnik& getPosiljaoc()const { return posiljaoc; }
	Korisnik& getPrimalac()const { return primalac; }
	string getNaslov() const { return naslov; }
	Stanje getStanje() const { return stanje; }

	virtual ~ElektronskaPoruka() {};

	virtual void posaljiPoruku() = 0;

	virtual ElektronskaPoruka* kopiraj() = 0;
protected:
	 virtual void pisi(ostream& os)const {
		os << getNaslov()<< endl << getPosiljaoc() << getPrimalac();
	}

	friend ostream& operator <<(ostream& os, const ElektronskaPoruka& ep) {
		ep.pisi(os);
		return os;
	}




};




#endif // !_ElektronskaPoruka_h_

