
/************************************************************************
    Author: William Keller
    Title: Operator Overload Example for ECE 321L
    Date: 11.19.2022
    
    Purpose:
        Main function of op_overload program with use of header file.
        Gives examples of how the code works.
************************************************************************/

#include <iostream>
#include "op_overload.h" //Include header file to access its contents
using namespace std;

int main(){
    Distance d1 = Distance(10,9);
    Distance d2 = Distance(3,4);
    Distance d3 = d1 + d2;
    d1.print();
    --d1;
    d1.print();
    d2.print();
    d3.print();
    d2*3;
    d2.print();
    Distance d4 = d2;
    d4.print();
    check_equality(d1,d3);
    check_equality(d4,d2);
    return 0;
}