// print all prime factors of a number

#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int N)
{
  int cnt = 0;
  // for loop run sqrt(N) time
  for (int i = 1; i * i <= N; i++)
  {
    // if take O(1) time
    if (N % i == 0)
    {
      cnt++;
      if (N / i != i)
        cnt++;
    }
    if (cnt > 2)
      break;
  }
  if (cnt == 2)
    return true;
  return false;
}

// naive solution-
// t.c-O(N*sqrt(N)) approx. if condition is not match for all i so prime check also not done for all i
// s.c-O(1), only ans space is there which store answer not solve the problem
vector<int> printPrimeFactors(int N)
{
  vector<int> ans;
  // for loop run (N) time
  // we start from i=2 because we want prime factor and 2 is first prime number so
  for (int i = 2; i <= N; i++)
  {
    // if condition is not match for all i so prime check also not done for all i
    if (N % i == 0)
    {
      // take (sqrt(N)) time
      if (checkPrime(i))
      {
        ans.push_back(i);
      }
    }
  }
  return ans;
}

// better solution- we know for divisor of number we can go upto sqrt(N) done in question print all divisors of number

// t.c- approx. O(sqrt(N)*2*sqrt(N)) because // if condition is not match for all i so prime check also not done for all i

// s.c-O(1), only ans space is there which store answer not solve the problem

vector<int> printprimeFactors(int N)
{
  vector<int> ans;
  // we start from i=2 because we want prime factor and 2 is first prime number so
  // for loop run sqrt(N) time
  for (int i = 2; i * i <= N; i++)
  {
    // if condition is not match for all i so prime check also not done for all i
    if (N % i == 0)
    {
      // // take (sqrt(N)) time
      if (checkPrime(i))
        ans.push_back(i);
      if (N / i != i) // to avoid repeat one
      {
        // take (sqrt(N)) time
        if (checkPrime(N / i))
          ans.push_back(N / i);
      }
    }
  }
  return ans;
}

// optimized solution- simple LCM type, when we do LCM of number we get prime factors of it and we divide with same factor until it divide with it
// for more detail see notes

// t.c-
// for a large number that is prime in itself still take O(N) time not reduce,so we have to optimize it still, we done optimization in next function

// s.c-O(1), only ans space is there which store answer not solve the problem
vector<int> primeFactors(int N)
{
  vector<int> ans;
  // we start from i=2 because we want prime factor and 2 is first prime number so
  for (int i = 2; i <= N; i++)
  {
    // if condition is not match for all i
    if (N % i == 0)
    {
      ans.push_back(i);
      // while loop take logarithmic time
      while (N % i == 0)
      {
        N = N / i; // this update N until it divide with i that we done in LCM
      }
    }
  }
  return ans;
}

// optimize above slightly by running for loop upto sqrt(N) time

// t.c- approx.O(sqrt(N)*(log(N))(while loop take)) approx. because if condition is not match for all i

// s.c-O(1), only ans space is there which store answer not solve the problem
vector<int> primefactors(int N)
{
  vector<int> ans;
  // we start from i=2 because we want prime factor and 2 is first prime number so

  // run sqrt(N) time
  for (int i = 2; i * i <= N; i++)
  {
    // if condition is not match for all i
    if (N % i == 0)
    {
      ans.push_back(i);
      // while loop take logarithmic time
      while (N % i == 0)
      {
        N = N / i; // this update N until it divide with i that we done in LCM
      }
    }
  }

  // this is when in for loop we don't reach upto N=1
  if (N != 1)
  {
    ans.push_back(N);
  }
  return ans;
}

int main()
{
  int N;
  cout << "Enter the number: ";
  cin >> N;
  // vector<int> result = printPrimeFactors(N);
  // vector<int> result = printprimeFactors(N);
  // vector<int> result = primeFactors(N);
  vector<int> result = primefactors(N);
  cout << "Print all prime factors of a number: ";
  for (auto it : result)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}