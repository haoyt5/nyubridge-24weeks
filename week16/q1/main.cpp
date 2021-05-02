#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openInputFile(std::ifstream &inFile) {
    string filename ;
    cout << "The file name you are going to open? ";
    cin >> filename;
    inFile.open(filename);

    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "The file name you are going to open? ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

bool symbolIsBalance(const ifstream &inFile) {
    return true;
}

int main() {
    std::ifstream inFile1;
    openInputFile(inFile1);
    if (symbolIsBalance(inFile1)) {
        cout << "Result: The symbol is balanced." << endl;
    } else {
        cout << "Result: The symbol is not balanced." << endl;
    }
    return 0;
}
