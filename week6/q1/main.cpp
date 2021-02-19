#include <iostream>

using namespace std;

const int ORDINAL_ZERO = 0;
const int ORDINAL_FIRST_AND_SECOND = 1;


int fibonacci(int length, int theLast, int oneBeforeTheLast);

int main() {
    int ordinal;
    int ordinalElement;
    cout << "Please input a positive integer: ";
    cin >> ordinal;

    if (ordinal > 2) {
        ordinalElement = fibonacci(ordinal, ORDINAL_FIRST_AND_SECOND, ORDINAL_FIRST_AND_SECOND);
        cout << ordinalElement << endl;
        return 0;
    }
    if (ordinal < 3 && ordinal > 0) {
        cout << ORDINAL_FIRST_AND_SECOND << endl;
        return 0;
    }
    if (ordinal == 0) {
        cout << ORDINAL_ZERO << endl;
        return 0;
    }

    return 0;
}

int fibonacci(int length, int theLast, int oneBeforeTheLast) {
    int sum;
    int updateTheLast = theLast;
    int updateOneBeforeTheLast = oneBeforeTheLast;
    for (int n = 0; n < length - 2; n++) {
        sum = updateTheLast + updateOneBeforeTheLast;
        updateOneBeforeTheLast = updateTheLast;
        updateTheLast = sum;
    }
    return sum;
}
