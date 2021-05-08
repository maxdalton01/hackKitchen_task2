// include statements
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

string getFileContents(ifstream& file)
{
    string lines = ""; // all lines
    if (file)          // check if everything is good
    {
	    while (file.good())
	    {
	        string templine;                  //Temp line
	        getline (file , templine);        //Get temp line
	        templine += "\n";                      //Add newline character
	        lines += templine;                     //Add newline
	    }
	    return lines;
    }
    else //Return error
    {
	    return "ERROR File does not exist.";
    }
}

void printArt(const string& file)
{
    string art;
    ifstream myfile;
    myfile.open(file.c_str()); //Open file
    art = getFileContents(myfile); //Get file
    cout << art << endl;             //Print it to the screen
    myfile.close();                           //Close file
}

int main()
{
    system ("CLS"); // clear the screen
    Sleep(1000); // in milliseconds
    cout << "Hello! Welcome to the Beaver Restaurant!\n" << endl;
    printArt("restaurant.txt");
    Sleep(3000);
    system("CLS");
    cout << "Master Ramsey will take you to your table.\n" << endl;
    printArt("waiter.txt");
}