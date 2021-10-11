#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cctype>


using namespace std;
int tempread();


char intemp;
string inputFileName;
ifstream infile;


int main()
{

	infile.open("inTempurature.dat");
	if (!infile)
	{
		char yesno;
		cout << "File not found would you like to make one Y or N; ";
		cin >> yesno;
		if (yesno == 'N' || yesno == 'n')
		{
			cerr << "failed to open " << '\n';
		}
		else if (yesno == 'Y' || yesno == 'y')
		{
			string filename = "inTempurature.dat";
			ofstream outfile;
			outfile.open("inTempurature.dat");
			cout << "File has been opened, Restart the program to accsess";
		}
		return 1;
	}
	tempread();
	infile.close();

	return 0;
}

int tempread()
{
	infile >> intemp;
	int mintemp = '-35';
	int maxtemp = '120';
	cout << "Tempurature for 24 hours:\n";
	cout << "   -30        0        30        60        90       120" << endl;
	string star;
	star = " * ";
	string space;
	space = " ";
	int i;

	while (intemp)
	{
		if (intemp == -35 && intemp <= -30)
		{
			cout << intemp;
			for (i = -35; i == -30; i + 1)
			{
				if (i < intemp)
				{
					cout << " ";
				}
				else if (i >= intemp)
				{
					cout << star;
				}
			}
		}
		else if (intemp > -30 && intemp <= -1)
		{
			cout << intemp;
			for (i = -30; i == -1; i + 1)
			{
				if (i < intemp)
				{
					cout << " ";
				}
				else if (i >= intemp)
				{
					cout << star;
				}
				cout << endl;
			}
		}
		else if (intemp == 0)
		{
			cout << 0 << setw(12) << "|";
		}
		else if (intemp > 0 && intemp <= 120)
		{
			for (i = 1; i == 120; i + 1)
			{
				if (i < intemp)
				{
					cout << " ";
				}
				else if (i >= intemp)
				{
					cout << star;
				}
				cout << endl;
			}
		}
		else if (intemp > 120)
		{
			cout << intemp << setw(12) << "|" << setw(12) << star << endl;
		}
		cout << endl;
		infile >> intemp;
	}
	return EXIT_SUCCESS;
}
