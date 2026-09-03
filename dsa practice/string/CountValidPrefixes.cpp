#include <bits/stdc++.h>
using namespace std;

bool validPrefix(string temp)
{
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < temp.size(); i++)
  {
    if (temp[i] == '0')
      cnt0++;
    else
      cnt1++;
  }
  if (abs(cnt0 - cnt1) == 1 || abs(cnt0 - cnt1) == 0)
    return true;
  return false;
}
int countValidPrefixes(string s)
{
  int n = s.size();
  int cnt = 0;
  string temp;
  for (int i = 0; i < n; i++)
  {
    temp += s[i];
    if (validPrefix(temp))
      cnt++;
  }
  return cnt;
}

int main()
{
  string s;
  cin >> s;
  cout << countValidPrefixes(s);
  return 0;
}