#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void openInputFile(std::ifstream &inFile);

bool symbolsAreBalance(ifstream &inFile);

bool containOpenSymbol(string &word);

bool containEndSymbol(string &word);

void iterateAndPush(string &str, stack<string> &strStack);

bool isPairedSymbol(string &ending, string &opening);

void openInputFile(std::ifstream &inFile) {
    string filename;
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

bool symbolsAreBalance(ifstream &inFile) {
    stack<string> symbolStack;
    string line;
    while (getline(inFile, line)) {
        string word;
        stringstream ss(line);
        while (ss >> word) {
            if (word == "begin") {
                symbolStack.push(word);
            }
            if (containOpenSymbol(word)) {
                iterateAndPush(word, symbolStack);
            }
            if (word == "end" || containEndSymbol(word)) {
                if (word == "end") {
                    if (symbolStack.empty()) {
                        return false;
                    }
                    string opening = symbolStack.top();
                    symbolStack.pop();
                    if (opening != "begin") {
                        return false;
                    }
                }
                if (containEndSymbol(word)) {
                    if (symbolStack.empty()) {
                        return false;
                    } else {
                        string edString;
                        for (char &symbol: word) {
                            if (symbol == '}') {
                                edString = "}";
                                string opening = symbolStack.top();
                                symbolStack.pop();
                                if (!isPairedSymbol(edString, opening)) {
                                    return false;
                                }
                            }
                            if (symbol == ']') {
                                edString = "]";
                                string opening = symbolStack.top();
                                symbolStack.pop();
                                if (!isPairedSymbol(edString, opening)) {
                                    return false;
                                }
                            }
                            if (symbol == ')') {
                                edString = ")";
                                string opening = symbolStack.top();
                                symbolStack.pop();
                                if (!isPairedSymbol(edString, opening)) {
                                    return false;
                                }
                            }
                        }

                    }
                }
            }
        }
    }
    return symbolStack.empty();
}


bool containOpenSymbol(string &word) {
    bool result = false;
    if ((word.find('{') != std::string::npos)) {
        result = true;
    }
    if ((word.find('[') != std::string::npos)) {
        result = true;
    }
    if ((word.find('(') != std::string::npos)) {
        result = true;
    }
    return result;
}

bool containEndSymbol(string &word) {
    bool result = false;
    if ((word.find('}') != std::string::npos)) {
        result = true;
    }
    if ((word.find(']') != std::string::npos)) {
        result = true;
    }
    if ((word.find(')') != std::string::npos)) {
        result = true;
    }
    return result;
}


bool isPairedSymbol(string &ending, string &opening) {
    if (ending == "}" && opening == "{") {
        return true;
    }
    if (ending == "]" && opening == "[") {
        return true;
    }
    if (ending == ")" && opening == "(") {
        return true;
    }
    return false;
}

void iterateAndPush(string &str, stack<string> &strStack) {
    string opString;
    for (char &symbol: str) {
        if (symbol == '{') {
            opString = "{";
            strStack.push(opString);
        }
        if (symbol == '[') {
            opString = "[";
            strStack.push(opString);
        }
        if (symbol == '(') {
            opString = "(";
            strStack.push(opString);
        }
    }
}


int main() {
    std::ifstream inFile1;
    openInputFile(inFile1);
    if (symbolsAreBalance(inFile1)) {
        cout << "Result: The symbols are balanced." << endl;
    } else {
        cout << "Result: The symbols are not balanced." << endl;
    }
    return 0;
}
