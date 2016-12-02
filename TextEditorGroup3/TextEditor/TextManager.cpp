#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "TextManager.h"
#include "UsefulMethods.h"


TextManager::TextManager(void) //constructor that initalizes all fields as specified
{
	harambe = vector<string>(); //lines are stored here
	copyStorage = vector<string>(); //cut and copy results are stored here
	fileEdited = false; //indicates whether the file was edited or not
	currentLine = 0; //pointer for current line
	currentFileName =  ""; //stores the current filename
	undospace = vector<string>(); //stores state of line storage vector for a one-frame-wide undo command
}
TextManager::~TextManager(void)
{
}
bool TextManager::getFileEdited() //getter for fileEdited field
{
	return fileEdited;
}
void TextManager::setFileEdited(bool value) //getter for fileEdited field, stored undo frames
{
	fileEdited = value;

	if(!value)
		return;

	undospace = harambe;
}
int TextManager::getCurrentLine() //getter for current line pointer
{
	return currentLine;
}
void TextManager::setCurrentLine(int value) //setter for current line pointer
{
	currentLine = value;
}
string TextManager::getCurrentFilename() //getter for current filename
{
	return currentFileName;
}
void TextManager::createFile(string fileName) //setter for current filename
{
	currentFileName = fileName;
}

//REYES
void TextManager::type(int numLinesToType) //types numLinesToType lines, including current line
{
	if(harambe.size() == 0) //stop if there are no lines
		return;
	int res = harambe.size() - getCurrentLine(); //check if there are numLinesToType lines ahead, if not change number of lines to type to remaining
	if (numLinesToType > res)
		numLinesToType = res;
	for (int x = 0; x < numLinesToType; x++) //for the next numLinesToType lines
	{
		cout << "L " << setw(3) << getCurrentLine()+x+1; //show line number
		cout << " : " << harambe.at(getCurrentLine() + x) << endl; //show line contents
	}
}

void TextManager::copyLines(int numLinesToCopy) //copies numLineToCopy lines, including current line
{
	if(harambe.size() == 0) //stop if there are no lines
		return;
	if(harambe.size() - getCurrentLine() < numLinesToCopy) //check if there are numLinesToCopy lines ahead, if not change number of lines to copy to remaining
		numLinesToCopy = harambe.size() - getCurrentLine();
	copyStorage.clear(); //clear the copy vector
	for(int x = 0; x < numLinesToCopy; x++)
	{
		copyStorage.push_back(harambe.at(getCurrentLine()+x)); //store copied lines to storage vector
	}
}

void TextManager::substitueStrings(string oldS, string newS) //find occurances of oldS and substitute them into newS in current line
{
	if(harambe.size() == 0) //stop if there are no lines
		return;
	string testString; //variable to perform tests on
	testString = harambe.at(getCurrentLine()); //get the contents of the current line
	int pos = testString.find(oldS); //test if the current line contains the specified substring
	if (pos != string::npos) //if the line contains the token
	{
		setFileEdited(true); //this method changes the contents of the line, so we store an undo frame
		testString.replace(pos, newS.size(), newS); //replace the first occurance
		harambe[getCurrentLine()] = testString; //make changes to the vector
	}
}

//CHRIS
void TextManager::replace(int numLinesToReplace) //prompts user for input to replace the next numLinesToReplace lines, including the current line
{
	if(harambe.size() == 0) //stop if there are no lines
		return;

	setFileEdited(true);
	if (numLinesToReplace + getCurrentLine() > harambe.size()) //if number of lines to replace exceeds the size of the text body
		numLinesToReplace = harambe.size() - getCurrentLine();//then we set the number to how many are left
	string input; //variable to store user input
	cout << endl; //print new line...
	cin.ignore(); //...and ignore it, for input safety
	for (int x = 0; x < numLinesToReplace; x++)//for the lines specified
	{
		cout << "L " << setw(3) << getCurrentLine()+x + 1; //print the line's number
		cout << " : ";
		getline(cin, input); //get user input
		harambe[getCurrentLine()+x] = input; //set the line to the input
	}
	setCurrentLine(numLinesToReplace + getCurrentLine() - 1); //set current line to last line replaced
}

void TextManager::cutLines(int numLinesToCut) //cuts lines and stores them into the copy space, including the current line
{
	if (harambe.size() == 0) //stop if there are not lines
		return;

	setFileEdited(true); //this method edits the vector, so we store an undo frame
	if(harambe.size() - getCurrentLine() < numLinesToCut) //if there are less lines available than we can cut
		numLinesToCut = harambe.size() - getCurrentLine(); //set the number of lines we cut to the remaining available
	copyStorage.clear(); //clear the copt vector
	for(int x = 0; x < numLinesToCut; x++) //for the specified lines...
	{
		copyStorage.push_back(harambe.at(getCurrentLine()+x)); //store the line to copy storage
	}
	harambe.erase(harambe.begin()+getCurrentLine(), harambe.begin()+getCurrentLine()+numLinesToCut); //remove all lines on interval [current line, current line + numLinesToCut)
}

