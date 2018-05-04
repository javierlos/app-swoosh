//Object Oriented Menu Item Class
//Expanded by Tyson McMillan 11-20-2013
//Expanded by TYPE_YOUR_NAME HERE, TYPE_DATE 
#include <iostream>
using namespace std;

class MenuItem
{
	private:
		string name; 
		char addLetter; 
		char removeLetter; 
		double payUpAmt; 
		int count;
	public:
		void setName(string);
		void setAddLetter(char);
		void setRemoveLetter(char);
		void setPayUpAmt(double); 
		void setCount(int); 
		string getName();
		char getAddLetter() const; //value does not change
		char getRemoveLetter() const; //value does not change
		double getPayUpAmt(); 
		int getCount(); 
};

//Set name assign values to the name member
void MenuItem::setName(string n)
{
	name = n; 
}

void MenuItem::setAddLetter(char al)
{
	addLetter = al; 
}

void MenuItem::setRemoveLetter(char rl)
{
	removeLetter = rl; 
}

void MenuItem::setPayUpAmt(double pua)
{
	payUpAmt = pua; 
}

void MenuItem::setCount(int c)
{
	count = c; 
}

string MenuItem::getName()
{
	return name; 
}

char MenuItem::getAddLetter() const 
{
	return addLetter; 
}

char MenuItem::getRemoveLetter() const 
{
	return removeLetter; 
}

double MenuItem::getPayUpAmt()  
{
	return payUpAmt; 
}

int MenuItem::getCount()  
{
	return count; 
}