
/* Fatih Dursun �zer
 18120205041
 Bilgisayar M�hendisli�i
 rectanguarPrism.h dosyas�
 �dev �al��mas� 2
*/

#pragma once

class RectangularPrism
{
public: // Member data functions...
	RectangularPrism(double width = 1, double height = 1, double length = 1); // Constructor
	double getWidth() const ; // width de�erini al�r
	double getHeight() const  ; // height de�erini al�r
	double getLength() const  ; // Length de�erini al�r
	double surfaceArea() const ; // Y�zey alan�n� hesaplar ve d�nderir
	double volume() const ; // Hacimi hesaplay�p d�nderir.
	double setWidth(double width); // width de�erini d�zenler
	double setHeight(double height); // height de�erini d�zenler
	double setLength(double length); // length de�erini d�zenler
	bool setDimensions(double width, double length, double height); //setWidth, setHeight , setLength fonksiyonlar�n� i�erir.
private:
    double w; // Private member data 
	double h; // Private member data 
	double l; // Private member data
};
