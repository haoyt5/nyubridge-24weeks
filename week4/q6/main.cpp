#include <iostream>

#include <cmath>

using namespace std;

int main() {

    int input;
    cout << "Please input a positive integer n: ";

    cin >> input;
    for (int i = 1; i <= input; i++) {
        int evenDigitCount = 0;
        int oddDigitCount = 0;
        for (int d = 0; pow(10, d) < input; d++) {
            int digitValue = (int) (i / pow(10, d));
            int remainder = digitValue % 2;
            if (remainder == 0) {
                evenDigitCount += 1;
            } else {
                oddDigitCount += 1;
            }
        }
        if (evenDigitCount > oddDigitCount) {
            cout << i << endl;
        }
    }

    return 0;
}
