#ifndef _Mec_h_
#define _Mec_h_
#include"Tim.h"
#include"Par.h"
#include"Greske.h"

enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };

class Mec {
	Par<Tim> p1;
	Ishod ish;
	bool odigran;
	int x, y;
public:

	explicit Mec(Par<Tim> par1) :p1(par1) {
		odigran = false;
	}

	Par<Tim> getPar()const { return p1; }

	bool daLiJeOdigran()const { return odigran; }

	Mec& odigraj();


	Par<int> getOsvojenePoene();

	friend ostream& operator<<(ostream& os, Mec& m1);
};


#endif // !_Mec_h_


