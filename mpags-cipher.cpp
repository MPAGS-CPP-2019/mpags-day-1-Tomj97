#include <iostream>
using namespace std;



void varManipulation();
void constVarManipulation();
/*
Main code block, calls functions
*/
int main()
{
  string helloWorld = "Hello World!";
  // varManipulation();
  constVarManipulation();
  cout << "This has been created as a string type variable: " << helloWorld << endl;

}

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

void constVarManipulation()
{

  const double i = 5.9;
  int j{20};
  int k = j + 1;
  
  cout << "This is a contant double: " << i << endl;
  
  cout << "This is a variable integer: " << k << endl;

}
