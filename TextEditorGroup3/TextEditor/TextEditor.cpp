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
#include "NewCOUT.h"
using namespace std;

void cls();
void filePrompt(TextManager*);
bool isValidFilename(string);
char getInput();
int getIntInput();
NewCOUT magiccout;

int main() //use this to test your functions
{
	cls();
	TextManager harambeLivesOn;
	filePrompt(&harambeLivesOn);
	char userInput;
	while(true)
	{
		magiccout << menuPrompt << selectionMarker;
		userInput = getInput();

		switch(userInput)
		{
			case 'b' : { //substitute
							cls();
							cin.ignore();
							magiccout << "Look for: ";
							string testfor;
							getline(cin, testfor);
							if(testfor.empty())
							{
								magiccout <<  '\n' << "Can't look for blanks!" << '\n';
								break;
							}
							magiccout <<  "Replace with: ";
							string rep;
							getline(cin, rep);
							harambeLivesOn.substitueStrings(testfor, rep);
					   }
				break;
			case 't' : { //type
							cls();
							magiccout <<  "How many lines to type?: ";
							int ltp = getIntInput();
							if(!(ltp > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.type(ltp);
					   }
				break;
			case 'r' : { //replace
							cls();
							magiccout <<  "How many lines to replace?: ";
							int ltr = getIntInput();
							if(!(ltr > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.replace(ltr);
					   }
				break;
			case 'm' : { //move
							cls();
							magiccout <<  "Move current line to line: ";
							int ltm = getIntInput();
							ltm--;
							if(!(ltm >= 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.moveLine(ltm);
					   }
				break;
			case 'g' : { //goto
							cls();
							magiccout << "Go to Line: ";
							int ltgt = getIntInput();
							ltgt--;
							if(!(ltgt >= 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.moveToLine(ltgt);
					   }
				break;
			case 'q' : { //quit
							if(harambeLivesOn.getFileEdited())
								{
									cls();
									magiccout << "Save unsaved edits? (y/n): ";
									char ans = getInput();
									while(!(ans == 'y' || ans == 'n'))
									{
										magiccout <<  invalidChoiceError << '\n';
										magiccout <<  "Save unsaved edits? (y/n): ";
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
							magiccout <<  "How many lines to copy?: ";
							int ltc = getIntInput();
							if(!(ltc > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
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
							magiccout <<  "How many lines to insert?: ";
							int lts = getIntInput();
							if(!(lts > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.insertLines(lts);
					   }
				break;
			case 'd' : { //delete
							cls();
							magiccout <<  "How many lines to delete?: ";
							int ltd = getIntInput();
							if(!(ltd > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.deleteLines(ltd);
					   }
				break;
			case 'f' : { //find
							cls();
							cin.ignore();
							magiccout <<  "Look for: ";
							string testfor;
							getline(cin, testfor);
							if(testfor.empty())
							{
								magiccout << '\n' << "Can't look for blanks!" << '\n';
								break;
							}
							char ans;
							if (!harambeLivesOn.locateString(testfor))
							{
								magiccout <<  "Not found. Check entire document? (y/n): ";
								ans = getInput();
								while(!(ans == 'y' || ans == 'n'))
								{
									magiccout << invalidChoiceError << '\n';
									magiccout << "Not found. Check entire document? (y/n): ";
									ans = getInput();
								}
								if(ans == 'y')
								{
									harambeLivesOn.setCurrentLine(0);
									if(!harambeLivesOn.locateString(testfor))
										magiccout <<  "Not found." << '\n';
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
							magiccout <<  enterFilename;
							string fileName;
							cin.ignore();
							getline(cin, fileName);
							while (!isValidFilename(fileName))
							{
								cls();
								magiccout <<  filenameError;
								cin >> fileName;
								if (fileName.compare("quit"))
									break;
							}
							harambeLivesOn.save(fileName);
							magiccout <<  "Saved as: " << fileName << '\n';
					   }
				break;
			case 'u' : {
							harambeLivesOn.undo();
					   }
				break;
			case 'x' : {
							cls();
							magiccout << "How many lines to cut?: ";
							int ltx = getIntInput();
							if(!(ltx > 0))
							{
								magiccout << '\n' << negandzeroerror << '\n';
								break;
							}
							harambeLivesOn.cutLines(ltx);
					   }
				break;
			case 'h' : {
							cls();
							magiccout << helpText;
					   }
			default :  {
							magiccout << '\n';
							cin.ignore();
					   }
		}
		magiccout << "###" << '\n';
	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void filePrompt(TextManager* tm)
{
	magiccout << fileMenuPromt << selectionMarker;
	int choice = getIntInput();
	while (choice < 1 || choice > 3)
	{
		magiccout << invalidChoiceError << selectionMarker;
		choice = getIntInput();
	}

	if (choice == 3)
	{
		magiccout << quitMessage;
		cin.ignore();
		string dummy;
		getline(cin, dummy);
		exit(0);
	}

	magiccout << enterFilename;
	string fileName;
	cin.ignore();
	getline(cin, fileName);
	while (!isValidFilename(fileName))
	{
		cls();
		magiccout << filenameError;
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
			magiccout << "That file does not exist. Would you like to create it? (Y/N) : " ;
			choice = getInput();
			while(choice != 'y' && choice != 'n')
			{
				magiccout << invalidChoiceError << selectionMarker;
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
	magiccout << gagCopyright;
}


char getInput()
{

	string input;
	cin >> input;
	char ret;

	if(!input.empty())
	{
		if(!input.compare("MCSIZEITPLEASE"))
		{
			magiccout.doUpper();
			magiccout << "SURE THING!" << '\n';
			return 'z';
		}
		else if(!input.compare("Lays."))
		{
			magiccout.doAir();
			magiccout << "INCOMING AIR JOKES" << '\n';
			return 'z';
		}
		else if(!input.compare("cha-cha-slide"))
		{
			magiccout.reverse();
			magiccout << "Cha Cha Real Smooth!" << '\n';
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