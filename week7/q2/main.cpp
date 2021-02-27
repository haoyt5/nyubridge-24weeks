#include <iostream>

using namespace std;

void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs);

bool isPerfect(int num);

int main() {
    int input;
    cout << "Please enter a positive integer >=2: " << endl;
    cin >> input;
    if (input < 2) {
        cout << "Invalid Input" << endl;
        return 0;
    }
    cout << "All the perfect numbers between 2 and " << input << ":" << endl;
    for (int i = 2; i <= input; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "All pairs of amicable numbers that are between 2 and " << input << " (both numbers must be in the range): "
         << endl;
    int num = input;

    while (num > 1) {
        int outCountDivs = 0;
        int outSumDivs = 0;
        int amiableCountDivs = 0;
        if (!isPerfect(num)) {
            analyzeDivisors(num, outCountDivs, outSumDivs);
            if (outSumDivs <= input) {
                analyzeDivisors(outSumDivs, outCountDivs, amiableCountDivs);
                if (num == amiableCountDivs && num > outSumDivs) {
                    cout << "[ " << outSumDivs << " , " << num << " ] ";
                }
            }
        }
        num--;
    }
    cout << endl;

    return 0;
}


void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs) {
    int divisor = num;
    while (divisor * divisor >= num) {
        int pairDivisor = num / divisor;
        if (num % divisor == 0 && pairDivisor * divisor == num && pairDivisor <= divisor) {
            outSumDivs += (divisor + pairDivisor);
            outCountDivs += 2;
            if (divisor == num || divisor == pairDivisor) {
                outSumDivs -= divisor;
                outCountDivs--;
            }
        }
        divisor--;
    }
}

bool isPerfect(int num) {
    bool isPerfect = false;
    int outCountDivs = 0;
    int outSumDivs = 0;
    analyzeDivisors(num, outCountDivs, outSumDivs);
    if (num == outSumDivs) {
        isPerfect = true;
    }
    return isPerfect;
}