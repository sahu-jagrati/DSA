// we have an array like[]=[1,2,3,4,5] it represent these are already placed gas station at particular coordinate like at 0th index there is 1st gas station at 1 coordinate, 2nd gas station at 2 coordinate and so on these coordinate are on x-axis
// now, we have to place k gas station at minimise maximum distance
// we can place anywhere on the non-negative side of x-axis
// array is sorted and of positive integer
// we can also place at decimal cordinate
// you can also place two gas station at same coordinate
// Note- Answer within 10^-6 of the actual answer will be accepted otherwise it show time limit excced
// and return in long double/double/float

// in answer we also observe that in placing new gas station ideally we don't have to go left part of an array i.e like in example that we take not go before 1 and also not in right part because in right part we can put gas station at 100 coordinate but we want min(max)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// brute- // time complexity -O(k*n)+O(n)
// space complexity-O(1)
// this is not give proper answer it show time limit exceeds
// e.g-arr=[1,13,17,23], k=5, answer=3 but it give other
long double minimaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> howMany(n - 1, 0); // n-1 size and value is 0
  for (int gasStation = 1; gasStation <= k; gasStation++)
  {
    long double maxSection = -1;
    int maxIndex = -1;
    for (int i = 0; i < n - 1; i++)
    {
      long double diff = (arr[i + 1] - arr[i]);
      long double sectionLength = diff / (long double)(howMany[i] + 1);
      if (sectionLength > maxSection)
      {
        maxSection = sectionLength;
        maxIndex = i;
      }
    }
    howMany[maxIndex]++;
  }
  long double maxans = -1;
  for (int i = 0; i < n - 1; i++)
  {
    long double diff = (arr[i + 1] - arr[i]);
    long double sectionLength = diff / (long double)(howMany[i] + 1);
    maxans = max(maxans, sectionLength);
  }
  return maxans;
}

// optimize-
// we use priority queue(max heap)- pq.push(2)
// pq.push(3) - it take log n to push
// pq.push(1); it take log n to push
// pq.top()- give 3 because it store max in top
// pq.pop()
// pq.top()-give 2

// time complexity-n*log n(for push in pq)+ k*log n
// space complexity-O(n-1) // now optimize this
long double minimaxdistance(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  priority_queue<pair<long double, int>> pq;
  for (int i = 0; i < n - 1; i++)
  {
    pq.push({arr[i + 1] - arr[i], i});
  }
  for (int gasStation = 1; gasStation <= k; gasStation++)
  {
    auto top = pq.top();
    pq.pop();
    int sectionIndex = top.second;
    howMany[sectionIndex]++;
    long double initialdiff = arr[sectionIndex + 1] - arr[sectionIndex];
    long double newSectionLength = initialdiff / (long double)(howMany[sectionIndex] + 1);
    pq.push({newSectionLength, sectionIndex});
  }
  return pq.top().first;
}

// optimize space complexity- we have to find min(max) so, we can use binary search but not directly because we have long double and also can have decimal as answer so we can't directly do low=mid+1 or high=mid-1
// first we have to find range of answer-[0 to max(consecutive distance btw arr elements)], we can't take less than 0, we have to be in non-negative x-axis

// time complexity-O(n)(for finding high)+O(log (max(consecutive distance btw arr elements)-0) (base 2))*O(n)
// space complexity-O(1)
int numberOfGasStationsRequired(vector<int> &arr, long double dis)
{
  int cnt = 0;
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    int numberInBetween = ((arr[i] - arr[i - 1]) / dis);
    if ((arr[i] - arr[i - 1]) / dis == numberInBetween * dis)
    {
      numberInBetween--;
    }
    cnt += numberInBetween;
  }
  return cnt;
}
long double minimiseMaxDistance(vector<int> &arr, int k)
{
  int n = arr.size();
  long double low = 0;
  long double high = 0;
  for (int i = 0; i < n - 1; i++)
  {
    high = max(high, (long double)(arr[i + 1] - arr[i]));
  }
  long double diff = 1e-6;

  while (high - low > diff)
  {
    long double mid = (low + high) / (2.0);
    int cnt = numberOfGasStationsRequired(arr, mid);
    if (cnt > k)
    {
      low = mid;
    }
    else
    {
      high = mid;
    }
  }
  return high; // here concept of opposite polarity doesn't work
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // array should be sorted
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k; // gas station that has to be placed in an array
  cin >> k;
  // long double result = minimaxDistance(arr, k);
  // long double result = minimaxdistance(arr, k);
  long double result = minimiseMaxDistance(arr, k);
  cout << result << endl;
  return 0;
}
