

/*Fatih Dursun Üzer
18120205041
3.Ödev Çalýþmasý
karmasik.cpp
Kullanýcýdan alýnýn karmaþýk sayýlarýn ortalamasýný, en uzak iki çiftini ve aralarýndaki uzaklýðý bulan program.
Genel olarak operatörlerin aþýrý yüklenmesi konu edilmiþtir.
Yapým süresi: 9 Mart 2019- 16 Mart 2019 arasý.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include "karmasik.h"
using namespace std;

// Constructor. Gerçel bir sayýyý karmaþýk bir sayýya çevirir, bu karmaþýk sayýnýn
// sanal kýsmý '0'dýr.
ComplexNumbers::ComplexNumbers(double sayi)
{
	reel = sayi;
	sanal = 0;
}

// Default Constructor.
ComplexNumbers::ComplexNumbers()
{}

// Constructor. Bir karmaþýk sayýya ilk deðerini atar.
ComplexNumbers::ComplexNumbers(double reelSayi, double complexSayi)
{
	reel = reelSayi;
	sanal = complexSayi;
}
// Karmaþýk sayýnýn sanal kýsmýný döndürür.
double ComplexNumbers::Im()
{
	return sanal;
}

// Karmaþýk sayýnýn reel kýsmýný döndürür
double ComplexNumbers::Re()
{
	return reel;
}

// Ýki karmaþýk sayýyý toplar.
const ComplexNumbers operator +(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers toplam;
	toplam.reel = sayi.reel + sayi2.reel;
	toplam.sanal = sayi.sanal + sayi2.sanal;

	return toplam;
}

// Sol el tarafýndaki karmaþýk sayý ile sað el tarafýndaki tam sayýyý toplayan ve bu toplamý döndüren + operatoru.
const ComplexNumbers operator+(const ComplexNumbers& sayi, int a)
{
	ComplexNumbers toplam;
	toplam.reel = sayi.reel + a;
	toplam.sanal = sayi.sanal;

	return toplam;
}

// Sol el tarafýndaki tam sayý ile sað el tarafýndaki tam sayýyý toplayan ve bu toplamý döndüren + operatoru.
const ComplexNumbers operator+(int a, const ComplexNumbers& sayi)
{
	ComplexNumbers toplam;
	toplam.reel = a + sayi.reel;
	toplam.sanal = sayi.sanal;

	return toplam;
}

// Ýki karmaþýk sayýyý birbirinden çýkartýp oluþan sonucu döndürür.
const ComplexNumbers operator -(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers cikartma;
	cikartma.reel = sayi.reel - sayi2.reel;
	cikartma.sanal = sayi.sanal - sayi2.sanal;

	return cikartma;
}

//Sol el kýsmýna karmaþýk gelecek þekilde, Bir karmaþýk sayýdan bir reel sayýyý çýkartýp oluþan sonucu döndüren - operatoru
const ComplexNumbers operator -(const ComplexNumbers& sayi, double reelSayi)
{
	ComplexNumbers cikartma;
	cikartma.reel = sayi.reel - reelSayi;
	cikartma.sanal = sayi.sanal;

	return cikartma;
}

//Sol el kýsmýna reel sayi gelecek þekilde, Bir reel sayýdan bir karmaþýk sayýyý çýkartýp sonucunu döndüren - operatoru
const ComplexNumbers operator -(double reelSayi, const ComplexNumbers& sayi)
{
	ComplexNumbers cikartma;
	cikartma.reel = reelSayi - sayi.reel;
	cikartma.sanal = sayi.sanal;
	return cikartma;
}

// Programýn vereceði çýktýyý programýn yapýsýna göre düzenleyen << operatoru
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

// Programýn kullanýcýdan alacaðý girdiyi programýn yapýsýna göre düzenleyen >> operatoru.
istream& operator>> (istream &input, ComplexNumbers& c)
{
	char arti;
	char i;
	input >> c.reel >> arti >> c.sanal >> i;
	return input;
}

// Ýki karmaþýk sayýnýn eþitliðini kontrol eden == operatoru
const bool operator==(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if ((sayi.reel == sayi2.reel) && (sayi.sanal == sayi2.sanal))
		return true;
	else
		return false;
}

// Ýki karmaþýk sayýnýn eþitsizliðini kontrol eden == operatoru
const bool operator !=(const ComplexNumbers& sayi, const ComplexNumbers & sayi2)
{
	if (!((sayi.reel == sayi2.reel) || (sayi.sanal == sayi2.sanal)))
		return true;
	else
		return false;
}

// Sol el tarafýndaki karmaþýk sayýnýn sað el tarafýndaki karmaþýk sayýdan büyük olup olmadýðýný kontrol eden > operatoru..
const bool operator >(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel > sayi2.reel)
		return true;
	else
		return false;
}

// Sol el tarafýndaki karmaþýk sayýnýn sað el tarafýndaki karmaþýk sayýdan büyük veya eþit olup olmadýðýný kontrol eden  >= operatoru
const bool operator >=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel >= sayi2.reel)
		return true;
	else
		return false;
}

// Sol el tarafýndaki karmaþýk sayýnýn sað el tarafýndaki karmaþýk sayýdan küçük olup olmadýðýný kontrol eden < operatoru
const bool operator <(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel < sayi2.reel)
		return true;
	else
		return false;
}

// Sol el tarafýndaki karmaþýk sayýnýn sað el tarafýndaki karmaþýk sayýdan küçük veya eþit olup olmadýðýný kontrol eden <= operatoru
const bool operator <=(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	if (sayi.reel <= sayi2.reel)
		return true;
	else
		return false;
}

// Sol el tarafýndaki karmaþýk sayýya, kendisiyle sað el tarafýndaki karmaþýk sayýnýn toplamýný atayan += operatoru
ComplexNumbers operator+=(ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	sayi.reel += sayi2.reel;
	sayi.sanal += sayi2.sanal;

	return sayi;
}

// Sol el tarafýndaki karmaþýk sayýya, kendisiyle sað el tarafýndaki karmaþýk sayýnýn çýkartmasýný atayan  -= operatoru
ComplexNumbers operator-=(ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	sayi.reel -= sayi2.reel;
	sayi.sanal -= sayi2.sanal;

	return sayi;
}

// Bir karmaþýk sayýnýn eþleniðini döndüren  ! operatoru
const ComplexNumbers ComplexNumbers::operator !()
{
	ComplexNumbers eslenik;
	eslenik.reel = reel;
	eslenik.sanal = -sanal;

	return eslenik;
}

// ++x Karmaþýk sayýlar icin pre operatoru. Karmaþýk sayýnýn reel kýsmýnýn deðerini bir arttýr ve döndürür.
ComplexNumbers  ComplexNumbers::operator ++()
{
	reel++;

	return *this;
}

// x++ Karmaþýk sayýlar için post operatoru. Karmaþýk sayýnýn reel kýsmýnýn deðerini bir arttýrýr ancak eski deðerini döndürür.
ComplexNumbers ComplexNumbers:: operator ++(int a)
{
	a = 0;
	ComplexNumbers temp = *this;
	reel++;
	return temp;
}

//x--  Karmaþýk sayýlar için post operatoru. Karmaþýk sayýnýn reel kýsmýnýn deðerini bir azaltýr ancak eski deðerini döndürür.
ComplexNumbers ComplexNumbers:: operator --(int a)
{
	a = 0;
	ComplexNumbers temp = *this;
	reel--;
	return temp;
}

//--x  Karmaþýk sayýlar icin pre operatoru. Karmaþýk sayýnýn reel kýsmýnýn deðerini bir azaltýr ve döndürür.

ComplexNumbers operator --(ComplexNumbers& sayi)
{
	(sayi.reel)--;

	return sayi;
}

// Ýki karmasik sayiyi birbiriyle carpan * operatoru
const ComplexNumbers operator *(const ComplexNumbers& sayi, const ComplexNumbers& sayi2)
{
	ComplexNumbers carpim;
	carpim.reel = (sayi.reel*sayi2.reel) - (sayi.sanal*sayi2.sanal);
	carpim.sanal = (sayi.reel*sayi.sanal) + (sayi.sanal*sayi2.reel);

	return carpim;
}

// sol el tarafindaki sayiya, kendisiyle sol el tarafýndaki sayinin carpimini atayan *= operatoru.
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

// sol el tarafindaki karmasik sayi ile sað el tarafindaki reel sayiyi carpan operator.
ComplexNumbers operator *(const ComplexNumbers& sayi, double reelSayi)
{
	ComplexNumbers carpim;
	carpim.reel = reelSayi * (sayi.reel);
	carpim.sanal = reelSayi * (sayi.sanal);
	return carpim;
}

// sol el tarafindaki reel sayi ile sað el tarafindaki karmasik sayiyi carpan operator.
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

// Verilen karmasik sayilarin ortalamalarýný döndüren fonksiyon.
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

// Ýki karmasik sayiyi birbirine bölen / operatoru.
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



