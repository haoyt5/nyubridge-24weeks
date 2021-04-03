#include <iostream>

#include <vector>

using namespace std;

int main1();

int main2();

void readIndexInVector(vector<int> inputArray, int searchValue);

void readIndexInDynamicArray(const int *inputArray, int inputArraySize, int searchValue);

void resizeArray(int *&arr, int currentSize, int newSize);

int main() {
    main1();
    main2();
    return 0;
}

void resizeArray(int *&arr, int currentSize, int newSize) {
    int *temp = new int[newSize];
    for (int i = 0; i < currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}


int main1() {
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    int size = 1;
    int *inputArray = new int[size];
    int currentInput = 0;
    while (currentInput != -1) {
        cin >> currentInput;
        inputArray[size - 1] = currentInput;
        resizeArray(inputArray, size, size * 2);
        size++;
    }
    int searchValue;
    cout << "Please enter a number you want to search." << endl;
    cin >> searchValue;
    cout << searchValue << " shows in lines ";
    readIndexInDynamicArray(inputArray, size, searchValue);
    cout << endl;
    delete[] inputArray;
    return 0;
}

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

void readIndexInDynamicArray(const int *inputArray, int inputArraySize, int searchValue) {
    int lineIndex = 0;
    for (int i = 0; i < inputArraySize; i++) {
        if (inputArray[i] == searchValue) {
            lineIndex == 0 && cout << i + 1;
            lineIndex > 0 && cout << ", " << i + 1;
            lineIndex++;
        }
    }
    cout << "." << endl;
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
