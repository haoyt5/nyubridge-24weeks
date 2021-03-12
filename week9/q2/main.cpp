#include <iostream>

using namespace std;
const int upperCaseA = 'A';
const int upperCaseZ = 'Z';
const int lowerCaseA = 'a';
const int lowerCaseZ = 'z';

bool isAnagrams(const string &firstSentence, const string &secondSentence);

bool isAlphabet(char input);

char lowerCaseFormatter(char alphabet);

void countAlphabet(const string &sentence, int (&countArray)[26]);

bool compareCountArray(int (&firstCountArray)[26], int (&secondCountArray)[26]);


int main() {
    string firstSentence;
    string secondSentence;

    cout << "This program determines if two strings are anagrams" << endl;
    cout << "Please enter the first one: " << endl;
    getline(cin, firstSentence);
    cout << "Please enter the second one: " << endl;
    getline(cin, secondSentence);

    cout << "\"" << firstSentence << "\" is ";
    if (!isAnagrams(firstSentence, secondSentence)) {
        cout << "not ";
    }
    cout << "an anagram of \"" << secondSentence << "\"" << endl;

    return 0;
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


bool isAnagrams(const string &firstSentence, const string &secondSentence) {
    bool isAnagrams = false;
    int countFirstArray[26] = {0};
    int countSecondArray[26] = {0};

    countAlphabet(firstSentence, countFirstArray);
    countAlphabet(secondSentence, countSecondArray);

    if (compareCountArray(countFirstArray, countSecondArray)) {
        isAnagrams = true;
    }

    return isAnagrams;
}

void countAlphabet(const string &sentence, int (&countArray)[26]) {
    for (char i : sentence) {
        if (isAlphabet(i)) {
            char alphabet = lowerCaseFormatter(i);
            int index = alphabet - lowerCaseA;
            if (!countArray[index]) {
                countArray[index] = 1;
            } else {
                countArray[index]++;
            }
        }
    }
}

bool compareCountArray(int (&firstCountArray)[26], int (&secondCountArray)[26]) {
    bool isSame = true;
    for (int i = 0; i < 26; i++) {
        if (firstCountArray[i] != secondCountArray[i]) {
            isSame = false;
        }
    }
    return isSame;
}