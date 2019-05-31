/* 31 May 2019
   Knuth-Morris-Pratt string searching algorithm
   
   http://btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html
   https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
   https://brilliant.org/wiki/knuth-morris-pratt-algorithm/
   https://www.coursera.org/lecture/algorithms-on-strings/knuth-morris-pratt-algorithm-73RS1

   The worst case complexity of the Naive algorithm is O(m(n-m+1)). 
   The time complexity of KMP algorithm is O(n) in the worst case
 
*/

#include <iostream>
#include <string>

using namespace std;

//  text T[0...n-1]  and pattern P[0...m-1]

//  Longest proper Prefix which is also Suffix
void computeLPS(string& P, int *lps)
{
    int m = P.length();
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m)
    {
	if(P[i] == P[len])
	{
	    len++;
	    lps[i] = len;
	    i++;
	}
	else
	{
	    if(len != 0)
	    {
		len = lps[len - 1];
	    }
	    else
	    {
		lps[i] = 0;
		i++;
	    } 
	}
    }
}

int KMPStringMatching(string T, string P)
{
  int n = T.length(), m = P.length();
  if(m > n) return -1;
  
  int lps[m] = {0}, i = 0, j = 0;
  computeLPS(P, lps);
  
  //for(int k = 0; k < m; k++)
  //  cout << lps[k] << " ";
  
  while(i < n )
  {  
      if(T[i] == P[j])
      {
	  i++;
	  j++;
      }
      else if(T[i] != P[j])
      {
	  if(j != 0)
	    j = lps[j-1];
	  else
	    i++;
      }
      if(j == m) 
	  return (i-j);   
  }
  
  return -1;
}


int main()
{
  cout << "KMPStringMatching(abacaabacc, abacab) " << KMPStringMatching("abacaabacc", "abacab") << endl;
  cout << "KMPStringMatching(abacaabacab, abacab) " << KMPStringMatching("abacaabacab", "abacab") << endl;
  cout << "KMPStringMatching(mississippi, mississippi) " << KMPStringMatching("mississippi", "mississippi") << endl;
  cout << "KMPStringMatching(mississippi, issip) " << KMPStringMatching("mississippi", "issip") << endl;
  return 0;
}
