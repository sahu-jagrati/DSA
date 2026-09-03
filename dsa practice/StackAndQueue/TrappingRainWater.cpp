// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:

// n == height.length
// 1 <= n <= 2 * 10^4
// 0 <= height[i] <= 10^5

#include <bits/stdc++.h>
using namespace std;

// here we want to find how much unit of water that we can store
// given that each building width is 1
// we can store water between buildings if there is any building in left and any building in right which is greater in height than current building height.

// so minimum(left building height,right building height) upto that we can store water because after that water flow down

// for an example: height=[4,2,0,3,2,5]
// if we draw above height building then we can see
// here before height=4 we cannot store water because there is no building in left
// when we draw these building heights we can see from height 4 in left to height 4 in right because of building height=5  we can store water between them and it is total 9 unit water that we can store
// use pen - paper to see it

// so we have to know that how much water can be trapped on top of each bar
// for that we need to know the highest bar on the left and the highest bar on the right of that position.

// brute force solution:

// To find how much water can be trapped on top of each bar ,  we need to know the highest bar on the left and the highest bar on the right of that position.

// The water trapped depends on the smaller of these two heights minus the height of the current bar i.e min(left max height,right max height)- current height.

// If the current bar is taller than both sides, no water can be trapped there. This needs to be done for every bar in the array.
// Always keep in mind that the leftmax and the rightmax both of them has to be greater than current bar height then only it can store water.

// For each bar in the array, find the maximum height bar on its left.
// Find the maximum height bar on its right.
// both leftmax and rightmax should be greater than current height to trap water

// Calculate the trapped water on the current bar as min(maxLeft,maxRight)-current height.

// Sum all trapped water from each bar to get the total amount of trapped water.

// example- height=[3,0,2,0,4]
// both leftmax and rightmax should be greater than current height to trap water

// for index 0: curr=3, maxLeft=3(itself), maxRight=4
// so water=min(3,4)-3=0(no water trapped) because there is no leftmax which is greater than current bar
// for index 1: curr=0, maxLeft=3, maxRight=4
// so water=min(3,4)-0=3 so 3 units of water trapped above bar height 0
// for index 2: curr=2, maxLeft=3, maxRight=4
// so water=min(3,4)-2=1 so 1 units of water trapped above bar height 2
// for index 3: curr=0, maxLeft=3, maxRight=4
// so water=min(3,4)-0=3 so 3 units of water trapped above bar height 0
// for index 4: curr=4, maxLeft=4(because leftmax shoud be greater than current but there is no highest building in left so itself), maxRight=4(itself)
// so water=min(4,4)-4=0 so 0 units of water trapped above bar height 2 because there is no leftmax and rightmax which is greater than current bar

// total water trapped=0+3+1+3+0=7 units

// Function to calculate trapped rainwater using brute force approach

// t.c-O(n^2) because for each bar, we scan all bars to its left and right to find the maximum height, resulting in nested loops.
// s.c-O(1)as no additional data structures are used proportional to input size, only variables to track max heights and total water.
int trap(vector<int> &height)
{
  int n = height.size();

  // variable to store total trapped water
  int totalWater = 0;

  // iterate over each bar in the elevation mao
  for (int i = 0; i < n; i++)
  {

    // initialize max heights to the left and right of current bar
    int maxLeft = 0;
    int maxRight = 0;

    // find maximum height to the left of current bar
    // we go upto current bar so we can check  that maxLeft should be greater than current bar or if it is not greater than it is equal to current bar
    for (int j = 0; j <= i; j++)
    {
      if (height[j] > maxLeft)
      {
        maxLeft = height[j];
      }
    }
    // find maximum height to the right of current bar
    // we start from current bar itself so we can check  that maxRight should be greater than current bar or if it is not greater than it is equal to current bar
    for (int j = i; j < n; j++)
    {
      if (height[j] > maxRight)
      {
        maxRight = height[j];
      }
    }
    // Water trapped on current bar is min of maxLeft and maxRight minus current height
    totalWater += min(maxLeft, maxRight) - height[i];
  }
  // return total trapped water
  return totalWater;
}

