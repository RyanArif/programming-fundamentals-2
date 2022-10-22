//#include <iostream> //already included with input validation
//#include <string> //already included with input validation
#include "./Input_Validation_Extended.h"

//using namespace std; //already part of input validation

//prototypes
void mainMenu(); //display the main menu
void calculationChooser(string menuInput); //take in a validated user input, and decide how to calculate the answer.
void physicsCalculator(string operation, string equation); //perform any basic physics calculation (multiplication and division of two numbers ONLY.)
void equationSeperator(string equation, string (&equationArr)[4]); //break apart a simple physics equation into individual components, so above function can work.
string stringToLower(string word); //convert a string to all lowercase letters
string stringToUpper(string word); //convert a string to all uppercase letters


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
            cout << "Goodbye!" << endl;
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
    //Main Menu
    cout << "Physics Calculator" << endl
        << "Please choose from the following menu options." << endl
        << "Type the letter E to exit the program." << endl
        << "1. Velocity" << endl
        << "2. Acceleration" << endl
        << "3. Motion" << endl
        << "4. Newton's Second Law" << endl
        << "5. Weight" << endl
        << "6. Momentum" << endl;
}

//makes the decision on which calculation to perform.
//paramater menuInput: a validated a string of the input from the user

//NOTE: Perhaps this logic is a bit TOO nested, like there's functions instead of functions inside of functions at this point
//think of a change to improve readability of the code
//go to sleep for now lmao be back later
void calculationChooser(string menuInput)
{
    //Motion is the only complicated thing. Exclude motion from this.
    if (menuInput == "motion"){
        //call a motion specific helper function. not made yet.
        return;
    }
    
    //pair of arrays for determing the name of an option and the corresponding equation
    //array of available options
    string options[5] = {
        "velocity",
        "acceleration",
        "newton's second law",
        "weight",
        "momentum"
    };
    //array of corresponding equations
    string equations[5] = {
        "v = Δs / Δt",
        "a = Δv / Δt",
        "F = m * a",
        "W = m * g",
        "p = m * v"
    };

    //loop through the options until we find the right one
    for(int i = 0; i < sizeof(options); i++){
        if (options[i] == menuInput){ //if the user chose a valid menu option ...
            return physicsCalculator(options[i], equations[i]); //start the physics calculation.
        }else if (i == (sizeof(options) - 1)){ //if the user chooses some dumb thing that isn't real...
            i = -1;
            cout << "ERROR: Invalid option. Try again." << endl; //Tell them they are stupid
            menuInput = validateString(menuInput); //and then make them choose again. 
            menuInput = stringToLower(menuInput);
        }
    }
    
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

    //output the name of the operation we are performing
    cout << stringToUpper(operation) << endl;
    //output the equation
    cout << equation << endl;

    //create a menu to query the user for information
    cout << "What is the value of " << equationPieces[1] << "?" << endl;
    pieceOne = validateDouble(pieceOne);
    cout << endl << "What are the units?" << endl;
    unitOne = validateString(unitOne);
    cout << "What is the value of " << equationPieces[3] << "?" << endl;
    pieceTwo = validateDouble(pieceTwo);
    cout << endl << "What are the units?" << endl;
    unitTwo = validateString(unitTwo);

    //ok, time to do the math. 
    if(equationPieces[2] == "*"){
        result = pieceOne * pieceTwo;
    }else{
        result = pieceOne / pieceTwo;
    }

    cout << "Wow. That was really, really hard." << endl
        << "Somehow, I managed to solve this problem for you." << endl
        << "Here is the solution." << endl
        << stringToUpper(operation) << endl
        << equation << endl
        << equationPieces[0] << " = " << pieceOne << " " << unitOne << " " << equationPieces[2] << pieceTwo << " " << unitTwo << endl
        << equationPieces[0] << " = " << result << " " << unitOne << " " << equationPieces[2] << unitTwo << endl;

    //add a pause button here so the user can read their solution until they are ready to proceed back to the main menu. 
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
    for(int i = 0; i < 4; i++){ //for some reason sizeof(equationArr) was throwing out some astronomically large number breaking the program when we tried to add info to it, because we'd quickly go out of bounds. For now - hard coded.
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