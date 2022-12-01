//Menu Class Member Functions
#include "Menu.h"
#include<iostream>
#include<iomanip>

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
