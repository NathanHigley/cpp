#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Customer {
private:
	char first_name[40];
	char last_name[40];

protected:
	static int ID;

public:
	void setFirstName(const char* fname) { strcpy_s(first_name, 40, fname); }
	void setLastName(const char* lname) { strcpy_s(last_name, 40, lname); }
	void setID(int id) { ID = id; }

	const char* getFirstName() { return first_name; }
	const char* getLastName() { return last_name; }
	int getID() { return ID; }

	Customer(const char* Fname, const char* Lname, int id) {
		setFirstName(Fname);
		setLastName(Lname);
	}
	Customer() {
		setFirstName("Customer");
		setLastName("Unknown");
	}
};

class Checking {
private:
	double balance;
	double interest;
	bool active;

public:
	void deposit(int type, double amt) {
		balance += amt;
	}
	void withdraw(int type, double amt) {
		balance -= amt;
	}
	double getBalance() {
		return balance;
	}
	void resetBalance() {
		balance = 0.0;
	}
	void setState(bool state) {
		active = state;
	}
	bool getState() {
		return active;
	}
	void setInterest(double i) {
		interest = i;
	}
	double getInterest() {
		return interest;
	}
	Checking() {
		balance = 0.0;
		interest = 0.02;
		active = false;
	}
};

class Savings {
private:
	double balance;
	double interest;
	bool active;

public:
	void deposit(int type, double amt) {
		balance += amt;
	}
	void withdraw(int type, double amt) {
		if (balance < 1000.0) {
			balance -= 50.00; // penalty
			balance -= amt;
		}
		else {
			balance -= amt;
		}
	}
	double getBalance() {
		return balance;
	}
	void resetBalance() {
		balance = 0.0;
	}
	void setState(bool state) {
		active = state;
	}
	bool getState() {
		return active;
	}
	void setInterest(double i) {
		interest = i;
	}
	double getInterest() {
		return interest;
	}
	Savings() {
		balance = 0.0;
		interest = 0.0105;
		active = false;
	}
};

class MMDA {
private:
	double balance;
	double interest;
	bool active;

public:
	void deposit(int type, double amt) {
		balance += amt;
	}
	void withdraw(int type, double amt) {
		if (balance < 10000.0) {
			balance -= 200.00; // penalty
			balance -= amt;
		}
		else {
			balance -= amt;
		}
	}
	double getBalance() {
		return balance;
	}
	void resetBalance() {
		balance = 0.0;
	}
	void setState(bool state) {
		active = state;
	}
	bool getState() {
		return active;
	}
	MMDA() {
		balance = 0.0;
		interest = 0.0125;
		active = false;
	}
};

class CD {
private:
	double balance;
	double interest;
	int period;
	bool matured;
	bool active;

public:
	void deposit(int type, double amt) {
		balance += amt;
	}
	void withdraw(int type, double amt) {
		if (matured == true) {
			balance -= amt;
		}
		else { // penalty if taken before matured
			if (period <= 3) {
				balance *= 0.90; // penalty
				balance -= amt;
			}
			else if (period <= 6) {
				balance *= 0.80; // penalty
				balance -= amt;
			}
			else if (period <= 12) {
				balance *= 0.50; // penalty
				balance -= amt;
			}
		}
	}
	double getBalance() {
		return balance;
	}
	void setState(bool state) {
		active = state;
	}
	bool getState() {
		return active;
	}
	void setPeriod(int month) {
		period = month;
		if (period <= 3) {
			interest = 0.025;
		}
		else if (period <= 6) {
			interest = 0.03;
		}
		else if (period <= 12) {
			interest = 0.05;
		}
	}
	int getPeriod() {
		return period;
	}
	bool setMature(bool m) {
		matured = m;
	}
	bool getMature() {
		return matured;
	}
	void setInterest(double i) {
		interest = i;
	}
	double getInterest() {
		return interest;
	}
	void resetBalance() {
		balance = 0.0;
	}
	CD() {
		balance = 0.0;
		interest = 0.0;
		period = 0;
		matured = false;
		active = false;
	}
};

