/*	Name: Nathan Higley
	Date Modified: 2/20/2021
	Purpose: Translate dollar values into text descriptions.
	Compiler: MS VC++ 2019
*/
#include <iostream>
using namespace std;

class Numbers {
public:
	Numbers();
	void print();
	string convert(int number, string place);

private:
	int number;
	static string lessThan20[];
	static string lessThan100[];
	static string zero;
	static string hundred;
	static string thousand;
};

string Numbers::lessThan20[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
					"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string Numbers::lessThan100[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
string Numbers::zero = "zero";
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers() {
	cout << "Enter a Number (0-9999):\n$";
	cin >> number;
	while (number < 0 || number > 9999) {
		cout << "Invalid!\n";
		cin >> number;
	}
}

string Numbers::convert(int number, string place) {
	string numPhrase;
	
	//Over Twenty
	if (number > 19) {
		numPhrase += lessThan100[(number / 10)] + " " + lessThan20[(number % 10)];
	}
	//Under Twenty
	else {
		numPhrase += lessThan20[number];
	}
	//Over Zero
	if (number) {
		numPhrase += " " + place;
	}

	return numPhrase;
}

void Numbers::print() {

	string numOut;

	//Thousand
	numOut += convert(((number / 1000) % 100), thousand) + " ";

	//Hundred
	numOut += convert(((number / 100) % 10), hundred) + " ";

	//Ten / One
	numOut += convert((number % 100), "");
	
	//Zero
	if (number == 0) {
		numOut = zero;
	}

	cout << numOut << "dollars\n";
}

int main()
{
	Numbers check;

	check.print();

	return 0;
}