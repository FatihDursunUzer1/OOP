
/* 18120205041 Fatih Dursun Üzer 7.lab çalışması product.cpp */
#include<iostream>
#include"product.h"
using namespace std;

product::product()
{
}

product::product(string namev, double pricev)
{
	name=namev;
	price=pricev;
}

void product::printinfo()
{
	cout << "name  " << name<<endl;
	cout << "price  " << price << endl;
}

string product::getname()
{
	return name;
}

double product::getprice()
{
	return price;
}

void product::setname(string namev)
{
	name = namev;
}

void product::setprice(double pricev)
{
	price = pricev;
}

camera::camera() :product()
{
	
}

camera::camera(unsigned num)
{
	numberofpixels = num;
}

camera::camera(const string& namev, const double& pricev, unsigned num)
	:product(namev,pricev)
{
	numberofpixels=num;
}



void camera::printinfo()
{
	cout << "name  " << name << endl;
	cout << "price  " << price << endl;
	cout << "camera pixel  " << numberofpixels << endl;
}

unsigned camera::getnumber()
{
	return numberofpixels;
}

void camera::setnumber(unsigned num)
{
	numberofpixels = num;
}

phone::phone():product()
{
}

phone::phone(const string& namev, const double& pricev, double sarv)
	: product(namev, pricev)
{
	sar = sarv;
}
void phone::printinfo()
{
	cout << "name  " << name << endl;
	cout << "price  " << price << endl;
	cout << "phone sar  " << sar << endl;
}

double phone::getsar()
{
	return sar;
}

void phone::setsar(double sarv)
{
	sar = sarv;
}



smartphone::smartphone(const string& namev, const double& pricev, double sarv, unsigned num, bool fourg)
	:phone(namev,pricev,sarv), camera( num)
{
	fourGsupport = fourg;
}

void smartphone::printinfo()
{
	cout << "name  " << product::getname() << endl;
	cout << "price  " << product::getprice() << endl;
	cout << "phone sar  " << phone::getsar() << endl;
	cout << "camera pixel  " << camera::getnumber() << endl;
	if(fourGsupport)
		cout << "the phone is supporting 4G network" << endl;
	else
		cout <<"the phone is not supporting 4G network" << endl;
}
