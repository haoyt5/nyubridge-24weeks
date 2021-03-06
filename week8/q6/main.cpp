#include <iostream>

using namespace std;

bool isDigitString(string sentence, int startIndex, int endIndex);

void convertDigitString(string &sentence, int startIndex, int endIndex);

int main() {
    string sentence;

    cout << "Please enter a line of text:" << endl;

    getline(cin, sentence);

    int startIndex = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            int endIndex = i - 1;
            bool digitString = isDigitString(sentence, startIndex, endIndex);
            if (digitString) {
                convertDigitString(sentence, startIndex, endIndex);
            }
            startIndex = endIndex + 2;
        }
    }

    cout << sentence << endl;
    return 0;
}

bool isDigitString(string sentence, int startIndex, int endIndex) {
    bool isDigitString = true;
    for (int i = 0; i < (endIndex - startIndex + 1); i++) {
        if (sentence[startIndex + i] < '0' || sentence[startIndex + i] > '9') {
            isDigitString = false;
        }
    }
    return isDigitString;
}

void convertDigitString(string &sentence, int startIndex, int endIndex) {
    for (int i = 0; i < (endIndex - startIndex + 1); i++) {
        char stringX = 'x';
        sentence[startIndex + i] = stringX;
    }
}