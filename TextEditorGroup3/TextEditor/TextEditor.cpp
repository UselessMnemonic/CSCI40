/*
	Main Body of Text Editor
	Authored by Group 3
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
	Command Structure
	[command] [arg 1] [arg 2] ... [arg n]
*/

//necessary functions
void substitueStrings(string oldString, string newString);//reyes
void copyLines(int numberOfLines);//reyes
void type(int linesToPrint);//reyes

void deleteLines(int numberOfLines);//kevin
void moveToLine(int lineToMoveTo);//kevin
void insertLines(int linesToInsert);//kevin

void replace(int linesToReplace);//chris
void locateString(string stringToFind);//chris
void paste();//chris

//additional
void save(string fileName); //Brae
void load(string fileName); //Brae
void quit(); //Brae

void moveUp(); //etc.
void moveDown(); //etc.
bool isValidFilename(string fileName); //etc.

//team globals
vector<string> harambe; //text body
vector<string> storedCopy;
bool fileEdited; //true if file has been edited since load or last save; false otherwise
int currentLine;
string currentFileName;

//getters/setters
bool getFileEdited(); //get value of fileEdited
void setFileEdited(bool value); //set value of fileEdited
void init(); //initialize globals
int getCurrentLine(); //get current line
void setCurrentLine(int value); //set the value of currentLine
void filePrompt();

int main() //use this to test your functions
{
	cout << "Copyright Team 3 - 2016" << endl << endl;
	init();
	filePrompt();
	string userInput;
	while(true)
	{

	}

	return 1; //SHOULD NEVER, EVER, EVER HAPPEN
}

void replace(int linesToReplace)
{
	if (linesToReplace < 0) //make sure user input is not negative number
		return;

	int currLine = getCurrentLine();

	if (unsigned int(linesToReplace + currLine) > harambe.size()) //if number of lines to replace exceeds the size of the text body
		linesToReplace = harambe.size() - currLine;//then we set the number to how many are left

	for (int x = currLine; x < currLine + linesToReplace; x++)//for the lines specified
	{
		harambe.assign(x, ""); //set the line to blank
	}
}

void locateString(string stringToFind)
{
	if (stringToFind.compare("")) //make sure the token is not empty
		return;

	string testString;
	for (unsigned int x = getCurrentLine(); x < harambe.size(); x++) //for each line in the document, starting at current line
	{
		testString = harambe.at(x);
		if (testString.find(stringToFind) != string::npos) //if the line contains the token, set the current line there
		{
			//TO-DO method to set line, prompt to check from begining of document
			break;
		}
	}
}

void paste()
{
	vector<string>::iterator it = harambe.begin(); //create fancy "Start Here" sign
	for(unsigned int x = 0; x < storedCopy.size(); x++) //for each line of copied text, paste after current line
		harambe.insert(it+getCurrentLine()+x, storedCopy.at(x));
	//TO-DO method to set line to last pasted line
}

void init() //instantiates the globals
{
	harambe = vector<string>();
	storedCopy = vector<string>();
	setFileEdited(false);
	currentLine = 0;
}

bool getFileEdited()
{
	return fileEdited;
}

void setFileEdited(bool value)
{
	fileEdited = value;
}

int getCurrentLine()
{
	return currentLine;
}

void setCurrentLine(int value)
{
	currentLine = value;
}

void filePrompt()
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
				filePrompt();
		}
		load(fileName);
		currentFileName = fileName;
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
				filePrompt();
		}
		currentFileName = fileName;
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

bool isValidFilename(string fileName)
{
	for(unsigned int x = 0; x < fileName.length(); x++)
	{
		if(!isalnum(fileName[x]))
			return false;
	}
	return true;

}
