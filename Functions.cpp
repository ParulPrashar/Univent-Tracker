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
    cout<<" \t\tWelcome to insertion of events "<<endl;
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
    
    cout<<"\n Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int delete_event()
{
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to deletion of events "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    // int count=event_count;
    ifstream fin("events.txt");
    if (!fin) {
        cerr<<" Error: Could not open file! "<<endl;
        return -1;
    }
    string name[100],date[100],venue[100], line; 
    int id[100], count=0;

    // Reading events from text file into arrays
    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        id[count] = stoi(temp);
        getline(ss, name[count],'|');
        getline(ss, date[count],'|');
        getline(ss, venue[count],'|');
        count++;
    }
    fin.close();
    // cout<<" count= \t"<<count<<endl;
    // cout<<" event_count= \t"<<event_count<<endl;
    if (!count) {
        // cout<<" count= \t"<<count<<endl;
        // cout<<" event_count= \t"<<event_count<<endl;
        cout << " No events found in 'events.txt' file! " << endl;
    }
    else{
    int choice;
    cout<<" Do you want to display events before deleting? "<<endl;
    cout<<" Press 0 : No "<<endl;
    cout<<" Press 1 : Yes "<<endl;
    cout<<" Your Choice : \t";
    cin>>choice;
    switch(choice){
        case 1:
            display();
            break;
        default:
            break;
    }

    int del_id;
    cout << "\n Enter the Event ID to delete the event : \t";
    cin >> del_id;
    if (del_id < 1 || del_id > count) {
        cout << " Invalid ID enetered " << endl;
        return 0;
    }
    // Shift all elements by one place before, after deleting the required element
    for (int i = del_id-1; i < count; i++) {
        id[i]    = i+1;
        name[i]  = name[i + 1];
        date[i]  = date[i + 1];
        venue[i] = venue[i + 1];
    }
    count--;
    event_count--;
    saveEventCount();
    // Rewrite into events.txt file with updated list
    ofstream fout("events.txt");
    for (int i = 0; i < count; i++) {
        fout << id[i] << "|"
             << name[i] << "|" 
             << date[i] << "|" 
             << venue[i] << "\n";
    }
    fout.close();

    cout << " Event deleted successfully! \n"<<endl;
    cout << " Updated List of Events \n"<<endl;
    display();
    cout<<" Final events count is: "<<event_count<<endl;
    }
    cout<<"\n Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int search_event(){
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to searching event "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" Select one of the following available options for search type " << endl;
    cout<<" Press 1 : Search by Event Name " << endl;
    cout<<" Press 2 : Search by Venue " << endl;
    cout<<" Press 3 : Search by Date " << endl;  
    cout<<" Your Choice : \t";
    int input_from_user;
    cin>>input_from_user;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    string search_val;
    switch (input_from_user)
    {
    case 1:
        search_name();
        break;
    case 2:
        search_venue();
        break;
    case 3:
        search_date();
        break;
    default:
        cout<<"invalid input";
        break;
    }

    
    cout<<"\n Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int sort_event(){
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to sorting event "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" Select one of the following available options for sort type " << endl;
    cout<<" Press 1 : Sort by Event Name " << endl;
    cout<<" Press 2 : Sort by Date " << endl;  
    cout<<" Press 3 : Sort by Venue " << endl;
    cout<<" Your Choice : \t";
    int input_from_user;
    cin>>input_from_user;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    switch (input_from_user)
    {
    case 1:
        sort_Name();
        break;
    case 2:
        sort_Date();
        break;
    case 3:
        sort_Venue();
        break;
    default:
        cout<<"invalid input";
        break;
    }

    
    cout<<"\n Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}

int display_event(){
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" \t\tWelcome to displaying event "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;

    display();
    // ifstream file("events.txt");
    // if (!file) {
    //     cerr<<" Error: Could not open file! "<<endl;
    //     return -1;
    // }

    // cout<<left;
    // cout<<setw(6) << " ID";
    // cout<<setw(30)<< " Name";
    // cout<<setw(15)<< " Date";
    // cout<<setw(20)<< " Venue"<< "\n";
    // cout<<" ---------------------------------------------------------- "<<endl;

    // string line;
    // bool found = false;

    // while (getline(file, line)) {
    //     stringstream ss(line);
    //     string id, name, date, venue;

    //     getline(ss, id, '|');
    //     getline(ss, name, '|');
    //     getline(ss, date, '|');
    //     getline(ss, venue, '|');

    //     cout << " ";
    //     cout << setw(6)  << id;
    //     cout << setw(30) << name;
    //     cout << setw(15) << date;
    //     cout << setw(20) << venue << endl;
    //     found=true;
    // }
    // file.close();
    // if (!found) {
    //     cout << " Events not found in the file! "<<endl;
    // }
    cout<<"\n Press 1 to continue operations OR Press 0 to exit. \t";
    cin>>prgm_exe;
    cin.ignore();
    cout<<" ------------------------------------------------------- "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    return 0;
}