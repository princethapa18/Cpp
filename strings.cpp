/* char* 11 Feb 2022  

*/

#include <cstring>
#include <iostream>

/* 
------- "strlen"-----------------------------
defined in <cstring>
std::size_t strlen( const char* str );
Get string length
Returns the length of the C string str.

The length of a C string is determined by the terminating null-character: A C string is as 
long as the number of characters between the beginning of the string and 
the terminating null character (without including the terminating null character itself).
This should not be confused with the size of the array that holds the string. For example:

char mystr[100]="test string";
defines an array of characters with a size of 100 chars, 
but the C string with which mystr has been initialized has a length of only 11 characters. 
Therefore, while sizeof(mystr) evaluates to 100, strlen(mystr) returns 11.

In C++, char_traits::length implements the same behavior.

------- strdup --------------
Defined in header <string.h>
char *strdup( const char *src );
char *strdup( const char *src );  (since C23)
		
Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src. 
The space for the new string is obtained as if the malloc was invoked. The returned pointer must be passed to free to avoid a memory leak.

If an error occurs, a null pointer is returned and errno might be set.
Parameters
src 	- 	pointer to the null-terminated byte string to duplicate
Return value

A pointer to the newly allocated string, or a null pointer if an error occurred.

    const char *s1 = "Duplicate me!";
    char *s2 = strdup(s1);
    printf("s2 = \"%s\"\n", s2);
    free(s2);

*/


int main()
{
    //char *p1 = "prince";       //warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings]
    const char *p1 = "prince";  // this is okay
    // pointer p1 is pointing to const char    ---> first char element of the char array
    size_t sz = sizeof(*p1); // output = 1
    std::cout << sz;
    
    //char p2[2] = "hi";        // error: initializer-string for array of chars is too long [-fpermissive]
    char p[3] = "hi";   //  num of characters = 2 + 1 required for null terminating character

    char src[] = "thapa";    // sizeof(src) = 6 (5 + 1 for null terminating character ) and strlen(src) = 5
    size_t src_length = strlen(src);



    std::cout << "\nsizeof(src) " << sizeof(src) << " strlen(src) " << strlen(src) << "\n";
    for(auto i = 0; i < sizeof(src); i++)
    {
        if(src[i] == '\0')
            std::cout << " null terminating character in src\n";
        std::cout << src[i] << " ";
    }

    /*
    char *dest = nullptr; 
    strcpy(dest, src); // segmentation fault at runtime because no memory allocated to dest . dest has no space to copy from src
    */

    //char *dest = new char[src_length];
    
    /*  In this case dest won't have null terminating character . sizeof(dest) == strlen(dest) 
        char dest[strlen(src)]; // sizeof(dest) 5 strlen(dest) 5
        strcpy(dest, src);      // dest -->  't' 'h' 'a' 'p' 'a'
    */

   //char dest[strlen(src)-1];  // sizeof(dest) 4 strlen(dest) 5 
   //strcpy(dest, src);         // dest -->  't' 'h' 'a' 'p' '\0'

    //char *dest = (char*)malloc(strlen(src)*sizeof(char));  // sizeof(dest) 8 strlen(dest) 5
    //strcpy(dest, src);       // dest --> 't' 'h' 'a' 'p' 'a' '\0' '\0' '\0'

    //char *dest = new char[strlen(src)]; // sizeof(dest) 8 strlen(dest) 5
    // but this is not the correct way. Because it may or may not allocate enough

    char *dest = new char[strlen(src) + 1]; // 1 extra space for null terminating character also
    strcpy(dest, src);  // dest --> 't' 'h' 'a' 'p' 'a' '\0' '\0' '\0'

    std::cout << "\nsizeof(dest) " << sizeof(dest) << " strlen(dest) " << strlen(dest) << "\n";
    for(auto i = 0; i < sizeof(dest); i++)
    {
        if(dest[i] == '\0')
            std::cout << " null terminating character in dest\n";
        std::cout << dest[i] << " ";
    }

    char *dup = strdup(src); // sizeof(dup) 8 strlen(dup) 5
    std::cout << "\nsizeof(dup) " << sizeof(dup) << " strlen(dup) " << strlen(dup) << "\n";
    for(auto i = 0; i < strlen(dup); i++)
    {
        if(dup[i] == '\0')
            std::cout << " null terminating character in dup\n";
        std::cout << dup[i] << " ";
    }

    // dup --> 't' 'h' 'a' 'p' 'a'
    std::cout << "\n";
    char src1[] = "this is a very long sentence. some balasdadsa asdadsasa asdas dsadas dsa das dsadasd asd sa dasd asdsadas dsadasd sa asdasdasasdsdas sad sa sad sad";
    char *dest1 = (char*)malloc( (strlen(src1) + 1) * sizeof(char));
    strcpy(dest1, src1);
    std::cout << "\nsizeof(src1) " << sizeof(src1) << " strlen(src1) " << strlen(src1) << "\n";
    std::cout << "\nsizeof(dest1) " << sizeof(dest1) << " strlen(dest1) " << strlen(dest1) << "\n";
    for(auto i = 0; i < strlen(dest1); i++)
    {
        if(dest1[i] == '\0')
            std::cout << " null terminating character in dest1\n";
        std::cout << dest1[i] << " ";
    }

    return 0;
}

