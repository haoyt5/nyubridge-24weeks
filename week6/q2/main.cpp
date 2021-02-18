#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main() {
    int numberOfTree;
    char symbol;
    cout << "Please enter the number of triangles in the pine tree: " << endl;
    cin >> numberOfTree;
    cout << "Please enter the character filling the pine tree(eg. ‘*’ or ’+’ or ‘$’ etc): " << endl;
    cin >> symbol;
    printPineTree(numberOfTree, symbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int spaceLength = n;
    int symbolLength = 1;
    int triangleRow = 1 + (n - m);
    for (int row = 0; row < triangleRow; row++) {
        for (int spaceCount = 0; spaceCount < spaceLength; spaceCount++) {
            cout << " ";
        }
        for (int symbolCount = 0; symbolCount < symbolLength; symbolCount++) {
            cout << symbol;
        }
        cout << endl;
        spaceLength--;
        symbolLength = symbolLength + 2;
    }


}

void printPineTree(int n, char symbol) {
    int baseSpaceLength = n - 1;
    while (baseSpaceLength >= 0) {
        printShiftedTriangle(n, baseSpaceLength, symbol);
        baseSpaceLength--;
    }
}