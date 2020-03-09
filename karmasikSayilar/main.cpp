/* Fatih Dursun Üzer
18120205041
3.Ödev Çalýþmasý
main.cpp
Karmaþýk sayý programýnýn ana kýsmý
Yapým süresi:9 Mart 2019- 16 Mart 2019.

*/


#include "karmasik.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout << "Karmasik sayi ortalama hesaplama ve karmasik sayilar arasi mesafe bulma programina hosgeldiniz..." << endl;
	cout << "Dipnot: islemleri lutfen '7+i' seklide yazmayiniz. '7+1i' seklinde yaziniz.";
	char c;
	cout << "Belirlediginiz iki sayi icin dort islem yapmak icin dort islem ve baska islemleri yapmak icin '1' e tiklayiniz." << endl
		<< "Direkt olarak girecek oldugunuz karmasik sayilarin ortalamalari ,birbirine en uzak olan iki karmasik sayiyi ve aralarindaki uzakligi"
		<< " bulmak icin '2'e tiklayiniz" << endl;
	cin >> c;
	if (c == '1')
	{
		ComplexNumbers a;
		ComplexNumbers b;
		cout << "Gireceginiz ilk sayi : a , ikinci sayi : b olarak temsil edilecektir." << endl;
		cout << "Ýslemlerde kullanilmasini istediginiz ilk karmasik sayiyi giriniz" << endl;
		cin >> a;
		cout << "ikinci sayiyi giriniz" << endl;
		cin >> b;
		cout << " Toplam : " << a + b << endl << "Cikarma :" << a - b << endl << "Carpma : " << a * b << endl << "Bolme :" << a / b << endl << endl;
		cout << " Programimizin yapabildigi daha bircok islem var, gormek icin '1'e basiniz" << endl;
		char d;
		cin >> d;
		if (d == '1')
		{
			cout << "5*a   : " << 5 * a << endl << "b*5   :" << b * 5 << endl << "5/b   ::    " << 5 / b << endl << "a^2   :" << (a ^ 2) << endl << " !a   :" << !a << endl << endl;
			cout << "***************************** Esitlik Kontrolleri **************************************" << endl;
			cout << " Eger ki degerler gosterilen esitligi saglýyorsa 0'dan farklý pozitif bir sayý olarak karsiniza cikacaktir." << endl
				<< "a>b   :" << (a > b) << endl << " a<b   :" << (a < b) << endl << " a>=b   : " << (a >= b) << endl << " a<=b   : " << (a <= b) << endl
				<< " a==b   :" << (a == b) << endl << "a!=b   :" << (a != b) << endl << endl;

			cout << "***************************** ARTTIRMA VE AZALTMA  Ýslemleri****************************" << endl;
			cout << "a++   :" << a++ << endl << "++b   :" << ++b << endl << "a--   " << a-- << endl << "--b   " << --b << endl << endl;
			cout << " Simdi asil isimize gecebiliriz..." << endl;
		}
	}
	vector<ComplexNumbers> sayilar;
	ComplexNumbers sayi;
	int belirt;

	cout << "Lutfen karmasik sayi adetini giriniz " << endl;
	cin >> belirt;
	for (int a = 0; belirt <= 0; a++)
	{
		cout << "Islem yapabilmek icin lutfen 0'dan buyuk bir sayi giriniz" << endl;
		cin >> belirt;
	}
	cout << endl;
	int i = 1;
	while (i <= belirt)
	{
		cout << i << ".nci karmasik sayi:" << endl;
		cin >> sayi;
		sayilar.push_back(sayi);
		i++;
	}
	cout << "Girmis oldugunuz karmasik sayilar sirasiyla sunlardir :";
	for (int i = 0; i < belirt; ++i)
	{
		cout << sayilar[i] << endl;
	}
	Uzaklik(sayilar);
	Ortalama(sayilar);
	return 0;
}