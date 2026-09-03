#include <bits/stdc++.h>
using namespace std;

int maxx(int num1, int num2)
{
  // 5>=6 no
  if (num1 >= num2)
  {
    return num1;
  }
  // looking for a return type so we to return if , if condition not fulfil
  return num2;
}

int main()
{
  int num1, num2;
  cin >> num1 >> num2;
  // int maximum = max(num1, num2);
  // int minimum = min(num1, num2);
  int maximum = maxx(num1, num2);
  cout << maximum << endl;
  // cout << minimum << endl;
  return 0;
}