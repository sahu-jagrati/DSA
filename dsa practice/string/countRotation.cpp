#include <bits/stdc++.h>
using namespace std;

int cyclicRotation(string temp, int score)
{
  int n = temp.size();
  for (int i = 0; i <= n - 2; i++)
  {
    if (temp[i] == temp[i + 1])
    {
      score += 1;
    }
  }
  cout << "SCore" << score << endl;
  return score;
}

int countRotations(string s, int k)
{
  int ans = 0;
  string prefix = "";
  for (int i = 0; i < s.size(); i++)
  {
    string temp = s.substr(i);
    if (i != 0)
    {
      prefix += s[i - 1];
      temp += prefix;
    }
    cout << "string" << temp << endl;
    int score = 0;
    score = cyclicRotation(temp, score);
    cout << "Score" << score << endl;
    if (score == k)
      ans += 1;
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << countRotations(s, k);
  return 0;
}