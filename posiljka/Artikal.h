#ifndef _Artikal_h_
#define _Artikal_h_
#include<iostream>
#include<string>
using namespace std;

class Artikal {
	string naziv;
	int barkod;
	double nabavnaCena;
public:
	Artikal(string naz, int bkod, double ncen) : naziv(naz), barkod(bkod), nabavnaCena(ncen) {}
	string getNaziv()const { return naziv; }
	int getBarkod()const { return barkod; }
	double getNabavna()const { return nabavnaCena; }

	friend bool operator ==(const Artikal& a1, const Artikal& a2) {
		if (a1.barkod == a2.barkod)  return 1;
			return 0;
	}
};

#endif // !_Artikal_h_

