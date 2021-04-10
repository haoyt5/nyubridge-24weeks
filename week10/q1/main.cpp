#include <iostream>

using namespace std;


string *createWordsArray(const string &sentence, int &outWordsArrSize);

void readArray(string *arr, int arraySize);

bool isAlphabet(char input);

void resizeArray(string *&arr, int currentSize, int newSize);

int main() {
    const string SENTENCE = "You can do it";

    int outWordsArrSize = 0;
    string *wordsArray;

    wordsArray = createWordsArray(SENTENCE, outWordsArrSize);

    readArray(wordsArray, outWordsArrSize);
    delete[] wordsArray;
    return 0;
}

void resizeArray(string *&arr, int currentSize, int newSize) {
    string *temp = new string[newSize];
    for (int i = 0; i < currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

string *createWordsArray(const string &sentence, int &outWordsArrSize) {

    string *dynamicArray = new string[outWordsArrSize];

    int wordLength = sentence.find(' ');
    string restSentence = sentence;
    int nextWordStartIndex = 0;

    while (wordLength != -1 && isAlphabet(restSentence[0])) {
        if (outWordsArrSize == 0) {
            outWordsArrSize = 1;
            resizeArray(dynamicArray, outWordsArrSize, outWordsArrSize * 2);
        } else {
            outWordsArrSize++;
            resizeArray(dynamicArray, outWordsArrSize, outWordsArrSize * 2);
        }

        dynamicArray[outWordsArrSize - 1] = restSentence.substr(0, wordLength);

        nextWordStartIndex = nextWordStartIndex + wordLength + 1;
        restSentence = sentence.substr(nextWordStartIndex, sentence.length() - nextWordStartIndex);
        wordLength = restSentence.find(' ');
    }
    if (wordLength == -1 && isAlphabet(restSentence[0])) {
        outWordsArrSize++;
        dynamicArray[outWordsArrSize - 1] = restSentence;
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