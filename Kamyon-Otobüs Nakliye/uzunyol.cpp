/*Fatih Dursun Uzer
18120205041
Ýstanbul Medeniyet Üniversitesi
Odev-8
uzunyol.cpp
07.06.2019*/

#include "uzunyol.h"
#include <sstream>

using namespace std;


Surucu::Surucu()
{
	ad = nullptr;
	elemanSayisi = 0;
	yas = NULL;
}

Surucu::Surucu(const char * ad,const string ehliyet, const string yas)
{
	setAd(ad);
	i = stoi(yas);
	this->yas = i + 32;
	if (ehliyet == "B")
		this->ehliyet = B;
	if (ehliyet == "C")
		this->ehliyet = C;
	if (ehliyet == "D")
		this->ehliyet = D;
	if (ehliyet == "E")
		this->ehliyet = E;
}


char Surucu::getEhliyet() const
{
	return (static_cast<char>('B'+ehliyet));
}

unsigned int Surucu::getYas() const
{
	return yas;
}

Surucu::~Surucu()
{
	if (ad != nullptr)
	{
		delete[] ad;
		ad = nullptr;
	}
}

Surucu::Surucu(const Surucu & diger)
{
	setAd(diger.ad);
	setYas(diger.yas);
	setEhliyet(diger.ehliyet);
}

void Surucu::setAd(const char * ad)
{
	elemanSayisi = strnlen_s(ad, 100);
	if (elemanSayisi > 0)
	{
		this->ad = new char[elemanSayisi + 1];
		if (this->ad == nullptr)
		{
			cout << "Hafýzada yer alýnamadý " << endl;
			 throw ERROR();
		}
		for (auto i = 0; i < elemanSayisi; ++i)
		{
			this->ad[i] = ad[i];
		}
		this->ad[elemanSayisi] = NULL;
	}
}

void Surucu::setYas(unsigned int yas)
{
	this->yas = yas;
	return;
}

void Surucu::setEhliyet(ehliyetSinifi ehliyet)
{
	this->ehliyet = ehliyet;
	return;
}


Surucu& Surucu::operator=(const Surucu& diger)
{
	if (this == &diger)
		return *this;
	if (ad != nullptr)
		delete[] ad;
	elemanSayisi = diger.elemanSayisi;
	ad = new char[elemanSayisi+1];
	if (ad == nullptr)
	{
		cout << "Hafýzada yer alýnamadý " << endl;
		 throw ERROR();
	}
	for (auto i = 0; i < elemanSayisi; ++i)
	{
		ad[i] = diger.ad[i];
	}
	ad[elemanSayisi] = NULL;

	setEhliyet(diger.ehliyet);
	setYas(diger.yas);
	return *this;
}

ostream & operator<<(ostream & out, const Surucu & yeni)
{
	if (yeni.elemanSayisi > 0)
	{
		out << "Surucunun ismi: ";
		for (auto i = 0; i < yeni.elemanSayisi; ++i)
		{
			out << yeni.ad[i];
		}
		out << endl;
		out << "Surucunun yasi: " << yeni.yas << endl;
		out << "Ehliyet turu: " << (static_cast<char>('B' + yeni.ehliyet)) << endl;
	}

	return out;
}

ostream & operator<<(ostream & out, const Yolcu & yeniYolcu)
{
	if (yeniYolcu.elemanSayisiAd > 0 && yeniYolcu.elemanSayisiBinis > 0)
	{
		out << "Yolcunun ismi :";
		for (auto i = 0; i < yeniYolcu.elemanSayisiAd; ++i)
		{
			out << yeniYolcu.ad[i];
		}
		out << endl;
		out << "Yolcunun bindigi yer :";
		for (auto i = 0; i < yeniYolcu.elemanSayisiBinis; ++i)
		{
			out << yeniYolcu.binisYeri[i];
		}
		out << endl;
		out << "Yolcunun inis yaptigi yer :" << yeniYolcu.inisYeri << endl;
	}
	return out;
}

ostream & operator<<(ostream & out, const Yuk & yeniYuk)
{
	if (yeniYuk.icerikElemanSayisi > 0)
	{
		out << "icerik :";
	for (auto i = 0; i < yeniYuk.icerikElemanSayisi; ++i)
		out << yeniYuk.icerik[i];
	out << endl;
	out << "icerigin agirligi : " << yeniYuk.agirlik << endl;
	out << "icerigin hacimi : " << yeniYuk.hacim << endl;
	out << "Alicinin ismi : " << yeniYuk.alici << endl;
	out << "icerigin binis yeri : " << yeniYuk.binisYeri << endl;
	out << "icerigin inis yeri : " << yeniYuk.inisYeri << endl;
    }
		return out;
}

