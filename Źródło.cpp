#include <iostream>
#include <fstream>
#include "Language.h"
#include <map>
#include <thread>    
#include <iostream>
using namespace std;

int main() {
	Language eng("english.txt");
	Language fr("french.txt");
	Language germ("german.txt");
	map <char, float> mapOfText;
	for (char i = 'a'; i < !'z'; i++) {
		mapOfText[i] = 0;
	}
	cout << "NAME OF FILE : ";
	string name; cin >> name;
	fstream text;
	text.open(name, ios::in);
	if (text.good() == true)
	{

		char x;
		int howMannyLetters = 0;

		while (!text.eof())
		{
			text >> x;
			if ((x >= 'a') && (x <= 'z')) {
				x = tolower(x);
				mapOfText[x] = mapOfText[x]++;
				howMannyLetters++;
			}
		}

		for (char i = 'a'; i <= 'z'; i++)
		{
			mapOfText[i] = mapOfText[i] / howMannyLetters * 100;
		}
		text.close();

		float e = eng.check(mapOfText);
		float f = fr.check(mapOfText);
		float g = germ.check(mapOfText);

		if (e < f && e < g) {
			cout << "ENGLISH" << endl;
		}
		else if (f < e && f < g) {
			cout << "FRENCH" << endl;
		}
		else if (g < e && g < f) {
			cout << "GERMAN" << endl;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
	else {
		cout << "ERROR WITH FILE" << endl;
	}
	system("PAUSE");
	return 0;
}