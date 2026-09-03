// We are playing the Guess Game. The game is as follows:

// I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.

// Example 1:

// Input: n = 10, pick = 6
// Output: 6
// Example 2:

// Input: n = 1, pick = 1
// Output: 1
// Example 3:

// Input: n = 2, pick = 1
// Output: 1

// Constraints:

// 1 <= n <= 2^31 - 1
// 1 <= pick <= n

#include <bits/stdc++.h>
using namespace std;

int guess(int num, int pick)
{
  if (num == pick)
    return 0;
  else if (num > pick)
    return -1;
  else
    return 1;
}

// t.c-O(logn) // we use binary search
// s.c-O(1)
int guessNumber(int n, int pick)
{
  int low = 1, high = n;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    // if you don't want to call guess function again and again for same mid so
    // int store=guess(mid,pick);
    if (guess(mid, pick) == 0)
      return mid;
    else if (guess(mid, pick) == 1)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main()
{
  int n, pick;
  cout << "Enter value of 'n' and 'pick number': ";
  cin >> n >> pick;

  int answer = guessNumber(n, pick);
  cout << answer << endl;
  return 0;
}