#include "Igrac.h"

Igrac& Igrac::promeniVrednost(double procenat) {
	vrednost = vrednost + vrednost * procenat / 100;
	return *this;
}

bool operator==(Igrac& i1, Igrac& i2) {
	if (i1.ime == i2.ime && i1.vrednost == i2.vrednost) return 1;
	else return 0;
}
