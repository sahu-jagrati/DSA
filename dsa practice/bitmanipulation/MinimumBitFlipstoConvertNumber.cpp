// A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

// For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

// Example 1:

// Input: start = 10, goal = 7
// Output: 3
// Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
// - Flip the first bit from the right: 1010 -> 1011.
// - Flip the third bit from the right: 1011 -> 1111.
// - Flip the fourth bit from the right: 1111 -> 0111.
// It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
// Example 2:

// Input: start = 3, goal = 4
// Output: 3
// Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
// - Flip the first bit from the right: 011 -> 010.
// - Flip the second bit from the right: 010 -> 000.
// - Flip the third bit from the right: 000 -> 100.
// It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.

// Constraints:

// 0 <= start, goal <= 109

// Note: This question is the same as 461: Hamming Distance.

#include <bits/stdc++.h>
using namespace std;

// here in this problem we have to convert start into goal by minimum number of bit flips

// so if I take XOR of start and goal then the no. of set bits in start^goal=minimum bit flips because in XOR if we have even number of 1's then it is 0 and if we have odd number of 1's then it is 1 so when we take XOR if bit are same in number then it is 0 or if bit are different then it is 1 so no.of set bit (i.e 1) is our answer

// for an example : start=10 , goal=7
// 10 in binary-> 1010
// 7 in binary->  0111
// so minimum bit required to convert 10 to 7 here is 3

// now solution is if we take XOR
// ans=start^goal
//    1010
// ^
//    0111
// ans=1101   so see here for same bit we have 0 in ans and for different bit we have 1 in ans so no.of set bit(i.e 1 ) is the minimum bit flip because in that position the bits are different in given number

// now the problem is we have to count number of set bit
// so for that we know: ans&(ans-1) until ans==0 because we know from from first rightmost set bit ans-1 is flip of ans so we do AND so rightmost set bit become 0 until ans==0

// for more detail see notes

// t.c-O(32) because we know integer represents as a 32 bit so if all bit in ans is set bit then loop runs 32 times
// s.c-O(1)
int minBitFlips(int start, int goal)
{
  // first we take xor so we get the ans where we have to cnt no.of set bits
  int ans = start ^ goal;
  int cnt = 0;
  // now we cnt no. of set bits
  while (ans != 0)
  {
    ans = ans & (ans - 1);
    cnt++;
  }
  return cnt;
}

int main()
{
  int start, goal;
  cin >> start >> goal;
  cout << minBitFlips(start, goal);
  return 0;
}