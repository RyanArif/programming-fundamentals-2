/*
TO DO: 
Create Sub Menus for the update functions

Update Sub-Menu for the Team Info. 
    create a sub menu just like the otehr ones sound fair? ok sounds good. 
*/
#include "Input_Validation_Extended.h" //input validation
#include <iostream>
#include <string>

#include "Team.h" //team class
#include "Scoreboard.h" //scoreboard class

using namespace std;

//colors!
const string RESET = "\x1b[0m";
const string COLOR_YELLOW = "\x1b[33;1m";
const string COLOR_RED =  "\x1b[31;1m";

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

//update the score
//queries the user asking for some info on to which team to update the score for 
//takes in the scoreboard as a referenced parameter
void updateScore(Scoreboard & sb)
{
    //Ask the user -- H for home, A for away.
    cout << "Update " << COLOR_YELLOW << "(H)" << RESET << "ome or " << COLOR_YELLOW << "(A)" << RESET << "way" << endl;
    char userChoice = '\0';
    Team tempTeam; //temporary team variable, will be used later.
    //Multiple Inifnite Loops: 
    //They validate input. 
    //They are all broken out only when the conditions are met.
    while(true){ 
        userChoice = validateChar(userChoice);
        userChoice = tolower(userChoice);
        if(userChoice != 'h' && userChoice != 'a'){
            cout << COLOR_RED << "ERROR: Choose H for Home and A for Away" << RESET << endl;
        }else if (userChoice == 'h'){
            tempTeam = sb.getHomeTeam(); //copy the home team into the temp team
            break;
        }else if (userChoice == 'a'){
            tempTeam = sb.getAwayTeam(); //copy the away team into the temp team
            break;
        }
    }

    cout << COLOR_YELLOW << "A. " << RESET << "Increase Score" << endl
        << COLOR_YELLOW << "B. " << RESET << "Decrease Score" << endl
        << COLOR_YELLOW << "C. " << RESET << "Set Score" << endl;
    while(true){ //validate input
        userChoice = validateChar(userChoice);
        userChoice = tolower(userChoice);
        if (userChoice != 'a' && userChoice != 'b' && userChoice != 'c'){
            cout << COLOR_RED << "ERROR: Pick a valid option!" << RESET << endl;
        }else{
            break;
        }
    }
    
    
    int temp = 0;
    //ensure the user inputs a positive integer
    //scores generally can't be negative
    //i dunno anything about football, but i'm pretty sure that's true.
    while(true){
        temp = validateInt(temp);
        if (temp < 0){
            cout << COLOR_RED << "ERROR: Pick a positive integer." << RESET << endl;
        }else{
            break; //leave infinite loop
        }
    }

    //A - increase score. B - decrease score. C - set score.
    if(userChoice == 'a'){
       tempTeam.setScore( tempTeam.getScore() + temp );
        
    }else if (userChoice == 'b'){
       tempTeam.setScore(tempTeam.getScore() - temp);
    }else if (userChoice == 'c'){
        temp = validateInt(temp);
        tempTeam.setScore(temp);
    }

    //finally, copy the orignaly copied team back to where it was, but with the updated score.
    if(tempTeam.getHomeStatus()){
        sb.setHomeTeam(tempTeam);
    }else{
        sb.setAwayTeam(tempTeam);
    }

    system("clear"); //get this stuff off the screen and go back to the scoreboard. 
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

//update the game info as a submenu
//modifies the scoreboard private instance variables
void updateGameInfo(Scoreboard &sb)
{
    cout << COLOR_YELLOW << "A. " << RESET << "Update Downs" << endl
        << COLOR_YELLOW << "A. " << RESET << "Update Downs" << endl
        << COLOR_YELLOW << "B. " << RESET << "Update To Go" << endl
        << COLOR_YELLOW << "C. " << RESET << "Update Quarter" << endl
        << COLOR_YELLOW << "D. " << RESET << "Update Possesion" << endl;

    char userChoice = '\0';
    while(true){
        userChoice = validateChar(userChoice);
        userChoice = tolower(userChoice);
        if (userChoice != 'a' && userChoice != 'b' && userChoice != 'c' && userChoice != 'd'){
            cout << COLOR_RED << "ERROR: Pick a valid option." << endl;
        }else{
            break;
        }
    }    
    if(userChoice == 'a'){
        cout << COLOR_YELLOW << "A. " << RESET << "Increase Downs" << endl
            << COLOR_YELLOW << "B. " << RESET << "Decrease Downs" << endl
            << COLOR_YELLOW << "C. " << RESET << "Set Downs" << endl;
        while(true){
            userChoice = validateChar(userChoice);
            userChoice = tolower(userChoice);
            if (userChoice != 'a' && userChoice != 'b' && userChoice != 'c'){
                cout << COLOR_RED << "ERROR: Pick a valid option." << endl;
            }else{
                break;
            }
        }
        int val;
        while(true){
            val = validateInt(val);
            if (val < 0) {
                cout << COLOR_RED << "ERROR: Enter a positive integer!" << endl;
            }else{
                break;
            }
        }
        if(userChoice == 'a'){
            sb.setDown(sb.getDown() + val);
        }else if(userChoice == 'b'){
            sb.setDown(sb.getDown() - val);
        }else if (userChoice == 'c'){
            sb.setDown(val);
        }
        return; //down updated, bye bye. 
            
    }else if(userChoice == 'b'){
        cout << COLOR_YELLOW << "A. " << RESET << "Increase To Go" << endl
            << COLOR_YELLOW << "B. " << RESET << "Decrease To Go" << endl
            << COLOR_YELLOW << "C. " << RESET << "Set To Go" << endl;
        while(true){
            userChoice = validateChar(userChoice);
            userChoice = tolower(userChoice);
            if (userChoice != 'a' && userChoice != 'b' && userChoice != 'c'){
                cout << COLOR_RED << "ERROR: Pick a valid option." << endl;
            }else{
                break;
            }
        }
        int val;
        while(true){
            val = validateInt(val);
            if (val < 0) {
                cout << COLOR_RED << "ERROR: Enter a positive integer!" << endl;
            }else{
                break;
            }
        }
        if(userChoice == 'a'){
            sb.setToGo(sb.getToGo() + val);
        }else if(userChoice == 'b'){
            sb.setToGo(sb.getToGo() - val);
        }else if (userChoice == 'c'){
            sb.setToGo(val);
        }
        return; //to go updated, bye bye. 
            
    }else if(userChoice == 'c'){
        cout << COLOR_YELLOW << "A. " << RESET << "Increase Quarter" << endl
            << COLOR_YELLOW << "B. " << RESET << "Decrease Quarter" << endl
            << COLOR_YELLOW << "C. " << RESET << "Set Quarter" << endl;
        while(true){
            userChoice = validateChar(userChoice);
            userChoice = tolower(userChoice);
            if (userChoice != 'a' && userChoice != 'b' && userChoice != 'c'){
                cout << COLOR_RED << "ERROR: Pick a valid option." << endl;
            }else{
                break;
            }
        }
        int val;
        while(true){
            val = validateInt(val);
            if (val < 0) {
                cout << COLOR_RED << "ERROR: Enter a positive integer!" << endl;
            }else{
                break;
            }
        }
        if(userChoice == 'a'){
            sb.setQtr(sb.getQtr() + val);
        }else if(userChoice == 'b'){
            sb.setQtr(sb.getQtr() - val);
        }else if (userChoice == 'c'){
            sb.setQtr(val);
        }
        return; //quarter updated, bye bye. 
            
    }else if (userChoice == 'd'){
        cout << "Does the Home Team have possesion? " << COLOR_YELLOW << "(Y/n)" << RESET << endl;
        while(true){
            userChoice = validateChar(userChoice);
            if(userChoice != 'y' && userChoice != 'n'){
                cout << COLOR_RED << "ERROR!: SELECT Y FOR YES AND N FOR NO." << RESET << endl;
            }else{
                break;
            }
        }
        if (userChoice =='y'){
            sb.setPosession(true);
        }else if (userChoice == 'n'){
            sb.setPosession(false);
        }
        return; //done!
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
