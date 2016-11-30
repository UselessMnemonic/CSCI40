#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class NewCOUT
{

public:
    NewCOUT()
    {
		upper = false;
		air = false;
		cha = false;
    }

	string makeAdjustments(const char* s)
	{
		string v(s);
		return makeAdjustments(v);
	}

	string makeAdjustments(string s)
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
				f[x] = toupper(s[y]);
			}
			return f;
		}

		return s;
	}

	NewCOUT &operator<<(string s)
	{
		string v = makeAdjustments(s);
		cout << v;
		return *this;
	}

	NewCOUT &operator<<(const char* s)
	{
		string v = makeAdjustments(s);
		cout << v;
		return *this;
	}

	template <class T> NewCOUT &operator<<(T t)
	{
		cout << t;
		return *this;
	}

	void doUpper()
	{
		cha = false;
		air = false;
		upper = !upper;
	}

	void doAir()
	{
		cha = false;
		upper = false;
		air = !air;
	}

	void reverse()
	{
		upper = false;
		air = false;
		cha = !cha;
	}

    ~NewCOUT()
    {
    }

private:
	bool cha;
	bool upper;
	bool air;
};