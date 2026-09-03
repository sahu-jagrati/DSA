// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

// Example 3:
// Input: s = "abc"
// Output: 1

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters

#include <bits/stdc++.h>
using namespace std;

// done by me
// naive solution - generate all substring having atleast one occurrence of all these characters a, b and c.
// t.c-O(n^2) where n is length of string, we use map but its size is constant which is 3 at max
// s.c-O(1)
int numberOf(string s)
{
  int n = s.size();
  int cnt = 0;
  unordered_map<char, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp.clear();
    for (int j = i; j < n; j++)
    {
      mpp[s[j] - 'a']++;
      if (mpp.size() == 3)
        cnt++;
    }
  }
  return cnt;
}

// brute solution-generate all substring having atleast one occurrence of all these characters a, b and c.
// t.c-O(n^2) where n is length of string
// s.c-O(1)  because hasharray has constant size 3

int cntNumberOf(string s)
{
  int n = s.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    vector<int> hasharray(3, 0); // for three characters - a,b,c
    for (int j = i; j < n; j++)
    {
      hasharray[s[j] - 'a'] = 1;
      if (hasharray[0] + hasharray[1] + hasharray[2] == 3)
        cnt++;
    }
  }
  return cnt;
}

// better solution-if we get first substring for i in brute solution then after this for all j we have substring so we can do cnt=cnt+(n-j) when we get first substring and break

// t.c is better in average case but in worst case it still O(n^2) where n is size of string when s=aaaaaa we never get our first substring of given condition so it run fully
// s.c-O(1) because hasharray has constant size 3
int cntNumberOfSubstring(string s)
{
  int n = s.size();
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    vector<int> hasharray(3, 0); // for three characters - a,b,c
    for (int j = i; j < n; j++)
    {
      hasharray[s[j] - 'a'] = 1;
      if (hasharray[0] + hasharray[1] + hasharray[2] == 3)
      {
        cnt = cnt + (n - j);
        break;
      }
    }
  }
  return cnt;
}

// optimal solution-with every character there is a substring that ends
//  here we make lastseen of index of every character whenever we seen them, when we see one of them and if each three character lastseen!=-1 then  those have min lastseen index and +1 to it give number of substring upto the current pointer
//  for more details see notes
// Intuition (why this works)

// lastSeen[x] → last index where 'a', 'b', or 'c' appeared

// When all three are seen, every substring that:

// ends at index i

// starts anywhere from 0 to the minimum lastSeen index
// is valid

// t.c-O(n) where n is size of string
// s.c-O(1) because lastseen array has size =3
int numberOfSubStringWithThreeChar(string s)
{
  int n = s.size();
  int cnt = 0;
  vector<int> lastSeen(3, -1); // initially for three characters - a,b,c
  for (int i = 0; i < n; i++)
  {
    lastSeen[s[i] - 'a'] = i;
    // when all three character we get
    if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
    {
      cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
    }
  }
  return cnt;
}
int main()
{
  string s;
  cout << "Enter the string: ";
  cin >> s;
  cout << "Number of substrings containing at least one occurrence of all these characters a, b and c:  " << numberOf(s) << endl;
  // cout << "Number of substrings containing at least one occurrence of all these characters a, b and c:  " << cntNumberOf(s) << endl;
  // cout << "Number of substrings containing at least one occurrence of all these characters a, b and c:  " << cntNumberOfSubstring(s) << endl;
  // cout << "Number of substrings containing at least one occurrence of all these characters a, b and c:  " << numberOfSubStringWithThreeChar(s) << endl;
  return 0;
}