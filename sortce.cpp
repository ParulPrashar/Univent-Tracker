#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cctype>


using namespace std;

class Event {
public:
    int id;
    string name;
    string date;       
    string venue;

    void input();
};

void Event::input() {
    cout<<"Enter Event ID:";
    cin>>id;
    cin.ignore(); 
    cout<<"Enter Event Name:";
    getline(cin, name);
    cout<<"Enter Event Date:";
    getline(cin,date);
    cout<<"Enter venue:";
    getline(cin,venue);

}



void insertEvent() {
    Event e;
    e.input();
    ofstream fout("events.txt", ios::app);
    fout<<e.id<<"|"<<e.name<<"|"<<e.date<<"|"<<e.venue<<"\n" ;

    fout.close();
    cout << "\nEvent inserted successfully !\n";
    
}
void sortEventsByName(){
    ifstream fin("events.txt");
    if(!fin) {
        cout<<"\nNo events found!";
        return;
    }
    Event events[100];
    string line;
    int count =0;

    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        events[count].id = stoi(temp);
        getline(ss, events[count].name,'|');
        getline(ss,events[count].date,'|');
        getline(ss,events[count].venue,'|');
        count++;
    }
    fin.close();

        if(count ==0){
            cout<<"\n No events to sort\n";
            return;

        }
        for(int i=0; i<count-1;i++){
            for(int j=0; j<count-i-1;j++){
                string name1= events[j].name;
                string name2=events[j+1].name;

                transform(name1.begin(),name1.end(),name1.begin(),::tolower);
                transform(name2.begin(),name2.end(),name2.begin(),::tolower);
                if(name1 >name2){
                    Event temp=events[j];
                    events[j]=events[j+1];
                    events[j+1]=temp;
                }
            }

        }
    cout<<"\n===== Events Sorted By Name ==== \n";
    cout<<left;
    cout<<setw(6)<< "ID";
    cout<<setw(25)<< "Name";
    cout<<setw(15)<< "Date";
    cout<<setw(20)<< "Venue"<< "\n";
    cout<<string(70,'-') << "\n";

    for(int i=0;i<count;i++){
        cout<< setw(6) << events[i].id;
        cout<< setw(25) << events[i].name;
        cout<< setw(15) << events[i].date;
        cout<< setw(20) << events[i].venue<<"\n";
    }
} 


int dateToint(const string &date){
    int d ,m,y;
    char sep;
    stringstream ss(date);
    ss>>d>>sep>>m>>sep>>y;
    return y*10000+m*100+d;

}


void sortEventsByDate(){
    ifstream fin("events.txt");
    if(!fin){
        cout<<"\nNo events found\n";
        return;
    }
    Event events[100];
    string line;
    int count =0;

    while(getline(fin,line) && count<100){
        stringstream ss(line);
        string temp;

        getline(ss,temp,'|');
        events[count].id = stoi(temp);
        getline(ss, events[count].name,'|');
        getline(ss,events[count].date,'|');
        getline(ss,events[count].venue,'|');
        count++;

        

    }
    fin.close();
    if(count ==0){
            cout << "\n No events to sort\n";
            return;

        }
        for(int i=0; i<count-1;i++){
            for(int j=0; j<count-i-1; j++){
                if(dateToint(events[j].date) > dateToint(events[j+1].date)){
                    Event temp=events[j];
                    events[j]=events[j+1];
                    events[j+1]=temp;
                }
            }

        }

 cout<<"\n===== Events Sorted By Date ==== \n";
    cout<< left;
    cout<< setw(6)<< "ID";
    cout<< setw(25)<< "Name";
    cout<< setw(15)<< "Date";
    cout<< setw(20)<< "Venue"<< "\n";
    cout<< string(70,'-') << "\n";
    
    for(int i=0;i<count;i++){
        cout<< setw(6) << events[i].id;
        cout<< setw(25) << events[i].name;
        cout<< setw(15) << events[i].date;
        cout<< setw(20) << events[i].venue<<"\n";
    }
}   

int main(){
    sortEventsByDate();
    return 0;
}
