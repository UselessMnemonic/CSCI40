/*
	Main Body of Text Editor
	Authored by Group 3
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//necessary functions
void substitueStrings(string oldString, string newString);//reyes
void copyLines(int numberOfLines);//reyes
void type(int linesToPrint);//reyes

void deleteLines(int numberOfLines);//kevin
void moveToLine(int lineToMoveTo);//kevin
void instertLines(int linesToInsert);//kevin

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
string harambe[]; //text body
bool fileEdited; //true if file has been edited since load or last save; false otherwise

//getters/setters
bool getFileEdited(); //get value of fileEdited
void setFileEdited(bool value); //set value of fileEdited


int main() //use this to test your functions
{
	return 0;
}

