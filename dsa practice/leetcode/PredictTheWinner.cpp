// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

// Example 1:

// Input: nums = [1,5,2]
// Output: false
// Explanation: Initially, player 1 can choose between 1 and 2.
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
// Hence, player 1 will never be the winner and you need to return false.
// Example 2:

// Input: nums = [1,5,233,7]
// Output: true
// Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 10^7

#include <bits/stdc++.h>
using namespace std;

// here we start with recursion because we try all ways to get the best answer from all
// we take two pointers (i,j) where i points index 0 and j points index (n-1) in starting and score1=0 and scroe2=0 also in starting and we take one more extra parameter which determines whose turn is now let's say we take 'k' if k==0 then player 1 has turn or it k==1 then player 2 has turn
// now if k==0 means player1 has turn then in that we have two cases either player1 takes nums[i] then we add nums[i] in score1 then we do i++  or either player1 takes nums[j] then we add nums[j] in score1 then we do j-- and after that player2 has turn so we make k=1
// now if k==1 means player2 has turn in that also we have two cases either player2 takes nums[i] then we add nums[i] in score2 then we do i++ or either player2 takes nums[j] then we add nums[j] in score2 then we do j-- and after that player1 has turn so we make k=0

// base case is when i>j: if(i>j)return score1>=score2 ; if it is then return true else return false

// in intially in recursion we start with i=0 , j=n-1 , score1=0, score2=0 and k=0 because A.T.Q player1 starting first so k=0 where k=0 repersenets player1 and k=1 represents player2

// this is not a solution, question is slightly confuse me
bool f1(int i, int j, int k, int score1, int score2, vector<int> &nums)
{
  // base case
  if (i > j)
    return score1 >= score2;
  // player1 turn
  if (k == 0)
  {
    return f1(i + 1, j, 1, score1 + nums[i], score2, nums) || f1(i, j - 1, 1, score1 + nums[j], score2, nums);
  }
  // when player2 turn
  return f1(i + 1, j, 0, score1, score2 + nums[i], nums) || f1(i, j - 1, 0, score1, score2 + nums[j], nums);
}

bool predictTheWinner(vector<int> &nums)
{
  int n = nums.size();
  // in intially in recursion we start with i=0 , j=n-1 , score1=0, score2=0 and k=0 because A.T.Q player1 starting first so k=0 where k=0 repersenets player1 and k=1 represents player2
  return f1(0, n - 1, 0, 0, 0, nums);
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << predictTheWinner(nums);
  return 0;
}