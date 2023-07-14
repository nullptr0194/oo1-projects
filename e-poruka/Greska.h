#ifndef _Greska_h_
#define _Greska_h_
#include <iostream>
using namespace std;

class GVecPoslataPoruka {
	friend ostream& operator<<(ostream& os, GVecPoslataPoruka& g1) {
		return os << "GRESKA: Poruka je vec poslata, ne moze se sad menjati tekst" << endl;
	}	
};

class GNePostojiTekEl {
	friend ostream& operator<<(ostream& os, GNePostojiTekEl g2) {
		return os << "GRESKA: Ne postojji tekuci element u momentu dohvatanja" << endl;
	}
};

#endif // !_Greska_h_

