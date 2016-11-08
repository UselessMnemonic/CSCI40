#pragma once

#include <vector>
#include <string>
using namespace std;

class TextManager
{

private:

	vector<string> harambe; //text body
	vector<string> copyStorage; //storage for whatever was copied 
	
	string currentFileName; //file name that is being used

	bool fileEdited; //true if file has been edited since load or last save; false otherwise

	int currentLine; //current line that is in focus

public:

	TextManager(void);
	~TextManager(void);

	//getters/setters
	void setFileEdited(bool value); //set value of fileEdited
	bool getFileEdited(); //get value of fileEdited

	void setCurrentLine(int value); //set the value of currentLine
	int getCurrentLine(); //get current line

	int getNumberLines();

	//necessary functions
	void substitueStrings(string oldString, string newString);//reyes
	void copyLines(int numberOfLines);//reyes
	void type(int linesToPrint);//reyes

	void deleteLines(int numberOfLines);//kevin
	void moveToLine(int lineToMoveTo);//kevin
	void insertLines(int linesToInsert);//kevin

	void replace(int numLinesToReplace);//chris
	void locateString(string stringToFind);//chris
	void paste();//chris

	//additional
	void save(string fileName); //Brae
	void load(string fileName); //Brae
	void quit(); //Brae

	void moveUp(); //etc.
	void moveDown(); //etc.
};

