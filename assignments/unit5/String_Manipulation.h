#include <string>

string stringToLower(string word); //convert a string into all lowercase
string stringToUpper(string word); //convert a string into all uppercase
void enterToContinue(); //hold the terminal until the user hits the enter key 

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
    string color = "\x1b[33;1m"; //yellow bold color
    string reset = "\x1b[0m";   //reset formatting

    cout << "Press " << color << "ENTER" << reset << " to continue." << endl;
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