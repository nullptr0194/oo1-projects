#ifndef _Igrac_h_
#define _Igrac_h_
#include <string>
#include<iostream>
using namespace std;

class Igrac {

	string ime;
	int vrednost;
public:
	explicit Igrac(const string& im, int cvr=1000):ime(im), vrednost(cvr){}
	
	int getVrednost()const { return vrednost; }
	
	Igrac& promeniVrednost(double procenat);

	friend bool operator ==(Igrac& i1, Igrac& i2);

	friend ostream& operator<<(ostream& os, Igrac& i1) {
		return os << i1.ime << "#" << i1.vrednost;
	}
};

#endif // !_Igrac_h_

