#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TextManager.h"


TextManager::TextManager(void)
{
	harambe = vector<string>();
	copyStorage = vector<string>();
	fileEdited = false;
	currentLine = 0;
}
TextManager::~TextManager(void)
{
}
bool TextManager::getFileEdited()
{
	return fileEdited;
}
void TextManager::setFileEdited(bool value)
{
	fileEdited = value;
}
int TextManager::getCurrentLine()
{
	return currentLine;
}
void TextManager::setCurrentLine(int value)
{
	currentLine = value;
}

//CHRIS
void TextManager::replace(int numLinesToReplace)
{
	if (numLinesToReplace < 0) //make sure user input is not negative number
		return;

	int currLine = getCurrentLine();

	if (unsigned int(numLinesToReplace + currLine) > harambe.size()) //if number of lines to replace exceeds the size of the text body
		numLinesToReplace = harambe.size() - currLine;//then we set the number to how many are left

	for (int x = currLine; x < currLine + numLinesToReplace; x++)//for the lines specified
	{
		harambe.assign(x, ""); //set the line to blank
	}
}

void TextManager::locateString(string stringToFind)
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

void TextManager::paste()
{
	vector<string>::iterator it = harambe.begin(); //create fancy "Start Here" sign
	for(unsigned int x = 0; x < copyStorage.size(); x++) //for each line of copied text, paste after current line
		harambe.insert(it+getCurrentLine()+x, copyStorage.at(x));
	//TO-DO method to set line to last pasted line
}


//KEVIN
void TextManager::insertLines(int linesToinsert) //should be OK
{
	if(linesToinsert <= 0)
		cout << "You must input a number above 0" << endl;
		return;
	
		if(getCurrentLine() == harambe.size)
		{
			harambe.push_back("");
			linesToinsert--;
		}

	for(int i = 1; i <= linesToinsert; i++)
	{
		harambe.insert(harambe.begin() + getCurrentLine()+1, ""); //writes the lines in the array to the text body 
		setCurrentLine(getCurrentLine()+1);
	}


}

void TextManager::moveToLine(int lineToMove)
{
	int lineNum;
	
	cout << "Which line do you want to move?" << endl;
	cin >> lineNum;

	
	harambe.push_back(harambe[lineNum + 1]);
	harambe.erase(harambe.begin() + (lineNum + 1)); 
}

void TextManager::deleteLines(int linesToDelete)
{
	int lineNum;

	cout << "Starting from which line do you want to delete from?" << endl;
	cin >> lineNum;

	harambe.erase(harambe.begin() + lineNum, harambe.begin() + lineNum + linesToDelete);
}
