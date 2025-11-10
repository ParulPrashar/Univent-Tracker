#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string>
#include "multipleCodeChoice.h"

using namespace std;

//Commonly used functions
string toLowerCase(string var){
                transform(var.begin(), var.end(), var.begin(), [](unsigned char c){
                    return tolower(c); });
                    return var;
                }
int dateToint(string date){
    int d,m,y;
    char sep;
    stringstream ss(date);
    ss>>d>>sep>>m>>sep>>y;
    return y*10000+m*100+d;
}

//search functions
void search_name() {
    string id, name, date, venue;
    string search_name;
    string line; 
    bool found = false;

    int count=0, req_id;

    cout << " Enter event name to search: ";
    getline(cin, search_name);

    search_name=toLowerCase(search_name);

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        
       
        while (getline(file, line)) {
            
            stringstream ss(line);

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|'); 

            string temp_name=name;
            temp_name=toLowerCase(temp_name);
            
            if (temp_name == search_name) {
                found =true;
                if(count==0){
                cout << " Event found on this name ! \n" << endl;
                count++;
                }
                cout << " Event ID: " << id << endl;
                cout << " Event Name: " << name << endl;
                cout << " Event Date: " << date << endl;
                cout << " Event Venue: "  << venue << endl;
                cout << " \n";
                break;
            }
        }
        file.close();

        if (found == false) {
            cout << " Event not found! on " << search_name << "!" << endl;
        }
    } else {
         cerr<<" Error: Could not open file! "<<endl;
    }
}

void search_venue()
{
    string id, name, date, venue;
    string search_venue;
    string line; 
    bool found = false;

    int count=0;

    cout << " Enter venue to search : ";
    getline(cin, search_venue);
    search_venue=toLowerCase(search_venue);

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        
       
        while (getline(file, line)) {
            
            stringstream ss(line);

         
            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|'); 

            string temp_venue=venue;
            temp_venue=toLowerCase(temp_venue);
            
            if (temp_venue == search_venue) {
                found =true ;
                if(count==0){
                cout << " Events found on this venue ! \n" << endl;
                count++;
                }
                cout << " Event ID : " << id << endl;
                cout << " Event Name : " << name << endl;
                cout << " Event Date : " << date << endl;
                cout << " Event Venue : "  << venue << endl;
                cout << " \n";
                
            }
        }
        file.close();

        if (found == false) {
            cout << " Event not found! on " << search_venue << "!" << endl;
        }
    } else {
        cerr<<" Error: Could not open file! "<<endl;
    }
}

void search_date() 
{
    string id, name, date, venue;
    string search_date;
    string line;
    bool found = false;

    int count=0;

    cout << " Enter date to search (dd-mm-yyyy) : ";
    cin >> search_date;

    ifstream file;
    file.open("events.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, date, '|');
            getline(ss, venue, '|');

            if (date == search_date) {
                found = true;
                if(count==0){
                cout << " Events found on this date ! \n" << endl;
                count++;
                }
                cout << " Event ID : " << id << endl;
                cout << " Event Name : " << name << endl;
                cout << " Event Date : " << date << endl;
                cout << " Event Venue : "  << venue << endl;
                cout << " \n";
            }
        }
        file.close();

        if (!found) {
            cout << " Event not found! on " << search_date << endl;
        }
    } else {
        cerr<<" Error: Could not open file! "<<endl;
    }
}


//sort functions

void sort_Name(){
    ifstream fin("events.txt");
    if(!fin) {
        cout<<"\nNo events found!";
        return;
    }
    // Event events[100];
    string sort_name[100], _date[100], _venue[100];
    string line, temp_name, temp_date,temp_venue;
    int count =0, _id[100], temp_id;
    string date, venue;

    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        _id[count] = stoi(temp);
        getline(ss, sort_name[count],'|');
        getline(ss, _date[count],'|');
        getline(ss, _venue[count],'|');
        count++;
    }
    fin.close();

        if(count ==0){
            cout<<"\nFile is empty\n";
            return;

        }
        for(int i=0; i<count-1;i++){
            for(int j=0; j<count-i-1;j++){
                string name1=sort_name[j];
                string name2=sort_name[j+1];

                name1=toLowerCase(name1);
                name2=toLowerCase(name2);
                if(name1 >name2){
                    temp_name=sort_name[j];
                    sort_name[j]=sort_name[j+1];
                    sort_name[j+1]=temp_name;

                    temp_id=_id[j];
                    _id[j]=_id[j+1];
                    _id[j+1]=temp_id;

                    temp_date=_date[j];
                    _date[j]=_date[j+1];
                    _date[j+1]=temp_date;

                    temp_venue=_venue[j];
                    _venue[j]=_venue[j+1];
                    _venue[j+1]=temp_venue;
                }
            }

        }
    cout<<left;
    cout<<setw(6) << " ID";
    cout<<setw(30)<< " Name";
    cout<<setw(15)<< " Date";
    cout<<setw(20)<< " Venue"<< "\n";
    cout<<" ---------------------------------------------------------- "<<endl;

    for(int i=0;i<count;i++){
        cout<<" ";
        cout<< setw(6)  << _id[i];
        cout<< setw(30) << sort_name[i];
        cout<< setw(15) << _date[i];
        cout<< setw(20) << _venue[i]<<"\n";
    }
} 

