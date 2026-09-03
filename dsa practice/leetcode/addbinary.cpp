// Given two binary strings a and b, return their sum as a binary string.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

// Constraints:

// 1 <= a.length, b.length <= 10^4
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

// Example you gave:

// a = "11" (binary → decimal 3)

// b = "1" (binary → decimal 1)

// sum=3+1=4 in binary it is 100
// answer=100

// Given
// a = "11"
// b = "1"

// First, make their lengths equal by thinking like this:

// a = 11
// b = 01

// Start adding from right to left (just like normal addition)
// Step 1 (rightmost bits)

// 1 + 1 = 2

// In binary, 2 = 10

// Write 0, carry 1

// Step 2 (next bits)

// 1 + 0 + carry(1) = 2

// Again, 2 = 10

// Write 0, carry 1

// Step 3 (leftover carry)

// Carry 1 remains → write it

// Final result
// 100

#include <bits/stdc++.h>
using namespace std;

// t.c-O(n+m) where n is string a size and m is string b size
// s.c-O(ans space)
string addBinary(string a, string b)
{
  int i = a.size() - 1;
  int j = b.size() - 1;
  int carry = 0;
  string ans = "";
  while (i >= 0 || j >= 0 || carry)
  {
    int sum = carry;
    if (i >= 0)
      // we do -'0' because a[i] and b[j] give char so for convert it in ascii value
      // ascii value of char '0' is 48 and char '1' is 49
      // so '0'-'0'=0 integer
      // and '1'-'0'=1 integer
      sum += a[i] - '0';
    if (j >= 0)
      sum += b[j] - '0';
    i--;
    j--;

    // we do binary addition so we do sum%2 for current binary digit and sum%2 is integer so +  '0' char gives char and push it
    ans.push_back((sum % 2) + '0');
    // and sum/2 gives carry
    carry = sum / 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
// Why + '0' then?

// Because:

// sum % 2 → gives number 0 or 1

// But string stores characters

// So:

// (sum % 2) + '0'

// Converts:

// 0 → '0'
// 1 → '1'

// Important clarification 🧠

// ❌ We are NOT converting sum into binary
// ✅ We are extracting one binary bit at a time

// This is exactly how manual binary addition works.

// Think of it like this

// Decimal addition:

// 18 % 10 → last digit
// 18 / 10 → carry

// Binary addition:

// sum % 2 → last binary digit
// sum / 2 → carry
int main()
{
  string a, b;
  cout << "Enter the binary string: ";
  cin >> a >> b;
  string answer = addBinary(a, b);
  cout << "Binary string addition: " << answer << endl;
  return 0;
}