class BankAccount : public Customer {
private:
	int accID;
	Checking CheckingAcc;
	Savings SavingsAcc;
	MMDA MMAcc;
	CD CDAcc;

public:
	virtual void deposit(int type, double amt) {
		switch (type) {
		case 1: {
			SavingsAcc.setState(true);
			SavingsAcc.deposit(type, amt);
			break;
		}
		case 2: {
			CheckingAcc.setState(true);
			CheckingAcc.deposit(type, amt);
			break;
		}
		case 3: {
			MMAcc.setState(true);
			MMAcc.deposit(type, amt);
			break;
		}
		case 4: {
			CDAcc.setState(true);
			CDAcc.deposit(type, amt);
			break;
		}
		}
	}
	virtual void withdraw(int type, double amt) {
		switch (type) {
		case 1: {
			SavingsAcc.withdraw(type, amt);
			break;
		}
		case 2: {
			CheckingAcc.withdraw(type, amt);
			break;
		}
		case 3: {
			MMAcc.withdraw(type, amt);
			break;
		}
		case 4: {
			CDAcc.withdraw(type, amt);
			break;
		}
		}
	}
	virtual void resetBalance() {}

	int getaccID() {
		return accID;
	}

	void removeAccount(int type) {
		switch (type) {
		case 1: {
			SavingsAcc.setState(false);
			SavingsAcc.resetBalance();
			break;
		}
		case 2: {
			CheckingAcc.setState(false);
			CheckingAcc.resetBalance();
			break;
		}
		case 3: {
			MMAcc.setState(false);
			MMAcc.resetBalance();
			break;
		}
		case 4: {
			CDAcc.setState(false);
			CDAcc.resetBalance();
			break;
		}
		}
	}

	BankAccount(const char* Fname, const char* Lname) {
		accID = ++ID;
		cout << "Customer ID: " << accID << endl;
		Customer cstm(Fname, Lname, accID);
	}
	BankAccount() {
		accID = ID;
		Customer cstm;
	}

	Checking getCheckingAcc() { return CheckingAcc; }
	Savings getSavingsAcc() { return SavingsAcc; }
	MMDA getMMAcc() { return MMAcc; }
	CD getCDAcc() { return CDAcc; }
};

void saveFile(vector <BankAccount> vec) {
	remove("samediff_data.dat"); // Remove current file
	fstream file;

	// Write objects to file 
	file.open("samediff_data.dat", ios::app | ios::out | ios::binary);
	for (int i = 0; i < vec.size(); i++) {
		file.write(reinterpret_cast<char*>(&vec[i]), sizeof(vec[i]));
	}
	file.close();
}

void createCustomer(vector<BankAccount>& vec) {
	char fname[40];
	char lname[40];

	cout << "Enter Customer First Name: " << endl;
	cin >> fname;

	cout << "Enter Customer Last Name: " << endl;
	cin >> lname;

	BankAccount new_acc(fname, lname); 

	vec.push_back(new_acc);

	saveFile(vec);
	return;
}

void removeCustomer(vector<BankAccount>& vec) {
	int id;

	cout << "Enter Customer ID: " << endl;
	cin >> id;

	//Check Customer ID
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].getID() == id) {
			vec.erase(vec.begin() + i);
			break;
		}
	}

	saveFile(vec);
	return;
}

void createAccount(vector<BankAccount>& vec) {
	int select;
	int id;
	double amt;

	cout << "Enter Customer ID: ";
	cin >> id;

	cout << "Enter Account Type:\n"
		 << "1] Savings\n"
		 << "2] Checking\n" 
		 << "3] Money Market\n" 
		 << "4] Certificate of Deposit\n";		

	cin >> select;

	cout << "Enter Deposit Amount: ";
	cin >> amt;

	// Create account based on Customer ID
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].getaccID() == id) {
			vec[i].deposit(select, amt);
			break;
		}
	}
	saveFile(vec);
}

void removeAccount(vector<BankAccount>& vec) {
	int select;
	int id;

	cout << "Enter Customer ID: ";
	cin >> id;

	cout << "Enter Account Type:\n"
		 << "1] Savings\n"
		 << "2] Checking\n"
		 << "3] Money Market\n"
		 << "4] Certificate of Deposit\n";

	cin >> select;

	// Remove accounts based on Customer ID
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].getaccID() == id) {
			vec[i].removeAccount(select);
			break;
		}
	}
	saveFile(vec);
}

