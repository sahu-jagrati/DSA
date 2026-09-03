// Given a valid (IPv4) IP address, return a defanged version of that IP address.

// A defanged IP address replaces every period "." with "[.]".

// Example 1:

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"
// Example 2:

// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"

// Constraints:

// The given address is a valid IPv4 address.

#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address)
{
  int n = address.size();
  string answer = "";
  for (int i = 0; i < n; i++)
  {
    if (address[i] == '.')
    {
      answer += '[';
      answer += '.';
      answer += ']';
    }
    else
    {
      answer += address[i];
    }
  }
  return answer;
}
int main()
{
  string address;
  cin >> address;
  cout << defangIPaddr(address);
  return 0;
}