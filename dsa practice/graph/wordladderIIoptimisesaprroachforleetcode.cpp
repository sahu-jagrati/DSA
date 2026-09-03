// for interviews go with wordladderII solution not go with this, nit try to become smart
// this is only for leetcode and cp

// in this we do two step-
// step-1 follow wordladderI and find the length of minimum shortest transformation sequence i.e min step and store the steps for each string here in queue we store onyl string for steps we take map data structure
// step -2 backtrack in the map from endWord to beginWord to get the answer
// so in previous solution we store so many sequence but here we starting from back we know we get answer in lesser amount meanse we go in correct way by backtrack from (endword to beginword), not going unnecesaary

// for details description of solution see notes

#include <bits/stdc++.h>
using namespace std;

// N-wordlist size
// K-number of shortest sequences
// S-length of each sequence(<=N)

// s.c- O(N)(for unordered set)+O(N)(queue, also we can have many transformation but push only that is in wordlist)+O(N)(for map)+O(K*S)(for answer)+O(S)(dfs recursion stack space)
// t.c-(N*wordlength*26*1(in average or N in worst in unordered set ) or (logN in ordered set))(step1)+(step2)(K*S*wordlength*26)
class Solution
{
  map<string, int> mpp;
  vector<vector<string>> ans;
  string b; // b is beginword

private:
  // step -2 backtracking from end to begin word
  void dfs(string word, vector<string> &seq)
  {
    if (word == b)
    {
      reverse(seq.begin(), seq.end()); // reverse seq for push in answer because answer is from begin to end word
      ans.push_back(seq);
      reverse(seq.begin(), seq.end()); // again reverse for so on backtracking process
      return;
    }
    int steps = mpp[word];
    int sz = word.size();
    for (int i = 0; i < sz; i++)
    {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch;
        if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) /// check level difference =1
        {
          seq.push_back(word);
          dfs(word, seq);
          seq.pop_back(); // popback from seq means we return back
        }
      }
      word[i] = original;
    }
  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> st(wordList.begin(), wordList.end()); // you can use ordered set also but it take slight more time, so we use unordered set
    queue<string> q;
    q.push(beginWord);
    b = beginWord;
    mpp[beginWord] = 1;
    int sizee = beginWord.size();
    st.erase(beginWord);
    while (!q.empty())
    {
      string word = q.front();
      int steps = mpp[word];
      q.pop();
      if (word == endWord)
        break;
      for (int i = 0; i < sizee; i++)
      {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch;
          if (st.count(word) > 0) // count() function return 1 if elt found else return 0
          {
            q.push(word);
            st.erase(word);
            mpp[word] = steps + 1;
          }
        }
        word[i] = original;
      }
    }
    if (mpp.find(endWord) != mpp.end()) // if in map there is endword then do backtracking
    {
      vector<string> seq;
      seq.push_back(endWord);
      dfs(endWord, seq);
    }
    return ans;
  }
};

// input type-beginword-"hit", endword-"cog"
// wordlist-{"hot","dot","dog","lot","log","cog"}
int main()
{
  string beginword, endword;
  cout << "Enter the beginword and endword: ";
  cin >> beginword >> endword;
  int n;
  cout << "Enter the size of wordlist: ";
  cin >> n;
  vector<string> wordlist(n);
  cout << "Enter the word for wordlist: ";
  for (int i = 0; i < n; i++)
  {
    cin >> wordlist[i];
  }
  Solution result;
  vector<vector<string>> answer = result.findLadders(beginword, endword, wordlist);
  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}