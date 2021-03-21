#include <iostream>

using namespace std;

void printTriangle(int n);

void printOpositeTriangles(int n);

void printRuler(int n);

int main() {
    const int number = 4;

    cout << "a. print Triangle" << endl;
    printTriangle(number);

    cout << "\nb. print Opposite Triangles" << endl;
    printOpositeTriangles(number);

    cout << "\nc. print Ruler" << endl;
    printRuler(number);

    return 0;
}

void printTriangle(int n) {
    if (n == 0) {
        return;
    }
    printTriangle(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printOpositeTriangles(int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
    printOpositeTriangles(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printRuler(int n) {
    if (n == 0) {
        return;
    }
    printRuler(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
    printRuler(n - 1);
}