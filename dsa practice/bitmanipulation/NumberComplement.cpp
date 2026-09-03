// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

// Constraints:

// 1 <= num < 231

// Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

#include <bits/stdc++.h>
using namespace std;

// here we have to find the 1's complement

// suppose num=5 so in binary it is 101 so after flip we get 010 which is 2 in decimal so ans=2

// brute force: i) first convert num in binary
// ii) then flip every bit
// iii) then convert binary back into decimal

// optimal-

// we have num=5 so in binary it is 101 it has 3 bits so if I take 3 bits 1 then let mask=111
// if we take XOR of num and mask -:  (101)^(111)=010 which is the flip of 101 so our answer is 010 which is 2 in decimal

// no how we take 111? it is the same number of bits as the binary representation of num.

// e.g- num=5, in binary it is 101 which is 3 bits so we take 111
// num=10, in binary it is 1010 which is 4 bits so we take 1111
// (1010)^(1111)=0101 which is 5 in decimal

// But how we know that how many number of bits are in binary representation of num?
// For that we create the mask:
// Mask in bit manipulation is simply a number used to control, select, or modify specific bits of another number.

// For the number complement problem, the mask is simple:
// The mask is a binary number containing 1s in exactly the same number of positions as the original number.

// Example: 5
// 5 = 101

// It has 3 bits, so we create a mask with 3 ones:

// mask = 111

// Now XOR:

//   101   ← number
// ^ 111   ← mask
// -----
//   010   ← complement

// So the answer is 2.

// Why does 111 help?

// Remember XOR:

// 0 ^ 1 = 1
// 1 ^ 1 = 0

// So XORing with 1 flips the bit.

// Therefore:

// 101
// 111
// ---
// 010

// Every bit gets flipped.

// Another example: 10
// 10 = 1010

// 4 bits → mask needs 4 ones:

// mask = 1111

// Then:

//   1010
// ^ 1111
// ------
//   0101

// Answer = 5.

// n one line

// Think of a mask as a tool/pattern of bits that you use with operations like &, |, and ^ to manipulate particular bits.

// For Number Complement: mask=2^(number of bits) - 1
// for 5: mask=(2^3) - 1 = 7
// and 7 in binary is 111 so mask=111

// t.c-O(log n)(base 2) because temp is always half each time , decrease by power of 2
// s.c-O(1)
int findComplement(int num)
{
  int mask = 0;
  int temp = num;
  while (temp > 0)
  {
    mask = (mask << 1) | 1;
    temp >>= 1;
  }
  return num ^ mask;
}

int main()
{
  int num;
  cin >> num;
  cout << findComplement(num);
  return 0;
}