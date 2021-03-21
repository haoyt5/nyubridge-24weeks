#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);

bool isSorted(int arr[], int arrSize);

void readArray(int arr[], int arrSize);

int main() {
    int array[4] = {2, -1, 3, 10};
    int arraySize = 4;
    cout << "Array: [";
    readArray(array, arraySize);
    cout << "]" << endl;
    cout << "a. sumOfSquares:" << endl;
    int result = sumOfSquares(array, arraySize);
    cout << result << endl;
    cout << "b. isSorted:" << endl;
    bool isSort = isSorted(array, arraySize);
    cout << std::boolalpha << isSort << endl;

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

int sumOfSquares(int arr[], int arrSize) {
    int square;
    int result;
    if (arrSize == 1) {
        square = arr[0] * arr[0];
        result = square;
        return result;
    } else {
        square = arr[arrSize - 1] * arr[arrSize - 1];
        result = square + sumOfSquares(arr, arrSize - 1);
        return result;
    }
}

bool isSorted(int arr[], int arrSize) {
    bool isSort = false;
    if (arrSize == 1) {
        isSort = true;
        return isSort;
    } else {
        if (arr[arrSize - 2] < arr[arrSize - 1]) {
            isSort = true;
        }
        isSort = isSort && isSorted(arr, arrSize - 1);
        return isSort;
    }

}