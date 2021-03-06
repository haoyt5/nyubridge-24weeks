#include <iostream>

using namespace std;

bool isPalindrome(string str);

int main() {
    string input;
    cout << "Please enter a word: ";
    cin >> input;
    cout << input << " is";
    if (!isPalindrome(input)) {
        cout << " not";
    }
    cout << " a palindrome";

    return 0;
}

bool isPalindrome(string str) {
    bool result = true;
    int i;
    int halfLength = (int) str.length() / 2;
    int endIndex = (int) str.length() - 1;
    for (i = 0; i < halfLength; i++) {
        if (str[i] != str[endIndex - i]) {
            result = false;
        }
    }
    return result;
}