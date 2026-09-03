// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

// Example 1:

// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1807"
//   |
// "7810"
// Example 2:

// Input: secret = "1123", guess = "0111"
// Output: "1A1B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1123"        "1123"
//   |      or     |
// "0111"        "0111"
// Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.

// Constraints:

// 1 <= secret.length, guess.length <= 1000
// secret.length == guess.length
// secret and guess consist of digits only.

#include <bits/stdc++.h>
using namespace std;

// done by me fully
// firstly i calculate bulls all
// then i calculate cows
// because if we calculate together according to me cows can decrease th guess value in map and for bulls we cannot go correctly so we do in two loops alag-alag
string getHint(string secret, string guess)
{
  int n = secret.size();
  string answer = "";
  unordered_map<char, int> mpp_guess;
  for (int i = 0; i < n; i++)
  {
    mpp_guess[guess[i]]++;
  }
  int bulls = 0, cows = 0;
  for (int i = 0; i < n; i++)
  {
    if (secret[i] == guess[i] && mpp_guess.count(secret[i]))
    {
      bulls++;
      mpp_guess[guess[i]]--;
      if (mpp_guess[guess[i]] == 0)
        mpp_guess.erase(guess[i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (secret[i] != guess[i] && mpp_guess.count(secret[i]))
    {
      cows++;
      mpp_guess[secret[i]]--;
      if (mpp_guess[secret[i]] == 0)
        mpp_guess.erase(secret[i]);
    }
  }
  answer += to_string(bulls);
  answer += 'A';
  answer += to_string(cows);
  answer += 'B';
  return answer;
}
int main()
{
  string secret, guess; // having only digits
  cin >> secret >> guess;
  cout << getHint(secret, guess);
  return 0;
}