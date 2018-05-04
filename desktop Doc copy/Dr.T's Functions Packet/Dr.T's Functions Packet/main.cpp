//
//  main.cpp
//  Dr.T's Functions Packet
//
//  Created by javier salgado on 2/8/17.
//  Copyright © 2017 javier salgado. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
using namespace std;

void welcomeMessage();
double calcNetPay(double,double,string, int);

int main(int argc, const char * argv[]) {
   
    welcomeMessage();
    cout << calcNetPay(32.5, 100.25, "Tyson", 1) << endl;
    cout << calcNetPay(55, 600.54, "Salgado", 1) << endl;
    
    return 0;
}
void welcomeMessage()
{
    cout << "Money in the Bank" << endl;
    cout << "WHAAAAAT!!!" << endl;
}

double calcNetPay(double hours, double rate, string name, int empType)
{
    cout << fixed;
    double grossPay = 0.0;
    double netPay = 0.0;
    double overTimeHours= 40.0;
    int nameLenth = name.length();
    int startingPoint = 240
    locale loc;
}
