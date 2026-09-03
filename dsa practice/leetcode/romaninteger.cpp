#include <iostream>

using namespace std;

// but it was run in leetcode with all complete test cases passed
int romanToInt(string s)
{
  char I = 1;
  char V = 5;
  char X = 10;
  char L = 50;
  char C = 100, D = 500, M = 1000;
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'I')
    {
      if (s[i + 1] == 'V' || s[i + 1] == 'X')
      {
        sum = sum - 1;
      }
      else
      {
        sum = sum + 1;
      }
    }
    if (s[i] == 'V')
    {
      sum = sum + 5;
    }
    if (s[i] == 'X')
    {
      if (s[i + 1] == 'L' || s[i + 1] == 'C')
      {
        sum = sum - 10;
      }
      else
      {
        sum = sum + 10;
      }
    }
    if (s[i] == 'L')
    {
      sum = sum + 50;
    }
    if (s[i] == 'C')
    {
      if (s[i + 1] == 'D' || s[i + 1] == 'M')
      {
        sum = sum - 100;
      }
      else
      {
        sum = sum + 100;
      }
    }
    if (s[i] == 'D')
    {
      sum = sum + 500;
    }
    if (s[i] == 'M')
    {
      sum = sum + 1000;
    }
  }
  return sum;
}

int main()
{
  string s;
  cin >> s;
  int a = romanToInt(s);
  cout << a << endl;
  return 0;
}