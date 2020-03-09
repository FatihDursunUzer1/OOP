#include <iostream>
#include <fstream>
#include "student.h"
#include <vector>
#include <iostream>


using namespace std;

int main()
{
	Classroom a("students.txt");
	a.readGradesFromAFile("grades.txt");
    a.writeGradesToAFile("outFile.txt");
}