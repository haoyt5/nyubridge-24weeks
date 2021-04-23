#include <iostream>
#include <vector>

using namespace std;

vector<int> getMinAndMax(const vector<int> &items, int start, int end);

void readItems(const vector<int> &items);

int main() {
    vector<int> arr = {11, 8, 9, 2, 11, 77, 99};
    cout << "Input: ";
    readItems(arr);
    int end = (int) arr.size() - 1;
    if (end < 0) {
        cout << "Invalid Input" << endl;
        exit(1);
    }
    vector<int> result = getMinAndMax(arr, 0, end);
    cout << "Output: ";
    readItems(result);
    cout << "The min is: " << result[0] << endl;
    cout << "The max is: " << result[1] << endl;
    return 0;
}

vector<int> getMinAndMax(const vector<int> &items, int start, int end) {
    if (end - start + 1 == 1) {
        return {items[start], items[start]};
    }
    if (end - start + 1 == 2) {
        if (items[start] > items[end]) {
            return {items[end], items[start]};
        } else {
            return {items[start], items[end]};
        }
    }
    int mid = start + (end - start) / 2;
    vector<int> firstHalf;
    vector<int> secondHalf;
    int min;
    int max;
    firstHalf = getMinAndMax(items, start, mid);
    secondHalf = getMinAndMax(items, mid + 1, end);
    if (firstHalf[0] < secondHalf[0]) {
        min = firstHalf[0];
    } else {
        min = secondHalf[0];
    }
    if (firstHalf[1] > secondHalf[1]) {
        max = firstHalf[1];
    } else {
        max = secondHalf[1];
    }
    return {min, max};

}

void readItems(const vector<int> &items) {
    for (int item : items) {
        cout << item << " ";
    }
    cout << endl;
}