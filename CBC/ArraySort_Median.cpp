/*	Name: Nathan Higley
	Date Modified: 2/19/2021
	Purpose: Allocate a dynamic array of values, sort them into ascending order, and obtain median.
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
	cout << endl << "Sorted Array:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << *(ptrArray + i) << "\t";
	}
	cout << endl;
}

float arrayMedian(int* (ptrArray), int SIZE) {
	//Median of Odd Array Size
	float median = *(ptrArray + (SIZE / 2));

	//Median of Even Array Size
	if (SIZE % 2 == 0) {
		median = (median + *(ptrArray + (SIZE / 2) - 1)) / 2;
	}
	return median;
}

int main() {

	int SIZE;
	int* ptrArray;

	cout << "How many elements?\n";
	cin >> SIZE;
	while (SIZE < 1) {
		cout << "Invalid! Total must be positive.\n";
		cin >> SIZE;
	}

	cout << endl << "Values of " << SIZE << " elements:\n";
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

	//Display Median
	cout << endl << "The Median of the array was " << arrayMedian(ptrArray, SIZE) << endl;

	return 0;
}