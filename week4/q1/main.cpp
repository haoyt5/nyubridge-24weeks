#include <iostream>

using namespace std;

int main() {
    int input;

    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    cin >> input;

    int index = 1;
    while (input > 0) {
        cout << index * 2 << endl;
        index = index + 1;
        input = input - 1;
    }

    cout << "section b" << endl;
    cout << "Please enter a positive integer: ";
    cin >> input;

    for (int n = 1; n <= input; n++) {
        cout << n * 2 << endl;
    }

    return 0;
}