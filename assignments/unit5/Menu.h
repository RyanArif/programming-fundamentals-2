//Menu Class
#ifndef MENU_H
#define MENU_H

#include<vector>
#include<string>
#include "MenuItem.h"

class Menu : protected MenuItem
{
  private:
    std::string menuName;
    std::vector<MenuItem> menuItems;
    int totalItems; //not accessible outside of this class. It isn't necessary, at all. Setters/Getters not required.
  public:
    //constructors
    Menu(); //default
    Menu(std::string, std::vector<MenuItem>);
    //setters
    void setMenuName(std::string);
    void setMenuItems(std::vector<MenuItem>);
    //getters
    std::string getMenuName() const;
    std::vector<MenuItem> getMenuItems() const;
    //other really cool FUNctions!
    void showMenu(); //prints the menu
};

#endif

