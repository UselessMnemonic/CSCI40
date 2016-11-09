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
#include "res.h"
using namespace std;

/*
	Command Structure
	[command] [arg 1] [arg 2] ... [arg n]
*/
void cls();
void filePrompt(TextManager* tm);

int main() //use this to test your functions
{
	cls();
	
	TextManager harambeLivesOn;
	filePrompt(&harambeLivesOn);
	char userInput;

	while(true)
	{
		cout << menuPrompt << selectionMarker;
		cin.ignore();
		cin >> userInput;



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

	cout << enterFilename;
	string fileName;
	cin.ignore();
	getline(cin, fileName);
	while (!isValidFilename(fileName))
	{
		cls();
		cout << filenameError;
		cin >> fileName;
		if (fileName.compare("quit"))
			filePrompt(tm);
	}

	if (choice == 1)
	{
		int res = (*tm).load(fileName);
		if(!res)
		{
			char choice;
			cls();
			cout << "That file does not exist. Would you like to create it? (Y/N)" << endl;
			cin.ignore();
			cin >> choice;
			choice = tolower(choice);
			while(!(choice == 'y' || choice == 'n'))
			{
				cout << invalidChoiceError;
				cin >> choice;
				choice = tolower(choice);
			}
			if(choice == 'n')
				filePrompt(tm);
		}
	}
	else if (choice == 3)
	{
		cout << quitMessage;
		cin.ignore();
		string dummy;
		getline(cin, dummy);
		exit(0);
	}
}

void cls()
{
	system("cls");
	cout << gagCopyright;;
}