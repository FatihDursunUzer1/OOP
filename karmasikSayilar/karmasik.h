/* Fatih Dursun Üzer
18120205041
3.Ödev Çalýþmasý
karmasik.h
Karmaþýk sayý sýnýfýnýn bulunduðu kýsým
Yapým süresi: 9Mart 2019- 16 Mart 2019

*/


#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ComplexNumbers
{
public:
	ComplexNumbers(double sayi);
	ComplexNumbers();
	ComplexNumbers(double reelSayi, double complexSayi);
	friend const ComplexNumbers operator +(const ComplexNumbers& sayi1, const ComplexNumbers& sayi2);
	friend const ComplexNumbers operator+(const ComplexNumbers& sayi, int a);
	friend const ComplexNumbers operator+(int sayi2, const ComplexNumbers& sayi);
	friend const ComplexNumbers operator -(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const ComplexNumbers operator -(const ComplexNumbers& sayi, double reelSayi);
	friend const ComplexNumbers operator-(double reelSayi, const ComplexNumbers& sayi);
	friend const ComplexNumbers operator *(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend ostream& operator <<(ostream& outputStream, const ComplexNumbers& sayi);
	friend istream& operator>> (istream &input, ComplexNumbers& c);
	friend const bool operator==(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const bool operator !=(const ComplexNumbers& sayi, const ComplexNumbers & sayi2);
	friend const bool operator >(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const bool operator >=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const bool operator <(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const bool operator <=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend ComplexNumbers operator *=(ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	const ComplexNumbers& operator=(const ComplexNumbers& sayi);
	friend ComplexNumbers operator+=(ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend ComplexNumbers operator-=(ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend const ComplexNumbers operator^(const ComplexNumbers& sayi, double us);
	friend ComplexNumbers operator *(double carp, const ComplexNumbers& sayi);
	friend ComplexNumbers operator *(const ComplexNumbers& sayi, double carp);
	ComplexNumbers operator ++(int a);
	ComplexNumbers operator ++();
	ComplexNumbers operator --(int a);
	friend  ComplexNumbers operator--(ComplexNumbers& sayi);
	const ComplexNumbers operator !();
	friend void Uzaklik(vector<ComplexNumbers>);
	friend const ComplexNumbers operator /(const ComplexNumbers& sayi, const ComplexNumbers& sayi2);
	friend ComplexNumbers  operator /= (const ComplexNumbers& sayi, ComplexNumbers& sayi2);
	friend const ComplexNumbers Ortalama(const vector <ComplexNumbers> v);
	double Re();
	double Im();
private:

	double reel;
	double sanal;

};



