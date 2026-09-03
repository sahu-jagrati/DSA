// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.

// Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/

#include <bits/stdc++.h>
using namespace std;

// We need a subsequence that:
// Contains every distinct character exactly once.
// Is lexicographically smallest

// let s="cbacdcbc"
// character 'a' last appears at index = 2
// character 'b' last appears at index = 6
// character 'c' last appears at index = 7
// character 'd' last appears at index = 4    // This tells us whether we can safely remove a character now because it will appear again later.

// We maintain
// stack<char>st -> current answer
// visited[26] -> whether a character is already in the stack
// last[26] -> last occurence index

// total t.c-O(n) where n is the size of string
// s.c-O(26)(last)+O(26)(visited)+O(26)(stack - atmost one of each lowercase letter) = O(1) + O(ans string size)
string smallestSubsequence(string s)
{
  vector<int> last(26); // this is for last occurence of character means last index where the character appear

  // O(n)
  for (int i = 0; i < s.size(); i++)
  {
    last[s[i] - 'a'] = i;
  }
  vector<bool> visited(26, false); // this check we visited this char already or not
  stack<char> st;
  // O(n) (each character is pushed and popped at most once)
  // traverse the string
  for (int i = 0; i < s.size(); i++)
  {
    char ch = s[i];
    // if already visited means already in the stack then skip it, don't insert duplicates- each character should appear exactly once.
    if (visited[ch - 'a'])
      continue;

    // here what we do is that ? at stack top() we want to put smaller char so we check if current char is smaller than top char then pop out top char but we also have to check that the top char is not the last occurence so if it is last occurence of thatt char then we don't remove it
    while (!st.empty() && st.top() > ch && last[st.top() - 'a'] > i)
    {
      visited[st.top() - 'a'] = false; // make it unvisited also
      st.pop();                        // pop out top elt if it is greater than current elt
    }
    st.push(ch);
    visited[ch - 'a'] = true;
  }
  string ans;
  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  // O(k), where k is the number of distinct characters (atmost 26)
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << smallestSubsequence(s);
  return 0;
  return 0;
}

// Why this condition?
// while(!st.empty()&&st.top()>ch&&lat[ch-'a']>i)

// i) st.top()>ch
// current character is smaller.
// replacing the top with currenct charcter makes the answer lexicographically smaller.

// ii) last[ch-'a']>i
// this is the important one.
// It means - the top character will come again later.
// therefore it's safe to remove it now.
// If not, you will never get that character back.

// iii) !visited[ch]
// don't insert duplicates.
// each character should appear exactly once.

// let's take an example-
// s="cbacdcbc"
//    01234567  <- indexing

// last['a']=2
// last['b']=6
// last['c']=7
// last['d']=4

// This tells us whether we can safely remove a character now because it will appear again later.

// We maintain
// stack<char> st → current answer
// visited[26] → whether a character is already in the stack
// last[26] → last occurrence index

// traverse the string

// i=0 , ch='c'
// stack is empty and visited['c']=false
// push 'c' in stack
// visited[c]=true

// i=1, ch='b'
// stack is not empty and top=c
// Is c>b? yes
// Can we remove c? Yes because c appears again at index 7.
// So pop c and visited[c]=false again
// Now push b.
// visited[b]=true
// so stack have 'b' only now

// i=2, ch='a'
// stack is not empty and top=b
// Is b>a? yes
// Can we remove b? Does b appear later? Yes because b appears again at index 6.
// So pop b and visited[b]=false again
// Now push a.
// visited[a]=true
// so stack have 'a' only now

// i=3, ch='c'
// stack is not empty and top=a
// Is a>c? No
// Push c and visited[c]=true again
// so stack have - 'a' ,'c' now with top='c'

// i=4,ch='d'
// stack is not empty and top=c
// Is c>d? No
// Push d and visited[d]=true
// so stack have - 'a' ,'c', 'd' now with top='d'

// i=5, ch='c'
// Already visited
// skip
// so stack have - 'a' ,'c', 'd' now with top='d'

// i=6, ch='b'
// // stack is not empty and top=d
// Is d>b? yes
// Can we remove b? Does d appear later? look at last occurence of d. last[d]=4 and current index=6.
// since 4<6 means there are no more d's
// so if we pop d, we'll lose it forever.
// so we cannot pop.
// Now push b.
// visited[b]=true
// so stack have 'a','c', 'd', 'b' now with top='b'

// i=7, ch='c'
// already visited
// skip
// string finish
// so now stack have 'a','c', 'd', 'b' with top='b'

// so we pop from the stack and append it in answer string and reverse it so we get answer="acdb"