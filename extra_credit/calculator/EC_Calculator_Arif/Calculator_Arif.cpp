#include "Input_Validation_Extended.h" //validate user input
#include <iostream> //cin, cout
#include <string> //adds support for strings

using namespace std; //std::

//globals
//Colors!
const string RESET = "\x1b[0m"; //reset formatting
const string COLOR_GREEN = "\x1b[32;1m"; 
const string COLOR_RED = "\x1b[31;1m";
const string COLOR_YELLOW =  "\x1b[33;1m";

//FUNction prototypes
void mainMenu(); //displays a main menu!
char getOperation(); //gets the operation from the user, and returns it
double doMath(double, double, char); //does the calculation and returns it
void displayResult(double, double, double, char); //displasy the final result
void getNums(double &, double &); //gets the numbers from the user 
bool shouldExit(); //check if we should exit the program or loop again

int main()
{
    do{
        mainMenu(); //print hte main menu to the terminal 

        //numbers to hold the input from the user
        double numOne = 0.0;
        double numTwo = 0.0;
        getNums(numOne, numTwo); //gets input from the user

        char operation = getOperation(); //gets operation from the user

        double result = doMath(numOne, numTwo, operation); //do the computation

        displayResult(numOne, numTwo, result, operation); //display the final answer, showing work
        
    }while(!shouldExit());

    return 0;
}

void mainMenu()
{
    cout << COLOR_GREEN << "WELCOME TO THE CALCULATOR!" << RESET << endl;
}

char getOperation()
{
    char operation = '\0'; //stores the operand for the operation
    //print out to the user some options
    cout << "What math operation would you like to perform?" << endl;
    cout << COLOR_YELLOW << "+" << endl
        << "-" << endl
        << "*" << endl
        << "/" << endl << RESET;

    //loop user input until they enter a valid input option.
    while(true){
        operation = validateChar(operation);
        operation = tolower(operation); //lowercase input is easy.
        if(operation != '+' && operation != '-' && operation != '*' && operation != '/'){
            cout << COLOR_RED << "ERROR: INVALID CHOICE. TRY AGAIN." << RESET << endl;
        }else{
            break; //loop break point
        }
    }

    return operation; 
}

double doMath(double numOne, double numTwo, char operand)
{
    double result = 0.0; //stores the final result

    //go through the menu options, and apply the right math.
    switch (operand)
    {

        case '+':
            result = numOne + numTwo;
            break;
        case '-':
            result = numOne - numTwo;
            break;
        case '*':
            result = numOne * numTwo;
            break;
        case '/':
            result = numOne / numTwo;
            break;
        default:
            break;           
    }

    return result; //return the final result
}

void displayResult(double numOne, double numTwo, double result, char operand)
{
    //print some stuff to the screen
    cout << "Thank you for your input!" << endl;
    cout << "The answer is: " << endl;
    cout << COLOR_GREEN << numOne << " " << operand << " " << numTwo << " = " << result << RESET << endl;
}

void getNums(double &numOne, double &numTwo)
{
    cout << COLOR_YELLOW << "Number 1: " << RESET;
    numOne = validateDouble(numOne); //validate input for the first number
    cout << COLOR_YELLOW << "Number 2: " << RESET;
    numTwo = validateDouble(numTwo); //validate the second number
}

bool shouldExit()
{
    bool exit = false; //should we exit the program? 

    cout << "Would you like to exit? " << COLOR_YELLOW << "(y/n)" << RESET << endl;
    char yesorno = '\0';
    //loop until the user inputs Y or N.
    while(true){ 
        yesorno = validateChar(yesorno);
        yesorno = tolower(yesorno); //only lowercase comparisons makes lif easy
        if(yesorno != 'y' && yesorno != 'n'){
            cout << COLOR_RED << "ERROR: Type Y for yes, or N for no." << endl;
        }else{
            break; //break the loop
        }
    }

    if(yesorno == 'y'){
        exit = true;
    }else if (yesorno == 'n'){
        exit = false;
    }

    return exit;
}
