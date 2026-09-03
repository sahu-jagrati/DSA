// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false

// Constraints:

// 1 <= n <= 231 - 1

#include <bits/stdc++.h>
using namespace std;

// solution is easy we know, we have to determine only when we have to stop the process so
// first when n==1 after replace the number by the sum of the squares of its digits.
// second if the number os not happy then in that case we do the process until we get the same number by replace the number by the sum of the squares of its digits means loops endlessly in a cycle

bool happyNumber(int n)
{
  int temp = n;
  unordered_set<int> seen; // we used set to store n after every process and check if n is repeat then it is not happy means it never ends with 1
  while (temp != 1 && !seen.count(temp))
  {
    seen.insert(temp);
    int sum = 0;
    while (temp > 0)
    {
      int digit = temp % 10;
      sum = sum + (digit * digit);
      temp /= 10;
    }
    temp = sum;
  }
  return temp == 1;
}

int main()
{
  int n;
  cin >> n;
  cout << happyNumber(n) << endl;
  return 0;
}