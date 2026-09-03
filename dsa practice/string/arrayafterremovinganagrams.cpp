#include <bits/stdc++.h>
using namespace std;

vector<string> removeAnagrams(vector<string> &words)
{
  int n = words.size();
  for (int i = 0; i < n; i++)
  {

    sort(words[i].begin(), words[i].end());
  }
  int i = 0;
  while (i < n - 1)
  {
    int j = i + 1;
    while (words[i] == words[j] && j < n - 1)
    {
      words[j].erase();
      j++;
    }
    i++;
  }
  return words;
}

int main()
{
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words[i];
  }
  vector<string> answer = removeAnagrams(words);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}