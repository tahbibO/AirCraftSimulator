#include "Part.h"

Part::Part(const string& name):name(name){};

//maybe delete date?
Part::~Part(){
    delete installationDate;
}

string Part::getName(){return name;};

int Part::getFlightHours(){return flightHours;};

void Part::addFlightHours(const int& num){
    flightHours+= num;
}

void Part::install(Date& d){
    delete installationDate;
    installationDate = new Date(d.getYear(),d.getMonth(),d.getDay());
};


//FH_Part

FH_Part::FH_Part(const string& name, const int& fh)
:Part(name), fh_inspect(fh){};

FH_Part::~FH_Part(){};

int FH_Part::getFh_inspect(){return fh_inspect;};

void FH_Part::print(ostream& output){
    output << left;
    output << setw(15) << "Part" << ": " << name << endl;
    output << setw(15) << "Date" << ": " << (*installationDate);
    output << setw(15) << "Flight Hours" << ": " << flightHours << endl;
    output << setw(15) << "FH Inspection" << ": " << fh_inspect << endl;
    output << endl;

}

bool FH_Part::inspection(Date& d){
    return (flightHours >= fh_inspect);
}

//IT_Part

IT_Part::IT_Part(const string& name,const int& num)
:Part(name),it_inspect(num){};

IT_Part::~IT_Part(){};

int IT_Part::getIt_inspect(){return it_inspect;};

bool IT_Part::inspection(Date& d  ){
    int diff = d.toDays() - (*installationDate).toDays(); 
    return (diff >= it_inspect) || ((-1*diff) >= it_inspect);
}

void IT_Part::print(ostream& output){
    output << left;
    output << setw(15) << "Part" << ": " << name << endl;
    output << setw(15) << "Date" << ": " << (*installationDate);
    output << setw(15) << "Flight Hours" << ": " << flightHours << endl;
    output << setw(15) << "IT Inspection" << ": " << it_inspect << endl;
    output << endl;

}

//FHIT_Part

FHIT_Part::FHIT_Part(const string& name, const int& fh, const int& it)
:Part(name),FH_Part(name,fh),IT_Part(name,it){};

FHIT_Part::~FHIT_Part(){};

bool FHIT_Part::inspection(Date& d){
    return FH_Part::inspection(d)|| IT_Part::inspection(d);
};

void FHIT_Part::print(ostream& output){
    output << left;
    output << setw(15) << "Part" << ": " << name << endl;
    output << setw(15) << "Date" << ": " << (*installationDate);
    output << setw(15) << "Flight Hours" << ": " << flightHours << endl;
    output << setw(15) << "FH Inspection" << ": " << fh_inspect << endl;
    output << setw(15) << "IT Inspection" << ": " << it_inspect << endl;
    output << endl;
}

ostream& operator<<(ostream& out, Part& p){
    p.print(out);
    return out;
}