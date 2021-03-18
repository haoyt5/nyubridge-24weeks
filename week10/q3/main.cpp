#include <iostream>

#include <vector>

using namespace std;

//int main1();

int main2();

void readIndexInVector(vector<int> inputArray, int searchValue);

int main() {
//    main1();
    main2();
    return 0;
}

//int main1() {
//    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
//    cout << "End you input by typing -1." << endl;
//
//    int searchValue;
//    cout << "Please enter a number you want to search." << endl;
//    cin >> searchValue;
//    cout << searchValue << " shows in lines ";
//    cout << endl;
//    return 0;
//}

int main2() {
    vector<int> inputArray;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    int currentInput = 0;
    while (currentInput != -1) {
        cin >> currentInput;
        inputArray.push_back(currentInput);
    }

    int searchValue;
    cout << "Please enter a number you want to search." << endl;
    cin >> searchValue;
    cout << searchValue << " shows in lines ";
    readIndexInVector(inputArray, searchValue);

    return 0;
}


void readIndexInVector(vector<int> inputArray, int searchValue) {
    int lineIndex = 0;
    for (int i = 0; i < inputArray.size(); i++) {
        if (inputArray[i] == searchValue) {
            lineIndex == 0 && cout << i + 1;
            lineIndex > 0 && cout << ", " << i + 1;
            lineIndex++;
        }
    }
    cout << "." << endl;
}