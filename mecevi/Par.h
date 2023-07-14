#ifndef _Par_h_
#define _Par_h_
#include<iostream>
using namespace std;

template <typename T>
class Par {
	T* prvi, * drugi;
public:
	Par(T* a, T*b):prvi(a), drugi(b){}

	T* getPrvi()const { return prvi; }
	T* getDrugi()const { return drugi; }

	T& setPrvi(T* p1) { return prvi = p1; }
	T& setDrugi(T* p2) { return drugi = p2; }

	friend bool operator==(Par& p1, Par& p2) {
		if (*(p1.getPrvi()) == *(p1.getDrugi())) return 1;
		else return 0;
	}

	friend ostream& operator<<(ostream& os, Par& p1) {
		return os << "[" << *(p1.getPrvi()) << "-" << *(p1.getDrugi()) << "]" << endl;
	}
};



#endif // !_Par_h_


