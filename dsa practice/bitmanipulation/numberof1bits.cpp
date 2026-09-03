// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

// Constraints:

// 1 <= n <= 2^31 - 1

// Follow up: If this function is called many times, how would you optimize it?

#include <bits/stdc++.h>
using namespace std;

// brute force
int hammingWeight(int n)
{
  if (n == 1)
    return 1;
  // string result; // making string is useless
  int setBit = 0;
  while (n > 0)
  {
    if ((n % 2) == 1)
    {
      setBit++;
    }
    // result += (n % 2) + '0';
    n /= 2;
  }
  return setBit;
}

// better solution- using bitwise operations
// (n&1) is simialr to (n%2)
// n>>1 is simialr to (n/2)
// we use bitwise because bitwise operations are faster
// t.c-O(log(n)(base 2)) in worst case =O(31)

// for understanding see notes
int cntSetBit(int n)
{
  int setBit = 0;
  while (n > 0)
  {
    setBit += (n & 1); // check last bit, similar to (n%2) if return 1 then stBit+=1 or if return 0 then setBit+=0
    n = n >> 1;        // right shift which do n=n/2
  }
  return setBit;
}

// optimal approach-Brian Kernighan's Algorithm

// t.c-)(number of set bits) in worst case=O(31)
//  normal method-O(32)
//  kernighan's- O(number of set bits)
// this approach can be apply because most numbers don't have all of bits =1

// for understanding see notes
int setBit(int n)
{
  int cnt = 0;
  while (n != 0)
  {
    n = n & (n - 1);
    cnt++;
  }
  return cnt;
}

int main()
{ // n is positive
  int n;
  cin >> n;

  // int answer = hammingWeight(n);
  int answer = cntSetBit(n); // best is using bitwise operations

  // int answer = setBit(n); // we can also use this

  cout << answer << endl;
  return 0;
}

// in good way
int cntSetBit(int n)
{
  int cnt = 0;
  while (n > 1)
  {
    cnt += (n & 1); // n&1 is forchecking odd if odd it give 1 else give 0
    n = (n >> 1);
  }
  if (n == 1)
    cnt += 1;
  return cnt;
}

// there is builtin function also for count number of set bit but this is depen on the c++ version we used and generally we don't use it