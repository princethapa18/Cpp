/* 12 Feb 2022 String Stream 
   https://www.geeksforgeeks.org/stringstream-c-applications/ 

To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:

    clear()- To clear the stream.
    str()- To get and set string object whose content is present in the stream. 
    operator <<- Add a string to the stringstream object. 
    operator >>- Read something from the stringstream object.

    ----- std::getline (string)	
    istream& getline (istream&  is, string& str, char delim);   (1)
    istream& getline (istream&& is, string& str, char delim);

    istream& getline (istream&  is, string& str);     (2)
    istream& getline (istream&& is, string& str);

    ----- Get line from stream into string
    Extracts characters from is and stores them into str until the 
    delimitation character delim is found (or the newline character, '\n', for (2)).

    The extraction also stops if the end of file is reached in is or if 
    some other error occurs during the input operation.
    If the delimiter is found, it is extracted and discarded 
    (i.e. it is not stored and the next input operation will begin after it).

    Note that any content in str before the call is replaced by the newly extracted sequence.
    Each extracted character is appended to the string as if its member push_back was called.
*/

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int countWords(const std::string& str)
{
    std::stringstream strStream{str};
    std::string word;
    int count = 0;
    while (strStream >> word)  // cin >> x  //  >> extraction operator
    {
        // extract a substring from strStream into word
        std::cout << count++ << " " << word << "\n";
    }
    return count;
}

int main()
{
    std::string inputStr;
    cout << "Enter a string: \n";
    std::getline(std::cin , inputStr);
    std::cout << countWords(inputStr) << std::endl;
    return 0;
}

/*
    https://www.cplusplus.com/reference/iostream/cin/
    std::cin
    extern istream cin;

    --- Standard input stream
    Object of class istream that represents the standard input stream oriented to narrow characters (of type char). 
    It corresponds to the C stream stdin.

    The standard input stream is a source of characters determined by the environment. 
    It is generally assumed to be input from an external source, such as the keyboard or a file.

    As an object of class istream, characters can be retrieved either as formatted data 
    using the extraction operator (operator>>) or as unformatted data, using member functions such as read.


*/