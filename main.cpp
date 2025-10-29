#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

void search_name() {
    string id, name, date, venue;
    string searchname;
    string line; 
    bool found = false;

    cout << "Enter event name to search: ";
    getline(cin, searchname);

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        
       
        while (getline(file, line)) {
            
            stringstream ss(line);

         
            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|'); 

            
            if (name == searchname) {
                cout << "Event found!" << endl;
                cout << "Event ID: " << id << endl;
                cout << "Event Name: " << name << endl;
                cout << "Event Date: " << date << endl;
                cout << "Venue:"  << venue << endl;
                found =true ;
                break;
            }
        }
        file.close();

        if (found == false) {
            cout << "Event not found!" << endl;
        }
    } else {
        cout << "File unable to open!" << endl;
    }
}

void search_venuename(){
    string id, name, date, venue;
    string search_venuename;
    string line; 
    bool found = false;

    cout << "Enter venue name to search: ";
    getline(cin, search_venuename);

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        
       
        while (getline(file, line)) {
            
            stringstream ss(line);

         
            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|'); 

            
            if (venue == search_venuename) {
                cout << "Events found on this venue !" << endl;
                cout << "Event ID: " << id << endl;
                cout << "Event Name: " << name << endl;
                cout << "Event Date: " << date << endl;
                cout << "Venue:"  << venue << endl;
                found =true ;
                
            }
        }
        file.close();

        if (found == false) {
            cout << "Event not found ! :(" << endl;
        }
    } else {
        cout << "File unable to open! :(" << endl;
    }
}

;


int main() {
    cout << "\n--- Event Search Menu ---" << endl;
    cout << "1 -->   Search by Event Name" << endl;
    cout << "2 -->  Search by Venue Name" << endl;
    
    int input_from_user;
    cin>>input_from_user;
    cin.ignore();
    if (input_from_user==1){
        search_name();

    }
    else if (input_from_user==2)
    {
        search_venuename();
    }
    else{
        cout<<"invalid input";
    }
    
    return 0;
}
