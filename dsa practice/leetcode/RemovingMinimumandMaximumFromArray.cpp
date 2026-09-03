// You are given a 0-indexed array of distinct integers nums.

// There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

// A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

// Example 1:

// Input: nums = [2,10,7,5,4,1,8,6]
// Output: 5
// Explanation:
// The minimum element in the array is nums[5], which is 1.
// The maximum element in the array is nums[1], which is 10.
// We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
// This results in 2 + 3 = 5 deletions, which is the minimum number possible.
// Example 2:

// Input: nums = [0,-4,19,1,8,-2,-3,5]
// Output: 3
// Explanation:
// The minimum element in the array is nums[1], which is -4.
// The maximum element in the array is nums[2], which is 19.
// We can remove both the minimum and maximum by removing 3 elements from the front.
// This results in only 3 deletions, which is the minimum number possible.
// Example 3:

// Input: nums = [101]
// Output: 1
// Explanation:
// There is only one element in the array, which makes it both the minimum and maximum element.
// We can remove it with 1 deletion.

// Constraints:

// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5
// The integers in nums are distinct.

#include <bits/stdc++.h>
using namespace std;

// by using hint I solve this:
// 1. There can only be three scenarios for deletions such that both minimum and maximum elements are removed.

// Scenario1: Both elements are removed by only deleting front the front

// Scenario2: Both elements are removed by only deleting from the back.

// Scenario3: Delete from the front to remove one of the elements, and delete from the back to remove the other element.  In this case we try both i) remove maximum from front and minimum from back ii) maximum from front and minimum from back and then take minimum of both cases- min(i,ii) cases

// And then we compare which of these three scenarios results in the minimum number of moves.

// example-: nums=[2,10,7,5,4,1,8,6]
// minimum =1 at index=5
// maximum=10 at index=1

// Scenario1: if we take out both from the front then first we remove the one that have smaller index so:
// i) miniIndex<maxiIndex
// we have 5<1 false means here maxiIndex<miniIndex so first 10 is out from front of the array so it takes 2 operations then nums=[7,5,4,1,8,6] now 1 is remove from the array after deletion of maximum so now it takes 4 operations
// frontOper=2+ 4 = 6 if we see formula when we delete from front for maxiimum deletions it is (maxiIndex-0+1) and for minimum deletion our array become short by maxiImdex so it is (maxiIndex-miniIndex) so frontOper=(maxiIndex-0+1)+(miniIndex-maxiIndex)  when (maxiIndex<miniIndex)
// if miniIndex<maxiIndex then FrontOPer=(miniIndex-0+1)+(maxiIndex-miniIndex) so this is scenario1

// Scenario2:  if we take out both from the back then first we remove the one that have larger index so:
// i) miniIndex<maxiIndex :
// 5<1 false means miniIndex is larger so first we remove the minimum elt from the array so if we remove 1 from the nums it take 3 operation and after that nums become [2,10,7,5,4] then we remove 10 from nums now it take 4 operations
// backOper=3+4=7  if we see formula when we delete from back then if miniIndex<maxiIndex then first we remove it so (n-miniIndex) then for maximum it is (miniIndex-maxiIndex ) so backOper=(n-miniIndex)+(miniIndex-maxiIndex ) when miniIndex>maxiIndex

// maxiIndex>miniIndex then backOper=(n-maxiIndex)+(maxiIndex-miniIndex)

// Scenario3: we have two cases in that :
// i) maximum from front and minimum from back
// ii) minimum from front and maximum from back
// and then take minimum of both so we get minimum number of operations
// Case i) oper1=(maxiIndex-0+1)+(n-minIndex)=(1-0+1)+(8-5)=5
// Case ii) oper2=(miniIndex-0+1)+(n-maxiIndex)=(5-0+1)+(8-1)=6+7=13
// backAndFront=min(oper1,oper2)
// in this example: backAndFront=min(5,13)=5

// final answer=min(both front, both back, backAndFront)=min(6,7,5)=5 so answer =5  so for this example optimal answer is given by scenario 3

