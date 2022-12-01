//Menu Class Member Functions
#include "Menu.h"

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


