#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{
  unordered_map<string, int> mpp_s1;
  unordered_map<string, int> mpp_s2;

  stringstream ss1(s1);
  string word1;
  while (ss1 >> word1)
  {
    mpp_s1[word1]++;
  }

  stringstream ss2(s2);
  string word2;
  while (ss2 >> word2)
  {
    mpp_s2[word2]++;
  }

  vector<string> answer;
  for (auto it : mpp_s1)
  {
    if (it.second == 1)
    {
      if (!mpp_s2.count(it.first))
        answer.push_back(it.first);
    }
  }
  for (auto it : mpp_s2)
  {
    if (it.second == 1)
    {
      if (!mpp_s1.count(it.first))
        answer.push_back(it.first);
    }
  }
  return answer;
}

int main()
{
  string sentence1, sentence2;
  getline(cin, sentence1);
  cin.ignore();
  getline(cin, sentence2);
  vector<string> answer = uncommonFromSentences(sentence1, sentence2);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}