ostream & operator<<(ostream & out, const Arac &yeniArac)
{
	yeniArac.print(out);
	return out;
}

ostream & operator<<(ostream & out, const Otobus & yeniOtobus)
{
	yeniOtobus.print(out);
	return out;
}

ostream & operator<<(ostream & out, const Kamyon & yeniKamyon)
{
	yeniKamyon.print(out);

	return out;
}

Yolcu::Yolcu()
{
	ad = nullptr;
	binisYeri = nullptr;
	inisYeri = "";
	elemanSayisiAd = 0;
	elemanSayisiBinis = 0;
}

Yolcu::Yolcu(const char * ad, const char * binisYeri, string inisYeri)
{
	setAd(ad);
	setBinisYeri(binisYeri);
	setÝnisYeri(inisYeri);
}

Yolcu::Yolcu(const Yolcu & digerYolcu)
{
	setAd(digerYolcu.ad);
	setBinisYeri(digerYolcu.binisYeri);
	setÝnisYeri(digerYolcu.inisYeri);
}

Yolcu & Yolcu::operator=(const Yolcu & digerYolcu)
{
	if (this == &digerYolcu)
		return *this;
	if (ad != nullptr)
		delete[] ad;
	elemanSayisiAd = digerYolcu.elemanSayisiAd;
	if (elemanSayisiAd > 0)
	{
		ad = new char[elemanSayisiAd+1];
		if (ad == nullptr)
		{
			cout << "Hafýzada yer alýnamadý" << endl;
			 throw ERROR();
		}
		for (auto i = 0; i < elemanSayisiAd; ++i)
			ad[i] = digerYolcu.ad[i];

		    ad[elemanSayisiAd] = NULL;
	}

	if (binisYeri != nullptr)
		delete[] binisYeri;
	elemanSayisiBinis = digerYolcu.elemanSayisiBinis;
	if (elemanSayisiBinis > 0)
	{
		binisYeri = new char[elemanSayisiBinis+1];
		if (binisYeri == nullptr)
		{
			cout << "Hafýzada yer alýnamadý" << endl;
			 throw ERROR();
		}

		for (auto i = 0; i < elemanSayisiBinis; ++i)
			binisYeri[i] = digerYolcu.binisYeri[i];

		binisYeri[elemanSayisiBinis] = NULL;
	}
	inisYeri = digerYolcu.inisYeri;

	return *this;
}

Yolcu::~Yolcu()
{
	if (ad != nullptr)
	{
		delete[] ad;
		ad = nullptr;
	}

	if (binisYeri != nullptr)
	{
		delete[] binisYeri;
		binisYeri = nullptr;
	}
}

string Yolcu::getInisYeri() const
{
	return inisYeri;
}

int Yolcu::getElemanSayisiAd() const
{
	return elemanSayisiAd;
}

int Yolcu::getElemanSayisiBinis() const
{
	return elemanSayisiBinis;
}

void Yolcu::setÝnisYeri(string inisYeri)
{
	this->inisYeri = inisYeri;
	return;
}

void Yolcu::setBinisYeri(const char * binisYeri)
{
	elemanSayisiBinis = strnlen_s(binisYeri, 1000);
	if (elemanSayisiBinis > 0)
	{
		this->binisYeri = new char[elemanSayisiBinis + 1];
		if (this->binisYeri == nullptr)
		{
			cout << "Hafýzada yer alýnamadý " << endl;
			 throw ERROR();
		}

		for (auto i = 0; i < elemanSayisiBinis; ++i)
			this->binisYeri[i] = binisYeri[i];
		this->binisYeri[elemanSayisiBinis] = NULL;
	}
}

void Yolcu::setAd(const char * ad)
{
	elemanSayisiAd = strnlen_s(ad, 1000);
	if (elemanSayisiAd > 0)
	{
		this->ad = new char[elemanSayisiAd + 1];
		if (this->ad == nullptr)
		{
			cout << "Hafýzada yer alýnamadý " << endl;
			 throw ERROR();
		}

		for (auto i = 0; i < elemanSayisiAd; ++i)
			this->ad[i] = ad[i];
		
		this->ad[elemanSayisiAd] = NULL;
	}

}

Yuk::Yuk()
{
	hacim = 0;
	agirlik = 0; 
	icerik = nullptr;
	alici = "";
	binisYeri = "";
	inisYeri = "";
	icerikElemanSayisi = 0;
}