// better solution:
// formula is same as above used
// If the current bar is taller than both sides, no water can be trapped there. This needs to be done for every bar in the array.
// Always keep in mind that the leftmax and the rightmax both of them has to be greater than current bar height then only it can store water.

// here also we find how much water can be trapped by each bar but instead of figure out the leftmax and the rightmax for every elt by traversing left for leftmax and by traversing right for rightmax each time there is a better way to get the leftMax and rightMax

// by prefixMax and suffixMax
// prefixMax is basically a array of size n
// and similarly for suffixMax we define a array of size n
// so in prefixMax array for index i , prefixMax[i]= maximum of all elts in given array height till index i from index 0 means in left of current index
// and suffixMax[i]= maximum of all elts in given array from index i to n-1 means in right

// example: height=[2,1,0,5,3]
// prefixmax=[2,2,2,5,5,5]
// here we can say that till index 0 we have no elt in left so prefixMax[0]=height[0]=2
// till index 1 we have leftMax=2 so prefixMax[1]=2 and similalary we go for other indices

// suffixMax=[5,5,5,5,3]
// here we can say that suffixmax[0]=5 means for index0 will be the rightmax value for index0  and similarly for other indices

// so now we can easily figure out the leftMax by using prefixMax array and
// figure out rightMax by using the suffixMax array

// Function to calculate trapped rainwater using better force approach

// t.c-O(n)(for prefixmax array)+O(n)(for suffixmax array)+O(n)(for traverse each bar to find trap water)=O(3n)
// s.c-O(2n)(for prefixmax and suffixmax array)

int trappedWater(vector<int> &height)
{
  int n = height.size();
  // prefixMax array for storing leftMax upto that index
  vector<int> prefixMax(n);
  prefixMax[0] = height[0]; /// because for index0 there is no left
  for (int i = 1; i < n; i++)
  {
    prefixMax[i] = max(prefixMax[i - 1], height[i]); // by this we easily get leftmax for each index upto that index
  }
  // suffixMax array for storing rightMax upto that index
  vector<int> suffixMax(n);
  // for this we traverse from back because we have to check for right max
  suffixMax[n - 1] = height[n - 1]; // so for last index there is no right
  for (int i = n - 2; i >= 0; i--)
  {
    suffixMax[i] = max(suffixMax[i + 1], height[i]); // by this we easily get rightmax for each index upto that index
  }

  // now we find trapped water for each bar
  int totalWater = 0;
  for (int i = 0; i < n; i++)
  {
    int leftMax = prefixMax[i];
    int rightMax = suffixMax[i];
    // if currentheight is less than both leftmax and rightmax then we can trap water
    // If the current bar is taller than both sides, no water can be trapped there. This needs to be done for every bar in the array.
    // Always keep in mind that the leftmax and the rightmax both of them has to be greater than current bar height then only it can store water.
    if (height[i] < leftMax && height[i] < rightMax)
    {
      totalWater += min(leftMax, rightMax) - height[i];
    }
  }
  return totalWater;
}

// optimal approach: two-pointer approach
// The optimial approach uses two pointers to efficiently calculate the trapped water without extra space for arrays.
// The key insight is that the amount of water trapped at any position depends on the tallest bars to the left and right of that position. By maintaining two pointers starting from both ends of the elevation array and tracking the maximum heights enccountered so far from both sides, we can determine the trapped water at each step.
// If the left height is smaller or equal to the right height, the trapped water depends on the left side's maximum; otherwise, it depends on the right side's maximum. This two pointer technique lets us compute trapped water in one pass while using constant extra space.

// Initialize two pointers: one at the start(left) and one at the end(right) of the array.

// Initialize two variables to track the maximum height encountered so far from the left(maxLeft) and from the right(maxRight).

// Initialize a variable to store the total trapped water(totalWater).