void sort_Date(){
    ifstream fin("events.txt");
    if(!fin){
        cout<<"\nNo events found\n";
        return;
    }
    string _name[100], sort_date[100], _venue[100];
    string line, temp_name, temp_date,temp_venue;
    int count =0, _id[100], temp_id;
    string date, venue;

    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        _id[count] = stoi(temp);
        getline(ss, _name[count],'|');
        getline(ss, sort_date[count],'|');
        getline(ss, _venue[count],'|');
        count++;
    }
    fin.close();
    if(count ==0){
            cout << "\n No events to sort\n";
            return;

        }
        for(int i=0; i<count-1;i++){
            for(int j=0; j<count-i-1; j++){
                if(dateToint(sort_date[j]) > dateToint(sort_date[j+1])){
                    temp_date=sort_date[j];
                    sort_date[j]=sort_date[j+1];
                    sort_date[j+1]=temp_date;

                    temp_id=_id[j];
                    _id[j]=_id[j+1];
                    _id[j+1]=temp_id;

                    temp_name=_name[j];
                    _name[j]=_name[j+1];
                    _name[j+1]=temp_name;

                    temp_venue=_venue[j];
                    _venue[j]=_venue[j+1];
                    _venue[j+1]=temp_venue;
                }
            }
        }
    cout<< left;
    cout<< setw(6) << " ID";
    cout<< setw(30)<< " Name";
    cout<< setw(15)<< " Date";
    cout<< setw(20)<< " Venue"<< "\n";
    cout<<" ---------------------------------------------------------- "<<endl;
    
    for(int i=0;i<count;i++){
        cout<<" ";
        cout<< setw(6)  << _id[i];
        cout<< setw(30) << _name[i];
        cout<< setw(15) << sort_date[i];
        cout<< setw(20) << _venue[i]<<"\n";
    }
}   

void sort_Venue(){
    ifstream fin("events.txt");
    if(!fin){
        cout<<"\nNo events found\n";
        return;
    }
    string _name[100], _date[100], sort_venue[100];
    string line, temp_name, temp_date,temp_venue;;
    int count =0, _id[100], temp_id;
    string date, venue;

    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        _id[count] = stoi(temp);
        getline(ss, _name[count],'|');
        getline(ss, _date[count],'|');
        getline(ss, sort_venue[count],'|');
        count++;
    }
    fin.close();
    if(count ==0){
            cout << "\n No events to sort\n";
            return;

        }
        for(int i=0; i<count-1;i++){
            for(int j=0; j<count-i-1; j++){
                if(sort_venue[j] > sort_venue[j+1]){
                    temp_venue=sort_venue[j];
                    sort_venue[j]=sort_venue[j+1];
                    sort_venue[j+1]=temp_venue;

                    temp_id=_id[j];
                    _id[j]=_id[j+1];
                    _id[j+1]=temp_id;

                    temp_name=_name[j];
                    _name[j]=_name[j+1];
                    _name[j+1]=temp_name;

                    temp_date=_date[j];
                    _date[j]=_date[j+1];
                    _date[j+1]=temp_date;
                }
            }
        }
    cout<< left;
    cout<< setw(6) << " ID";
    cout<< setw(30)<< " Name";
    cout<< setw(15)<< " Date";
    cout<< setw(20)<< " Venue"<< "\n";
    cout<<" ---------------------------------------------------------- "<<endl;
    
    for(int i=0;i<count;i++){
        cout<<" ";
        cout<< setw(6)  << _id[i];
        cout<< setw(30) << _name[i];
        cout<< setw(15) << _date[i];
        cout<< setw(20) << sort_venue[i]<<"\n";
    }
}   

//display code for deletion 
void display(){
    ifstream file("events.txt");
    if (!file) {
        cerr<<" Error: Could not open file! "<<endl;
        return;
    }

    cout<<left;
    cout<<setw(6) << " ID";
    cout<<setw(30)<< " Name";
    cout<<setw(15)<< " Date";
    cout<<setw(20)<< " Venue"<< "\n";
    cout<<" ---------------------------------------------------------- "<<endl;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, date, venue;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, date, '|');
        getline(ss, venue, '|');

        cout << " ";
        cout << setw(6)  << id;
        cout << setw(30) << name;
        cout << setw(15) << date;
        cout << setw(20) << venue << endl;
        found=true;
    }
    file.close();
    if (!found) {
        cout << " Events not found in the file! "<<endl;
    }
}