/* 18120205041 
FAT�H DURSUN �ZER
5.�DEV �ALI�MASI 
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
	cout << "Vekt�rlerden s�zl�k olu�turma �rne�i" << endl;
	cout << d;
	Kayit a1;
	cin >> a1;
	cout << "Tek bir kay�ttan s�zl�k olu�turma �rne�i";
	Sozluk yeni(a1);
	cout << yeni;
	cout << "�ki s�zl���n toplam� �rne�i; " << endl;
	cout << yeni +d ;
	cout << " BOOL �RNEKLER�" << endl;
	cout << (yeni == d) << endl << (yeni != d) << endl << (yeni <= d) << endl << (yeni >= d) << endl << (yeni < d) << endl << (yeni > d) << endl;
	yeni -= d;
	cout << " -= �rne�i" << endl;
	cout << yeni;
	


}