#include "PrivilegovaniTim.h"

void PrivilegovanTim::pisi(ostream& os) const {
	int ind = 0;
	os << "(" << minimalnaVrednost << ")";
	os << "[";
	for (int i = 0; i < this->getMaxIgraca(); i++) {
		if (igraci[i] != nullptr) {
			if (!ind) {
				os << *(igraci[i]);
				ind++;
			}
			else {
				os << "," << *(igraci[i]);
			}
		}
	}
	os << "]";
}

PrivilegovanTim& PrivilegovanTim::staviNaPoziciju(Igrac* i1, int pozicija) {
	if (!(pozicija > this->getMaxIgraca() || pozicija < 0)) {
		if (i1->getVrednost() < minimalnaVrednost) throw GMalaVrednosIgraca();
		igraci[pozicija] = new Igrac(*i1);
	}
}
