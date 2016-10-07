/*
	Main Body of Text Editor
	Authored by Group 3
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

//team globals
vector<string> harambe; //text body
vector<string> storedCopy;
bool fileEdited; //true if file has been edited since load or last save; false otherwise
int currentLine;

//getters/setters
bool getFileEdited(); //get value of fileEdited
void setFileEdited(bool value); //set value of fileEdited
void init(); //initialize globals
int getCurrentLine(); //get current line
void setCurrentLine(int value); //set the value of currentLine

int main() //use this to test your functions
{
}

void replace(int linesToReplace)
{
	if (linesToReplace < 0)
		return;
	int currLine = getCurrentLine();
	for (int x = currLine; x < currLine + linesToReplace; x++)
	{
		try
		{
			harambe.assign(x, "");
		}
		catch (out_of_range ofr)
		{
			break; //break out of for loop--elements have been replaced.
		}
	}

}

void locateString(string stringToFind)
{
	if (stringToFind.compare(""))
		return;

	string testString;
	for (unsigned int x = getCurrentLine(); x < harambe.size(); x++)
	{
		testString = harambe.at(x);
		if (testString.find(stringToFind) != string::npos)
		{
			break;
		}
	}
}

void paste()
{
	vector<string>::iterator it = harambe.begin();
	for(unsigned int x = 0; x < storedCopy.size(); x++)
		harambe.insert(it+getCurrentLine()+x, storedCopy.at(x));
}

void init()
{
	harambe = vector<string>();
	storedCopy = vector<string>();
	setFileEdited(false);
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