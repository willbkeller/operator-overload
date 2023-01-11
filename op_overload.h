
/************************************************************************
    Author: William Keller
    Title: Operator Overload Example for ECE 321L
    Date: 11.19.2022
    
    Purpose:
        C++ header file w/ class and function definitions for 
        op_overload program.
************************************************************************/

#include <iostream>
using namespace std;

class Distance{

    /*
        Prototypes are declared in the class. Definitions are outside
        of the class
    */
    friend Distance operator+(Distance d1, Distance d2);
    friend void operator*(Distance &d, int m);
    friend bool operator==(Distance d1, Distance d2);
    friend void operator--(Distance &d);

    private:
        int Feet;
        int Inches;
    
    public:
        Distance(int ft, int inch){
            if(inch>=12){
                Feet = ft + 1;
                Inches = inch - 12;
            }
            else{
                Feet = ft;
                Inches = inch;
            }
        }

        void print(){
            cout<<Feet<<"'"<<Inches<<"\""<<endl;
        }
};

Distance operator+(Distance d1, Distance d2){
    int feet = d1.Feet + d2.Feet;
    int inches = d1.Inches + d2.Inches;
    return Distance(feet, inches);
}

/*
    The order in which the arguments are passed matter when
    dealing with different types (i.e. int and Distance).
    If in main(), I tried to write '3*d2;' I would get an
    error because the function was not defined in that way.
*/
void operator*(Distance &d, int m){
    d.Feet = m * d.Feet;
    d.Inches = m * d.Inches;
    d = Distance(d.Feet, d.Inches);
}

bool operator==(Distance d1, Distance d2){
    if(d1.Feet==d2.Feet && d1.Inches==d2.Inches)
        return true;
    else
        return false;
}

void operator--(Distance &d){
    d = Distance(--d.Feet, --d.Inches);
}

void check_equality(Distance d1, Distance d2){
    //Ternary operator makes use of the '==' overloading
   (d1==d2)?cout<<"Equal"<<endl:cout<<"Not Equal"<<endl; 
}