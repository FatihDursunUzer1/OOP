#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
	// Verilen outFile dosyasina aþaðýdaki þekilde öðrenci bilgilerini yazar
	/*
	Ogrenci Adi: Zeynep Kodyazar
	Ogrenci No: 12345678
	Notlari: 80 90
	Ortalama: 85.00
	*/
	friend ofstream & operator << (ofstream &outFile, const Student &s);

	// grades.txt dosyasindan ogrencinin notlarini okur ve grades vektorune ekler (Mevcut notlar silinir.)
	friend ifstream & operator >> (ifstream &inFile, Student &s);
public:
	Student(const string & name, const string & studentNumber);

	// ogrencinin kac tane not kaydi oldugunu donderir
	int getNumberOfGrades() const;

	// ogrencinin not ortalamasini donderir
	double getAverage() const;

	string getStudentNumber();
	string getName();
	vector <double> getGrades();
	vector<double> grades;

private:
	//vector<double> grades;
	string name;
	string studentNumber;
	//vector<double> grades;
};

class Classroom
{
public:
	Classroom(const string & classFilePath);

	// siniftaki tum ogrencilerin notlarini verilen dosyadan okur
	int readGradesFromAFile(const string & classFilePath);

	// siniftaki tum ogrencilerin notlarini verilen dosyaya alt alta yazar
	// Verilen outFile dosyasina aþaðýdaki þekilde öðrenci bilgilerini yazar
	/*
	Ogrenci Adi: Zeynep Kodyazar
	Ogrenci No: 12345678
	Notlari: 80 90
	Ortalama: 85.00

	Ogrenci Adi: Ahmet Kalitimalir
	Ogrenci No: 12345673
	Notlari: 100 70 90
	Ortalama: 86.66
	*/
	int writeGradesToAFile(const string & classGradesFilePath);
	
private:
	vector< Student > students;
};
