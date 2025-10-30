#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

void display() {
    ifstream file("events.txt");

    if (!file) {
        cout << "Error: Could not open events.txt file!\n";
        return;
    }

    cout << "\n Event List:\n";
    cout << setw(10) << left << "ID"
         << setw(20) << left << "Name"
         << setw(15) << left << "Date"
         << setw(20) << left << "Venue" << endl;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, date, venue;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, date, '|');
        getline(ss, venue, '|');

        cout << setw(10) << left << id
             << setw(20) << left << name
             << setw(15) << left << date
             << setw(20) << left << venue << endl;

        found = true;
    }

    file.close();

    if (!found) {
        cout << "\n No events found in file.\n";
    }
}

int main() {
    int choice1 = 1;

    while (choice1 == 1) {
        display();

        cout << "\nPress 1 to continue operation or 0 to exit: ";
        cin >> choice1;
    }

    cout << "\n Exit program.\n";
    return 0;
}