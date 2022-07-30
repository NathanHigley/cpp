/*	Name: Nathan Higley
    Date Modified: 2/20/2021
    Purpose: Use arrays and classes to calculate an annual sum by quarterly divisions.
    Compiler: MS VC++ 2019
*/
#include <iostream>
using namespace std;

class DivSales {
private:
    static int TotalSales;

public:
    DivSales(int div);
    int salesQtrArray[4];
    void salesCalculate(int q1, int q2, int q3, int q4);
    int getQtrSale(int qtr);
    void displaySales(int div);
};

int DivSales::TotalSales = 0;

DivSales::DivSales(int div) {
    int q1, q2, q3, q4, input;
    cout << "Enter sales per quarter for Division " << div << ":\n";
    cin >> q1;
    cin >> q2;
    cin >> q3;
    cin >> q4;
    
    salesCalculate(q1, q2, q3, q4);
}

void DivSales::salesCalculate(int q1, int q2, int q3, int q4) {
    salesQtrArray[0] = q1;
    salesQtrArray[1] = q2;
    salesQtrArray[2] = q3;
    salesQtrArray[3] = q4;

    TotalSales = TotalSales + q1 + q2 + q3 + q4;
}

int DivSales::getQtrSale(int qtr) {
    return salesQtrArray[qtr];
}

void DivSales::displaySales(int div) {
    cout << "\nDivision " << (div + 1) << "\t";
    for (int i = 0; i < 4; i++) {
            cout << "$" << getQtrSale(i) << "\t";
        }
    cout << "\n";

    //Display Total when finished
    if (div == 5) {
        cout << "\nThe Total Sales for this year is $" << TotalSales << endl;
    }
}

int main()
{
    DivSales div1(1);
    DivSales div2(2);
    DivSales div3(3);
    DivSales div4(4);
    DivSales div5(5);
    DivSales div6(6);
    DivSales DivArray[6] = { div1, div2, div3, div4, div5, div6 };

    //Display each division's sales
    for (int n = 0; n < 6; n++) {
        DivArray[n].displaySales(n);
    }

    return 0;
}