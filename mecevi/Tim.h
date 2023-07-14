#ifndef _Tim_h_
#define _Tim_h_
#include "Igrac.h"

class Tim {
	string naziv;
	int maxIgraca;
protected: 
	Igrac** igraci;

private:
	void kopiraj(const Tim& t1);
	void premesti(Tim& t1);
	void obrisi();

public:
	Tim(const string& str, int kap):naziv(str), maxIgraca(kap){
		igraci = new Igrac*[kap];
		for (int i = 0; i < kap; i++) {
			igraci[i] = nullptr;
		}
	}
	//kopirajuci
	Tim(const Tim& t1) {
		kopiraj(t1);
	}
	Tim(Tim&& t1) {
		premesti(t1);
	}

	Tim& operator = (const Tim& t1) {
		if (this != &t1) {
			obrisi();
			kopiraj(t1);
		}
		return *this;
	}
	Tim& operator = (Tim&& t1) {
		if (this != &t1) {
			obrisi();
			premesti(t1);
		}
		return *this;
	}
	virtual ~Tim() {
		obrisi();
	}


	int getMaxIgraca()const { return maxIgraca; }

	int getTrenutnoIgraca() const;

	virtual Tim& staviNaPoziciju(Igrac* i1, int pozicija);

	Igrac* operator[](int i);

	const Igrac* operator[](int i) const;

	double getSrednjaVrednostTima() const;

	friend bool operator==(const Tim& t1, const Tim& t2);
protected:
	virtual void pisi(ostream& os)const;

	friend ostream& operator<<(ostream& os,const Tim& t1) {
		os << t1.naziv; t1.pisi(os);
		return os;
	}

};



#endif // !_Tim_h_

