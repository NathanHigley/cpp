/*	Name: Nathan Higley
    Date Modified: 2/20/2021
    Purpose: Calculate number of days worked based on the numbers of hours worked using classed objects with overloaded operators.
    Compiler: MS VC++ 2019
*/
#include <iostream>
#include <iomanip>
using namespace std;

class NumDays {
private:
    int hours;
    float days;

public:
    NumDays() {
        hours = 0;
        days = 0;
        days = (float)hours / 8;
    }
    NumDays(string w) {
        cout << "How many hours did " << w << " work?\n";
        cin >> hours;
        days = (float)hours / 8;
    }
    NumDays(int h) {
        hours = 0;
        days = 0;
        storeHours(h);
        days = (float)hours / 8;
    } 
    
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);

    void storeHours(int hoursIn);
    int getHours();
    void storeDays(int daysIn);
    float getDays();
};

//Operator Overloads
NumDays operator+ (NumDays a, NumDays b) {
    return NumDays(a.getHours() + b.getHours());
}

NumDays operator- (NumDays a, NumDays b) {
    return NumDays(a.getHours() - b.getHours());
}

NumDays NumDays::operator++ () {
    hours++;
    return NumDays(hours);
}
NumDays NumDays::operator++(int) {
    NumDays post(hours);
    hours++;
    return post;
}

NumDays NumDays::operator-- () {
    hours--;
    return NumDays(hours);
}
NumDays NumDays::operator--(int) {
    NumDays post(hours);
    hours--;
    return post;
}


void NumDays::storeHours(int hoursIn) {
    hours = hours + hoursIn;
}

int NumDays::getHours() {
    return hours;
}

void NumDays::storeDays(int daysIn) {
    hours = hours + (daysIn * 8);
}

float NumDays::getDays() {
    return days;
}

int main()
{
    NumDays work1(12);
    NumDays work2(14);
    NumDays work3;
    NumDays work4("Worker 4");

    work1++;
    work2--;
    work3 = work1 + work2;
    work4 = work3 - work2;

    cout << fixed << setprecision(2) << "Worker 1 worked for " << work1.getDays() << " Days.\n";
    cout << "Worker 2 worked for " << work2.getHours() << " Hours.\n";
    cout << "Worker 3 worked for " << work3.getDays() << " Days.\n";
    cout << "Worker 4 worked for " << work4.getDays() << " Days.\n";

    return 0;
}