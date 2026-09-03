#include <bits/stdc++.h>
using namespace std;

// call by value- here in this original is not pass, copy passed so change occur only in copy not in original
void printNumber(int num)
{
  cout << num << endl;
  num += 5;
  cout << num << endl;
  num += 5;
  cout << num << endl;
}
void printString(string s)
{
  cout << s << endl;
  s[0] = 'm';
  cout << s << endl;
}

// call by reference - do not pass copy , it takes the address so it takes the original
void printString1(string &s)
{
  cout << s << endl;
  s[0] = 'm';
  cout << s << endl;
}

int main()
{
  int num = 10;
  printNumber(num);
  cout << num << endl;
  string s = "woman";
  // printString(s);
  // cout << s << endl;
  printString1(s);
  cout << s << endl;
  return 0;
}