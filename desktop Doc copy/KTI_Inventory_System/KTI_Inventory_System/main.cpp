//
//  main.cpp
//  KTI_Inventory_System
//
//  Created by javier salgado on 2/14/17.
//  Copyright © 2017 javier salgado. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "Lab8_Header.h"
using namespace std;

void ktInventory();
void ktiMainmenu();
void maxInventory();
void inventType();
int main()
{
    char decisionOne = '\0';
    cout << fixed << setprecision(2);
    
    
    ktInventory();
    ktiMainmenu();
    decisionOne=validateChar(decisionOne);
    
    while(decisionOne != 'y' && decisionOne != 'Y')
    {
        ktInventory();
        ktiMainmenu();
        decisionOne=validateChar(decisionOne);
        if (cin.fail()) // to remove infinite loop when alphabet character is pressed
        {
            cin.clear();
            cin.ignore(100,'\n');
        }
    
        if (decisionOne == '1') {
            ktInventory();
            maxInventory();
            cout << endl;
            ktiMainmenu();
            decisionOne=validateChar(decisionOne);
        
        }
        else if (decisionOne =='2'){
            ktInventory();
            inventType();
        }
        else
        {
            cout << "thank you come again" << endl << endl;
        }
    }
    return 0;
}

void ktInventory()//function used in the beginning of a new paige
{
    cout << " *******************************************************************" << endl;
    cout << "                  KTI Inventory Management System" << endl;
    cout << " *******************************************************************" << endl << endl << endl;
}

void ktiMainmenu()
{
    cout << " *-* Main Menu *-*" << endl;
    cout << " 1) check max inventory\n 2)Create an P.O.\n\nEnter decision: ";
}

void maxInventory()//checking the ammount of material should have total
{
    int material[7] = {15,25,25,30,20,35,15};
    cout << " --- Check Max Inventory ---\n";
    cout << "1/4 MDF                   "<< material[0] << "\n1/4 Red Oak 61s           " << material[1] << "\n1/4 Red Oak 62s           "<< material[2] << "\n1/4 White Oak 61s         " << material[3] << "\n1/4 White Oak 61s         " << material[4] << "\n1/4 Rift White Oak 61s    " << material[5] << "\n1/4 Rift White Oak 61s    " << material[5]<< endl;
}

void inventType()
{
    char decisionInvent;
    int materialUse;
    string materialS[8] = {"","1/4 MDF","1/4 Red Oak G1s","1/4 Red Oak G2s","1/4 White Oak G1s", "1/4 White Oak G2s", "1/4 Rift White Oak G1s", "1/4 Rift White Oak G2s"};
    double materialCost[8] ={0,76,85,77,49,81,65,90};
    cout << " *** Create a P.O. ***\n";
    cout << " --- Choose from the following materials --- \n0 For all of the following";
    
    for (int a = 0; a < 8; a++) {
        cout << a << " " << materialS[a] << endl;
    }
    cout << "Your answer: ";
    decisionInvent=validateChar(decisionInvent);
    cout << "How much material did you use: ";
    materialUse=validateInt(materialUse);
    
    if(decisionInvent == '0')//shows the cost of all of the materials
    {
        cout << endl << endl;
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[1] << "                    " << materialUse << "                     $" << materialCost[1] << "                  $" << ((materialCost[1]*materialUse)*.0825) <<"                 $"<< ((materialCost[1]*materialUse)+(materialCost[1]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[2] << "            " << materialUse << "                     $" << materialCost[2] << "                  $" << ((materialCost[2]*materialUse)*.0825) <<"                 $"<< ((materialCost[2]*materialUse)+(materialCost[2]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[3] << "            " << materialUse << "                     $" << materialCost[3] << "                  $" << ((materialCost[3]*materialUse)*.0825) <<"                 $"<< ((materialCost[2]*materialUse)+(materialCost[3]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[4] << "          " << materialUse << "                     $" << materialCost[4] << "                  $" << ((materialCost[4]*materialUse)*.0825) <<"                 $"<< ((materialCost[4]*materialUse)+(materialCost[4]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[5] << "          " << materialUse << "                     $" << materialCost[5] << "                  $" << ((materialCost[5]*materialUse)*.0825) <<"                 $"<< ((materialCost[5]*materialUse)+(materialCost[5]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[6] << "     " << materialUse << "                     $" << materialCost[6] << "                  $" << ((materialCost[6]*materialUse)*.0825) <<"                 $"<< ((materialCost[6]*materialUse)+(materialCost[6]*materialUse)*.0825) <<endl;
        cout << "   " << materialS[7] << "     " << materialUse << "                     $" << materialCost[7] << "                  $" << ((materialCost[7]*materialUse)*.0825) <<"                 $"<< ((materialCost[7]*materialUse)+(materialCost[7]*materialUse)*.0825) <<endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "total cost $" << ((materialCost[1]*materialUse)+(materialCost[1]*materialUse)*.0825)+((materialCost[2]*materialUse)+(materialCost[2]*materialUse)*.0825)+((materialCost[2]*materialUse)+(materialCost[3]*materialUse)*.0825)+((materialCost[4]*materialUse)+(materialCost[4]*materialUse)*.0825)+((materialCost[5]*materialUse)+(materialCost[5]*materialUse)*.0825)+((materialCost[6]*materialUse)+(materialCost[6]*materialUse)*.0825)+((materialCost[7]*materialUse)+(materialCost[7]*materialUse)*.0825) << endl;
        
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '1')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[1] << "               " << materialUse << "                     $" << materialCost[1] << "                  $" << ((materialCost[1]*materialUse)*.0825) <<"                 $"<< ((materialCost[1]*materialUse)+(materialCost[1]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '2')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[2] << "            " << materialUse << "                     $" << materialCost[2] << "                  $" << ((materialCost[3]*materialUse)*.0825) <<"                 $"<< ((materialCost[2]*materialUse)+(materialCost[2]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '3')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[3] << "            " << materialUse << "                     $" << materialCost[3] << "                  $" << ((materialCost[3]*materialUse)*.0825) <<"                 $"<< ((materialCost[2]*materialUse)+(materialCost[3]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '4')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[4] << "          " << materialUse << "                     $" << materialCost[4] << "                  $" << ((materialCost[4]*materialUse)*.0825) <<"                 $"<< ((materialCost[4]*materialUse)+(materialCost[4]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '5')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[5] << "          " << materialUse << "                     $" << materialCost[5] << "                  $" << ((materialCost[5]*materialUse)*.0825) <<"                 $"<< ((materialCost[5]*materialUse)+(materialCost[5]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '6')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[6] << "     " << materialUse << "                     $" << materialCost[6] << "                  $" << ((materialCost[6]*materialUse)*.0825) <<"                 $"<< ((materialCost[6]*materialUse)+(materialCost[6]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if (decisionInvent == '7')
    {
        cout << "   Name                     Ammount                in cost                  Tax                total cost    " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "   " << materialS[7] << "     " << materialUse << "                     $" << materialCost[7] << "                  $" << ((materialCost[7]*materialUse)*.0825) <<"                 $"<< ((materialCost[7]*materialUse)+(materialCost[7]*materialUse)*.0825) <<endl;
        decisionInvent=validateChar(decisionInvent);
    }
    else if(decisionInvent < 7 || decisionInvent > 1)
    {
        cout << "Pick from the following options: ";
    }
}
