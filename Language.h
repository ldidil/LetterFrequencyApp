#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class Language
{
	map <char, float> letters;
public:
	float check(map <char, float> oryginal);
	Language(string name);
	~Language();
};

