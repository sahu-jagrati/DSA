// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
// Example 2:

// Input: s = "a"
// Output: 0
// Example 3:

// Input: s = "ab"
// Output: 1

// Input: s = “bababcbadcede”
// Output: 4
// Explanation: If we do 4 partitions in the following way, each substring of the partition will be a palindrome.
// bab | abcba | d | c | ede.

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters only.

// this problem will not be similar to MCM DP rather this will come under partition DP here we will use front partition technique

#include <bits/stdc++.h>
using namespace std;

// In order to solve this problem, we need to partition the given string in such a way that every substring of the partition becomes a palindrome. One key point to notice here is that we can make every substring of any string a palindrome, by partitioning it n-1 times as every string of length one is a palindrome.
// example: we have s="aabb" here n is the length of the string so a|a|b|b string of length 1 is a palindrome so here we do n-1 = 4-1=3 partition so we can make every substring of any string a palindrome, by partitioning it n-1 times as every string of length one is a palindrome.

// But we want minimum cuts needed for a palindrome partitioning of s.
// so n-1 is maximum number of cuts needed for a palindrome partitioning of s.
// but here we have to find minimum number of partitions. Does an answer always exist? Yes, because if I do n-1 partitions everyone will be a single character and everyone will be a palindrome in itself so that is for sure

// This type of problem is typically approached using the front partition technique.

//  Starting from the first index of the given string, we check whether a partition can be made between the first and second indices. Next, we include the second index and check if a partition is possible between the second and third indices. This process continues sequentially until the last index of the string. A partition is considered valid only if the substring on the left side of the partition is a palindrome.

// so if left side of the substring is palindrome then we add 1 in number of cuts and again partition the right substring to check it

// like we have a string s="bababcbadcede"

// we call       f(bababcbadcede)   partition at each index and check it is palindrome or not
// i) partition after 'b' we have this and 'b' is palindrome:       b|ababcbadcede    so 1+f(ababcbadcede) next call
// ii) if we partition after 'a' then we have : ba|babcbadcede  but here in left 'ab' is not palindrome so not valid partition
// iii) if we partition after 'b' then we have : bab|abcbadcede so here in left we have 'bab' which is a palindrome so 1+f(abcbadcede) and recursively call
// iv) if we partition after 'a' then we have: baba|bcbadcede but here in left 'baba' is not palindrome so not valid partition
// v) if we partition after 'b' then we have: babab|cbadcede so here in left we have 'babab' which is palindrome so 1+f(cbadcede)

// similalry we try all possible partitions in given string and take min(of all partitions)

// Start from the first index of the string s.

// Iterate over all possible substrings starting at the current index.

// For each substring, check if it is a palindrome.

// If the substring is a palindrome, recursively solve the problem for the remaining substring starting right after the current substring.

// Calculate the minimum cuts needed by choosing the substring partitions that lead to the least number of cuts.

// Return 0 cuts if the whole substring is already a palindrome (base case).

// rules of writing a recurrence:
// 1. Express everything in terms of an index.
// so let we have s="bababcbadcede" so here we start partition from front so from i=0
// 2. Express all possibilities
// 3. take the min of all possibilities
// 4. write the base case

// f(i) where i is a index from where we will start to make the partition

// base case: we try out all partitions as we start from index=0 and go upto n-1 because we already proved that maximum number of partition is n-1 so we can say that when i==n we cannot do any partition so
// if(i==n)return 0; // is the base case

// initially we start recursion from index=0
// f(i){
// base case
// if(i==n)return 0; means whenever we reach the end there is no partition so return 0

// int mini=INT_MAX;
// try out all partitions
// we keep a temp string to store left part and check it is a palindrome or not
// string temp="";
// for(int j=i;j<n;j++){
// so we check for a left string sthat it is a palindrome or not and recursively call for a right substring which is from j+1 index
// temp+=s[j]; // because from i to j will always be store in that temp string
// now when we can make a partition is the question? I can definitely make a partition if a temp string is palindrome i.e left side string is palindorme and recursively call for a right string
// if(isPalindrome(temp)){
// int cost=1+f(j+1);
// mini=min(mini,cost);
// }
//}
// return mini;
//}

