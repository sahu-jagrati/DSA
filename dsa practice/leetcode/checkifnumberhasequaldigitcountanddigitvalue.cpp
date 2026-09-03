// You are given a 0-indexed string num of length n consisting of digits.

// Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.

// Example 1:

// Input: num = "1210"
// Output: true
// Explanation:
// num[0] = '1'. The digit 0 occurs once in num.
// num[1] = '2'. The digit 1 occurs twice in num.
// num[2] = '1'. The digit 2 occurs once in num.
// num[3] = '0'. The digit 3 occurs zero times in num.
// The condition holds true for every index in "1210", so return true.
// Example 2:

// Input: num = "030"
// Output: false
// Explanation:
// num[0] = '0'. The digit 0 should occur zero times, but actually occurs twice in num.
// num[1] = '3'. The digit 1 should occur three times, but actually occurs zero times in num.
// num[2] = '0'. The digit 2 occurs zero times in num.
// The indices 0 and 1 both violate the condition, so return false.

// Constraints:

// n == num.length
// 1 <= n <= 10
// num consists of digits.

#include <bits/stdc++.h>
using namespace std;

// first mistake i do is that using num[i] directly
// num[i] is a character, not an integer
// so we have to convert it in integer- num[i]-'0'

// second mistake- mpp[num[i]]++ storee frequency of characters like '0','1',etc but later we check if(mpp[i]!=num[i]) here i is an index, not a digit character- mismatch
// bool digitCount(string num)
// {
//   int n = num.size();
//   vector<int> mpp(n, 0);
//   for (int i = 0; i < n; i++)
//   {
//     mpp[num[i]]++;
//   }
//   for (int i = 0; i < n; i++)
//   {
//     if (mpp[i] != num[i])
//       return false;
//   }
//   return true;
// }

// i think code fully, only i do mistakes are above mention
// and we can also use an array instead of map- faster (O(1) access)

// problem when we take this- vector<int> mpp(n, 0);
// this assumes digits are only from 0 to n-1
// but what if input contains a digit>=n?
// Example:
// num = "3210"

// n = 4

// digits: 3,2,1,0 → OK

// BUT:

// num = "5123"

// digit 5 → ❌ out of bounds (mpp[5] doesn't exist)
// safer version is - always use size 10(digit 0-9) vector<int>mpp(10,0)

// we have to generally also think that when we do frequency count by using array then the size should be fixed because we initially put there frequency=0 and if we think that array of isze is n how can be possible this because for frequency number is repeated and n is size of num, not the fixed value that is occur in num
// t.c-O(n+n)=O(n)
// s.c-O(1) (since mpp's sized is constant)
bool digitCount(string num)
{
  int n = num.size();

  vector<int> mpp(10, 0); // fixed size
  for (int i = 0; i < n; i++)
  {
    mpp[num[i] - '0']++; // do conversion also
  }
  for (int i = 0; i < n; i++)
  {
    if (mpp[i] != (num[i] - '0')) // here also convert char into integer then check
      return false;
  }
  return true;
}

// Constraints:

// n == num.length
// 1 <= n <= 10
// num consists of digits.
int main()
{
  string num;
  cin >> num;
  cout << digitCount(num) << endl;
  return 0;
}