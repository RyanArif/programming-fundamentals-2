/*
Student: Ryan Arif
Professor: Dr. Tyson McMillan
Section: 2022FL COSC-1437-58001
Date: 10/31/2022
Editor: VSCode, G++ compiler on Ubuntu via WSL2.
Summary: This code will display the contents of a file of grades, 
then prompt the user for their name, take in some info about some grades, 
sort the grades, then write the grades to a file.

I ran out of time during the quiz. I will finish this and then try attempt 2 I guess. 
Quick Question: Why is the quiz for Unit 2 due before the Revel is due? 
This makes it so when I opened the quiz up, I had to frantically search the textbook for the answers while doing it.
It also means I don't know the proper syntax and method for doing this program with the file and stuff. 

I'll finish this, and then start attempt 2. 
*/

#include <iostream> //cout
#include <string> //strings
#include <algorithm> //CSTL Sort!
#include <fstream> //file stream
#include "Input_Validation_Extended.h" //Input Validation!

using namespace std; 

//global variables
const string GRADE_FILE = "GradeReport.txt";

void printGradesFile(); //prints the values in the grades file, if it exists.
string getUserName(); //gets the users name
int getNumGrades(); //gets how many grades the user wants to enter
void saveGradesFile(double gradesArray[], string userName, int gradesNum); //saves the grades to a file

int main()
{   
    do{ //loop through the menu until...

        printGradesFile(); //shows the grades from the file

        string userName = getUserName(); //gets the users name
        int numGrades = getNumGrades(); //gets how many grades there should be from the user

        //I was going to make a separate function to get the grades from the user. 
        //I have like 25 minutes left to finish this.
        //Not gonna happen. 
        double gradesArray[numGrades]; //make an array to hold the grades
        for(int i = 0; i < numGrades; i++){ //loop through the grades array
            cout << "What is the value of the " << i+1 << "th grade?" << endl; //query the user
            double tempGrade = 0.0;
            while(true){ //validate...
            tempGrade = validateDouble(tempGrade); //and have them ente ra validated value
                if(tempGrade < 0){ //ensure the user inputs a positive value
                    cout << "ERROR: Value must be positive!" << endl;
                }else{
                    break; //leave the loop if the user enters a positive value.
                }
            }
            gradesArray[i] = tempGrade; //save that value to the array, and repeat.
        }

        sort(gradesArray,gradesArray+numGrades); //sort the grades array in desc order

        saveGradesFile(gradesArray, userName, numGrades); //save the data to the grades file

        cout << "Wanna do it again? (y/n)" << endl;
        char userChoice = 'z';
        userChoice = validateChar(userChoice);
        if(tolower(userChoice) == 'n'){ //user does not want to continue
            break; //leave the array
        }else if (tolower(userChoice) == 'y'){
            cout << "Choose y or n, as in YES or NO." << endl;
        }

    }while(true); //loop infinitely until the user hits y and confirms he wants to leave the loop.

    return 0;
}

/*
Input: Nothing
Process: open the grades file if it exists, print out the data from it, and close the file.
Output: Nothing? Return void.
*/
void printGradesFile()
{
    ifstream inFile; //create a new ifstream object to read in the file.

    inFile.open(GRADE_FILE); //try to open the file.
    if(!inFile) return; //if the file doesn't exist, get outta here. Print nothing.

    string userName = "";
    inFile >> userName; //the first line of the file will always be the username.
    cout << "Previous Session: \n Grades for user: " << userName << endl;

    double input = 0.0; //input to get in from the file
    while(inFile >> input){ //as long as input exists...
        cout << input << endl; //display it
    };

    inFile.close(); //close the opened file.
}

/*
Input: Nothing
Process: Queries the user for a string that represents their name.
Output: The string username
*/
string getUserName()
{
    string userName = ""; //declare & init a string for the username

    cout << "What is your first name?" << endl; //ask the user a question
    userName = validateString(userName); //validate the input from the user, and save it so we can...

    cout << "Thank you, " << userName << "." << endl; //display the username back to the user

    return userName; //...return it
}

/*
input: nothing, no parameters
process: query the user for the total number of grades he/she will be inputting.
output: the integer for the total number of grades
*/
int getNumGrades()
{
    int numGrades = 0; //declare & init the number of grades 

    cout << "How many grades will you be inputting today?" << endl;
    while(true){
        numGrades = validateInt(numGrades); //get the validated input from the user
        if(numGrades < 0){ //verify the user enters a positive value
            cout << "ERROR: Positive Integer Required!" << endl;
        }else{
            break; //leave the loop
        }
    }

    return numGrades; //return the validated input
}

/*
input: an array of doubles that represents the grades from our user. a string that is our users username. int gradesNum is the total number of grades.
process: save the array to a file
output: nothing*/
void saveGradesFile(double gradesArray[], string userName, int gradesNum)
{
    ofstream outFile; //output file stream
    outFile.open(GRADE_FILE); //open the grades file

    outFile << userName << endl; //save the username to the file

    for(int i = 0; i < gradesNum; i++){ //for each double inside of the array...
        outFile << gradesArray[i] << endl; //...output the data to the file.
    }

    outFile.close(); //close the file
}