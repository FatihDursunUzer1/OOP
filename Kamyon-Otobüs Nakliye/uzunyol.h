
/*Fatih Dursun Uzer 
18120205041
�stanbul Medeniyet �niversitesi 
Odev-8
uzunyol.h
07.06.2019*/

#pragma once
#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <new>
#include <vector>

using namespace std;
class ERROR /*Try Catch icin olusturulan sinif. Gelen parametreye g�re throw yapmay� sa�lar*/
{
public:
	ERROR()
	{
		throw bad_alloc();
	}

	ERROR(unsigned int a)
	{
		throw out_of_range("Dizinin kapasitesini astiniz.");
	}

};



using namespace std;
enum ehliyetSinifi { B, C, D, E };
class Surucu 
{
	friend ostream& operator <<(ostream & out, const Surucu& yeni); //Arac(lar)�n suruculer�n�n isimlerini,yaslarini ve ehliyet siniflarini yazdiran operator
private:
	ehliyetSinifi ehliyet; //Surucunun ehliyet t�r�n� tutar
	char *ad;//Surucunun ismini tutar
	unsigned int i : 5; //Surucunun yasini 5 bit le sinirlar. 30-62 arasi degerler alabilir
	unsigned int yas;//Surucunun yasini tutar
	int elemanSayisi;//Surucunun ismindeki toplam karakter sayisini tutar.
public:
	
	Surucu(); // Bo� bir surucu s�n�f� olusturur.
	Surucu(const char* ad�,const string ehliyett, string yass); //Constructor. Bir Surucu objesi olu�turur.
	char getEhliyet() const; //Ehliyet sinifi degeri dondurur
	unsigned int getYas()const; //Surucunun yasini donderir.
	~Surucu(); //Destructor
	Surucu& operator=(const Surucu& diger); // atama operatoru
	Surucu(const Surucu& diger); // Copy constructor
	void setAd(const char* ad); //Surucunun ismini degistirir
	void setYas(unsigned int yas); //Surucunun yasini degistirir
	void setEhliyet(ehliyetSinifi ehliyet); //Surucunun ehliyet sinifini degistirir.
	int getElemanSayisi() const //Surucunun isminde bulunan karakterlerin sayisini donderir
	{
		return elemanSayisi;
	}
	char* getAd() const //Surucunun ismini donderir
	{
		return ad;
	}

};

class Yolcu
{
	friend ostream& operator<<(ostream& out, const Yolcu& yeni);//Yolcu(lar) hakkindaki bilgileri ekrana yazdiran fonksiyon
public:
	Yolcu();//Bos bir yolcu objesi olusturur.
	Yolcu(const char * ad, const char* binisYeri, string inisYeri);//Constructor. Bir yolcu objesi olu�turur
	Yolcu(const Yolcu&digerYolcu); //Copy Constructor
	Yolcu& operator=(const Yolcu& digerYolcu); //Atama operatoru
	~Yolcu();//Destructor
	string getInisYeri()const ; //In�syerini donderir
	int getElemanSayisiAd()const ; //Yolcunun ismindeki karakter sayisini donderir
	int getElemanSayisiBinis()const ; //Binis yerinin ismindeki karakter sayisini donderir.
	void set�nisYeri(string inisYeri); //�nisYerini degistirir.
	void setBinisYeri(const char * binisYeri); //BinisYerini degistirir.
	void setAd(const char* ad); //Yolcunun ismini degistirir
	char* getAd() //Yolcunun ismini donderir.
	{
		return ad;
	}
	string getBinisYeri() //Binisyerini donderir
	{
		return binisYeri;
	}
private:
	char* ad;//Yolcunun ismini tutar
	char* binisYeri;//Yolcunun bindi�i yeri tutar.
	string inisYeri;//Yolcunun indi�i yeri tutar
	int elemanSayisiAd; // Yolcunun ismindeki toplam karakter sayisini tutar.
	int elemanSayisiBinis;//Yolcunun binis yerinin ismindeki toplam karakter sayisini tutar.
};