bool TextManager::locateString(string stringToFind)
{
	if(harambe.size() == 0) //stop if there are no lines
		return true;
	bool res = false; //store result of the search
	string testString; //varaible of substring to look for
	for (unsigned int x = getCurrentLine(); x < harambe.size(); x++) //for each line in the document, starting at current line
	{
		testString = harambe.at(x); //get the line...
		int pos = testString.find(stringToFind); //..check for substring
		if (pos != string::npos) //if the line contains the token
		{
			cout << "L " << setw(3) << x+1; //print line number
			cout << " : " << testString << endl; //print contents of line
			for(int x = 0; x < pos+8; x++) //print ^ to show begining of substring
				cout << ' ';
			cout << '^' << endl;
			res = true; //return success
		}
	}

	return res; //return failure
}

void TextManager::paste() //paste copy storage in between current line and previous, or, if at the end of the file, onto the end of the vector, setting the current line to the last line pasted
{
	if(copyStorage.size() == 0) //stop if there are no lines to paste
		return;
	setFileEdited(true); //this method changes the contents of the vector so we store an undo frame
	if (getCurrentLine() == (harambe.size() - 1)) //special case for pasting onto end of file
	{
		for (unsigned int x = 0; x < copyStorage.size(); x++)
			harambe.push_back(copyStorage.at(x));
	}
	else
	{
		for (unsigned int x = 0; x < copyStorage.size(); x++) //for each line of copied text, paste before current line
			harambe.insert(harambe.begin() + getCurrentLine() + x, copyStorage.at(x));
	}

	setCurrentLine(getCurrentLine()+copyStorage.size()-1);  //set the current line to the last line pasted
}


//KEVIN
void TextManager::insertLines(int linesToinsert) //inserts lines into the line vector
{
	string input; //store user input
	cin.ignore();
	setFileEdited(true); //this changes the contents of the vector, so we store an undo frame
	if(harambe.size() == 0 || getCurrentLine() == (harambe.size()-1)) //if the vector is empty or we are at the end of the vector
	{
		int adjust = 0;
		if(getCurrentLine() == -1)
			adjust = 1;

		for (int i = 0; i < linesToinsert; i++) //for each line to insert
		{
			cout << "L " << setw(3) << getCurrentLine()+1 + adjust; ; //print line number
			cout << " : "; 
			getline(cin, input); //get input
			harambe.push_back(input); //add onto the vector
			setCurrentLine(getCurrentLine() + 1); //set the current line to the line we just added... we end up just one above the last line inserted as the current line
		}
	}
	else //otherwise, if we are inside the vector...
	{
		for (int i = 0; i < linesToinsert; i++) //for each line to insert
		{
			cout << "L " << setw(3) << getCurrentLine()+1; //print line number
			cout << " : ";
			getline(cin, input); //get input
			harambe.insert(harambe.begin() + getCurrentLine(), input); //insert the line before the current line
			setCurrentLine(getCurrentLine() + 1); //set the current line to the line we just added... we end up just one above the last line inserted as the current line
		}
		setCurrentLine(getCurrentLine() - 1); //adjust current line for accuracy
	}

}

bool TextManager::moveToLine(int lineToMove) //set the line pointer to the specified line number
{
	if((lineToMove > -1) && (lineToMove < harambe.size())) //if the line number is valid, proceed
	{
		setCurrentLine(lineToMove);
		return true;
	}
	else //report error
		return false;
}

void TextManager::moveLine(int newPlace) //moves the current line to the specified line
{
	if(harambe.size() == 0) //stop if there are no lines
		return;
	if (newPlace >= harambe.size() - 1) //special case if store at the end of the file
		newPlace = harambe.size();
	setFileEdited(true); //vector is edited so we store undo frame
	string old = harambe.at(getCurrentLine()); //gave the current line
	harambe.erase(harambe.begin()+getCurrentLine()); //remove the current line
	harambe.insert(harambe.begin()+newPlace, old);
	setCurrentLine(newPlace);
	if (getCurrentLine() == harambe.size()) //adjust current line for accuracy
		setCurrentLine(newPlace - 1);
}

void TextManager::deleteLines(int linesToDelete)
{
	if(harambe.size() == 0) //stop if there are no lines
		return;
	setFileEdited(true); //changes vector so we save undo frame

	if(harambe.size() - getCurrentLine() < linesToDelete) //if there are less lines available than we can delete
		linesToDelete = harambe.size() - getCurrentLine(); //set lines to delete to number left

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
	currentFileName = filename;
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
	setFileEdited(false);
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

void TextManager::undo()
{
	harambe.swap(undospace);
	setCurrentLine(0);
	if(undospace.size() == 0)
		setCurrentLine(-1);
}