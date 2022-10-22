/**
 * Student: Ryan Arif
 * Professor: Dr. Tyson McMillan
 * Class: 2022FL COSC-1437-58001
 * Date Completed: lol it's not done yet
**/

//#include <iostream> //already included with input validation
//#include <string> //already included with input validation
#include "./Input_Validation_Extended.h"

//using namespace std; //already part of input validation

//GLOBAL VARIABLES
//floating point precision 
const int PRECISION = 4;
//text formatting
const string RESET = "\x1b[0m"; //reset formatting
const string COLORS[6] = {
    "\x1b[31;1m", //red bold
    "\x1b[32;1m", //green bold
    "\x1b[33;1m", //yellow bold
    "\x1b[34;1m", //indigo bold
    "\x1b[35;1m", //purple bold
    "\x1b[36;1m" //light blue bold
};

//menu options and, if exists, corresponding menu options 
//always leave motion at the bottom. 
//doing it this way means we could add as many *simple* physics operations as possible
//without having to re-code the whole thing.
//ALWAYS LOWERCASE. ALWAYS ONE WORD.
const string OPERATIONS[6] = {
    "velocity",
    "acceleration",
    "nsl",
    "weight",
    "momentum",
    "motion" //leave at the end! This should ALWAYS be last.
};
//motion will be handeled separately. 
//FORMAT SHOULD ALWAYS FOLLOW: 
//SOMETHING = SOMETHING */ SOMETHING
const string EQUATIONS[5] = {
    "v = Δs / Δt",
    "a = Δv / Δt",
    "F = m * a",
    "W = m * g",
    "p = m * v"
};


//prototypes
void mainMenu(); //display the main menu
void calculationChooser(string menuInput); //take in a validated user input, and decide how to calculate the answer.
void motionMenu(); //menu specific to motion problems
void motionHandler(char menuInput); //handles the user inputting the dreaded motion problems.
void physicsCalculator(string operation, string equation); //perform any basic physics calculation (multiplication and division of two numbers ONLY.)
void equationSeperator(string equation, string (&equationArr)[4]); //break apart a simple physics equation into individual components, so above function can work.
string stringToLower(string word); //convert a string to all lowercase letters
string stringToUpper(string word); //convert a string to all uppercase letters
void enterToContinue(); //'freeze' the terminal until the user presses the enter key.

int main()
{
    string menuInput = "";
    bool loopMenu = true;

    //loop through the program until the user types e or E
    do{
        //display the main menu
        mainMenu();
        
        //prompt the user for some cute input
        menuInput = validateString(menuInput);
        menuInput = stringToLower(menuInput); //convert to lowercase

        //exit the program if the user wants to
        if (menuInput == "e"){
            cout << COLORS[1] << "Goodbye!" << RESET << endl;
            loopMenu = false;
            break;
        }

        //choose the right function
        calculationChooser(menuInput);

    }while(loopMenu);

    return 0;
}

//function definitions 

//Prints the main menu out to the terminal
void mainMenu()
{
    cout << COLORS[1] << "Physics Calculator" << RESET << endl
        << "Please choose from the following menu options." << endl
        << "Type the letter " << COLORS[2] << "E" << RESET <<" to exit the program." << endl
        << "Type the letter " << COLORS[2] << "X" << RESET <<" to clear the screen." << endl;

    //dnamic main menu
    //sizeof returns the size in memory of some data
    //so, because arrays are like several somethings in memory, the size of the array is
    //the size of the data type * the number of stuff in the array
    //how_many_pieces = total_size_of_array / size_of_one_piece
    //https://en.cppreference.com/w/cpp/language/sizeof
    //because each array may hold a different data type, I'm not sure how to incorporate this into a function for easy repeatability.
    //also i'm not smart enough to pretend to go look at the documentation for C++ when something weird happens
    //found on stack overflow https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    //just wanted to write an explanation to demonstrate understanding
    for(int i = 0; i < (sizeof(OPERATIONS)/sizeof(*OPERATIONS)); i++) 
    {
        cout << i + 1 << ". " << COLORS[2] << stringToUpper(OPERATIONS[i]) << RESET << endl;
    }

}

