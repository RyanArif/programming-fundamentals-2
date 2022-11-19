/*
TO DO: 
Create Sub Menus for the update functions

Score: 
    A: Home
    B: Away
        A: Increase
        B: Decrease
            Int: By How Many
        C: Set

Update Game Info: 
    A: Possesion
        A = Home Team, B = Away Team
    B: Down
        - limit to 4 
        A: Increase
        B: Decrease
        C: Set
    C: Quater
        - limit to 4
        A: Increase
        B: Decrease
        C: Set
            Int: Set to/Increase by how many?
*/
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
bool handleInput(Scoreboard &);
void printMainMenu();
void updateScore(Scoreboard &);
void updateGameInfo(Scoreboard &);
void updateTeams(Scoreboard &);
void buildTeams(Scoreboard &, Team&, Team&);
void buildTeam(Team&, bool);

int main()
{
    Team home, away;
    Scoreboard sb(home, away);
    buildTeams(sb, home , away);

    do{
        sb.print(); //print the scoreboard

        printMainMenu(); //print out the main menu        

    }while(handleInput(sb));
    
    return 0;
}

//returns a boolean - true if the menu should be quit, false if it should keep going
bool handleInput(Scoreboard &sb)
{
    char userChoice = '\0';
    while(true){
        userChoice = validateChar(userChoice);
        userChoice = tolower(userChoice);
        if(userChoice != 'a' && userChoice != 'b' && userChoice != 'c' && userChoice != 'e'){
            cout << COLOR_RED << "ERROR: Select Valid Input" << RESET << endl;
        }else {
            break; //leave the infinite loop
        }
    }

    switch (userChoice)
    {
    case 'a' : 
        updateScore(sb);
        return true; //keep the loop going
    case 'b' : 
        updateGameInfo(sb); //update info on the game
        return true;
    case 'c' : 
        updateTeams(sb);
        return true; 
    default:
        return false; //quit the scoreboard
    }    

    return false; // this should be impossible to get to but in case it isn't...
}

// display the main menu
void printMainMenu()
{
    cout << "Main Menu: " << endl
        << COLOR_YELLOW << "A. " << RESET << "Update Score" << endl
        << COLOR_YELLOW << "B. " << RESET << "Update Game Info" << endl
        << COLOR_YELLOW << "C. " << RESET << "Update Team Info" << endl
        << COLOR_YELLOW << "E. " << RESET << "to Exit" << endl;
}

void updateScore(Scoreboard & sb)
{
    cout << "Update " << COLOR_YELLOW << "(H)" << RESET << "ome or " << COLOR_YELLOW << "(A)" << RESET << "way" << endl;
        cout << "NOT IMPLEMENTED LUL" << endl;
}
void updateTeams(Scoreboard & sb)
{
    cout << "Update Team Info:" << endl
        << "Who is the home team?" << endl
        << COLOR_YELLOW << "A. " << RESET << sb.getHomeTeam().getName() << " or " << COLOR_YELLOW << "B. " << RESET << sb.getAwayTeam().getName() << "?" << endl;
        char userChoice = '\0';
        while(true){
            userChoice = validateChar(userChoice);
            userChoice = tolower(userChoice);
            if (userChoice == 'a'){
                cout << "No Change." << endl;
                break;
            }else if (userChoice == 'b'){
                //swap the teams
                Team temp = sb.getHomeTeam();
                sb.setHomeTeam(sb.getAwayTeam());
                sb.setAwayTeam(temp);
                cout << "Home Team Updated." << endl;
                break;
            }else{
                cout << COLOR_RED << "ERROR: INVALID INPUT. CHOOSE A OR B." << endl;
            }
        }

        Team tempHome, tempAway;
        tempHome = sb.getHomeTeam();
        tempAway = sb.getAwayTeam();
        buildTeams(sb, tempHome, tempAway); //might now work, getTeam i think returns a value not the actual like reference to that team.
        sb.setHomeTeam(tempHome);
        sb.setAwayTeam(tempAway);

}

void updateGameInfo(Scoreboard &sb)
{
    cout << "How Many Downs?" << endl;
    int iVal = 0;
    iVal = validateInt(iVal);
    sb.setDown(iVal);
    cout << "How Many To Go?" << endl;
    iVal = validateInt(iVal);
    sb.setToGo(iVal);
    cout << "What Quarter?" << endl;
    iVal = validateInt(iVal);
    sb.setQtr(iVal);
    cout << "Does the Home Team have Possession?" << endl;
    char cVal = '\0';
    while(true){
        cVal = validateChar(cVal);
        cVal = tolower(cVal);
        if( cVal != 'y' && cVal != 'n'){
            cout << COLOR_RED << "ERROR: Select Y for Yes and N for No." << RESET << endl;
        }
        if(cVal == 'y'){
            sb.setPosession(true);
        }else if (cVal == 'n'){
            sb.setPosession(false);
        }
    }

}

void buildTeams(Scoreboard & sb, Team& home, Team& away)
{

    cout << "Enter the Home Team's Information." << endl;
    buildTeam(home, true); //build the home team up
    cout << "Enter the Away Team's Information" << endl;
    buildTeam(away, false); //build up the away team

    system("clear"); //clear the screen, and move on to displaying the scoreboard

    sb.setHomeTeam(home);
    sb.setAwayTeam(away);
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
