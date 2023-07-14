#ifndef _PrivilegovaniTim_h_
#define _PrivilegovaniTim_h_
#include"Tim.h"
#include"Greske.h"

class PrivilegovanTim:public Tim {
	int minimalnaVrednost;

	void pisi(ostream& os)const override;
public:
	PrivilegovanTim(int minv, const string& str, int kap):Tim(str, kap), minimalnaVrednost(minv){}
	//opet oni silni konstruktori

	PrivilegovanTim& staviNaPoziciju(Igrac* i1, int pozicija) override;
};


#endif // !_PrivilegovaniTim_h_

