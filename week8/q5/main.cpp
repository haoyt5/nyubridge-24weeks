#include <iostream>

using namespace std;

int main() {
    string firstName;
    string middleName;
    string lastName;
    cout << "Pleas enter a person’s name in the following format First_Name Middle_Name(or initial) Last Name: "
         << endl;
    cin >> firstName;
    cin >> middleName;
    cin >> lastName;
    cout << lastName << ", " << firstName << " " << middleName[0] << "." << endl;
    return 0;
}
