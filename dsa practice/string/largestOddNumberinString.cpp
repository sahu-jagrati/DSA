// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: num = "52"
// Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
// Example 2:

// Input: num = "4206"
// Output: ""
// Explanation: There are no odd numbers in "4206".
// Example 3:

// Input: num = "35427"
// Output: "35427"
// Explanation: "35427" is already an odd number.

// Constraints:

// 1 <= num.length <= 10^5
// num only consists of digits and does not contain any leading zeros.

#include <bits/stdc++.h>
using namespace std;

// my thinking
// but still my code is not work for very very large number.
// long long number=stoll(num)- This will crash (out_of_range) if num is very large (which is exactly the case in this problem — strings can be up to 10⁵ digits).
// string largestOddNumber(string num)
// {
//   // int number=stoi(num);
//   // but num can be very large so i used stoll - where ll is long long.
//   long long number = stoll(num);
//   if (number % 2 != 0)
//     return to_string(number);
//   while (number > 0)
//   {
//     if (number % 2 != 0)
//       return to_string(number);
//     number /= 10;
//   }
//   return "";
// }

// simple approach is we don't need to convert to number at all
// for odd number we have to check only last digit so Just find the rightmost odd digit and return substring till there.
// Why this works
// A number is odd if last digit is odd
// So:
// Traverse from right
// First odd digit → that index is your answer
// Return substring till that index
// t.c-O(n)
// s.c-O(1)
string largestOddNumber(string num)
{
  for (int i = num.size() - 1; i >= 0; i--)
  {
    if ((num[i] - '0') % 2 != 0)
      return num.substr(0, i + 1);
  }
  return "";
}
// Key Takeaway
// ❌ Never use stoll() for large strings
// ✅ Use string logic instead (very common CP trick)
int main()
{
  string num;
  cin >> num;
  cout << largestOddNumber(num);
  return 0;
}