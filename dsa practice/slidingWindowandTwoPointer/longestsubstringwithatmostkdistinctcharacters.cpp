// given the string s and an integer k. Our task is to find maxlen substring with atmost k distinct characters, the substring can have repeated characters but there must be k distinct characters also

// example- s=aaabbccd, k=2
// substring with k distinct character can be-
// i) aaabb-no.of distinct char=2 and len=5
// ii) aabb-no.of distinct char=2 and len=4
// iii)aaabbc-no.of distinct char=3 so cann't take
// iv)ccd-no.of distinct char=2 and len=3

// so maxlen substring with given condition is 5

// in string we can have all 256 character, so in worst case k can be 256

#include <bits/stdc++.h>
using namespace std;

// naive solution- generate all subarrays with k distinct char so we used hashmap for k

// t.c-O(n^2)*O(log(256)), logarithmic if we used ordered map, here we use unordered map so it is O(1) in average or O(256) in worst case
//  256 in worst case when k =256
// s.c-O(256) for mpp, where n is size of array
int longestSubstring(string s, int k)
{
  int n = s.size();
  unordered_map<char, int> mpp; // store <character,frequency>
  int maxlen = 0;
  for (int i = 0; i < n; i++)
  {
    mpp.clear(); // every time
    for (int j = i; j < n; j++)
    {
      mpp[s[j]]++;
      if (mpp.size() <= k)
        maxlen = max(maxlen, j - i + 1);
      else
        break;
    }
  }
  return maxlen;
}

// better solution-// better solution-two pointers/sliding window- pattern 2-better solution and also use hashmap for k
// this is also optimal solution when we want to print substring of maxlen
// here we now only find maxlen

// t.c-O(N(outer while loop)+N(inner while loop))+O(log(256))=O(2N)+O(log(256))
// logarithmic if we used ordered map, here we use unordered map so it is O(1) in average or O(256) in worst case
//  256 in worst case when k =256
// s.c-O(256) for mpp, where N is size of array

int longestSubstringWithK(string s, int k)
{
  int n = s.size();
  int l = 0, r = 0;
  int maxlen = 0;
  unordered_map<char, int> mpp; // store <character,frequency>
  // run n time
  while (r < n)
  {
    mpp[s[r]]++;
    // this while loop not run n length every time, in worst case it is run n length at a single time throughout the whole journey
    while (mpp.size() > k)
    {
      mpp[s[l]]--;
      if (mpp[s[l]] == 0)
        mpp.erase(s[l]);
      l++; // shrink the current window until the zeros<=k
    }
    if (mpp.size() <= k)
      maxlen = max(maxlen, r - l + 1);
    r++; // expand the window
  }
  return maxlen;
}

// optimal solution- this is only when we want only maxlen, not want to print maxlen substring

// pattern2-optimal solution- remove inner while loop of better solution
// here we don't shrink l until the mpp size>k, here we shrink l only by one place to match current len to maxlen and not go current len to beyond maxlen because we know maxlen till that so no need to go beyond that if maxlen incerease then we move forward
// so whenever mpp size>k we shrink l only by 1 to macth curr len to maxlen only, not shrink l completely to valid the given condition(mpp size<=k)

// t.c-O(N) only for outer while loop+O(log(256))=O(N)+O(log(256))
// logarithmic if we used ordered map, here we use unordered map so it is O(1) in average or O(256) in worst case
//  256 in worst case when k =256
// s.c-O(256) for mpp, where N is size of array

int longestSubStringWithK(string s, int k)
{
  int n = s.size();
  int l = 0, r = 0;
  int maxlen = 0;
  unordered_map<char, int> mpp; // store <character,frequency>
  // run n time
  while (r < n)
  {
    mpp[s[r]]++;
    // we move l only by 1, so now take O(1)
    if (mpp.size() > k)
    {
      mpp[s[l]]--;
      if (mpp[s[l]] == 0)
        mpp.erase(s[l]);
      l++; // shrink the current window until the zeros<=k
    }
    if (mpp.size() <= k)
      maxlen = max(maxlen, r - l + 1);
    r++; // expand the window
  }
  return maxlen;
}
int main()
{
  string s;
  cout << "Enter the string: ";
  cin >> s;
  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  // int answer = longestSubstring(s, k);
  // int answer = longestSubstringWithK(s, k);
  int answer = longestSubStringWithK(s, k);
  cout << "Longest substring with atmost k distinct characters: " << answer << endl;

  return 0;
}