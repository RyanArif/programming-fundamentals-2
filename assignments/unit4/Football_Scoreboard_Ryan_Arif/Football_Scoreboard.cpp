#include "Input_Validation_Extended.h" //input validation
#include <iostream>
#include <string>

#include "Team.h" //team class
#include "Scoreboard.h" //scoreboard class

using namespace std;

string RESET = "";
string COLOR_YELLOW = "";
string COLOR_RED = "";

//function prototypes
bool shouldExitMenu();
void printMainMenu();
void buildTeam(Team&, bool);

int main()
{
    Team home, away;

    cout << "Enter the Home Team's Information." << endl;
    buildTeam(home, true); //build the home team up
    cout << "Enter the Away Team's Information" << endl;
    buildTeam(away, false); //build up the away team

    system("clear"); //clear the screen, and move on to displaying the scoreboard

    Scoreboard sb = Scoreboard(home, away);

    do{
        sb.print(); //print the scoreboard

        printMainMenu(); //print out the main menu      
        

    }while(!shouldExitMenu());
    
    return 0;
}

//returns a boolean - true if the menu should be quit, false if it should keep going
bool shouldExitMenu()
{
    cout << "Exit Menu? " << COLOR_YELLOW << "(y/n)" << RESET << endl;
    char userChoice = '\0';
    while(true){
        userChoice = validateChar(userChoice);
        userChoice = tolower(userChoice);
        if(userChoice != 'y' && userChoice != 'n'){
            cout << COLOR_RED << "ERROR: Must select Y or N." << RESET << endl;
        }else{
            break; //leave the infinite loop
        }
    }
    if(userChoice == 'y'){
        return true;
    }else if(userChoice == 'n'){
        return false;
    }

    return false; // this should be impossible to get to but in case it isn't...
}

// display the main menu
void printMainMenu()
{
    cout << "Main Menu: " << endl
        << COLOR_YELLOW << "A. " << RESET << "Update Score" << endl
        << COLOR_YELLOW << "B. " << RESET << "Update Team Names" << endl
        << COLOR_YELLOW << "C. " << RESET << "Update Coach Names" << endl
        << COLOR_YELLOW << "D. " << RESET << "Update City" << endl
        << COLOR_YELLOW << "E. " << RESET << "Update Possession" << endl
        << COLOR_YELLOW << "F. " << RESET << "Update Downs" << endl
        << COLOR_YELLOW << "G. " << RESET << "Update To Go" << endl;
}


//prompt the user on building the team. Gets all of the data, and modifies the team to hold the info.
void buildTeam(Team &team, bool b)
{
    string val;

    cout << "What is the name of the city?" << endl;
    val = validateString(val);
    team.setCity(val); 

    cout << "What is the name of the team?" << endl;
    val = validateString(val);
    team.setName(val);

    cout << "What is the name of the coach?" << endl;
    val = validateString(val);
    team.setCoachName(val);

    team.setHomeStatus(b);

}
