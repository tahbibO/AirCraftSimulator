#ifndef AIRCRAFT_H
#define AIRCRAFT_H

using namespace std;

#include <iostream>
#include <string>
#include "Array.h"
#include "Part.h"
#include "Date.h"
#include "defs.h"
#include <iomanip>


class Aircraft{
    
    friend ostream& operator<<(ostream& out, Aircraft&);

    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;

    public:
        string getRegistration();
        Aircraft(const string&, const string&);
        ~Aircraft();
        void install(Part*, Date&);
        void takeFlight(int);
        void inspectionReport(Date&, Array<Part*>&);
        void print(ostream&);
};



#endif