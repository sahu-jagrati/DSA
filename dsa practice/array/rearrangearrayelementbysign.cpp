// rearrange like-[+ve,-ve,+,-,+,-] and size of array shoule be even

#include <iostream>
#include <vector>
using namespace std;

// brute approach- time complexity-O(n)+O(n/2)=O(n)
// space complexity-O(n/2)+O(n/2)=O(n)
void rearrangeElements(vector<int> &arr)
{
  int n = arr.size();
  vector<int> pos;
  vector<int> neg;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      pos.push_back(arr[i]);
    }
    else
    {
      neg.push_back(arr[i]);
    }
  }
  for (int i = 0; i < n / 2; i++)
  {
    arr[2 * i] = pos[i];
    arr[2 * i + 1] = neg[i];
  }
}

// optimal approach-
void rearrangeArrayElements(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans(n);
  int posIndex = 0, negIndex = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      ans[posIndex] = arr[i];
      posIndex += 2;
    }
    else
    {
      ans[negIndex] = arr[i];
      negIndex += 2;
    }
  }
  for (int i = 0; i < n; i++)
  {
    arr[i] = ans[i];
  }
}

// variety 2- when no. of positive is not equal to no. of negative
// in this we go to brute approach of variety1-
// time complexity-O(n)+O(min.(pos,neg))+O(leftover) - cases of 2nd and 3rd part-  i) case minimum - when no. of pos=0 and no.of neg =n or no.of pos=n and no.of neg=0 in that case time complexity-O(n)+O(0)+O(n) ii)case maximum- when no.of pos==no.of neg in that case time complexity-O(n)+O(n/2)+O(0). So, by taking all case time complexity -O(n)+O(n)=O(2n)
// space complexity-O(n) for pos.array and ne.array
// These complexity is of function not of main function
vector<int> rearrangearrayelements(vector<int> &arr)
{
  int n = arr.size();
  vector<int> pos, neg;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0)
    {
      pos.push_back(arr[i]);
    }
    else
    {
      neg.push_back(arr[i]);
    }
  }

  if (pos.size() > neg.size())
  {
    for (int i = 0; i < neg.size(); i++)
    {
      arr[i * 2] = pos[i];
      arr[i * 2 + 1] = neg[i];
    }
    int index = neg.size() * 2;
    for (int i = neg.size(); i < pos.size(); i++)
    {
      arr[index] = pos[i];
      index++;
    }
  }
  else
  {
    for (int i = 0; i < pos.size(); i++)
    {
      arr[i * 2] = pos[i];
      arr[i * 2 + 1] = neg[i];
    }
    int index = pos.size() * 2;
    for (int i = pos.size(); i < neg.size(); i++)
    {
      arr[index] = neg[i];
      index++;
    }
  }
  return arr;
}
int main()
{
  int n; // n should be even
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // rearrangeElements(arr);
  // rearrangeArrayElements(arr);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << arr[i] << " ";
  // }
  vector<int> result = rearrangearrayelements(arr);
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}