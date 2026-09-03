#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> largeGroupPositions(string s)
{
  int n = s.size();
  map<char, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[s[i]]++;
  }
  vector<vector<int>> answer;
  for (auto it : mpp)
  {
    if (it.second >= 3)
    {
      char ch = it.first;
      vector<int> temp;
      for (int i = 0; i < n; i++)
      {
        if (s[i] == ch)
        {
          temp.push_back(i);
          int j = i+1;
          while (s[j] == ch)
          {
            j++;
          }
          temp.push_back(j - 1);
          break;
        }
      }
      answer.push_back(temp);
    }
  }
  return answer;
}

int main()
{
  string s;
  cin >> s;

  vector<vector<int>> answer = largeGroupPositions(s);
  for (auto it : answer)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << endl;
  }
  return 0;
}
