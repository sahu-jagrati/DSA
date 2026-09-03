#include <iostream>
#include <cstdint>
using namespace std;

int reverseInteger(int x)
{
  int int_max = 2147483647;  // 2^31 -1
  int int_min = -2147483648; // -2^31
  int remainder = 0;

  long reverse = 0;
  while (x != 0)
  {

    remainder = x % 10;
    x = x / 10;

    // overflow check befor appliying
    if (reverse > int_max / 10 || (reverse == int_max / 10 && remainder > 7))
      return 0;
    if (reverse < int_min / 10 || (reverse == int_min / 10 && remainder < -8))
      return 0;

    reverse = reverse * 10 + remainder;
  }
  return reverse;
}

int main()
{
  int x;
  cin >> x;
  int result = reverseInteger(x);

  cout << result << endl;
  return 0;
}