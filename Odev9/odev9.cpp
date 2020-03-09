/*Fatih Dursun Üzer
18120205041
9.Ödev Çalýlmasý
12 Mayýs 2019
odev9.cpp
Bilgisayar Mühendisliði */

#include "odev9.h"
#include <iostream>
#include<string>
#include <new>

using namespace std;

template <class T>
ostream& operator<<(ostream& out, AkilliDizi<T>& dizi) /* AkilliDiziyi ekrana yazdýran << operatoru*/
{
	for (unsigned int i = 0; i < dizi.elemanSayisi; ++i)
	{
		out << dizi.veri[i] << endl;
	}
	return out;
}

template<class T>
 AkilliDizi<T>::AkilliDizi()  /* bos bir akilli dizi olusturur*/
{
	 veri = nullptr;
	 elemanSayisi = 0;
	 kapasite = 0;
}

 template<class T>
 AkilliDizi<T>::AkilliDizi(T &i) /* tek elamanlý ve eleman degeri i olan template bir akilli dizi olusturur */
 {
		 elemanSayisi = 1;
		 kapasite = elemanSayisi+elemanSayisi/2;
		 veri = new T[elemanSayisi];
		 if (veri == nullptr)
			 throw ERROR();
		 veri[0] = i;
	 
 }

 template<class T>
 AkilliDizi<T>::AkilliDizi(const T * tDizi, unsigned int elemanSayisi)/* elemanSayisi elamanli bir
	akilli dizi olusturur ve tDizi elamanlarini template akilli diziye atar*/
 {
	 this->elemanSayisi = elemanSayisi;
	 kapasite = this->elemanSayisi * 2;
	 veri = new T[elemanSayisi];
	 if (veri == nullptr)
		  throw ERROR();
	 for (unsigned int i = 0; i < elemanSayisi; ++i)
	 {
		 veri[i] = tDizi[i];
	 }

 }

 template<class T>
 AkilliDizi<T>::AkilliDizi(const vector<T>& TVector) /*vektoru template akilli diziye donusturur*/
 {
	 elemanSayisi = TVector.size();
	 kapasite = TVector.capacity();
	 veri = new T[elemanSayisi];
	 if (veri == nullptr)
		  throw ERROR();
	 for (unsigned int i = 0; i < elemanSayisi; ++i)
	 {
		 veri[i] = TVector[i];
	 }
 }

 template<class T>
 AkilliDizi<T>::~AkilliDizi() /*Akilli dizi nin destructoru. veriyi silip nullptr atar*/
 {
	 delete[] veri;
	 veri = nullptr;
 }

 template<class T>
 AkilliDizi<T>::AkilliDizi(const AkilliDizi<T>& kopyaT)  /*Copy Constructor. Bir akillidiziyi baþka bir akillidiziye kopyalar*/
 {
	 cout << "COPY CONSTRUCTOR  " << endl;
	 elemanSayisi = kopyaT.elemanSayisi;
	 kapasite = kopyaT.kapasite;
	 veri = new T[elemanSayisi];
	 if (veri == nullptr)
		  throw ERROR();
	 for (unsigned int a = 0; a < elemanSayisi; ++a)
	 {
		 veri[a] = kopyaT.veri[a];
	 }
 }

 template<class T>
 AkilliDizi<T>& AkilliDizi<T>::operator=(const AkilliDizi<T>& atamaT) /* Atama operatoru. Bir akillidiziyi baska bir akillidiziye atar.*/
 {
	 cout << "ASSIGNMENT" << endl;
	 if (this == &atamaT)
		 return *this;
	 if (veri != nullptr)
		 delete[]veri;
	 elemanSayisi = atamaT.elemanSayisi;
	 kapasite = atamaT.kapasite;
	 veri = new T[elemanSayisi];
	 if (veri == nullptr)
		  throw ERROR(); 
	 for (unsigned int i = 0; i < elemanSayisi; ++i)
	 {
		 veri[i] = atamaT.veri[i];
	 }
	 return *this;
 }

 template<class T>
 T AkilliDizi<T>::operator[](unsigned int a) /* index operatoru. erismek istedigimiz indexteki elemaný donderir*/
 {
	 if (a > kapasite)
		 throw ERROR(a);
	 return veri[a];
 }

 template<class T>
 AkilliDizi<T>& AkilliDizi<T>::operator+(T i) /* AkilliDiziye bir obje ekler.*/
 {
	 vector<T> vektor;
	 for (unsigned int i = 0; i < elemanSayisi; ++i)
	 {
		 vektor.push_back(veri[i]);
	 }
	 vektor.push_back(i);

	 if (veri != nullptr)
		 delete[] veri;
	 elemanSayisi = elemanSayisi + 1;
	 kapasite = elemanSayisi+elemanSayisi/2;
	 veri = new T[kapasite];
	 if (veri == nullptr)
		  throw ERROR();

	 for (unsigned int i = 0; i < elemanSayisi; ++i)
	 {
		 veri[i] = vektor[i];
	 }

	 return *this;
 }

 template<class T>
 void AkilliDizi<T>::sirala() const  /* AkilliDizideki elemanlari buyukten kucuge dogru siralar*/
 {
	 T temp;
	 for (unsigned int i = 0; i < elemanSayisi ; ++i)
	 {
		 for (unsigned int j = 0; j < elemanSayisi; ++j)
		 {
			 if (i == j)
				 continue;
			 if (veri[i] > veri[j])
			 {
				 temp = veri[i];
				 veri[i] = veri[j];
				 veri[j] = temp;
			 }
		 }
	 }
	 return;

 }

 template<class T>
 void AkilliDizi<T>::histogram(vector<Pair<T>> hist)  /* veri icinde gecen her bir elemanin kac kez
	oldugunu bulur */
 {
	 sirala();
	 Pair<T>temp;
	 for (unsigned int i = 0; i < elemanSayisi; i += kacTane(veri[i]))
	 {
		 temp.eleman = veri[i];
		 temp.adet = kacTane(veri[i]);
		 hist.push_back(temp);
	 }

	 for (unsigned int i = 0; i < hist.size(); ++i)
	 {
		 cout << hist[i].eleman << "  den  " << hist[i].adet << "tane bulunmaktadir. " << endl;
	 }
 }

 template<class T>
 unsigned AkilliDizi<T>::kacTane(const T& i) const /* AkilliDizinin icerisinde i degerinin kactane oldugunu bulur ve buldugu sayýyý donderir*/
 {
	int iSayisi = 0;
	 for (unsigned int a = 0; a< elemanSayisi; ++a)
	 {
		 if (veri[a] == i)
		 {
			 iSayisi++;
		 }
	 }
	/* cout << i << "den" << iSayisi << "kadar vardir" << endl;*/
	 return iSayisi;
 }

 template<class T>
 bool AkilliDizi<T>::varMi(const T& i) const /* AkilliDizinin icerisinde i elemanýnýn olup olmadýgýný bulan fonksiyon*/
 {
	 for (unsigned int a= 0; a < elemanSayisi; ++a)
	 {
		 if (veri[a] == i)
		 {
			 cout << "Belirtilen deger Akilli dizide bulunmaktadir." << endl;
			 return true;
		 }
	}
	 cout << "Belirtilen deger Akilli dizide bulunmamaktadir." << endl;
	 return false;
 }
