
/* Fatih Dursun Üzer
 18120205041
 Bilgisayar Mühendisliði
 rectanguarPrism.h dosyasý
 Ödev Çalýþmasý 2
*/

#pragma once

class RectangularPrism
{
public: // Member data functions...
	RectangularPrism(double width = 1, double height = 1, double length = 1); // Constructor
	double getWidth() const ; // width deðerini alýr
	double getHeight() const  ; // height deðerini alýr
	double getLength() const  ; // Length deðerini alýr
	double surfaceArea() const ; // Yüzey alanýný hesaplar ve dönderir
	double volume() const ; // Hacimi hesaplayýp dönderir.
	double setWidth(double width); // width deðerini düzenler
	double setHeight(double height); // height deðerini düzenler
	double setLength(double length); // length deðerini düzenler
	bool setDimensions(double width, double length, double height); //setWidth, setHeight , setLength fonksiyonlarýný içerir.
private:
    double w; // Private member data 
	double h; // Private member data 
	double l; // Private member data
};
