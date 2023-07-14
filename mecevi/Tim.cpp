#include "Tim.h"

void Tim::kopiraj(const Tim& t1)
{
	naziv = t1.naziv;
	maxIgraca = t1.maxIgraca;

	igraci = new Igrac * [maxIgraca];
	for (int i = 0; i < maxIgraca; i++) {
		igraci[i] = new Igrac(*t1.igraci[i]);
	}


	
}

void Tim::premesti(Tim& t1)
{
	naziv = t1.naziv;
	maxIgraca = t1.maxIgraca;
	igraci = t1.igraci;
	t1.igraci = nullptr;

}

void Tim::obrisi()
{
	for (int i = 0; i < maxIgraca; i++) {
		delete igraci[i];
	}
	delete[] igraci;
	maxIgraca = 0;
	naziv = "";
}

int Tim::getTrenutnoIgraca() const {
	int tr = 0;
	for (int i = 0; i < maxIgraca; i++) {
		if (igraci[i] != nullptr) tr++;
	}
	return tr;
}

Tim& Tim::staviNaPoziciju(Igrac* i1, int pozicija) {
	if (!(pozicija > maxIgraca || pozicija < 0)) {
		igraci[pozicija] = new Igrac(*i1);
	}
	return *this;
}

Igrac* Tim::operator[](int i) {
	if (!(i > maxIgraca || i < 0))
		return igraci[i];
}

const Igrac* Tim::operator[](int i) const {
	if (!(i > maxIgraca || i < 0))
		return igraci[i];
}

double Tim::getSrednjaVrednostTima() const {
	int sum = 0;
	for (int i = 0; i < maxIgraca; i++) {
		if (igraci[i])
			sum += igraci[i]->getVrednost();
	}
	if (sum) {
		return sum / getTrenutnoIgraca();
	}
	else return 0;
}

void Tim::pisi(ostream& os) const {
	int ind = 0;
	os << "[";
	for (int i = 0; i < maxIgraca; i++) {
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

bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.maxIgraca != t2.maxIgraca || t1.naziv != t2.naziv) return 0;
	else {
		for (int i = 0; i < t1.maxIgraca; i++) {
			if (t1.igraci[i] == nullptr && t2.igraci[i] != nullptr) return 0;
			if (t2.igraci[i] == nullptr && t1.igraci[i] != nullptr) return 0;
			if (t1.igraci[i] == nullptr && t2.igraci[i] == nullptr) continue;
			if (!(*(t1.igraci[i]) == *(t2.igraci[i]))) return 0;
		}
		return true;
	}
}