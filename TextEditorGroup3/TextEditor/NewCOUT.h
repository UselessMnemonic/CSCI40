#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class NewCOUT
{

public:
    NewCOUT() //constructor
    {
		upper = false;
		air = false;
		cha = false;
    }

	string makeAdjustments(const char* s) //edit output it needed, special case for const char*
	{
		string v(s);
		return makeAdjustments(v);
	}

	string makeAdjustments(string s) //edit output before print
	{
		int size = s.length();

		if(upper)
		{
			for(int x = 0; x < size; x++)
				s[x] = toupper(s[x]);
		}
		else if(air)
		{
			for(int x = 0, y = 0; x < size; x++, y++)
			{
				if(y%2)
					s[x] = ' ';
			}
		}
		else if(cha)
		{
			string f(s);
			for(int x = 0, y = size-1; x < size && y > -1; x++, y--)
			{
				f[x] = s[y];
			}
			return f;
		}

		return s;
	}

	NewCOUT &operator<<(string s) //defines the << operator for NewCOUT object
	{
		string v = makeAdjustments(s);
		cout << v;
		return *this;
	}

	NewCOUT &operator<<(const char* s) //defines the << operator for NewCOUT object
	{
		string v = makeAdjustments(s);
		cout << v;
		return *this;
	}

	template <class T> NewCOUT &operator<<(T t) //defines the << operator for NewCOUT object
	{
		cout << t;
		return *this;
	}

	void doUpper() //det cout to print all uppercase
	{
		cha = false;
		air = false;
		upper = !upper;
	}

	void doAir()//set cout to replace every other character with space
	{
		cha = false;
		upper = false;
		air = !air;
	}

	void reverse()//reverse output
	{
		upper = false;
		air = false;
		cha = !cha;
	}

    ~NewCOUT()
    {
    }

private: //hide fields
	bool cha;
	bool upper;
	bool air;
};