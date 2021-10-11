#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cctype>


using namespace std;
void tempread();


char intemp;
string inputFileName = "C:/Users/quinn/source/repos/Lab 4 Restart/Lab 4 Restart";
ifstream inFile;


int main()
{

	inFile.open("inTempurature.dat");
	if (!inFile)
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
	inFile.close();

	return 0;
}


void tempread()
{
	char temp;

	cout << "\nOpening file...";


	//Heading for graph.
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	inFile.open("inTempurature.dat");
	inFile.get(temp);

	if (!inFile.get(temp))
	{
		cout << "Stream Error. Clossing.\n";
		return;
	}

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
		for (int i = 1; i <= (abs(temp) / 3.0); ++i) //abs() is used to calculate values for negative inputs.
		{
			starOutput.append("*"); //Appends a star to a string called starOutput every time the loop iterates.
		}

		//Following if else ladder prints the corressponding temperature and number of stars associated with that value
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
	cout << "###############\n";
	cout << "* = 3 degrees";
	cout << "\n###############";
	inFile.close();
}
