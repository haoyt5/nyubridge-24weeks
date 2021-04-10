# Week 12
## Agenda

This week we will be studying object oriented programming including the design of classes, constructors, destructors, copy constructors, operator overloading (including the assignment operator), inheritance and polymorphism. 

Object orientation came about in the mid-1980s as a concept to keep data and the functions to work on the data together.  Since then, a lot of development has been done and today object orientation is expected in a lot of situations.  Java, for example, is a purely object-oriented language; everything is an object!

For this week, please do the following:

- Read “Problem solving with C++” by Walter Savitch, chapters 10 and 11
- Be able to answer all of the self-test exercises in the chapters
- Attend the weekly webinar (Thursday 8:00 pm). This week we will be discussing solving problems with pointers and dynamic storage as well as debugging problems with pointers.
- Review the sample code and lecture notes for the CS2124 website listed below. (http://cis.poly.edu/jsterling/cs2124/)

## Objectives
By the end of this week, you should:

- Be able to define classes and use them properly
- Understand “encapsulation”
- Understand Public, Private and Protected
- Be able to overload the following operators: +,-,++,--,*,*=,<<,>>,<,=,[]
- Understand the Big 3 and when they are needed
- Understand when to implement as a member, non-member friend and non-member non-friend

## Assignment

CH11 #7 (page 698): Write a checkbook balancing program. 
The program will read in, from the console, the following for all checks that were not cashed as of the last time you balanced your checkbook:
-  the number of each check (int)
- the amount of the check (double)
-  and whether or not it has been cashed (1 or 0, boolean in the array). 
Use an array with the class as the type. The class should be a class for a check. 
There should be three member variables to record 
- the check number,
- the check amount
- and whether or not the check was cashed.
 The class for a check will have a member variable of type Money (as defined on page 662 in the book; Display 11.9) to record the check amount. So, you will have a class used within a class.
The class for a check should have accessor and mutator functions as well as constructors and functions for both input and output of a check.  In addition to the checks, the program also reads all the deposits (from the console; cin), the old and the new account balance (read this in from the user at the console; cin). You may want another array to hold the deposits. The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.

The program outputs the total of the checks cashed, the total of the deposits, what the new balance should be, and how much this figure differs from what the bank says the new balance is. 
It also outputs two lists of checks: the checks cashed since the last time you balanced your checkbook and the checks still not cashed. 
[ edit: if you can, Display both lists of checks in sorted order from lowest to highest check number.]
```
Please enter your existing(old) bank balance ($##.##): $10.04
Please enter your new bank balance ($##.##): $70.03
Please enter how many deposits you have (#): 2
Please enter deposit ($##.##) one per line: 
$10.39
$20.99

Please enter how many checks you have for processing (#): 2
*The format of the check input per line is (# $##.## #), with space between the detail items 
	- The first position is the check number (#),
	- The second position is the check amount ($##.##),
	- The third position is whether checked or not, 0 if not chased, 1 if cashed (#),
Please enter checks (# $##.## #) one per line:
1001 $1002.10 1
1003 $1003.05 0

The total value of the deposits you made is: $31.38
The total value of the cashed check is: $1002.10

The new balance by input is: -$960.68
The difference from the bank balance is : -$1030.71

List of all cashed checks : 
ID	Amount	Cashed Status
1001	$1002.10	1

List of all non-cashed checks : 
ID	Amount	Cashed Status
1003	$1003.05	0
```
## Module 15 Object Oriented Programming

### Accessors and Mutators
- Accessors (Getter): are used to get information out of the class.
- Mutators (Setter): are used to put information into the class. (Can change data)
- Example creating three functions here that will act as the mutators; so we've got the set day, set month, and set year function:
    - all three functions are members of the class 
    - idea of encapsulation:  members of the class will have access to the private information inside the class

```c++
class Date {
private:
    int day;
    int month;
    int year;
public:
    void setDay(int newDay);  // mutator

    void setMonth(int newMonth); // mutator

    void setYear(int newYear) { year = newYear; }; // mutator
    void displayDate() const{
        cout << day <<"/"<<month <<"/" << year;
    }; 
};

void Date::setDay(int newDay) {
    if (newDay > 0 && newDay <= 31) {
        day = newDay;
    }
}

void Date::setMonth(int newMonth) {
    if (newMonth > 0 && newMonth <= 12) {
        month = newMonth;
    }
}
// Creating and working with an object
int main() {
    Date d1;
    d1.setDay(6);
    d1.setMonth(8);
    d1.setYear(1991);

    cout<<"very important date: ";
    d1.displayDate();
}
```

### Constructor 
- A constructor is a (public) member function automatically called when the object of the class is declared
- the default constructor is a function named exactly the same as the name of the class with no return type and no parameter
#### constructor parts
```c++
class Date1 {
private:
    int day;
    int month;
    int year;
public:
    Date1() : day(6), month(8), year(1991) {};  // constructor: Member initialization list
};

class Date2 {
private:
    int day;
    int month;
    int year;
public:
    Date2() {
        day = 6;
        month = 8;
        year = 1991;
    };  // constructor
};
```

```c++
class Date {
private:
    int day;
    int month;
    int year;
public:
    void displayDate() const {
        cout << day << "/" << month << "/" << year;
    }; // const-ified function
    Date(int newD, int newM, int newY) : day(newD), month(newM), year(newY) {};   // constructor ; constructor initialization section

};

int main() {
    Date d2(6, 8, 1991);
    cout << "very important date: ";
    d2.displayDate();
}
```

### An important Pointer: this
- Every object has a pointer, which looks like a data member, called "this".
```c++
    void setYear(int newYear) { this->year = newYear; };
```