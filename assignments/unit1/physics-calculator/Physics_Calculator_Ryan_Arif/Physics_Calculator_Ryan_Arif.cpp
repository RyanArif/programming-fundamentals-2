//#include <iostream> //already included with input validation
//#include <string> //already included with input validation
#include "./Input_Validation_Extended.h"

//using namespace std; //already part of input validation

//prototypes
void mainMenu();
void calculationChooser(string menuInput);
void physicsCalculator(string operation, string equation);
void equationSeperator(string equation, string (&equationArr)[4]);
string stringToLower(string word);
string stringToUpper(string word);


int main()
{
    string menuInput = "";
    bool loopMenu = true;
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
    cout << "Physics Calculator ver 0" << endl
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
void calculationChooser(string menuInput)
{
    //Motion is the only complicated thing. Exclude motion from this.
    if (menuInput == "motion"){
        //call a motion specific helper function.
        return;
    }
    
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
        if (options[i] == menuInput){
            return physicsCalculator(options[i], equations[i]);
        }else if (i == (sizeof(options) - 1)){
            i = -1;
            cout << "ERROR: Invalid option. Try again." << endl;
            menuInput = validateString(menuInput);
            menuInput = stringToLower(menuInput);
        }
    }
    
}

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
        result = pieceOne + pieceTwo;
    }

    cout << "Wow. That was really, really hard." << endl
        << "Somehow, I managed to solve this problem for you." << endl
        << "Here is the solution." << endl
        << stringToUpper(operation) << endl
        << equation << endl
        << equationPieces[0] << " = " << pieceOne << " " << unitOne << " " << equationPieces[2] << pieceTwo << " " << unitTwo << endl
        << equationPieces[0] << " = " << result << " " << unitOne << " " << equationPieces[2] << unitTwo << endl;
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

    int seperator = 0;
    for(int i = 0; i < 4; i++){
        int newSeperator = -1;
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

    /*At first, I started thinking like "OK OMG Gotta break apart the string into an array of characters, and then like break those down to separate arrays of characters to differentiate sections of the string to make a really really cool thing"
    And then, like an hour or so into the process...
    I recalled string.substring and string.find so like haha 
    hahahaha
    This is way easier now. But I'm not deleting this. I want this to stand as a warning to future me. 
    jk this will be deleted in like a commit, I just wanted to leave it here for a while.

    int length = equation.length();
    char stack[length];
    int wordSeperator = 0;

    //dump the string into an array of characters
    for(int i = 0; i < length; i++){
        stack[i] = equation.at(i);
    }

    for(int i = 0; i < sizeof(equationArr); i++){
        string tempString;
        //loop through the stack
        //starts at position 0, then with each iterations, picks up at the next 'word' or 'piece' of the equation
        for(int j = wordSeperator; j < sizeof(stack); j++){
            if(stack[j] == ' ' || stack[j] == '=')
            {
                wordSeperator = j + 1; //next time, start at the character after our word seperator
                break; // leave this loop
            }
            
        }

        equationArr[i] = string(tempStack);
     } */

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