#include <iostream>

using namespace std;

void countWords(string sentence, int &wordCount);

int main() {
    int wordCounts = 0;
    string sentence;
    cout << "Please enter a line of text: " << endl;
//    cout << "I say Hi." << endl;
    getline(cin, sentence);
    countWords(sentence, wordCounts);
    cout << wordCounts << "\t word";
    if (wordCounts != 1) {
        cout << "s" << endl;
    }
    return 0;
}

void countWords(string sentence, int &wordCount) {
    for (int i = 0; i < sentence.length(); i++) {
        if (i == 0) {
            wordCount++;
        }
        if (sentence[i] == ' ') {
            wordCount++;
        }
    }

}