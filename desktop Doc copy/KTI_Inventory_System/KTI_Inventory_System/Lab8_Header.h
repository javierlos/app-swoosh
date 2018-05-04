//From: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
#include <ios>  // Provides ios_base::failure
#include <iostream>  // Provides cin
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
using namespace std;

//Function Prototypes
int validateInt(int &); //use the validation method to vaildate and return a data type integer pass by reference &
double validateDouble(double &); //use the validation method to vaildate and return a data type double pass by reference &
char validateChar(char &); //use the validation method to vaildate and return a data type char pass by reference &
string validateString(string &); //use the validation method to vaildate and return a data type string pass by reference &
//function prototype
void greetings();
void mainCodes();

template <typename T>
T getValidatedInput()
{
    // Get input of type T
    T result;
    cin >> result;
    
    // Check if the failbit has been set, meaning the beginning of the input
    // was not type T. Also make sure the result is the only thing in the input
    // stream, otherwise things like 2b would be a valid int.
    if (cin.fail() || cin.get() != '\n')
    {
        // Set the error state flag back to goodbit. If you need to get the input
        // again (e.g. this is in a while loop), this is essential. Otherwise, the
        // failbit will stay set.
        cin.clear();
        
        // Clear the input stream using and empty while loop.
        while (cin.get() != '\n')
            ;
        
        // Throw an exception. Allows the caller to handle it any way you see fit
        // (exit, ask for input again, etc.)
        throw ios_base::failure("Invalid input.");
    }
    
    return result;
}

//Function Definitions
int validateInt(int &intInput)
{
    while (true)
    {
        
        try
        {
            intInput = getValidatedInput<int>();
        }
        catch (exception e)
        {
            cerr << "Please put numbers with no decimal places" << endl << "Enter the amount of pennies you will be taking to the bank : ";
            continue;
        }
        
        break;
    }
    
    return intInput;
}

double validateDouble(double &doubleInput)
{
    while (true)
    {
        try
        {
            doubleInput = getValidatedInput<double>();
        }
        catch (exception e)
        {
            cerr << e.what() << ": Invalid input."<< endl;
            continue;
        }
        
        break;
    }
    
    return doubleInput;
}

char validateChar(char &charInput)
{
    while (true)
    {
        try
        {
            charInput = getValidatedInput<char>();
        }
        catch (exception e)
        {
            cerr << e.what() << ": Invalid input."<< endl;
            continue;
        }
        
        break;
    }
    
    return charInput;
}

string validateString(string &stringInput)
{
    while (true) //use cin, getline() for this
    {
        
        try
        {
            stringInput  = getValidatedInput<string>();
        }
        catch (exception e)
        {
            cerr << "Please enter your first name: ";
            continue;
        }
        
        break;
    }
    
    return stringInput; 
}

//function defenition
void greetings()
{
    cout << " --- Welcome to the company's paycheck checker. ---\n --- Please Follow the on screen guide. --- \n";
}

void mainCodes()
{
    
    string name;
    int hourWorked = 0;
    double hourlyRate;
    double grossPay;
    double netPay;
    double overTime= hourWorked-40;
    char decision;
    
    cout << "Welcome Please enter your name: ";
    name=validateString(name);
    cout << "Welcome " << name << " How many hours did you work this week: ";
    hourWorked=validateInt(hourWorked);
    
    if (hourWorked > 40) {
        cout << " --- Congrats you worked overtime ---" << "\n\n\n" << "What is your hourly rate: $";
        hourlyRate=validateDouble(hourlyRate);
        double overTime= hourWorked-40;
        grossPay=((overTime*(hourlyRate*2))+hourWorked*hourlyRate);
        cout << "Are you a fulltime worker of part time (fulltime =1 parttime =2): ";
        decision=validateChar(decision);
        
        if (decision == '1')
        {        //FIT               //SS                //Medicare      //dental and retirement
            netPay = grossPay - ((grossPay *.12) + (grossPay * .062) + (grossPay * .0145)+ 35.00 +45.00);
            cout << "This paycheck you will recive $" << netPay << endl;
        }
        else {
            netPay = grossPay - ((grossPay *.12) + (grossPay * .062) + (grossPay * .0145));
            cout << "This paycheck you will recive $" << netPay << endl;
        }
    }
    else if(hourWorked <= 40)
    {
        cout << " --- You did not work overtime ---" << "\n\n\n" << "What is your hourly rate: $";
        hourlyRate=validateDouble(hourlyRate);
        grossPay=(hourWorked-40)*hourlyRate;
        cout << "Are you a fulltime worker of part time (fulltime =1 parttime =2): ";
        decision=validateChar(decision);
        
        if (decision == '1') {        //FIT               //SS                //Medicare      //dental and retirement
            netPay = grossPay - ((grossPay *.12) + (grossPay * .062) + (grossPay * .0145)+ 35.00 +45.00);
            cout << "This paycheck you will recive $" << netPay << endl;
        }
        else {
            netPay = grossPay - ((grossPay *.12) + (grossPay * .062) + (grossPay * .0145));
            cout << "This paycheck you will recive $" << netPay << endl;
        }
    }
}
