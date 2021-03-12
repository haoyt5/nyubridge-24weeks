#include <iostream>

using namespace std;

int main() {
    string firstSentence;
    string secondSentence;
    
    cout << "This program determines if two strings are anagrams" << endl;
    cout << "Please enter the first one: " << endl;
    getline(cin, firstSentence);
    cout << "Please enter the second one: " << endl;
    getline(cin, secondSentence);
    cout << "\"" << firstSentence << "\" is ";

    cout << "an anagram of \"" << secondSentence << "\"" << endl;
    return 0;
}
