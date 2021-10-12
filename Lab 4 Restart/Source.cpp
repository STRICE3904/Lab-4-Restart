/*Samuel Trice
* Lab 4. Ussing a file to make a chart of tempurature
* Due:
*/


#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cctype>


using namespace std;
void tempread(ifstream& inFile, string inputFileName);


 char temp;

ifstream inFile;
string inputFileName;

int main()
{

	do
	{
		cout << "Type the name of the file to be inputed: ";
		cin >> inputFileName;
		inFile.open(inputFileName.c_str());

		if (!inFile)
		{
			cout << "Input file failed to open. Make sure you typed its name correctly and that the input file exists.\n";
			cout << "Try again or press 't' to make a new file with a selected name: ";
			cin >> inputFileName;
			cout << "\n\n\n";

			if (inputFileName == "T" || inputFileName == "t") //User terminates program. 
			{
				string filename = "inTempurature.dat";
				ofstream outfile;
				outfile.open("inTempurature.dat");
				cout << "File named inTempurature.dat has been opened, Restart the program to accsess";
				return 1;
			}
			inFile.open(inputFileName.c_str());
		}
	} while (!inFile);
	tempread(inFile, inputFileName);//Function call
	inFile.close();

	return 0;
}


void tempread(ifstream& inFile, string fileName)
{
	

	cout << "\nOpening file...";
	inFile.get(temp);

	//Heading for graph.
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;


	do
	{
		temp = ceil(temp); //ceil is suposed to round to whole number

		string starOutput; //Stores stars
		starOutput = ""; //Should reset the stars for each time

		if (temp < -35 || temp > 120) { //if value is too much the loop skips. Preventing Infinite loops
			inFile >> temp;
			continue; //Tells compiler to skip body of loop and return to loop condition of first for loop.

		}
		else { //temp in range
			cout << temp << ":";
		}

		//This for loop is used to get the correct amount of stars per degree.
		for (int i = 1; i <= (abs(temp) / 3.0); ++i) //abs() is ussed so the star count stays possitive.
		{
			starOutput.append("*"); //Append for the star. Supposed to help the star loop reset the string.
		}

		//Nested If-Else for star output
		if (temp == -30) {
			cout << setw(12) << starOutput + "|";
		}
		else if (temp > -30 && temp <= -10) {
			cout << setw(12) << starOutput + "|";
		}
		else if (temp > -10 && temp < 0) {
			cout << setw(13) << starOutput + "|";
		}
		else if (temp >= 0 && temp < 10) {
			cout << setw(14) << "|" << starOutput;
		}
		else if (temp >= 10 && temp < 100) {
			cout << setw(13) << "|" << starOutput;
		}
		else if (temp >= 100 && temp <= 120) {
			cout << setw(12) << "|" << starOutput;
		}

		cout << endl;
		inFile.get(temp);
	} while (inFile);
	//output to show ussers how the stars work.
	cout << "###############\n";
	cout << "* = 3 degrees";
	cout << "\n###############";
	inFile.close();
}
