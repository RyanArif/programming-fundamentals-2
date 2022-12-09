/*
Student: Ryan Arif
Professor: Dr. Tyson McMillan
Date: 12/8/2022
Assignment: Unit 7 - Towers of Hanoi & Recursion

Recursion: to repeat the same steps over and over again. In computer science, it's typically when we call the function within itself.
*/

#include<iostream> //cout
#include "Input_Validation_Extended.h"

using namespace std;

void towerOfHanoi(int, char, char, char);
int factorialR(int);
int getPosInt(int &);

int main()
{
  int userInt = 0;

  cout << "TOWER OF HANOI" << endl;
  cout << "How many discs for your tower: ";
  userInt = getPosInt(userInt);

  //solve the towers of hanoi problem with a 5 disc tower.
  //moves everything from tower A, to tower B, using tower C as the temporary tower stacking place.
  towerOfHanoi(userInt, 'a', 'b', 'c');

  cout << "Factorials!" << endl;
  cout << "What number would you like to know the factorial for: ";
  userInt = getPosInt(userInt);

  cout << userInt << "! = " << factorialR(userInt) << endl;

  return 0;
}

int getPosInt(int & toValidate)
{
  toValidate = validateInt(toValidate); //get validated input
  if(toValidate < 0)
  {
    cout << "ERROR: Enter a positive integer." << endl;
    toValidate = getPosInt(toValidate);
  }

  return toValidate;
}

//moves some disks around some rods to solve the tower of hanoi problem.
//4 parameters: the number of disks to move, the starting tower, the ending tower, and the tertiary or auxilary tower.
//the rules are simple: You can only move one disk at a time. You cannot put a larger disc on top of a smaller disc. Move all the discs to another tower.
void towerOfHanoi(int numDisks, char fromTower, char toTower, char otherTower)
{
  //if there is only one disc, then move the disk.
  if(numDisks == 1)
  {
    cout << "Moved disk " << numDisks << " from tower " << fromTower << " to tower " << toTower << "." << endl;
    return; //done
  }

  //if there are multiple disks, eat the elephant one bite at a time
  //move the disk from the starting tower to the other tower, so we can move the disks around the right way.
  towerOfHanoi(numDisks-1, fromTower, otherTower, toTower);
  cout << "Moved disk " << numDisks << " from tower " << fromTower << " to tower " << toTower << "." << endl;
  //then unpack the auxilary tower and move it to the other tower that the stuff needs to be on.
  towerOfHanoi(numDisks-1, otherTower, toTower, fromTower);
}

//returns the result of the factorial of a given integer
//example: 5! = 5 * 4 * 3 * 2 * 1 = 120
int factorialR(int num)
{
  //edge case: 0! = 1
  if(num == 0)
  {
    return 1;
  }

  if(num == 1) //if we reach the end of the factorial,
  {
    return 1; //return 1
  }else{
    return(num * factorialR(num-1));
    //factorialR(5)
    //5 * factorialR(4)
    //5 * (4 * factorialR(3))
    //5 * (4 * 3 * factorialR(2)....
  }
}

