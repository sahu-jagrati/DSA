// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
  int age;
  cin >> age;
  if (age < 18)
  {
    cout << "not eligible for job" << endl;
  }
  else if (age < 55)
  {
    cout << "eligible for job" << endl;
  }
  else if (age <= 57)
  {
    cout << "eligible for job, but retirement soon" << endl;
  }
  else
  {
    cout << "retirement time" << endl;
  }
  return 0;
}