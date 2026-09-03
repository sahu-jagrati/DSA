// You are given an integer array nums.

// Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

// Example 1:

// Input: nums = [1,2,3]

// Output: 2

// Explanation:

// One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.

// Example 2:

// Input: nums = [2,3,4]

// Output: 3

// Explanation:

// The longest subsequence is [2, 3, 4]. The bitwise XOR is computed as 2 XOR 3 XOR 4 = 5, which is non-zero.

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^9

#include <bits/stdc++.h>
using namespace std;

// Hint 1
// What happens if you take the entire array?
// Hint 2
// If the XOR of the entire array is 0, can removing one element help?
// Hint 3
// What if all elements are 0?

// I solve this problem using a hint

// According to hint:
// i) first we find the XOR of an entire array and if XOR!=0 then our answer is n(length of array) because we want longest subsequence so entire array
// ii) if XOR of an entire array ==0, then by removing one elt can help, now we have to traverse for each elt and remove it from XOR and check each time that if XOR!=0 then ans= n-1 because one elt is decrease ,
// we want longest subsequence with non-zero bitwise XOR so we remove only one elt and it can be any in the entire array that XOR with it make the ans xor==0 so we have to remove that one elt , by removing that elt we get ansXor!=0, so we don't have to try for removing two elts or three elts because we want longest subsequence and we can see that if ansXor==0 means by xor with one elt make it ==0 so we have to remove that one elt

// if all elts are 0 then Xor of an entire array remains 0 whatever elt we remove

// now when we get ansXor==0 , we have to traverse array and check for each elt so for that how we approach

// Suppose we have 5 elts : a,b,c,d,e
// we take XOR of all so: ans=a^b^c^d^e
// and if ans!=0 then we return 5 as a length
// if ans==0
// suppose if we remove c from ans xor then we get ans!=0 so how we remove c:
// we know 0^num=num
// ans num^num=0
// if ans xor==0 then just do : 0^c=c
// Why? because: (a^b^c^d^e)^c
// becomes: a^b^d^e and we get ans xor !=0 if c makes it 0
// example: arr=[1,2,3]
// ans=1^2^3=0
// we traverse an array: first we satrt from i=0
// so we try to remove 1
// temp=ans^arr[0]=0^1=1
// and if we check for remaining elts then we get : 2^3=1 which is = temp so that's how we remove elt from ans xor and we don't have to remove either two elts or three elts or so on to get ans!=0 because there is one elt that make ans==0 so we have to remove that just one elt
// we atke temp because if we do in ans then ans change so we take temp

// if all elts are 0 then ans==0 and if we try to remove one elt from ans we never get it !=0 so we return 0 in last

// t.c-O(n)+O(n)(in worst case)=O(n), where n is the length of given array
// s.c-O(1)
int longestSubsequence(vector<int> &nums)
{
  int n = nums.size();
  int ansXor = 0;
  for (int i = 0; i < n; i++)
  {
    ansXor ^= nums[i];
  }
  if (ansXor != 0)
    return n; // means entire array is our answer
  else
  {
    // we try to remove that one elt that makes ansXor==0
    for (int i = 0; i < n; i++)
    {
      int temp = ansXor ^ nums[i]; // we use temp because if we do this with ansXor then ansXor change everytime but we want to remove only one elt
      if (temp != 0)
      {
        return n - 1; // longest subsequence length become n-1 because we remove that one elt
        break;
      }
    }
  }
  // r no subsequence exist when all elts are zero so
  return 0;
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
  cout << longestSubsequence(nums);
  return 0;
}