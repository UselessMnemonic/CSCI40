#include <string>
#include <ctype.h>

bool isValidFilename(std::string fileName)
{
	for(unsigned int x = 0; x < fileName.length(); x++)
	{
		if(fileName[x] != '.')
			if(!isalnum(fileName[x]))
				return false;
	}
	return true;

}