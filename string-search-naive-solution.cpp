// 31 may 2019
#include <iostream>
#include <string>

/*  Naive solution  
 *  Text T[i...n-1]   Pattern P[j...m-1]
 *  O(m*(m-n+1))
*/

using namespace std;

int strStr(string haystack, string needle) 
{
	if(needle.empty()) return 0;
	int n = haystack.length();
	int m = needle.length(); 
	if( m > n  ) 
	    return -1;

	int i = 0, j = 0; 
	
	for(i = 0; i <= n-m; i++)
	{
	    for(j = 0; j < m ; j++)
	    {
		if(haystack[i + j] != needle[j])
		  break;
	    }
	    
	    if(j==m)
	      return i;
	}
	
	return -1;
}


int main()
{
	cout << "strStr(\"ababcd\", \"abc\") " << strStr("ababcd", "abc") << endl;
	cout << "strStr(\"hello\", \"ll\") " << strStr("hello", "ll") << endl;
	cout << "strStr(\"mississippi\", \"mississippi\") " << strStr("mississippi", "mississippi") << endl;
	cout << "strStr(\"mississippi\", \"issip\") " << strStr("mississippi", "issip") << endl;
	cout << "strStr(\"abacaabacc\", \"abacab\") " << strStr("abacaabacc", "abacab") << endl;
        cout << "strStr(\"abacaabacab\", \"abacab\") " << strStr("abacaabacab", "abacab") << endl;
	return 0;
}
