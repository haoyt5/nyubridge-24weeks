#include <iostream>


using namespace std;

class Money;

class Check;

class Money {
public:
    friend Money operator+(const Money &amount1, const Money &amount2);

    friend Money operator-(const Money &amount1, const Money &amount2);

    friend Money operator-(const Money &amount);

    friend bool operator==(const Money &amount1, const Money &amount2);

    friend bool operator<(const Money &amount1, const Money &amount2);

    Money(long dollars, int cents);

    Money(long dollars);

    Money();

    double getValue() const;

    friend istream &operator>>(istream &ins, Money &amount);

    friend ostream &operator<<(ostream &outs, Money &amount);

private:
    long allCents;
};

class Check {
public:

    Check(int checkNumber, Money checkAmount, bool haveCashed);

    Check();

    int getCheckNumber() const;

    Money getCheckAmount() const;

    bool getHaveCashed() const;

    void setCheckNumber(int inputNumber);

    void setCheckAmount(Money inputAmount);

    void setHaveCashed(char inputCashedChar);

private:
    int checkNumber;
    Money checkAmount;
    bool haveCashed;
};

int digitToInt(char c);

void resizeArray(Money *&arr, int currentSize, int newSize);

int main() {
    Money oldAmount;
    Money newAmount;
    int numberOfDeposit;

    cout << "Please enter your existing(old) bank balance ($##.##): ";
    cin >> oldAmount;

    cout << "Please enter your new bank balance ($##.##): ";
    cin >> newAmount;

    cout << "Please enter how many deposits you have (#): ";
    cin >> numberOfDeposit;

    int resArrSize = 1;
    Money *depositArr = new Money[resArrSize];

    cout << "Please enter deposit ($##.##) one per line: " << endl;


    for (int i = 0; i < numberOfDeposit; i++) {
        Money depositAmount;
        cin >> depositAmount;
        depositArr[resArrSize - 1] = depositAmount;
        resizeArray(depositArr, resArrSize, resArrSize * 2);
        resArrSize++;
    }


    int numberOfCheck;
    resArrSize = 1;
    Check *checkArr = new Check[resArrSize];

    cout << endl;
    cout << "Please enter how many checks you have for processing (#): ";
    cin >> numberOfCheck;
    cout << "*The format of the check input per line is (# $##.## #), each unit separate by a space, " << endl;
    cout << "\t- The first unit is the check number (#)," << endl;
    cout << "\t- The second unit is the check amount ($##.##)," << endl;
    cout << "\t- The third unit is whether checked or not, 0 if not chased, 1 if cashed (#)," << endl;
    cout << "Please enter checks (# $##.## #) one per line:" << endl;

    for (int i = 0; i < numberOfCheck; i++) {
        Check checkItem;
        int checkNumber;
        Money checkAmount;
        char checkHaveCashed;
        cin >> checkNumber >> checkAmount >> checkHaveCashed;

        checkItem.setCheckNumber(checkNumber);
        checkItem.setCheckAmount(checkAmount);
        checkItem.setHaveCashed(checkHaveCashed);

        checkArr[resArrSize - 1] = checkItem;
        resizeArray(depositArr, resArrSize, resArrSize * 2);
        resArrSize++;
    }


    return 0;
}

int digitToInt(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}

void resizeArray(Money *&arr, int currentSize, int newSize) {
    Money *temp = new Money[newSize];
    for (int i = 0; i < currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Illegal values for dollars and cents" << endl;
        exit(1);
    }
    allCents = dollars * 100 + cents;
}

Money::Money(long dollars) : allCents(dollars * 100) {

}

Money::Money() : allCents(0) {

}

double Money::getValue() const {
    return (allCents * 0.01);
}

Money operator+(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

Money operator-(const Money &amount1, const Money &amount2) {
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}

Money operator-(const Money &amount) {
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2) {
    return (amount1.allCents == amount2.allCents);
}

bool operator<(const Money &amount1, const Money &amount2) {
    return (amount1.allCents < amount2.allCents);
}

istream &operator>>(istream &ins, Money &amount) {
    char prefixChar;
    char decimalPoint;
    char digit1;
    char digit2;
    long dollars;
    int cents;
    bool isNegative = false;
    ins >> prefixChar;

    if (prefixChar == '-') {
        isNegative = true;
        ins >> prefixChar;
    }

    ins >> dollars >> decimalPoint >> digit1 >> digit2;
    if (prefixChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Illegal values for dollars and cents" << endl;
        exit(1);
    }

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
    amount.allCents = dollars * 100 + cents;
    if (isNegative) {
        amount.allCents = -amount.allCents;
    }
    return ins;

}

ostream &operator<<(ostream &outs, Money &amount) {
    long positiveCents;
    long dollars;
    long cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;
    if (amount.allCents < 0) {
        outs << "-$" << dollars << '.';
    } else {
        outs << "$" << dollars << '.';
    }
    if (cents < 10) {
        outs << '0';
    }
    outs << cents;
    return outs;
}


Check::Check(int id, Money amount, bool cashed) : checkNumber(id), checkAmount(amount), haveCashed(cashed) {

}

Check::Check() : checkNumber(), checkAmount(), haveCashed() {

}

int Check::getCheckNumber() const {
    return (checkNumber);
}

Money Check::getCheckAmount() const {
    return (checkAmount);
}

bool Check::getHaveCashed() const {
    return (haveCashed);
}

void Check::setCheckNumber(int inputNumber) {
    checkNumber = inputNumber;
}

void Check::setCheckAmount(Money inputAmount) {
    checkAmount = inputAmount;
}

void Check::setHaveCashed(char inputCashedChar) {
    char one = '1';
    char zero = '0';

    if (inputCashedChar == one) {
        haveCashed = true;
    } else if (inputCashedChar == zero) {
        haveCashed = false;
    } else {

        cout << "Illegal values for whether checked" << endl;
        exit(1);

    }


}