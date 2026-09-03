// we have to check a number is prime or not

// definition of prime number - The number that is divisible by 1 and itself and the total no. of divisors is two(i.e one and itself)is prime number.
// example-: N=1 no.of divisor=1 so 1 is not prime
// N=2 no.of divisor=2(1 and 2) so 2 is prime

#include <bits/stdc++.h>
using namespace std;

// naive solution
// t.c-O(N)
// s.c-O(1)
bool check(int N)
{
  int cnt = 0;
  // run (N) time
  for (int i = 1; i <= N; i++)
  {
    // if take O(1) time
    if (N % i == 0)
      cnt++;
  }
  if (cnt == 2)
    return true;
  return false;
}

// optimized solution- checking divisor of number by run for loop upto sqrt(N) done in print divisor question
// instead of checking for [1 to N], we check for [1 to sqrt(N)]

// t.c-O(sqrt(N))
// s.c-O(1)

// we can use i*i<=N or i<=sqrt(N), sqrt() is predefine funtion in some language so better use is i*i<=N
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
int main()
{
  int N;
  cout << "Enter the number: ";
  cin >> N;
  // bool result = check(N);
  bool result = checkPrime(N);
  cout << "Prime or not: " << result << endl;
  return 0;
}