// The value of an alphanumeric string can be defined as:

// The numeric representation of the string in base 10, if it comprises of digits only.
// The length of the string, otherwise.
// Given an array strs of alphanumeric strings, return the maximum value of any string in strs.

// Example 1:

// Input: strs = ["alic3","bob","3","4","00000"]
// Output: 5
// Explanation:
// - "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
// - "bob" consists only of letters, so its value is also its length, i.e. 3.
// - "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
// - "4" also consists only of digits, so its value is 4.
// - "00000" consists only of digits, so its value is 0.
// Hence, the maximum value is 5, of "alic3".
// Example 2:

// Input: strs = ["1","01","001","0001"]
// Output: 1
// Explanation:
// Each string in the array has value 1. Hence, we return 1.

// Constraints:

// 1 <= strs.length <= 100
// 1 <= strs[i].length <= 9
// strs[i] consists of only lowercase English letters and digits.

// we simply check if first char of string is alphabet then we check length or if whole string is digit then we convert the string into int

#include <bits/stdc++.h>
using namespace std;

int maximumValue(vector<string> &strs)
{
  int ans = INT_MIN;
  for (int i = 0; i < strs.size(); i++)
  {
    string str = strs[i];
    bool flag = 0;
    for (int j = 0; j < str.size(); j++)
    {
      if (str[j] >= 'a' && str[j] <= 'z')
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
    {
      int digit = stoi(str);
      ans = max(ans, digit);
    }
    else
    {
      ans = max(ans, (int)str.size());
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++)
  {
    cin >> strs[i];
  }
  cout << maximumValue(strs);
  return 0;
}