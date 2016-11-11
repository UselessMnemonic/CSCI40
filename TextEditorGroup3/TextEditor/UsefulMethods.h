#include <string>
#include <ctype.h>

bool isValidFilename(std::string fileName)
{
	if(fileName.empty())
		return true;
	for(unsigned int x = 0; x < fileName.length(); x++)
	{
		if(fileName[x] != '.')
			if(!isalnum(fileName[x]))
				return false;
	}
	return true;

}

bool isAllWhitespace(std::string input)
{
	for(unsigned int x = 0; x < input.length(); x++)
		if(!iswspace(input[x]))
			return false;
	return true;
}