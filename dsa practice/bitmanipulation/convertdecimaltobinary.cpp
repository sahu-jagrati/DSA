#include <bits/stdc++.h>
using namespace std;

int convertDecimalToBinary(int n)
{
  string result;
  while (n > 0)
  {
    result += (n % 2) + '0'; // we add '0' to convert digit to character
    n = n / 2;
  }
  reverse(result.begin(), result.end());
  int binary = stoi(result);
  return binary;
}
// Returning int for binary is not recommended.

// Example:

// If n = 8
// Binary = "1000"
// Returned integer = 1000 (decimal thousand, not binary!)

// So it only looks like binary, but it's actually a decimal number

string convertDeciToBinary(int n)
{
  if (n == 0)
    return "0";
  string result;
  while (n > 0)
  {
    result += (n % 2) + '0';
    n = n / 2;
  }
  reverse(result.begin(), result.end());
  return result;
}
int main()
{
  int n;
  cin >> n;

  // int answer = convertDecimalToBinary(n);
  string answer = convertDeciToBinary(n);
  cout << answer << endl;
  return 0;
}

// built-in method
string convertdecimalTobinary(int n)
{
  return bitset<32>(n).to_string();
}