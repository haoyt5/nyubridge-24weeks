#include <iostream>
#include <vector>

using namespace std;
const int upperCaseA = 'A';
const int upperCaseZ = 'Z';
const int lowerCaseA = 'a';
const int lowerCaseZ = 'z';

void countWords(string sentence, int &wordCount, int (&countArray)[26], vector<int> typeArray);

char lowerCaseFormatter(char alphabet);

bool isAlphabet(char input);

void printAlphabetCount(int (&countArray)[26], vector<int> &typeArray);

int main() {
    int wordCounts = 0;
    int countArray[26] = {0};
    string sentence;
    vector<int> typeArray;
    cout << "Please enter a line of text: " << endl;
    getline(cin, sentence);

    countWords(sentence, wordCounts, countArray, typeArray);
    cout << wordCounts << "\tword";
    if (wordCounts != 1) {
        cout << "s";
    }
    cout << endl;
    printAlphabetCount(countArray, typeArray);
    return 0;
}

void countWords(string sentence, int &wordCount, int (&countArray)[26], vector<int> typeArray) {
    for (int i = 0; i < sentence.length(); i++) {
        if (isAlphabet(sentence[i])) {
            char alphabet = lowerCaseFormatter(sentence[i]);
            int index = alphabet - lowerCaseA;
            if (!countArray[index]) {
                countArray[index] = 1;
                typeArray.push_back(sentence[i]);
            } else {
                countArray[index]++;
            }

        }
        if (i == 0) {
            wordCount++;
        }
        if (sentence[i] == ' ' && i != sentence.length() - 1) {
            wordCount++;
        }
    }


}

bool isAlphabet(char input) {
    bool isAlphabet = false;
    if ((input >= upperCaseA && input <= upperCaseZ) || (input >= lowerCaseA && input <= lowerCaseZ)) {
        isAlphabet = true;
    }
    return isAlphabet;
}

char lowerCaseFormatter(char alphabet) {
    int convertNumber = lowerCaseA - upperCaseA;
    char lowerCaseResult = alphabet;
    if (alphabet >= upperCaseA && alphabet <= upperCaseZ) {
        lowerCaseResult = char(alphabet + convertNumber);
    }
    return lowerCaseResult;
}

void printAlphabetCount(int (&countArray)[26], vector<int> &typeArray) {
    for (int i = 0; i < 26; i++) {
        if (countArray[i] != 0) {
            char alphabet = char(i + lowerCaseA);
            cout << alphabet << "\t" << countArray[i] << endl;
        }
    }
}
