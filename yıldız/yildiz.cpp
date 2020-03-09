/*
Fatih Dursun Üzer
18120205041
Konsol'dan alýnan sayýlara göre ters üçgen, düz üçgen ve elmas þekli yapan program.
Sadece tek sayýlarda çalýþýr.

21 Þubat 2019- 21 February 2019
*/
#include <iostream>
using namespace std;
/*Bu fonksiyon ekrana yýldýzlardan oluþan bir üçgen yazar.
Fonksiyon sadece [3, 15] aralýðýndaki tek sayýlarda çalýþýr.
Uygun parametre gönderilmezse ekrana hiçbir þey yazdýrmadan çýkar.*/
void duzUcgen(int deger)
{
	if (deger % 2 == 0 || (deger < 3 || deger>15)) /* Girilen deger bir çift sayý ise ya da girilen deðer 3 den küçük
												      ya da 15 den büyükse programdan çýkýþ yapar*/
	{
		return;
	}
		
	int sayac, bosluk, boslukSayisi = (deger / 2), yildiz;
	for (sayac = 1; sayac <= deger; ++sayac) /*Döngü þeklinde yýldýzlarýn yazýlmasý*/
	{
		for (bosluk = 0; bosluk < boslukSayisi; ++bosluk) /* Satýrlara boþluklar koyma*/
		{
			cout << " ";
		}
		boslukSayisi = boslukSayisi - 1; /* Konulan boþluklarýn azalmasý için */
		for (yildiz = 0; yildiz < sayac; ++yildiz) /* Yýldýzlarý yerleþtirme*/
		{
			cout << "*";
		}
		if (sayac != deger) /* Son aþamada alt satýra atmasýný önlemek için þart*/
		{
			cout << endl;
		}
		++sayac;
	}
}

/*Bu fonksiyon ekrana yýldýzlardan oluþan ters bir üçgen yazar.
Fonksiyon sadece[3, 15] aralýðýndaki tek sayýlarda çalýþýr.
Uygun parametre gönderilmezse ekrana hiçbir þey yazdýrmadan çýkar.*/
void tersUcgen(int deger)
{
	if (deger % 2 == 0 || (deger < 3 || deger>15))/* Girilen deger bir çift sayý ise ya da girilen deðer 3 den küçük
												      ya da 15 den büyükse programdan çýkýþ yapar*/
	{
		return;
	}

	int sayac=0, yildiz, bosluk,yariDeger=(deger/2);
	while(sayac<=yariDeger)
	{
		for (bosluk=1;bosluk<=sayac;++bosluk)  /* Boþluklarý yerleþtirme */
		{
			cout << " ";
		}
		for (yildiz = deger; yildiz >2*sayac;--yildiz) /* Yýldýzlarý yerleþtirme*/
		{
			cout << "*";
		}
		if (sayac !=yariDeger) /* Son aþamada alt satýra atmasýný önlemek için þart*/
		{
			cout << endl;
		}
		++sayac;
	}
}
/*Bu fonksiyon ekrana yýldýzlardan oluþan bir elmas þekli yazar.
Fonksiyon sadece [5, 15] aralýðýndaki tek sayýlarda çalýþýr.
Uygun parametre gönderilmezse ekrana hiçbir þey yazdýrmadan çýkar.*/
void elmas(int deger)
{
	if (deger % 2 == 0 || (deger < 5 || deger>15)) /* Girilen deger bir çift sayý ise ya da girilen deðer 5 den küçük
												      ya da 15 den büyükse programdan çýkýþ yapar*/
	{
		return;
	}
	int sayac, bosluk, boslukSayisi = (deger / 2), yildiz;
	for (sayac = 1; sayac <= deger; ++sayac)
	{
		for (bosluk = 0; bosluk < boslukSayisi; ++bosluk)
		{
			cout << " ";
		}
		boslukSayisi=boslukSayisi-1;
		for (yildiz = 0; yildiz < sayac; ++yildiz)
		{
			cout << "*";
		}
			cout << endl;
		++sayac;
	}
	 sayac=1, yildiz=0, bosluk=0;
	while(sayac<=(deger/2))
	{
		for (bosluk = 1; bosluk <= sayac; ++bosluk)
		{
			cout << " ";
		}
		for (yildiz = deger; yildiz > (2 * sayac); --yildiz)
		{
			cout << "*";
		}
		if (sayac != deger / 2)
		{
			cout << endl;
		}
		++sayac;
	}
}




