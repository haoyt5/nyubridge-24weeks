#include <iostream>

using namespace std;

void readArray(int arr[], int arrSize);

int visitCost(int arr[], int arrSize);

int main() {
    int arr[6] = {0, 3, 80, 6, 57, 10};
    int arrSize = 6;

    cout << "The sample game board where n is " << arrSize << ": " << endl;
    readArray(arr, arrSize);
    int lowestCost = visitCost(arr, arrSize);
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

int visitCost(int arr[], int arrSize) {
    int visitedIndex = arrSize - 1;
    if (arrSize <= 3) {
        return arr[visitedIndex];
    } else {
        int costMove = visitCost(arr, arrSize - 1);
        int costJump = visitCost(arr, arrSize - 2);
        if (costMove < costJump) {
            return arr[visitedIndex] + costMove;
        } else {
            return arr[visitedIndex] + costJump;
        }
    }
}