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
char getInput();
int getIntInput();
void getSettings();
void setSettings();
void doCaps();

int main() //use this to test your functions
{
	cls();
	
	TextManager harambeLivesOn;
	filePrompt(&harambeLivesOn);
	char userInput;

	while(true)
	{
		cout << menuPrompt << selectionMarker;
		userInput = getInput();

		switch(userInput)
		{
			case 'b' : { //substitute
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
							cout << "Replace with: ";
							string rep;
							getline(cin, rep);
							harambeLivesOn.substitueStrings(testfor, rep);
					   }
				break;
			case 't' : { //type
							cls();
							cout << "How many lines to type?: ";
							int ltp = getIntInput();
							if(!(ltp > 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.type(ltp);
					   }
				break;
			case 'r' : { //replace
							cls();
							cout << "How many lines to replace?: ";
							int ltr = getIntInput();
							if(!(ltr > 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.replace(ltr);
					   }
				break;
			case 'm' : { //move
							cls();
							cout << "Move current line to line: ";
							int ltm = getIntInput();
							ltm--;
							if(!(ltm >= 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.moveLine(ltm);
					   }
				break;
			case 'g' : { //goto
							cls();
							cout << "Go to Line: ";
							int ltgt = getIntInput();
							ltgt--;
							if(!(ltgt >= 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.moveToLine(ltgt);
					   }
				break;
			case 'q' : { //quit
							if(harambeLivesOn.getFileEdited())
								{
									cls();
									cout << "Save unsaved edits? (y/n): ";
									char ans = getInput();
									while(!(ans == 'y' || ans == 'n'))
									{
										cout << invalidChoiceError << endl;
										cout << "Save unsaved edits? (y/n): ";
										cin >> ans;
										ans = tolower(ans);
									}
									if(ans == 'y')
									{
										harambeLivesOn.save(harambeLivesOn.getCurrentFilename());
									}
								}
							exit(0);
					   }
				break;
			case 'c' : { //copy
							cls();
							cout << "How many lines to copy?: ";
							int ltc = getIntInput();
							if(!(ltc > 0))
							{
								cout << endl << negandzeroerror << endl;
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
							int lts = getIntInput();
							if(!(lts > 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.insertLines(lts);
					   }
				break;
			case 'd' : { //delete
							cls();
							cout << "How many lines to delete?: ";
							int ltd = getIntInput();
							if(!(ltd > 0))
							{
								cout << endl << negandzeroerror << endl;
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
							char ans;
							if (!harambeLivesOn.locateString(testfor))
							{
								cout << "Not found. Check entire document? (y/n): ";
								ans = getInput();
								while(!(ans == 'y' || ans == 'n'))
								{
									cout << invalidChoiceError << endl;
									cout << "Not found. Check entire document? (y/n): ";
									ans = getInput();
								}
								if(ans == 'y')
								{
									harambeLivesOn.setCurrentLine(0);
									if(!harambeLivesOn.locateString(testfor))
										cout << "Not found." << endl;
								}
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
			case 'a' : {
							cls();
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
									break;
							}
							harambeLivesOn.save(fileName);
							cout << "Saved as: " << fileName << endl;
					   }
				break;
			case 'u' : {
							harambeLivesOn.undo();
					   }
				break;
			case 'x' : {
							cls();
							cout << "How many lines to cut?: ";
							int ltx = getIntInput();
							if(!(ltx > 0))
							{
								cout << endl << negandzeroerror << endl;
								break;
							}
							harambeLivesOn.cutLines(ltx);
					   }
				break;
			case 'h' : {
							cls();
							cout << helpText;
					   }
			default :  {
							cout << endl;
							cin.ignore();
					   }
		}
		cout << "###" << endl;
	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void filePrompt(TextManager* tm)
{
	cout << fileMenuPromt << selectionMarker;
	int choice = getIntInput();
	while (choice < 1 || choice > 3)
	{
		cout << invalidChoiceError << selectionMarker;
		choice = getIntInput();
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
			cout << "That file does not exist. Would you like to create it? (Y/N) : " ;
			choice = getInput();
			while(!(choice == 'y' || choice == 'n'))
			{
				cout << invalidChoiceError;
				choice = getInput();
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
	cout << gagCopyright;
}


char getInput()
{
	string input;
	cin >> input;
	char ret;

	if(!input.empty())
	{
		if(input.compare("MCSIZEITPLEASE"))
		{
			doCaps();
			return 'z';
		}
		else
		{
			ret = input[0];
			ret = tolower(ret);
			return ret;
		}
	}
	else
		return 'z';
}

int getIntInput()
{
	string input;
	cin >> input;
	int ret = atoi(input.c_str());
	return ret;
}

void doCaps()
{
	cout << std::uppercase;
}