// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10

// Constraints:

// 1 <= nums.length <= 10^5
// 0 <= nums[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// approach 1: we can use XOR operator because a^a=0 and 0^b=b so for duplicate elts it make 0 and taking XOR of with single give single elt but here t.c-O(n) and s.c-O(1)

// approach 2: we can use unordered_map to store <value,frequency> and then traverse map so elt having frequency 1 we return but here t.c-O(n) and unordered map takes O(1) in average and s.c-O(mpp size)

// approach 3: we check for index 0 and for index n-1 separately and then check for each index from 1 to n-2 if (nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]) so return nums[i] but it also take t.c-O(n) and s.c-O(1)

// but we want solution with t.c-O(logn) and s.c-O(1)

// we have sorted array
// so we use binary search

// in a sorted array, before the single elt:
// examle: [1,1,2,2,3,4,4]
// before the single elt, pairs start at even indices: (0,1),(2,3)
// after the single elt, pairs start from at odd indices: (5,6),..
// so we wliminate left and right half by using index-(even,odd)- so single element in right half, so eliminate left half or if index- (odd,even)- so single element in left half, so eliminate right half
// time complexity-O(log n(base 2))
// s.c-O(1)
int singleNonDuplicate(vector<int> &nums)
{
  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (nums[0] != nums[1])
    return nums[0];
  if (nums[n - 1] != nums[n - 2])
    return nums[n - 1];
  // eliminate left and right half by using index-(even,odd)- so single element in right half, so eliminate left half & (odd,even)- so single element in left half, so eliminate right half
  // we already done with index 0 and n-1 so
  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // if single elt is mid
    if ((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1]))
      return nums[mid];
    // eliminate left half when pair start from odd indices
    if (((mid % 2 == 1) && (nums[mid] == nums[mid - 1])) || ((mid % 2 == 0) && (nums[mid] == nums[mid + 1])))
    {
      low = mid + 1;
    }
    // eliminate right half
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

// same above approach but write in different ways
// time complexity-O(log n(base 2))
// s.c-O(1)
int singleNonDuplicateElt(vector<int> &nums)
{
  int n = nums.size();
  if (n == 1)
    return nums[0];
  if (nums[0] != nums[1])
    return nums[0];
  if (nums[n - 1] != nums[n - 2])
    return nums[n - 1];
  int low = 0, high = n - 1;
  while (low < high)
  {
    int mid = low + (high - low) / 2;

    // make mid even
    if (mid % 2 == 1)
      mid--;

    // now if mid is even and nums[mid]==nums[mid+1] means single elt is on the right because pair is (even,odd) so there is no single elt on left side so eliminate left half
    // now mid is even so mid+1 is odd so if nums[mid]==nums[mid+1] then pair(even,odd) means they are duplicates so single is on right half
    if (nums[mid] == nums[mid + 1])
    {
      // pair is correct, so single elt is to the right because we get pair of indexes(even ,odd)
      low = mid + 2; // because we already do above mid-1 when mid%2==1
    }
    // mid is even but nums[mid]!=nums[mid+1] so single elt is on left half or at mid
    else
    {
      // pair is broken. so single elt is at mid or to the left
      high = mid; // single elt is at mid or to the left of mid
    }
  }
  return nums[low];
}

int main()
{
  int n;
  cin >> n;
  // enter the sorted array
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << singleNonDuplicate(nums) << endl;
  cout << singleNonDuplicateElt(nums);
  return 0;
}