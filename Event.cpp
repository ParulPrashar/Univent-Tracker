// this is a file where class structure is created i.e., all events are stored here in the form of array of classes
#include<iostream>
#include<string>
#include"Event.h"
#include "main.h"
using namespace std;

//SETTERS
void Event::set_ID(int e_ID){
    event_id=e_ID;
}
void Event::set_Name(string e_name){
    event_name=e_name;
}
void Event::set_Date(string e_date){
    event_date=e_date;
}
void Event::set_Venue(string e_venue){
    event_venue=e_venue;
}

//Getters
int Event::get_ID(){
    return event_id;
}
string Event::get_Name(){
    return event_name;
}
string Event::get_Date(){
    return event_date;
}
string Event::get_Venue(){
    return event_venue;
}
