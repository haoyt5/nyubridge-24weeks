#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << fixed;
    cout.precision(4);
    cout << "section a" << endl;
    int sequenceLength;
    cout << "Please enter the length of the sequence: ";
    cin >> sequenceLength;

    cout << "Please enter your sequence:" << endl;
    int product = 1;
    for (int i = 0; i < sequenceLength; i++) {
        int input;
        cin >> input;
        product = product * input;
    }
    double exponent = (double) 1 / sequenceLength;
    double geometricMean = pow(product, exponent);

    cout << "The geometric mean is: " << geometricMean << endl;

    cout << "" << endl;
    cout << "section b" << endl;
    int continueInput = 1;
    cout
            << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:"
            << endl;
    sequenceLength = 0;
    product = 1;
    while (continueInput != -1) {
        cin >> continueInput;
        if (continueInput == -1) {
            break;
        }
        product = product * continueInput;
        sequenceLength = sequenceLength + 1;
    }
    exponent = (double) 1 / sequenceLength;
    geometricMean = pow(product, exponent);

    cout << "The geometric mean is: " << geometricMean << endl;
    return 0;
}