Yuk::Yuk(const char * icerik, string alici, string agirlik, string hacim, string binisYeri, string inisYeri)
{
	setÝcerik(icerik);
	setAlici(alici);
	double d = stoi(agirlik);
	setAgirlik(d);
	double d2 = stoi(hacim);
	setHacim(d2);
	setBinisYeri(binisYeri);
	setÝnisYeri(inisYeri);
}

Yuk::Yuk(const Yuk & diger)
{
	setÝcerik(diger.icerik);
	setAlici(diger.alici);
	setAgirlik(diger.agirlik);
	setHacim(diger.hacim);
	setBinisYeri(diger.binisYeri);
	setÝnisYeri(diger.inisYeri);
}

Yuk::~Yuk()
{
	if (icerik != nullptr)
	{
		delete[] icerik;
		icerik = nullptr;
	}
	icerikElemanSayisi = 0;
}

Yuk & Yuk::operator=(const Yuk & diger)
{
	if (this == &diger)
		return *this;
	icerikElemanSayisi = diger.icerikElemanSayisi;
	
	if (icerikElemanSayisi > 0)
	{
		if (icerik != nullptr)
			delete[] icerik;
		icerik = new char[icerikElemanSayisi+1];
		if (icerik == nullptr)
		{
			cout << "Hafýzada yer alýnamadý" << endl;
			 throw ERROR();
		}

		for (auto i = 0; i < icerikElemanSayisi; ++i)
			icerik[i] = diger.icerik[i];
		icerik[icerikElemanSayisi] = NULL;

		setAlici(diger.alici);
		setAgirlik(diger.agirlik);
		setHacim(diger.hacim);
		setBinisYeri( diger.binisYeri);
		setÝnisYeri(diger.inisYeri);
	}
	return *this;
}

double Yuk::getHacim() const
{
	return hacim;
}

double Yuk::getAgirlik() const
{
	return agirlik;
}

string Yuk::getAlici() const
{
	return alici;
}

string Yuk::getBinisYeri() const
{
	return binisYeri;
}

string Yuk::getÝnisYeri() const
{
	return inisYeri;
}

void Yuk::setHacim(double hacim)
{
	this->hacim = hacim;
	return;
}

void Yuk::setAgirlik(double agirlik)
{
	this->agirlik = agirlik;
	return;
}

void Yuk::setAlici(string alici)
{
	this->alici = alici;
	return;
}

void Yuk::setBinisYeri(string binisYeri)
{
	this->binisYeri = binisYeri;
	return;
}

void Yuk::setÝnisYeri(string inisYeri)
{
	this->inisYeri = inisYeri;
}

void Yuk::setÝcerik(const char* icerik)
{
	icerikElemanSayisi = strnlen_s(icerik, 250);
	this->icerik = new char[icerikElemanSayisi+1];
	if (this->icerik == nullptr)
	{
		cout << "Hafýzada yer alýnamadý";
			 throw ERROR();
	}
	for (auto i = 0; i < icerikElemanSayisi; ++i)
		this->icerik[i] = icerik[i];
	this->icerik[icerikElemanSayisi] = NULL;
	return;
}


void Arac::print(ostream & out)const
{
	out << "Arac plakasý :" << endl;
	for (auto i = 0; i < plakaElemanSayisi; ++i)
		out << plaka[i];

	out << "Arac soforleri : " << endl;
	for (auto it = Suruculer.begin(); it != Suruculer.end(); it++)
		out << *it;
	return;
}

Arac::Arac()
{
	plaka = nullptr;
	plakaElemanSayisi = 0;
	Suruculer.clear();
}

Arac::Arac(const char * plaka, list<Surucu> Suruculer)
{
	setPlaka(plaka);
	setSuruculer(Suruculer);
}

Arac::~Arac()
{
	if (plaka != nullptr)
	{
		delete[] plaka;
		plaka = nullptr;
	}
	Suruculer.clear();
}

Arac::Arac(const Arac & digerArac)
{
	cout << "-COPY CONSTRUCTOR-" << endl;
	setPlaka(digerArac.plaka);
	setSuruculer(digerArac.Suruculer);
}

Arac & Arac::operator=(const Arac & digerArac)
{
	cout << "=OPERATORU" << endl;
	if (this == & digerArac)
		return *this;
	plakaElemanSayisi = digerArac.plakaElemanSayisi;
	if (plakaElemanSayisi > 0)
	{
		if (plaka!= nullptr)
			delete[] plaka;
		plaka = new char[plakaElemanSayisi+1];
		if (plaka == nullptr)
			 throw ERROR();
		for (auto i = 0; i < plakaElemanSayisi; ++i)
			plaka[i] = digerArac.plaka[i];
		plaka[plakaElemanSayisi] = NULL;
		setSuruculer(digerArac.Suruculer);
	}
	return *this;
}

