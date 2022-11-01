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
    vector<int>::iterator it;
    for (it  = vint.begin(); it != vint.end(); ++it){
        cout << *it << " ";
    }

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
    for(itSet = iset.begin(); itSet != iset.end(); itSet++){ //go through the set...
        cout << *itSet << " "; //... and output each value.
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

    /****2022FL COSC-1437-58001****Map_Summary*/
    //Write the code as presented in: 16. Map summary

    //Write comments that help one better understand what the code is doing.

    /****2022FL COSC-1437-58001**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

    //Write comments that help one better understand what the code is doing.

    /****2022FL COSC-1437-58001****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function

    //Write comments that help one better understand what the code is doing. 

      return 0; 
 }