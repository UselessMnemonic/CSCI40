#include <string>
using namespace std;

string menuPrompt = "Select your course of action from the list of commands below.\n\nS[U]bstitute    [T]ype      [R]epalce     [M]ove        [A]djust    [G]oto      [Q]uit\n[C]opy          [P]aste     [I]nsert      [D]elete      [F]ind      [S]ave";
string filenameError = "This is not a valid file name, please try again, or enter \"quit\" to return to menu.\n";
string invalidChoiceError = "That is not a valid choice. Please choose again.\n";
string fileMenuPromt = "Would you like to load or create a new file?\n1. Load File\n2. Create File\n3. Quit\n";
string selectionMarker = "Enter: "; //use this maybe after all prompts?
string enterFilename = "Enter an alphanumeric file name: ";
string quitMessage = "Hit Enter to close the program. . .";
string gagCopyright = "Copyright Team 3 - 2016\n\n";

char choices[] = {'u','t', 'r', 'm', 'a', 'g', 'q', 'c', 'p', 'i', 'd', 'f', 's'};