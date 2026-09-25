// Given an integer num, return a string of its base 7 representation.

// Example 1:

// Input: num = 100
// Output: "202"
// Example 2:

// Input: num = -7
// Output: "-10"

// Constraints:

// -10^7 <= num <= 10^7

#include <bits/stdc++.h>
using namespace std;

// a number represents as a base-7 is made up from digits 0 to 6

// algorithm to convert base-10 integer (given) into base-7 number:
// Step-1: Divide the decimal number by 7
// Step-2: Get the integer quotient = num for next step and add the remainder in answer string.
// Step-3: Repeat the process with the quotient until our quotient becomes 0
// Step-4: Reverse the answer string of remainders and after reversing it is our answer

// Only When the given number in negative then we apply above algorithm with positive of number and in last in answer we add '-' in answer

// When we divide num with 7 remainder is from : 0 to 6

// t.c-O(no. of digits in num)
// s.c-O(ans size)

string convertToBase7(int num)
{
  // edge case
  if (num == 0)
  {
    return "0";
  }
  // we use temp because if num is negative then in that case we take positive of that
  int temp = num;
  if (temp < 0)
  {
    temp = -temp;
  }
  // answer string
  string ans = "";
  // we do until our temp==0
  while (temp != 0)
  {
    int remainder = temp % 7;
    ans = ans + to_string(remainder);
    temp /= 7;
  }
  // when num<0 so add in '-' in answer
  if (num < 0)
  {
    ans += '-';
  }
  // reverse the answer string
  reverse(ans.begin(), ans.end());
  return ans;
}

int main()
{
  int num;
  cin >> num;
  cout << convertToBase7(num);
  return 0;
}