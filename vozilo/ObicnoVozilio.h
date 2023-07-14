#ifndef _ObicnoVozilo_h_
#define _ObicnoVozilo_h_
#include"Vozilo.h"

class ObicnoVozilo :public Vozilo {

public:
	explicit ObicnoVozilo(const string& s1):Vozilo(s1){}
	double izracunajCenuPuta(double put) override {
		return 120 + put * 0.1;
	}

};

#endif // _ObicnoVozilo_h_
