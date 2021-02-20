#include <iostream>

using namespace std;

void printDivisors(int num);

int main() {
    int inputNumber;
    cout << "Please enter a positive integer >=2: ";
    cin >> inputNumber;
    if(inputNumber < 2){
        cout << "Input invalid" << endl;
        return 0;
    }
    printDivisors(inputNumber);
    return 0;
}

void printDivisors(int num) {
    int pairDivisor = num;
    for (int divisor = 1; divisor * divisor <= num; divisor++) {
        if (num % divisor == 0 && pairDivisor >= divisor) {
            pairDivisor = num / divisor;
            cout << divisor << " ";

        }
    }

    while (pairDivisor * pairDivisor > 0) {
        int divisor = num / pairDivisor;
        if (num % pairDivisor == 0 && divisor > pairDivisor) {
            cout << divisor << " ";
        }
        pairDivisor--;
    }
    cout << endl;
}

