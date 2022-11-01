//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_Arif

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <cassert>
#include <stack>
#include <set>
#include <utility>
#include <map>

using namespace std; 

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1 (vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};
//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector2
{ 
    vector<int> vec;
 
public:
    MyClassVector2(vector<int> v) : vec(v)
    {
    }
    void print()
    {
        /// print the value of vector
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
    }
};
//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector3
{ 
    vector<int>& vec;
 
public:
    // this is the right way to assign
    // the reference of stl container
    MyClassVector3(vector<int>& arr)
        : vec(arr)
    {
    }
    void print()
    {
        /// print the value of vector
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
    }
};

//I have absolutely no idea what these 2 lines do. 
//Someting with map iterators. What that means, I have no clue.
typedef map<string, int> MapT; //what does typedef mean? 
typedef MapT::const_iterator MapIterT;

bool less_than_7(int value); //function prototype

int main() 
{
    /****2022FL COSC-1437-58001***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1);
    vd.push_back(2);
    vd.push_back(3);
    vd.push_back(55.4); 

    //add 3 elements to the vi vector
    vi.push_back(2);
    vi.push_back(42);
    vi.push_back(300);
    // add 3 elements to the vs vector
    vs.push_back("string1");
    vs.push_back("string2");
    vs.push_back("string3");

   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector
   cout << "\nValues in vi: \n"; 
   for(int vals : vi)
   {
     cout << vals << endl; 
   }
   // display the 3 elements in the vs vector
   cout << "\nValues in vs: \n"; 
   for(string vals : vs)
   {
     cout << vals << endl; 
   }
   
    /****2022FL COSC-1437-58001***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

   cout << "\nVector_as_Class_Member" << endl; 
    vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print(); 
      
      //Continue with MyClassVector2 and MyClassVector3
    cout << "\nMyClassVector2\n";
    MyClassVector2 objTwo(vec);
    objTwo.print();

    cout << "\nMyClassVector3\n";
    MyClassVector3 objThree(vec);
    objThree.print();

    /****2022FL COSC-1437-58001***STL_Iterators*/ 
    cout << endl << "STL_Iterators" << endl;
    vector<int> vint(10); //vector with 10 integer numbers
    for(int i = 0; i < 10; i++){ //fill it up
        vint[i] = ((i+1) * 10); //10, 20, 30... 100
    }

    //output the elements of the vector
    vector<int>::iterator it; //make a new iterator that's gonna act like a pointer to a vector<int>
    for (it  = vint.begin(); it != vint.end(); ++it){ //the iterator should start at the beginning of the vector int, and end at the end of the vector. 
        cout << *it << " "; //*it means instead of outputting the memorary address, it will look inside and like idk tell you what that address in memory really is, which is the specific piece within the vector
    }
    //if this looks like I barely understand how pointers work, it's because I barely understand how pointers work. 

    /****2022FL COSC-1437-58001*** Stack*/
    //Write comments that help one better understand what the code is doing.

    stack<int> st; //create a new stack object holding integers

    st.push(100); //push the number 100 onto the top of the stack
    assert(st.size() == 1); //verify one element is on the stack 
    assert(st.top() == 100); // verify that it is in fact 100, like we set it to

    st.top() = 456; //assign a new value -- not adding a new item, but changing the existing. 100 is now 456.
    assert(st.top() == 456); //verify the value at the top of the stack is 456

    st.pop(); //remove the element on the top of the stack
    assert(st.empty() == true); //verify the stack is now empty

    /****2022FL COSC-1437-58001**** Set*/
    cout << "\nSet\n";
    //Write the code as presented in: 3. std::set

    //Write comments that help one better understand what the code is doing.

    set<int> iset; //create a set object named iset that holds integers

    //insert some values into the set
    iset.insert(11);
    iset.insert(-11);
    iset.insert(55);
    iset.insert(22);
    iset.insert(22); //22 already exists. So, insert will not actually insert it.

    if(iset.find(55) != iset.end()){ //check if the value is stored. set.find will return the end of the set if the item isn't found.
        iset.insert(55); //insert 55
    }

    assert( iset.size() == 4); //verify the size is 4

    set<int>::iterator itSet; //create a new iterator for the set
    for(itSet = iset.begin(); itSet != iset.end(); itSet++){ //go through the set
        cout << *itSet << " "; //... and output each value by de-referencing the pointer (i think that's what it's called?), and tell us what the actual value of the thing is
    }


    /****2022FL COSC-1437-58001****Pair_Structure*/
    //Write the code as presented in: 4. std::pair structure

    //Write comments that help one better understand what the code is doing.

    pair<string, string> strstr; //declare  a pair, consisting of a string and a string, called strstr
    strstr.first = "Hello"; //set the first value to a string Hello
    strstr.second = "World"; //initialize the second value to "World"

    pair<int, string> intstr; //declare a pair of two different datatypes
    intstr.first = 1; //the first one is an integer, the number 1
    intstr.second = "one"; //and the second one is a string, of value one

    pair<string, int> strint("two", 2); //declare & initialize the pair, in one line!
    assert(strint.first == "two"); //verify the values are configured correctly
    assert(strint.second == 2); //side note - I tried changing the values to be wrong. And it's really cool. Either the compiler is doing something cool, or the debugger with VSCode is doing something cool and letting me know this failed. 

    /****2022FL COSC-1437-58001**** Map_Insert*/
    //Write the code as presented in: 14. std::map::insert

    //Write comments that help one better understand what the code is doing.
    MapT amap; //new MapT object named amap
    pair< MapIterT, bool> result = //Create a pair that holds two datatypes - one MapTerT, and a boolean
        amap.insert(make_pair("Fred", 45)); //insert a pair into the map. This means the map should look like this: amap: ["Fred"] = 45 or something, if that makes sense. 
        // https://cplusplus.com/reference/map/map/insert/
        //the insert function seems to return a pair - the first thing being an iterator to the item that was inserted into the map, the second being a boolean - true if inserted into the map.
    //soo -- we make a pair for the result. The result is a MapIterator, which will be like a pointer for that thing we inserted into the other map, and true/false depending if something was inserted.

    assert(result.second == true); //check if the second piece of the pair is true
    assert(result.first->second == 45); //result.first will be an iterator of the inserted pair for the map (or the existing pair), -> the second thing in that should be 45.

    result = amap.insert(make_pair("Fred", 54)); //insert a new value into the map. Fred already exists! So, nothing is inserted, the iterator will just be the already existing value, and the second part of the pair for result is false.

    //Fred was already in the map, and result.first simply points there now:
    assert(result.second == false); //Verify the second part of the pair is false
    assert(result.first->second == 45); //Because Fred was already in the map, his age should be unchanged and still be 45.

    /****2022FL COSC-1437-58001****Map_Summary*/
    cout << endl << "Map Summary" << endl;
    //Write the code as presented in: 16. Map summary

    //Write comments that help one better understand what the code is doing.
    map<string, string> phone_book; //create a new map, with key being a string, and the data for that key also being a string
    phone_book["411"] = "Directory"; //At key 411, the value is Directory
    phone_book["911"] = "Emergency"; //at position 411, the value is emergency
    phone_book["508-678-2811"] = "BCC";

    if (phone_book.find("411") != phone_book.end()){ //if 411 exists within the map,
        phone_book.insert( //insert...
            make_pair( //..a pair...
                string("411"),
                string("Directory") //consisting of these 2 string values.
            )
        ); //insert a pair of strings into the phonebook map
    }

    assert(phone_book.size() == 3); //verify the size of the phone book is still 3
    map<string, string>::const_iterator mapSumIt; //Make an iterator, which is like a pointer for the map.
    for(mapSumIt = phone_book.begin(); mapSumIt != phone_book.end(); ++mapSumIt){ //output the values of the map
        cout
            << " " << mapSumIt->first //mapSumIt is an iterator, which is like a pointer, so access the first part of the thing that is being pointed at with the -> and output it
            << " " << mapSumIt->second //same as above, but for the second piece
            << endl;
    }
    /****2022FL COSC-1437-58001**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

    //Write comments that help one better understand what the code is doing.

    int arr[100]; //create an integery array of size 100 called arr
    sort(arr, arr+100); //sort the array from the first address in memory for the array plus 100, which is the end of our array. From start to finish.
    vector<int> v1; //make a vector called v1 of no datatype jk I declared one, it's an integer vector now because the example doesn't compile
    sort(v1.begin(), v1.end()); //sort the vector from the start ot the end of it

    /****2022FL COSC-1437-58001****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function
    
    //Write comments that help one better understand what the code is doing. 

    vector<int> countIfPredicateVectory; //create a vector of integers
    int count_less = std::count_if(v1.begin(), v1.end(), less_than_7 ); 
    //count_less is the number of objects in the vector that satisfy the condition less_than_7. I don't know why you dont have to pass in a value to the function less than 7 that is expecting an integer, but I guess you don't.

      return 0; 
 }

 bool less_than_7(int value) //function, check if a given integer is less than 7 or not
 {
    return value < 7; //return the value of the expression value < 7. True if the int is less than 7, false if it's not.
 }