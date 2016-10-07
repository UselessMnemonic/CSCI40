# CSCI40
This is the progress report for Group 3

Terms:
token : a red flag of sorts, something we seek out or that directs our course of action. The token in the locateString function is the substring of the text body we are trying to find; in locateString("XYZ"), 'XYZ' is the token that could appear in the body text

The following methods are assigned to the following group members:

*Reyes*

substitueStrings : Substitutes every occurrence of specified token in the current line with another token

copyLines : copies n lines of text on interval [currentLine, currentLine+n)

type : prints n lines of text on interval [currentLine, currentLine+n)

*Kevin*

deleteLines : deletes n lines on the interval [currentLine, currentLine+n)

moveToLine : moves the current line to the specified line

insertLines : insrets n lines from currentLine to currentLine+n

*Chris*

replace : blanks out n lines on the interval [currentLine, currentLine+n)

locateString : finds first occurance of token on interval [currentLine, bodyEnd]

paste : inserts all n lines of 

*Brae*

save : saves the text to a file

load : loads text from a file

quit : prompts user to save and quit

*The following are extra methods:

moveUp : moves current line to up

moveDown : moves current line to down

*The following are globals that may be used, as well as thier getters and setters if any:

harambe : Text Body

storedCopy : Copy/Paste area

fileEdited : should be false if file was just loaded or saved; true when storedCopy has been changed

getFileEdited : get value of fileEdited

setFileEdited : set value of fileEdited

currentLine : current line that user sees

getCurrentLine : gets value of currentLine

setCurrentLine : sets value of currentLine
