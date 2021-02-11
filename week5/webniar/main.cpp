#include <iostream>

using namespace std;

int main() {
    char inputLetter;
    char currentLetter = 97;

    cout << "Please enter a lower case letter:" << endl;
    cin >> inputLetter;

    int length = (inputLetter - 'a') + 1;
    int spaceLength = (inputLetter - 'a');
    for (int lineCount = 1; lineCount <= length; lineCount++) {
        for (int n = spaceLength; n > 0 ; n--){
            cout << "\t" ;
        }
        spaceLength--;
        for (int i = 0; i < lineCount; i++) {
            cout << char (currentLetter + i) << "\t";
        }
        cout << endl;
    }
    return 0;
}
