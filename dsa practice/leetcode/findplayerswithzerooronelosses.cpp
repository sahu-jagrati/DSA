// You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

// Return a list answer of size 2 where:

// answer[0] is a list of all players that have not lost any matches.
// answer[1] is a list of all players that have lost exactly one match.
// The values in the two lists should be returned in increasing order.

// Note:

// You should only consider the players that have played at least one match.
// The testcases will be generated such that no two matches will have the same outcome.

// Example 1:

// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
// Example 2:

// Input: matches = [[2,3],[1,3],[5,4],[6,4]]
// Output: [[1,2,5,6],[]]
// Explanation:
// Players 1, 2, 5, and 6 have not lost any matches.
// Players 3 and 4 each have lost two matches.
// Thus, answer[0] = [1,2,5,6] and answer[1] = [].

// Constraints:

// 1 <= matches.length <= 105
// matches[i].length == 2
// 1 <= winneri, loseri <= 105

// winneri != loseri
// All matches[i] are unique.

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// let answer[0].size=j
// let answer[1].size=k
// t.c-O(n)+O(win.size)+O(lose.size)+O(jlogj)+O(klog(k))
// s.c-O(win)+O(lose)+answer size is required
vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
  int n = matches.size();
  unordered_map<int, int> win;
  unordered_map<int, int> lose;
  for (int i = 0; i < n; i++)
  {
    win[matches[i][0]]++;
    lose[matches[i][1]]++;
  }
  vector<vector<int>> answer(2);
  for (auto it : win)
  {
    if (!lose.count(it.first))
      answer[0].push_back(it.first);
    else if (lose[it.first] == 1)
      answer[1].push_back(it.first);
  }
  for (auto it : lose)
  {
    if (!win.count(it.first) && it.second == 1)
      answer[1].push_back(it.first);
  }
  sort(answer[0].begin(), answer[0].end());
  sort(answer[1].begin(), answer[1].end());
  return answer;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matches(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> matches[i][0] >> matches[i][1];
  }
  vector<vector<int>> answer = findWinners(matches);
  for (auto it1 : answer)
  {
    for (auto it2 : it1)
    {
      cout << it2 << " ";
    }
    cout << endl;
  }
  return 0;
}