/**
 * Student: Ryan Arif
 * Professor: Dr. Tyson McMillan
 * Class: 2022FL COSC-1437-58001
 * Date Completed: lol it's not done yet
**/

//#include <iostream> //already included with input validation
//#include <string> //already included with input validation
#include "Input_Validation_Extended.h"
#include "String_Manipulation.h"
#include <vector>
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
    "motion" //leave at the end! motion should ALWAYS be last.
};
//motion will be handeled separately. 
//FORMAT SHOULD ALWAYS FOLLOW: 
//SOMETHING = SOMETHING */ SOMETHING
const string EQUATIONS[5] = {
    "v = ds / dt",
    "a = dv / dt",
    "F = m * a",
    "W = m * g",
    "p = m * v"
};

//prototypes
void mainMenu(); //display the main menu
void calculationChooser(string menuInput); //take in a validated user input, and decide how to calculate the answer.
void motionMenu(); //menu specific to motion problems
void motionHandler(char menuInput); //handles the user inputting the dreaded motion problems.
vector<string> physicsMenuQuery(string operation, string equation, vector<double>& userNums, vector<string>& userUnits); //query the user for a bunch of info and return a broken up string
void simplePhysicsCalculator(string operation, string equation); //queries the user for inputs, and puts together the cute display for the outputs.
void solutionMenu(string operation, string equation, vector<string> equationPieces, vector<double> userNums, vector<string> userUnits, double result, string units); //displays the final solution
double simpleCalculator(vector<string> equationVector, vector<double> userNums); //perform any basic physics calculation (multiplication and division of two numbers ONLY.)
string simpeUnitsCalculator(vector<string> equationVector, vector<string> userUnits); //performs basic physics calulations on the units. Literally just combines two strings lol.
void equationSeperator(string equation, vector<string>& equationVector); //break apart a simple physics equation into individual components, so above function can work.
bool isMathOperator(string thing); //check if something is a math operator
double numberCalculator(vector<string> equationVector, vector<double> userNums); //takes in some info, and performs complicated (not really but kind of actually) math

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
    //when i find something on stack overflow, i use it as a resource to learn about a new function or operator to help me go back
    //and read the documentation to properly learn how something can work best for me
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
            return simplePhysicsCalculator(OPERATIONS[i], EQUATIONS[i]); //start the physics calculation.
        }else if (i == ((sizeof(EQUATIONS)/sizeof(*EQUATIONS)) - 1)){ //if the user chooses some dumb thing that isn't real...
            cout << COLORS[0] << "ERROR: Invalid option. Try again." << RESET << endl; //Tell them they are stupid
            menuInput = validateString(menuInput); //and then make them choose again. 
            menuInput = stringToLower(menuInput);
            return calculationChooser(menuInput);
        }
    }
    
}

//displays the menu for the motion problems
void motionMenu()
{   
    string motionEquations [4] = {
        "s = s0 + v0t + ½at^2",
        "v = v0 + at",
        "v^2 = v0^2 + 2a(s - s0)",
        "v̅ = ½(v + v0)"
    };

    bool loopMenu = true;
    do{
        //display the menu
        cout << COLORS[1] << "Motion Equations" << RESET << endl
            << "Type the letter" << COLORS[2] << " E " << RESET << "to return to the main menu." << endl
            << "Type the letter" << COLORS[2] << " X " << RESET << "to clear the screen." << endl;
        
        //loop through the equations to list them
        char i = 'A';
        for (string eq : motionEquations){
            cout << COLORS[2] << i << RESET << ". " << eq << endl;
            i++;
        }

        //query the user for a menu input
        char menuInput = 'z';
        menuInput = validateChar(menuInput);
        menuInput = tolower(menuInput);
    
        //exit the menu if the user wants to
        if (menuInput == 'e'){
            cout << COLORS[1] << "Returning to main menu..." << RESET << endl;
            loopMenu = false;
            break;
        }else if (menuInput == 'x'){ //clear the screen...
        }

        motionHandler(menuInput);

    }while(loopMenu);
}

