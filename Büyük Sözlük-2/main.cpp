/* 18120205041 
FAT�H DURSUN �ZER
5 -6�DEV �ALI�MASI 
/


#include "sozluk.h"
#include "kayit.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	Kayit c("Medeniyet", "toplum bilimi");
	Sozluk b(c);
	Kayit d("Fatih", "Fetheden");
	Sozluk e(d);
	ofstream out;
	out.open("deneme2.txt");
	out << b;
	out << e;
	out.close();

	Sozluk q;
	Sozluk x;
	ifstream in;
	in.open("deneme2.txt");
	in >> q;
	in >> x;

	cout << q;
	cout << x;

	in.close();
}