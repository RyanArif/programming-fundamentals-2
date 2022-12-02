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
  double taxRate = 0.0825;
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
    void acceptOrder(); //accepts an order from da user
    void printReceipt(double subtotal, double tip, double total, std::string paymentType, double tender);
};

#endif

