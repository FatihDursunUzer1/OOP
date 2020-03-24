/*
Fatih Dursun Üzer
4.Ödev Çalışması 
main.cpp
25 MART 2019*/

#include <iostream>
#include <vector>
#include <string>
#include "kayit.h"

using namespace std;

int main()
{
	Kayit kayit1;
	Kayit kayit2;
	cout << "Sozluk programina hosgeldiniz. Bu program icerisine kelime ve aciklama ekleyebilir, aciklama cikarabilir, \n iki kelimeyi anlamca karsilastirabilir ve bir kelimenin bos olup olmadıgını kontrol edebilirsiniz." << endl;
	cout << "Bir ornek yapalim" << endl;
	Kayit deneme("Barbaros", "Kizil Sakal"); // Yapıcı çağrıldı.
	cout << deneme;
	cout << "Simdi bu kayıta 'Denizci' aciklamasini ekleyelim" << endl;
	string ekle = "Denizci";
	cout << deneme + ekle << endl; // String ile obje toplandı.
	cout << " Simdi de az once ekledigimiz aciklamayi cikartalim" << endl;
	string cikart = "Denizci";
	cout << deneme - cikart; // objede bulunan bir aciklama cikartildi.
	cout << "Yeni bir kelime ve aciklama olusturup diger kelime ve aciklamasiyla toplayalim" << endl;
	Kayit deneme2("Barbaros", "Türk Denizci");
	cout << deneme + deneme2; // İki objenin birleşim kümesi.
	cout << "Simdi de Bu iki kayitin esit olup olmadigini bulalim. Eger esitse 1 yazacak ekranda" << endl;
	cout << (deneme == deneme2); // Eğer bu iki kayıt objesi aynı ya da eş anlamıysa doğru(true)(1) ekrana yazar.
	cout << "ikinci olusturulan kelime ve aciklamanin bos olup olmadigini kontrol edelim. Eger bos ise ekrana 1 yazacak" << endl;
	cout << !deneme2 << endl; // ikinci obje boş ise true döndürecek.
	cout << " Son olarak bir kayıt ile bir aciklamayi karsilastiralim. aciklamamiz 'Barbaros' eger es anlamliysa ya da aynıysa 1 yazacak." << endl;
	string esitlik = "Barbaros";
	cout << (deneme2 == esitlik) << endl;// Bir obje ile stringi karşılaştırır. Eğer ki aynı ya da eş anlamlıysa 1 ekrana yazar.
	cout << "Alistirmamiz sona erdi. Tekrardan hosgeldiniz..." << endl;
	cout << "Lutfen ilk kelime ve bu ilk kelimenin aciklamalarini giriniz" << endl;
	cin >> kayit1;
	cout << "Girmis oldugunuz kelime ve aciklamalar:" << kayit1<< endl;
	if (!kayit1)
	{
		cout << "Bu kayit bos" << endl;
	}
	else
		cout << "Bu kayıt dolu" << endl;

	cout << "Aciklama ekleme bolumu " << endl;
		string eklenenAciklama;
		cout << " Eklenecek olan aciklamayi giriniz..." << endl;
		getline(cin, eklenenAciklama);
		cout << kayit1 + eklenenAciklama << endl;
		cout << " Aciklama cikarma bolumu " << endl;
		string cikarilanAciklama;
		cout << " Cikarilacak olan aciklamayi giriniz... Unutmayın ki cikarilmasini istediginiz aciklamanin su an ki aciklamalar listesinde olması gerekmektedir." << endl;
		getline(cin, cikarilanAciklama);
		cout << kayit1 - cikarilanAciklama << endl;
		cout << " İki kelimenin karsilastirilmasi icin ikinci kelimeyi ve aciklamalarini giriniz " << endl;
		cin >> kayit2;
		cout << "Girmis oldugunuz kelime ve aciklamalar : " << endl;
		cout << kayit2 << endl;
		cout << " KONTROL ASAMASI ... " << endl;

		if (kayit1 == kayit2)
		{
			cout << "Bu iki kelime es anlamlidir." << endl;
			cout << " İki kelimenin birlesim kumesi ... " << endl;
			cout << kayit1 + kayit2;
		}

		else
			cout << " Bu iki kelime es anlamli degildir." << endl;

		cout << "Programimizin daha neler yapabildiğini gormek icin lutfen bir kelime ya da bir kelimeye ait aciklama giriniz" << endl;
		string kelime;
		getline(cin, kelime);
		cout << "Girmis oldugunuz kelime/aciklama : " << kelime << endl;
		if (kayit1 == kelime)
		{
			cout << "girmis oldugunuz kelime/aciklama  ilk verdiginiz kelime ile es anlamlidir." << endl;
		}

	    if (kayit2 == kelime)
		{
			cout << "girmis oldugunuz kelime/aciklama  ikinci verdiginiz kelime ile es anlamlidir." << endl;
		}

		else
			cout << "girmis oldugunuz kelime/aciklama daha onceden verilen hicbir kelimeyle uyusmamaktadır." << endl;
		cout << "Programimizi tercih ettiginiz icin tesekkurler....." << endl;

		return 0;

}