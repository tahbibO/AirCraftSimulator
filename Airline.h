#ifndef AIRLINE_H
#define AIRLINE_H

using namespace std;

#include <iomanip>
#include <string>
#include "Aircraft.h"
#include "Array.h"
#include "Part.h"
#include "defs.h"

class Airline{
    private:
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;

        bool getAircraft(string, Aircraft*&);
        bool getPart(string,Part*&);


    public:
        Airline(const string&);
        ~Airline();
        void addAircraft(const string&,const string&);
        void addPart(const string&, int=0, int=0);
        void takeFlight(string reg, int hours);
        void printAircraft();
        void printParts();
        void inspectionReport(string,Date&);
        bool install(string,string,Date&);

};

#endif