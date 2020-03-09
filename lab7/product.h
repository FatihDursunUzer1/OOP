
/* 18120205041 Fatih Dursun Üzer 7.lab çalışması product.h */

#pragma once
#include<string>
#include<iostream>
using namespace std;
class product
{
public:
	product();
	product(string namev,double pricev);
	void printinfo();
	string getname();
	double getprice();
	void setname(string namev);
	void setprice(double pricev);
protected:
	string name;
	double price;
};
class camera :public product
{
public:
	camera();
	camera(unsigned num);
	camera(const string& namev, const double& pricev,unsigned num);
	void printinfo();
	unsigned getnumber();
	void setnumber(unsigned num);
protected:
	unsigned numberofpixels;
};
class phone :public product
{
public:
	phone();
	phone(const string& namev, const double& pricev, double sarv);
	void printinfo();
	double getsar();
	void setsar(double sarv);
protected:
	double sar;
};
class smartphone :public phone,camera
{
public:
	smartphone(const string& namev, const double& pricev, double sarv,unsigned num,bool fourg);
	void printinfo();
private:
	bool fourGsupport;
};
