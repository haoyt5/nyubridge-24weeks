#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize);

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);

void getPosNums3(int *arr, int arrSize,
                 int *&outPosArr, int &outPosArrSize);

void getPosNums4(int *arr, int arrSize,
                 int **outPosArrPtr, int *outPosArrSizePtr);

int main() {
    int arr[10] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;
    int arrPosArrSize;


    cout << "a) getPosNums1 " << endl;
    printArray(arr, arrSize);

    int *posArr1 = getPosNums1(arr, arrSize, arrPosArrSize);
    cout << "new size: " << arrPosArrSize << endl;
    printArray(posArr1, arrPosArrSize);
    cout << endl;


    cout << "b) getPosNums2" << endl;
    printArray(arr, arrSize);

    int *posArr2 = getPosNums2(arr, arrSize, &arrPosArrSize);
    cout << "new size: " << arrPosArrSize << endl;
    printArray(posArr2, arrPosArrSize);
    cout << endl;


    cout << "c) getPosNums3" << endl;
    printArray(arr, arrSize);

    int *outPosArr = nullptr;
    int outPosArrSize;
    getPosNums3(arr, arrSize, outPosArr, outPosArrSize);
    cout << "new size: " << outPosArrSize << endl;
    printArray(outPosArr, outPosArrSize);
    cout << endl;

    cout << "d) getPosNums4" << endl;
    printArray(arr, arrSize);

    int *outPosArrPtr = nullptr;
    int outPosArrSizePtr;
    getPosNums4(arr, arrSize, &outPosArrPtr, &outPosArrSizePtr);
    cout << "new size: " << outPosArrSizePtr << endl;
    printArray(outPosArrPtr, outPosArrSizePtr);
    cout << endl;
    return 0;
}

void printArray(int arr[], int arrSize) {
    int i;
    cout << "[";
    for (i = 0; i < arrSize; i++) {
        cout << arr[i];
        if (i != arrSize - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize) {
    int posArrSize = 0;
    int *posArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArray[posArrSize] = arr[i];
            posArrSize++;
        }
    }
    outPosArrSize = posArrSize;
    return posArray;
}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr) {
    int *posArray = new int[*outPosArrSizePtr];
    int posLength = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArray[posLength] = arr[i];
            posLength++;
        }
    }
    return posArray;
}

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize) {
    int *posArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArray[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }
    outPosArr = posArray;
}

void getPosNums4(int *arr, int arrSize,
                 int **outPosArrPtr, int *outPosArrSizePtr) {
    *outPosArrPtr = new int[*outPosArrSizePtr];
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[*outPosArrSizePtr] = arr[i];
            (*outPosArrSizePtr)++;
        }
    }
}