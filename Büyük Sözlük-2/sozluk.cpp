/* 18120205041
FATÝH DURSUN ÜZER
5.ÖDEV ÇALIÞMASI
07.04.2019*/

#include "sozluk.h"
#include "kayit.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ostream & operator<<(ostream & o, const Sozluk & s)
{
	for (int i = 0; i < s.toplamKayitSayisi; ++i)
	{
		o << s.kayitlar[i] << endl;
	}
	o << s.toplamKayitSayisi;

	return o;
}


Sozluk::Sozluk()
{
	kayitlar = nullptr;
	toplamKayitSayisi = 0;
}

Sozluk::Sozluk(const Kayit & kayit)
{
	kayitlar = new Kayit[1];

	if (kayitlar == nullptr)
		exit(-1);
	kayitlar[0] = kayit;
	toplamKayitSayisi = 1;
}


	Sozluk::Sozluk(const vector<Kayit>& kayitlar)
	{
		vector<Kayit> temp = kayitlar; //Verilen kaydı geçici olarak tutan vector.

		for (unsigned i = 0; i < temp.size(); i++)
		{
			for (unsigned j = temp.size() - 1; j > i; j--)
			{
				if (temp[i].getKelime() == temp[j].getKelime())
				{
					temp[i] + temp[j];
					temp.erase(temp.begin() + j);
				}
			}
		}
		this->kayitlar = nullptr;
		this->kayitlar = new Kayit[temp.size()];
		if (this->kayitlar == nullptr)
			exit(-1);
		toplamKayitSayisi = temp.size();
		for (unsigned i = 0; i < toplamKayitSayisi; i++)
		{
			this->kayitlar[i] = temp[i];
		}

	}



Sozluk::Sozluk(const Sozluk & other)
{
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = nullptr;

	if (toplamKayitSayisi > 0)
	{
		kayitlar = new Kayit[toplamKayitSayisi];
		if (kayitlar == nullptr)
		{
			exit(-1);
		}

		for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
		{
			kayitlar[i] = other.kayitlar[i];
		}
	}

}

Sozluk & Sozluk::operator=(const Sozluk & other)
{
	// TODO: döndürme ifadesini buraya ekleyin
	if (this == &other)
		return *this;
	if (kayitlar != nullptr)
		delete[] kayitlar;
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = new Kayit[toplamKayitSayisi];
	if (kayitlar == nullptr)
		exit(-1);

	if (memcpy(kayitlar, other.kayitlar, toplamKayitSayisi * sizeof(Kayit)) == nullptr)
		exit(-1);

	return *this;

}

Sozluk::~Sozluk()
{
	if (kayitlar != nullptr)
		delete[] kayitlar;
}

Kayit & Sozluk::operator[](const string & kelime)
{
	for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
	{
		if (kayitlar[i].getKelime() == kelime)
		{
			return kayitlar[i];
		}
	}
}

bool Sozluk::operator==(const Sozluk & other)
{
	int aciklamaSayisi = 0;
	int aciklamaSayisi1 = 0;
	for (unsigned int i = 0; i < other.toplamKayitSayisi; ++i)
	{
		aciklamaSayisi = aciklamaSayisi + other.kayitlar[i].getAciklamaSayisi();
	}

	for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
	{
		aciklamaSayisi1 = aciklamaSayisi1 + kayitlar[i].getAciklamaSayisi();
	}

	if (aciklamaSayisi == aciklamaSayisi1)
	{
		return true;
	}
	return false;
}

int Sozluk::getToplam()
{
	return toplamKayitSayisi;
}

int Sozluk::getAciklamSayisi()const
{
	int temp = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; i++)
	{
		temp += kayitlar[i].getAciklamaSayisi();
	}
	return temp;
}

bool Sozluk::operator != (const Sozluk& other)
{
	if (*this == other)
		return true;

	return false;
}

bool Sozluk::operator>(const Sozluk & other)
{
	int aciklamaSayisi = 0;
	int aciklamaSayisi1 = 0;
	for (unsigned int i = 0; i < other.toplamKayitSayisi; ++i)
	{
		aciklamaSayisi = aciklamaSayisi + other.kayitlar[i].getAciklamaSayisi();
	}

	for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
	{
		aciklamaSayisi1 = aciklamaSayisi1 + kayitlar[i].getAciklamaSayisi();
	}

	if (aciklamaSayisi > aciklamaSayisi1)
		return true;

	return false;
}

bool Sozluk::operator<(const Sozluk & other)
{
	int aciklamaSayisi = 0;
	int aciklamaSayisi1 = 0;
	for (unsigned int i = 0; i < other.toplamKayitSayisi; ++i)
	{
		aciklamaSayisi = aciklamaSayisi + other.kayitlar[i].getAciklamaSayisi();
	}

	for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
	{
		aciklamaSayisi1 = aciklamaSayisi1 + kayitlar[i].getAciklamaSayisi();
	}

	if (aciklamaSayisi < aciklamaSayisi1)
		return true;

	return false;
}

bool Sozluk::operator<=(const Sozluk & other)
{
	if ((*this == other) || (*this < other))
		return true;

	return false;
}

bool Sozluk::operator>=(const Sozluk & other)
{
	if ((*this > other) || (*this == other))
		return true;

	return false;
}

Sozluk & Sozluk::operator+(const Sozluk & digerSozluk)
{
	toplamKayitSayisi = 1;
	for (unsigned int i = 0; i < toplamKayitSayisi; ++i)
	{
		for (unsigned int j = 0; j < digerSozluk.toplamKayitSayisi; ++j)
		{
			if ((kayitlar[i].getKelime() == digerSozluk.kayitlar[j].getKelime()))
			{
				kayitlar[i] = kayitlar[i] + digerSozluk.kayitlar[j];
			}
		}
	}
	return *this;
}


Sozluk & Sozluk::operator+=(const Sozluk & digerSozluk)
{
	*this = *this + digerSozluk;
	return *this;
}

ofstream & operator << (ofstream &o, const Sozluk &s)
{
	for (int i = 0; i < s.toplamKayitSayisi; ++i)
	{
		o << "Kelime:" << s.kayitlar[i].getKelime() << endl;
		o << "Aciklamalar:" << endl;
		for (int j = 0; j < s.getAciklamSayisi(); ++j)
		{
			o << s.kayitlar[i].getAciklama()[j] << endl;
		}
		o << endl << "********";
	}

	return o;
}

ifstream & operator >>(ifstream & in, Sozluk &s)
{
	string kelimetutan, aciklamatutan, bos, kelime, aciklama;
	vector<string>aciklamalar;
	vector<Kayit>yeniKayitlar;
	while (!in.eof())
	{
		getline(in, kelime);
		getline(in, kelimetutan);
		getline(in, aciklama, '\n');
		getline(in, aciklamatutan, '\n');

		while (aciklamatutan != "********")
		{
			aciklamalar.push_back(aciklamatutan);
			getline(in, aciklamatutan, '\n');

		}
		Kayit yeni(kelimetutan, aciklamalar);
		yeniKayitlar.push_back(yeni);
		aciklamalar.clear();
	}
	Sozluk yeniSozluk(yeniKayitlar);
	s = yeniSozluk;
	return in;

}



	 






