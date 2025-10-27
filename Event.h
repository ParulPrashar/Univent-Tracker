#ifndef EVENT_H
#define EVENT_H
#include<iostream>
#include<string>
using namespace std;

class Event{
        private:
            int event_id;
            string event_name, event_date, event_venue;
        
        public:
            void event_input();
            void event_display(int id, string name, string date, string venue);

            void set_ID(int);
            void set_Name(string);
            void set_Date(string);
            void set_Venue(string);

            int get_ID();
            string get_Name();
            string get_Date();
            string get_Venue();
};

#endif