#include <iostream>
#include <string>
#include <vector>


//List of functions
void varManipulation();
void constVarManipulation();
void exampleSol4();
int fullEncryption(std::string  userMsg);
int decryption(std::string  userMsg);

/*
Main code block. Accepts inputs from user.
*/
int main()
{
  std::cout << "Enter the message: \n" << std::endl;
  std::string  msg;
  std::getline(std::cin,msg); //Put input from user into the msg variable.
  std::string choice = "0";


 
  //If user does not choose 1 or 2 as their choice, ask them again until they enter a correct option.
  while( choice != "1" && choice != "2")
    {
      std::cout << "What would you like to do? \n1 Encryption \n2 Decryption \n"; 
      std::cin >> choice;
      
	 if( choice == "1")
	   {
	     fullEncryption(msg);
	   }
	 else if(choice == "2")
	   {
	     decryption(msg);
	   }
    }

  return 0;
}

/*Encypts a message input by the user
Arguments: 
"std::string userMsg" = The string that has been entered in the program by the user. Via the 'cin' command.
*/
int fullEncryption(std::string userMsg)
{

  char ch;

  //Filling a vector with words to replace the integers in users string.
  std::vector<std::string> numString;
  numString.push_back("Zero");
  numString.push_back("One");
  numString.push_back("Two");
  numString.push_back("Three");
  numString.push_back("Four");
  numString.push_back("Five");
  numString.push_back("Six");
  numString.push_back("Seven");
  numString.push_back("Eight");
  numString.push_back("Nine");
  
  //Change numbers in users string to strings. e.g 1 -> one.
  for(int i = 0; userMsg[i] != '\0'; ++i) //Loop until null character is found.
    {

      if(isdigit(userMsg[i]))
	{

	  int j = userMsg[i] -'0'; //Converts character to integer i.e a character '1' would become the int '1'. This is in order to extract the correct string from numString. (Avoids a block of switch cases).
	  userMsg.replace(i,1,numString[j]); //replace character at ith point in the string with word in jth point of numString vector. 
	  
	  

	}
        
	
}
  //Change all lower case letters to upper case letters. e.g a->A.
  for(int i = 0; userMsg[i] != '\0'; ++i) //Loop until null character is found
    {
         
          char chUpper = toupper(userMsg[i]);
	  userMsg[i] = chUpper;
    }
  std::cout<< userMsg << std::endl; //Print out the final message after encryption.
  return 0;
}


/*Decrpyts a message input by the user*/  
int decryption(std::string userMsg)
{

  std::cout<< "decryption not yet functional. This is here to set up for future work."<< std::endl;
  return 0;

}





/*Solution to EX2 of C++ course 
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
/*Solution to EX3 of C++ course
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
  

 }*/
