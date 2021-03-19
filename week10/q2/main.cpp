#include <iostream>

using namespace std;

int *findMissing(const int arr[], int n, int &resArrSize);

void readArray(int *arr, int arraySize);

int main() {
    int arr[] = {3, 1, 3, 0, 6, 4};
    int arrSize = 6;
    int resArrSize = 0;
    int *missingArr;

    missingArr = findMissing(arr, arrSize, resArrSize);
    readArray(missingArr, resArrSize);
    delete[]  missingArr;
    return 0;
}

int *findMissing(const int arr[], int n, int &resArrSize) {
    int *numberArray;
    numberArray = new int[n];
    for (int i = 0; i < n; i++) {
        numberArray[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int numberIndex = arr[i];
        numberArray[numberIndex] = 1;
    }


    int *missingNumberArr;
    resArrSize = 0;
    missingNumberArr = new int[resArrSize];

    for (int i = 0; i < n; i++) {
        if (numberArray[i] != 1) {
            resArrSize++;
            missingNumberArr[resArrSize - 1] = i;
        }
    }
    delete[] numberArray;
    return missingNumberArr;

}

void readArray(int *arr, int arraySize) {
    cout << "resArrSize: " << arraySize << endl;
    cout << " [";
    for (int i = 0; i < arraySize; i++) {
        i == 0 && cout << arr[i] << " ";
        i != 0 && cout << ", " << arr[i];
    }
    cout << "]";
}