bool isPalindrome(int i, int j, string &str)
{
  while (i < j)
  {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

// recursion
// t.c-exponential in nature
// s.c-O(n) auxiliary stack space
int f1(int i, string &str, int n)
{
  // base case when we reach the end there is no partition then return 0
  if (i == n)
    return 0;

  int miniPartition = INT_MAX;
  // string temp = ""; // when we do a partition at j then the string on left is always be from i...j so no need to store separately left partition string in temp
  // try out all possible partitions
  for (int j = i; j < n; j++)
  {
    // temp += str[j];
    if (isPalindrome(i, j, str))
    {
      int partition = 1 + f1(j + 1, str, n); // recursively call for right partition string
      miniPartition = min(miniPartition, partition);
    }
  }
  return miniPartition;
}

// memoization
// there can be overlapping subproblems so we apply memoization
// we have one changing parameter i which go from 0 to n-1 so we declare dp[n] 1D array

// t.c
// for i it run n times and for each i in worst case j runs n times and we check palindorme or not so n also so
// total t.c-O(n*n*n)=O(n^3)
// s.c-O(n)(for dp array)+O(n)(for auxiliary stack space)
int f2(int i, int n, string &str, vector<int> &dp)
{
  // base case when we reach the end there is no partition then return 0
  if (i == n)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  int miniPartition = INT_MAX;
  // string temp = ""; // when we do a partition at j then the string on left is always be from i...j so no need to store separately left partition string in temp
  // try out all possible partitions
  for (int j = i; j < n; j++)
  {
    // temp += str[j];
    if (isPalindrome(i, j, str))
    {
      int partition = 1 + f1(j + 1, str, n); // recursively call for right partition string
      miniPartition = min(miniPartition, partition);
    }
  }
  return dp[i] = miniPartition;
}

// tabulation
// 1. write base case
// 2. write changing parameter in opposite fashion of recursion
// 3. copy the recurrence
// t.c
// for i it run n times and for each i in worst case j runs n times and we check palindorme or not so n also so
// total t.c-O(n*n*n)=O(n^3)
// s.c-O(n)(for dp)
int f3(int n, string &str)
{
  vector<int> dp(n + 1, 0); // we declare dp of size n+1 because when i==n we return 0 so for storing i==n we want n+1 size
  // base case when we reach the end there is no partition then return 0, in recursion we have if(i==n)return 0;
  dp[n] = 0;

  // try out all partitiones
  // as in recursion i go from 0 to n-1 so in tabulation it is opposite so i go from n-1 to 0
  for (int i = n - 1; i >= 0; i--)
  {
    // copy the recurrence
    int miniPartition = INT_MAX;
    // string temp = ""; // when we do a partition at j then the string on left is always be from i...j so no need to store separately left partition string in temp

    for (int j = i; j < n; j++)
    {
      // temp += str[j];
      if (isPalindrome(i, j, str))
      {
        int partition = 1 + dp[j + 1]; // recursively call for right partition string
        miniPartition = min(miniPartition, partition);
      }
    }
    dp[i] = miniPartition;
  }
  return dp[0];
}

// as when we have s="abc" here we required only 2 partitions to get every substring palindrome i) first partition is a|bc and ii) second partition is a|b|c so total we have 2 partition but our code does first partition a|bc and calls for bc and does a second partition for b which is this  a|b|c and then calls for c and then for c does a partition here like this a|b|c| eventually calls for i==n so what happens is it does a partition right at the end so what we just need to make sure is whatever answer comes since it is doing a partition at the end we just need to minus 1 from answer so ans=ans-1;  in last whatever ans comes

// for more understanding try on paper take an any example like s="abc"

// first call f(0) -> cost=1+f(1) -> f(1)-> cost=1+f(2)-> f(2)-> cost=1+f(3) and now i==n=3 so it return 0  so for f(2)=1+0=1 then for f(1)=1+1=2 then for f(0)=1+2=3 mini=3 so what happens is it does the partition right at the end so we do minus 1 in the answer so ans=3-1=2

int palindromePartitioning(string &str)
{
  int n = str.size();
  // recursion - initially we start from index=0 to partition the given string which is a front partition technique
  // in starting we have an entire array 
  // return f1(0, str, n) - 1; // why we do minus 1? reason is  mention above

  // memoization
  // vector<int> dp(n, -1);
  // return f2(0, n, str, dp) - 1;

  // tabulation
  return f3(n, str) - 1;
}
int main()
{
  string str;
  cin >> str;
  cout << palindromePartitioning(str);
  return 0;
}