#include "Mec.h"

ostream& operator<<(ostream& os, Mec& m1) {
	if (!m1.daLiJeOdigran()) return os << "Nije Odigran";
	int s = m1.ish;
	switch (s) {
	case(0):
		return os << m1.p1 << "POBEDA_DOMACIN" << endl;
		break;
	case(1):
		return os << m1.p1 << "NERESENO" << endl;
		break;
	case(2):
		return os << m1.p1 << "POBEDA_GOST" << endl;
	}
}

Mec& Mec::odigraj() {
	odigran = true;
	if (p1.getPrvi()->getSrednjaVrednostTima() >= p1.getDrugi()->getSrednjaVrednostTima()) {
		if (p1.getPrvi()->getSrednjaVrednostTima() == p1.getDrugi()->getSrednjaVrednostTima()) ish = NERESENO;
		else {
			ish = POBEDA_DOMACIN;
			for (int i = 0; i < (p1.getPrvi())->getMaxIgraca(); i++) {
				if ((*(p1.getPrvi()))[i] != nullptr)
					(*(p1.getPrvi()))[i]->promeniVrednost(10);
			}
			for (int i = 0; i < (p1.getDrugi())->getMaxIgraca(); i++) {
				if ((*(p1.getDrugi()))[i] != nullptr)
					(*(p1.getDrugi()))[i]->promeniVrednost(-10);
			}
		}

	}
	else {
		ish = POBEDA_GOST;
		for (int i = 0; i < (p1.getPrvi())->getMaxIgraca(); i++) {
			if ((*(p1.getPrvi()))[i] != nullptr)
				(*(p1.getPrvi()))[i]->promeniVrednost(-10);
		}
		for (int i = 0; i < (p1.getDrugi())->getMaxIgraca(); i++) {
			if ((*(p1.getDrugi()))[i] != nullptr)
				(*(p1.getDrugi()))[i]->promeniVrednost(10);
		}

	}

	return *this;
}

Par<int> Mec::getOsvojenePoene() {
	//int* a = new int();
	//int* b = new int();
	
	Par<int> lok(&x, &y);
	if (!odigran) throw GMecNijeOdigran();
	if (ish == POBEDA_DOMACIN) {
		x = 3; y = 0;

		return lok;
	}
	else if (ish == POBEDA_GOST) {
		y = 3; x = 0;
		return lok;
	}
	else {
		x = 1; y = 1;
		return lok;
	}

}
