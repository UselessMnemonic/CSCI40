#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "TextManager.h"
#include "UsefulMethods.h"


TextManager::TextManager(void)
{
	harambe = vector<string>();
	copyStorage = vector<string>();
	fileEdited = false;
	currentLine = 0;
	currentFileName =  "";
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
string TextManager::getCurrentFilename()
{
	return currentFileName;
}
void TextManager::createFile(string fileName)
{
	currentFileName = fileName;
}

//REYES
void TextManager::type(int numLinesToType)
{
	int res = harambe.size() - getCurrentLine();
	if (numLinesToType > res)
		numLinesToType = res;
	for (int x = 0; x < numLinesToType; x++)
	{
		cout << "L " << setw(3) << getCurrentLine()+x;
		cout << " : " << harambe.at(getCurrentLine() + x) << endl;
	}
}

void TextManager::copyLines(int numLinesToCopy)
{
	if (harambe.size() == 0)
		return;
	if(harambe.size() - getCurrentLine() < numLinesToCopy)
		numLinesToCopy = harambe.size() - getCurrentLine();
	copyStorage.clear();
	for(int x = 0; x < numLinesToCopy; x++)
	{
		copyStorage.push_back(harambe.at(getCurrentLine()+x));
	}
}

//CHRIS
void TextManager::replace(int numLinesToReplace)
{
	if(harambe.size() == 0)
		return;
	if (numLinesToReplace + getCurrentLine() > harambe.size()) //if number of lines to replace exceeds the size of the text body
		numLinesToReplace = harambe.size() - getCurrentLine();//then we set the number to how many are left
	string input;
	cout << endl;
	cin.ignore();
	for (int x = 0; x < numLinesToReplace; x++)//for the lines specified
	{
		cout << "L " << setw(3) << getCurrentLine()+x;
		cout << " : ";
		getline(cin, input);
		harambe[getCurrentLine()+x] = input;
	}
	setCurrentLine(numLinesToReplace + getCurrentLine() - 1);
}

bool TextManager::locateString(string stringToFind)
{
	if(harambe.size() == 0)
		return true;

	string testString;
	for (unsigned int x = getCurrentLine(); x < harambe.size(); x++) //for each line in the document, starting at current line
	{
		testString = harambe.at(x);
		int pos = testString.find(stringToFind);
		if (pos != string::npos) //if the line contains the token, set the current line there
		{
			cout << "L " << setw(3) << x;
			cout << " : " << testString << endl;
			for(int x = 0; x < pos+8; x++)
				cout << ' ';
			cout << '^' << endl;
			return true;
		}
	}

	return false;
}

void TextManager::paste()
{
	if (getCurrentLine() == (harambe.size() - 1))
	{
		for (unsigned int x = 0; x < copyStorage.size(); x++)
			harambe.push_back(copyStorage.at(x));
	}
	else
	{
		for (unsigned int x = 0; x < copyStorage.size(); x++) //for each line of copied text, paste before current line
			harambe.insert(harambe.begin() + getCurrentLine() + x, copyStorage.at(x));
	}

	setCurrentLine(getCurrentLine()+copyStorage.size()-1);
}


//KEVIN
void TextManager::insertLines(int linesToinsert) //should be OK
{
	string input;
	cin.ignore();
	if(harambe.size() == 0 || getCurrentLine() == (harambe.size()-1))
	{
		int adjust = 1;

		if (harambe.size() == 0)
			adjust = -1;

		for (int i = 0; i < linesToinsert; i++)
		{
			cout << "L " << setw(3) << getCurrentLine()+adjust;
			cout << " : ";
			getline(cin, input);
			harambe.push_back(input);
			setCurrentLine(getCurrentLine() + 1);
		}
	}
	else
	{
		for (int i = 0; i < linesToinsert; i++)
		{
			cout << "L " << setw(3) << getCurrentLine();
			cout << " : ";
			getline(cin, input);
			harambe.insert(harambe.begin() + getCurrentLine(), input); //writes the lines in the array to the text body 
			setCurrentLine(getCurrentLine() + 1);
		}
		setCurrentLine(getCurrentLine() - 1);
	}

}

bool TextManager::moveToLine(int lineToMove)
{
	if((lineToMove > -1) && (lineToMove < harambe.size()))
	{
		setCurrentLine(lineToMove);
		return true;
	}
	else
		return false;
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
	if(harambe.size() - getCurrentLine() < linesToDelete)
		linesToDelete = harambe.size() - getCurrentLine();
	harambe.erase(harambe.begin() + getCurrentLine(), harambe.begin() + getCurrentLine() + linesToDelete);
	if (getCurrentLine() >= harambe.size())
		setCurrentLine(harambe.size() - 1);
}
//BRAE

int TextManager::load(string fileName)
{
	string line;
	ifstream ifile(fileName);
	currentFileName = fileName;
	setCurrentLine(0);
	if (!ifile.is_open())
	{
		ifile.close();
		fileName.append(".txt");
		ifile.open(fileName);
		if (!ifile.is_open())
		{
			currentFileName = fileName;
			return 0;
		}
	}

	while (getline(ifile, line))
	{
		harambe.push_back(line);
	}

	ifile.close();
	return 1;
}

void TextManager::save(string filename)
{
	string line;
	ofstream ofile(filename);
	int x = harambe.size()-1;

	while(isAllWhitespace(harambe.at(x)))
	{
		x--;
	}

	for(int y = 0; y <= x; y++)
	{
		ofile << harambe.at(y) << endl;
	}

	ofile.close();
}

int TextManager::getNumberLines()
{
	return harambe.size();
}

void TextManager::displayCopyStorage()
{
	cout << "CLIPBOARD BEGIN" << endl;
	for(int x = 0; x < copyStorage.size(); x++)
	{
		cout << copyStorage.at(x) << endl;
	}
	cout << "CLIPBOARD END" << endl;
}