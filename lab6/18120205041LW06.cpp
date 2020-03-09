/* FATÝH DURSUN ÜZER
18120205041
6.LAB ÇALIÞMASI*/

#include "student.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <sstream>

using namespace std;

Classroom::Classroom(const string & classFilePath)  /* Student vektörü oluþturur. Student dosyasýndan veri alýr.*/
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
int Classroom::readGradesFromAFile(const string & classFilePath)  /* Notlarý dosyadan okur*/
{
	ifstream inPut(classFilePath);
	for (unsigned int i =0; i<students.size();i++)
	{
		inPut >> students[i];
	}
	return 0;

	inPut.close();

}

int Classroom::writeGradesToAFile(const string & classGradesFilePath)  /* Ýsimlerle beraber notlarý da yeni bir dosyaya aktarýr*/
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

ofstream & operator<<(ofstream & outFile, const Student & s) /* Dosyaya yazarken nasýl bir formatta yazýlacaðýný belirten overloading*/
{
	if (!outFile.fail())
	{
		outFile << "Ogrenci adý : " << s.name << endl << "Ogrenci No: " << s.studentNumber << endl << " Notlari: ";
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
	int sayý;

	ss >> numara >> sayý;
	if (numara == s.studentNumber)
	{
		
		s.grades.push_back(sayý);
	}
	ss.clear();

	while (!inFile.eof())
	{
		getline(inFile, a);
		stringstream ss;
		ss << a;

		ss >> numara >> sayý;
		if (numara == s.studentNumber)
		{

			s.grades.push_back(sayý);
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

int Student::getNumberOfGrades() const /* grade sayýsýný dönderir(kiþi baþý)*/
{
	return this->grades.size();
}

double Student::getAverage() const /* Kiþinin notlarýnýn ortalamasýný dönderir*/
{
	int bos = 0;
	if (getNumberOfGrades() == bos)
		return 0;
	int bölünen;
	double toplam = 0;
	for (bölünen = 0; bölünen < this->getNumberOfGrades(); ++bölünen)
	{
		toplam += this->grades[bölünen];
	}

	return toplam / bölünen;
}

string Student::getStudentNumber() /* Kiþinin okul numarasýný dönderir*/
{
	return studentNumber;
}

string Student::getName() /* Kiþinin ismini dönderir*/
{
	return name;
}

vector<double> Student::getGrades() /* Notlar vektörünü dönderir*/
{
	return grades;
}



