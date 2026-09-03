#include <iostream>
#include <string>
using namespace std;

// used only lowercase letters

int strStr(string haystack, string needle)
{
  if (needle.empty())
    return 0;
  int n = haystack.size();
  int m = needle.size();

  for (int i = 0; i <= n - m; i++)
  {
    int j = 0;
    while (j < m && haystack[i + j] == needle[j])
    {
      j++;
    }
    if (j == m)
    {
      return i; // found the needle
    }
  }
  return -1; // not found the needle
}
int main()
{
  string haystack;
  string needle;
  cin >> haystack;
  cin >> needle;
  int result = strStr(haystack, needle);
  cout << result << endl;
  return 0;
}