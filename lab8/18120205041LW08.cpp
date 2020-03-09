#include "18120205041LW08.h"
Sekil::Sekil()
{
	++olusturulmuSekilSayisi;
}

Sekil::Sekil(string& ad)
{
	this->ad = ad;
	++olusturulmuSekilSayisi;
}

Sekil::~Sekil()
{
	cout << "Dest-Sekil" << endl;
}

void Sekil::bilgiYazdýr()
{
	cout << "Adi: " << ad << endl;
}

string Sekil::getAd()
{
	return ad;
}



Ucgen::Ucgen() : Sekil()
{
}

Ucgen::Ucgen(string & ad, double k1, double k2, double k3) : Sekil(ad)
{
	kenarlar[0] = k1;
	kenarlar[1] = k2;
	kenarlar[2] = k3;

}

Ucgen::~Ucgen()
{
	cout << "Dest-Ucgen" << endl;

}

double Ucgen::alan()
{
	double u = (kenarlar[0] + kenarlar[1] + kenarlar[2]) / 2;
	return sqrt(u*abs((u - kenarlar[0]))*abs((u - kenarlar[1]))*abs((u - kenarlar[2])));
}

double Ucgen::cevre()
{
	return kenarlar[0] + kenarlar[1] + kenarlar[2];
}

void Ucgen::bilgiYazdýr()
{
	Sekil::bilgiYazdýr();
	cout << "Kenarlar " << kenarlar[0] << ", " << kenarlar[1] << ", " << kenarlar[2] << endl;
}

Dortgen::Dortgen() : Sekil()
{
}

Dortgen::Dortgen(string & ad) : Sekil(ad)
{
}

Dortgen::~Dortgen()
{
	cout << "Dest-Dortgen" << endl;

}

Kare::Kare() : Dortgen()
{
}

Kare::Kare(string & ad, double a) : Dortgen(ad)
{
	this->a = a;
}

Kare::~Kare()
{
	cout << "Dest-Kare" << endl;

}

double Kare::alan()
{
	return a * a;
}

double Kare::cevre()
{
	return a * 4;
}

void Kare::bilgiYazdýr()
{
	Sekil::bilgiYazdýr();
	cout << "Kenar " << a << endl;
}

Dikdortgen::Dikdortgen() : Dortgen()
{
}

Dikdortgen::Dikdortgen(string & ad, double a, double b) : Dortgen(ad)
{
	this->a = a;
	this->b = b;
}

Dikdortgen::~Dikdortgen()
{
	cout << "Dest-Dikdortgen" << endl;

}

double Dikdortgen::alan()
{
	return a * b;
}

double Dikdortgen::cevre()
{
	return 2 * (a + b);
}

void Dikdortgen::bilgiYazdýr()
{
	Sekil::bilgiYazdýr();
	cout << "Kenarlar " << a << ", " << b << endl;
}