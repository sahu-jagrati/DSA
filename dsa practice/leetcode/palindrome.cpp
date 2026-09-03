#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
  if (x < 0)
    return false;
  if (x == 0)
    return true;
  int remainder, original = x;
  long long reverse = 0;
  while (original > 0)
  {
    remainder = original % 10;
    reverse = reverse * 10 + remainder;
    original = original / 10;
  }
  if (reverse == x)
  {
    return true;
  }
  else
    return false;
}

int main()
{
  int x;
  cin >> x;
  bool res = isPalindrome(x);
  cout << res << endl;
  return 0;
}