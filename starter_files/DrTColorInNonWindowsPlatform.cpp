//Dr_T Color in Non-Windows Platforms ANSI technique 9-1-2019
//source: https://stackoverflow.com/questions/20608058/c-colour-console-text
//using https://en.wikipedia.org/wiki/ANSI_escape_code

#include <iostream>
#include<string>
using namespace std; 

void changeColor(); 

int main()
{
    cout << "\x1b[32;1mHello\x1b[0m\n";
    cout << "\x1b[31;1mBye\x1b[0m\n";
    changeColor();

    return 0; 

}

//Credit McMillanite James Orr for working with Dr_T on this soluton
void changeColor()
{
  string color; 
  string reset = "\x1b[0m";
  
  //Color Variations changing the values before the ; 
  for(int i = 30; i >= 30 && i <= 47; i++)
  {
     color = "\x1b[" + to_string(i) + ";1m";
     cout << "Value  " << color << i << reset << endl;
  }
  cout << endl; 
  
  //Formatting Settings changing the value after the ;
  for(int i = 0; i <= 108; i++)
  {
     if(i <= 7)
     {
      color = "\x1b[" + to_string(32) + ";"+to_string(i)+"m";
      cout << "Settings  " << color << i << reset << endl;
     }

     if(i >= 30 && i <= 47)
     {
      color = "\x1b[" + to_string(32) + ";"+to_string(i)+"m";
      cout << "Settings  " << color << i << reset << endl;
     }

     if(i >= 90 && i <= 108)
     {
      color = "\x1b[" + to_string(32) + ";"+to_string(i)+"m";
      cout << "Settings  " << color << i << reset << endl;
     }
  }

  
}