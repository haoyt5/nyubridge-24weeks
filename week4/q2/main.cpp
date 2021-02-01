#include <iostream>

using namespace std;

const int digitM = 1000;
const int digitD = 500;
const int digitC = 100;
const int digitL = 50;
const int digitX = 10;
const int digitV = 5;
const int digitI = 1;

int main() {
    int decimalInput;
    string romanDigit;

    cout << "Enter decimal number:" << endl;
    cin >> decimalInput;

    int digitMLength = 0;
    int digitMQuotient = decimalInput / digitM;
    for (int i = 0; i < digitMQuotient; i++) {
        romanDigit += "M";
        digitMLength = digitMLength + 1;
    }

    int digitDLength = 0;
    int digitDQuotient = (decimalInput - digitMLength * digitM) / digitD;
    for (int i = 0; i < digitDQuotient && i < 1; i++) {
        romanDigit += "D";
        digitDLength = digitDLength + 1;
    }

    int digitCLength = 0;
    int digitCQuotient = (decimalInput - digitMLength * digitM - digitDLength * digitD) / digitC;
    for (int i = 0; i < digitCQuotient && i < 4; i++) {
        romanDigit += "C";
        digitCLength = digitCLength + 1;
    }

    int digitLLength = 0;
    int digitLQuotient =
            (decimalInput - digitMLength * digitM - digitDLength * digitD - digitCLength * digitC) / digitL;
    for (int i = 0; i < digitLQuotient && i < 1; i++) {
        romanDigit += "L";
        digitLLength = digitLLength + 1;
    }

    int digitXLength = 0;
    int digitXQuotient = (decimalInput - digitMLength * digitM - digitDLength * digitD - digitCLength * digitC -
                          digitLLength * digitL) / digitX;
    for (int i = 0; i < digitXQuotient && i < 4; i++) {
        romanDigit += "X";
        digitXLength = digitXLength + 1;
    }

    int digitVLength = 0;
    int digitVQuotient = (decimalInput - digitMLength * digitM - digitDLength * digitD - digitCLength * digitC -
                          digitLLength * digitL - digitXLength * digitX) / digitV;
    for (int i = 0; i < digitVQuotient && i < 1; i++) {
        romanDigit += "V";
        digitVLength = digitVLength + 1;
    }

    int digitILength = 0;
    int digitIQuotient = (decimalInput - digitMLength * digitM - digitDLength * digitD - digitCLength * digitC -
                          digitLLength * digitL - digitXLength * digitX - digitVLength * digitV) / digitI;
    for (int i = 0; i < digitIQuotient && i < 4; i++) {
        romanDigit += "I";
        digitILength = digitILength + 1;
    }

    cout << decimalInput << " is " << romanDigit << endl;
    return 0;
}
