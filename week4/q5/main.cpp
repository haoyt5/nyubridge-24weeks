#include <iostream>

using namespace std;

int main() {
    int input;
    cout << "Please enter a positive integer n : ";
    cin >> input;

    for (int i = 0; i < 2 * input; i++) {
        if (i < input) {
            int spaceLength = i;
            int starLength = 2 * (input - 1 - i) + 1;
            string hourglassTop;
            for (int n = 0; n < spaceLength; n++) {
                hourglassTop += " ";
            }
            for (int n = 0; n < starLength; n++) {
                hourglassTop += "*";
            }
            cout << hourglassTop << endl;
        } else {
            int spaceLength = input * 2 - (1 + i);
            int starLength = 2 * (i % input) + 1;
            string hourglassBottom;
            for (int n = 0; n < spaceLength; n++) {
                hourglassBottom += " ";
            }
            for (int n = 0; n < starLength; n++) {
                hourglassBottom += "*";
            }
            cout << hourglassBottom << endl;
        }
    }
    return 0;
}
