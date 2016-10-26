/*
	Main Body of Text Editor
	Authored by Group 3
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "UsefulMethods.h"
#include "TextManager.h"
using namespace std;

/*
	Command Structure
	[command] [arg 1] [arg 2] ... [arg n]
*/


int main() //use this to test your functions
{
	cout << "Copyright Team 3 - 2016" << endl << endl;
	
	TextManager harambeLivesOn();

	string userInput;
	while(true)
	{

	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void filePrompt(TextManager tm)
{
	cout << "Would you like to load or create a new file?" << endl;
	cout << "1. Load File" << endl;
	cout << "2. Create File" << endl;
	cout << "3. Quit" << endl;
	int choice;
	cin >> choice;
	while(choice < 1 || choice > 3)
	{
		cout << "That is not a valid choice. Please choose from among the list." << endl;
		cin >> choice;
	}

	if(choice == 1)
	{
		cout << "Enter an alphanumeric file name: ";
		string fileName;
		while(!isValidFilename(fileName))
		{
			cout << "This is not a valid file name, please try again, or enter \"quit\" to return to menu." << endl;
			cin >> fileName;
			if(fileName.compare("quit"))
				filePrompt(tm);
		}
		tm.load(fileName);
	}
	else if(choice == 2)
	{
		cout << "Enter an alphanumeric file name: ";
		string fileName;
		while(!isValidFilename(fileName))
		{
			cout << "This is not a valid file name, please try again, or enter \"quit\" to return to menu." << endl;
			cin >> fileName;
			if(fileName.compare("quit"))
				filePrompt(tm);
		}
	}
	else
	{
		cout << "Hit Enter to close the program. . .";
		cin.ignore();
		string dummy;
		getline(cin, dummy);
		exit(0);
	}
