/*	Name: Nathan Higley
	Date Modified: 3/15/2021
	Purpose: Create an inventory system using a menu, structure, and binary file system.
	Compiler: MS VC++ 2019
*/
#include <iostream>
#include <fstream>
using namespace std;


const int DESCSIZE = 25;

struct Inventory
{
	char desc[DESCSIZE];
	int qty;
	double wcost;
	double rcost;
	int day;
	int month;
	int year;
};

void createFile(fstream&);
void writeRecord(fstream&);
void readFile(fstream&);
void retrieveRecord(fstream&);
void updateRecord(fstream&);
void menu();

int main()
{
	fstream file;
	int choice;
	menu();
	cout << "Select: " << endl;
	cin >> choice;
	while (choice >= 1 && choice <= 5)
	{
		switch (choice)
		{
		case 1:
			createFile(file);
			cout << "File created.\n";
			system("pause");
			break;
		case 2:
			writeRecord(file);
			cout << "File written.\n";
			system("pause");
			break;
		case 3:
			readFile(file);
			system("pause");
			break;
		case 4:
			retrieveRecord(file);
			system("pause");
			break;
		case 5:
			updateRecord(file);
			cout << "File updated.\n";
			system("pause");
			break;
		default:
			return 0;
		}

		menu();
		cout << "Select: " << endl;
		cin >> choice;
	}

	cin.ignore();
	cin.get();
	return 0;
}

void menu()
{
	system("cls");
	cout << "INVENTORY Menu" << endl;
	cout << "1\tCreate an Inventory file." << endl;
	cout << "2\tWrite record to Inventory." << endl;
	cout << "3\tRead Inventory file." << endl;
	cout << "4\tRetrieve a record from Inventory." << endl;
	cout << "5\tUpdate a record in Inventory." << endl;

	cout << "6\tExit" << endl;
}


void createFile(fstream& binf)
{
	binf.open("inv_data.dat", ios::out | ios::binary);
	if (!binf)
	{
		cout << "Could not open.";
		cin.ignore();
		cin.get();
		exit(1);
	}
	binf.close();
}

void writeRecord(fstream& binf)
{
	binf.open("inv_data.dat", ios::out | ios::binary);
	if (!binf)
	{
		cout << "Could not open.";
		cin.ignore();
		cin.get();
		exit(1);
	}
	else
	{
		Inventory record;
		char answer = 'Y';

		do
		{
			cout << "Description: ";
			cin.ignore(); // This was missing from the example to make it function.
			cin.getline(record.desc, DESCSIZE);
			cout << "Quantity: ";
			cin >> record.qty;
			cout << "Wholesale Cost: ";
			cin >> record.wcost;
			cout << "Retail Cost: ";
			cin >> record.rcost;
			//VS will not cooperate with ctime.
			cout << "Date:\nM: ";
			cin >> record.month;
			while (record.month <= 0 || record.month > 12) {
				cout << "Invalid Month!\n";
				cin >> record.month;
			}

			cout << "D: ";
			cin >> record.day;
			while (record.day <= 0 || record.day > 31) {
				cout << "Invalid Day!\n";
				cin >> record.day;
			}

			cout << "Y: ";
			cin >> record.year;
			while (record.year <= 1900 || record.year > 2022) {
				cout << "Invalid Year!\n";
				cin >> record.year;
			}

			binf.write(reinterpret_cast<char*>(&record), sizeof(record));

			cout << "Do you want to enter another record? ";
			cin >> answer;
			cin.ignore();

		} while (answer == 'y' || answer == 'Y');
	}

	binf.close();
}

void readFile(fstream& binf)
{
	binf.open("inv_data.dat", ios::in | ios::binary);
	if (!binf)
	{
		cout << "Could not open.";
		cin.ignore();
		cin.get();
		exit(1);
	}
	else
	{
		Inventory record;
		binf.read(reinterpret_cast<char*>(&record), sizeof(record));
		while (!binf.eof())
		{
			cout << "Description: " << record.desc << endl;
			cout << "Quantity: " << record.qty << endl;
			cout << "Wholesale Cost: " << record.wcost << endl;
			cout << "Retail Cost: " << record.rcost << endl;
			cout << "Date Added: " << record.month << "/" << record.day << "/" << record.year << endl;
			cin.get();
			binf.read(reinterpret_cast<char*>(&record), sizeof(record));

		}

	}
	binf.close();
}

void retrieveRecord(fstream& binf)
{
	binf.clear();
	binf.open("inv_data.dat", ios::in | ios::binary);
	if (!binf)
	{
		cout << "Could not open.";
		cin.ignore();
		cin.get();
		exit(1);
	}
	else
	{
		Inventory record;
		int recnum = 0;
		cout << "What # record do you want to retrieve?" << endl;
		cin >> recnum;
		binf.seekg((recnum - 1) * sizeof(record), ios::beg);
		binf.read(reinterpret_cast<char*>(&record),
			sizeof(record));

		cout << "Inventory Record #" << recnum << ": " << endl;
		cout << "Description: " << record.desc << endl;
		cout << "Quantity: " << record.qty << endl;
		cout << "Wholesale Cost: " << record.wcost << endl;
		cout << "Retail Cost: " << record.rcost << endl;
		cout << "Date Added: " << record.month << "/" << record.day << "/" << record.year << endl;
	}

	binf.close();
}

void updateRecord(fstream& binf)
{
	binf.clear();
	binf.open("inv_data.dat", ios::out | ios::in | ios::binary);
	if (!binf)
	{
		cout << "Could not open.";
		cin.ignore();
		cin.get();
		exit(1);
	}
	else
	{
		Inventory record;
		int recnum = 0;
		cout << "What # record do you want to update?" << endl;
		cin >> recnum;
		binf.seekg((recnum - 1) * sizeof(record), ios::beg);
		binf.read(reinterpret_cast<char*>(&record), sizeof(record));

		cout << "Inventory Record #" << recnum << ": " << endl;
		cout << "Description: " << record.desc << endl;
		cout << "Quantity: " << record.qty << endl;
		cout << "Wholesale Cost: " << record.wcost << endl;
		cout << "Retail Cost: " << record.rcost << endl;
		cout << "Date Added: " << record.month << "/" << record.day << "/" << record.year << endl;
		cin.ignore();

		cout << endl << "Updated Information: " << endl;
		cout << "Description: ";
		cin.getline(record.desc, DESCSIZE);
		cout << "Quantity: ";
		cin >> record.qty;
		cout << "Wholesale Cost: ";
		cin >> record.wcost;
		cout << "Retail Cost: ";
		cin >> record.rcost;

		cout << "Date:\nM: ";
		cin >> record.month;
		while (record.month <= 0 || record.month > 12) {
			cout << "Invalid Month!\n";
			cin >> record.month;
		}
		cout << "D: ";
		cin >> record.day;
		while (record.day <= 0 || record.day > 31) {
			cout << "Invalid Day!\n";
			cin >> record.day;
		}
		cout << "Y: ";
		cin >> record.year;
		while (record.year <= 1900 || record.year > 2022) {
			cout << "Invalid Year!\n";
			cin >> record.year;
		}

		binf.seekp((recnum - 1) * sizeof(record), ios::beg);

		binf.write(reinterpret_cast<char*>(&record),
			sizeof(record));

	}

	binf.close();

}
