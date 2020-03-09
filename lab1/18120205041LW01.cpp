/*  Fatih Dursun Üzer 13 Þubat 2019
	18120205041
	Bu program üç argüman alýp bu argümanlarý alfabetik sýralamaya sokmaktadýr.
 */
#include <iostream>
#include <string>
using namespace std;
const int ARGSAY = 4;
const int i = 1;

int main(int argc, char *argv[])
{
	if (argc == ARGSAY)
	{
		string s(argv[i]);
		string s2(argv[i + 1]);
		string s3(argv[i + 2]);

		if ((s.compare(s2) > 0) && (s.compare(s3) > 0))
		{
			if ((s2.compare(s3) > 0))
				cout << s3 << endl << s2 << endl << s << endl;
			else
				cout << s2 << endl << s3 << endl << s2 << endl;
		}

		else if ((s2.compare(s) > 0) && (s2.compare(s3) > 0))
		{
			if ((s.compare(s3) > 0))
				cout << s3 << endl << s << endl << s2 << endl;
			else
				cout << s << endl << s3 << endl << s2 << endl;
		}

		else if ((s3.compare(s) > 0) && (s3.compare(s2)) > 0)
		{
			if (s.compare(s2) > 0)
				cout << s2 << endl << s << endl << s3 << endl;
			else
				cout << s << endl << s2 << endl << s3 << endl;
		}
	}
	else
		cout << "Bu program uc kelimeyi karsilastirip siralamak icin olusturulmustur." << endl
		<< "Ornegin; armut,elma,elmas" << endl;

	return 0;
}