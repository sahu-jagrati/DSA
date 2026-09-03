#include <bits/stdc++.h>
using namespace std;

int countDigit(int n) // time complexity= O(log10(n))
{
  // int count = (int)(log10(n)+1); // by this directly get
  int count = 0;
  while (n > 0)
  {
    // int lastDigit = n % 10; // it has no use in countDigit , it has significance during extraction of digit
    count++;
    n = n / 10;
  }
  return count;
}
int reverseNumber(int n)
{
  int reverse = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    n = n / 10;
    reverse = (reverse * 10) + lastDigit;
  }
  return reverse;
}
void palindrome(int n)
{
  int a = reverseNumber(n);
  if (a == n)
  {
    cout << "Palindrome" << endl;
  }
  else
  {
    cout << "Not Palindrome" << endl;
  }
}
bool armstrong(int n)
{
  // we used temp here because when while loop completed then n=0 and n=0 value is compared with sum so we used temp  jisse n ka value last me change na ho
  int temp = n;
  int a = countDigit(n);
  int sum = 0;
  while (temp > 0)
  {
    int ld = temp % 10;
    sum += pow(ld, a);
    temp = temp / 10;
  }
  return (sum == n);
}
void divisors(int n)
{
  // here time complexity is O(n)
  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      cout << i << " ";
    }
  }
  cout << endl;
  // we can make it more efficient i.e time complexity is O(sqrt(n)) but it give in unsorted order so we use here vector

  vector<int> v;
  // sqrt() is a already define function it takes their time also so instead of this we use i*i<=n
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      v.push_back(i);
      if (i != n / i)
      {
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  for (auto it : v)
  {
    cout << it << " ";
  }
  cout << endl;
}
int main()
{
  int n;
  cin >> n;
  // int a = countDigit(n);
  // int a = reverseNumber(n);
  // cout << a << endl;
  // palindrome(n);
  // cout<<armstrong(n)<<endl;
  divisors(n);
  return 0;
}