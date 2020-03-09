/*Fatih Dursun Üzer
18120205041
9.Ödev Çalýlmasý
12 Mayýs 2019
main.cpp
ogrenci sinifi odev9.h nin icersinindedir
Bilgisayar Mühendisliði */

#include <iostream>
#include <vector>
#include "odev9.h"
#include "odev9.cpp"
#include <new>
#include <exception>


using namespace std;

int main()
{
	try {
		Ogrenci ogrenci("Fatih Dursun Uzer", "18120205041");
		AkilliDizi<Ogrenci> tekElemanliOgrenci(ogrenci);
		cout << "Tek elemanli akilli dizi olusturan constructor icin << operatoru  -OGRENCI" << endl;
		cout << tekElemanliOgrenci;
		Ogrenci ogrenci1("Ramazan Yilmaz", "13325245088");
		AkilliDizi<Ogrenci> tekElemanliOgrenci1(ogrenci1);
		cout << "tekElemanliOgrenci1 akilli dizisi " << endl << tekElemanliOgrenci1;
		tekElemanliOgrenci = tekElemanliOgrenci1;
		cout << "Tek elemanli akilli dizi olusturan constructor icin =operatoru  -OGRENCI" << endl;
		cout << "tekElemanliOgrenci  :" << endl << tekElemanliOgrenci << "tekElemanliOgrenci1  :" << endl << tekElemanliOgrenci1;
		AkilliDizi<Ogrenci> tekElemanliOgrenci2 = tekElemanliOgrenci1;
		cout << "Tek elemanli akilli dizi olusturan constructor icin copy constructor  -OGRENCI" << endl;
		cout << "tekElemanliOgrenci2 :" << endl << tekElemanliOgrenci2 << "tekElemanliOgrenci1 :" << endl << tekElemanliOgrenci1;
		cout << "Tek elemanli akilli dizi olusturan constructor icin varMi fonksiyonu  -OGRENCI" << endl;
		cout << "tekElemanliOgrenci akilli dizisinide ogrenci1 objeli biri var mi? Burada numaralar esas alinir." << endl;
		cout << tekElemanliOgrenci.varMi(ogrenci1) << endl;
		Ogrenci ogrenci2("Hakan Sahin", "18125254446");
		cout << "Ogrenci sinifi icin ogrenci2 objesi  :" << endl << ogrenci2;
		AkilliDizi<Ogrenci> tekElemanliOgrenci3(ogrenci2);
		cout << "tekElemanliOgrenci3 akilli dizisi icin index operatoru -OGRENCI. 0 indexli deger :" << endl << tekElemanliOgrenci3[0] << endl;
		cout << "tekElemanliOgrenci3+ogrenci2 :" << (tekElemanliOgrenci3 + ogrenci2) << endl;

		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKÝ TESTLER T* ve int bir sayý alan constructor icindir...OGRENCI" << endl;

		Ogrenci ogrenci3("Ahmet Demirci", "28566453698");
		cout << "ogrenci3 objesi :" << endl << ogrenci3 << endl;
		Ogrenci ogrDizisi[] = { ogrenci,ogrenci1,ogrenci2,ogrenci3 };
		cout << "ogrDizisi :" << endl;
		for (unsigned int i = 0; i < 4; ++i)
		{
			cout << ogrDizisi[i];
		}
		cout << endl;
		AkilliDizi<Ogrenci> akilliOgrDizisi(ogrDizisi, 4);
		cout << "akilliOgrDizisi :" << endl << akilliOgrDizisi << endl;
		AkilliDizi<Ogrenci> akilliOgrDizisi2 = akilliOgrDizisi;
		cout << "copy constructor" << endl;
		cout << "akilliOgrDizisi2 :" << endl << akilliOgrDizisi2 << endl << "akilliOgrDizisi :" << endl << akilliOgrDizisi;
		cout << "akilliOgrDizisi icin sirala fonksiyonu :" << endl;
		akilliOgrDizisi.sirala();
		cout << akilliOgrDizisi;
		cout << "akilliOgr dizisi icin histogram fonksiyonu :" << endl;
		vector<Pair<Ogrenci>> pairOgrenci;
		akilliOgrDizisi.histogram(pairOgrenci);
		Ogrenci ogrenci4("Hasan Saglam", "36125255047");
		cout << "ogrenci4 objesi :" << endl;
		cout << "akilliOgrDizisi+ogrenci4 :" << (akilliOgrDizisi + ogrenci4);
		Ogrenci ogrenci5("Kemal Dolar", "6257504941");
		cout << "akilliOgrDizisi icinde ogrenci5 var mi?" << endl;
		cout << akilliOgrDizisi.varMi(ogrenci5) << endl << "var ise kac tane var ?" << endl << akilliOgrDizisi.kacTane(ogrenci5) << endl;
		cout << "akilliOgrDizisinin 2 indexli elemani" << endl << akilliOgrDizisi[2];
		Ogrenci ogrDizisi2[] = { ogrenci5 };
		AkilliDizi<Ogrenci> akilliOgrDizisi3(ogrDizisi2, 1);
		cout << "akilliOgrDizisi3 : " << endl << akilliOgrDizisi3 << endl;
		cout << "akilliOgrDizisi2icin =operatoru" << endl;
		akilliOgrDizisi2 = akilliOgrDizisi3;
		cout << "akilliOgrDizisi2 :" << endl << akilliOgrDizisi2 << endl << "akilliOgrDizisi3 :" << endl << akilliOgrDizisi3 << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKÝ TESTLER vector<T> alan Constructor icindir...-OGRENCI" << endl;
		Ogrenci yeniOgrenci("Lokman Sadikoglu", "18130306614");
		Ogrenci yeniOgrenci2("Mustafa pasa", "18811938567");
		cout << "yeniOgrenci objesi : " << endl << yeniOgrenci;
		cout << "yeniOgrenci2 objesi : " << endl << yeniOgrenci2;
		vector<Ogrenci> yeniler;
		yeniler.push_back(yeniOgrenci);
		yeniler.push_back(yeniOgrenci2);
		cout << "yeniler vektoru : " << endl;
		for (unsigned int i = 0; i < yeniler.size(); ++i)
			cout << yeniler[i];
		cout << endl;
		AkilliDizi<Ogrenci> yeniOgrenciler(yeniler);
		cout << "vector<Ogrenci> constructor icin << operatoru" << endl;
		cout << yeniOgrenciler << endl;
		AkilliDizi<Ogrenci>yeniOgrenciler2 = yeniOgrenciler;
		cout << "yeniOgrenciler2 Akilli dizisi icin copy constructor" << endl;
		cout << "yeniOgrenciler : " << yeniOgrenciler << endl << "yeniOgrenciler2 : " << endl << yeniOgrenciler2;
		AkilliDizi<Ogrenci>yeniOgrenciler3(ogrenci2);
		cout << "yeniOgrenciler3 vektoru : " << endl << yeniOgrenciler3;
		yeniOgrenciler3 = yeniOgrenciler2;
		cout << "=operatoru" << endl;
		cout << "yeniOgrenciler3 : " << endl << yeniOgrenciler3 << endl << "yeniOgrenciler2 : " << endl << yeniOgrenciler2 << endl;
		vector<Ogrenci> yeniler2;
		yeniler2.push_back(ogrenci1);
		yeniler2.push_back(ogrenci2);
		for (unsigned int i = 0; i < yeniler2.size(); ++i)
			cout << yeniler2[i];
		cout << endl;
		AkilliDizi<Ogrenci>yeniOgrenciler4(yeniler2);
		cout << "yeniOgrenciler4 vektoru : " << endl << yeniOgrenciler4 << endl;
		cout << "yeniOgrenciler4 + ogrenci4 : " << endl << yeniOgrenciler4 + ogrenci4;
		cout << "yeniOgrenciler4+ogrenci1+yeniOgrenci2" << endl << yeniOgrenciler4 + ogrenci1 + yeniOgrenci2;
		cout << "yeniOgrenciler4 dizisi icin siralama fonksiyonu : " << endl;
		yeniOgrenciler4.sirala();
		cout << yeniOgrenciler4;
		cout << "yeniOgrenciler4 dizisi icin 1 indexli eleman : " << endl;
		cout << yeniOgrenciler4[1] << endl;
		cout << "yeniOgrenciler4 dizisi icin varMi ve kacTane fonksiyonu" << endl;
		cout << yeniOgrenciler4.varMi(ogrenci) << endl << "kac tane var?" << endl << yeniOgrenciler4.kacTane(ogrenci) << endl;
		cout << "yeniOgrenciler4 dizisi icin histogram" << endl;
		vector<Pair<Ogrenci>> pairOgr;
		yeniOgrenciler4.histogram(pairOgr);
		cout << endl;

		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKI TESTLER tek bir objeli elemaný olan AkilliDizi constructoru icindir... -INTEGER" << endl;
		int a = 5;
		AkilliDizi<int> tamSayi(a);
		cout << "Constructor icin << operatoru" << endl;
		cout << "tamSayi dizisi :" << endl << tamSayi;
		AkilliDizi<int> tamSayi2 = tamSayi;
		cout << " Copy Construcor " << endl;
		cout << "tamSayi2 dizisi :" << tamSayi2 << endl << "tamSayi dizisi :" << endl << tamSayi << endl;
		int b = 17;
		AkilliDizi<int> tamSayi3(b);
		cout << "= operatoru " << endl;
		tamSayi2 = tamSayi3;
		cout << "tamSayi2 :" << endl << tamSayi2 << "tamSayi3 :" << tamSayi3 << endl;
		AkilliDizi<int>tamSayi4 = tamSayi;
		cout << "Copy Constructor " << endl;
		cout << "tamSayi4 dizisi:" << tamSayi4 << endl << "tamSayi dizisi" << endl << tamSayi;
		cout << "tamSayi3 icin kacTane ve varMi fonskiyonlari" << endl;
		cout << tamSayi3.varMi(5) << endl << tamSayi3.kacTane(5);
		cout << "tamSayi3+28: " << endl << tamSayi3 + 28 << endl;
		cout << "tamSayi3 dizisinin 0 indexli elemani" << endl << tamSayi3[0];
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKI TESTLER T* ve int bir sayý alan constructor icindir...INTEGER" << endl;
		int intDizisi[] = { 5,7,10,56,51,28,44 };
		AkilliDizi<int> akilliIntDizisi(intDizisi, 7);
		cout << " << operatoru " << endl;
		cout << "akilliIntDizisi : " << endl << akilliIntDizisi << endl;
		cout << "akilliIntDizisi + 41 : " << endl << akilliIntDizisi + 41;
		cout << "akilliIntDizisi icin sirala ve histogram fonksiyonu" << endl;
		akilliIntDizisi.sirala();
		cout << "akilliIntDizisi : " << endl << akilliIntDizisi;
		vector<Pair<int>> intPair;
		akilliIntDizisi.histogram(intPair);
		cout << " COPY CONSTRUCTOR" << endl;
		AkilliDizi<int> akilliIntDizisi2 = akilliIntDizisi;
		cout << "akilliIntDizisi2 : " << endl << akilliIntDizisi2 << endl << "akilliIntDizisi : " << endl << akilliIntDizisi;
		cout << "= operatoru " << endl;
		int intDizisi2[] = { 5 };
		AkilliDizi<int> akilliIntDizisi3(intDizisi2, 1);
		cout << "akilliIntDizisi3 : " << endl << akilliIntDizisi;
		cout << "= operatoru " << endl;
		akilliIntDizisi3 = akilliIntDizisi2;
		cout << "akilliIntDizisi3 : " << endl << akilliIntDizisi3 << endl << "akilliIntDizisi2 : " << endl;
		cout << "akilliIntDizisi2 icin kacTane ve varMi fonksiyonlari " << endl << akilliIntDizisi2.varMi(17) << endl << akilliIntDizisi2.kacTane(41);
		cout << "akilliIntDizisi2 nin 2 indexli elemani" << endl << akilliIntDizisi[2] << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKÝ TESTLER vector<T> alan Constructor icindir...-INTEGER" << endl;
		vector<int> intVektor;
		for (unsigned int i = 0; i < 10; ++i)
			intVektor.push_back(((i*i) - 50));
		cout << "intVektor : " << endl;
		for (unsigned int i = 0; i < intVektor.size(); ++i)
			cout << intVektor[i] << endl;
		AkilliDizi<int> intVektorDizisi(intVektor);
		cout << "intVektor dizisi : " << endl << intVektorDizisi;
		cout << "intVektorDizisi icin siralama" << endl;
		intVektorDizisi.sirala();
		cout << intVektorDizisi << endl;
		cout << "intVektorDizisi icin histogram, varMi ve kacTane fonksiyonu" << endl;
		vector<Pair<int>> intVektorr;
		intVektorDizisi.histogram(intVektorr);
		cout << "24 sayisi intVektorDizisinde var mi?" << endl << intVektorDizisi.varMi(24) << endl << "30 sayisi kac tane ?" << endl << intVektorDizisi.kacTane(30) << endl;
		cout << "Copy Constructor" << endl;
		AkilliDizi<int>intVektorDizisi2 = intVektorDizisi;
		cout << "intVektorDizisi2 : " << endl << "intVektorDizisi : " << endl;
		vector<int>intVektor2;
		intVektor2.push_back(28);
		cout << "intVektor2 : " << endl;
		cout << intVektor2[0];
		AkilliDizi<int> intVektorDizisi3(intVektor2);
		cout << "intVektorDizisi3 : " << endl << intVektorDizisi3;
		cout << "= operatoru " << endl;
		intVektorDizisi3 = intVektorDizisi;
		cout << "intVektorDizisi2 : " << endl << intVektorDizisi << endl << "intVektorDizisi3 : " << endl << intVektorDizisi3;
		cout << "intVektorDizisi3+28" << endl << intVektorDizisi3 + 28;
		cout << "intVektorDizisi3 un 4 indexli elemani" << endl << intVektorDizisi3[4] << endl;

		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;

		cout << "BURADAKI TESTLER tek bir objeli elemaný olan AkilliDizi constructoru icindir... -DOUBLE" << endl;
		double a1 = 5;
		AkilliDizi<double> doubleSayi(a1);
		cout << "Constructor icin << operatoru" << endl;
		cout << "doubleSayi dizisi :" << endl << doubleSayi;
		AkilliDizi<double> doubleSayi2 = doubleSayi;
		cout << " Copy Construcor " << endl;
		cout << "doubleSayi2 dizisi :" << doubleSayi2 << endl << "doubleSayi dizisi :" << endl << doubleSayi << endl;
		double b1 = 17;
		AkilliDizi<double> doubleSayi3(b1);
		cout << "= operatoru " << endl;
		doubleSayi2 = doubleSayi3;
		cout << "doubleSayi2 :" << endl << doubleSayi2 << "doubleSayi3 :" << doubleSayi3 << endl;
		AkilliDizi<double>doubleSayi4 = doubleSayi;
		cout << "Copy Constructor " << endl;
		cout << "doubleSayi4 dizisi:" << doubleSayi4 << endl << "doubleSayi dizisi" << endl << doubleSayi;
		cout << "doubleSayi3 icin kacTane ve varMi fonskiyonlari" << endl;
		cout << doubleSayi3.varMi(5) << endl << doubleSayi3.kacTane(5);
		cout << "doubleSayi3+28: " << endl << doubleSayi3 + 28 << endl;
		cout << "doubleSayi3 dizisinin 0 indexli elemani" << endl << doubleSayi3[0] << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKI TESTLER T* ve double bir sayý alan constructor icindir...DOUBLE" << endl;
		double doubleDizisi[] = { 5.0,7.9,10.4,56.5,51.3,28.0,44.4 };
		AkilliDizi<double> akillidoubleDizisi(doubleDizisi, 7);
		cout << " << operatoru " << endl;
		cout << "akillidoubleDizisi : " << endl << akillidoubleDizisi << endl;
		cout << "akillidoubleDizisi + 41 : " << endl << akillidoubleDizisi + 41;
		cout << "akillidoubleDizisi icin sirala ve histogram fonksiyonu" << endl;
		akillidoubleDizisi.sirala();
		cout << "akillidoubleDizisi : " << endl << akillidoubleDizisi;
		vector<Pair<double>> doublePair;
		akillidoubleDizisi.histogram(doublePair);
		cout << " COPY CONSTRUCTOR" << endl;
		AkilliDizi<double> akillidoubleDizisi2 = akillidoubleDizisi;
		cout << "akillidoubleDizisi2 : " << endl << akillidoubleDizisi2 << endl << "akillidoubleDizisi : " << endl << akillidoubleDizisi;
		cout << "= operatoru " << endl;
		double doubleDizisi2[] = { 8.0 };
		AkilliDizi<double> akillidoubleDizisi3(doubleDizisi2, 1);
		cout << "akillidoubleDizisi3 : " << endl << akillidoubleDizisi;
		cout << "= operatoru " << endl;
		akillidoubleDizisi3 = akillidoubleDizisi2;
		cout << "akillidoubleDizisi3 : " << endl << akillidoubleDizisi3 << endl << "akillidoubleDizisi2 : " << endl;
		cout << "akillidoubleDizisi2 icin kacTane ve varMi fonksiyonlari " << endl << akillidoubleDizisi2.varMi(25) << endl << akillidoubleDizisi2.kacTane(64);
		cout << "akillidoubleDizisi2 nin 1 indexli elemani" << endl << akillidoubleDizisi[1] << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKÝ TESTLER vector<T> alan Constructor icindir...-DOUBLE" << endl;
		vector<double> doubleVektor;
		doubleVektor.push_back(0);
		for (unsigned int i = 0; i < 10; ++i)
			doubleVektor.push_back(((i*5.0) - 10));
		/*cout << "doubleVektor : " << endl;*/

		AkilliDizi<double> doubleVektorDizisi(doubleVektor);
		cout << doubleVektorDizisi;
		doubleVektorDizisi.sirala();
		cout << doubleVektorDizisi;

		cout << "BURADAKI TESTLER tek bir objeli elemaný olan AkilliDizi constructoru icindir... -CHAR" << endl;
		char a2 = 'a';
		AkilliDizi<char> charSayi(a2);
		cout << "Constructor icin << operatoru" << endl;
		cout << "charSayi dizisi :" << endl << charSayi;
		AkilliDizi<char> charSayi2 = charSayi;
		cout << " Copy Construcor " << endl;
		cout << "charSayi2 dizisi :" << charSayi2 << endl << "charSayi dizisi :" << endl << charSayi << endl;
		char b2 = 'b';
		AkilliDizi<char> charSayi3(b2);
		cout << "= operatoru " << endl;
		charSayi2 = charSayi3;
		cout << "charSayi2 :" << endl << charSayi2 << "charSayi3 :" << charSayi3 << endl;
		AkilliDizi<char>charSayi4 = charSayi;
		cout << "Copy Constructor " << endl;
		cout << "charSayi4 dizisi:" << charSayi4 << endl << "charSayi dizisi" << endl << charSayi;
		cout << "charSayi3 icin kacTane ve varMi fonskiyonlari" << endl;
		cout << charSayi3.varMi('a') << endl << charSayi3.kacTane('a');
		cout << "charSayi3+c: " << endl << charSayi3 + 'c' << endl;
		cout << "charSayi3 dizisinin 0 indexli elemani" << endl << charSayi3[0] << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKI TESTLER T* ve char bir karakter alan constructor icindir...char" << endl;
		char charDizisi[] = { 'f','a','t','i','h','u','z','e','r' };
		AkilliDizi<char> akillicharDizisi(charDizisi, 9);
		cout << " << operatoru " << endl;
		cout << "akillicharDizisi : " << endl << akillicharDizisi << endl;
		cout << "akillicharDizisi + d : " << endl << akillicharDizisi + 'd';
		cout << "akillicharDizisi icin sirala ve histogram fonksiyonu" << endl;
		akillicharDizisi.sirala();
		cout << "akillicharDizisi : " << endl << akillicharDizisi;
		vector<Pair<char>> charPair;
		akillicharDizisi.histogram(charPair);
		cout << " COPY CONSTRUCTOR" << endl;
		AkilliDizi<char> akillicharDizisi2 = akillicharDizisi;
		cout << "akillicharDizisi2 : " << endl << akillicharDizisi2 << endl << "akillicharDizisi : " << endl << akillicharDizisi;
		cout << "= operatoru " << endl;
		char charDizisi2[] = { 'k' };
		AkilliDizi<char> akillicharDizisi3(charDizisi2, 1);
		cout << "akillicharDizisi3 : " << endl << akillicharDizisi;
		cout << "= operatoru " << endl;
		akillicharDizisi3 = akillicharDizisi2;
		cout << "akillicharDizisi3 : " << endl << akillicharDizisi3 << endl << "akillicharDizisi2 : " << endl;
		cout << "akillicharDizisi2 icin kacTane ve varMi fonksiyonlari " << endl << akillicharDizisi2.varMi('f') << endl << akillicharDizisi2.kacTane('d');
		cout << "akillicharDizisi2 nin 1 indexli elemani" << endl << akillicharDizisi[1] << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "BURADAKÝ TESTLER vector<T> alan Constructor icindir...-CHAR" << endl;
		vector<char> charVektor = { 'b','i','l','1','2','2' };
		cout << "charVektor : " << endl;
		for (unsigned int i = 0; i < charVektor.size(); ++i)
			cout << charVektor[i] << endl;
		AkilliDizi<char> charVektorDizisi(charVektor);
		cout << "charVektor dizisi : " << endl << charVektorDizisi;
		cout << "charVektorDizisi icin siralama" << endl;
		charVektorDizisi.sirala();
		cout << charVektorDizisi << endl;
		cout << "charVektorDizisi icin histogram, varMi ve kacTane fonksiyonu" << endl;
		vector<Pair<char>> charVektorr;
		charVektorDizisi.histogram(charVektorr);
		cout << "a karakteri charVektorDizisinde var mi?" << endl << charVektorDizisi.varMi('a') << endl << "c karakteri kac tane ?" << endl << charVektorDizisi.kacTane('c') << endl;
		cout << "Copy Constructor" << endl;
		AkilliDizi<char>charVektorDizisi2 = charVektorDizisi;
		cout << "charVektorDizisi2 : " << endl << "charVektorDizisi : " << endl;
		vector<char>charVektor2;
		charVektor2.push_back('m');
		cout << "charVektor2 : " << endl;
		cout << charVektor2[0];
		AkilliDizi<char> charVektorDizisi3(charVektor2);
		cout << "charVektorDizisi3 : " << endl << charVektorDizisi3;
		cout << "= operatoru " << endl;
		charVektorDizisi3 = charVektorDizisi;
		cout << "charVektorDizisi2 : " << endl << charVektorDizisi << endl << "charVektorDizisi3 : " << endl << charVektorDizisi3;
		cout << "charVektorDizisi3+'t'" << endl << charVektorDizisi3 + 't';
		cout << "charVektorDizisi3 un 1 indexli elemani" << endl << charVektorDizisi3[1] << endl;
		vector<int> sayýlar= { 5,6,7,4,4 };
		AkilliDizi<int> diziler(sayýlar);
		cout << diziler[4];
	}
		catch (bad_alloc &ff)
		{
			cerr << "Hafizada yer alinamadi..." << ff.what() << endl;
			exit(-1);
		}
		catch (out_of_range& oor) {
			cerr << oor.what() << endl;
			exit(-1);
		}

		catch (...)
		{
			cerr << "Belirlenemeyen bir hata olustu..." << endl;
			exit(-1);
		}
		return 0;
}