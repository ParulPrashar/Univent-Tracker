#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Event {
public:
    string name;
    string date;
    string venue;
};

int main() {
    Event events[100];   
    int count = 0;       

    ifstream fin("eventss.txt");
    if (!fin) {
        cout << "File not found!" << endl;
        return 0;
    }
    // Reading events 
    while (getline(fin, events[count].name, '|') &&
           getline(fin, events[count].date, '|') &&
           getline(fin, events[count].venue)) {
        count++;
    }
    fin.close();

    if (count == 0) {
        cout << "No events found in 'eventss.txt'." << endl;
        return 0;
    }

    // Displaying events
    cout << "\n--- Event List ---\n";
    cout << "Sr.No\tEvent Name\t\tDate\t\tVenue\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << "\t" 
             << events[i].name << "\t\t"
             << events[i].date << "\t"
             << events[i].venue << endl;
    }

    // Delete event by serial number
    int index;
    cout << "\nEnter the serial number of the event to delete: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Invalid serial number!" << endl;
        return 0;
    }

    // Shift all elements after deleted one to the left
    for (int i = index - 1; i < count - 1; i++) {
        events[i] = events[i + 1];
    }
    count--;

    // Rewrite file with updated events
    ofstream fout("eventss.txt");
    for (int i = 0; i < count; i++) {
        fout << events[i].name << "|" 
             << events[i].date << "|" 
             << events[i].venue << "\n";
    }
    fout.close();

    cout << "\nEvent deleted successfully!\n";

    // Display updated list
    cout << "\n--- Updated Event List ---\n";
    cout << "Sr.No\tEvent Name\t\tDate\t\tVenue\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << "\t" 
             << events[i].name << "\t\t"
             << events[i].date << "\t"
             << events[i].venue << endl;
    }

    return 0;
}
