#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cctype>


using namespace std;
void tempread();


char intemp;
string inputFileName = "C:/Users/quinn/source/repos/Lab 4 Restart/Lab 4 Restart/inTempurature.dat";
ifstream inFile;


int main()
{

	inFile.open(inputFileName);//File open
	if (!inFile)//Test to check for file and if not then it makes one
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
		return 1;//Ends operation so the next time there will be a file. 
	}
	tempread();//Function call
	inFile.close();

	return 0;
}


void tempread()
{
	char temp;

	cout << "\nOpening file...";
	inFile.get(temp);

	//Heading for graph.
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	while (temp != '\0')
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
	}
	//output to show ussers how the stars work.
	cout << "###############\n";
	cout << "* = 3 degrees";
	cout << "\n###############";
	inFile.close();
}