//makes the decision on which calculation to perform.
//paramater menuInput: a validated a string of the input from the user
void calculationChooser(string menuInput)
{
    if (menuInput == "x"){
        system("clear");
        return;
    } else if (menuInput == "motion"){     //Motion handled by a separate function
        return motionMenu();
    }

    //loop through the options until we find the right one
    for(int i = 0; i < (sizeof(EQUATIONS)/sizeof(*EQUATIONS)); i++){
        if (OPERATIONS[i] == menuInput){ //if the user chose a valid menu option ...
            return physicsCalculator(OPERATIONS[i], EQUATIONS[i]); //start the physics calculation.
        }else if (i == ((sizeof(EQUATIONS)/sizeof(*EQUATIONS)) - 1)){ //if the user chooses some dumb thing that isn't real...
            i = -1;
            cout << COLORS[0] << "ERROR: Invalid option. Try again." << RESET << endl; //Tell them they are stupid
            menuInput = validateString(menuInput); //and then make them choose again. 
            menuInput = stringToLower(menuInput);
        }
    }
    
}

//displays the menu for the motion problems
void motionMenu()
{
    bool loopMenu = true;
    do{
        //display the menu
        cout << COLORS[1] << "Motion Equations" << RESET << endl
            << "Type the letter" << COLORS[2] << " E " << RESET << "to return to the main menu." << endl
            << "Type the letter" << COLORS[2] << " X " << RESET << "to clear the screen." << endl
            << "A. " << COLORS[2] << "v = v0 + at" << RESET << endl
            << "B. " << COLORS[2] << "s = s0 + v0t + ½at2" << RESET << endl
            << "C. " << COLORS[2] << "v2 = v02 + 2a(s - s0)" << RESET << endl
            << "D. " << COLORS[2] << "v̅ = ½(v + v0)" << RESET << endl;

        //query the user for a menu input
        char menuInput = 'a';
        menuInput = validateChar(menuInput);
        menuInput = toupper(menuInput);

        //exit the menu if the user wants to
        if (menuInput == 'E'){
            cout << COLORS[1] << "Returning to main menu..." << RESET << endl;
            loopMenu = false;
            break;
        }else if (menuInput == 'X'){
            system("clear");
        }

        motionHandler(menuInput);

    }while(loopMenu);
}

//handles the 4 motion problems
void motionHandler(char menuInput)
{

}

//outputs information to the screen about what basic physics problem is being done
//walks through all of the steps
//and queries the user for some input to perform said calculations
void physicsCalculator(string operation, string equation)
{
    double pieceOne = 0.0; //first number from the user
    double pieceTwo = 0.0; // second number from the user 
    string unitOne = ""; // units for the first number
    string unitTwo = ""; //units for the second number
    double result = 0.0; //result

    string equationPieces[4];

    //break apart the equation into pieces
    equationSeperator(equation, equationPieces);
    
    //weight check (weight assumes gravity is 9.81)
    if (operation == "weight"){
        pieceTwo = 9.80665;
        unitTwo = "meters/s^2";
    }
    //output the name of the operation we are performing
    cout << endl << COLORS[4] << stringToUpper(operation) << RESET << endl;

    //output the equation
    cout << equation << endl;
    //create a menu to query the user for information
    cout << "What is the value of " << COLORS[4] << equationPieces[1] << RESET << "?" << endl;
    pieceOne = validateDouble(pieceOne);
    cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
    unitOne = validateString(unitOne);
    if(operation != "weight"){ //weight already has this filled out. just need the mass to calculate.
        cout << endl << "What is the value of " << COLORS[4] << equationPieces[3] << RESET << "?" << endl;
        pieceTwo = validateDouble(pieceTwo);
        cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
        unitTwo = validateString(unitTwo);
        cout << endl;
    }

    //ok, time to do the math. 
    //first -- dividing by zero is undefined. 
    if(pieceTwo == 0.0){
        cout << endl << COLORS[0] << "ERROR: DIVIDE BY ZERO" << RESET << endl
            << "Would you like to try again? " << COLORS[2] << "(y/n)" << RESET << endl;
        char yesorno = 'a';
        yesorno = validateChar(yesorno);
        if (yesorno == 'y')
            return physicsCalculator(operation, equation);
        else
            return;
    }
    if(equationPieces[2] == "*"){
        result = pieceOne * pieceTwo;
    }else{
        result = pieceOne / pieceTwo;
    }
    cout << "Wow. That was really, really hard." << endl
        << "Somehow, I managed to solve this problem for you." << endl
        << "Here is the solution." << endl
        << COLORS[4] << stringToUpper(operation) << endl
        << equation << RESET << endl
        << COLORS[4] << equationPieces[0] << RESET << " = " << COLORS[5] << pieceOne << RESET << " " << COLORS[3] << unitOne << RESET << " " << equationPieces[2] << " " << COLORS[5] << pieceTwo << RESET << " " << COLORS[3] << unitTwo << RESET << endl;
    //set the precision to display for our final answer
    cout.precision(PRECISION);
    cout.setf(ios::fixed, ios::floatfield);
    //final answer
    cout << COLORS[1] << equationPieces[0] << " = " << result << " " << unitOne << " " << equationPieces[2] << " " << unitTwo << RESET << endl;
    //unset the precision
    cout.unsetf(ios::floatfield);
    enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
    //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
}

