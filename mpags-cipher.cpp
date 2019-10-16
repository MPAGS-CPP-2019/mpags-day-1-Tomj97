#include <iostream>
#include <string>
#include <vector>


//List of functions
std::string fullEncryption(std::string  userMsg);

/*
Main code block. Contains all the command line argument handling. 
Also accepts input for user message to be encrypted.
- return 0 indicates successful run of code.
- return 'non-zero' indicates unsuccessful run of code (ERROR).
*/
int main(int argc, char* argv[])
{
  const std::string versionNum {"1.1"}; //Version number of the program.

  //Format command line arguments for read out at start of program.
  const std::vector<std::string> cmdLineArgs{argv, argv+argc}; //Contains the command line arguments. These will be saved to the ouput file.
  const int numOfArgs = cmdLineArgs.size(); //Define the number of arguments as the size of the vector cmdLineArgs
  std::cout << "Command Line Arguments: ";
  for(int i= 0; i < numOfArgs; ++i)
    {
    std::cout << cmdLineArgs[i];
    if(i != (numOfArgs - 1))
      {
	std::cout << ", ";
      } 
    else 
      {
	std::cout << "\n";
      }
    }

//Declaration of variables related to all command line arguments.
  bool help = false;
  bool version = false;
  std::string inputFileName;
  std::string outputFileName;
 
  for(int i = 1; i < numOfArgs; ++i)
    {
     if(cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") //cmdLineArgs[0] = name of the program. So loop needs to start from index 1.
      {
	help = true;
      }
    else if(cmdLineArgs[i] == "-i")
      {
      // Next element is filename unless -i is the last argument
      if (i == numOfArgs-1) 
	{
	  std::cerr << "[ERROR] -i option requires a filename argument" << std::endl;
	  // 
	  return 1;
	}
      inputFileName = cmdLineArgs[i+1];
      ++i;
      }
    else if(cmdLineArgs[i] == "-o")
      {
      // Next element is filename unless -o is the last argument
      if (i == numOfArgs-1) 
	{
        std::cerr << "[ERROR] -o option requires a filename argument" << std::endl;
        return 1;
	}
      outputFileName = cmdLineArgs[i+1];
      ++i;
      }
    else if(cmdLineArgs[i] == "--version" || cmdLineArgs[i] == "-v")
      {
	version = true;
      }
    else
      {
	std::cerr << "[ERROR] command line input: '" << cmdLineArgs[i] << "' is not an accepted command. Use -h for a list of all accepted commands." << std::endl;
	return 1;
      }
    }

  //If user activates help argument output help message (contains all arguments), then close the program.
  if (help == true) 
    {
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input messages using the three classical ciphers: Ceasar, Playfair, Vignere \n\n"
      << "Available options:\n\n"
      << "  -h || --help     Print this help message and exit program\n\n"
      << "  -v || --version  Print version information\n\n"
      << "  -i filename      Read user input message from filename\n"
      << "                   program will run and accept standard cin if file not provided\n\n"
      << "  -o filename      Write encrypted message to filename\n"
      << "                   program will run and output message in console if file is not provided\n\n" ;
    // Help requires no further action, so return from main
    return 0;
  }

  /*If user activates version command line prompt. Output version number then close program.
   */
  if (version == true) 
    {
      std::cout << "Version " << versionNum << std::endl;
      return 0;
    }


  




 //******************PROGRAM START***************************
  std::string msg;
  std::string encryptedMsg;
  /*Read in user input from file
    -This has not yet been implemented-*/
  if (!inputFileName.empty()) 
    {
      std::cout << "[WARNING] input from files not yet implemented. Cannot read file ('"
		<< inputFileName
		<< "') "
		<< "enter message via standard input below. \n\n\n";
    }
 
    



  std::cout << "Enter the message to be encrypted. Once message has been entered, press the 'Enter' key to start the encryption: \n" << std::endl;
  std::getline(std::cin,msg); //Put input from user into the msg variable.
      
  encryptedMsg = fullEncryption(msg); //encrypted message is the return value of the 'fullEncryption' function
    
  /*Write encrypted message to 'outputfilename'
    -This has not yet been implemented- */
  if(!outputFileName.empty())
    {

      std::cout << "[WARNING] output to files is not yet implemented. Cannot write to file ('"
		<< outputFileName
		<< "') "
		<< "message will be output to console below. \n\n\n";

    }
  
  std::cout<< "This is the original message: " << msg << std::endl;
  std::cout<< "Message after encryption: " << encryptedMsg << std::endl;   //Print out the final message after encryption.   
   

  return 0;
}






/*
Encypts a message input from the user by changing lower case letters to upper case, ignorning non-alpha characters
and changing numbers to words i.e '1' -> 'one'. 


Arguments: 
"std::string userMsg" = The string that has been entered in the program by the user.
*/
std::string fullEncryption(std::string userMsg)
{

  //char ch;
  std::string newString; //Contains the encrypted message.

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
  
  //Change numbers in users string to strings. e.g 1 -> one and convert lower case letters to upper case..
  for(int i = 0; userMsg[i] != '\0'; ++i) //Loop until null character is found.
    {
      
	  if(isdigit(userMsg[i]))
	    {

	      int j = userMsg[i] -'0'; //Converts character to integer i.e a character '1' would become the int '1'. This is in order to extract the correct string from numString. (Avoids a block of switch cases).
	      newString+=numString[j]; //Add the number word to the new string
	  
	  

	    }
	  //Add all alpha characters to the new string. Ignore all non-alpha characters (this includes spaces between words).
	  else if(isalpha(userMsg[i]))
	    {

	      newString += userMsg[i];

	    }
        
	
}
  //Convert all the characters in the new string to upper case.
  for(int i = 0; newString[i] != '\0'; ++i)
    {

      char chUpper = toupper(newString[i]);
      newString[i] = chUpper;



    }

  return newString;
}
