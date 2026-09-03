// You are given a string s consisting of digits and an integer k.

// A round can be completed if the length of s is greater than k. In one round, do the following:

// Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on. Note that the size of the last group can be smaller than k.
// Replace each group of s with a string representing the sum of all its digits. For example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
// Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.
// Return s after all rounds have been completed.

// Example 1:

// Input: s = "11111222223", k = 3
// Output: "135"
// Explanation:
// - For the first round, we divide s into groups of size 3: "111", "112", "222", and "23".
//   ​​​​​Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5.
//   So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
// - For the second round, we divide s into "346" and "5".
//   Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5.
//   So, s becomes "13" + "5" = "135" after second round.
// Now, s.length <= k, so we return "135" as the answer.
// Example 2:

// Input: s = "00000000", k = 3
// Output: "000"
// Explanation:
// We divide s into "000", "000", and "00".
// Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, and 0 + 0 = 0.
// s becomes "0" + "0" + "0" = "000", whose length is equal to k, so we return "000".

// Constraints:

// 1 <= s.length <= 100
// 2 <= k <= 100
// s consists of digits only.

#include <bits/stdc++.h>
using namespace std;

// my solution- done by me fully
string sumOfDigit(string digit)
{
  int sum = 0;
  for (int i = 0; i < digit.size(); i++)
  {
    sum += (digit[i] - '0');
  }
  return to_string(sum);
}
string digitSum(string s, int k)
{
  if (s.size() <= k)
    return s;
  string ans = "";
  for (int i = 0; i < s.size(); i += k)
  {
    int j = i;
    string digit = "";
    int count = k; // use temp variable to keep k const for check in next string
    while (j < s.size() && count > 0)
    {
      digit += s[j];
      j++;
      count--;
    }
    ans += sumOfDigit(digit);
  }
  return digitSum(ans, k);
}

// optimized version
// Complexity
// Time: O(n log n) (shrinks each iteration) in worst case when k=2 each time string is half
// Space: O(n)
string digitsum(string s, int k)
{
  while (s.size() > k)
  {
    string ans = "";
    for (int i = 0; i < s.size(); i += k)
    {
      int sum = 0;
      for (int j = i; j < i + k && j < s.size(); j++)
      {
        sum += s[j] - '0';
      }
      ans += to_string(sum);
    }
    s = ans;
  }
  return s;
}
int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << digitSum(s, k) << endl;
  cout << digitsum(s, k);
  return 0;
}

// Why Time Complexity = O(n log n)?

// Your optimized solution repeatedly reduces the string size.

// 📌 What happens each iteration?
// You take groups of size k
// Replace each group with sum of digits
// So new string length becomes roughly:n/k

// Total iterations

// Each time size shrinks like:n->n/k->n/k^2->---

// This continues until size ≤ k.

// So number of iterations ≈ log(n)(base k)

// Work per iteration
// You scan the entire string once → O(n)
// ✅ Total Time Complexity
// O(n)*(logn)=O(nlogn)
// technically O(n logₖ n), but we write O(n log n))

// 🔹 2. Space Complexity = O(n)
// You create a new string ans each iteration
// Maximum size = n

// So:
// Space=O(n)

// // of my code

// Your code also follows the same idea, so:

// ✔️ Time Complexity:
// Outer loop → processes all characters → O(n)
// Recursion depth → log n

// 👉 So:
// Time=O(nlogn)

// More Accurate Analysis (Advanced Insight 💡)

// Actually, total work is:

// n+n/k+n/k^2+--
// This is a geometric series:
// <= n/(1-1/k)=O(n)

// so my code t.c in worst case -O(n)
// s.c-O(n)