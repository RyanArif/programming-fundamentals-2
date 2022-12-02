/*
Author: Ryan Arif
Professor: Dr. Tyson McMillan
Date: 12/2/2022
Unit 5 Assignment
*/

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include "Menu.h"
#include "MenuItem.h"

//interesting error: Because I need this header for multiple files, that are also being included or compiled into this program, I get big errors. However, this file, that is to say this scope, does not have the function definitions.
//so, because this is included elsewhere, we won't include it here. But, I still need the function definition for the char I need ot validate (suddently, it works lol)
//#include "Input_Validation_Extended.h"
char validateChar(char &);

void populateMenuItems(std::vector<MenuItem> &);
void printReceipt(Menu &);

int main()
{
  //create a vector of menu items and populate the data
  std::vector<MenuItem> menuItems;
  populateMenuItems(menuItems);

  //create the menu object and put our items into the menu
  Menu m("Big Belly Burger", menuItems);

  //loop through the menu
  do{
    std::cout << "\033[2J\033[1;1H"; //clear screen
    m.showMenu(); //print the menu to the screen
    m.acceptOrder(); //accepts the order

    std::cout << "Take another order? (Y/n)" << std::endl;
    char userChoice = '\0';
    while(true){
      userChoice = validateChar(userChoice);
      userChoice = tolower(userChoice);
      if (userChoice != 'y' && userChoice != 'n'){
        std::cout << "ERROR! Input Y for yes, or N for no." << std::endl;
      }else{
        break; //input validated - leave loop
      }
    }
    if(userChoice == 'y'){
      //reset the menu.
      for(int i = 0; i < menuItems.size(); i++)
      {
        menuItems[i].setCount(0); //reset the count of the itmes
      }
      m.setMenuItems(menuItems); //and then save them into the menu
      continue; //restart the loop
    }else if(userChoice == 'n'){
      break; //leave the loop, done taking orders.
    }
  }while(true); //loop infinitely until the user inputs the character N.

  return 0;
}

//populates the menu with some basic data
void populateMenuItems(std::vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7;
  MenuItem Item1;
  MenuItem Item2;
  MenuItem Item3;
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  std::vector<std::string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"};
  std::vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  std::vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently
    entireMenu[i].setName(defaultMenuNames[i]);
    entireMenu[i].setAddLetter(defaultAddLetters[i]);
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]);
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }
}

