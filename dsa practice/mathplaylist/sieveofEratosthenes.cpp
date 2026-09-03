// given a number N, print all primes till N.
// example-: N=10 so print [2,3,5,7] all prime till 10.

#include <bits/stdc++.h>
using namespace std;

// t.c-O(sqrt(N))
// s.c-O(1)
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

// t.c-O(N*sqrt(N))
// s.c-O(1)
void print(int N)
{
  // for loop run N time
  // we start with 2 because 2 is first prime
  for (int i = 2; i <= N; i++)
  {
    // take sqrt(N) time
    if (checkPrime(i))
    {
      cout << i << " ";
    }
  }
}

// optimize solution- if we try to check prime in O(1) time then we can optimize above solution
// so we take an array prime of size (N+1)
// initially all marked as 1
// prime[0] and prime[1] marked as 0 because they are not prime so we start from 2
// if it is marked as 1 we take it and marked all multiple of it 0
// similary take 3 if it is 1 take it and marked all multiple of 3 is 0
// so 0 denote it is not prime and 1 denote it is prime
// in last, in array those are marked with 1 is prime
// so by array we can check prime now in O(1) time
// this is precomputation that we do and it is know as Sieve of Eratosthenes

void printPrime(int N)
{
  vector<int> prime(N + 1);
  // initially marked all as 1 and prime[0] and prime[1] =0 because they are not prime
  // we start with 2 because 2 is first prime
  for (int i = 2; i <= N; i++)
  {
    prime[i] = 1;
  }
  // marking
  // for this for loop we cannot tell about time complexity it's still complicated
  for (int i = 2; i <= N; i++)
  {
    // check here
    if (prime[i] == 1)
    {
      // if it is prime then marked all it multiple 0
      //  j start with i*2 and next j is j+i
      for (int j = 2 * i; j <= N; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  // get prime array
  for (int i = 2; i <= N; i++)
  {
    // give prime till N
    if (prime[i] == 1)
      cout << i << " ";
  }
}

// in above solution we can optimize marked for loop more by two observation-
// Ist observation- first we go with i=2 and marked all multiple of it 0 then we go i=3 and marked it all multiple to 0 but here we see when we do i=2 we marked already 2*3=6 already 0 and when i=3 we again run loop for 3*2=6 that already marked 0 similary in case if i=3 we marked 3*5=15 as 0 in case of i=5 why we again do 5*3=15 marked 0 so we can improve it by
// not start j loop from (2*i), we start it from (i*i)

// IInd observation-by Ist observation now j start from i*i
// when we run i loop in start from [2 to N] in case of like N=30 when i=6 so j=6*6=36 greater than N so not consider so we take i loop in start from [2 to sqrt(N)]

// now updated optimize solution-

// t.c-O(N)+O(N(log(logN)))+O(N)
// s.c-O(N) for prime array

void printPrimeTillN(int N)
{
  vector<int> prime(N + 1);
  //  // initially marked all as 1 and prime[0] and prime[1] =0 because they are not prime
  // we start with 2 because 2 is first prime
  // take O(N) time
  for (int i = 2; i <= N; i++)
    prime[i] = 1;

  // marking
  // this for loop time complexity is mathematically prove so cann't explain, this is prime harmonic series and take O(N(log(logN)))
  // IInd observation
  for (int i = 2; i * i <= N; i++)
  {
    if (prime[i] == 1)
    {
      // Ist observation
      for (int j = i * i; j <= N; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  // print
  // take O(N) time
  for (int i = 2; i <= N; i++)
  {
    if (prime[i] == 1)
      cout << i << " ";
  }
}

// in above we can optimize one more thing that  we can completely ignoe even numbers except 2 because all are multiple of 2 does not have prime number property so they cannot be prime
// Except for 2 , every prime is odd
// so instead of storing information for: 0,1,2,3,4,5,6,7....
// we can store only : 3,5,7,9,11...
// This cuts the memory roughly in half again

// here we cnt number of primes  numbers that are strictly less than n.
//  Constraints:

// 0 <= n <= 5 * 10^6
// Why this is faster

// Your original above sieve processes:

// 2, 3, 4, 5, 6, 7, 8, 9, ...

// But we know:

// 4, 6, 8, 10, 12, ... → never prime

// So the optimized version only stores:

// 3, 5, 7, 9, 11, 13, ...

// That's roughly half the memory and significantly fewer operations.

int countPrimes(int n)
{
  if (n <= 2)
    return 0;
  // storing half memory
  int size = n / 2;
  // we have large constraints so we take bool instead of int because bool take less space in comparison to int , int typically 4 bytes for each elt so for n=10^7 is approx. 40 MB
  vector<bool> isPrime(size, true);
  // index i represents number 2*i+1 here
  isPrime[0] = false; // means index 0 represents number 1
                      // i*i can be overflow in int so we use 1LL*i*i
                      // i+=2 so we jump to get only odd number
  for (int i = 3; 1LL * i * i < n; i += 2)
  {
    // isPrime[i/2]==true means it is prime
    if (isPrime[i / 2])
    {
      // j+=i it is only because of ;arge constraint so we do j=j+2LL*i
      for (long long j = 1LL * i * i; j < n; j += 2LL * i)
      {
        isPrime[j / 2] = false;
      }
    }
  }
  int cnt = 0;
  if (n > 2)
    cnt = 1; // because for that number 2 is always count in prime less than n
  for (int i = 1; i < size; i++)
  {
    if (isPrime[i])
      cnt++;
  }
  return cnt;
}
int main()
{
  int N;
  cout << "Enter the number: ";
  cin >> N;
  cout << "Print all prime till N: ";
  // print(N);
  // printPrime(N);
  printPrimeTillN(N);
  cout << endl;
  cout << "Number of primes less than N: " << countPrimes(N);
  return 0;
}