void sortByName(vector<BankAccount>& vec) {
	// Displays all active records
	for (int i = 0; i < vec.size(); i++) {
		cout << "Customer Name: " << vec[i].getLastName() << ", " << vec[i].getFirstName() << endl; // sort by Last Name
		cout << "Customer ID: " << vec[i].getID() << endl;
		if (vec[i].getCheckingAcc().getState()) {
			cout << "Checking Balance: " << vec[i].getCheckingAcc().getBalance() << endl;
		}
		if (vec[i].getSavingsAcc().getState()) {
			cout << "Savings Balance: " << vec[i].getSavingsAcc().getBalance() << endl;
		}
		if (vec[i].getMMAcc().getState()) {
			cout << "Money Market Balance: " << vec[i].getMMAcc().getBalance() << endl;
		}
		if (vec[i].getCDAcc().getState()) {
			cout << "Certificate of Deposit Balance: " << vec[i].getCDAcc().getBalance() << endl;
		}
		cout << "\n";
	}
}

void sortByBalance(vector<BankAccount>& vec) {
	BankAccount temp;
	bool swap = true;
	
	while (swap) { // sort by Balance
		swap = false;
		for (int j = 0; j < (vec.size() - 1); j++) {
			if (vec[j].getCheckingAcc().getBalance() > vec[j + 1].getCheckingAcc().getBalance()) {
				temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
				swap = true;
			}
		}
	}

	// Display all active records
	for (int i = 0; i < vec.size(); i++) {
		cout << "Customer Name: " << vec[i].getLastName() << ", " << vec[i].getFirstName() << endl;
		cout << "Customer ID: " << vec[i].getID() << endl;
		if (vec[i].getCheckingAcc().getState()) {
			cout << "Checking Balance: " << vec[i].getCheckingAcc().getBalance() << endl;
		}
		if (vec[i].getSavingsAcc().getState()) {
			cout << "Savings Balance: " << vec[i].getSavingsAcc().getBalance() << endl;
		}
		if (vec[i].getMMAcc().getState()) {
			cout << "Money Market Balance: " << vec[i].getMMAcc().getBalance() << endl;
		}
		if (vec[i].getCDAcc().getState()) {
			cout << "Certificate of Deposit Balance: " << vec[i].getCDAcc().getBalance() << endl;
		}
		cout << "\n";
	}
}

int menu() {
	int select;
	system("cls");

	cout << " - SAMEDIFF BANK - \n\n"
		 << "1] Create Customer\n"
		 << "2] Create Account\n"
		 << "3] Remove Customer\n"
		 << "4] Remove Account\n"
		 << "5] Display Accounts (Sort: Balance)\n"
		 << "6] Display Accounts (Sort: Last Name)\n"
		 << "\n0] Exit\n";

	cout << "\nSelect: ";
	cin >> select;

	while (select < 0 || select > 6) {
		cout << "Invalid option!" << endl;
		cout << "Select: ";
		cin >> select;
	}
	return select;
}

int Customer::ID = 0; // initialize static ID to increment

int main() {
	int select;
	fstream file;
	vector <BankAccount> accounts;														
	BankAccount record;

	// Put existing data into vector
	file.open("samediff_data.dat", ios::app | ios::in | ios::binary);
	file.read(reinterpret_cast<char*>(&record), sizeof(record));
	while (!file.eof()) {
		accounts.push_back(record);
		file.read(reinterpret_cast<char*>(&record), sizeof(record));
	} 
	file.close();

	 do {
		select = menu();
		switch (select) {
			case 1: {
				cin.ignore();
				createCustomer(accounts);
				cout << "Customer created.\n";
				system("pause");
				break;
			}
			case 2: {
				cin.ignore();
				createAccount(accounts);
				cout << "Account created.\n";
				system("pause");
				break;
			}
			case 3: {
				removeCustomer(accounts);
				cout << "Customer removed.\n";
				system("pause");
				break;
			}
			case 4: {
				removeAccount(accounts);
				cout << "Account removed.\n";
				system("pause");
				break;
			}
			case 5: {
				sortByBalance(accounts);
				system("pause");
				break;
			}
			case 6: {
				sortByName(accounts);
				system("pause");
				break;
			}
		}
	} while (select != 0);

	return 0;
}