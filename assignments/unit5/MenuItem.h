//Menu Item Class
#ifndef MENUITEM_H
#define MENUITEM_H
#include<string>

class MenuItem
{
  private:
    std::string name;
    double itemCost;
    std::string desc;
    char addLetter;
    char removeLetter;
    int count;
  public:
    //Constructors
    MenuItem(); //default
    MenuItem(std::string, double, std::string, char, char, int); //set everything yourself
    //setters
    void setName(std::string);
    void setItemCost(double);
    void setDesc(std::string);
    void setAddLetter(char);
    void setRemoveLetter(char);
    void setCount(int);
    //getters
    std::string getName() const;
    double getItemCost() const;
    std::string getDesc() const;
    char getAddLetter() const;
    char getRemoveLetter() const;
    int getCount() const;
};

#endif

