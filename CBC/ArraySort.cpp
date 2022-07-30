/*	Name: Nathan Higley
    Date Modified: 2/2/2021
    Purpose: Sort an array of numbers into an ascending order.
    Compiler: MS VC++ 2019
*/
#include<iostream>
using namespace std;

int main() {
    int i;
    int check;
    int current;

    int SortArray[5] = { 13, 49, 23, 35, 4 };

    //Print Unsorted Array
    cout << "Unsorted Array:" << endl;
    for (i = 0; i < 5; i++) {
        cout << SortArray[i] << "\t";
    }

    //Sort, if check is less than current
    for (i = 0; i < 5; i++) {
        for (check = i + 1; check < 5; check++)
        {
            if (SortArray[check] < SortArray[i]) {
                current = SortArray[i];
                SortArray[i] = SortArray[check];
                SortArray[check] = current;
            }
        }
    }
    //Print Sorted Array
    cout << endl << "Sorted Array:" << endl;
    for (i = 0; i < 5; i++) {
        cout << SortArray[i] << "\t";
    }

    return 0;
}