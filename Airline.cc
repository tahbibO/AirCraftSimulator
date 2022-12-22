#include "Airline.h"



Airline::Airline(const string& name):
name(name){};

Airline::~Airline(){
    
};

bool Airline::getAircraft(string r,Aircraft*& a){
    for(int i =  0; i < aircrafts.getSize(); i++){
        if(aircrafts[i]->getRegistration().compare(r)==0){
            a = aircrafts[i];
            return true;
        } 
    }
    return false;
};


bool Airline::getPart(string n, Part*& p ){
    for(int i = 0; i < parts.getSize();i++){
        if(parts[i]->getName().compare(n)==0){
            p = parts[i];
            return true;
        }
    }
    return false;
};



void Airline::takeFlight(string reg, int hours){
    Aircraft* a;
    if(getAircraft(reg, a)){
        a->takeFlight(hours);
    }
};


void Airline::addAircraft(const string& t, const string& r){
    Aircraft* a = new Aircraft(t,r);
    aircrafts.add(a);
}


void Airline::addPart(const string& name,int fh_inspect, int it_inspect){
    
    Part* p;

    if (fh_inspect != 0 and it_inspect != 0){
        p = new FHIT_Part(name,fh_inspect,it_inspect);


    }else if(fh_inspect == 0){
        p = new IT_Part(name,it_inspect);

    }else if (it_inspect == 0){
        p = new FH_Part(name,fh_inspect);

    }
   
    parts.add(p);
}



void Airline::printAircraft(){
    cout << aircrafts;
}


void Airline::printParts(){
    cout << parts;
}


void Airline::inspectionReport(string r, Date& d){
    Array<Part*> arr;
    Aircraft* a;
    if(getAircraft(r,a)){
        a->inspectionReport(d,arr);
    }else{
        cout << "could not find aircraft" << endl;
    }
    

    
}

bool Airline::install(string reg,string name,Date& d){
    
    Part* p;
    Aircraft* a;
    if (getPart(name, p) == false || getAircraft(reg,a) == false){
        return false;
    }
    a->install(p,d);
    return true;
}   
