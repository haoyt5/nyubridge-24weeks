#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr);

void printArray(const vector<int> &arr);

int main() {
    vector<int> arr = {4, 9, 2, 6, 1, 3};
    cout << "Output of the origin vector array: ";
    printArray(arr);
    cout << "Output after the insertion sort: ";
    insertionSort(arr);
    printArray(arr);
    return 0;
}


void insertionSort(vector<int> &arr) {
    int key;
    int h;
    for (int i = 1; i < arr.size(); i++) {
        key = arr[i];
        h = i-1;
        while (h >= 0 && key < arr[h]) {
            arr[h+1] = arr[h];
            h = h-1;
        }
        arr[h + 1] = key;
    }
}

void printArray(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
