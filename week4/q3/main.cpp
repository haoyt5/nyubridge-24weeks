#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int input;
    cout << "Enter decimal number:" << endl;
    cin >> input;

    int result = 0;
    int length = 1 + (int) sqrt(input);
    for (int i = 0; i < length; i++) {
        int remainder = int(input / pow(2, i)) % 2;
        result = result + (int) pow(10, i) * remainder;
    }

    cout << "The binary representation of " << input << " is " << result << endl;
    return 0;

}
