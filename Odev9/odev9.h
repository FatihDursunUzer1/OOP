/*Fatih Dursun Üzer
18120205041
9.Ödev Çalýlmasý
12 Mayýs 2019
odev9.h
Bilgisayar Mühendisliði */

#pragma once
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <new>
//#include <exception>
using namespace std;

class ERROR
{
public:
	ERROR()
	{
		throw bad_alloc();
    }

	ERROR(unsigned int a)
	{
		throw out_of_range("Dizinin kapasitesini astiniz.Dizinin kapasitesi elemanSayisi+elemanSayisi/2 den fazla olamaz.");
	}



};
template <class T>
struct Pair
{
	T eleman;
	int adet;
};// histogramda her bir elemandan kacar adet oldugunu gosterebilecek veri tipi */
template <class T>
class AkilliDizi /* TEMPLATE OLACAK */
{
	template <class T>
	friend ostream& operator<<(ostream& out, AkilliDizi<T>& dizi);
	// Dizinin tum elemanlarini ekrana basabilecek sekilde << operatorunu asiri yukleyiniz
	//TEMPLATE OLACAK
public:
	AkilliDizi(); /* bos bir akilli dizi olusturur*/
	AkilliDizi(T& i); /* tek elamanlý ve eleman degeri i olan bir akilli dizi olusturur
	TEMPLATE OLACAK*/
	AkilliDizi(const T * tDizi, unsigned int elemanSayisi); /* elemanSayisi elamanli bir
	akilli dizi olusturur ve intDizi elamanlarini akilli diziye atar TEMPLATE OLACAK*/
	AkilliDizi(const vector<T> & TVector); /*vektoru akilli diziye donusturur TEMPLATE
	OLACAK*/
	/* Dinamik bellek yonetimi icin gerekli olan fonksiyonlari yaziniz TEMPLATE OLACAK*/
	~AkilliDizi(); 
	AkilliDizi(const AkilliDizi<T>& copyT); /*Copy Constructor */
	AkilliDizi<T>& operator=(const AkilliDizi<T>& atamaT); /* Atama operatoru*/
	/* [] operatorunu asiri yukleyiniz. Verilen indeks degeri elemanSayisindan buyukse hata
	mesaji yazdirin. TEMPLATE OLACAK*/
	T operator [](unsigned int a);
	/* Akilli diye bir int degeri ekleyebilecek sekilde + operatorunu yukleyin TEMPLATE
	OLACAK*/
	AkilliDizi<T>& operator+(T i);
	void sirala()const; /* diziyi buyukten kucuge siralar TEMPLATE OLACAK*/
	void histogram(vector<Pair<T>>  hist); /* veri icinde gecen her bir elemanin kac kez
	oldugunu bulur ve bunu vektor<Pair> olarak donderir TEMPLATE OLACAK*/
	unsigned kacTane(const T& i) const; /* veri icinde i degerinden kac tane olduðunu sayar
	TEMPLATE OLACAK*/
	bool varMi(const T& i) const; /* veri icinde i degeri mevcutsa dogru degilse yanlis donderir
	TEMPLATE OLACAK*/
	unsigned int getElemanSayisi() /*Eleman sayisini donderir.*/
	{
		return elemanSayisi;
	}

	T * getVeri()
	{
		return veri;
	}
private:
	T * veri; /* veriyi dinamik olarak tutar TEMPLATE OLACAK*/
	unsigned int kapasite; /* Kapasite doldugunda yeni alinacak yer mevcut kapasitenin yarisi
	olmali. Ýhtiyac daha

	fazlaysa ihtiyac + mevcut kapasitenin yarisi kadar

	yer alinmali.*/
	unsigned int elemanSayisi; /* dizideki mevcut eleman sayisini verir */
};

