#include <iostream>

using namespace std;

class Money;


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

int digitToInt(char c);

int main() {


    Money money = Money();
    Money money2 = Money(10, 10);
    Money money3 = Money(10);
    cout << money.getValue() << endl;
    cout << money2.getValue() << endl;
    cout << money3.getValue() << endl;
    return 0;
}

int digitToInt(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
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