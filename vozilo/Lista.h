#ifndef _Lista_h_
#define _Lista_h_
#include<iostream>
#include"Greske.h"

template<typename T>

class Lista {
	struct Elem {
		T pod;
		Elem* sledeci;
		Elem(const T& p) :pod(p) {
			sledeci = nullptr;
		}
	};
	Elem* prvi = nullptr, * poslednji = nullptr;
	int brEl = 0;
	void premesti(Lista& l1) {
		prvi = l1.prvi;
		poslednji = l1.poslednji;
		l1.prvi = nullptr;
		l1.poslednji = nullptr;
	}
	void kopiraj(const Lista& l1) {
		prvi = poslednji = nullptr;
		brEl = l1.brEl;

		for (Elem* pok = l1.prvi; pok; pok = pok->sledeci) {
			Elem* novi = new Elem(pok->pod);
			if (!prvi) {
				poslednji = prvi = novi;
			}
			else {
				poslednji = poslednji->sledeci = novi;
			}

		}

	}
	void obrisi() {
		brEl = 0;
		while (prvi) {
			Elem* prethodni = prvi;
			prvi = prvi->sledeci;
			delete prethodni;
		}
		poslednji = nullptr;
	}

public:
	Lista() {};

	Lista(const Lista & l1) {
		kopiraj(l1);
	}
	Lista(Lista && l1) {
		premesti(l1);
	}
	Lista& operator = (const Lista & l1) {
		if (this != &l1) {
			obrisi();
			kopiraj(l1);
		}
		return *this;
	}
	Lista& operator = (Lista && l1) {
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

	Lista& operator+=(const T & t) {
		if (!prvi) {
			poslednji = prvi = new Elem(t);
		}
		else {
			poslednji = poslednji->sledeci = new Elem(t);
		}
		brEl++;
		return *this;
	}

	 T& operator[](int i) {
		if (i<0 || i>brEl) throw GNePostojiElNaPoziciji();
		else {
			Elem* pok = prvi;
			for(int k=0; k<i;k++){
				pok = pok->sledeci;
			}
		return pok->pod;
		}
		
	}

	const T& operator[](int i)const {
		if (i<0 || i>brEl) throw GNePostojiElNaPoziciji();
		else {
			Elem* pok = prvi;
			for (int k = 0; k < i; k++) {
				pok = pok->sledeci;
			}
		return pok->pod;
		}
		
	}



};

#endif // !_Lista_h_

