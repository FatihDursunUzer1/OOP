/* Fatih Dursun �zer 
   18120205041
   Bilgisayar M�hendisli�i
   rectangularPrism.cpp
   �dev �al��mas� 2
*/


#include <iostream>
#include "rectangularPrism.h"
using namespace std;

 RectangularPrism::RectangularPrism(double width, double height, double length) // Veri �yelerini ilklendirme. E�er prizma olu�muyor ise ��k�� yapar.
{
	w = width;
	h = height;
	l = length;
	if ((w <= 0 || h<= 0) || l <= 0) {
		cout << "Boyutlar 0\'dan buyuk olmalidir.";
		exit(1);
	}
}

 double RectangularPrism::getWidth() const // width(geni�lik) de�erini d�nderir.
 {
	 return w;
 }

 double RectangularPrism::getHeight() const // height(y�kseklik) de�erini d�nderir
 {
	 return h;
 }

 double RectangularPrism::getLength() const // length(uzunluk) de�erini d�nderir
 {
	 return l;
 }

 double RectangularPrism::surfaceArea() const // Y�zey alan� de�erini d�nderir
 {
	 return 2 * ((w*h) + (w*l) + (l*h));
 }

 double RectangularPrism::volume() const // Hacim de�erini d�nderir
 {
	 return w * h*l;
 }

 double RectangularPrism::setWidth(double width) // width(geni�lik) de�erini belirli �artlara g�re g�nceller
 {
	 if (width <= 0)
	 {
		 return w;
	 }
	  w = width;
	  return w;
 }

 double RectangularPrism::setLength(double length) // length(uzunluk) de�erini belirli �artlara g�re g�nceller.
 {
	 if (length <= 0)
	 {
		 return l;
	 }
	   l = length;
	   return l;
 }

 double RectangularPrism::setHeight(double height) // height(y�kseklik) de�erini belirli �artlara g�re g�nceller.
 {
	 if (height <= 0)
	 {
		 return h;
	 } 
	  h = height;
	   return h;
 }

 bool RectangularPrism::setDimensions(double width, double length, double height) // e�er width, length, height de�erleri 0 dan b�y�kse bu al�nan
 {                                                                              // �� parametrenin de�erlerini de�i�tirip s�n�ftaki ilgili veri �yelerine atar ve daha sonra d�nderir.
	 if ((width <= 0) || (length <= 0) || (height <= 0))
	 {
		 return false;
	 }
	 setWidth(width);
	 setLength(height);
	 setHeight(length);

	  return true;
 }

