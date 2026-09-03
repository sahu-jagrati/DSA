#include <bits/stdc++.h>
using namespace std;

// s is a sentence
int lengthOfLastWord(string s)
{
  stringstream ss(s);
  string word;
  while (ss >> word)
  {
  }
  return word.size();
}

int main()
{
  string sentence;
  getline(cin, sentence);
  int answer = lengthOfLastWord(sentence);
  cout << answer << endl;
  return 0;
}