/*Samuel Trice
* C++ 2021
* September 29th
* Lab 4
* Outputting a chart bassed on tempurature input from a file
*/


#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cctype>


using namespace std;//Makes codding easier

//Predicting that the file will hopefully take the variables and use them 
//Output should be the finished product
void tempread(ifstream& inFile, string inputFileName);


 float temp;//Global veriable for tempurature

ifstream inFile;//Global identifier for the infile
string inputFileName; //global name for the infile

int main()
{
	//Do loop cause I like them better than while loops
	do
	{
		//Allows people to use whatever file they have saved with the code
		cout << "Type the name of the file to be inputed: ";
		cin >> inputFileName;
		inFile.open(inputFileName.c_str());
		//If the file dosn't exist it makes sure you used the right file name and if not asks if you would like to make one
		if (!inFile)
		{
			cout << "Input file failed to open. Make sure you typed its name correctly and that the input file exists.\n";
			cout << "Try again or press 't' to make a new file with a selected name: ";
			cin >> inputFileName;
			cout << "\n\n\n";

			if (inputFileName == "T" || inputFileName == "t") //Usser makes their own file 
			{
				string filename = "inTempurature.dat";
				ofstream outfile;
				outfile.open("inTempurature.dat");
				cout << "File named inTempurature.dat has been opened, Restart the program to accsess";
				return 1;
			}
			inFile.open(inputFileName.c_str());//Opens new file
		}
	} while (!inFile);
	tempread(inFile, inputFileName);//Function call
	inFile.close();

	return 0;
}


void tempread(ifstream& inFile, string fileName)
{
	

	cout << "\nOpening file...";
	inFile >> temp;

	//Heading for graph.
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	//Loop ussed to output the graph
	do
	{
		temp = round(temp); //round is suposed to round to whole number

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
		inFile >> temp;
	} while (inFile);
	//output to show ussers how the stars work.
	cout << "###############\n";
	cout << "* = 3 degrees";
	cout << "\n###############";
	inFile.close();//Closes the file
}
