// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]​​​​​​​
// nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// Return true if it is possible to construct such an array, otherwise return false.

// Example 1:

// Input: nums1 = [1,4,7]

// Output: true

// Explanation:​​​​​​​​​​​​​​

// Set nums2[0] = nums1[0] = 1.
// Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
// Set nums2[2] = nums1[2] = 7.
// nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
// Example 2:

// Input: nums1 = [2,3]

// Output: false

// Explanation:

// It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.

// Example 3:

// Input: nums1 = [4,6]

// Output: true

// Explanation:

// Set nums2[0] = nums1[0] = 4.
// Set nums2[1] = nums1[1] = 6.
// nums2 = [4, 6], and all elements are even. Thus, the answer is true.

// Constraints:

// 1 <= n == nums1.length <= 10^5
// 1 <= nums1[i] <= 10^9
// nums1 consists of distinct integers.

#include <bits/stdc++.h>
using namespace std;

// Brute force solution:

// I already explain the solution in Part I here we have one more condition to check: nums1[i]-nums1[j]>=1

// here in this part we cann't directly say we always get either all even or all odd because of the condition

// t.c-O(n)(for even and odd construct)+O(n*odd size(in worst case))(when second loop run if nums1 has both even and odd elts)=O(n)
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
  // Case 3: when in nums1 some elts are even and some are odd in that case nums2 can have all elts odd only if given condition satisfy because even-odd=odd so we never get an even elt
  // so in that case i) if nums1[i] is odd then we say nums2[i]=nums1[i]
  // ii) if nums1[i] is even then we do: nums2[i]=nums1[i]-odd[j] because even-odd=odd so we know there is an odd elt in our given array and also given that all are distinct integers so we can say odd[j] is nums1[j] where j!=i and also nums1[i]!=nums1[j] because nums1[i] is even and odd[j] or nums1[j] is odd but here if we have to check one more condition : nums1[i]-nums1[j]>=1
  vector<int> nums2(n);
  for (int i = 0; i < n; i++)
  {
    // if it is odd directly push in nums2
    if (nums1[i] % 2 != 0)
      nums2[i] = nums1[i];
    // when nums1[i] is even so we do even-odd=odd to make odd
    else
    {
      // here we have to check one one more condition : nums1[i]-nums1[j]>=1 so we have to traverse over the odd array if we get any odd elt that satisfy the condition then we stop and break
      bool flag = false;
      for (int j = 0; j < odd.size(); j++)
      {
        // as elts are distinct so checking by value is satisfy the i!=j
        // also no need to check this nums1[i]!=odd[j] because nums1[i] is even while odd[j] is odd so they never  have equal vale or equal index in nums1
        if (nums1[i] != odd[j])
        {
          if (nums1[i] - odd[j] >= 1)
          {
            nums2[i] = nums1[i] - odd[j];
            flag = true; // means we convert an  even elt into odd
            break;
          }
        }
      }
      // if after going with each odd number we cannot convert even elt into odd the then flag==false still means we cannot construct the nums2 array with all odd elts we return false here don't proceed forward
      if (flag == false)
        return false;
    }
  }
  return true; // we return true because case 3 is fulfill we get an nums2 array of all odd elts when nums1 has some elts even and some elts odd
}

// above solution gives time limit exceed for large array

// I notice that there is no need of nums2 array becasue we want to know either we construct or not, we don't need to return an nums2 array , we have to check only condition and check whether we get nums2 or not so we can remove nums2 from above solution
// but still we get time limit exceed for large array

// as we use case 3 when nums1 has even and odd both elts in that case for odd elts we simply continue , for even elts we need to convert them in odd by subtracting an odd elt but with the condition satisfy and condition say nums1[i]-nums1[j]>=1 means subtractions should be  positive always so if we subtract  smallest odd elt from any nums1[i] then in that case it can be possible to satisfy the condition for an example we have nums1=[1,4,7] for here nums1[1]=4 is even we need to subtract odd elt we have two odd elt {1,7} if we subtract 7 then we get 4-7=-3 <1 not satisfy condition or if we subtract 4-1=3>1 we satisfy the condition so we subtract the smallest odd elt from any nums1[i] when it is even if it satisfy then we continue otherwise we return false because if subtracting with smallest odd elt we don't get >=1 then subtracting with other odd elt never give >=1

// so we do some changes in above code

// t.c-O(n)(for even and odd construct)+O(n)(when second loop run if nums1 has both even and odd elts)=O(n)
// s.c-O(n)(even+odd array together because both elts combine get nums1)=O(n)
bool uniformParityArray(vector<int> &nums1)
{

  int n = nums1.size();
  vector<int> even;
  vector<int> odd;
  int minOdd = INT_MAX; // to store smallest odd elt
  for (int x : nums1)
  {
    if (x % 2 == 0)
      even.push_back(x);
    else
    {
      odd.push_back(x);
      minOdd = min(minOdd, x);
    };
  }
  if (even.size() == n)
    return true;
  if (odd.size() == n)
    return true;
  // case 3 we don't need to store an nums2 , we have to check only can we construct nums2 or not
  // when nums1 has both even and odd then we can construct nums2 with only odd elts if condition satisfy
  for (int i = 0; i < n; i++)
  {
    //  if nums1[i] is odd then we simply continue, nothing has to do
    if (nums1[i] % 2 != 0)
      continue;
    // when nums1[i] is even so we subtract minimumOdd elt from it if it satify condition goo otherwise we return false immediately because if subtracting with smallest odd elt we don't get >=1 then subtracting with other odd elt never give >=1
    // and also we don't need to check j!=i because nums1[i] is even and we subtract it from odd so ofcourse they are diiferent index elt
    else
    {
      // we directly check condition if not satisfy then return false
      if (nums1[i] - minOdd < 1)
        return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums1(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums1[i];
  }
  cout << uniformArray(nums1) << endl;
  cout << uniformParityArray(nums1);
  return 0;
}