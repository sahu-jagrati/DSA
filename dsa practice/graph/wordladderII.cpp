// extension of word ladder I-
// here we have to return all shortest transformation sequene(s) from beginword to endword. you can return them in any order possible.
// if there is no such transformation sequence return an empty list

// approach is some similar but have changes also
// first- queue now store vector list
// we erase word from set when we complete level fully
// so for same level you can take word as many times you want but for next level you cann't take
// for detail description see notes

#include <bits/stdc++.h>
using namespace std;

// time complexity will be different for each example so we cann't predict time complexity for this
class Solution
{
public:
  vector<vector<string>> findSequence(string beginWord, string endWord, vector<string> &wordList)
  {
    // we use unordered set to reduce time complexity but in worst case it also take wordlist.size, you can use ordered set also
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    int level = 0;
    vector<vector<string>> ans;

    while (!q.empty())
    {
      vector<string> vec = q.front();
      q.pop();

      // erase all words that has been used in the previous levels to transform
      if (vec.size() > level) // here we go to next level so, when we go next level then we erase word from set
      {
        level++;
        for (auto it : usedOnLevel) // erase all words that we used in previous level
        {
          st.erase(it);
        }
        usedOnLevel.clear(); // after erasing from set we clear the usedOnlevel so, we put new word of next level
      }

      string word = vec.back();

      // store the answer
      if (word == endWord)
      {
        // the first sequence when we reached to endword
        if (ans.size() == 0)
        {
          ans.push_back(vec);
        }
        else if (ans[0].size() == vec.size())
        {
          ans.push_back(vec);
        }
      }

      for (int i = 0; i < word.size(); i++)
      {
        char original = word[i];
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch;
          // count() function return 1 if element found else return 0
          if (st.count(word) > 0)
          {
            vec.push_back(word);
            q.push(vec);
            // mark as visited on the level
            usedOnLevel.push_back(word);

            vec.pop_back(); // done for erase last word and replace it with new word like vec = [hit, hot]
                            // push "dot"
                            // queue gets [hit, hot, dot]
                            // after pushing
                            // vec = [hit, hot, dot]
                            // Now, if you don’t pop, next word will do:
                            // vec.push_back("lot")
                            // → [hit, hot, dot, lot] ❌ WRONG
                            // But we want:

            // [hit, hot, lot] ✔
          }
        }
        word[i] = original;
      }
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
  vector<vector<string>> answer = result.findSequence(beginword, endword, wordlist);
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