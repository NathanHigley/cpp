/*	Name: Nathan Higley
	Date Modified: 2/19/2021
	Purpose: Allocate a dynamic array of values, sort them into ascending order, and obtain mean, median, and mode.
	Compiler: MS VC++ 2019
*/
#include <iostream>
#include <iomanip>
using namespace std;

void arraySort(int *(ptrArray), int SIZE) {
	//Sort, if check is less than current
	for (int i = 0; i < SIZE; i++) {
		for (int check = i + 1; check < SIZE; check++)
		{
			if (*(ptrArray + check) < *(ptrArray + i)) {
				int current = *(ptrArray + i);
				*(ptrArray + i) = *(ptrArray + check);
				*(ptrArray + check) = current;
			}
		}
	}
	//Print Sorted Array
	cout << endl << "Sorted Array:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << *(ptrArray + i) << "\t";
	}
	cout << endl;
}

float arrayMean(int *(ptrArray), int SIZE) {
	int total = 0;
	int i;
	//Sum of Scores
	for (i = 0; i < SIZE; i++) {
		total += *(ptrArray + i);
	}

	//Average of Scores
	float mean = total / SIZE;
	return mean;
}

float arrayMedian(int *(ptrArray), int SIZE) {
	//Median of Odd Array Size
	float median = *(ptrArray + (SIZE / 2));

	//Median of Even Array Size
	if (SIZE % 2 == 0) {
		median = (median + *(ptrArray + (SIZE / 2) -1 )) / 2;
	}
	return median;
}

float arrayMode(int *(ptrArray), int size) {
	int occur = 1;
	int max_occur = 0;
	int mode = *(ptrArray);

	//Check for Occurence
	for (int check = 0; check < (size - 1); check++)
	{
		//Add occurence, if check is valid
		if (*(ptrArray + check) == *(ptrArray + (check + 1)))
		{
			occur++;
			if (occur > max_occur)
			{
				max_occur = occur;
				mode = *(ptrArray + check);
			}
		}
		//Reset, if no occurence
		else
			occur = 1;
	}
	return mode;
}

int main() {

	int SIZE;
	int *ptrArray;

	cout << "How many Students were surveyed?\n";
	cin >> SIZE;
	while (SIZE < 1) {
		cout << "Invalid! Total must be positive.\n";
		cin >> SIZE;
	}

	cout << endl << "How many movies did each of the " << SIZE << " Students see?\n";
	ptrArray = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		cin >> *(ptrArray + i);
		while (*(ptrArray + i) < 0) {
			cout << "Invalid! Values must be positive.\n";
			cin >> *(ptrArray + i);
		}
	}

	//Display Sorted Array
	arraySort(ptrArray, SIZE);
	cout << setprecision(1) << fixed;

	//Display Mean Score
	cout << endl << "The Mean of movies seen was " << arrayMean(ptrArray, SIZE) << endl;

	//Display Median
	cout << endl << "The Median of movies seen was " << arrayMedian(ptrArray, SIZE) << endl;

	//Display Mode
	cout << endl << "The Mode of movies seen was " << arrayMode(ptrArray, SIZE) << endl;

	return 0;
}