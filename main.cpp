#include <iostream>
#include<sstream>
#include "main.h"
#include <fstream>
#include "Event.h"
#include "Functions.h"
using namespace std;

int event_count;
int prgm_exe;
    
void loadEventCount(){
    ifstream file("count.txt");
    if(file){
        file>> event_count;
        file.close();
    }
    else{
        event_count=0;
    }
}
void saveEventCount(){
    ofstream file("count.txt");
    file<< event_count;
    file.close();
}

int main()
{
    // Event events[100];
    loadEventCount();
    // loadEvents();
    prgm_exe=1;
    cout<<" --------------------------------------------- WELCOME TO UNIVENT TRACKER! ----------------------------------------------"<<endl;
    cout<<" Initial events count is: "<<event_count<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    do
    {
        int choice;
        cout<<" Select one of the following choices:- "<<endl;
        cout<<" Press 1 : Insert new Event"<<endl;
        cout<<" Press 2 : Delete an Event"<<endl;
        cout<<" Press 3 : Search for an Event"<<endl;;
        cout<<" Press 4 : Sort all the Events"<<endl;;
        cout<<" Press 5 : Display all the Events"<<endl;;
        cout<<" YOUR CHOICE: \t";
        cin>>choice; 
        cin.ignore();
        switch(choice){
            case 1:
                event_count++; // each of this event is in Functions.cpp file linked to header file in this main.cpp top
                // cout<< event_count<<" "<<endl;
                insert_event();
                break;
            case 2:
                delete_event();
                break;
            case 3:
                search_event();
                break;
            case 4:
                sort_event();
                break;
            case 5:
                display_event();
                break;
            default:
                cout<<" The choice entered is invalid. "<<endl;
                cout<<" Press 1 to continue operations OR Press 0 to exit. \t";
                cin>>prgm_exe;
                cin.ignore();
                cout<<" ------------------------------ "<<endl;
                cout<<" ------------------------------ "<<endl;
        }
    
    }while(prgm_exe); //ask in each method at the method end about prgm_exe your choice to continue or exit. 
    
    cout<<" Thank you for using Univent Tracker. Have a great day! "<<endl;
    cout<<" ------------------------------------------------------- "<<endl;
    system("pause");
    return 0;
}
