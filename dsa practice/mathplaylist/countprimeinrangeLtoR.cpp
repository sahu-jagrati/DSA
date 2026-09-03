// print the count of primes for range [L to R], L and R both are also included
// this is query based problem
// example- let no.of query, Q=3 and for each query we have L and R different

// i) Q=1, L=3 and R=10 so prime are[3,5,7] so cnt=3 print
// ii)Q=2, L=8 and R=20 so prime are[11,13,17,19] so cnt=4 print
// iii) Q=3, L=1 and R=5 so prime are[2,3,5] so cnt=3 print

// limits of no.of query(q) and L and R
// q<=10^5
// L<=R<=10^5
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
// q= number of queries
// N = maximum value of R
// If checkPrime(j) runs in O(√j):
// t.c-O(q*(R-L+1)*(sqrt(N)))
// s.c-O(1)

void count(vector<pair<int, int>> &queries)
{
  int q = queries.size();

  // for loop run q time
  for (int i = 0; i < q; i++)
  {
    // for each query we have L and R different
    int L = queries[i].first;
    int R = queries[i].second;
    int cnt = 0;
    // this for loop run (R-L+1) time
    for (int j = L; j <= R; j++)
    {
      // for each j we check
      if (checkPrime(j))
        cnt++;
    }
    cout << cnt << " ";
  }
}

// better solution- by checking prime(j) in O(1) time by sieve of Eratosthens
// here N is 10^6 because for each query we have different rage so we done for all that is make prime array of maximum

// t.c-O(N)+O(N(log(logN)))+O(N)=O(N(log(logN)))
// s.c-O(N) for prime array where N=10^6
vector<int> getSieve(int N)
{
  vector<int> prime(N + 1);
  // initially all are marked as 1
  for (int i = 2; i <= N; i++)
    prime[i] = 1;
  // marked

  for (int i = 2; i * i <= N; i++)
  {
    // if it is prime then marked all it multiple 0
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= N; j += i)
        prime[j] = 0;
    }
  }
  return prime; // array
}

// t.c-O(q*(R-L+1)) now
// s.c-O(10^6) for prime array where N= 10^6
void printCount(vector<pair<int, int>> &queries)
{
  int q = queries.size();
  // this take O(N(log(logN))) where N=10^6
  int MAXN = 1e6;
  vector<int> prime = getSieve(MAXN); // here N is 10^6 because for each query we have different rage so we done for all that is make prime array of maximum

  // run q time
  for (auto it : queries)
  {
    int L = it.first;
    int R = it.second;
    int cnt = 0;
    // take O(R-L+1) time
    for (int j = L; j <= R; j++)
    {
      // take O(1) time
      if (prime[j] == 1)
        cnt++;
    }
    cout << cnt << " ";
  }
}

// optimized solution-we cann't optimize q in time complxity because we have to go with each and every query so we try to optimize (R-L+1) by precomputation of cnt of each N upto 10^6 this is called prefix sum
// like we have prime array which denote who is prime or not by precomputation Sieve of Eratosthens
// same in this array we cnt prime for each number upto them and store cnt in it for each number
// and then get number of prime in range

// t.c-O(N(log(logN)))(where N is 10^6)+O(10^6)(for perfix sum)+O(q)
// s.c-O(10^6) for prime array

void printCountPrime(vector<pair<int, int>> &queries)
{
  // take O(N(log(logN))) where N=10^6
  int MAXN = 1e6;
  vector<int> prime = getSieve(MAXN); // this is now give who is prime or not
  int cnt = 0;
  // now prefix sum- precomputation of number of prime for each number in same prime array
  // start with 2 because for 0 and 1 number of prime is 0

  // run 10^6 time
  for (int i = 2; i <= 1e6; i++)
  {
    cnt = cnt + prime[i];
    prime[i] = cnt; // for that number
  }

  // run q time
  for (auto it : queries)
  {
    int L = it.first;
    int R = it.second;

    // number of prime in range L and R is
    cout << (prime[R] - prime[L - 1]) << " ";
  }
}

int main()
{
  int q;
  cout << "Enter the size of queries: ";
  cin >> q;
  // vector<pair<int, int>> queries(q); if we take like this defin size of queries then taking input like
  // using pre-sized vector
  //   for (int i = 0; i < q; i++)
  // {
  //     cin >> queries[i].first >> queries[i].second;
  // }

  vector<pair<int, int>> queries;
  // also take like this
  // vector<vector<int>>queries(q,vector<int>(2));
  // for this we take input for each query like cin>>queries[i][0]>>queries[i][1] and in similar way we access it

  cout << "Enter the value of L and R for each query: ";
  for (int i = 0; i < q; i++)
  {
    int L, R;
    cin >> L >> R;
    queries.push_back({L, R});
  }

  cout << "Print the number of prime in range L and R: ";
  // count(queries);
  // printCount(queries);
  printCountPrime(queries);
  return 0;
}

// RULE TO REMEMBER (INTERVIEW GOLD)

// ❗ If vector is created with size n, while taking input
// ❗ use indexing queries[i]
// ❗ NOT push_back()