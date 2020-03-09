
 /*Fatih Dursun Üzer 18120205041
  */
#pragma once
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Sekil
{
public:
	Sekil();
	Sekil(string & ad);
	virtual ~Sekil();
	virtual double alan() = 0;
	virtual double cevre() = 0;
	virtual void bilgiYazdýr();
	static unsigned int olusturulmuSekilSayisi;
	string getAd();
private:
	string ad;
};

class Ucgen : public Sekil
{
public:
	Ucgen();
	Ucgen(string& ad, double k1, double k2, double k3);
	~Ucgen();
	double alan();
	double cevre();
	void bilgiYazdýr();
private:
	double kenarlar[3];

};
class Dortgen : public Sekil
{
public:
	Dortgen();
	Dortgen(string & ad);
	virtual ~Dortgen();
};
class Kare : public Dortgen
{
public:
	Kare();
	Kare(string & ad, double a);
	~Kare();
	double alan();
	double cevre();
	void bilgiYazdýr();
private:
	double a;

};

class Dikdortgen : public Dortgen
{
public:
	Dikdortgen();
	Dikdortgen(string & ad, double a, double b);
	~Dikdortgen();
	double alan();
	double cevre();
	void bilgiYazdýr();
private:
	double a, b;
};