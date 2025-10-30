#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void searchDate() {
    string id, name, date, venue;
    string searchDate;
    string line;
    bool found = false;

    cout << "\nEnter Event Date to Search (dd-mm-yyyy): ";
    cin >> searchDate;

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|');

            if (date == searchDate) {
                cout << "\nEvent Found!" << endl;
                cout << "Event ID     : " << id << endl;
                cout << "Event Name   : " << name << endl;
                cout << "Event Date   : " << date << endl;
                cout << "Event Venue  : " << venue << endl;
                found = true;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "\nEvent not found on " << searchDate << "!" << endl;
        }
    } else {
        cout << "\nError: Unable to open events.txt!" << endl;
    }
}

int main() {
    int choice = 1;
    cout << "        EVENT SEARCH MENU     " << endl;
    while (choice == 1) {
        searchDate();
        cout << "\nPress 1 to continue or 0 to exit: ";
        cin >> choice;
    }

    cout << "\nProgram exited successfully." << endl;
    return 0;
}