class Yuk 
{
	friend ostream& operator<<(ostream& out, const Yuk& yeni); //Yuk veya yukler hakk�ndaki bilgileri ekrana yazd�ran operator
public:
	Yuk();//Bos bir yuk objesi olusturmaya yarayan Constructor
	Yuk(const char* icerik, string alici, string agirlik, string hacim, string binisYeri, string inisYeri);//Constructor. Bir yuk objesi olusturur
	Yuk(const Yuk &diger);  //Copy Constructor
	~Yuk();//Destructor
	Yuk& operator=(const Yuk& diger); //Atama operatoru
	double getHacim() const; //Yukun hacmini donderir.
	double getAgirlik() const; //Yukun agirligini donderir.
	string getAlici()const ; //Yukun alicisini donderir.
	string getBinisYeri()const ; //Yukun binisyerini donderir.
	string get�nisYeri() const;  //Yukun In�syerini donderir.
	void setHacim(double hacim); //Yukun hacmini degistirir.
	void setAgirlik(double agirlik);  //Yukun agirligini degistirir.
	void setAlici(string alici); //Yukun alicisini degistirir
	void setBinisYeri(string binisYeri);  //Yukun binisyerini degistirir.
	void set�nisYeri(string inisYeri); //Yukun inisyerini degistirir.
	void set�cerik(const char* icerik); //Yukun icerigini degistirir.
	char* get�cerik(char* icerik) const //Yukun icerigini donderir.
	{
		return icerik;
	}
private:
	char* icerik;//Y�k�n i�eri�ini tutar
	double agirlik;//Y�k�n a��rl���n� tutar
	double hacim;//Y�k�n hacmini tutar
	string alici;//Y�k�n al�c�s�n�n ismini tutar
	string binisYeri;//Y�k�n binis yerinin ismini tutar.
	string inisYeri;// Y�k�n inis yerinin ismini tutar.
	int icerikElemanSayisi;//Y�k�n i�eri�inin ismindeki toplam karakter sayisini tutar.

};

class Arac //Base Class. Objesi olu�turulamaz.
{
	friend ostream& operator<< (ostream& out, const Arac& yeniArac); //Arac veya Araclar hakk�ndaki bilgiyi print fonksiyonu yardimi ile ekrana yazdirir
public:
	virtual void print(ostream& out)const=0; //S�n�f� sanal yapmaya yaran fonksiyon. operator <<'a yard�mc� olur.
	Arac();//Bos bir arac objesi olusturan Constructor
	Arac(const char* plaka, list<Surucu> Suruculerr);//Constructor.Bir ara� objesi olu�turur.
	virtual ~Arac();//Destructor
	Arac(const Arac& digerArac); //Copy Constructor
	Arac& operator=(const Arac& digerArac);//Atama operatoru
	list<Surucu> getSuruculer() const //Suruculer� donderir.
	{
		return Suruculer;
	}
	void setPlaka(const char* plaka); //Plakay� degistirir.
	int getPlakaElemanSayisi() const //Arac�n Plakas�nda bulunan karakter sayisini donderir.
	{
		return plakaElemanSayisi;
	}
	void setSuruculer(list<Surucu>Suruculerr); //Suruculer� degistirir.
	char* getPlaka() const //Arac�n plakas�n� donderir.
	{
		return plaka;
	}

private:
	char* plaka;//Aracin plakasini tutar.
	list<Surucu> Suruculer;
	int plakaElemanSayisi;//Aracin plakasindaki toplam karakter sayisini tutar.
};

class Otobus :public Arac // Arac s�n�f�ndan t�retilen bir s�n�ft�r. 
{
	 friend ostream& operator<< (ostream& out,  const Otobus& yeniOtobus);//Otobus veya Otobusler hakk�ndaki bilgileri ekrana yazdirir.
public:
	virtual void print(ostream& out)const;//Sanall��� sa�layan fonksiyon.operator << '�n sanal olmas�n� sa�lar.
	Otobus();//Bos bir otobus objesi olusturan Constructor.
	Otobus(const char* plaka, list<Surucu>Suruculer, vector<Yolcu> Yolcular);//Constructor.Bir otobus objesi olu�turur.
	virtual ~Otobus();//Destructor
	Otobus(const Otobus& digerOtobus);//Copy Constructor
	Otobus& operator=(const Otobus& digerOtobus); //Atama operatoru buraya bi daha bak FDU
	vector<Yolcu>& getYolcular();//Yolcular� donderir.
	 void setYolcular(vector<Yolcu>Yolcular); //Yolcular� degistirir.
private:
	vector<Yolcu> Yolcular;
};

class Kamyon : public Arac
{
	friend ostream& operator <<(ostream& out, const Kamyon& yeniKamyon);
	
public:
	virtual void print(ostream& out)const;//Sanall��� sa�layan fonksiyon. operator << '�n sanal olmas�n� sa�lar.
	Kamyon();//Bos bir kamyon objesi olusturan Constructor
	Kamyon(const char* ozluSoz, const char* plaka, list<Surucu> Suruculer, vector<Yuk>Yukler); //Constructor
	Kamyon(const Kamyon& digerKamyon);//Copy Constructor
	virtual ~Kamyon();
    Kamyon& operator=(const Kamyon& digerKamyon); //Atama operatoru
	void setOzluSoz(const char* ozluSoz);//OzluSozu degistirir.
	char * getOzluSoz() const; //OzluSozu donderir
	vector<Yuk> getYukler() //Yukleri donderir
	{
		return Yukler;
	}
	void setYukler(vector<Yuk>Yukler); //Yukleri degistirir.
private:
	char* ozluSoz;//Ozlu Soz u tutar.
	int ozluSozElemanSayisi;//OzluSozun icerisindeki toplam karakter sayisini tutar.
	vector<Yuk>Yukler;
};