class Ogrenci {

friend ostream & operator <<(ostream & out, const Ogrenci& diger) /*Ogrenci sinifini ekrana yazdýran operator...*/
{
	out << "Ogrenci ismi     ";
	for (unsigned int i = 0; i <diger.isimUzunluk ; ++i)
	{
		out << diger.isim[i];
	}
	out << endl;
	out << "Ogrenci numara     ";
	for  (unsigned int i = 0; i < diger.numaraUzunluk; ++i)
	{
		out << diger.numara[i];
	}
	out << endl;
	return out;
}
public:
	Ogrenci()  /*Bos bir ogrenci objesi olusturan constructor*/
	{
		isimUzunluk = 0;
		numaraUzunluk = 0;
		isim = nullptr;
		numara = nullptr;
	}
	Ogrenci(string isim, string numara) /*Tek bir ogrenci objesi olusturur.*/
	{
		isimUzunluk = isim.size();
		numaraUzunluk = numara.size();

		this->isim = new char[isimUzunluk];
		if (this->isim == nullptr)
			 throw ERROR();
		this->numara = new char[numaraUzunluk];
		if (this->numara == nullptr)
			 throw ERROR();
		for (unsigned int i = 0; i < isimUzunluk; ++i)
		{
			this->isim[i] = isim[i];
		}

		for (unsigned int i = 0; i < numaraUzunluk; ++i)
		{
			this->numara[i] = numara[i];
		}

	}
	~Ogrenci() /* Destructor. isimi ve numarayi siler.*/
	{
		if (isim != nullptr)
		{
			delete[] isim;
			isim = nullptr;
		}
		if (numara != nullptr)
		{
			delete[] numara;
			numara = nullptr;
		}
	}
	Ogrenci(const Ogrenci& diger) /* Bir Ogrenci objesini baska bir Ogrenci objesine kopyalayan Copy Constructor.*/
	{
		isimUzunluk = diger.isimUzunluk;
		this->isim = new char[isimUzunluk];
		if (isim == nullptr)
			 throw ERROR();
		for (unsigned int i = 0; i < isimUzunluk; ++i)
		{
			isim[i] = diger.isim[i];
		}

		numaraUzunluk = diger.numaraUzunluk;
		numara = new char[numaraUzunluk];
		if (numara == nullptr)
			 throw ERROR();
		for (int i = 0; i < numaraUzunluk; ++i)
			numara[i] = diger.numara[i];
	}
	Ogrenci& operator=(const Ogrenci& diger)/* Bir Ogrenci objesinin baska bir Ogrenci objesine atayan operator*/
	{
		if (this == &diger)
			return *this;
		if (isim != nullptr)
			delete[] isim;
		isimUzunluk = diger.isimUzunluk;
		isim = new char[isimUzunluk];
		if (isim == nullptr)
			 throw ERROR();
		for (unsigned int i = 0; i < isimUzunluk; ++i)
			isim[i] = diger.isim[i];
		if (numara != nullptr)
			delete[] numara;
		numaraUzunluk = diger.numaraUzunluk;
		numara = new char[numaraUzunluk];
		if (numara == nullptr)
			 throw ERROR();
		for (unsigned int i = 0; i < numaraUzunluk; ++i)
			numara[i] = diger.numara[i];

		return *this;
	}

	

	

	char * getNumara() /*numarayý donderir*/
	{
		return numara;
	}


	bool operator > ( Ogrenci& diger) /*iki ogrenci objesini numaralara gore karsilastirir.*/
	{
		if (this->cevirici() > diger.cevirici())
			return true;
		return false;
	}

	bool operator <(Ogrenci& diger)/*iki ogrenci objesini numaralara gore karsilastirir. */
	{
		if (this->cevirici() < diger.cevirici())
			return true;
		return false;

	}

	bool operator==(const Ogrenci& digerOgrenci) /*/*iki ogrenci objesini numaralara gore karsilastirir. Eger iki Ogrenci objesi esit ise true donderir.*/
	{
		int benzerlik = 0;
		for (unsigned int i = 0; i < numaraUzunluk; ++i)
		{
			if (numara[i] == digerOgrenci.numara[i])
				benzerlik++;
				
		}
		if (benzerlik == numaraUzunluk && benzerlik == digerOgrenci.numaraUzunluk)
			return true;
		return false;
	}

	int getUzunlukNum() { return numaraUzunluk; }/*numara uzunlugunu donderir*/
	int getUzunlukÝsim() { return isimUzunluk; } /* isim uzunlugunu donderir.*/

	double cevirici() const /* char dizilerini integer bir degere cevirir. bu fonksiyon Ogrenci objeleri karsilastirmalarinda kullanilmak uzere yazilmistir. */
	{
		double sayi = 0;
		double rakam = 0;
		double basamakDegeri = 0;
		int numaraUzunlukTut = numaraUzunluk;
		int rakamlarASCII[] = { 48,49,50,51,52,53,54,55,56,57 };

		for (unsigned int i = 0; i < numaraUzunluk; ++i)
		{
			for (unsigned int j = 0; j < 10; ++j)
			{
				if ((int)numara[0] == rakamlarASCII[0])
				{
					numaraUzunlukTut--;
					break;
				}
				if ((int)numara[i] == rakamlarASCII[j])
					rakam = j;
			}
			basamakDegeri = rakam * pow(10, numaraUzunlukTut);
			sayi = basamakDegeri + sayi;
			numaraUzunlukTut--;
		}

		return sayi;
	}

private:
	char * isim;
	char * numara;
	int numaraUzunluk;
	int isimUzunluk;
};

