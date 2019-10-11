#include <iostream>
using namespace std;

int main()
{
  std::cout << "Hello World! \n";

  int a{10};
  int b = a/2;
  double c{2.1};
  int d = c * a;

  cout<< "This is the modified integer: " << b << endl;
  cout<< "This is the created double: " << c << endl;
  cout<< "This is the integer created from the double: " << d << endl;
  
}
