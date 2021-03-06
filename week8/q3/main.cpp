
#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize);

void reverseArray(int arr[], int arrSize);

void removeOdd(int arr[], int &arrSize);

void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        int lastIndex = arrSize - 1;
        int initValue = arr[i];
        int swapValue = arr[lastIndex - i];
        arr[i] = swapValue;
        arr[lastIndex - i] = initValue;
    }
}

void removeOdd(int arr[], int &arrSize) {
    int evenIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentValue = arr[i];
        if (currentValue % 2 == 0) {
            arr[evenIndex] = currentValue;
            evenIndex++;
        }
    }
    arrSize = evenIndex;
}

void splitParity(int arr[], int arrSize) {
    int evenIndex = (arrSize / 2) + 1;
    for (int i = 0; i < arrSize / 2; i++) {
        int firstHalf = arr[i];
        int secondHalf = arr[evenIndex];
        if (firstHalf % 2 == 0) {
            arr[evenIndex] = firstHalf;
            if (secondHalf % 2 == 1) {
                arr[i] = secondHalf;
            }
            evenIndex++;
        }
    }
}