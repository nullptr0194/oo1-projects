#ifndef _korisnik_h_
#define _korisnik_h_

#include <iostream>
#include <string>

using namespace std;

class Korisnik {
private:
	string ime;
	string ePosta;
public:
	Korisnik(string im, string mail) : ime(im), ePosta(mail){}

	string getIme()const { return ime; }
	string getePosta()const { return ePosta; }

	void pisi(ostream& os)const {
		os << "(" << getIme() << ")" << getePosta() << endl;
	}
	friend ostream& operator <<(ostream& os, const Korisnik& k) {
		k.pisi(os);
		return os;
	}

	Korisnik(const Korisnik& k1) = delete;
	Korisnik& operator=(const Korisnik&) = delete;

};

#endif // !_korisnik_h_

