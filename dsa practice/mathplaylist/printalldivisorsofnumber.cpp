// print all divisors of a number-order does not matter
// we know divisor of a number N lie btw [1 to N]

#include <bits/stdc++.h>
using namespace std;

// naive solution-
// t.c-O(N)
// s.c-O(1), only ans space is there which store answer not solve the problem
vector<int> printDivisor(int N)
{
  vector<int> ans;
  // for loop run (N) time
  for (int i = 1; i <= N; i++)
  {
    // if take O(1) time
    if (N % i == 0)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

// optimized solution - can be run loop upto sqrt(N)
// because for example N=36 so divisors are=[1,2,3,4,6,9,12,18,36]
// we see if we figure out 1 then we can figure out 36 - 1*36=36
// similarly 2*18=36, 3*12=36, 4*9=36, 6*6=36 so if we get i then other is N/i

// t.c-O(sqrt(N))
// s.c-O(1), only ans space is there which store answer not solve the problem

// we can use i*i<=N or i<=sqrt(N), sqrt() is predefine funtion in some language so better use is i*i<=N

vector<int> printAllDivisor(int N)
{
  vector<int> ans;
  // for loop run (sqrt(N)) time
  for (int i = 1; i * i <= N; i++)
  {
    // if take O(1) time
    if (N % i == 0)
    {
      ans.push_back(i);
      if (N / i != i)
      { // this is for avoid repeat
        ans.push_back(N / i);
      }
    }
  }
  return ans;
}
int main()
{
  int N;
  cout << "Enter the number: ";
  cin >> N;
  // vector<int> result = printDivisor(N);
  vector<int> result = printAllDivisor(N);
  cout << "Print all divisor of a number: ";
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}