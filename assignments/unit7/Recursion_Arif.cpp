/*
Student: Ryan Arif
Professor: Dr. Tyson McMillan
Date: 12/8/2022
Assignment: Unit 7 - Towers of Hanoi & Recursion

Recursion: to repeat the same steps over and over again. In computer science, it's typically when we call the function within itself.
*/

#include<iostream> //cout

using namespace std;

void towerOfHanoi(int, char, char, char);

int main()
{
  //solve the towers of hanoi problem with a 5 disc tower.
  //moves everything from tower A, to tower B, using tower C as the temporary tower stacking place.
  towerOfHanoi(5, 'a', 'b', 'c');

  return 0;
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

