#ifndef _Tacka_h_
#define _Tacka_h_
#include<iostream>
#include<cmath>
#include "Lista.h"
using namespace std;

class Tacka {
	int x, y;
public:
	Tacka(int a, int b): x(a), y(b){}

	double IzracunajUdaljenost(Tacka& t2) const {
		return sqrt(pow(x - t2.x, 2) + pow(y - t2.y, 2));
	}
	friend bool operator ==(const Tacka& t1,const Tacka& t2) {
		if (t1.x == t2.x && t1.y == t2.y) return 1;
		return 0;
	}
	friend ostream& operator<<(ostream& os, Tacka& t1) {
		return os << "(" << t1.x << "," << t1.y << ")" << endl;
	}
};


#endif // !_Tacka_h_
