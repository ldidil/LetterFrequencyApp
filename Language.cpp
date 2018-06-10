#include "Language.h"
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


float Language::check(map<char, float> oryginal)
{
	float x;
	float sum = 0;
	for (char i = 'a'; i <='z'; i++) {
		x=letters[i] - oryginal[i];
		if (x < 0) x = -x;
		sum += x;
	}
	cout << sum << endl;
	return sum;
	
}

Language::Language(string name)
{
	fstream file;
	file.open(name, ios::in);
	char letter;
	float percentage;
	while (!file.eof())
	{
		file >> letter;
		file >> percentage;
		letters[letter] = percentage;
	}

	file.close();
}


Language::~Language()
{
}
