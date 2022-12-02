//Menu Item class definition
#include "MenuItem.h"
//Constructors

//default constructor
MenuItem::MenuItem()
{
  name = "DefaultName";
  itemCost = 0.0;
  desc = "DefaultDesc";
  addLetter = '\0';
  removeLetter = '\0';
  count = 0;
}

//set everything yourself constructor
MenuItem::MenuItem(std::string s1, double d, std::string s2, char c1, char c2, int i) //set everything yourself
{
  name = s1;
  itemCost = d;
  desc = s2;
  addLetter = c1;
  removeLetter = c2;
  count = i;
}

//Setters
//each of these just take in a single variable to set a private instance variable

void MenuItem::setName(std::string s){ name = s; }
void MenuItem::setItemCost(double d){ itemCost = d; }
void MenuItem::setDesc(std::string s){ desc = s; }
void MenuItem::setAddLetter(char c){ addLetter = c; }
void MenuItem::setRemoveLetter(char c){ removeLetter =c; }
void MenuItem::setCount(int i){ count = i; }

//Getters
//Each of these just returns the value of a private member variable

std::string MenuItem::getName() const { return name; }
double MenuItem::getItemCost() const { return itemCost; }
std::string MenuItem::getDesc() const { return desc; }
char MenuItem::getAddLetter()const{ return addLetter; }
char MenuItem::getRemoveLetter() const { return removeLetter; }
int MenuItem::getCount() const { return count; }

