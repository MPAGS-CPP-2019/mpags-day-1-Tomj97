#include <iostream>
using namespace std;



void varManipulation();
void constVarManipulation();
void exampleSol4();
/*
Main code block, calls functions
*/
int main()
{
  
  // varManipulation();
  //constVarManipulation();
  exampleSol4();
}
/*Solution to EX2 of C++ course */
void varManipulation()
{

  //Variables
  int a{10};
  int b = a/2;
  double c{2.1};
  int d = c * a;

  //outputs
  cout<< "This is the modified integer: " << b << endl;
  cout<< "This is the created double: " << c << endl;
  cout<< "This is the integer created from the double: " << d << endl;
}
/*Solution to EX3 of C++ course*/
void constVarManipulation()
{

  const double i = 5.9;
  int j{20};
  int k = j + 1;
  
  cout << "This is a contant double: " << i << endl;
  
  cout << "This is a variable integer: " << k << endl;

}

void exampleSol4()
{

  const int a{5};
  const double b{10.5};
  int product = a*b;
  double doubDivInt = b/a;
  int intDivInt = a/a;
  string newString("LHCb");
  char newChar = newString[3];


  cout << "Product of double and int: " << product << endl;
  cout << "Double divided by int: " << doubDivInt << endl;
  cout << "Int divided by int: " << intDivInt << endl;
  cout << "This is my string: " << newString << endl;
  cout << "This is the 4th char of my string: " << newString[3] << endl;
  

}
