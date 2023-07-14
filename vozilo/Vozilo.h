#ifndef _Vozilo_h_
#define _Vozilo_h_
#include<string>
using namespace std;

class Vozilo {
	string model;

public:
	explicit Vozilo(const string& s1): model(s1){}
	virtual ~Vozilo() {}
	virtual double izracunajCenuPuta(double put)=0;

	friend ostream& operator<<(ostream& os, const Vozilo& v1 ) {
		return os << v1.model;
	}
};

#endif // !_Vozilo_h_

