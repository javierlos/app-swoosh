#include <iostream>
#include "MenuItemClass.h"
#include<conio.h>//for WaitKey() function
#include<windows.h>//dos commands, in particular those for color
#include <fstream>  //for Read/Write objects in C++
using namespace std;

//function to retrieve menu items
double * getMenuPrices()
{
	/* C++ does not advocate to return the address of a local variable to outside of 
	// the function so you would have to define the local variable as static variable.*/
	double cowboysPrice = 3.75;
	double starsPrice = 2.75;
	double rangersPrice= 1.00;
	double mavsPrice = 1.50;
	double untFootballPrice = 1.25;

	static double menuPrices[5] = {cowboysPrice,starsPrice,rangersPrice,mavsPrice,untFootballPrice};
	
	return menuPrices; 	
}

//function to retrieve item counts
int * getItemCounts()
{
	/* C++ does not advocate to return the address of a local variable to outside of 
	// the function so you would have to define the local variable as static variable.*/
	static int itemCounts[5] = {0,0,0,0,0}; //initial values can be changed by user
	
	return itemCounts; 	
}

void setColor(int colorValue)
{
     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //For use of SetConsoleTextAttribute()
     SetConsoleTextAttribute(console, colorValue);
}

void increaseSubtotal(double &subtotal, double amount)
{
   subtotal += amount;
}

void decreaseSubtotal(double &subtotal, double amount)
{
   subtotal -= amount;
}

