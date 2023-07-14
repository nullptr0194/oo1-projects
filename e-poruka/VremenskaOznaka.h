#ifndef _VremenskaOznaka_h_
#define _VremenskaOznaka_h_

#include <iostream>
using namespace std;

class VremenskaOznaka{
private:
	int godina, mesec, dan, sati, minuti;

public:
	VremenskaOznaka(int god, int mes, int  d, int s, int m): godina(god), mesec(mes), dan(d), sati(s), minuti(m){}

	void pisi(ostream& os)const {
		os << godina << "." << mesec << "." << dan << "-" << sati << ":" << minuti << endl;
	}
	friend ostream& operator <<(ostream& os, const VremenskaOznaka& oz) {
	oz.pisi(os);
		return os;
	}

};


#endif // !_VremenskaOznaka_h_

