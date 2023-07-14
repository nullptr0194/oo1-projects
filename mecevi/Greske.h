#ifndef _Greske_h_
#define _Greske_h_
#include <iostream>
using namespace std;

class GMalaVrednosIgraca {
	friend ostream& operator<<(ostream& os, GMalaVrednosIgraca& g1) {
		return os << "GRESKA:Vrednost igraca manja od minimalne da bi se prikljucio timu " << endl;
	}
};
class GMecNijeOdigran {
	friend ostream& operator<<(ostream& os, GMecNijeOdigran& g2) {
		return os << "GRESKA:Mec nije odigran " << endl;
	}
};


#endif // !_Greske_h_
