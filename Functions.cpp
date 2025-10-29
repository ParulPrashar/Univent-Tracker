#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Event.h"
#include "Functions.h"
#include "main.h"
#include "multipleCodeChoice.h"
using namespace std;

int insert_event(){

    Event e;
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to inserting event "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    string temp_name, temp_date, temp_venue;
    int temp_id;
    
    //Inputting Values
    temp_id=event_count;
    e.set_ID(temp_id);

    cout<<" Enter the name of the event: \t";
    getline(cin,temp_name);
    e.set_Name(temp_name);

    cout<<" Enter the date of the event: \t";
    getline(cin, temp_date);
    e.set_Date(temp_date);

    cout<<" Enter the venue of the event: \t";
    getline(cin, temp_venue);
    e.set_Venue(temp_venue);

    //ADDING TEXT FILE
    ofstream file("events.txt", ios::app);

    if(!file){
        cerr<<" Error: Could not open file! "<<endl;
        return -1;
    }
    file<<e.get_ID()<< "|" <<e.get_Name()<< "|" <<e.get_Date()<< "|" <<e.get_Venue()<<'\n';
    file.close();

    //Confirmation Message
    cout<<" ------------------------------------------------------- "<<endl;
    saveEventCount();
    cout<<" Event added successfully "<<endl;
    cout<<" Final events count is: "<<event_count<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int delete_event(){}

int search_event(){
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to searching event "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" Select one of the following availaable options for search type " << endl;
    cout<<" Press 1 : Search by Event Name " << endl;
    cout<<" Press 2 : Search by Venue " << endl;
    cout<<" Your Choice : \t";
    int input_from_user;
    cin>>input_from_user;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    if (input_from_user==1)
    {
        search_name();
    }
    else if (input_from_user==2)
    {
        search_venuename();
    }
    else{
        cout<<"invalid input";
    }
    
    cout<<" Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int sort_event(){}

int display_event(){
        
    // Event e;
    // string temp_name, temp_date, temp_venue;
    // int temp_id;
    
    // ifstream file("event.txt");
    // if (!file){
    //     cerr<< " Error: Cannot Read the file";
    //     return -1;
    // }

    // cout << setw(20) <<left<< "Name"
    //      << setw(15) <<left<< "Date"
    //      << setw(15) <<left<< "Venue"<< endl;

        
}