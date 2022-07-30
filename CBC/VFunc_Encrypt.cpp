/*	Name: Nathan Higley
    Date Modified: 3/18/2021
    Purpose: Create an encryption/decryption program using classes with virtual functions.
    Compiler: MS VC++ 2019
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Encryption {
protected:
    ifstream inFile;
    ofstream outFile;
public:
    Encryption(const string& inFileName, const string& outFileName);
    virtual ~Encryption();
    virtual char transform(char ch, int mode, int eKey) const = 0;
    virtual void encrypt(int mode) final;
    int getKey();
};

Encryption::Encryption(const string& inFileName, const string& outFileName) {
    inFile.open(inFileName);
    outFile.open(outFileName);
    if (!inFile) {
        cout << "File " << inFileName << " cannot open.";
        exit(1);
    }
    if (!outFile)
    {
        cout << "File " << outFileName << " cannot open.";
        exit(1);
    }
}

Encryption::~Encryption() {
    inFile.close();
    outFile.close();
}

void Encryption::encrypt(int mode) {
    char ch;
    char transCh;
    int eKey = getKey();

    inFile.get(ch);
    while (!inFile.fail()) {
        transCh = transform(ch, mode, eKey);
        outFile.put(transCh);
        inFile.get(ch);
    }
}

int Encryption::getKey() {
    int eKey;
    cout << "Enter encryption key: ";
    cin >> eKey;
    return eKey;
}

class SimpleEncryption : public Encryption {
public:
    char transform(char ch, int mode, int eKey) const override {
        if (mode == 1) { //Encrypt
            return ch + eKey;
        }
        if (mode == 2) { //Decrypt
            return ch - eKey;
        }
    }
    SimpleEncryption(const string& inFileName, const string& outFileName)
        : Encryption(inFileName, outFileName) {}
};

int main() {
    string inFileName, outFileName;
    int mode;
    
    cout << "1.\tEncrypt a File\n2.\tDecrypt a File\n";
    cin >> mode; 
    while (mode != 1 && mode != 2) { //Obfuscate doesn't seem to work with switches.
        cout << "Invalid!\n";
        cin >> mode;
    }
    if (mode == 1) { //Encrypt
        cout << "Enter input file to encrypt: ";
        cin >> inFileName;
        cout << "Enter output file: ";
        cin >> outFileName;
        SimpleEncryption obfuscate(inFileName, outFileName);
        obfuscate.encrypt(mode);
        cout << "File encrypted.\n";
    }
    else if (mode == 2) { //Decrypt
        cout << "Enter input file to decrypt: ";
        cin >> inFileName;
        cout << "Enter output file: ";
        cin >> outFileName;
        SimpleEncryption obfuscate(inFileName, outFileName);
        obfuscate.encrypt(mode);
        cout << "File decrypted.\n";
    }
    system("pause");
    return 0;
}