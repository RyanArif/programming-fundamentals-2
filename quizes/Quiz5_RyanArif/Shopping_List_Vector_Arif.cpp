/*
Assignment: Quiz 5
Student: Ryan Arif
Prof: Dr. Tyson McMillan
Date: 11/29/2022
*/

#include<iostream> //cin, cout
#include<string> //stringz
#include<vector> //vectorz
#include "Input_Validation_Extended.h" //validate input!

void splitCommaString(string, vector<string> &);
void sortShoppingList(vector<string> &);

using namespace std;

int main()
{
  //create a vector of strings
  vector<string> shoppingList;

  cout << "Shopping List!" << endl;
  //query the user for some data
  cout << "Please enter a comma seperated list. Prepend * to an item to mark it as a favorite." << endl;

  string shoppingString = "Error: shoppingString not validated?";
  shoppingString = validateString(shoppingString);

  //break up the string into multiple strings
  splitCommaString(shoppingString, shoppingList);

  //sort the list!
  sortShoppingList(shoppingList);

  //output the new, sorted list!
  cout << "Sorted Shopping List:" << endl;
  for(string item : shoppingList){
    cout << item << endl;
  }

  return 0;
}

//separates a comma separated list into a vector of strings.
//takes in 2 variables: a long, comma seperated string, and a vector to dump it into.
void splitCommaString(string longString, vector<string> & vString)
{
  //loop through the big comma separated list
  for(int i = 0; i < longString.size(); i++)
  {
    //when the end of the loop is reached, add in the last word.
    if(i == longString.size() -1){
      vString.push_back(longString);
    }
    //if there is no comma, skip.
    if(longString.at(i) != ','){
      continue;
    }else{ //once we have found a comma,
      string tempString = longString.substr(0,i); //create a substring from the beginning of the word, to the comma.
      vString.push_back(tempString); //and save it to the list!
      longString = longString.substr(i+1); //then, delete the comma and move onto the next item!
      i = 0;
    }
  }

  //end the list with an END to mark the end of the shopping list.
  vString.push_back("END");
}

//perform a Bubble Sort on the list!
//Takes in a vector<string>, and modifies it (sorts it)
void sortShoppingList(vector<string> & shopList)
{
  //navigate through the list!
  for(int i = shopList.size()-1; i > 0; i--)
  {
    bool didSwap = false; //no swap done yet
    for(int j = 0; j < i; j++)
    {
      //swap the words if they don't start with *, are not END, and the word on the left has a bigger first character (ex: b > a) than the one on the right.
      if((shopList[j].at(0) > shopList[j+1].at(0)) && (shopList[j].at(0) != '*') && (shopList[j] != "END") && (shopList[j+1] != "END")){
        //swap the strings
        string temp = shopList[j];
        shopList[j] = shopList[j+1];
        shopList[j+1] = temp;
        didSwap = true; //record that we swapped
      }
    }
    if(!didSwap){
      break; //didn't swap anything? That means there was nothing to swap, aka the list is sorted!
    }
  }
}

