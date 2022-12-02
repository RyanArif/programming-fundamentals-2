//Menu Class Member Functions
#include "Menu.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include "Input_Validation_Extended.h"
#include "String_Manipulation.h"


//colors
const std::string ANSI_RESET = "\x1b[0m"; //reset the ansi color codez
const std::string ANSI_BLUE = "\x1b[36;1m";
const std::string ANSI_RED = "\x1b[31;1m";

std::string ANSI_GREEN = "\x1b[32;1m";
Menu::Menu()
{
  menuName = "DefaultName";
  MenuItem tempItem;
  std::vector<MenuItem> tempVector = {tempItem};
  menuItems = tempVector;
}

Menu::Menu(std::string s, std::vector<MenuItem> v)
{
  menuName = s;
  menuItems = v;
}

//setters!
void Menu::setMenuName(std::string s){ menuName = s; }
void Menu::setMenuItems(std::vector<MenuItem> v){ menuItems = v; }
//getters!
std::string Menu::getMenuName() const { return menuName; }
std::vector<MenuItem> Menu::getMenuItems() const { return menuItems; }

//prints the menu
void Menu::showMenu()
{
  std::cout << std::fixed << std::setprecision(2); //set doubles to 2 decimal places
  std::cout << ANSI_BLUE << menuName << ANSI_RESET << std::endl;
  std::cout << "ADD \tNAME \t COST \tREMOVE\tCOUNT\tDESC" << std::endl;

  for(int i = 0; i < menuItems.size(); i++)
  {
    std::cout << menuItems[i].getAddLetter() << ")" << std::setw(10) << menuItems[i].getName() << std::setw(5) << "$" << menuItems[i].getItemCost() << std::setw(5) << "(" << menuItems[i].getRemoveLetter() << std::setw(7) << menuItems[i].getCount() << std::setw(13) << menuItems[i].getDesc() << std::endl;
  }
}

