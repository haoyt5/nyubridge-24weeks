#include <iostream>

using namespace std;

const int INPUT_LENGTH = 20;

int minInArray(int arr[], int arrSize);

void printMatchInArray(const int *arr, int arrSize, int minimum);

int main() {
    int integerInputs[INPUT_LENGTH];

    cout << "Please enter " << INPUT_LENGTH << " integers separated by a space:" << endl;
    int minimumValue = minInArray(integerInputs, INPUT_LENGTH);

    cout << "The minimum value is " << minimumValue << ", and it is located in the following indices: ";
    printMatchInArray(integerInputs, INPUT_LENGTH, minimumValue);
    return 0;
}

int minInArray(int arr[], int arrSize) {
    cin >> arr[0];
    int minimum = arr[0];
    for (int i = 1; i < arrSize; i++) {
        cin >> arr[i];
        if (minimum >= arr[i]) {
            minimum = arr[i];
        }
    }
    return minimum;
}

void printMatchInArray(const int *arr, int arrSize, int minimum) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == minimum) {
            cout << i << " ";
        }
    }
    cout << endl;
}