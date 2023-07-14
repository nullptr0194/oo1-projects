#ifndef _Lista_h_
#define _Lista_h_
#include <iostream>
#include"Greska.h"
using namespace std;
template<typename T>

class Lista {

	struct Elem {
		T pod;
		Elem* sledeci;
		Elem(const T& p):pod(p) {
			sledeci = nullptr;
		}
	};
	
	Elem* prvi = nullptr, * poslednji = nullptr;
	mutable Elem* tekuci = nullptr;
	int brEl = 0;

	void premesti(Lista& l1) {
		prvi = l1.prvi;
		poslednji = l1.poslednji;
		l1.prvi = nullptr;
		l1.poslednji = nullptr;
	}
	void kopiraj(const Lista& l1) {
		prvi = poslednji = tekuci = nullptr;
		brEl = l1.brEl;

		for (Elem* pok = l1.prvi; pok; pok = pok->sledeci) {
			Elem* novi = new Elem(pok->pod);
			if (!prvi) {
				poslednji = prvi = novi;
			}
			else {
				poslednji = poslednji->sledeci = novi;
			}

			if (pok == l1.tekuci) tekuci = novi;
		}


	}
	void obrisi() {
		brEl = 0;
		while (prvi) {
			Elem* prethodni = prvi;
			prvi = prvi->sledeci;
			delete prethodni;
		}
		poslednji = tekuci = nullptr;
	}

public:
	Lista() {};

	Lista(const Lista& l1) {
		kopiraj(l1);
	}
	Lista(Lista&& l1) {
		premesti(l1);
	}
	Lista& operator = (const Lista& l1) {
		if (this != &l1) {
			obrisi();
			kopiraj(l1);
		}
		return *this;
	}
	Lista& operator = (Lista&& l1) {
		if (this != &l1) {
			obrisi();
			premesti(l1);
		}
		return *this;
	}
	~Lista() {
		obrisi();
	}

	int getBrElemenata() {
		return this->brEl;
	}

	Lista& dodajNaKraj(const T& t) {
		if (!prvi) {
			poslednji = prvi = new Elem(t);
		}
		else {
			poslednji = poslednji->sledeci = new Elem(t);
		}
		brEl++;
		return *this;
	}

	Lista& staviNaPocetak() {
		tekuci = prvi;
		return *this;
	}
	const Lista& staviNaPocetak() const {
		tekuci = prvi;
		return *this;
	}
	Lista& predjiNaSledeci() {
		if(tekuci) tekuci = tekuci->sledeci;
		return* this;
	}
	const Lista& predjiNaSledeci() const {
		if (tekuci) tekuci = tekuci->sledeci;
		return*this;
	}
	bool daLiPostojiTek() const {
		return tekuci != nullptr;
	}

	T& dohvatiT() {
		if (!tekuci) throw GNePostojiTekEl();
		return tekuci->pod;
	}
	const T& dohvatiT() const {
		if (!tekuci) throw GNePostojiTekEl();
		return tekuci->pod;
	}

	};
	

#endif // !_Lista_h_

