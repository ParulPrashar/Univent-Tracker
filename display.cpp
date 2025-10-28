#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Event {
    int eventID;
    string name;
    string date;
    string category;
    string department;
    string venue;
    string context;
};

Event event[5]={
    {101, "TechTalk", "26-10-2025", "Seminar", "CSE", "Auditorium", "Innovation"},
    {102, "Cultural Fest", "28-10-2025", "Festival", "Arts", "Main Ground", "Entertainment"},
    {103, "Coding Marathon", "30-10-2025", "Competition", "CSE", "Lab 3", "Programming"},
    {104, "Robotics Expo", "02-11-2025", "Exhibition", "CSE", "Hall B", "Technology"},
    {105, "Sports Meet", "05-11-2025", "Event", "Sports Dept", "Main Stadium", "Games"}
};
int n=5;
void printEvents(Event event [],int n){
    cout << setw(20) <<left<< "Name"
         << setw(15) <<left<< "Date"
         << setw(15) <<left<< "Category"
         << setw(15) <<left<< "Department"
         << setw(15) <<left<< "Venue"
         << setw(15) << left<<"Context" << endl;


    for (int i = 0; i < n; i++) {
            cout << setw(20) <<left<< event[i].name
             << setw(15) <<left<< event[i].date
             << setw(15) <<left<< event[i].category
             << setw(15) <<left<< event[i].department
             << setw(15) <<left<< event[i].venue
             << setw(15) <<left<< event[i].context << endl;
    }
}

int main() {     
    printEvents(event,n);   
    return 0;
}
