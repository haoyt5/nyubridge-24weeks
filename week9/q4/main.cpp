#include <iostream>
#include <vector>

using namespace std;

void printArray(int arr[], int arrSize);

void oddsKeepEvensFlip(int arr[], int arrSize);

bool isOdd(int num);

int main() {
    int arr[6] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;
    printArray(arr, arrSize);
    oddsKeepEvensFlip(arr, arrSize);
    printArray(arr, arrSize);
    return 0;
}

void printArray(int arr[], int arrSize) {
    int i;
    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    vector<int> evenHalf;
    int oddStartIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        int currentValue = arr[i];
        if (isOdd(currentValue)) {
            arr[oddStartIndex] = currentValue;
            oddStartIndex++;
        } else {
            evenHalf.push_back(currentValue);
        }
    }
    for (int i = 0; i < arrSize / 2; i++) {
        int evenStartIndex = arrSize - 1;
        arr[evenStartIndex - i] = evenHalf[i];
    }
}

bool isOdd(int num) {
    int isOdd = false;
    if (num % 2 == 1) {
        isOdd = true;
    }
    return isOdd;
}
