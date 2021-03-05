#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int PIN_INDICES_LENGTH = 10;
const int PINS_LENGTH = 5;
const int ACTUAL_PINS_INDEX_ARRAY[PINS_LENGTH] = {1, 2, 3, 4, 5};
const int ZERO_ASCII = 48;

void pinAuthenticate();

void fillInputPinArray(int a[], int pinDigit, string inputPinNumber);

bool isCorrectPin(const int inputPinArray[], const int randomNumberArray[]);

int main() {
    pinAuthenticate();
    cout << endl;
    pinAuthenticate();
    return 0;
}

void pinAuthenticate() {
    srand(time(nullptr));
    int randomNumber[PIN_INDICES_LENGTH];
    string inputPin;
    int formatPinInArray[PINS_LENGTH];
    cout << "Please enter your PIN according to the following mapping:" << endl;

    cout << "PIN:\t";
    for (int i = 0; i < PIN_INDICES_LENGTH; i++) {
        cout << i << " ";
        randomNumber[i] = (rand() % 3) + 1;
    }
    cout << endl;

    cout << "NUM:\t";
    for (int i : randomNumber) {
        cout << i << " ";
    }
    cout << endl;

    cin >> inputPin;
    cout << "Your PIN is ";
    fillInputPinArray(formatPinInArray, PINS_LENGTH, inputPin);
    if (!isCorrectPin(formatPinInArray, randomNumber)) {
        cout << "not ";
    }
    cout << "correct" << endl;
}

bool isCorrectPin(const int inputPinArray[], const int randomNumberArray[]) {
    bool result = true;
    for (int i = 0; i < PINS_LENGTH; i++) {
        int indexInRandomArray = ACTUAL_PINS_INDEX_ARRAY[i];
        if (inputPinArray[i] != randomNumberArray[indexInRandomArray]) {
            result = false;
        }
    }
    return result;
}

void fillInputPinArray(int a[], int pinDigit, string inputPinNumber) {
    char zero = ZERO_ASCII;
    for (int index = 0; index < pinDigit; index++) {
        a[index] = inputPinNumber[index] - ZERO_ASCII;
    }
    if (inputPinNumber[0] == zero) {
        a[0] = 4;
    }
}
