// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]
// nums2[i] = nums1[i] - nums1[j], for an index j != i
// Return true if it is possible to construct such an array, otherwise, return false.

// Example 1:

// Input: nums1 = [2,3]

// Output: true

// Explanation:

// Choose nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1.
// Choose nums2[1] = nums1[1] = 3.
// nums2 = [-1, 3], and both elements are odd. Thus, the answer is true​​​​​​​.
// Example 2:

// Input: nums1 = [4,6]

// Output: true

// Explanation:​​​​​​​

// Choose nums2[0] = nums1[0] = 4.
// Choose nums2[1] = nums1[1] = 6.
// nums2 = [4, 6], and all elements are even. Thus, the answer is true.

// Constraints:

// 1 <= n == nums1.length <= 100
// 1 <= nums1[i] <= 100
// nums1 consists of distinct integers

#include <bits/stdc++.h>
using namespace std;

// this problem is done by me

// answer is always true because the number is either even or odd so we can construct another array nums2 of length n such that elements in nums2 are either all odd or all even

// given that nums1 array has distinct integers

// Case1:  if nums1 has all even number then nums2=nums1 where nums2 has elements with all even, in that case we choose For each index i, nums2[i]=nums1[i]

// or Case2: if nums1 has all odd number then nums2 = num1 where nums2 hhas elements with all odd, in that case we choose For each index i, nums2[i]=nums1[i]

// or Case3: when nums1 have some elements even and some are odd  in that case  we know if we do :
// i) even+even=even
// ii) even-even=even
// iii) odd+odd=even
// iv) odd-odd=even
// v)  even+odd=odd
// vi) even-odd=odd

// in this problem we want only one combination : even-odd=odd

// but for nums2 we want either all are even or all are odd so in that case we cannot make all are even because in given nums1 array we have some even and some odd elements if we try to make all are even then if nums1 is even we directly say nums2[i]=nums1[i] but when nums1[i] is odd in that case for making nums2 with even we have to apply nums2[i]=nums1[i]-nums1[j], where j!=i so in that case we want nums1[j] is also even to make nums2[i] even because even - even=even but suppose we have only one even in entire given array which is nums1[i] so we never make nums2 with all even elements in case when nums1 have some elements even and some are odd so in that case nums2 has all odd elements because  if there is odd element in nums1 then nums2[i]=nums1[i] or if it is an even element then we say nums2[i]=nums1[i]-odd element (any one) because we have some even and some odd elements in given array
// so we get nums2 is an array of all odd elements
// so there is always one possible answer
// so we take two array even and odd

// t.c-O(n)(for even and odd construct)+O(n)(when second loop run if nums1 has both even and odd elts)=O(n)
// s.c-O(n)(even+odd array together because both elts combine get nums1)+O(n)(for nums2 in case 3)=O(n)
bool uniformArray(vector<int> &nums1)
{
  int n = nums1.size();
  vector<int> even; // to store even elts of an given array
  vector<int> odd;  // to store odd elts of an given array

  for (int x : nums1)
  {
    if (x % 2 == 0)
      even.push_back(x);
    else
      odd.push_back(x);
  }
  // Case 1: when all elts in nums1 are even then nums2 has all elts even in that case nums2[i]=nums1[i] for each index i so we can say it is possible to construct nums2 array with all even elts
  if (even.size() == n)
    return true;
  // Case 2: when all elts in nums1 are odd then nums2 has all elts odd in that case nums2[i]=nums1[i] for each index i so we can say it is possible to construct nums2 array with all odd elts
  if (odd.size() == n)
    return true;
  // Case 3: when in nums1 some elts are even and some are odd in that case nums2 is always have all elts odd
  // so in that case i) if nums1[i] is odd then we say nums2[i]=nums1[i]
  // ii) if nums1[i] is even then we do: nums2[i]=nums1[i]-odd[0] because even-odd=odd so we know there is an odd elt in our given array and also given that all are distinct integers so we can say odd[0] is nums1[j] where j!=i
  vector<int> nums2(n);
  for (int i = 0; i < n; i++)
  {
    // if it is odd directly
    if (nums1[i] % 2 != 0)
      nums2[i] = nums1[i];
    // when nums1[i] is even so we do even-odd=odd to make odd
    // Since nums1[i] is even and the array contains at least one odd number, that odd number cannot be nums1[i]. Therefore odd[0] automatically has a different index.
    else
    {
      nums2[i] = nums1[i] - odd[0]; // because all are distinct integrs, you can subtract any odd number from it
    }
  }
  return true; // we return true because case 3 is always fulfill if case1 and case2 not fulfill and always gives nums2 with all odd elts, there is always one possible answer either nums2 has all odd elts or nums2 has all even elts  so we don't need to check all cases return directly true  I show it below
}

// So we don't actually need to check all the cases in the code
// answer is always true , why?
// There are only two possibilities
// Case1: All numbers have the same parity
// For example:

// [2, 4, 6, 8]   → all even
// [1, 3, 5, 7]   → all odd

// We simply choose:

// nums2[i] = nums1[i];

// So nums2 is already uniform.
// Case2: There are both even and odd numbers
// for eaxmaple:[2,3,6,7]
// we want to make everything odd.
// for every odd number, keep it nums2[i]=nums1[i]
// for every even number, subtract any odd number from it:
// 2-3=-1 odd
// 6-3=3  odd
// so nums2=[-1,3,3,7]  all are odd
// The important thing is that when we process an even nums1[i], the odd number we choose must come from some j != i.

// Since nums1[i] is even and the array contains at least one odd number, that odd number cannot be nums1[i] in case 2. Therefore odd[0] automatically has a different index.

// so we directly say:
bool uniformParityArray(vector<int> &nums1)
{
  return true; // always nums2 has either all even or all odd
}
// so checking all three cases are logically correct, but unnecessary, because because even if neither condition is true, your Case 3 always succeeds.

// So your reasoning eventually proves:

// All even  → possible
// All odd   → possible
// Mixed     → possible

// Therefore:

// Answer = always TRUE

int main()
{
  int n;
  cin >> n;
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums1[i];
  }
  cout << uniformArray(nums1); // no need to check all 3 cases , answer is always true
  cout << uniformParityArray(nums1);
  return 0;
}

// int n=nums1.size();
//       vector<int>even;
//       vector<int>odd;
//       for(int x:nums1){
//           if(x%2==0)even.push_back(x);
//           else odd.push_back(x);
//       }
//       if(even.size()==n)return true;
//       if(odd.size()==n)return true;
//       vector<int>nums2(n);
//       for(int i=0;i<n;i++){
//           if(nums1[i]%2!=0)nums2[i]=nums1[i];
//           else {
//               nums2[i]=nums1[i]-odd[0];
//           }
//       }
//       return true;