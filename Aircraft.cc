#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& registration): 
type(type), registration(registration){
    flighthours = 0;
};

Aircraft::~Aircraft(){};

string Aircraft::getRegistration(){
    return registration;
}

void Aircraft::install(Part* part, Date& d ){
    part->install(d);
    parts.add(part);
};

void Aircraft::takeFlight(int hours){
    flighthours+= hours;

    for(int i = 0; i < parts.getSize();i++){
        parts[i]->addFlightHours(hours);
    }

};

void Aircraft::inspectionReport(Date& d, Array<Part*>& inspectParts){
    
    for(int i = 0; i < parts.getSize();i++){
        if(parts[i]->inspection(d) == true){
            inspectParts.add(parts[i]);
        }
    }
};


void Aircraft::print(ostream& os){
    os << type << ": " << registration;
};

ostream& operator<<(ostream& out, Aircraft& a){
    a.print(out);
    return out;
};