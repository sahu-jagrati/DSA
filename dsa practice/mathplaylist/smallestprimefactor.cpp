// this is a guery based problem
// in this question we have to print all prime factors of a number with their duplicacy
// example- N=60 take LCM-[2,2,3,5] are all prime factor of 60 woth duplicates of them

// we have to given number of queries(q) and the number in each query find the prime factorisation(i.e all prime factor with duplicates it there exists) of them
// example-q=3 number of queries
// for i)number =12, answer=[2,2,3]
// for ii) number=16, answer=[2,2,2,2]
// for iii) number=60, answer=[2,2,3,5]

// contraints-
// 1<=q<=10^5
// 1<=number<=10^5

#include <bits/stdc++.h>
using namespace std;

// naive solution-

// see print all prime factor code for more detail
vector<int> getPrimeFactor(int number)
{
  vector<int> ans;
  for (int i = 2; i * i <= number; i++)
  {
    if (number % i == 0)
    {
      while (number % i == 0)
      {
        // push all duplicates also
        ans.push_back(i);
        number = number / i;
      }
    }
  }
  if (number != 1)
    ans.push_back(number);
  return ans;
}
void printAll(vector<int> queries)
{
  int q = queries.size();
  for (int i = 0; i < q; i++)
  {
    int number = queries[i];
    vector<int> answer = getPrimeFactor(number);
    for (auto it : answer)
    {
      cout << it << " ";
    }
    cout << endl;
  }
}

// optimize solution- if somehow we know the smallestprime factor then we can skip the initial iteration
// example- number=25 then it's smallest prime factor is 5 so why we do iteratio for 2,3 if they don't contribute
// so we try to get smallest prime factor(SPF) of number

// we do precomputation forSPF similar to sieve of eratosthenes
// we make an array of SPF[1e5+1] for all number wher size 10^5 + 1
// initially all are SPF[i]=i
// if SPF[i]==i then it is prime and marked all multiple of it = i if their multiples also visit first time means SPF[j]=j should also be then marked with i if SPF[j]!=j means they already have smallest prime factor

// once we have the SPF, it will take the log(number)(base 2) in the worst case scenario if all the smallest prime factor are 2.
// But in case of bigger-smallest prime factor it will take lesser time

// for more detail see notes

// t.c-O(1e5)+O(N(log(log(N))))+O(q*log(N)(base 2)) where max.N=1e5
// s.c-O(1e5) for SPF array

void printAllPrimeFactorWithDuplicates(vector<int> queries)
{
  vector<int> SPF(1e5 + 1); // we make array for all number so size is 1e5+1
  // initially SPF[i]=i marked

  // take O(1e5)
  for (int i = 1; i <= 1e5; i++)
  {
    SPF[i] = i;
  }

  // for loop starting discussion see sieve of eratosthenes
  //  marking start

  // take O(N(log(log(N)))) where max.N=1e5
  for (int i = 2; i * i <= 1e5; i++)
  {
    // if it is prime then
    if (SPF[i] == i)
    {
      // then mark
      for (int j = i * i; j <= 1e5; j += i)
      {
        // only when they not mark by other
        if (SPF[j] == j)
        {
          SPF[j] = i;
        }
      }
    }
  }
  int q = queries.size();
  // run q time
  for (int i = 0; i < q; i++)
  {
    int number = queries[i];
    // take log(N)(base 2) in worst case
    while (number != 1)
    {
      // first smallest prime factor;
      cout << SPF[number] << " ";
      number = number / SPF[number];
    }
    cout << endl;
  }
}

int main()
{
  int q;
  cout << "Enter the size of queries: ";
  cin >> q;
  vector<int> queries(q);
  cout << "Enter the number in the queries array: ";
  for (int i = 0; i < q; i++)
  {
    cin >> queries[i];
  }
  // printAll(queries);
  printAllPrimeFactorWithDuplicates(queries);
  return 0;
}