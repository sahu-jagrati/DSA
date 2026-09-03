// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

// Example 1:

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:

// Input: jewels = "z", stones = "ZZ"
// Output: 0

// Constraints:

// 1 <= jewels.length, stones.length <= 50
// jewels and stones consist of only English letters.
// All the characters of jewels are unique.

// You are given two strings:

// jewels → contains characters that represent jewel types.

// stones → contains characters that represent stones you have.

// Each character = one type of stone.

// ⚠ Letters are case-sensitive:

// 'a' ≠ 'A'

// 'b' ≠ 'B'

// 🎯 What You Need To Find

// Count how many characters in stones are also present in jewels.

// In simple words:

// 👉 From all the stones you have, how many are jewels?

// 🔎 Example 1
// jewels = "aA"
// stones = "aAAbbbb"

// Step-by-step:

// Jewels allowed: 'a' and 'A'

// Stones you have: a A A b b b b

// Count how many are jewel types:

// a ✅

// A ✅

// A ✅

// b ❌

// b ❌

// b ❌

// b ❌

// Total jewels = 3

// 🔎 Example 2
// jewels = "z"
// stones = "ZZ"

// Jewels = 'z'

// Stones = 'Z', 'Z'

// Since case matters:

// 'Z' ≠ 'z'

// Answer = 0

#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones)
{
  int n = jewels.size();
  int m = stones.size();
  unordered_map<char, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[jewels[i]]++;
  }
  int count = 0;
  for (int i = 0; i < m; i++)
  {
    if (mpp.count(stones[i])) // count() function is similar to find() function
      count++;
  }
  return count;
}

int main()
{
  string jewels, stones;
  cout << "Enter the string: ";
  cin >> jewels >> stones;

  cout << numJewelsInStones(jewels, stones) << endl;
  return 0;
}