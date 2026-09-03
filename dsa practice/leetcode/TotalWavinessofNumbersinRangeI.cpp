// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].

// Example 1:

// Input: num1 = 120, num2 = 130

// Output: 3

// Explanation:

// In the range [120, 130]:
// 120: middle digit 2 is a peak, waviness = 1.
// 121: middle digit 2 is a peak, waviness = 1.
// 130: middle digit 3 is a peak, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 2:

// Input: num1 = 198, num2 = 202

// Output: 3

// Explanation:

// In the range [198, 202]:
// 198: middle digit 9 is a peak, waviness = 1.
// 201: middle digit 0 is a valley, waviness = 1.
// 202: middle digit 0 is a valley, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 3:

// Input: num1 = 4848, num2 = 4848

// Output: 2

// Explanation:

// Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

// Constraints:

// 1 <= num1 <= num2 <= 10^5

#include <bits/stdc++.h>
using namespace std;

// I solve this problem by brute force so we check each number in the range and for each number we check each digit except first and last digit of number

int countPeakAndValley(int num)
{
  // first we convert num into string to extract digits easily
  string str = to_string(num);
  int n = str.size();
  int cnt = 0;
  // we don't go for i=0 and i=n-1 because for them there is no i-1 and i+1 they give out of bound
  for (int i = 1; i < n - 1; i++)
  {
    // for comparing digits we have to convert char into digits
    int prevDigit = str[i - 1] - '0';
    int currDigit = str[i] - '0';
    int nextDigit = str[i + 1] - '0';
    // for peak - strictly greater
    if (prevDigit < currDigit && currDigit > nextDigit)
      cnt++;
    // for valley- strictly lesser
    else if (prevDigit > currDigit && currDigit < nextDigit)
      cnt++;
  }
  return cnt;
}

int totalWaviness(int num1, int num2)
{
  int cnt = 0;
  for (int i = num1; i <= num2; i++)
  {
    cnt += countPeakAndValley(i);
  }
  return cnt;
}

int main()
{
  int num1, num2;
  cin >> num1 >> num2;
  cout << totalWaviness(num1, num2);
  return 0;
}