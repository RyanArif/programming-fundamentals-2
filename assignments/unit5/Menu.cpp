//Menu Class Member Functions
#include "Menu.h"
#include<iostream>
#include<iomanip>
#include "Input_Validation_Extended.h"
#include "String_Manipulation.h"

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
  std::cout << menuName << std::endl;
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
  double total = 0.0; //total after tax and tip and everything
  double taxRate = 0.0825; //8.25% sales tax in (most) of Texas
  double tip = 0.0; //if you tip 0 at a restauraunt you go straight to heck

  do{
    std::cout << "\nPlease choose an item (x to Exit): ";
    option = validateChar(option);

    for(int i = 0; i < menuItems.size(); i++)
    {
      if (option == menuItems[i].getAddLetter())
      {
        std::cout << "\n Menu Item " << menuItems[i].getAddLetter() << " selected.";
        menuItems[i].setCount(menuItems[i].getCount() + 1); //increment the count by 1
        std::cout << "\033[2J\033[1;1H"; //clear screen
        std::cout << "\n1 UP on " << menuItems[i].getName() << std::endl;
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
          std::cout << "\n1 DOWN on " << menuItems[i].getName() << std::endl;
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
                std::cout << "\nInvalid input (" << option << "). Please try again." << std::endl;
              }
            }
    }
  }while(option != 'x' && option != 'X');


  std::cout << "\nThank you for placing your order." << std::endl;

  //handle the tip process here
  std::cout << "\nPlease enter a tip (20 percent Gratuity: $" << (subtotal * 0.20) << "): ";
  tip = validateDouble(tip);
  if(tip == 0.0){
    std::cout << "\nYou're actually a dirtbag, get out of my store. Order somewhere else." << std::endl;
    return; //stiffers get sent away in my restaurant.
  }

  //Calculate Total
  total = subtotal + tip + (subtotal * taxRate);
  std::cout << "Subtotal: $" << subtotal << std::endl;
  std::cout << "Tax: $" << (subtotal * taxRate) << std::endl;
  std::cout << "\nTotal: $" << total << std::endl;

  //Accept Payment Type
  std::cout << "Payment Type: Cash or Credit: ";
  string paymentType = "";
  while(true)
  {
    paymentType = validateString(paymentType);
    paymentType = stringToLower(paymentType); //converts the string to all lowercase
    if( (paymentType != "cash" || paymentType != "credit") ){
        std::cout << "ERROR: Please choose Cash or Credit!" << std::endl;
    }else{
      break; //leave the loop, input is valid!
    }
  }
  //note: while it asks the user what to pay with, it literally does nothing. It's empty functionality. I could ask you for a credit card number, but I think that's beyond the scope of what this is asking me to do.


  //handle reciept generation here
}

