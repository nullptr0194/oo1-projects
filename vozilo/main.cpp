#include "Put.h"
#include "Lista.h"
#include "ObicnoVozilio.h"

int main() {
	try {

		Tacka t1(3, 4), t2(1, 2), t3(0, 0), t4(1, 1), t5(1, 1);

		int x = t1 == t2;
		int y = t4 == t5;
		cout << t1 << x << "..." << y << endl;

		cout << t4.IzracunajUdaljenost(t3)<<endl;

		Lista<Tacka>l1;
		l1 += t1;
		l1 += t2;
		l1 += t3;

		Tacka tx = l1[2];
		cout << tx << endl;

		Put p1;
		p1 += t1;
		p1 += t2;
		p1 += t3;
		cout << p1;
		cout << p1.izracunajDuzinuPuta()<<endl;

		ObicnoVozilo punto("fiat punto");

		double k = punto.izracunajCenuPuta(269);
		cout << k<<endl;
		cout << punto;

	}
	catch (GNePostojiElNaPoziciji& g1) {
		cout << g1;
	}
	catch (GVecPostojiTaTacka & g2) {
		cout << g2;
	}
	catch (...) {
		cout << "GRESKA:Nepredvidjena greska";
	}
}