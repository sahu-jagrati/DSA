// You are given a 0-indexed string s that has lowercase English letters in its even indices and digits in its odd indices.

// You must perform an operation shift(c, x), where c is a character and x is a digit, that returns the xth character after c.

// For example, shift('a', 5) = 'f' and shift('x', 0) = 'x'.
// For every odd index i, you want to replace the digit s[i] with the result of the shift(s[i-1], s[i]) operation.

// Return s after replacing all digits. It is guaranteed that shift(s[i-1], s[i]) will never exceed 'z'.

// Note that shift(c, x) is not a preloaded function, but an operation to be implemented as part of the solution.

// Example 1:

// Input: s = "a1c1e1"
// Output: "abcdef"
// Explanation: The digits are replaced as follows:
// - s[1] -> shift('a',1) = 'b'
// - s[3] -> shift('c',1) = 'd'
// - s[5] -> shift('e',1) = 'f'
// Example 2:

// Input: s = "a1b2c3d4e"
// Output: "abbdcfdhe"
// Explanation: The digits are replaced as follows:
// - s[1] -> shift('a',1) = 'b'
// - s[3] -> shift('b',2) = 'd'
// - s[5] -> shift('c',3) = 'f'
// - s[7] -> shift('d',4) = 'h'

// Constraints:

// 1 <= s.length <= 100
// s consists only of lowercase English letters and digits.
// shift(s[i-1], s[i]) <= 'z' for all odd indices i.

#include <bits/stdc++.h>
using namespace std;

char shiftForward(char ch, int x)
{
  return ch + x; // in question they already say shift  will never exceed char 'z'
}
string replaceDigits(string s)
{
  int n = s.size();
  // we have to go only odd indices
  for (int i = 1; i < n; i += 2)
  {
    s[i] = shiftForward(s[i - 1], s[i] - '0'); // we have to convert character digit into integer before directly passing it
  }
  return s;
}
int main()
{
  string s;
  cin >> s;
  cout << replaceDigits(s);
  return 0;
}

// if we don't convert char digit into integer and pass it directly then following index out of bounds error occur-
// Your bug is here 👇

// s[i] = shiftForward(s[i-1], s[i]);
// ❌ Problem

// s[i] is a character digit like '1', '2', etc.

// But you're passing it directly as an int x, so:

// shiftForward(s[i-1], s[i])

// actually becomes:

// shiftForward('a', '3')  // '3' ASCII = 51 ❌

// So you're doing:

// return ch + 51;  // huge shift → invalid character → UB error

// That’s why you're getting weird values like -110.

// ✅ Fix

// Convert the digit character to an integer:

// s[i] = shiftForward(s[i-1], s[i] - '0');
// ✔️ Correct Code
// char shiftForward(char ch, int x) {
//     return ch + x;
// }

// public:
// string replaceDigits(string s) {
//     int n = s.size();
//     for (int i = 1; i < n; i += 2) {
//         s[i] = shiftForward(s[i - 1], s[i] - '0');  // FIX
//     }
//     return s;
// }
// 🔍 Example

// Input:

// s = "a1c1e1"

// Step-by-step:

// 'a' + 1 → 'b'
// 'c' + 1 → 'd'
// 'e' + 1 → 'f'

// Output:

// "abcdef"
// 💡 Key Takeaway

// Whenever working with digits in strings:

// char digit = '5';
// int num = digit - '0';  // ✅ correct way