/*#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Igrac.h"
#include "PrivilegovaniTim.h"
#include "Mec.h"
#include "Par.h"*/
#include <iostream>
using namespace std;

class A {
	static int stID;
	int ID = ++stID;
public:
	A() {}
	A(const A& a) {}
	A(A&& a) {}
	~A() { cout << ID; }
};

int A::stID = 0;

void f1(A& a) {}
void f2(A a) {}

int main() {
	A x;
	for (int i = 0; i < 3; i++) {
		A* y = new A;
		if (i == 1) f2(*y);
		if (i == 2) f1(*y);
	}
	return 0;
}