// separates out a given equation into a specfic array
// paramater equation is the equation 
// equationArr is a reference to an existing array
// returning an array in C++ seems complicated, so instead of returning an array, we can reference the existing array to modify the data within
void equationSeperator(string equation, string (&equationArr)[4])
{
    //find where the space is
    //create a substring that starts at the pos of the last space
    //save substring to equation arry
    //repeat until gone over whole equation 
    //each basic physics equation is formatted in the same exact way. If it isn't, then this won't work. So, format it correctly. 
    
    int seperator = 0; //each " " or "=" is a seperator in our given list of equations. Start at 0 to start off at the beginning of the string.
    //for each possible value within the parameter equationArr...
    for(int i = 0; i < (sizeof(equationArr)/sizeof(*equationArr)); i++){ 
        int newSeperator = -1; //start at -1. Should never be -1. If it is, we can figure out something horrible happened and fix the bug.
        string tempString = equation.substr(seperator);

        //filter out the equals sign & spaces!
        if( tempString.find("=") != string::npos){
            int tempSep = tempString.find("=");
            tempString = tempString.erase(tempSep); //cut off everything after the =
            newSeperator = seperator + tempSep + 2; //a space will always follow the equals sign. Get rid of that one too. 
        }else if (tempString.find(" ") != string::npos){
            int tempSep = tempString.find(" ");
            tempString = tempString.erase(tempSep); //throw out everything after the first " "
            newSeperator = seperator + tempSep + 1;
        }

        equationArr[i] = tempString;
        seperator = newSeperator;
    }

}

//convert a string into all lowercase
string stringToLower(string word)
{
    int length = word.length();
    char stack[length]; //create an array of characters to store our broken up string into

    for(int i = 0; i < length; i++){
        stack[i] = word.at(i); //if a string is an array, then this is like word[i].
        stack[i] = tolower(stack[i]); //make the character lowercase
    }

    stack[length] = '\0'; //null terminator - marks end of string

    return string(stack);
}

//convert a string into all uppercase
string stringToUpper(string word)
{
    int length = word.length();
    char stack[length]; //create an array of characters to store our broken up string into

    for(int i = 0; i < length; i++){
        stack[i] = word.at(i); //if a string is an array, then this is like word[i].
        stack[i] = toupper(stack[i]); //make the character uppercase
    }

    stack[length] = '\0'; //null terminator - marks end of string

    return string(stack);
}

//tell the user to press enter to continue 
//"freeze" the program until the user hits enter
void enterToContinue()
{
    cout << "Press " << COLORS[2] << "ENTER" << RESET << " to continue." << endl;
    while(getchar() != '\n');
    //impossible to accomplish my goals if we validate the input to disallow escaping
    //tested inputting many different escape characters'
    //nothing seems to do anything
    /* 
    char didYouTypeEnter = '0';
    while(didYouTypeEnter != '\n'){
        didYouTypeEnter = validateChar(didYouTypeEnter);
    }
    */
}
