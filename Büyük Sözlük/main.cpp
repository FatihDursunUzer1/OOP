/* 18120205041 
FATÝH DURSUN ÜZER
5.ÖDEV ÇALIÞMASI 
07.04.2019*/


#include "sozluk.h"
#include "kayit.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Kayit a;
	Kayit b;
	cin >> a;
	cin >> b;
	vector<Kayit> c = { a,b };
	Sozluk d(c);
	cout << "Vektörlerden sözlük oluþturma örneði" << endl;
	cout << d;
	Kayit a1;
	cin >> a1;
	cout << "Tek bir kayýttan sözlük oluþturma örneði";
	Sozluk yeni(a1);
	cout << yeni;
	cout << "Ýki sözlüðün toplamý örneði; " << endl;
	cout << yeni +d ;
	cout << " BOOL ÖRNEKLERÝ" << endl;
	cout << (yeni == d) << endl << (yeni != d) << endl << (yeni <= d) << endl << (yeni >= d) << endl << (yeni < d) << endl << (yeni > d) << endl;
	yeni -= d;
	cout << " -= örneði" << endl;
	cout << yeni;
	


}