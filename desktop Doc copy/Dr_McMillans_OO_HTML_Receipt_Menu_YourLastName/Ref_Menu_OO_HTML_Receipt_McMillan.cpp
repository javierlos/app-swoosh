/* 
 //Object Oriented Menu
//Expanded by Dr. Tyson McMillan 11-20-2013, 3-29-2014, 10-04-2015
//Expanded by TYPE_YOUR_NAME HERE (all Team Memers), TYPE_DATE
 APP/CPP/FOLDER: Ref_Menu_OO_HTML_Receipt_YourLastName
This program keeps track of allowance that your dad will pay you.
For each win of his favorite team, dad awards you a certain amount.
This program is designed to help you help dad pay the correct amount to you. 
 

//Menu Item A and B has been solved for you.
//the program also accepts and validates Savings Amount

In this code, you need to be aware of 3 primary files driving the program (do NOT change the names of these files!!!):
    Ref_Menu_OO_HTML_Receipt_McMillan.cpp
    MenuFunctions.h 
    MenuItemClass.h

EXPAND THIS CODE TO: 
	Add and Remove Menu Items C, D, and E on the menu. 
		//Generate an HTML Reciept for each team win above 0
        //show the committed savings amount on the receipts as well.
        //Design the receipt as you choose for dad to be pround to pay up your allowance. 
        //Get the program to loop again to start over, resetting all needed values.
        
 Additionally, the program expands our knowledge by 
 showing students how to generate a dynamic HTML Reciept. 
 
 Also the item expands our knowledge by adding
 Object Oriented Classes to the mix. 
 
 Study how loops and arrays work so well together. 
 This program also uses pointers to array values.
 Such a method help us to avoid using global variables.

  Expanded by: Dr. Tyson McMillan, 10-04-2015
  Student: 
 
 A menu using the Power of functions that pass values by reference.
 Arrays and Object Oriented Coding as play a role. 
 When a function uses pass by refrence, it can manipulate variable values outside
 of its own scope. Reference refers to the memory location of the variable.
 
 */
#include <iostream>
#include <cstdlib> //to be able to use system("cls"); in multiple platforms
#include<windows.h>//for using various dos commands and color
#include<conio.h>//for using color and/or "Sleep" command
#include<string>
#include<iomanip>//setw and setprecison
#include "Input_Validation.h" //input validation header
#include <fstream>  //for Read/Write objects in C++
#include "MenuFunctions.h" //functions that add 
using namespace std;

// Function prototypes
void displayMenu(); 

int main()
{
   displayMenu(); //function call
   	   
   return 0;
}

void displayMenu()
{
   	
	char decision = '\0'; //hold the decision of the user 
	double saveAmount = 0.0;
	double tenderAmount = 0.0;
	double suggestedSaveAmount = 0.0; //subtotal * .20 (20%)

	double *menuPrice; //pointer to an item in the menuPrices Array 
	menuPrice = getMenuPrices(); 

	int *itemCountMain; //pointer to an item in the menuPrices Array 
	itemCountMain = getItemCounts(); 

	double subtotalMain = 0.0; 
	
	//Set precision fixed to 2 decimals in program 
	cout << fixed; 
	cout << setprecision(2); 

 	//show the initial menu to user parameters at this time
	showMenu(decision,subtotalMain);

	do
	{
		//validate input of the decisoin variable
		while (true)
		{
			cout << "\nPlease choose a menu item; capital letter to order (y to exit): "; 
			try
			{
				decision = getValidatedInput<char>();
			}
			catch (exception e)
			{
				setColor(10);
				cerr << "Invalid input: Please Enter Menu items (A-F, Y).";
				setColor(7);
				continue;
			}
			
			break; 
		}
		
		if(decision == 'A')
		{
			system("cls");  //clear the screen 
			itemCountMain[0]++; //Add 1 to count for Cowboys
			showMenu(decision,subtotalMain);
		}
		else if(decision == 'a')
		{
			system("cls");  //clear the screen 
			if(itemCountMain[0] != 0)
			{
				itemCountMain[0]--; //remove 1 from count for Cowboys if not at 0
				decreaseSubtotal(subtotalMain, menuPrice[0]);//subtract payUpAmt of Cowboys from the subTotal
				showMenu(decision,subtotalMain);
			}
			else			
			{
				showMenu(decision,subtotalMain);
			}
		}

		if(decision == 'B')
		{
			system("cls");  //clear the screen 
			itemCountMain[1]++; //Add 1 to count for Stars
			showMenu(decision,subtotalMain);
		}
		else if(decision == 'b')
		{
			system("cls");  //clear the screen 
			if(itemCountMain[1] != 0)
			{
				itemCountMain[1]--; //remove 1 from count for Cowboys if not at 0
				decreaseSubtotal(subtotalMain, menuPrice[1]); //subtract payUpAmt of Stars from the subTotal
				showMenu(decision,subtotalMain);
			}
			else			
			{
				showMenu(decision,subtotalMain);
			}
		}


		//Tell user when an invalid input has been entered
		if(
			(decision != 'a') && (decision != 'A') && 
			(decision != 'b') && (decision != 'B') && 
			(decision != 'y') && (decision != 'Y') && 
			(decision != '\0')
		  )
		{
				system("cls");
				setColor(55);//Error Blue Indicator
				cout << "Invalid input: (\""<< decision <<"\") please choose an item on the menu." << endl; 
				setColor(7);//standard black and white
				showMenu(decision,subtotalMain);
		}

	}while(decision != 'y' && decision != 'Y'); 
 
	//Accept input from the user for Savings Amount 

	suggestedSaveAmount = subtotalMain * .20; 
	
	while (true)
	{
		cout << "\nEnter a Save Amount (suggested at 20% = $" << suggestedSaveAmount << "):$";

		try
		{
			saveAmount = getValidatedInput<double>();
		}
		catch (exception e)
		{
			setColor(10);
			cerr << "Invalid input: Please Try again."<< endl;
			setColor(7);
			continue;
		}

		//ensure tip amount is positive
		if(saveAmount < 0)
		{
			cout << "\nPlease enter tip amount greather than or equal to 0.";
		}
		else
		{
			break;
		}
	}

	cout << "Dad, I commit to Save, You entered: $" << saveAmount << endl;   
	
	showMenu(decision,subtotalMain);//to show receipt
   	
  
}
