/* Fatih Dursun Üzer
4. Ödev Çalışması
 18120205041 
 25 MART 2019
 */
#include <iostream>
#include "kayit.h"
#include <string>
#include <vector>

using namespace std;
//Program kucuk buyuk harf duyarsızdır.
//Kelime ve o kelimeye ait tum aciklamalari satir satir ekrana yazar.
ostream & operator<<(ostream & outStream, const Kayit & kayit)
{
	outStream << "Kelime: " << kayit.kelime << endl;
	outStream << "Aciklamalar: ";
	for (int i = 0; i < kayit.aciklama.size(); ++i)
	{
		outStream << kayit.aciklama.at(i)<<endl;
	}
	return outStream;
}
// getline ile satır satır veri okunur. İlk satır kelimedir, diğer her bir satır bir açıklamadır.
	// Boş açıklama geldiğinde çıkar.
istream & operator>>(istream & inStream, Kayit & kayit) 
{
	cout << "Kelimeyi giriniz" << endl;
	getline(inStream, kayit.kelime);
	string aciklamalar;
	cout << "Aciklamalari giriniz " << endl;
	getline(inStream, aciklamalar);
	while (aciklamalar != "")
	{
		kayit.aciklama.push_back(aciklamalar);
		getline(inStream, aciklamalar);
	}
	return inStream;
}
/* Sozlukteki her bir kayıt bir kelime ve o kelimeye ait aciklamalari icerir.
	Bu yapici(constructor) fonksiyon bir kelime icin tek bir aciklama metni alir.*/
Kayit::Kayit(const string & kelime, const string & aciklama)
{
	this->kelime = kelime;
	this->aciklama.push_back(aciklama);
}
//Bir kelimenin birden cok anlami/aciklamasi olabilir. Bu yapici aciklamalarin bir vektorunu alir.*/
Kayit::Kayit(const string & kelime, const vector<string>& aciklamalar)
{
	this->kelime = kelime;
	for (int i = 0; i < aciklamalar.size(); ++i)
	{
		aciklama.push_back(aciklamalar.at(i));
	}
}
// Eger iki kaydin kelime degerleri esit ise aciklama vektorlerinin birlesim kumesi olusturulur.
	// Ayni aciklama yeni kayitta birden cok kez bulunamaz!
const Kayit & Kayit::operator+(const Kayit & digerKayit)
{
	int boyut = aciklama.size();
	if (kelime == digerKayit.kelime)
	{
		for (int i = 0; i < digerKayit.aciklama.size(); ++i)
		{
			for (int j = 0; j < boyut; ++j)
			{
				if (aciklama.at(j) == digerKayit.aciklama.at(i))
					break;
				else
				{
					if (j == boyut - 1)
						aciklama.push_back(digerKayit.aciklama.at(i));
					continue;
				}
			}
		}
		return *this;
	}
	return *this;
}
// Bir kayita daha once o kayitta olmayan yeni bir anlam/aciklama eklenebilir.
const Kayit & Kayit::operator+(const string & aciklama)
{
	int boyut = this->aciklama.size();
	for (int i = 0; i < boyut; ++i)
	{
		if (this->aciklama.at(i) == aciklama)
			return *this;
	}
	this->aciklama.push_back(aciklama);
	return *this;
}
// Bir kayitta bulunan anlam/aciklama cikartilabilir. Fonksiyon cikartilacak aciklamayi argüman olarak alır.
const Kayit & Kayit::operator -(const string &aciklama)
{
	 int boyut = this->aciklama.size();
	for (int i = 0; i < boyut; ++i)
	{
		if (this->aciklama.at(i) == aciklama)
		{
			this->aciklama.erase(this->aciklama.begin() + i);
			return *this;
		}		
	}
	return *this;
}
// Bir kayit bossa (kelime == "" veya hic aciklamasi yoksa) dogru yoksa yanlis donderir
bool Kayit:: operator!()// Bir kayit bossa (kelime == "" veya hic aciklamasi yoksa) dogru yoksa yanlis donderir
{
	if ((kelime == "") || (aciklama.size() == 0) || (this->aciklama.at(0) == ""))
		return true;
	else
		return false;
}
// Eger iki kaydin kelimeleri ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
	// Bir kelimenin aciklamasi tek bir kelime ise o kelime ile esanlamlidir.
bool Kayit::operator==(const Kayit & digerKayit)
{
	vector<Kayit> found;
	string bosluk = " ";
	// eğer bu iki kelime aynıysa ya da açıklamalarında birisi varsa doğru dönderir .
	if (kelime == digerKayit.kelime)
		return true;
	else if (kelime != digerKayit.kelime)
	{
		for (int i = 0; i < aciklama.size(); ++i)
		{
			if (aciklama.at(i) == digerKayit.kelime)
			{
				found.push_back(aciklama.at(i));
				if (bosluk.find(aciklama.at(i)) == string::npos)
				{
					return true;
				}
			}
		}
		for (int i = 0; i < digerKayit.aciklama.size(); ++i)
		{
			if (digerKayit.aciklama.at(i) == kelime)
			{
				found.push_back(digerKayit.aciklama.at(i));
				if (bosluk.find(digerKayit.aciklama.at(i)) == string::npos)
				{
					return true;
				}
			}
		}
	}
	return false;
}
// Eger kaydin kelimesi verilen kelime ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
	// Bir kelimenin aciklamasi tek bir kelime ise o kelime ile esanlamlidir.
bool Kayit::operator==(const string& digerKelime)
{
	string bosluk = " ";
	if (kelime == digerKelime)
		return true;
	else if (kelime != digerKelime)
	{
		vector<string>found;
		for (int i = 0; i < aciklama.size(); ++i)
		{
			if (aciklama.at(i) == digerKelime)
			{
				found.push_back(aciklama.at(i));
				if (bosluk.find(aciklama.at(i)) == string::npos)
				{
					return true;
				}
			}
		}
	}
	return false;
}