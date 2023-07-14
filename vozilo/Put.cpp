#include"Put.h"

Put& Put::operator+=(const Tacka& t1){
	for (int i = 0; i < l1.getBrElemenata(); i++) {
		if (t1 == l1[i]) throw GVecPostojiTaTacka();
	}
	l1 += t1;
}

double Put::izracunajDuzinuPuta()
{
	double sum = 0;
	for (int i = 0; i < l1.getBrElemenata() - 1; i++) {
		sum += l1[i].IzracunajUdaljenost(l1[i + 1]);
	}
	return sum;
}

ostream& operator<<(ostream& os, Put& p1)
{
	for (int i = 0; i < p1.l1.getBrElemenata(); i++)
		os << p1.l1[i];
	return os;
}