// While the left pointer is less than or equal to the right pointer:
//     1.  If the height at the left pointer is less than or equal to the height at the right pointer:
//          i) If the height at left is greater than or equal to maxLeft, update maxLeft.
//          ii) else, add the difference between maxLeft and the current height at left to totalWater.
//          iii) Move the left pointer one step right.

//     2.   Otheriwse (height at right is smaller):
//           i) If the height at right is greater than or equal to maxRight, update maxRight.
//           ii) Else, add the difference between maxRight and the current height at right to totalWater.
//           iii) Move the right pointer one step left.

// Return totalWater as the total trapped rainwater.

//  example: height =  [3,0,2,0,4]
//                     left       right

// left point index=0 and right point index=4
//   left    right    maxLeft    maxRight       totalWater
// initially
//    0        4        0          0                 0

// height[left]<height[right] = 3<4
// so, maxLeft=3, move left by 1
//    1        4         3        0                  0
// height[left]<height[right] = 0<4 and in that also maxLeft>height[left] so water trapped
// so,maxLeft=3, Water=3-0=3, totalWater=3, left++
//    2        4        3         0                 3
//   again height[left]<height[right]=2<4 and we have maxLeft= 3 >height[left] so water tarpped
// so, maxLeft=3, Water=3-2=1, totalWater=4, left++
//   3         4        3         0                 4
//  //   again height[left]<height[right]=0<4 and we have maxLeft= 3 >height[left] so water tarpped
// so, maxLeft=3, Water=3-0=3, totalWater=7, left++
//   4         4         3        0                 7
// height[left]=4=height[right] and in this height[left]>=maxLeft=4>3 so update maxLeft=4, no water trapped in this case, left++
//   5         4          4        0                7
// loop ends as left>right
// answer is totalWater=7

// Function to calculate trapped rainwater using the optimal two-pointer approach

// t.c-O(n)  because the two pointers traverse the array only once, each pointer moving inward and covering the entire array in total linear time.
// s.c-O(1) as only constant extra space is used for pointers and variables, regardless of input size.
int trapWater(vector<int> &height)
{
  int n = height.size();
  // initialize two pointers at both ends of the array
  int left = 0;
  int right = n - 1;

  // variables to track the maximum height to the left and right
  int maxLeft = 0;
  int maxRight = 0;

  // variable to store total trapped water
  int totalWater = 0;

  // iterate until left pointer meets right pointer
  while (left <= right)
  {
    // we have to take always smaller from leftmax and rightmax because upto that we can trap water after that water flow
    // if left bar is smaller or equal to right bar
    if (height[left] <= height[right])
    {
      // if current left bar is higher than maxLeft, update maxLeft
      if (height[left] >= maxLeft)
      {
        maxLeft = height[left];
      }
      else
      {
        // water trapped on left is difference between maxLeft and current height
        totalWater += maxLeft - height[left];
      }
      left++; // move left pointer to the right
    }
    // if right bar is smaller than left bar
    else
    {
      // if current right bar is higher than maxRight,update maxRight
      if (height[right] >= maxRight)
      {
        maxRight = height[right];
      }
      else
      {
        // Water trapped on right is difference between maxRight and current height
        totalWater += maxRight - height[right];
      }
      right--; // move right pointer to the left
    }
  }
  // return total trapped water
  return totalWater;
}

// if currentheight is less than both leftmax and rightmax then we can trap water
// If the current bar is taller than both sides, no water can be trapped there. This needs to be done for every bar in the array.
// Always keep in mind that the leftmax and the rightmax both of them has to be greater than current bar height then only it can store water.

// totalWater=summation of i=0 to n (min(leftmax,rightmax)-height[i])

// we have to take always smaller from leftmax and rightmax because upto that we can trap water after that water flow
int main()
{
  int n;
  cin >> n;
  vector<int> height(n);
  for (int i = 0; i < n; i++)
  {
    cin >> height[i];
  }
  cout << trap(height) << endl;
  cout << trappedWater(height) << endl;
  cout << trapWater(height) << endl;
  return 0;
}