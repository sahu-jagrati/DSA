// Given an integer n, find the digit that occurs least frequently in its decimal representation. If multiple digits have the same frequency, choose the smallest digit.

// Return the chosen digit as an integer.

// The frequency of a digit x is the number of times it appears in the decimal representation of n.

// Example 1:

// Input: n = 1553322

// Output: 1

// Explanation:

// The least frequent digit in n is 1, which appears only once. All other digits appear twice.

// Example 2:

// Input: n = 723344511

// Output: 2

// Explanation:

// The least frequent digits in n are 7, 2, and 5; each appears only once.

// Constraints:

// 1 <= n <= 231​​​​​​​ - 1

#include <bits/stdc++.h>
using namespace std;

int getLeastFrequentDigit(int n)
{
  int minFreq = INT_MAX;
  int ans = INT_MAX;
  unordered_map<int, int> mpp;

  while (n > 0)
  {
    int digit = n % 10;
    n = n / 10;
    mpp[digit]++;
  }
  for (auto it : mpp)
  {

    // if (it.second < minFreq)
    //     If two digits have same minimum frequency,
    // your function returns whichever appears first in unordered_map iteration.

    // If the question requires:

    // 🔹 smallest digit among least frequent → extra condition needed

    // 🔹 largest digit among least frequent → extra condition needed
    if (it.second < minFreq || it.second == minFreq && it.first < ans)
    {
      minFreq = it.second;
      ans = it.first;
    }
  }
  return ans;
}

// done by me

// int getLeastFrequentDigit(int n) {
//         int minFreq=INT_MAX;
//         int ans=INT_MAX;
//         unordered_map<int,int>mpp;

//         while(n>0){
//             int digit=n%10;
//             n=n/10;
//             mpp[digit]++;
//         }
//         for(auto it:mpp){
//             if(it.second<minFreq){
//                     ans=it.first;
//                     minFreq=it.second;
//             }
//              else if(it.second==minFreq){
//                 minFreq=it.second;
//         ans=min(ans,it.first);
//       }
//         }
//         return ans;
//     }
int main()
{
  int n;
  cin >> n;

  int result = getLeastFrequentDigit(n);
  cout << result << endl;
  return 0;
}