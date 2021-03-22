#include <iostream>

using namespace std;

void readArray(int arr[], int arrSize);

int lowestCostOfJumpIt(int arr[], int arrSize);

int main() {
    int arr[6] = {0, 3, 80, 6, 57, 10};
    int arrSize = 6;

    cout << "The sample game board where n is " << arrSize << ": " << endl;
    readArray(arr, arrSize);
    int lowestCost = lowestCostOfJumpIt(arr, arrSize);
    cout << "\nThe lowest cost of the sequence is: " << lowestCost << endl;
    return 0;
}

void readArray(int arr[], int arrSize) {
    if (arrSize == 1) {
        cout << arr[0];
    } else {
        readArray(arr, arrSize - 1);
        cout << ", " << arr[arrSize - 1];
    }
}

int lowestCostOfJumpIt(int arr[], int arrSize) {
    int jumpIndex = arrSize - 1;
    if (arrSize <= 1) {
        return 0;
    } else {
        int cheaper = arr[jumpIndex];
        if (arr[jumpIndex - 1] < cheaper) {
            jumpIndex--;
            cheaper = arr[jumpIndex];
        }
        return cheaper + lowestCostOfJumpIt(arr, jumpIndex);
    }
}