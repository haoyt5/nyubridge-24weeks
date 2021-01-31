#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int input;
    cout << "Enter decimal number:" << endl;
    cin >> input;

    int result = 0;

    for (int i = 0; input / pow(2, i) >= 1; i++) {
        int remainder = int(input / pow(2, i)) % 2;
        cout << remainder<<endl;
        result = result + (int) pow(10, i) * remainder;
    }

    cout << "The binary representation of " << input << " is " << result << endl;
    return 0;

}