//handles the 4 motion problems
//parameter: menuInput is a validadated char
void motionHandler(char menuInput)
{   
    //different variables to match the equations
    double iPos = 0.0;
    string iPosUnits = "";
    double pos = 0.0;
    string posUnits = "";
    double iVel = 0.0;
    string iVelUnits = "";
    double vel = 0.0;
    string velUnits = "";
    double accel = 0.0;
    string accelUnits = "";
    double time = 0.0;
    string timeUnits = "";
    double result = 0.0;

    //holy crap this is a huge freaking mess. 
    //What I would like to do, and do not know how, is to:
    //do the same exact thin I do to break down other functions, 
    //but with these motions functions, 
    //which get more complicated and each have a different amount of pieces and mathematical operations
    //and I don't know how to make like a "dynamic" array that doesn't have to be immediately told how big it is
    //does that make sense? I know there's a data type that exists that can help me. I don't know what it is.
    switch(menuInput){
        case 'a': //position
            //output text and query the user 
            cout << COLORS[4] << "POSITION" << RESET << endl
                << "s = s0 + v0t + ½at^2" << endl;
            cout << "What is the value of " << COLORS[4] << "s0" << RESET << "?" << endl;
            iPos = validateDouble(iPos);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            posUnits = validateString(posUnits);
            cout << endl << "What is the value of " << COLORS[4] << "v0" << RESET << "?" << endl;
            iVel = validateDouble(iVel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            iVelUnits = validateString(iVelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "a" << RESET << "?" << endl;
            accel = validateDouble(accel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            accelUnits = validateString(accelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "t" << RESET << "?" << endl;
            time = validateDouble(time);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            timeUnits = validateString(timeUnits);
            
            //perform the computation
            result = iPos + (iVel*time) + (0.5 * accel * (time * time));

            cout << "Wow. That was really, really hard." << endl
                << "Somehow, I managed to solve this problem for you." << endl
                << "Here is the solution." << endl
                << COLORS[4] << "POSITION" << endl
                << "s = s0 + v0t + ½at^2" << RESET << endl
                << COLORS[4] << "s" << RESET << " = " << COLORS[5] << iPos << RESET << " " << COLORS[3] << posUnits << RESET << " + (" << COLORS[5] << iVel << RESET << " " << COLORS[3] << iVelUnits << RESET << " * " << COLORS[5] << time << RESET << " " << COLORS[3] << timeUnits << RESET << ") +  (½" << COLORS[5] << accel << RESET << " " << COLORS[3] << accelUnits << RESET << " * (" << COLORS[5] << time << RESET << " " << COLORS[3] << timeUnits << RESET << ")^2)" << endl;
            //set the precision to display for our final answer
            cout.precision(PRECISION);
            cout.setf(ios::fixed, ios::floatfield);
            //final answer
            cout << COLORS[1] << "s = " << result << " " << posUnits << RESET << endl;
            //unset the precision
            cout.unsetf(ios::floatfield);
            enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
            //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
            break;
        case 'b': // velocity
            //output text and query the user 
            cout << COLORS[4] << "VELOCITY" << RESET << endl
                << "v = v0 + at" << endl;
            cout << "What is the value of " << COLORS[4] << "v0" << RESET << "?" << endl;
            iVel = validateDouble(iVel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            iVelUnits = validateString(iVelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "a" << RESET << "?" << endl;
            accel = validateDouble(accel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            accelUnits = validateString(accelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "t" << RESET << "?" << endl;
            time = validateDouble(time);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            timeUnits = validateString(timeUnits);            
            //perform the computation
            result = iVel + (accel*time);

            cout << "Wow. That was really, really hard." << endl
                << "Somehow, I managed to solve this problem for you." << endl
                << "Here is the solution." << endl
                << COLORS[4] << "VELOCITY" << endl
                << "v = v0 + at" << RESET << endl
                << COLORS[4] << "v" << RESET << " = " << COLORS[5] << iVel << RESET << " " << COLORS[3] << iVelUnits << RESET << " + (" << COLORS[5] << accel << RESET << " " << COLORS[3] << accelUnits << RESET << " * " << COLORS[5] << time << RESET << ") " << COLORS[3] << timeUnits << RESET << endl;
            //set the precision to display for our final answer
            cout.precision(PRECISION);
            cout.setf(ios::fixed, ios::floatfield);
            //final answer
            cout << COLORS[1] << "s = " << result << " " << iVelUnits << RESET << endl;
            //unset the precision
            cout.unsetf(ios::floatfield);
            enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
            //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
            break;
        case 'c': // v^2
            //output text and query the user 
            cout << COLORS[4] << "VELOCITY SQUARED" << RESET << endl
                << "v^2 = v0^2 + 2a(s - s0)" << endl;
            cout << "What is the value of " << COLORS[4] << "v0" << RESET << "?" << endl;
            iVel = validateDouble(iVel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            iVelUnits = validateString(iVelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "a" << RESET << "?" << endl;
            accel = validateDouble(accel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            accelUnits = validateString(accelUnits);
            cout << endl << "What is the value of " << COLORS[4] << "s" << RESET << "?" << endl;
            pos = validateDouble(pos);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            posUnits = validateString(posUnits);
            cout << endl << "What is the value of " << COLORS[4] << "s0" << RESET << "?" << endl;
            iPos = validateDouble(iPos);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            iPosUnits = validateString(iPosUnits);
            //perform the computation
            result = (iVel * iVel) + ((2 * accel) * (pos - iPos));

            cout << "Wow. That was really, really hard." << endl
                << "Somehow, I managed to solve this problem for you." << endl
                << "Here is the solution." << endl
                << COLORS[4] << "VELOCITY SQUARED" << endl
                << "v^2 = v0^2 + 2a(s - s0)" << RESET << endl
                << COLORS[4] << "v^2" << RESET << " = (" << COLORS[5] << iVel << RESET << " " << COLORS[3] << iVelUnits << RESET << ")^2 + (2 * " << COLORS[5] << accel << RESET << " " << COLORS[3] << accelUnits << RESET << ") * (" << COLORS[5] << pos << RESET << " " << COLORS[3] << posUnits << RESET << " - " << COLORS[5] << iPos << RESET << " " << COLORS[3] << iPosUnits << RESET << ")" << endl;
            //set the precision to display for our final answer
            cout.precision(PRECISION);
            cout.setf(ios::fixed, ios::floatfield);
            //final answer
            cout << COLORS[1] << "v^2 = " << result << " (" << iVelUnits << ")^2" << RESET << endl;
            //unset the precision
            cout.unsetf(ios::floatfield);
            enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
            //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
            break;
        case 'd': // average velocity
            //output text and query the user 
            cout << COLORS[4] << "AVERAGE VELOCITY" << RESET << endl
                << "v̅ = ½(v + v0)" << endl;
            cout << "What is the value of " << COLORS[4] << "v" << RESET << "?" << endl;
            vel = validateDouble(vel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            velUnits = validateString(velUnits);
            cout << endl << "What is the value of " << COLORS[4] << "v0" << RESET << "?" << endl;
            iVel = validateDouble(iVel);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            iVelUnits = validateString(iVelUnits);
            //perform the computation
            result = 0.5 * (vel + iVel);

            cout << "Wow. That was really, really hard." << endl
                << "Somehow, I managed to solve this problem for you." << endl
                << "Here is the solution." << endl
                << COLORS[4] << "AVERAGE VELOCITY" << endl
                << "v̅ = ½(v + v0)" << RESET << endl
                << COLORS[4] << "v̅" << RESET << " = ½(" << COLORS[5] << vel << RESET << " " << COLORS[3] << velUnits << RESET << " + " << COLORS[5] << iVel << RESET << " " << COLORS[3] << iVelUnits << RESET << ")" << endl;
            //set the precision to display for our final answer
            cout.precision(PRECISION);
            cout.setf(ios::fixed, ios::floatfield);
            //final answer
            cout << COLORS[1] << "v̅ = " << result << " " << velUnits << RESET << endl;
            //unset the precision
            cout.unsetf(ios::floatfield);
            enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
            //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
            break;
        case 'x' : //clear screen
            system("clear");
            break;
        default : //ERROR. User input an invalid option.
            cout << COLORS[0] << "ERROR: Invalid option. Try again." << RESET << endl;
            char tempChar = 'z';
            tempChar = validateChar(tempChar);
            return motionHandler(tempChar);
    }

}


//will ask the user for a bunch of info regarding a specific equation
//works for any equation, not just the simple ones.
vector<string> physicsMenuQuery(string operation, string equation, vector<double>& userNums, vector<string>& userUnits)
{
    vector<string> equationPieces; //holds the values for the below function

    //break apart the equation into pieces
    equationSeperator(equation, equationPieces);
    
    //output the name of the operation we are performing
    cout << endl << COLORS[4] << stringToUpper(operation) << RESET << endl;
    //output the equation
    cout << equation << endl;

    //create a menu to query the user for information
    for(int i = 2; i < equationPieces.size(); i++){ //always start at position 2. pos 0 is the thing we solve for, pos 1 is equals sign. 
        if (!isMathOperator(equationPieces[i])){
            cout << "What is the value of " << COLORS[4] << equationPieces[i] << RESET << "?" << endl;
            double tempDouble = 0.0;
            tempDouble = validateDouble(tempDouble);
            userNums.push_back(tempDouble);
            cout << "What are the " << COLORS[4] << "units" << RESET << "?" << endl;
            string tempString = "";
            tempString = validateString(tempString);
            userUnits.push_back(tempString);
            cout << endl;
        }
    }

    return equationPieces;
    
}

//outputs information to the screen about what basic physics problem is being done
//walks through all of the steps
//and queries the user for some input to perform said calculations
void simplePhysicsCalculator(string operation, string equation)
{
    vector<double> userNums;
    vector<string> userUnits;
    double result = 0.0; //result
    string units = ""; //final units
    vector<string> equationPieces;

    //query the user for a bunch of info
    //also, so we don't have to do it twice, go ahead and break up the equation into pieces of a vector
    equationPieces = physicsMenuQuery(operation, equation, userNums, userUnits);

    //do the (SIMPLE) math
    try{
        result = simpleCalculator(equationPieces, userNums);
    } catch (const char* errorMsg){
        cout << endl << COLORS[0] << errorMsg << RESET << endl;
        cout << "Would you like to try again?" << COLORS[2] << "(y/n)" << RESET << endl;
        char yesorno = 'z';
        do{
            yesorno = validateChar(yesorno);
        } while(!(yesorno == 'y' || yesorno == 'n'));
        if(yesorno == 'y')
            return simplePhysicsCalculator(operation, equation);
        else
            return;
    }

    //and for the units
    units = simpeUnitsCalculator(equationPieces, userUnits);

    //finally, display the result.
    solutionMenu(operation, equation, equationPieces, userNums, userUnits, result, units);


}

void solutionMenu(string operation, string equation, vector<string> equationPieces, vector<double> userNums, vector<string> userUnits, double result, string units)
{
    cout << "Wow. That was really, really hard." << endl
        << "Somehow, I managed to solve this problem for you." << endl
        << "Here is the solution." << endl
        << COLORS[4] << stringToUpper(operation) << endl
        << equation << RESET << endl
        << COLORS[4] << equationPieces[0] << RESET << " " << equationPieces[1] << " ";
    for(int i = 0; i < userNums.size(); i++){
        int eqPiecePos = i+2;
        //if we need to output a mathematical operator, do that.
        if (isMathOperator(equationPieces[eqPiecePos])){ 
            cout << equationPieces[eqPiecePos] << " ";
        }
        cout << COLORS[5] << userNums[i] << RESET << " " << COLORS[3] << userUnits[i] << RESET << " ";
    }
    //set the precision to display for our final answer
    cout.precision(PRECISION);
    cout.setf(ios::fixed, ios::floatfield);
    //final answer
    cout << endl << COLORS[1] << equationPieces[0] << " = " << result << " " << units << RESET << endl;
    //unset the precision
    cout.unsetf(ios::floatfield);
    enterToContinue(); //hold up the user until he hits enter. Give him time to record his answer and ponder the solution.
    //you could clear the screen here. But what if the user wants to scroll up and review his answer again?
}

//performs simple multiplication or division
//only to be used on simple x * y or x / y equations
//anything else won't work with this, you would need the below, unfinished function
double simpleCalculator(vector<string> equationVector, vector<double> userNums)
{
    double result = 0.0;

    if(equationVector[3] == "*"){
        result = userNums[0] * userNums[1];
    }else{ //must be division
        if(userNums[1] == 0){ //cannot divide by zero.
            throw "ERROR: Divide by 0.";        
        }
        result = userNums[0] / userNums[1];
    }

    return result;
}

string simpeUnitsCalculator(vector<string> equationVector, vector<string> userUnits)
{
    string units = "";

    if(equationVector[3] == "*"){
        units = userUnits[0] + " * " + userUnits[1];
    }else{ //must be division
        units = userUnits[0] + " / " + userUnits[1];
    }

    return units;
}

//I was going to make a really sophisticated calculator 
//it would be able to just look at an equation, and apply PEMDAS and instantly know what to do.
//However... it was getting really complicated. Like, too much for me to think about and finish in time for the due date.
//So ... I'll just handle the regular stuff and motion separately.
// double numberCalculator(vector<string> equationVector, vector<double> userNums)
// {
//     double result = 0.0;

//     //iterate through the equation
//     for(int i = 2; i < equationVector.size(); i++){ //skip everything before the equals sign
//         //PEMDAS!
//         if(equationVector[i] == "("){ //Paranthesis
//             double pResult = 0.0;
//             vector<string> tempEqVector; //create a temp vector...
//             for(int j = i+1; j < equationVector.size(); j++){ 
//                 tempEqVector.push_back(equationVector[j]); //...and fill it up.
//             }
//             pResult = numberCalculator(tempEqVector, userNums); //Call the calculator recursively, to find nested paranthesis. 2(2+2+(2*2))
//         }else if(equationVector[i].find("^") != string::npos){ //Exponent
            
//         }
//     }

//     return result;
// }

// separates out a given equation into a specfic array
// paramater equation is a string for the equation we want to break down
// paramater equationVector is a reference to a vector containing strings
// modifies equationVector to hold all of the pieces of a given equation
void equationSeperator(string equation, vector<string>& equationVector)
{   
    //experiencing weird stuff with this, come back and fix
    int spaceTracker = 0;
    for (int i = 0; i < equation.length(); i++){
        string tempString = equation.substr(spaceTracker);
        if(equation.at(i) == ' '){
            spaceTracker = i+1;
            tempString = tempString.erase(tempString.find(" "));
            equationVector.push_back(tempString);
        }else if (i == equation.length() -1){ //end of loop
            equationVector.push_back(tempString);
        }
    }
}


bool isMathOperator(string thing)
{
    return (thing == "*" || thing == "/" || 
        thing == "+" || thing == "-" || 
        thing == "(" || thing == ")" || 
        thing.find("^") != string::npos);
}