/* Week 05 31 Jan 2022   
    Streams
    Read/Write Class Objects from/to File in C++

    cin, cout are objects
    << --> insertion operator    
    >> --> extraction operator     cin >> x     ; // extract value from std input stream

    Mode --> ios::in (read mode) ,  ios::out, ios::ate ( at end), ios::app (append) , ios::trunc (truncates the content before opening the file)

    ios 
    ostream 
    istream
    iostream
    fstream
    ifstream
    ofstream
    sstream
    istringstream
    ostringstream
    stringstream

    https://stackoverflow.com/questions/17001050/writing-a-class-object-into-a-file-using-fstream-and-then-read-it

                ofstream       +----+
              +-------------------->|File|
              |                     +----+
              |
       +------+------+
       | Application |
       +------+------+
              |
              |                     +-------+
              +-------------------->|Console|
                        cout        +-------+

    C++ uses the stream paradigm to implement standard input/output.
    Stream paradigm means that if you application wants to access/use a resource (A file, the console, etc) 
    a stream acts as a mediator between your application and the resource:

    It means every write/read operations you perform are really stream operations. 
    The point of this is that stream operations are basically the same, independently of what type of resource (And what type of stream) are you using.
    This allows us to implement a "generic" (Generic meaning valid for any type of stream/resource). How? Overloading C++ operators >> and <<.
    For input operations (Input means receiving data from the stream and put it in our variable/object), we need to overload the >> (extraction) operator as follows:
    
    istream& operator>>(istream& is , MyClass& object)
    {
        is >> object.myClassAtributte; (1)
        ... //Same for every attribute of your class.

        return is;
    }

    First, note that the input stream is passed by reference. 
    By reference because streams are non-copyable (What exactly means to copy a stream? 
    Copy the link between your app and the resource? That sounds ridiculous), 
    and non-const beacuse you are going to modify the stream (You are going to write through it).

    For output operations (Output means sending data to the stream), we need to overload the << operator, wich implementation is exactly the same:

    ostream& operator<<(ostream& os , const MyClass& object)
    {
        os << object.myClassAtributte; (1)
        ... //Same for every attribute of your class.
        return os;
    }

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Streams
{
    void fun()
    {
        int i;
        cout << "Please enter an interger value : "; // << two less than  ---> insertion operator    Insert the string "Please enter ...." to cout(std output stream)
        cin >> i; //  >> two greater than   ---> extraction operator       extract from cin (std input stream)
        cout << "The value entered is " << i;
        int *p = &i;
        cout << "\nValue of i is " << *p;
    }
}

namespace IO
{
    // No copy or Assign for IO objects;
    void fun()
    {
        ofstream out1, out2;
        auto& out3 = out1; // reference is okay
        //out1 = out2; // non copyable
        /*
        In function ‘void IO::fun()’:
        error: use of deleted function ‘std::basic_ofstream<char>& std::basic_ofstream<char>::operator=(const std::basic_ofstream<char>&)’
         out1 = out2;
        */
    }

    void openCloseFile(const string& fname)
    {
        /* ifstream (const char* filename , ios_base::open_mode mode) */
        ifstream infile(fname.c_str(), ios::in);  // or ifstream infile; infile.open(fname.c_str());
        if(!infile)
        {
            cerr << "error: unable to open file: " << fname << endl;
        }
        else
        {
            cout << "file : " << fname << " opened successfully\n";
            string line;
            infile.close();
        }
    }

}


namespace ReadWrite
{
    /*
    Given a file “Input.txt” in which every line has values same as instance variables of a class. 
    Read the values into the class’s object and do necessary operations.
    Theory : 

    The data transfer is usually done using '>>'
    and <<' operators. But if you have
    a class with 4 data members and want 
    to write all 4 data members from its
    object directly to a file or vice-versa, 
    we can do that using following syntax :

    To write object's data members in a file :
    // Here file_obj is an object of ofstream
    file_obj.write((char *) & class_obj, sizeof(class_obj));

    To read file's data members into an object :
    // Here file_obj is an object of ifstream
    file_obj.read((char *) & class_obj, sizeof(class_obj));
    */

   class Contestant
   {
    public:
        string name;
        int age, ratings;
        int input();
        int output_highest_rated();
        friend ostream& operator<< (ostream& stream, const Contestant& obj);
        friend istream& operator>> (istream& stream, Contestant& obj);

   };

    istream& operator>>(istream& is, Contestant& obj)
    {
        is >> obj.name;
        is >> obj.age;
        is >> obj.ratings;
    }
    ostream& operator<<(ostream& os, const Contestant& obj)
    {
        os << obj.name;
        os << obj.age;
        os << obj.ratings;
    }

    int Contestant::input()
    {
        // object to write in file
        ofstream outfile;
        outfile.open("Input.txt", ios::app);
        if(!outfile)
        {
            cerr << "Could not open file to write\n";
            return 0;
        }

        Contestant buf;
        buf.name = "Michael";
        buf.age = 20;
        buf.ratings = 2500;
        
        // writing the object's data in file
        outfile.write( (char*)&buf, sizeof(buf));

        buf.name = "Terry";
        buf.age = 21;
        buf.ratings = 3200;

        outfile.write( (char*)&buf, sizeof(buf) );
        return 1;
    }

    int Contestant::output_highest_rated()
    {
        ifstream infile;
        infile.open("Input.txt", ios::in);
        if(!infile)
        {
            cerr << "Could not open file to read\n";
            return 0;
        }
        Contestant buf{};
        // Reading from file into buffer object buf
        infile.read( (char*)&buf, sizeof(buf) );

        int max = 0;
        string highest_rated{""};

        //std::ios::eof
        while(!infile.eof())
        {
            if(buf.ratings > max)
            {
                max = buf.ratings;
                highest_rated = buf.name;
            }

            infile.read(  (char*)&buf , sizeof(buf));
        }

        cout << highest_rated << endl;

        return 1;
    }

}

int main()
{
    // here it gives error error: ‘namespace’ definition is not allowed here
    //namespace Test
    //{
    //}
    //Streams::fun();
    //string fname = "test.txt";
    //IO::openCloseFile(fname);
    
    ReadWrite::Contestant cobj;
    cobj.input();
    cobj.output_highest_rated();

    return 0;
}