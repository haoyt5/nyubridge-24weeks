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

void resizeMoneyArray(Money *&arr, int currentSize, int newSize);

void resizeCheckArray(Check *&arr, int currentSize, int newSize);

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
        resizeMoneyArray(depositArr, resArrSize, resArrSize * 2);
        resArrSize++;
    }


    int numberOfCheck;
    int checkResArrSize = 1;
    Check *checkArr = new Check[checkResArrSize];


    cout << endl;
    cout << "Please enter how many checks you have for processing (#): ";
    cin >> numberOfCheck;
    cout << "*The format of the check input per line is (# $##.## #), with space between the detail items " << endl;
    cout << "\t- The first position is the check number (#)," << endl;
    cout << "\t- The second position is the check amount ($##.##)," << endl;
    cout << "\t- The third position is whether checked or not, 0 if not chased, 1 if cashed (#)," << endl;
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

        checkArr[checkResArrSize - 1] = checkItem;
        resizeCheckArray(checkArr, checkResArrSize, checkResArrSize * 2);
        checkResArrSize++;
    }

    Money totalDepositValue;
    Money totalCashedCheckValue;

    for (int i = 0; i < numberOfDeposit; i++) {
        totalDepositValue = totalDepositValue + depositArr[i];
    }

    for (int i = 0; i < numberOfCheck; i++) {
        if (checkArr[i].getHaveCashed()) {
            totalCashedCheckValue = totalCashedCheckValue + checkArr[i].getCheckAmount();
        }
    }
    cout << endl;

    cout << "The total value of the deposits you made is: " << totalDepositValue << endl;
    cout << "The total value of the cashed check is: " << totalCashedCheckValue << endl;
    cout << endl;
    Money updateBalance = oldAmount + totalDepositValue - totalCashedCheckValue;
    Money diffBalance = updateBalance - newAmount;

    cout << "The new balance by input is: " << updateBalance << endl;

    cout << "The difference from the bank balance is : " << diffBalance << endl;
    cout << endl;

    cout << "List of all cashed checks : " << endl;
    cout << "ID" << "\t" << "Amount" << "\t" << "Cashed Status" << endl;
    for (int i = 0; i < checkResArrSize; i++) {
        if (checkArr[i].getHaveCashed() && checkArr[i].getCheckNumber()) {
            int number = checkArr[i].getCheckNumber();
            Money amount = checkArr[i].getCheckAmount();
            bool cashed = checkArr[i].getHaveCashed();
            cout << number << "\t" << amount << "\t" << cashed << endl;
        }
    }
    cout << endl;

    cout << "List of all non-cashed checks : " << endl;
    cout << "ID" << "\t" << "Amount" << "\t" << "Cashed Status" << endl;
    for (int i = 0; i < checkResArrSize; i++) {
        if (!checkArr[i].getHaveCashed() && checkArr[i].getCheckNumber()) {
            int number = checkArr[i].getCheckNumber();
            Money amount = checkArr[i].getCheckAmount();
            bool cashed = checkArr[i].getHaveCashed();
            cout << number << "\t" << amount << "\t" << cashed << endl;
        }
    }
    return 0;
}

int digitToInt(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}

void resizeMoneyArray(Money *&arr, int currentSize, int newSize) {
    Money *temp = new Money[newSize];
    for (int i = 0; i < currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void resizeCheckArray(Check *&arr, int currentSize, int newSize) {
    Check *temp = new Check[newSize];
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