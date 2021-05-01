#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openInputFile(ifstream &inFile) {
    string filename;
    cout << "What filename you are going to open?";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "FILE FAILED TO OPEN" << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

class Employee {
public:
    Employee(const int &id, const double &payRate, const string &name) : id(id), payRate(payRate), name(name),
                                                                         workHours(0), totalPay(0) {

    }

    int getId() const {
        return id;
    }

    double getPayRate() const {
        return payRate;
    }

    string getName() const {
        return name;
    }

    int getWorkHours() const {
        return workHours;
    }

    double getTotalPay() const {
        return totalPay;
    }


private:
    int workHours;
    double totalPay;
    int id;
    double payRate;
    string name;
};

struct EmployeeStruct {
    int id{};
    double payRate{};
    string name;
};

int main() {
    ifstream inFile;
    openInputFile(inFile);
    EmployeeStruct temp;
    while (inFile >> temp.id) {
        inFile >> temp.payRate;
        inFile.ignore(9999, '\t');
        getline(inFile, temp.name);
        Employee tempClass(temp.id, temp.payRate, temp.name);
    }
    return 0;
}
