#include<iostream>
#include"18120205041LW08.h"
#include<string>
unsigned int Sekil::olusturulmuSekilSayisi = 0;
using namespace std;

int main()
{
	int secim;
	cout << "\t\t HOSGELDINIZ!" << endl;
	cout << "Lutfen olusturmak istediginiz seklin numarasini giriniz." << endl;
	cout << "\t0:Cikis, 1 : Ucgen, 2 : Kare, 3 Dikdortgen" << endl;
	string sekilAdi;
	double kenar1, kenar2, kenar3;
	Sekil* sPtr;
	while (1) {
		cout << "Secim yapin lutfen" << endl;
		cin >> secim;
		switch (secim)
		{
		case 0:
			cout << Sekil::olusturulmuSekilSayisi << endl;
			exit(1);
		case 1:
			sekilAdi = "Ucgen";
			cout << "Lutfen kenar uzunluklarini giriniz:" << endl;
			cin >> kenar1 >> kenar2 >> kenar3;
			sPtr = new Ucgen(sekilAdi, kenar1, kenar2, kenar3);
			sPtr->bilgiYazdýr();
			cout << "Alani: " << sPtr->alan() << endl;
			cout << "Cevresi: " << sPtr->cevre() << endl;
			delete sPtr;
			break;
		case 2:
			sekilAdi = "Kare";
			cout << "Lutfen kenar uzunlugunu giriniz:" << endl;
			cin >> kenar1;
			sPtr = new Kare(sekilAdi, kenar1);
			sPtr->bilgiYazdýr();
			cout << "Alani: " << sPtr->alan() << endl;
			cout << "Cevresi: " << sPtr->cevre() << endl;
			delete sPtr;
			break;
		case 3:
			sekilAdi = "Dikdortgen";
			cout << "Lutfen kenar uzunluklarini giriniz:" << endl;
			cin >> kenar1 >> kenar2;
			sPtr = new Dikdortgen(sekilAdi, kenar1, kenar2);
			sPtr->bilgiYazdýr();
			cout << "Alani: " << sPtr->alan() << endl;
			cout << "Cevresi: " << sPtr->cevre() << endl;
			delete sPtr;
			break;
		default:
			cout << "Yanlis Secim!\nTekrar ";

		}
	}

	return 0;
}