/*  3 April 2019

Memory Layout of C program
1) Stack
local/automatic variable
2) Heap
dynamically allocated memory
3) Text segment
Text segment contains machine code of the compiled program. sharable and read-only
4) Initialized data segment ( Data segment )
read-only and read-write
global, static, constant, and external variables ( declared with extern keyword ) that are initialized beforehand

5) Uninitialized Data segment ( bss [Block started by symbol])
uninitialized global, static, constant, and external variables ( declared with extern keyword ).
or initialized by 0;

gcc memory-layout.c -o memory-layout
size memory-layout.exe

=====================================
#include <stdio.h>

char c[]="rishabh tripathi";     //  global variable stored in Initialized Data Segment in read-write area
const char s[]="HackerEarth";    //  global variable stored in Initialized Data Segment in read-only area

void fun()
{
    int a; // local variable stored in stack
}

int main()
{
    static int i=11;             // static variable stored in Initialized Data Segment
    static int y;                // static variable stored in Uninitialized Data Segment
    static int z=0;              // static variable stored in Uninitialized Data Segment
    return 0;

    double d = 12.5;     // local variable stored in stack
    int *p = NULL;
    p = (int*) malloc(sizeof(int)*1); // memory allocated from Heap;
}
======================================

*/

/*
#include <stdio.h>
int main(void)
{
    return 0;
}

D:\myprog>gcc memory-layout.c -o memory-layout

D:\myprog>size memory-layout.exe
   text    data     bss     dec     hex filename
  13644    2400    2496   18540    486c memory-layout.exe
*/

/*
#include <stdio.h>
int global;         // bss 
static int a = 10;  // data segment 
int main(void)
{
    return 0;
}

D:\myprog>size memory-layout.exe
   text    data     bss     dec     hex filename
  13644    2416    2512   18572    488c memory-layout.exe
        (data segment)
  
*/

#include <stdio.h>
#include <stdlib.h>

static double ch;
int global;
int abc;
int main(void)
{
	static int c = 12;
	int x;
	float f =10;
	int *p = (int*)malloc(sizeof(int));
	double *d = (double*) malloc(sizeof(double)*3);
    return 0;
}
/*
D:\myprog>size memory-layout.exe
   text    data     bss     dec     hex filename
  13708    2416    2512   18636    48cc memory-layout.exe
                          heap     stack         
*/