// t.c-O(n)
// s.c-O(1)
int minimumDeletions(vector<int> &nums)
{
  int miniIndex = 0;
  int maxiIndex = 0;
  int mini = nums[0]; // because of constraint we cannot take mini=INT_MAx and maxi=INT_MIN
  int maxi = nums[0];
  int operations = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    // the integers in nums are distinct
    if (nums[i] > maxi)
    {
      maxi = nums[i];
      maxiIndex = i;
    }
    else if (nums[i] < mini)
    {
      mini = nums[i];
      miniIndex = i;
    }
  }

  // we having 0-based indexing

  // Scenario1: when both remove from front
  // int frontOper = 0;
  // if (miniIndex < maxiIndex)
  // {
  //   frontOper = frontOper + (miniIndex - 0 + 1) + (maxiIndex - miniIndex);
  // }
  // else
  // {
  //   frontOper = frontOper + (maxiIndex - 0 + 1) + (miniIndex - maxiIndex);
  // }
  // // Scenario2: when both remove from back
  // int backOper = 0;
  // if (miniIndex < maxiIndex)
  // {
  //   backOper = backOper + (n - maxiIndex) + (maxiIndex - miniIndex);
  // }
  // else
  // {
  //   backOper = backOper + (n - miniIndex) + (miniIndex - maxiIndex);
  // }

  // we can write frontOper and BackOper in one if and else
  int frontOper = 0, backOper = 0;
  if (miniIndex < maxiIndex)
  {
    frontOper = frontOper + (miniIndex - 0 + 1) + (maxiIndex - miniIndex);
    backOper = backOper + (n - maxiIndex) + (maxiIndex - miniIndex);
  }
  else
  {
    frontOper = frontOper + (maxiIndex - 0 + 1) + (miniIndex - maxiIndex);
    backOper = backOper + (n - miniIndex) + (miniIndex - maxiIndex);
  }

  // scenario3: Delete from the front to remove one of the elements, and delete from the back to remove the other element
  // so i) maximum from front and minimum from back
  // ii) minimum from front and maximum from back
  // and then take minimum of both so we get minimum number of operations
  int backAndFront = min((maxiIndex - 0 + 1) + (n - miniIndex), (miniIndex - 0 + 1) + (n - maxiIndex));

  // take minimum of all 3 scenarios
  operations = min(backAndFront, min(frontOper, backOper));

  return operations;
}

// slightly optimal then above one by not separate frontOper/backOper calculations based on index ordering.

// for indices miniIndex and maxiIndex:
// int left=min(miniIndex,maxiIndex)
// int right=max(miniIndex,maxiIndex)

// then:
// try this on pen and paper if confuse
// when we delete both from front then maximum of both indices +1 is total operations for that +1 because of 0-based indexing and maximum index comes later from front
// front=right+1

// when we delete from back then (n- minimum of both indices ) is total operations for that because when we rmeove from back them minimum of both index is later from back so
// back=n-left;

// when we delete one from front and one from right in that case we want minimum of both cases:
// i) maximum from front and minimum from back
// ii) minimum from front and maximum from back
// so the case that give minimum is when we remove min(of both index) from front and max(of both index ) from back because from front minimum of both is near and frmo back maximum of both index is near from back because large index is in last so
// both=(left+1)+(n-right) , in left+1 because of 0-based indexing and we use n not n-1

// answer= min(front,back,both)

// t.c-O(n)
// s.c-O(1)
int miniDeletions(vector<int> &nums)
{
  int n = nums.size();
  int miniIndex = 0;
  int maxiIndex = 0;

  // no need to store mini and maxi value of nums
  for (int i = 1; i < n; i++)
  {
    if (nums[i] > nums[maxiIndex])
    {
      maxiIndex = i;
    }
    if (nums[i] < nums[miniIndex])
    {
      miniIndex = i;
    }
  }
  int left = min(miniIndex, maxiIndex);
  int right = max(miniIndex, maxiIndex);

  // for explanation see above
  // delete both from front
  int front = right + 1;
  // delete both from back
  int back = n - left;
  // Delete one from front and one from back
  int both = (left + 1) + (n - right);

  return min({front, back, both});
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
  // both are correct and same t.c and s.c but second have cleaner solution then first one
  // cout << minimumDeletions(nums);
  cout << miniDeletions(nums);
  return 0;
}
