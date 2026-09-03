// Given an integer n, return any array containing n unique integers such that they add up to 0.

// Example 1:

// Input: n = 5
// Output: [-7,-1,1,3,4]
// Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
// Example 2:

// Input: n = 3
// Output: [-1,0,1]
// Example 3:

// Input: n = 1
// Output: [0]

// Constraints:

// 1 <= n <= 1000

// Hint 1
// Return an array where the values are symmetric. (+x , -x).
// Hint 2
// If n is odd, append value 0 in your returned array.

#include <bits/stdc++.h>
using namespace std;

// for sum = zero we have to say like that total positive sum = total negative sum of all elts in an array
// so we use hint

// t.c-O(n/2) because at a time we insert two elt
// s.c-O(n) for result array

// we have two mistake in our code
// if i=n-1 then i+1=n which is out of bound access  so valid indices are 0 to n-1
// Wrong Logic for Even n

// we wrote:

// if(n%2==0) result[0] = -(result[n-1]);

// But result[n-1] may not even be initialized correctly because of the loop issue.

// Also, the standard solution is simpler:

// Pair numbers i and -i

// If n is odd → include 0
// vector<int> sumZero(int n)
// {
//   vector<int> result(n);
//   for (int i = 1; i < n; i += 2)
//   {
//     result[i] = i;
//     result[i + 1] = (-i);
//   }
//   if (n % 2 == 0)
//     result[0] = -(result[n - 1]);
//   // in n = odd case result[0]=0 automatically
//   return result;
// }

// after fixing above solution
// t.c-O(n/2)
// s.c-O(n) for result array
vector<int> sumZero(int n)
{
  vector<int> result(n);
  int index = 0;
  for (int i = 1; i <= n / 2; i++)
  {
    result[index++] = i;
    result[index++] = -i;
  }
  if (n % 2 == 1)
    result[index] = 0;
  return result;
}

// one more similar way to write without using index variable
// we use push_back so there is no need of declaring result is of size n

// t.c-O(n/2)
// s.c-O(n) for result array
vector<int> SumZero(int n)
{
  vector<int> result;
  for (int i = 1; i <= n / 2; i++)
  {
    result.push_back(i);
    result.push_back(-i);
  }
  if (n % 2 == 1)
    result.push_back(0);
  return result;
}
int main()
{
  int n;
  cin >> n;
  // vector<int> answer = sumZero(n);
  vector<int> answer = SumZero(n);
  for (auto it : answer)
  {
    cout << it << " ";
  }
  return 0;
}