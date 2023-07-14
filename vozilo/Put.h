#ifndef _Put_h_
#define _Put_h_
#include"Tacka.h"
#include"Lista.h"
class Put {
	Lista<Tacka> l1;

public:
	Put(){}
	Put& operator+=(const Tacka& t1);

	double izracunajDuzinuPuta();

	friend ostream& operator<<(ostream& os, Put& p1);

};


#endif // !_Put_h_
