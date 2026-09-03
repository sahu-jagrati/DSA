// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, return the Hamming distance between them.

// Example 1:

// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.
// Example 2:

// Input: x = 3, y = 1
// Output: 1

// Constraints:

// 0 <= x, y <= 231 - 1

// Note: This question is the same as 2220: Minimum Bit Flips to Convert Number

#include <bits/stdc++.h>
using namespace std;

// it is same to same to question "Min Bit Flips to Convert Number"

// here also they ask to cnt no.of positions where bits are different in two integers so means we have to cnt min bit flips so that we convert x into y

// x is start and y is goal

// t.c-O(32) because we know integer represents as a 32 bit so if all bit in ans is set bit then loop runs 32 times
// s.c-O(1)
int hammingDistance(int x, int y)
{
  int ans = x ^ y;
  int cnt = 0;
  while (ans != 0)
  {
    ans = ans & (ans - 1);
    cnt++;
  }
  return cnt;
}

int main()
{
  int x, y;
  cin >> x >> y;
  cout << hammingDistance(x, y);
  return 0;
}