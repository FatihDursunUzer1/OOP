/*
Fatih Dursun �zer
18120205041
Konsol'dan al�nan say�lara g�re ters ��gen, d�z ��gen ve elmas �ekli yapan program.
Sadece tek say�larda �al���r.

21 �ubat 2019- 21 February 2019
*/
#include <iostream>
using namespace std;
/*Bu fonksiyon ekrana y�ld�zlardan olu�an bir ��gen yazar.
Fonksiyon sadece [3, 15] aral���ndaki tek say�larda �al���r.
Uygun parametre g�nderilmezse ekrana hi�bir �ey yazd�rmadan ��kar.*/
void duzUcgen(int deger)
{
	if (deger % 2 == 0 || (deger < 3 || deger>15)) /* Girilen deger bir �ift say� ise ya da girilen de�er 3 den k���k
												      ya da 15 den b�y�kse programdan ��k�� yapar*/
	{
		return;
	}
		
	int sayac, bosluk, boslukSayisi = (deger / 2), yildiz;
	for (sayac = 1; sayac <= deger; ++sayac) /*D�ng� �eklinde y�ld�zlar�n yaz�lmas�*/
	{
		for (bosluk = 0; bosluk < boslukSayisi; ++bosluk) /* Sat�rlara bo�luklar koyma*/
		{
			cout << " ";
		}
		boslukSayisi = boslukSayisi - 1; /* Konulan bo�luklar�n azalmas� i�in */
		for (yildiz = 0; yildiz < sayac; ++yildiz) /* Y�ld�zlar� yerle�tirme*/
		{
			cout << "*";
		}
		if (sayac != deger) /* Son a�amada alt sat�ra atmas�n� �nlemek i�in �art*/
		{
			cout << endl;
		}
		++sayac;
	}
}

/*Bu fonksiyon ekrana y�ld�zlardan olu�an ters bir ��gen yazar.
Fonksiyon sadece[3, 15] aral���ndaki tek say�larda �al���r.
Uygun parametre g�nderilmezse ekrana hi�bir �ey yazd�rmadan ��kar.*/
void tersUcgen(int deger)
{
	if (deger % 2 == 0 || (deger < 3 || deger>15))/* Girilen deger bir �ift say� ise ya da girilen de�er 3 den k���k
												      ya da 15 den b�y�kse programdan ��k�� yapar*/
	{
		return;
	}

	int sayac=0, yildiz, bosluk,yariDeger=(deger/2);
	while(sayac<=yariDeger)
	{
		for (bosluk=1;bosluk<=sayac;++bosluk)  /* Bo�luklar� yerle�tirme */
		{
			cout << " ";
		}
		for (yildiz = deger; yildiz >2*sayac;--yildiz) /* Y�ld�zlar� yerle�tirme*/
		{
			cout << "*";
		}
		if (sayac !=yariDeger) /* Son a�amada alt sat�ra atmas�n� �nlemek i�in �art*/
		{
			cout << endl;
		}
		++sayac;
	}
}
/*Bu fonksiyon ekrana y�ld�zlardan olu�an bir elmas �ekli yazar.
Fonksiyon sadece [5, 15] aral���ndaki tek say�larda �al���r.
Uygun parametre g�nderilmezse ekrana hi�bir �ey yazd�rmadan ��kar.*/
void elmas(int deger)
{
	if (deger % 2 == 0 || (deger < 5 || deger>15)) /* Girilen deger bir �ift say� ise ya da girilen de�er 5 den k���k
												      ya da 15 den b�y�kse programdan ��k�� yapar*/
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




