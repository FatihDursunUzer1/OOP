/* FAT�H DURSUN �ZER
18120205041
6.LAB �ALI�MASI*/

#include "student.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <sstream>

using namespace std;

Classroom::Classroom(const string & classFilePath)  /* Student vekt�r� olu�turur. Student dosyas�ndan veri al�r.*/
{
	ifstream inPut(classFilePath);
	if (inPut.fail())
		exit(-1);
	string isim;
	string numara;

	inPut >> numara;
	getline(inPut, isim);
	Student a(isim, numara);
	students.push_back(a);

	while (!inPut.eof())
	{
		string numara;
		inPut >> numara;
		string isim;
		getline(inPut, isim);
		Student b(isim, numara);
		students.push_back(b);
	}

	inPut.close();

}
int Classroom::readGradesFromAFile(const string & classFilePath)  /* Notlar� dosyadan okur*/
{
	ifstream inPut(classFilePath);
	for (unsigned int i =0; i<students.size();i++)
	{
		inPut >> students[i];
	}
	return 0;

	inPut.close();

}

int Classroom::writeGradesToAFile(const string & classGradesFilePath)  /* �simlerle beraber notlar� da yeni bir dosyaya aktar�r*/
{
	ofstream outPut(classGradesFilePath);
	if (outPut.fail())
		exit(-1);

	for (unsigned int i = 0; i < students.size();++i)
	{
		outPut << students[i] << endl << endl;
	}

	outPut.close();
	return 0;
}

ofstream & operator<<(ofstream & outFile, const Student & s) /* Dosyaya yazarken nas�l bir formatta yaz�laca��n� belirten overloading*/
{
	if (!outFile.fail())
	{
		outFile << "Ogrenci ad� : " << s.name << endl << "Ogrenci No: " << s.studentNumber << endl << " Notlari: ";
		for (int i = 0; i < s.getNumberOfGrades(); ++i)
		{
			outFile << " " << s.grades[i];
		}
		outFile << endl << "Ortalama: " << s.getAverage();

	}
	return outFile;
}

ifstream & operator>>(ifstream & inFile, Student & s) /* Gradesten not alan operator overloadingi*/
{ 
	string a;
	getline(inFile, a);
	stringstream ss;
	ss << a;
	string numara;
	int say�;

	ss >> numara >> say�;
	if (numara == s.studentNumber)
	{
		
		s.grades.push_back(say�);
	}
	ss.clear();

	while (!inFile.eof())
	{
		getline(inFile, a);
		stringstream ss;
		ss << a;

		ss >> numara >> say�;
		if (numara == s.studentNumber)
		{

			s.grades.push_back(say�);
		}
	}

	ss.clear();

	return inFile;

}
Student::Student(const string & name, const string & studentNumber) /* constructor*/
{
	this->name = name;
	this->studentNumber = studentNumber;
}

int Student::getNumberOfGrades() const /* grade say�s�n� d�nderir(ki�i ba��)*/
{
	return this->grades.size();
}

double Student::getAverage() const /* Ki�inin notlar�n�n ortalamas�n� d�nderir*/
{
	int bos = 0;
	if (getNumberOfGrades() == bos)
		return 0;
	int b�l�nen;
	double toplam = 0;
	for (b�l�nen = 0; b�l�nen < this->getNumberOfGrades(); ++b�l�nen)
	{
		toplam += this->grades[b�l�nen];
	}

	return toplam / b�l�nen;
}

string Student::getStudentNumber() /* Ki�inin okul numaras�n� d�nderir*/
{
	return studentNumber;
}

string Student::getName() /* Ki�inin ismini d�nderir*/
{
	return name;
}

vector<double> Student::getGrades() /* Notlar vekt�r�n� d�nderir*/
{
	return grades;
}



