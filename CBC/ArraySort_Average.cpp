/*	Name: Nathan Higley
	Date Modified: 2/19/2021
	Purpose: Allocate a dynamic array of values, sort them into ascending order, and obtain mean.
	Compiler: MS VC++ 2019
*/
#include <iostream>
#include <iomanip>
using namespace std;

void arraySort(int* (ptrArray), int SIZE) {
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
	cout << endl << "Scores:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << *(ptrArray + i) << "\t";
	}
	cout << endl;
}

float arrayMean(int* (ptrArray), int SIZE) {
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

int main() {

	int SIZE;
	int* ptrArray;

	cout << "How many Test Scores?\n";
	cin >> SIZE;
	while (SIZE < 1) {
		cout << "Invalid! Total must be positive.\n";
		cin >> SIZE;
	}

	cout << endl << "Scores of " << SIZE << " Tests:\n";
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
	cout << endl << "The Mean score was " << arrayMean(ptrArray, SIZE) << endl;

	return 0;
}