// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.

// Example 1:

// Input: score = [5,4,3,2,1]
// Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
// Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
// Example 2:

// Input: score = [10,3,8,9,4]
// Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
// Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

// Constraints:

// n == score.length
// 1 <= n <= 104
// 0 <= score[i] <= 106
// All the values in score are unique

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// t.c-O(nlogn)(sorting)+O(n*1)(for assign rank)+O(n*1)(for getting answer array), we use unordered_map so it takes O(1) in average for insert and for access
// s.c-O(n)(for temp)+O(n)(mpp size because all scores are unique)+O(n)(for answer)
vector<string> findRelativeRank(vector<int> &score)
{
  int n = score.size();
  vector<int> temp = score;
  sort(temp.begin(), temp.end(), greater<int>()); // sort in descending order because highest score means highest rank(1st,2nd,3rd)
  unordered_map<int, string> mpp;
  int j = 4; // this is for athelete 4th rank to nth rank

  // we do by i=0,i=1 and i=2 because we already sort temp in descending order so highest score is at 0 index then 2nd highest score at i=1 and so on.
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
      mpp[temp[i]] = "Gold Medal"; // 1st rank athlete
    else if (i == 1)
      mpp[temp[i]] = "Silver Medal"; // 2nd rank athlete
    else if (i == 2)
      mpp[temp[i]] = "Bronze Medal"; // 3rd rank athlete
    else
    {
      mpp[temp[i]] = to_string(j); // for 4th rank to nth rank athlete
      j++;
    }
  }
  vector<string> answer(n);
  for (int i = 0; i < n; i++)
  {
    answer[i] = mpp[score[i]];
  }
  return answer;
}

int main()
{
  int n;
  cin >> n;
  vector<int> score(n);
  for (int i = 0; i < n; i++)
  {
    cin >> score[i];
  }
  vector<string> answer = findRelativeRank(score);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}