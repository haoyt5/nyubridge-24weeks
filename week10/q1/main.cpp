#include <iostream>

using namespace std;


string *createWordsArray(const string &sentence, int &outWordsArrSize);

void readArray(string *arr, int arraySize);

bool isSplitBySpace(const string &sentence);

bool isAlphabet(char input);

int main() {
    const string SENTENCE = "You can do it";

    int outWordsArrSize = 0;
    string *wordsArray;

    wordsArray = createWordsArray(SENTENCE, outWordsArrSize);

    readArray(wordsArray, outWordsArrSize);

    delete[]wordsArray;

    return 0;
}

string *createWordsArray(const string &sentence, int &outWordsArrSize) {

    auto *dynamicArray = new string[outWordsArrSize];

    if (isSplitBySpace(sentence)) {
        int wordLength = sentence.find(' ');
        string restSentence = sentence;
        int nextWordStartIndex = 0;

        while (wordLength != -1 && isAlphabet(restSentence[0])) {
            if (outWordsArrSize == 0) {
                outWordsArrSize = 1;
            } else {
                outWordsArrSize++;
            }

            dynamicArray[outWordsArrSize - 1] = restSentence.substr(0, wordLength);

            nextWordStartIndex = nextWordStartIndex + wordLength + 1;
            restSentence = sentence.substr(nextWordStartIndex, sentence.length() - nextWordStartIndex);
            wordLength = restSentence.find(' ');
            if (wordLength == -1 && isAlphabet(restSentence[0])) {
                outWordsArrSize++;
                dynamicArray[outWordsArrSize - 1] = restSentence;
            }
        }


    } else {
        dynamicArray[0] = sentence;
    }
    return dynamicArray;
}

void readArray(string *arr, int arraySize) {
    cout << "outWordsArrSize: " << arraySize << endl;
    cout << " [";
    for (int i = 0; i < arraySize; i++) {
        i == 0 && cout << " '" << arr[i] << "' ";
        i != 0 && cout << ", '" << arr[i] << "' ";
    }
    cout << "]";
}

bool isSplitBySpace(const string &sentence) {
    bool isSplit = false;
    if (sentence.find(' ')) {
        isSplit = true;
    }
    return isSplit;
}

bool isAlphabet(char input) {
    bool isAlphabet = false;
    if (input >= 'a' && input <= 'z') {
        isAlphabet = true;
    }
    if (input >= 'A' && input <= 'Z') {
        isAlphabet = true;
    }
    return isAlphabet;
}