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
#include "strings.h"
using namespace std;

/*
	Command Structure
	[command] [arg 1] [arg 2] ... [arg n]
*/

void filePrompt(TextManager* tm);

int main() //use this to test your functions
{
	cout << "Copyright Team 3 - 2016" << endl << endl;
	
	TextManager harambeLivesOn;
	filePrompt(&harambeLivesOn);
	string userInput;

	while(true)
	{
		cout << menuPrompt;
		cin.ignore();
		cin >> userInput;
		exit(0);
	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void filePrompt(TextManager* tm)
{
	cout << fileMenuPromt;
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << invalidChoiceError;
		cin >> choice;
	}

	if (choice == 1)
	{
		cout << "Enter an alphanumeric file name: ";
		string fileName;
		cin.ignore();
		getline(cin, fileName);
		while (!isValidFilename(fileName))
		{
			cout << filenameError;
			cin >> fileName;
			if (fileName.compare("quit"))
				filePrompt(tm);
		}
		(*tm).load(fileName);
	}
	else if (choice == 2)
	{
		cout << "Enter an alphanumeric file name: ";
		string fileName;
		while (!isValidFilename(fileName))
		{
			cout << filenameError;
			cin >> fileName;
			if (fileName.compare("quit"))
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
}