void showMenu(char userDecision, double &subtotal)
{
	double *menuPrice; //pointer to an item in the menuPrices Array 
	menuPrice = getMenuPrices(); 

	//delcare the instances of the class. 
	MenuItem Cowboys;
	MenuItem Stars;
	MenuItem Rangers;
	MenuItem Mavs;
	MenuItem UNTFootball; 

	int *itemCount; //pointer to an item in the menuPrices Array 
	itemCount = getItemCounts(); 
	
	//**WRITING TO A FILE*****/
  	ofstream receipt_in_html; //object to hold the dynamic HTML Code generated by C++

	//set the counts of the menuItems based upon int main() User parameters
	Cowboys.setCount(itemCount[0]);
	Stars.setCount(itemCount[1]);
	Rangers.setCount(itemCount[2]);
	Mavs.setCount(itemCount[3]);
	UNTFootball.setCount(itemCount[4]);

	//set the Names of the menuItems 
	Cowboys.setName("Cowboys");
	Stars.setName("Stars");
	Rangers.setName("Rangers");
	Mavs.setName("Dallas Mavs");
	UNTFootball.setName("UNT Football"); 

	//set the payUpAmts of the menuItems 
	Cowboys.setPayUpAmt(menuPrice[0]);
	Stars.setPayUpAmt(menuPrice[1]);
	Rangers.setPayUpAmt(menuPrice[2]);
	Mavs.setPayUpAmt(menuPrice[3]);
	UNTFootball.setPayUpAmt(menuPrice[4]);

	//set the addLetters of the menuItems 
	Cowboys.setAddLetter('A');
	Stars.setAddLetter('B');
	Rangers.setAddLetter('C');
	Mavs.setAddLetter('D');
	UNTFootball.setAddLetter('E'); 

	//set the RemoveLetters of the menuItems 
	Cowboys.setRemoveLetter('a');
	Stars.setRemoveLetter('b');
	Rangers.setRemoveLetter('c');
	Mavs.setRemoveLetter('d');
	UNTFootball.setRemoveLetter('e'); 
 
	//Handle ordering of items 				
	if(userDecision == 'A')
	{
		increaseSubtotal(subtotal, Cowboys.getPayUpAmt()); 
	}
	else if(userDecision == 'a')
	{
			
		if(Cowboys.getCount() != 0)
		{
				setColor(33);//Remove Green Indicator
				cout << "1 down on Cowboys." << endl; 
				setColor(7);//standard black and white
		}
		else
		{
				setColor(55);//Error Blue Indicator
				cout << "Cowboys Count is 0, it cannot be removed!!!" << endl; 
				setColor(7);//standard black and white
				
		}
	}

	if(userDecision == 'B')
	{
		increaseSubtotal(subtotal, Stars.getPayUpAmt()); 
	}
	else if(userDecision == 'b')
	{
			
		if(Stars.getCount() != 0)
		{
				setColor(33);//Remove Green Indicator
				cout << "1 down on Stars." << endl; 
				setColor(7); //standard black and white
		}
		else
		{
				setColor(55); //Error Blue Indicator
				cout << "Stars Count is 0, it cannot be removed!!!" << endl; 
				setColor(7);//standard black and white
				
		}
	}

	if(userDecision != 'Y' && userDecision != 'y')
	{
		//show the menu on screen 
		cout << "\t\t\tMY HUMBLE ALLOWANCE" << endl;
		cout << "   Item Name (quantity)" << endl; 
		cout << Cowboys.getAddLetter()<< ")"  << setw(12) << Cowboys.getName() << " (" << Cowboys.getCount() 
				<< " @ $" << Cowboys.getPayUpAmt()  << ")\t" 
				<< "(enter lowercase \""<<Cowboys.getRemoveLetter() << "\", to remove)" << endl; 
		cout << Stars.getAddLetter()<< ")"  << setw(12) << Stars.getName() << " (" << Stars.getCount() 
			<< " @ $" << Stars.getPayUpAmt()  << ")\t" 
			<< "(enter lowercase \""<<Stars.getRemoveLetter() << "\", to remove)" << endl; 
		cout << Rangers.getAddLetter()<< ")"  << setw(12) << Rangers.getName() << " (" << Rangers.getCount() 
			<< " @ $" << Rangers.getPayUpAmt()  << ")\t" 
			<< "(enter lowercase \""<<Rangers.getRemoveLetter() << "\", to remove)" << endl; 
		cout << Mavs.getAddLetter()<< ")" << setw(12) << Mavs.getName() << " (" << Mavs.getCount() 
			<< " @ $" << Mavs.getPayUpAmt()  << ")\t" 
			<< "(enter lowercase \""<<Mavs.getRemoveLetter() << "\", to remove)" << endl; 
		cout << UNTFootball.getAddLetter()<< ")" << setw(12) << UNTFootball.getName() << " (" << UNTFootball.getCount() 
			<< " @ $" << UNTFootball.getPayUpAmt()  << ")\t" 
			<< "(enter lowercase \""<<UNTFootball.getRemoveLetter() << "\", to remove)" << endl; 
	
		setColor(10); //Error Blue Indicator
		cout << "\nCurrent Pay-Up Due, DAD: $" << subtotal; 
		setColor(7); //standard black and white
		cout << ". Make Bank!!!"  << endl; 
	}
		
	if(userDecision == 'Y' || userDecision == 'y')
	{
		//Generate a Receipt in HTML from OO input
		cout << "\nThank you for your order!" << endl;
	   	/* Of course, the student should consider TIP, Total with Tax, and Payment Prior to this step.
		   Such information is vita in order to generate a proper receipt.*/
	   	
		  //Output to an HTML/Webpage file to generate a reciept!!!!
		  //Think about ways to dynamically generate menu items based upon a counter...
		  receipt_in_html.open("receipt.html");
		  if (receipt_in_html.is_open())
		  {
	          receipt_in_html << "<html>\n";
	          receipt_in_html << "    <head>\n";
	          receipt_in_html << "		<title>Time to Pay-up, Dad!!!</title>\n";
	          receipt_in_html << "    </head>\n";
	          receipt_in_html << "    <body style=\"color:#FFFFFF; background-color:#000000\">\n";        
	        	receipt_in_html << "	<p align=\"center\" style=\"color:#000000; background-color:#FFFFFF\">\n";    
	        	receipt_in_html << "			<img src=\"tccd_logo.jpg\" alt=\"TCC_Logo_File\"/>&nbsp;&nbsp;\n";
	              receipt_in_html << "  </p>\n";
	             receipt_in_html << "   <center>\n";
	              receipt_in_html << "          <h1>RECEIPT</h1>\n";
	        	receipt_in_html << "		    <h2> Thank you for my most generous allowance: Time to Pay-up, Dad!!!</h2>\n";
	             receipt_in_html << "           <p> \n";
	            receipt_in_html << "				<br/>\n";
	            receipt_in_html << "				<img src=\"logotyson.png\" alt=\"My Logo\"/>\n<br />";
				receipt_in_html << "				<img src=\"Dr_Tea_Pose.jpg\" width=\"150\" height=\"150\" alt=\"Add a Picture of Your Smiling Face\"/>\n";
	            receipt_in_html << "			</p>\n";
	            receipt_in_html << "			</p>\n";
	            receipt_in_html << "			<p>\n";
	            receipt_in_html << "				This is an HTML paragraph\n";
	            receipt_in_html << "				<br/>\n";
	              receipt_in_html << "          </p>\n";
	        	receipt_in_html << "	</center>\n";
	        	receipt_in_html << "			  <table border=\"1\" width=\"80%\" align=\"center\">\n";
	        		receipt_in_html << "				<tr>\n";
	        		receipt_in_html << "					<th>Menu Item</th>\n";
	        		receipt_in_html << "					<th>Name</th>\n";
					receipt_in_html << "					<th>Wins @ Unit Price</th>\n";
	        		receipt_in_html << "					<th>Cost</th>\n";
	        		receipt_in_html << "				</tr>\n";
				if(Cowboys.getCount()  >= 1)
				{
					receipt_in_html << "				<tr>\n";
	        		receipt_in_html << "					<td width=\"20%\" align=\"center\">" <<  Cowboys.getAddLetter() << "</td>\n";
					receipt_in_html << "					<td width=\"20%\" align=\"center\">" <<  Cowboys.getName()<< "</td>\n";
					receipt_in_html << "					<td width=\"40%\" align=\"center\">" << Cowboys.getCount()<< "@ $" <<  Cowboys.getPayUpAmt() << "</td>\n";
					receipt_in_html << "					<td width=\"20%\" align=\"center\">$" << fixed << setprecision(2) << Cowboys.getCount()*Cowboys.getPayUpAmt() << "</td>\n";
	        		receipt_in_html << "				</tr>\n";
				}
	        	receipt_in_html << "			</table>\n";	
	        	          receipt_in_html << "			<p>\n";
	            receipt_in_html << "							Subtotal: $" << fixed << setprecision(2) << subtotal << "</td>\n";
	            receipt_in_html << "						<br/>\n";
	              receipt_in_html << "          		</p>\n";
	        				
	        receipt_in_html << "	</body>\n";
	        
	        receipt_in_html << "</html> \n";
	            receipt_in_html.close();
	        setColor(12); 
	            cout << "\n Receipt Generated: Opening with your default browser!!!!" << endl;
	        setColor(7);     
	        system("receipt.html");//open the reciept
		}
	}
}
