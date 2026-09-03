// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

// Given a positive integer n, return the nth element of the count-and-say sequence.

// Example 1:

// Input: n = 4

// Output: "1211"

// Explanation:

// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
// Example 2:

// Input: n = 1

// Output: "1"

// Explanation:

// This is the base case.

// Constraints:

// 1 <= n <= 30

// Follow up: Could you solve it iteratively?

// Hint 1
// Create a helper function that maps an integer to pairs of its digits and their frequencies. For example, if you call this function with "223314444411", then it maps it to an array of pairs [[2,2], [3,2], [1,1], [4,5], [1, 2]].
// Hint 2
// Create another helper function that takes the array of pairs and creates a new integer. For example, if you call this function with [[2,2], [3,2], [1,1], [4,5], [1, 2]], it should create "22"+"23"+"11"+"54"+"21" = "2223115421".
// Hint 3
// Now, with the two helper functions, you can start with "1" and call the two functions alternatively n-1 times. The answer is the last integer you will obtain

#include <bits/stdc++.h>
using namespace std;

// using hint i do this problem fully by own
string arrToString(vector<pair<char, int>> &arr)
{
  string res = "";
  for (int i = 0; i < arr.size(); i++)
  {
    char ch = arr[i].first;
    int freq = arr[i].second;
    res += to_string(freq);
    res += ch;
  }
  return res;
}
// we use array of pairs for freq because if we use hashmap then it count all the same char in one freq while we want char freq index by index not want to combine same char freq in one
vector<pair<char, int>> helper(string str)
{
  vector<pair<char, int>> arr;
  int l = 0, r = 0;
  int freq = 0;
  while (r < str.size())
  {
    if (str[l] == str[r])
    {
      freq++;
      r++;
    }
    else
    {
      arr.push_back({str[l], freq});
      freq = 0;
      l = r;
    }
  }
  if (freq != 0)
  {
    arr.push_back({str[l], freq});
  }
  return arr;
}
// firtly i try by recursion
string countAndSay(int n)
{
  if (n == 1)
    return "1";
  string ans = "1";
  for (int i = 1; i < n; i++)
  {
    vector<pair<char, int>> arr = helper(ans);
    ans = arrToString(arr);
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  cout << countAndSay(n);
  return 0;
}