void Arac::setPlaka(const char * plaka)
{
	plakaElemanSayisi = strnlen_s(plaka, 20);
	this->plaka = new char[plakaElemanSayisi+1];
	if (this->plaka == nullptr)
	{
		cout << "Hafýzada yer alýnamadý " << endl;
		 throw ERROR();
	}

	for (auto i = 0; i < plakaElemanSayisi; ++i)
		this->plaka[i] = plaka[i];
	this->plaka[plakaElemanSayisi] = NULL;
}

void Arac::setSuruculer(list<Surucu> Suruculerr)
{
	this->Suruculer.clear();

		for (auto it = Suruculerr.begin(); it != Suruculerr.end(); ++it)
			this->Suruculer.push_back(*it);
	return;
}

void Otobus::print(ostream & out) const
{
	Arac::print(out);
	out << "Yolculari : " << endl;
	for (auto i = 0; i < Yolcular.size(); ++i)
		out << Yolcular[i] << endl;
	return;
}

Otobus::Otobus():Arac()
{
}

Otobus::Otobus(const char * plaka, list<Surucu> Suruculer, vector<Yolcu> Yolcular) :Arac(plaka,Suruculer)
{
	setYolcular(Yolcular);
}

Otobus::~Otobus()
{
}

Otobus::Otobus(const Otobus & digerOtobus):Arac(digerOtobus)
{
	setYolcular(digerOtobus.Yolcular);
}

Otobus & Otobus::operator=(const Otobus & digerOtobus)
{
	Arac::operator=(digerOtobus);
	setYolcular(digerOtobus.Yolcular);

	return *this;
}

vector<Yolcu>& Otobus::getYolcular() 
{
	return Yolcular;
}

void Otobus::setYolcular(vector<Yolcu> Yolcular)
{
	this->Yolcular.clear();
	for (auto i = 0; i < Yolcular.size(); ++i)
		this->Yolcular.push_back(Yolcular.at(i));
	return;
}


void Kamyon::print(ostream & out) const
{
	Arac::print(out);
	for (auto i = 0; i < ozluSozElemanSayisi; ++i)
		out << ozluSoz[i];

	for (auto i = 0; i < Yukler.size(); ++i)
		out << Yukler[i];
	return;
}

Kamyon::Kamyon()
{
	ozluSoz = nullptr;
	ozluSozElemanSayisi = 0;
	Yukler.clear();
}

Kamyon::Kamyon(const char* ozluSoz, const char* plaka, list<Surucu> Suruculer, vector<Yuk>Yukler):Arac(plaka,Suruculer)
{
	setOzluSoz(ozluSoz);
	setYukler(Yukler);
}

Kamyon::~Kamyon()
{
	if (ozluSoz != nullptr)
	{
		delete [] ozluSoz;
		ozluSoz = nullptr;
	}
}

Kamyon & Kamyon::operator=(const Kamyon & digerKamyon)
{
	if (this == &digerKamyon)
		return *this;
	Arac::operator=(digerKamyon);
	ozluSozElemanSayisi = digerKamyon.ozluSozElemanSayisi;
	if (ozluSozElemanSayisi > 0)
	{
		if (ozluSoz != nullptr)
			ozluSoz = nullptr;
		ozluSoz = new char[ozluSozElemanSayisi];
		if (ozluSoz == nullptr)
			throw ERROR();
		for (auto i = 0; i < ozluSozElemanSayisi; ++i)
			ozluSoz[i] = digerKamyon.ozluSoz[i];
	}
	setYukler(digerKamyon.Yukler);
		return *this;
}

Kamyon::Kamyon(const Kamyon & digerKamyon):Arac(digerKamyon)
{
	setOzluSoz(digerKamyon.ozluSoz);
	setYukler(digerKamyon.Yukler);
}

void Kamyon::setOzluSoz(const char * ozluSoz)
{
	ozluSozElemanSayisi = strnlen_s(ozluSoz, 100);
	if (ozluSozElemanSayisi > 0)
	{
		this->ozluSoz = new char[ozluSozElemanSayisi+1];
		if (this->ozluSoz == nullptr)
			 throw ERROR();
		for (auto i = 0; i < ozluSozElemanSayisi; ++i)
			this->ozluSoz[i] = ozluSoz[i];
		this->ozluSoz[ozluSozElemanSayisi] = NULL;
	}
}

char * Kamyon::getOzluSoz() const
{
	return ozluSoz;
}

void Kamyon::setYukler(vector<Yuk>Yukler)
{
	this->Yukler.clear();
	for (auto i = 0; i < Yukler.size(); ++i)
		this->Yukler.push_back(Yukler[i]);
	return;
}


