

/*Fatih Dursun Uzer 
18120205041
Ýstanbul Medeniyet Üniversitesi
Odev-8
main.cpp
07.06.2019
Surucu,Yolcu, yuk vb getterlar setterlar Arac* cagrisi ile denenemeyeceði için Pointer cagrisi olmadan denenmiþtir.*/
#include "uzunyol.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

unsigned int dosyadanOku(const string& filename, list<Arac*>&Araclar) //Araclarý dosyadan list'e okur ve okuduðu arac sayýsýný donderir
{
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile(filename);

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");

	// Iterate over the Vehicles
	cout << "Parsing Vehicles.xml..." << endl;
	
	

	int i = 0;
	const char* ozluSoz;
	for (auto * vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{
		++i;
		const char* plaka= vehicle_node->first_node("Plaka")->value();
		const char* adi;
		string yasi;
		string ehliyet;
		const char* yolcuAdi;
		const char* yolcuBinis;
		string yolcuInis;
		const char* yukCinsi;
		string agirlik;
		string hacim;
		string aliciIsim;
		string yukBinis;
		string yukInis;
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
		{
			
			ozluSoz = vehicle_node->first_node("OzluSoz")->value();
			cout << endl;
		}
		else
		{
			ozluSoz = "";
		}

		auto * drivers_root_node = vehicle_node->first_node("Suruculer");
		int j = 0;
		list<Surucu>Suruculer;
		for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
		{
			adi = driver_node->first_node("Adi")->value();
			yasi = driver_node->first_node("Yasi")->value();
			ehliyet = driver_node->first_node("EhliyetSinifi")->value();
			Surucu a(adi, ehliyet, yasi);
			Suruculer.push_back(a);
		}

		auto * yolcular_root_node = drivers_root_node->next_sibling();

		int a = 0;
		vector<Yolcu>Yolcular;
		for (auto* yolcu_node = yolcular_root_node->first_node("Yolcu"); yolcu_node; yolcu_node = yolcu_node->next_sibling())
		{
			yolcuAdi = yolcu_node->first_node("Adi")->value();
			yolcuBinis = yolcu_node->first_node("BinisNoktasi")->value();
			yolcuInis = yolcu_node->first_node("InisNoktasi")->value();
			Yolcu a(yolcuAdi, yolcuBinis,yolcuInis);
			Yolcular.push_back(a);
		}
		auto * yukler_root_node = drivers_root_node->next_sibling();
		int b = 0;
		vector<Yuk>Yukler;
		for (auto* yuk_node = yukler_root_node->first_node("Yuk"); yuk_node; yuk_node = yuk_node->next_sibling())
		{
			yukCinsi = yuk_node->first_node("Icerik")->value();
			agirlik = yuk_node->first_node("Agirlik")->value();
			hacim = yuk_node->first_node("Hacim")->value();
			aliciIsim = yuk_node->first_node("Alici")->value();
			yukBinis = yuk_node->first_node("BinisNoktasi")->value();
			yukInis = yuk_node->first_node("InisNoktasi")->value();
			Yuk a(yukCinsi, aliciIsim, agirlik, hacim, yukBinis, yukInis);
			Yukler.push_back(a);
		}

		if (ozluSoz !="")
		{
			Arac* A = new Kamyon(ozluSoz, plaka, Suruculer, Yukler);
			Araclar.push_back(A);
		}
		else
		{
			Arac* B = new Otobus(plaka, Suruculer, Yolcular);
			Araclar.push_back(B);
		}
		
	}
	return i;
}

int main()
{
	try{
	Surucu bos;
	cout << "bos surucusunun bilgileri:" << bos << endl;
	Surucu a("Oguz Guclu", "D", "31");
	cout << "a surucusunun bilgileri:" << endl << a;
	a.setAd("Hasan");
	a.setEhliyet(B);
	a.setYas(47);
	cout << "a surucusunun yeni bilgileri -setter denemeleri:" << endl << a;

	Surucu b(a);
	cout << "b surucusunun bilgileri -COPY CONSTRUCTOR" << endl << b;
	Surucu c("Hakan Sahin", "E", "34");
	cout << "c surucusunun bilgileri:" << endl << c;
	b = c;
	cout << "b surucusunun bilgileri =Operatoru" << endl << b << endl;
	cout << "getter fonksiyonlari icin testler" << endl;
	cout << "a surucusunun ismi :" << a.getAd() << endl << "a surucusunun ehliyet turu:" << a.getEhliyet() << endl << "a surucusunun yasi:" << a.getYas() << endl;

	cout << "# # # # # # # # # # # # # # # # # # #" << endl;
	Yolcu bos1;
	cout << "bos1 yolcusunun bilgileri;" << endl << bos1 << endl;
	Yolcu aYolcu("Hayri giden", "Samsun", "Istanbul");
	cout << "aYolcu yolcusununsunun bilgileri:" << endl << aYolcu << endl;
	aYolcu.setAd("Yavuz giderli");
	aYolcu.setBinisYeri("Izmir");
	aYolcu.setÝnisYeri("Kocaeli");
	cout << "aYolcu yolcusunun yeni bilgileri -setter denemeleri:" << endl << aYolcu << endl;
	Yolcu bYolcu("Kerim Balci", "Agri", "Kirikkale");
	cout << "bYolcu yolcusunun bilgileri:" << endl << bYolcu;
	cout << "getter fonksiyonlari icin testler" << endl;
	cout << "bYolcu yolcusunun ismi:" << bYolcu.getAd() << endl << "bYolcu yolcusunun binisyeri:" << bYolcu.getBinisYeri() << endl << "bYolcu yolcusunun inisyeri:" << bYolcu.getInisYeri() << endl;
	Yolcu cYolcu(aYolcu);
	cout << "cYolcu yolcusunun bilgileri -COPY CONSTRUCTOR (Yolcu cYolcu(aYolcu))" << endl << cYolcu << endl;
	cYolcu = bYolcu;
	cout << "cYolcu bilgisinin bilgileri =Operatoru (cYolcu=bYolcu)" << endl << cYolcu << endl;

	cout << "# # # # # # # # # # # # # # # # # # #" << endl;

	Yuk bosYuk;
	cout << "aYuk bilgileri:" << endl << bosYuk;
	Yuk aYuk("Findik", "Fatih Dursun Uzer", "50", "10", "Giresun", "Istanbul");
	cout << "aYuk yukunun bilgileri:" << endl << aYuk;
	aYuk.setAlici("Taha Ozturk");
	aYuk.setÝcerik("Lahana");
	aYuk.setBinisYeri("Ordu");
	aYuk.setÝnisYeri("Mugla");
	aYuk.setAgirlik(20);
	aYuk.setHacim(5);
	cout << "aYuk yukunun yeni bilgileri -setter denemeleri :" << endl << aYuk;
	Yuk bYuk(aYuk);
	cout << "bYuk yukunun bilgileri (Yuk bYuk(aYuk)):" << endl << bYuk;
	cout << "-getter fonksiyonu denemeleri" << endl << "bYuk yukunun alicisi:" << bYuk.getAlici() << endl << "bYuk yukunun agirligi:" << bYuk.getAgirlik() << endl << "bYuk yukunun hacmi:" << bYuk.getHacim() << endl << "bYuk yukunun binisYeri:" << bYuk.getBinisYeri() << endl << "bYuk yukunun inisYeri:" << bYuk.getÝnisYeri() << endl;
	Yuk cYuk("Kayisi", "Alibey Ozbay"," 5", "1", "Malatya", "Istanbul");
	cout << "cYuk yukunun bilgileri:" << endl << cYuk;
	bYuk = cYuk;
	cout << "bYuk yukunun yeni bilgileri =Operatoru (bYuk=cYuk)" << endl << bYuk;
	cout << "# # # # # # # # # # # # # # # # # # #" << endl;
		Surucu aSurucu("Fatih Dursun Uzer", "D", "40");
		Surucu bSurucu("Mehmet Arif Erbas", "E", "61");
		list<Surucu> suruculer = { aSurucu,bSurucu };
		Yolcu dYolcu("Huseyin Ozturk", "KahramanMaras", "Istanbul");
		Yolcu eYolcu("Kahraman Yýlmaz", "KahramanMaras", "Istanbul");
		vector<Yolcu>Yolcular1 = { dYolcu,eYolcu };
		vector<Yolcu>Yolcular2 = { aYolcu,bYolcu };

	Surucu cSurucu("Ali Ayaz"," B"," 42");
		list<Surucu>yeniSuruculer = { cSurucu };
		Otobus aOtobus("34 DZ 666", yeniSuruculer, Yolcular1);
		cout << "aOtobus otobusunun bilgileri:" << endl << aOtobus << endl;
		Otobus bOtobus = aOtobus;
		cout << "bOtobus otobusunun bilgileri -Copy Constructor" << endl << bOtobus << endl;
		list<Surucu>suruculer1 = { a,b };
		Otobus cOtobus("06 MN 457", suruculer1, Yolcular2);
		cout << "cOtobus otobusunun bilgileri:" << endl << cOtobus << endl;
		bOtobus = cOtobus;
		cout << "bOtobus otobusunun yeni bilgileri =Operatoru" << endl << bOtobus << endl;
		bOtobus.setPlaka("06 KL 342");
		bOtobus.setSuruculer(suruculer);
		bOtobus.setYolcular(Yolcular1);
		cout << "bOtobus otobusunun yeni bilgileri -setter denemeleri" << endl << bOtobus << endl;
		cout << "-getter denemeleri" << endl << "cOtobus otobusunun plakasi:" << endl << cOtobus.getPlaka() << endl;
		cout << "# # # # # # # # # # # # # # # # # # #" << endl;
		Surucu kamyonSurucu("Arif Saglam", "E", "55");
		Surucu kamyonSurucu1("Gokhan Suruc", "E", "47");
		list<Surucu>kamyonSuruculer = { kamyonSurucu,kamyonSurucu1 };
		vector<Yuk> yukler = { aYuk,bYuk };
		vector<Yuk>tekYuk = { cYuk };
		Kamyon aKamyon("Everything you can imagine is real.","34 KS 28",kamyonSuruculer,yukler);
		cout << aKamyon;
		Kamyon bKamyon = aKamyon;
		cout << "bKamyon kamyonunun bilgileri -Copy Constructor" << endl << bKamyon << endl;
		bKamyon.setOzluSoz("Silence is the most powerful scream.");
		bKamyon.setPlaka("55 OS 14");
		bKamyon.setSuruculer(suruculer1);
		bKamyon.setYukler(tekYuk);
		cout << "bKamyon kamyonunun yeni bilgileri -setter denemeleri" << endl << bKamyon << endl;
		aKamyon = bKamyon;
		cout << "aKamyon kamyonunun yeni bilgileri  =Operatoru" << endl << aKamyon << endl;
		cout << "# # # # # # # # # # # # # # # # # # #" << endl;
		
		cout << "Arac* ile otobus ve kamyon objeleri olusturma ....... " << endl;
list<Arac*>Araclar;
Surucu surucuPointer("Fatih Dursun Uzer", "C", "36");
list<Surucu>SuruculerPointer = { surucuPointer };
Surucu surucuPointer1("Ramazan Ozcan", "D", "35");
Yolcu yolcuPointer("Hakan Cambaz", "Istanbul", "Giresun");
Yolcu yolcuPointer1("Süleyman Keser", "Kastamonu", "Giresun");
vector<Yolcu>yolcularPointer = { yolcuPointer,yolcuPointer1 };
Arac* otobus = new Otobus("34 BD 556", SuruculerPointer, yolcularPointer);
cout << *otobus;
Surucu kamyonSurucuPointer("Husnu Tatar", "E", "37");
list<Surucu>kamyonSuruculerPointer = { kamyonSurucuPointer };
Yuk yukPointer("Kayisi", "Alibey Ozbay", "100", "44", "Malatya", "Istanbul");
Yuk yukPointer1("Bugday", "Merve Ayaz", "300", "51", "Ankara", "Kayseri");
vector<Yuk>kamyonYukler = { yukPointer,yukPointer1};
Arac* kamyon = new Kamyon("SSSS","28 DZ 284", kamyonSuruculerPointer, kamyonYukler);
cout << *kamyon;

Araclar.push_back(otobus);
Araclar.push_back(kamyon);

for (auto it = Araclar.begin(); it != Araclar.end(); ++it)
cout << *(*it);

		list<Arac*>Aracc;
		cout<<dosyadanOku("bil122_hw08.xml", Aracc);
		cout << "Araclar listesi" << endl;
		for (auto it = Aracc.begin(); it != Aracc.end(); ++it)
			cout << *(*it) << endl;
}
			catch (bad_alloc &hata)
			{
				cerr << "Hafizada yer alinamadi..." << hata.what() << endl;
				exit(-1);
			}
			catch (...)
			{
				cerr << "Belirlenemeyen bir hata olustu..." << endl;
				exit(-1);
			}
			return 0;
		
}