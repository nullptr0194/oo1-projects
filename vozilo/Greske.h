#ifndef _Greske_h_
#define _Greske_h_
#include <iostream>
using namespace std;

class GNePostojiElNaPoziciji {
	friend ostream& operator<<(ostream& os, GNePostojiElNaPoziciji& g1) {
		return os << "GRESKA:Podatak na zadatoj poziciji ne postoji " << endl;
	}
};
class GVecPostojiTaTacka {
	friend ostream& operator<<(ostream& os, GVecPostojiTaTacka& g2) {
		return os << "GRESKA:Ta tacka je vec dodata " << endl;
	}
};

#endif // !_Greske_h_