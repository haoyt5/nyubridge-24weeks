#include <iostream>

using namespace std;

int main() {
    int input;
    cout << "Please enter a positive integer: " << endl;
    cin >> input;
    for (int i = 1; i <= input; i++) {
        for (int n = 0; n < input; n++) {
            cout << i + n * i << "\t";
        }
        cout << endl;
    }
    return 0;
}
