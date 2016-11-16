/*
	Main Body of Text Editor
	Authored by Group 3
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TextManager.h"
#include "res.h"
using namespace std;

/*
	Command Structure
	[command] [arg 1] [arg 2] ... [arg n]
*/
void cls();
void filePrompt(TextManager*);
bool isValidFilename(string);

int main() //use this to test your functions
{
	cls();
	
	TextManager harambeLivesOn;
	filePrompt(&harambeLivesOn);
	char userInput;

	while(true)
	{
		cout << menuPrompt << selectionMarker;
		cin >> userInput;
		userInput = tolower(userInput);

		switch(userInput)
		{
			case 'u' : { //substitute
							
					   }
				break;
			case 't' : { //type
							cls();
							cout << "How many lines to type?: ";
							int ltp;
							cin >> ltp;
							if(!(ltp > 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.type(ltp);
					   }
				break;
			case 'r' : { //replace
							cls();
							cout << "How many lines to replace?: ";
							int ltr;
							cin >> ltr;
							if(!(ltr > 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.replace(ltr);
					   }
				break;
			case 'm' : { //move
					   }
				break;
			case 'a' : { //adjust
					   }
				break;
			case 'g' : { //goto
							cls();
							cout << "Go to Line: ";
							int ltgt;
							cin >> ltgt;
							if(!(ltgt >= 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.moveToLine(ltgt);
					   }
				break;
			case 'q' : { //quit
							exit(0);
					   }
				break;
			case 'c' : { //copy
							cls();
							cout << "How many lines to copy?: ";
							int ltc;
							cin >> ltc;
							if(!(ltc > 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.copyLines(ltc);
					   }
				break;
			case 'p' : { //pase
							harambeLivesOn.paste();
					   }
				break;
			case 'i' : { //insert
							cls();
							cout << "How many lines to insert?: ";
							int lts;
							cin >> lts;
							if(!(lts > 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.insertLines(lts);
					   }
				break;
			case 'd' : { //delete
							cls();
							cout << "How many lines to delete?: ";
							int ltd;
							cin >> ltd;
							if(!(ltd > 0))
							{
								cout << endl << "Negative numbers not allowed here." << endl;
								break;
							}
							harambeLivesOn.deleteLines(ltd);
					   }
				break;
			case 'f' : { //find
							cls();
							cin.ignore();
							cout << "Look for: ";
							string testfor;
							getline(cin, testfor);
							if(testfor.empty())
							{
								cout << endl << "Can't look for blanks!" << endl;
								break;
							}
							if (!harambeLivesOn.locateString(testfor))
							{
								cout << "Not found. Check entire document? (y/n) ";

							}
					   }
				break;
			case 's' : { //save
							harambeLivesOn.save(harambeLivesOn.getCurrentFilename());
					   }
				break;
			case 'y' : {
							harambeLivesOn.displayCopyStorage();
					   }
			    break;
			default :  {
							cout << endl;
							cin.ignore();
					   }
		}
		cout << '#' << endl;
	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void filePrompt(TextManager* tm)
{
	cout << fileMenuPromt << selectionMarker;
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		cout << invalidChoiceError;
		cin.ignore();
		cin >> choice;
	}

	if (choice == 3)
	{
		cout << quitMessage;
		cin.ignore();
		string dummy;
		getline(cin, dummy);
		exit(0);
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
	else
		(*tm).createFile(fileName);
}

void cls()
{
	system("cls");
	cout << gagCopyright;;
}

/*bool isValidFilename(string fileName)
{
	for(unsigned int x = 0; x < fileName.length(); x++)
	{
		if(fileName[x] != '.')
			if(!isalnum(fileName[x]))
				return false;
	}
	return true;

}*/