//accepts the order from the user of the program
void Menu::acceptOrder()
{
  char option = '\0';
  double subtotal = 0.0;
  double tip = 0.0;
  double total = 0.0; //total after tax and tip and everything
  std::string paymentType = ""; //the payment type the user makes
  double tender = 0.0; //the amount of money the user is actually inputting.


  do{
    std::cout << ANSI_GREEN << "\nPlease choose an item (x to Exit): " << ANSI_RESET;
    option = validateChar(option);

    for(int i = 0; i < menuItems.size(); i++)
    {
      if (option == menuItems[i].getAddLetter())
      {
        std::cout << "\n Menu Item " << menuItems[i].getAddLetter() << " selected.";
        menuItems[i].setCount(menuItems[i].getCount() + 1); //increment the count by 1
        std::cout << "\033[2J\033[1;1H"; //clear screen
        std::cout << ANSI_GREEN << "\n1 UP on " << menuItems[i].getName() << ANSI_RESET << std::endl;
        subtotal += menuItems[i].getItemCost(); //increment subtotal by the cost of the item
        showMenu(); //show the menu
        std::cout << "\nSubtotal: $" << subtotal << std::endl;
      }
      else if(option == menuItems[i].getRemoveLetter())
      {
        std::cout << "\nRemove Item " << menuItems[i].getRemoveLetter() << " selected.";
        if(menuItems[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          menuItems[i].setCount(menuItems[i].getCount() - 1); //decrement the count by 1
          std::cout << "\033[2J\033[1;1H"; //clear screen
          std::cout << ANSI_RED << "\n1 DOWN on " << menuItems[i].getName() << ANSI_RESET << std::endl;
          subtotal -= menuItems[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(); //show the updated menu
          std::cout << "\nSubtotal: $" << subtotal << std::endl;
        }
        else //the the user why you blocked item removal
        {
            std::cout << "\nItem count must be > 0 to remove: " << menuItems[i].getName() << endl;
        }
      }
      else if(
                option != menuItems[i].getAddLetter() &&
                option != menuItems[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X'
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                std::cout << ANSI_RED << "\nInvalid input (" << option << "). Please try again." << ANSI_RESET << std::endl;
              }
            }
    }
  }while(option != 'x' && option != 'X');


  //check if the user actually input anything
  bool didOrder = false;
  for(int i = 0; i < menuItems.size(); i++)
  {
    if (menuItems[i].getCount() > 0)
    {
      didOrder = true;
      break; //they ordered, no need to make any more comparisons.
    }
  }

  if(!didOrder) //if you did not order...
  {
    std::cout << ANSI_RED << "\n Ok cool story bro, get out of the way for the paying customers.\n" << ANSI_RESET << std::endl;
    return; //stop the process.
  }

  std::cout << "\nThank you for placing your order." << std::endl;

  //handle the tip process here
  std::cout << "\nPlease enter a tip" << ANSI_GREEN << " (20 percent Gratuity: $" << (subtotal * 0.20) << ")" << ANSI_RESET << ": ";
  tip = validateDouble(tip);
  if(tip == 0.0){
    std::cout << ANSI_RED << "\nYou're actually a dirtbag, get out of my store. Order somewhere else." << std::endl << ANSI_RESET;
    return; //stiffers get sent away in my restaurant.
  }

  //Calculate Total
  total = subtotal + tip + (subtotal * taxRate);
  std::cout << "Subtotal: $" << subtotal << std::endl;
  std::cout << "Tax: $" << (subtotal * taxRate) << std::endl;
  std::cout << "Tip: $" << tip << std::endl;
  std::cout << ANSI_BLUE << "\nTotal: $" << total << std::endl << ANSI_RESET;

  //Accept Payment Type
  std::cout << "Payment Type: Cash or Credit: ";
  while(true)
  {
    paymentType = validateString(paymentType);
    paymentType = stringToLower(paymentType); //converts the string to all lowercase
    if( (paymentType != "cash" && paymentType != "credit") ){
        std::cout << ANSI_RED << "ERROR: Please choose Cash or Credit!" << std::endl << ANSI_RESET;
    }else{
      break; //leave the loop, input is valid!
    }
  }
  //note: while it asks the user what to pay with, it literally does nothing. It's empty functionality. I could ask you for a credit card number, but I think that's beyond the scope of what this is asking me to do.

  //Accept tender amount from user, if cash:
  if(paymentType == "cash"){
    std::cout << "Please Insert Tender: ";
    tender = validateDouble(tender);
    if(tender < total){
      std::cout << ANSI_RED << "Nice try, come back when you've got the scratch." << std::endl << ANSI_RESET;
      return; //sorry, only paying customers allowed!
    }else if(tender < 0) { //if the tender is negative...
      std::cout << ANSI_RED << "Nice try, bucko. You ain't robbing me today. This is Texas..." << std::endl << ANSI_RESET;
      return; //robbers go bye bye
    }else if(tender > total){
    std::cout << "Your change is: " << ANSI_GREEN << "$" << tender - total << std::endl << ANSI_RESET;
    }
  }else if(paymentType == "credit"){ //or just process the pretend credit card
    std::cout << ANSI_BLUE << "Pretend Credit Card Processor go brrrrrrrr" << std::endl << ANSI_RESET;
  }

  printReceipt(subtotal, tip, total, paymentType, tender);

}

//Input: the subtotal, tip, total, payment type, and tender (required, but it'll be 0 if it's credit), so it isn't calculated twice.
//Process & Output: Outputs to the file for the receipt
void Menu::printReceipt(double subtotal, double tip, double total, std::string paymentType, double tender)
{
  std::ofstream outfile;
  outfile.open("receipt.txt");
  outfile << std::fixed << std::setprecision(2); //set doubles to 2 decimal places
  outfile << "*** RECEIPT ***" << std::endl;
  outfile << menuName << std::endl;

  //print the items selected
  for(int i = 0; i < menuItems.size(); i++)
  {
    if(menuItems[i].getCount() > 0)
    {
      outfile << menuItems[i].getCount() << " " << menuItems[i].getName() << " @ " << menuItems[i].getItemCost() << std::endl;
    }
  }

  //print out the totals
  outfile << "Subtotal: $" << subtotal << std::endl
    << "Tax: $" << (subtotal * taxRate) << std::endl
    << "Tip: $" << tip << std::endl
    << "Total: $" << total << std::endl << std::endl;

  //print out the payment info
  outfile << "Payment Method: " << paymentType << std::endl;
  if (paymentType == "cash")
  {
    outfile << "Cash Recieved: $" << tender << std::endl
      << "Change: $" << tender - total << std::endl; //tender - total > 0 verified outside of this because lol
  }else{
    outfile << "Credit Card Info Concealed for Privacy!" << std::endl;
  }

  std::cout << "\nReceipt saved to receipt.txt\n" << std::endl;

}

