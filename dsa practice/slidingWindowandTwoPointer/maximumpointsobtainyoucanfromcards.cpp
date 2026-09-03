// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain

// Example 2:
// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.

// Example 3:
// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards

// given an array which contain a points of N cards and an integer k given
// there's a task, we have to pick up a k cards from the given array of cards with the condition is that we can pick up the card either from the back or either from the front but cann't pick up directly from the middle means when k<n either start from front or back but don't pick directly from middle or can pick half from front and half from back and then maximize the number of points and pick cards consecutivel don't skip any card.

// example-[6,2,3,4,7,2,1,7,1], k=4 and size of array=9
// we cann't pick directly middle 7
// i) either pick all from front-6+2+3+4=15
// ii)either pick all from back-1+7+1+2=11
// iii)either pick 3 from front and 1 from back-6+2+3+1(from back)=12
// iV)either pick 2 from front and 2 from back-6+2+7+1=16
// v)either pick 1 from front and 3 from back-6+1+7+1=15

// so max sum=16 answer

// we use sliding window-take two pointer
// start from front and go to back by reducing 1 from front and adding 1 from back

// we can take all cards of an array but if not necessary then we cann't pick directly from middle

#include <bits/stdc++.h>
using namespace std;

// t.c-O(k)+O(k)=O(2*k)
// s.c-O(1)
int maxPoints(vector<int> &cardpoint, int k)
{
  int n = cardpoint.size();
  if (k > n)
    return 0;
  int leftSum = 0, rightSum = 0;
  int maxSum = 0;
  // initially we start from front
  // run k times
  for (int i = 0; i < k; i++)
    leftSum = leftSum + cardpoint[i];
  // initially
  maxSum = leftSum;
  // now we go to back
  int rightIndex = n - 1;
  // reduce from front and add from back
  //  run k times
  for (int i = k - 1; i >= 0; i--)
  {
    leftSum = leftSum - cardpoint[i];
    rightSum = rightSum + cardpoint[rightIndex];
    rightIndex--;
    maxSum = max(maxSum, leftSum + rightSum);
  }
  return maxSum;
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  vector<int> cardPoint(n);
  cout << "Enter the elt of an array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> cardPoint[i];
  }
  int k;
  cout << "Enter the number of elt that we can take: ";
  cin >> k;
  int result = maxPoints(cardPoint, k);
  cout << "Maximum point: " << result << endl;
  return 0;
}