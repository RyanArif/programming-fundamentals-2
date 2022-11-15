#include "Scoreboard.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std; 

//mutator functions
void Scoreboard::setHomeTeam(Team t){ homeTeam = t;}
void Scoreboard::setAwayTeam(Team t){ awayTeam = t;}
void Scoreboard::setQtr(int i){ qtr = i;}
void Scoreboard::setDown(int i){ down = i;}
void Scoreboard::setToGo(int i){ toGo = i;}
void Scoreboard::setPosession(bool b){ possession = b; }

//accessor functions
Team Scoreboard::getHomeTeam() const { return homeTeam; }
Team Scoreboard::getAwayTeam() const { return awayTeam; }
int Scoreboard::getQtr() const { return qtr; }
int Scoreboard::getDown() const {return down;}
int Scoreboard::getToGo() const {return toGo;}
bool Scoreboard::getPossession() const {return possession;}

//prints the scoreboard
void Scoreboard::print()
{
    int columnOne = 10;
    int columnTwo = 1;
    int columnThree = 5;
    int columnFour = 1;
    int columnFive = 10;

    for(int i = 0; i < 35; i++){
        cout << "*";
    }
    cout << endl;

    //layout of the scoreboard
    cout << setw(columnOne) << "Home" << setw(columnTwo) << " " << setw(columnThree) << "Qtr" << setw(columnFour) << " " << setw(columnFive) << "Away" << endl;
    
    //set up home & away names & home ball possession
    cout << setw(columnOne) << homeTeam.getName() << setw(columnTwo);
    if (possession){
        cout << "*";
    }else{
        cout << " ";
    }
    cout << setw(columnThree) << qtr << setw(columnFour);
    if (possession){
        cout << " ";
    }else{
        cout << "*";
    }
    cout << setw(columnFive) << awayTeam.getName() << endl;

    //display coach names
    cout << setw(columnOne) << homeTeam.getCoachName() << setw(columnTwo) << " " << setw(columnThree) << " " << setw(columnFour) << " " << setw(columnFive) << awayTeam.getCoachName() << endl;

    cout << setw(columnOne) << "Downs:" << down << setw(columnTwo) << " " << setw(columnThree) << "" << setw(columnFour) << " " << setw(columnFive) << "To Go: " << toGo << endl;

    for (int i = 0; i< 35; i++){
        cout << "*";
    }

}


