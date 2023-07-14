#include "Korisnik.h"
#include "VremenskaOznaka.h"
#include "ElektronskaPoruka.h"
#include "ElektronskaPorukaSaTekstom.h"
#include "Lista.h"


int main() {
	try {

		Korisnik k1("Mirko", "mik@email.com");
		Korisnik k2("pera", "peki@gmail.com");
		Korisnik k3("zika", "ziakika@gmail.com");
		Korisnik k4("laza", "laki@gmail.com");

		cout << k1 << k2;

		VremenskaOznaka v1(2020, 12, 12, 20, 45), v2(2021, 9, 8, 10, 25);
		cout << v1 << v2;

		elPorukaSaTekstom el1(k1, k2, "Prva poruka");

		el1.postaviText("lmaorofl");

		cout << el1 << endl;
		el1.postaviText("sledeci text");
		cout <<el1<< endl;
		el1.posaljiPoruku();
		//el1.postaviText("nece");

		elPorukaSaTekstom el2(k3, k4, "Druga Poruka");
		elPorukaSaTekstom* el3 = el1.kopiraj();

		cout << el2 << endl;
		

		cout << el2;
		cout << *el3;

		Lista<Korisnik&>l1;
		cout << l1.getBrElemenata() << endl;;
		l1.dodajNaKraj(k1);
		l1.dodajNaKraj(k3);

		int br = l1.getBrElemenata();
		cout << br << endl;

		l1.staviNaPocetak();
		cout<<l1.daLiPostojiTek();
		Korisnik &k5 = l1.dohvatiT();
		cout << k5 << endl;
		l1.predjiNaSledeci();
		l1.predjiNaSledeci();
		//cout<<l1.daLiPostojiTek();
		//l1.dohvatiT();


	}
	catch (GVecPoslataPoruka & g1) {
		cout << g1;
	}
	catch (GNePostojiTekEl & g2) {
		cout << g2;
	}
	catch (...) {
		cout << "GRESKA:Neocekivan sled dogadjaja";
	}

}