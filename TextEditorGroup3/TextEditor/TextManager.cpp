#include "stdafx.h"
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