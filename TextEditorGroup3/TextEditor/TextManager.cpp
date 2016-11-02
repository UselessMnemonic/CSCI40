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

//REYES
void TextManager::type(int numLinesToType)
{
	int res = (harambe.size() - getCurrentLine());
	if (numLinesToType > res)
		numLinesToType = res;
	for (int x = 0; x < numLinesToType; x++)
	{
		cout << harambe.at(getCurrentLine() + x) << endl;
	}
}

//CHRIS
void TextManager::replace(int numLinesToReplace)
{
	if (numLinesToReplace < 0) //make sure user input is not negative number
		return;

	if (unsigned int(numLinesToReplace + getCurrentLine()) > harambe.size()) //if number of lines to replace exceeds the size of the text body
		numLinesToReplace = harambe.size() - getCurrentLine();//then we set the number to how many are left
	string input;
	for (int x = 0; x < numLinesToReplace; x++)//for the lines specified
	{
		getline(cin, input);
		harambe.assign(getCurrentLine()+x, input); //set the line to blank
	}
	setCurrentLine(numLinesToReplace + getCurrentLine() - 1);
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

		string input;
	if(getCurrentLine() == harambe.size()-1)
	{
		for (int i = 1; i <= linesToinsert; i++)
		{
			getline(cin, input);
			harambe.push_back(input);
			setCurrentLine(getCurrentLine() + 1);
		}
	}
	else
	{
		for (int i = 1; i <= linesToinsert; i++)
		{
			getline(cin, input);
			harambe.insert(harambe.begin() + getCurrentLine() + 1, input); //writes the lines in the array to the text body 
			setCurrentLine(getCurrentLine() + 1);
		}
	}

}

void TextManager::moveToLine(int lineToMove)
{
	if(lineToMove > -1 && lineToMove < harambe.size())
	setCurrentLine(lineToMove);
}

/*void TextManager::moveToLine(int lineToMove)
{
	int lineNum;
	
	cout << "Which line do you want to move?" << endl;
	cin >> lineNum;

	
	harambe.push_back(harambe[lineNum + 1]);
	harambe.erase(harambe.begin() + (lineNum + 1)); 
}*/

void TextManager::deleteLines(int linesToDelete)
{

	harambe.erase(harambe.begin() + getCurrentLine(), harambe.begin() + getCurrentLine() + linesToDelete-1);
}
