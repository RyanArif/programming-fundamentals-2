//Student Name: Ryan Arif

//Teacher: Dr. Tyson McMillan

//Date: 11/1/2022

//A program to practice working with multi-dimensional arrays

#include <iostream>
#include "Input_Validation_Extended.h"

using namespace std;

/*

Research Input data: go to http://www.weather.comLinks to an external site.

Pick two cities of your choice. Fill in the temperature for the 7 days of this week of both cities. Fill in this text data table, which will be used in your program.

//Chicago = 1, Fort Worth = 2  

//Data Table

//City X, Day X: Temp

City 1, Day 1: 69 

City 1, Day 2: 71 

City 1, Day 3: 68 

City 1, Day 4: 63 

City 1, Day 5: 62

City 1, Day 6: 59

City 1, Day 7: 61

City 2, Day 1: 76

City 2, Day 2: 80

City 2, Day 3: 75

City 2, Day 4: 70

City 2, Day 5: 75

City 2, Day 6: 76

City 2, Day 7: 80

*/

 

int main()

{

      const int CITY = 2;

      const int WEEK = 7;

 

    int temperature[CITY][WEEK];

    //Note your input data from the above

    cout << "Enter all temperature for a week of first city and then second city. \n";

 

    // Inserting the values into the temperature array

    //note for every dimension of the array you need a for loop 2 dimensions = 2 for loops

    for (int i = 0; i < CITY; ++i)

    {

        for(int j = 0; j < WEEK; ++j)

        {

            cout << "City " << i + 1 << ", Day " << j + 1 << " : ";

            //cin >> temperature[i][j]; //hold it, we can't do this. You should validate this input. Silly goose.
            int tempTemp = 0;
            while(true){ //do some input validation
                tempTemp = validateInt(tempTemp); //validate the integer
                //there is an absolute 0 value that must be acknowledged. The temperature literally cannot fall below this.
                //Absolute 0 in Farhenheit: −459.67 °F (source: wikipedia)
                if(tempTemp < -459){ 
                    cout << "ERROR: Inputted temperature is physically impossible." << endl;
                }else{ //the inputted value is physically possible...
                    break; //leave the loop.
                }
            };

            temperature[i][j] = tempTemp;
        }

    }

 

    cout << "\n\nDisplaying Values:\n";

 

    // Accessing the values from the temperature array

    for (int i = 0; i < CITY; ++i)

    {

        for(int j = 0; j < WEEK; ++j)

        {

            cout << "City " << i + 1 << ", Day " << j + 1 << " = " << temperature[i][j] << endl;

        }

    }

   /*For up to 5 Points Extra Credit

      Expand this program:

      1. Create a one dimensional array, cityOne[7] to store the 7 temperatures of city 1, assume that value 0 represents day 1, 1 represents day 2....

      2. Create a on dimensional array, cityTwo[7] to store the 7 temperatures of city 2 , assume that value 0 represents day 1, 1 represents day 2....

      3. Using a for loop (or nested for loop), feed the data of CityOne[] and CityTwo[] into temperature[i][j], where i is index of the City Number, and j is the index of the temp for the day.

      4. print the results of temperature[i][j]; to the screen.

    */

    int cityOne[7]; //new array for city 1
    cout << "Enter the temperatures for City 1." << endl;
    for(int i = 0; i < 7; i++){ //loop through the array and fill it up 
        cout << "City 1, Day " << i + 1 << " = ";
        int tempTemp = 0;
        while(true){ //do some input validation
            tempTemp = validateInt(tempTemp); //validate the integer
            //there is an absolute 0 value that must be acknowledged. The temperature literally cannot fall below this.
            //Absolute 0 in Farhenheit: −459.67 °F (source: wikipedia)
            if(tempTemp < -459){ 
                cout << "ERROR: Inputted temperature is physically impossible." << endl;
            }else{ //the inputted value is physically possible...
                break; //leave the loop.
            }
        };

        cityOne[i] = tempTemp; //fill up the array with a validated input
    } 
 
    int cityTwo[7]; //new array for city 2
    cout << "Enter the temperatures for City 2." << endl;
    for(int i = 0; i < 7; i++){ //loop through the array and fill it up 
        cout << "City 2, Day " << i + 1 << " = ";
        int tempTemp = 0;
        while(true){ //do some input validation
            tempTemp = validateInt(tempTemp); //validate the integer
            //there is an absolute 0 value that must be acknowledged. The temperature literally cannot fall below this.
            //Absolute 0 in Farhenheit: −459.67 °F (source: wikipedia)
            if(tempTemp < -459){ 
                cout << "ERROR: Inputted temperature is physically impossible." << endl;
            }else{ //the inputted value is physically possible...
                break; //leave the loop.
            }
        };

        cityTwo[i] = tempTemp; //fill up the array with a validated input
    }

    //traverse the temperature 2d array 
    for (int i = 0; i < CITY; ++i)
    {
        for(int j = 0; j < WEEK; ++j)
        {
            if(i == 0){
                temperature[i][j] = cityOne[j]; //fill up the data from city 1
            }else if(i == 1){
                temperature[i][j] = cityTwo[j]; //fill up city 2 
            }
        }
    }

    return 0;

}