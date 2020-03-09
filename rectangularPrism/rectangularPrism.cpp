/* Fatih Dursun Üzer 
   18120205041
   Bilgisayar Mühendisliði
   rectangularPrism.cpp
   Ödev çalýþmasý 2
*/


#include <iostream>
#include "rectangularPrism.h"
using namespace std;

 RectangularPrism::RectangularPrism(double width, double height, double length) // Veri üyelerini ilklendirme. Eðer prizma oluþmuyor ise çýkýþ yapar.
{
	w = width;
	h = height;
	l = length;
	if ((w <= 0 || h<= 0) || l <= 0) {
		cout << "Boyutlar 0\'dan buyuk olmalidir.";
		exit(1);
	}
}

 double RectangularPrism::getWidth() const // width(geniþlik) deðerini dönderir.
 {
	 return w;
 }

 double RectangularPrism::getHeight() const // height(yükseklik) deðerini dönderir
 {
	 return h;
 }

 double RectangularPrism::getLength() const // length(uzunluk) deðerini dönderir
 {
	 return l;
 }

 double RectangularPrism::surfaceArea() const // Yüzey alaný deðerini dönderir
 {
	 return 2 * ((w*h) + (w*l) + (l*h));
 }

 double RectangularPrism::volume() const // Hacim deðerini dönderir
 {
	 return w * h*l;
 }

 double RectangularPrism::setWidth(double width) // width(geniþlik) deðerini belirli þartlara göre günceller
 {
	 if (width <= 0)
	 {
		 return w;
	 }
	  w = width;
	  return w;
 }

 double RectangularPrism::setLength(double length) // length(uzunluk) deðerini belirli þartlara göre günceller.
 {
	 if (length <= 0)
	 {
		 return l;
	 }
	   l = length;
	   return l;
 }

 double RectangularPrism::setHeight(double height) // height(yükseklik) deðerini belirli þartlara göre günceller.
 {
	 if (height <= 0)
	 {
		 return h;
	 } 
	  h = height;
	   return h;
 }

 bool RectangularPrism::setDimensions(double width, double length, double height) // eðer width, length, height deðerleri 0 dan büyükse bu alýnan
 {                                                                              // üç parametrenin deðerlerini deðiþtirip sýnýftaki ilgili veri üyelerine atar ve daha sonra dönderir.
	 if ((width <= 0) || (length <= 0) || (height <= 0))
	 {
		 return false;
	 }
	 setWidth(width);
	 setLength(height);
	 setHeight(length);

	  return true;
 }

