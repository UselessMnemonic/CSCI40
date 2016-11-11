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
	isNewFile = false;
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
void TextManager::setIsNew(bool value)
{
	isNewFile = value;
}
bool TextManager::isNew()
{
	return isNewFile;
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
	setIsNew(true);
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

//CHRIS
void TextManager::replace(int numLinesToReplace)
{
	if (numLinesToReplace < 0) //make sure user input is not negative number
		return;
	if(harambe.size() == 0)
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
			return;
		}
	}

	cout << "Substring not found. Try from beginning of document? (Y/N): (DEPREDCATED)";
}

void TextManager::paste()
{
	vector<string>::iterator it = harambe.begin(); //create fancy "Start Here" sign
	for(unsigned int x = 0; x < copyStorage.size(); x++) //for each line of copied text, paste after current line
		harambe.insert(it+getCurrentLine()+x, copyStorage.at(x));
	setCurrentLine(getCurrentLine()+copyStorage.size());
}


//KEVIN
void TextManager::insertLines(int linesToinsert) //should be OK
{
	string input;
	if(isNew() || getCurrentLine() == (harambe.size()-1))
	{
		for (int i = 0; i <= linesToinsert; i++)
		{
			cout << "L " << setw(3) << getCurrentLine()+1;
			cout << " : ";
			cin.ignore();
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

void TextManager::moveToLine(unsigned int lineToMove)
{
	if((lineToMove > -1) && (lineToMove < harambe.size()))
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
//BRAE

int TextManager::load(string fileName)
{
	string line;
	ifstream ifile(fileName);
	setCurrentLine(0);
	if(!ifile.is_open())
		return 0;

	while (getline(ifile, line))
	{
		harambe.push_back(line);
	}

	ifile.close();
	currentFileName = fileName;
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