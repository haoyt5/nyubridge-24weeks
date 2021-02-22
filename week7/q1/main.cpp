#include <iostream>

using namespace std;

int const daysInWeek = 7;

int printMonthCalender(int numOfDays, int startingDay);

int convertDay(int lastMonthEndingDay);

bool isLeapYear(int year);

void printYearCalender(int year, int startingDay);

int monthLength(int month, int year);

string monthFormatter(int month);

int main() {
    int year;
    int startingDay;

    cout << "Please enter an integer that represents the year you intended print the calendar: " << endl;
    cin >> year;
    cout
            << "Please enter an integer number 1-7 that represents the day in the week of 1/1 in that year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.)"
            << endl;

    cin >> startingDay;
    if (startingDay > 0 && startingDay <= 7)
        printYearCalender(year, startingDay);
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    int lastDayInMonth = convertDay((numOfDays % daysInWeek) + startingDay - 1);

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    for (int tab = 0; tab < startingDay - 1; tab++) {
        cout << "\t";
    }
    for (int date = 1; date <= numOfDays; date++) {
        cout << date << "\t";
        if ((date + startingDay) % daysInWeek == 1 && date != numOfDays) {
            cout << endl;
        }
    }
    return lastDayInMonth;
}

bool isLeapYear(int year) {
    return (!(year % 4) && year % 100) || !(year % 400);
}

int monthLength(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int convertDay(int lastMonthEndingDay) {
    int dayIndex = lastMonthEndingDay % 7;
    if (dayIndex == 0) {
        return 7;
    }
    return dayIndex;
}

void printYearCalender(int year, int startingDay) {
    int lastDayInLastMonth = startingDay - 1;
    for (int month = 1; month <= 12; month++) {
        cout << endl;
        cout << monthFormatter(month) << " " << year << endl;
        lastDayInLastMonth = printMonthCalender(monthLength(month, year), convertDay(lastDayInLastMonth + 1));
        cout << endl;
    }
}

string monthFormatter(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "January";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}
