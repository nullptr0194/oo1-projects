#ifndef _ElektronskaPorukaSaTekstom_h_
#define _ElektronskaPorukaSaTekstom_h_
#include "ElektronskaPoruka.h"
#include"Greska.h"
using namespace std;

class elPorukaSaTekstom : public ElektronskaPoruka {
private:
	string text;
public:
	elPorukaSaTekstom(Korisnik& k1, Korisnik& k2, string ime) : ElektronskaPoruka(k1, k2, ime) {}
	void postaviText(const string txt) {
		if (this->getStanje() == POSLATA) throw GVecPoslataPoruka();
		this->text = txt; 
	}
	void posaljiPoruku() override {
		this->stanje = POSLATA;
	};
	elPorukaSaTekstom* kopiraj() override {
			return new elPorukaSaTekstom(*this);
	}
protected:
	void pisi(ostream& os)const override {
		ElektronskaPoruka::pisi(os); 
		os << this->text << endl;
	}
};



#endif // !_ElektronskaPorukaSaTekstom_h_

