#ifndef _Rukovalac_h_
#define _Rukovalac_h_

class Posiljka;

class Rukovalac {
public:
	virtual Posiljka& obradaPosiljke(Posiljka& p1) = 0;
	virtual ~Rukovalac(){}
};

#endif // !_Rukovalac_h_
