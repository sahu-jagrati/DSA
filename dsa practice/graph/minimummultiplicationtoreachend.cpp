// Given start,end and an array of n numbers. At each step, start is multiplied with any number in the array as many times you want(i.e you can multiply with same number as many times as you want) and then mod opeation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// so the range of number that we get after multiply is from 0 to 10^5 if it exceeds 10^5 then do mod with 10^5
// we do mod with 10^5 every time but when the number exceeds 10^5 then it work otherwise for lesser than 10^5 mod with 10^5 gives same number e.g- 4 % 10^5 =4
// 125 % 10^5 = 125
// 9999 % 10^5=9999
// but 10^5 % 10^5 =0
// (10^5 + 1)% 10^5=1
// (10^5 + 2 )% 10^5=2

// what is thought process behind this problem ?
// we have start node and for start step =0
// we multiply start with each elt of array and increase step by +1
// same for next number we multiply them also with each elt of array and increase step by +1 again and do until we get end also do mod with 10^5 for keep in range number

// as usual we apply djikstra for shortest path, here we have  no negative cycle and edge
// so we apply djikstra algo here but step increase by + 1 only as constant increasing so PQ not required, so we use queue here which reduce logV factor of djikstra

// range of number after multiplication - [0, 10^5-1]

#include <bits/stdc++.h>
using namespace std;

// s.c-O(10^5)(for distance array)+O(10^5)(for queue in worst case or in hypothetical scenario)
// we use djikstra but we don't use PQ, we use queue here
// t.c-O(100000*arr.size) in worst case, very hypothetical scenarion when you generate all number from [0,10^5] and multiply each with arr[i] but in real case t.c always less than this and depend on array elt after multiply what we get
class Solution
{
public:
  int minimumMultiplication(vector<int> &arr, int start, int end)
  {
    // not use PQ because of constant increasing in step
    queue<pair<int, int>> q;
    //{node,step}
    q.push({start, 0});

    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    int mod = 100000;

    while (!q.empty())
    {
      int node = q.front().first;
      int step = q.front().second;
      q.pop();

      // multiply with each element
      for (auto it : arr)
      {
        int num = (it * node) % mod; // to get in range
        if (step + 1 < dist[num])
        {
          dist[num] = step + 1;
          if (num == end)
            return step + 1;
          q.push({num, step + 1});
        }
      }
    }
    return -1;
  }
};

// input type- start=3,end=75,mod=100000
// arr=[2,5,7]
int main()
{
  int n;
  cout << "Enter the size of array: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elt of array (positive value): ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int start, end;
  cout << "Enter the value of start and end : ";
  cin >> start >> end;

  Solution result;
  cout << result.minimumMultiplication(arr, start, end) << endl;

  return 0;
}