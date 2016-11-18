#pragma once

#include <vector>
#include <string>
using namespace std;

class TextManager
{

private:

	vector<string> harambe; //text body
	vector<string> copyStorage; //storage for whatever was copied 
	vector<string> undospace; //storage for undo frames

	string currentFileName; //file name that is being used

	bool fileEdited; //true if file has been edited since load or last save; false otherwise

	unsigned int currentLine; //current line that is in focus

public:

	TextManager(void);
	~TextManager(void);

	//getters/setters
	void setFileEdited(bool value); //set value of fileEdited
	bool getFileEdited(); //get value of fileEdited

	void setCurrentLine(int value); //set the value of currentLine
	int getCurrentLine(); //get current line

	int getNumberLines();
	string getCurrentFilename();

	//necessary functions
	void substitueStrings(string oldString, string newString);//reyes
	void copyLines(int numberOfLines);//reyes
	void type(int linesToPrint);//reyes

	void deleteLines(int numberOfLines);//kevin
	bool moveToLine(int lineToMoveTo);//kevin
	void insertLines(int linesToInsert);//kevin

	void replace(int numLinesToReplace);//chris
	bool locateString(string stringToFind);//chris
	void paste();//chris

	//additional
	void save(string filename); //Brae
	int load(string fileName); //Brae
	void createFile(string fileName);
	void quit(); //Brae
	void moveLine(int newPlace);
	void displayCopyStorage();
	void cutLines(int linesToCut);
	void undo();
};

