#include <iostream>
#include <string>
#include "./Input_Validation_Extended.h"

using namespace std;

//prototypes
void mainMenu();
void calculationChooser(string);
void physicsCalculator(string , string);

int main()
{
    string menuInput = "";
    bool loopMenu = true;
    do{
        //display the main menu
        mainMenu();
        //prompt the user for some cute input
        menuInput = validateString(menuInput);
        //exit the program if the user wants to
        if (menuInput == "e" || menuInput == "E"){
            cout << "Goodbye!" << endl;
            loopMenu = false;
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
    if (menuInput == "Motion"){
        //call a motion specific helper function.
        return;
    }
    
    //array of available options
    string options[5] = {
        "Velocity",
        "Acceleration",
        "Newton's Second Law",
        "Weight",
        "Momentum"
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
    bool validOption = false;
    for(int i = 0; i < sizeof(options); i++){
        if (options[i] == menuInput){
            validOption = true;
            continue;
        }
    }
    //if the user chooses an invalid option, prompt them to choose again.
    if (!validOption){
        cout << "ERROR: Invalid option. Program is CaSe-SeNsItIvE." << endl;
        return;
    }
    
}

void physicsCalculator(string operation, string equation)
{
    bool mathMultiply = false; // figure out if we are multiplying or dividing
    double pieceOne = 0.0; //first number from the user
    double pieceTwo = 0.0; // second number from the user 
    string unitOne = ""; // units for the first number
    string unitTwo = ""; //units for the second number
    double result = 0.0; //result

    //output the name of the operation we are performing
    cout << operation << endl;
    //output the equation
    cout << equation << endl;
    //break down the equation into pieces to display
    string solveForWhat = "";
    string firstPiece = "";
    string mathOperator = "";
    string secondPiece = "";
    //do some whacky stuff to break it apart. A string is only a bunch of chars so we can just break that down, throw away the spaces, and be left with the pieces we need. 
    //make a separate function to do this. 

    cout << "What is the value of " << firstPiece << "?" << endl;
    pieceOne = validateDouble(pieceOne);
    cout << endl << "What are the units?" << endl;
    unitOne = validateString(unitOne);
    cout << "What is the value of " << secondPiece << "?" << endl;
    pieceTwo = validateDouble(pieceTwo);
    cout << endl << "What are the units?" << endl;
    unitTwo = validateString(unitTwo);

    //ok, time to do the math. 
    if(mathOperator == "*"){
        mathMultiply = true;
    }
    if(mathMultiply){
        result = pieceOne * pieceTwo;
    }else{
        result = pieceOne / pieceTwo;
    }
}