

/*Fatih Dursun �zer
18120205041
3.�dev �al��mas�
karmasik.cpp
Kullan�c�dan al�n�n karma��k say�lar�n ortalamas�n�, en uzak iki �iftini ve aralar�ndaki uzakl��� bulan program.
Genel olarak operat�rlerin a��r� y�klenmesi konu edilmi�tir.
Yap�m s�resi: 9 Mart 2019- 16 Mart 2019 aras�.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include "karmasik.h"
using namespace std;

// Constructor. Ger�el bir say�y� karma��k bir say�ya �evirir, bu karma��k say�n�n
// sanal k�sm� '0'd�r.
ComplexNumbers::ComplexNumbers(double sayi)
{
	reel = sayi;
	sanal = 0;
}

// Default Constructor.
ComplexNumbers::ComplexNumbers()
{}

// Constructor. Bir karma��k say�ya ilk de�erini atar.
ComplexNumbers::ComplexNumbers(double reelSayi, double complexSayi)
{
	reel = reelSayi;
	sanal = complexSayi;
}
// Karma��k say�n�n sanal k�sm�n� d�nd�r�r.
double ComplexNumbers::Im()
{
	return sanal;
}

// Karma��k say�n�n reel k�sm�n� d�nd�r�r
double ComplexNumbers::Re()
{
	return reel;
}

// �ki karma��k say�y� toplar.
const ComplexNumbers operator +(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers toplam;
	toplam.reel = sayi.reel + sayi2.reel;
	toplam.sanal = sayi.sanal + sayi2.sanal;

	return toplam;
}

// Sol el taraf�ndaki karma��k say� ile sa� el taraf�ndaki tam say�y� toplayan ve bu toplam� d�nd�ren + operatoru.
const ComplexNumbers operator+(const ComplexNumbers& sayi, int a)
{
	ComplexNumbers toplam;
	toplam.reel = sayi.reel + a;
	toplam.sanal = sayi.sanal;

	return toplam;
}

// Sol el taraf�ndaki tam say� ile sa� el taraf�ndaki tam say�y� toplayan ve bu toplam� d�nd�ren + operatoru.
const ComplexNumbers operator+(int a, const ComplexNumbers& sayi)
{
	ComplexNumbers toplam;
	toplam.reel = a + sayi.reel;
	toplam.sanal = sayi.sanal;

	return toplam;
}

// �ki karma��k say�y� birbirinden ��kart�p olu�an sonucu d�nd�r�r.
const ComplexNumbers operator -(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers cikartma;
	cikartma.reel = sayi.reel - sayi2.reel;
	cikartma.sanal = sayi.sanal - sayi2.sanal;

	return cikartma;
}

//Sol el k�sm�na karma��k gelecek �ekilde, Bir karma��k say�dan bir reel say�y� ��kart�p olu�an sonucu d�nd�ren - operatoru
const ComplexNumbers operator -(const ComplexNumbers& sayi, double reelSayi)
{
	ComplexNumbers cikartma;
	cikartma.reel = sayi.reel - reelSayi;
	cikartma.sanal = sayi.sanal;

	return cikartma;
}

//Sol el k�sm�na reel sayi gelecek �ekilde, Bir reel say�dan bir karma��k say�y� ��kart�p sonucunu d�nd�ren - operatoru
const ComplexNumbers operator -(double reelSayi, const ComplexNumbers& sayi)
{
	ComplexNumbers cikartma;
	cikartma.reel = reelSayi - sayi.reel;
	cikartma.sanal = sayi.sanal;
	return cikartma;
}

// Program�n verece�i ��kt�y� program�n yap�s�na g�re d�zenleyen << operatoru
ostream& operator <<(ostream& outputStream, const ComplexNumbers& sayi)
{
	outputStream << sayi.reel;
	if (sayi.sanal > 0)
		outputStream << "+";
	if (sayi.sanal != 0)
	{
		if (sayi.sanal != 1)
			outputStream << sayi.sanal << "i";
		else
			outputStream << "i";
	}
	return outputStream;
}

// Program�n kullan�c�dan alaca�� girdiyi program�n yap�s�na g�re d�zenleyen >> operatoru.
istream& operator>> (istream &input, ComplexNumbers& c)
{
	char arti;
	char i;
	input >> c.reel >> arti >> c.sanal >> i;
	return input;
}

// �ki karma��k say�n�n e�itli�ini kontrol eden == operatoru
const bool operator==(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if ((sayi.reel == sayi2.reel) && (sayi.sanal == sayi2.sanal))
		return true;
	else
		return false;
}

// �ki karma��k say�n�n e�itsizli�ini kontrol eden == operatoru
const bool operator !=(const ComplexNumbers& sayi, const ComplexNumbers & sayi2)
{
	if (!((sayi.reel == sayi2.reel) || (sayi.sanal == sayi2.sanal)))
		return true;
	else
		return false;
}

// Sol el taraf�ndaki karma��k say�n�n sa� el taraf�ndaki karma��k say�dan b�y�k olup olmad���n� kontrol eden > operatoru..
const bool operator >(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel > sayi2.reel)
		return true;
	else
		return false;
}

// Sol el taraf�ndaki karma��k say�n�n sa� el taraf�ndaki karma��k say�dan b�y�k veya e�it olup olmad���n� kontrol eden  >= operatoru
const bool operator >=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel >= sayi2.reel)
		return true;
	else
		return false;
}

// Sol el taraf�ndaki karma��k say�n�n sa� el taraf�ndaki karma��k say�dan k���k olup olmad���n� kontrol eden < operatoru
const bool operator <(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel < sayi2.reel)
		return true;
	else
		return false;
}

// Sol el taraf�ndaki karma��k say�n�n sa� el taraf�ndaki karma��k say�dan k���k veya e�it olup olmad���n� kontrol eden <= operatoru
const bool operator <=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel <= sayi2.reel)
		return true;
	else
		return false;
}

// Sol el taraf�ndaki karma��k say�ya, kendisiyle sa� el taraf�ndaki karma��k say�n�n toplam�n� atayan += operatoru
ComplexNumbers operator+=(ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	sayi.reel += sayi2.reel;
	sayi.sanal += sayi2.sanal;

	return sayi;
}

// Sol el taraf�ndaki karma��k say�ya, kendisiyle sa� el taraf�ndaki karma��k say�n�n ��kartmas�n� atayan  -= operatoru
ComplexNumbers operator-=(ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	sayi.reel -= sayi2.reel;
	sayi.sanal -= sayi2.sanal;

	return sayi;
}

// Bir karma��k say�n�n e�leni�ini d�nd�ren  ! operatoru
const ComplexNumbers ComplexNumbers::operator !()
{
	ComplexNumbers eslenik;
	eslenik.reel = reel;
	eslenik.sanal = -sanal;

	return eslenik;
}

// ++x Karma��k say�lar icin pre operatoru. Karma��k say�n�n reel k�sm�n�n de�erini bir artt�r ve d�nd�r�r.
ComplexNumbers  ComplexNumbers::operator ++()
{
	reel++;

	return *this;
}

// x++ Karma��k say�lar i�in post operatoru. Karma��k say�n�n reel k�sm�n�n de�erini bir artt�r�r ancak eski de�erini d�nd�r�r.
ComplexNumbers ComplexNumbers:: operator ++(int a)
{
	a = 0;
	ComplexNumbers temp = *this;
	reel++;
	return temp;
}

//x--  Karma��k say�lar i�in post operatoru. Karma��k say�n�n reel k�sm�n�n de�erini bir azalt�r ancak eski de�erini d�nd�r�r.
ComplexNumbers ComplexNumbers:: operator --(int a)
{
	a = 0;
	ComplexNumbers temp = *this;
	reel--;
	return temp;
}

//--x  Karma��k say�lar icin pre operatoru. Karma��k say�n�n reel k�sm�n�n de�erini bir azalt�r ve d�nd�r�r.

ComplexNumbers operator --(ComplexNumbers& sayi)
{
	(sayi.reel)--;

	return sayi;
}

// �ki karmasik sayiyi birbiriyle carpan * operatoru
const ComplexNumbers operator *(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers carpim;
	carpim.reel = (sayi.reel*sayi2.reel) - (sayi.sanal*sayi2.sanal);
	carpim.sanal = (sayi.reel*sayi.sanal) + (sayi.sanal*sayi2.reel);

	return carpim;
}

// sol el tarafindaki sayiya, kendisiyle sol el taraf�ndaki sayinin carpimini atayan *= operatoru.
ComplexNumbers operator *=(ComplexNumbers& sayi, const ComplexNumbers& sayi2) //Biraz daha bak;
{
	sayi = sayi * sayi2;

	return sayi;
}
// Atama operatoru..
const ComplexNumbers& ComplexNumbers:: operator=(const ComplexNumbers& sayi)
{
	 if (this != &sayi)
	{
		reel = sayi.reel;
		sanal = sayi.sanal;
	}
	return *this;
}

// Bir karmasik sayinin ussunu alan ^ operatoru.
const ComplexNumbers operator^(const ComplexNumbers& sayi, double us)
{
	if (us == 1)
		return sayi;
	else if (us == 0)
		return 1;
	else
		return sayi * (sayi ^ (us - 1));
}

// sol el tarafindaki karmasik sayi ile sa� el tarafindaki reel sayiyi carpan operator.
ComplexNumbers operator *(const ComplexNumbers& sayi, double reelSayi)
{
	ComplexNumbers carpim;
	carpim.reel = reelSayi * (sayi.reel);
	carpim.sanal = reelSayi * (sayi.sanal);
	return carpim;
}

// sol el tarafindaki reel sayi ile sa� el tarafindaki karmasik sayiyi carpan operator.
ComplexNumbers operator *(double reelSayi, const ComplexNumbers& sayi)
{
	ComplexNumbers carpim;
	carpim.reel = reelSayi * (sayi.reel);
	carpim.sanal = reelSayi * (sayi.sanal);
	return carpim;
}

// Karmasik sayilar arasindaki uzakligi bulan fonksiyon.
void Uzaklik(vector<ComplexNumbers> v)
{
	 ComplexNumbers iMin;
	iMin.reel = v[0].reel;
	iMin.sanal = v[0].sanal;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].reel <= iMin.reel)
		{
			iMin.reel = v[i].reel;
			iMin.sanal = v[i].sanal;
		}
	}
	 ComplexNumbers iMax;
	iMax.reel = v[0].reel;
	iMax.sanal = v[0].sanal;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].reel >= iMax.reel)
		{
			iMax.reel = v[i].reel;
			iMax.sanal = v[i].sanal;
		}
	}
	double dist;
	dist = sqrt(((iMax.reel - iMin.reel) *(iMax.reel - iMin.reel)) + ((iMax.sanal - iMin.sanal) * (iMax.sanal - iMin.sanal)));



	cout << "Birbirine en uzak olan iki cift :" << iMin << "ve " << iMax << endl<< "Aralarindaki uzaklik ise : " <<dist << endl;
	return;
}

// Verilen karmasik sayilarin ortalamalar�n� d�nd�ren fonksiyon.
const ComplexNumbers Ortalama(const vector <ComplexNumbers> v)
{
	ComplexNumbers ort;
	ComplexNumbers toplam = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		toplam = toplam + v[i];
	}

	ort = (toplam / v.size());

	cout<< "Girmis oldugunuz karmasik sayilarin ortalamasi :" << ort << endl;

	return ort;
}

// �ki karmasik sayiyi birbirine b�len / operatoru.
const ComplexNumbers  operator / (const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers bolum = 0;
		ComplexNumbers pay;
		double payda;
		pay.reel = (sayi.reel*sayi2.reel) + (sayi.sanal*sayi2.sanal);
		pay.sanal = (sayi.reel*(-sayi2.sanal)) + (sayi.sanal*sayi2.reel);
		payda = (sayi2.reel*sayi2.reel) + (sayi2.sanal*sayi2.sanal);
		bolum.reel = pay.reel / payda;
		bolum.sanal = pay.sanal / payda;

		if (payda == 0)
		{
			cout << "Payda '0' olamaz. Programdan cikiliyor."
				exit(1);
	    }
		
		return bolum;
}

// sol el tarafindaki karmasik sayiya kendisiyle sol el tarafindaki karmasik sayinin bolumunu atayan /= operatoru.
ComplexNumbers  operator /= (ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	sayi = (sayi / sayi2);

	return sayi;
}



