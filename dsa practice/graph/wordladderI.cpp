// given two distinct words beginword and endword and a list denoting wordlist of unique words of equal length.
// find the length of the shortest transformation sequence from beginword to endword

// also- a word can only consist of lowercase character
// only one letter can be changed in each transformation
// each transformation, word must exist in the wordlist including the endword
// beginword may or may not be part of the wordlist

// example - beginword-"hit", endword-"cog"
// wordlist-{"hot","dot","dog","lot","log","cog"}
// hit->hot->dot->dog->cog- sequence length-5

// for deep discussion in solution see notes

#include <bits/stdc++.h>
using namespace std;

// t.c-N(for getting in queue)*wordlength*26*O(1)(for search in unordered set in average case or in worst case it is O(N)) or (in ordered set it is logN) where N is length of wordlist . transformation can be many in worst case but there is only N get in queue we see
// s.c-O(N)(for set +queue)
class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    // making set as a visited array type
    // we use unordered set to reduce time complexity but in worst case it also take wordlist.size, you can use ordered set also
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord); // that mark as visited
    //
    while (!q.empty())
    {
      string word = q.front().first;
      int steps = q.front().second;
      q.pop();
      if (word == endWord)
        return steps;

      // t.c-N(for getting in queue)*wordlength*26*O(1)(for search in unordered set in average case or in worst case it is O(N)) or (in ordered set it is logN) where N is length of wordlist . transformation can be many in worst case but there is only N get in queue we see in example
      for (int i = 0; i < word.size(); i++)
      {
        char original = word[i];
        // from 'a' to 'z' take the character and check in set exist or not
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          word[i] = ch;
          // check it exists in the set
          if (st.find(word) != st.end())
          {
            st.erase(word);
            q.push({word, steps + 1});
          }
        }
        // in last make word original
        word[i] = original;
      }
    }
    return 0;
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
  int answer = result.ladderLength(beginword, endword, wordlist);
  cout << answer << endl;

  return 0;
}