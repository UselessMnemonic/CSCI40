#include <string>
using namespace std;

string menuPrompt = "Select your course of action from the list of commands below.\n\nSu[B]stitute    [T]ype      [R]epalce     [M]ove        Save [A]s   [G]oto      [Q]uit     [H]elp\n[C]opy          [P]aste     [I]nsert      [D]elete      [F]ind      [S]ave      [U]ndo     [X] Cut\n\n";
string filenameError = "This is not a valid file name, please try again, or enter \"quit\" to return to menu.\n";
string invalidChoiceError = "That is not a valid choice. Please choose again.\n";
string fileMenuPromt = "Would you like to load or create a new file?\n1. Load File\n2. Create File\n3. Quit\n";
string selectionMarker = "Enter: "; //use this maybe after all prompts?
string enterFilename = "Enter an alphanumeric file name: ";
string quitMessage = "Hit Enter to close the program. . .";
string gagCopyright = "Copyright Team 3 - 2016\n\n";
string helpText = "--Help Page--\n Substitute [B] - Replaces the first occurance of the specified string with another on the current line.\n       Type [T] - Displays the next n lines, including the current line.\n    Repalce [R] - Edits over the next n lines, including the current line.\n       Move [M] - Moves the current line to the specified line.\n    Save As [A] - Saves the file under a new filename.\n       Goto [G] - Changes the current line to the specified line number;\n       Quit [Q] - Exits the program.\n       Help [H] - Displays this help mesage.\n       Copy [C] - Copies the next n lines, including the current line.\n      Paste [P] - Pastes the clipboard into the space before the current line and the previous line.\n     Insert [I] - Inserts n lines into the space before the current line and the previous line, or after the last line.\n     Delete [D] - Deletes the next n lines, including the current one.\n       Find [F] - Finds all occurances of the specified string from the current line to the end of the file.\n       Save [S] - Saves the file.\n       Undo [U] - Undos the last edit.\n        Cut [X] - Cuts out the next n lines, including the current line.\n";
string spacewaster = "Ha, you can't deallocate me THIS runtime! Muahahaha!";