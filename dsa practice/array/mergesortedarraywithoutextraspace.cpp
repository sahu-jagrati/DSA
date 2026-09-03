// with extra space
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity-O(n+m)+O(n+m)
// space complexity-O(n+m)
void merge(vector<int> &a1, vector<int> &a2)
{
  int n = a1.size();
  int m = a2.size();
  vector<int> a3(n + m);
  int left = 0;
  int right = 0;
  int index = 0;
  while (left < n && right < m)
  {
    if (a1[left] <= a2[right])
    {
      a3[index] = a1[left];
      left++, index++;
    }
    else
    {
      a3[index] = a2[right];
      index++, right++;
    }
  }
  while (left < n)
  {
    a3[index++] = a1[left++];
  }
  while (right < m)
  {
    a3[index++] = a2[right++];
  }
  // put back in a1 and a2
  for (int i = 0; i < n + m; i++)
  {
    if (i < n)
    {
      a1[i] = a3[i];
    }
    else
    {
      a2[i - n] = a3[i];
    }
  }
}

// without extra space-
// optimal solution1-
// time complexity-O(min.(n,m)) (because of while loop) + O(n log n) + O(m log m)
// space complexity-O(1)
void Merge(vector<int> &a1, vector<int> &a2)
{
  int n = a1.size();
  int m = a2.size();
  int left = n - 1;
  int right = 0;
  while (left >= 0 && right < m)
  {
    if (a1[left] > a2[right])
    {
      // a1[left] = a2[right]; we cann't write this we have to swap it
      swap(a1[left], a2[right]);
      left--, right++;
    }
    else
    {
      break;
    }
  }
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());
}

// optimal solution2- gap method based on shell sorting
// time complexity-O(log base 2 (n+m)) * O(n+m) ( for inside while loop )
// space complexity-O(1)
void swapifgreater(vector<int> &a1, vector<int> &a2, int ind1, int ind2)
{
  if (a1[ind1] > a2[ind2])
  {
    swap(a1[ind1], a2[ind2]);
  }
}
void mergesortedArray(vector<int> &a1, vector<int> &a2)
{
  int n = a1.size();
  int m = a2.size();
  int len = n + m;
  int gap = (len / 2) + (len % 2);
  while (gap > 0)
  {
    int left = 0;
    int right = left + gap;
    while (right < len)
    {
      //  we are in both array a1 and a2
      if (left < n && right >= n)
      {
        swapifgreater(a1, a2, left, right - n);
      }
      // we are in only a2 array
      else if (left >= n)
      {
        swapifgreater(a2, a2, left - n, right - n);
      }
      // we are in a1 only
      else
      {
        swapifgreater(a1, a1, left, right);
      }
      left++, right++;
    }

    if (gap == 1)
      break;
    gap = (gap / 2) + (gap % 2);
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a1(n);
  vector<int> a2(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a1[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> a2[i];
  }
  // merge(a1, a2);
  // Merge(a1, a2);
  mergesortedArray(a1, a2);
  for (int i = 0; i < n; i++)
  {
    cout << a1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < m; i++)
  {
    cout << a2[i] << " ";
  }
  cout << endl;
  return 0;
}