#ifndef PART_H
#define PART_H

using namespace std;
#include <iostream>
#include <string>
#include "Date.h"
#include <iomanip>


class Part{

        friend ostream& operator<<(ostream& out, Part&);


    protected:
    
        string name;
        Date* installationDate = new Date();
        int flightHours;
    public:
        Part(const string&);
        virtual ~Part();

        string getName();
        int getFlightHours();


        void addFlightHours(const int&);
        void install(Date&);
        virtual void print(ostream&)=0;
    
        virtual bool inspection(Date&) = 0;
};

class FH_Part:virtual public Part {
    protected:
        int fh_inspect;
    public:
        FH_Part (const string&, const int&);
        virtual ~FH_Part();

        int getFh_inspect();
        
        virtual void print(ostream&);
        virtual bool inspection(Date&);
};

class IT_Part:virtual public Part{
    protected:
        int it_inspect;
    public:
        IT_Part(const string&, const int&);
        virtual ~IT_Part();

        int getIt_inspect();

        virtual void print(ostream&);
        virtual bool inspection(Date&);

};

class FHIT_Part: public IT_Part, public FH_Part{
    private:
        
    public:
        FHIT_Part(const string&, const int&, const int&);
        virtual ~FHIT_Part();
        
        virtual void print(ostream&);
        virtual bool inspection(Date& d);
};







#endif