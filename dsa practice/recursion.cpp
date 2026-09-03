#include <bits/stdc++.h>
using namespace std;

void printNames(int i, int n)
{
  // for (int i = 1; i <= n; i++)
  // {
  //   cout << "Jagrati Sahu" << endl;
  //   if (i > n)
  //   {
  //     return;
  //   }
  // }

  // by recursion
  if (i > n)
  {
    return;
  }
  cout << "Jagrati Sahu" << endl;
  printNames(i + 1, n);
}
void printNumber(int i, int n)
{
  if (i > n)
  {
    return;
  }
  cout << i << endl;
  printNumber(i + 1, n);
}
void reverseNumber(int i, int n)
{
  if (i < 1)
  {
    return;
  }
  cout << i << endl;
  reverseNumber(i - 1, n);
}

// by backtracking
void printNumber1(int i, int n)
{
  if (i < 1)
  {
    return;
  }
  printNumber1(i - 1, n);
  cout << i << endl;
}

// by backtracking
void reverseNumber1(int i, int n)
{
  if (i > n)
  {
    return;
  }
  reverseNumber1(i + 1, n);
  cout << i << endl;
}

// parametrised recursion
void sum(int i, int add)
{
  if (i < 1)
  {
    cout << add << endl;
    return;
  }
  sum(i - 1, add + i);
}
// functional recusion
int add1(int n)
{
  if (n == 0)
  {
    return 0;
  }
  return n + add1(n - 1);
}
int factorial(int n) // time comp. = O(n)
// alse space comp. = O(n) by stack type tacking space
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  return n * factorial(n - 1);
}
// reverse an array by recursion
void reverseArray(int leftIndex, int rightIndex, int arr[])
{
  if (leftIndex >= rightIndex)
  {
    return;
  }
  swap(arr[leftIndex], arr[rightIndex]);
  reverseArray(leftIndex + 1, rightIndex - 1, arr);
}

// reverse an array by pointer
void reverse(int i, int arr[], int n)
{
  if (i >= n / 2)
  {
    return;
  }
  swap(arr[i], arr[n - i - 1]);
  reverse(i + 1, arr, n);
}
// checking string is palindrome or not by functional recursion
// time  compl. is = O(n/2)
// space compl. is = O(n/2)  by stack space, n/2 because half of the string is still waiting
bool palindrome(string s, int i, int n)
{
  if (i >= n / 2)
    return true;
  if (s[i] != s[n - i - 1])
  {

    return false;
  }
  return palindrome(s, i + 1, n);
  ;
}

// multiple recursion calls

// in this recursion tree is horizontal with a vertical tree, using this examine who execute first f(n-1) or f(n-2) and inside tree check- check see time compl. by seeing how many times recursion call

int fibonacci(int n) // time compl. = O(2^n) exponential in nature because for n it call 2 times , n-1 again 2 time call similarly so on
// space compl. = O()
{
  // if (n == 0)
  //   return 0;
  // else if (n == 1)
  //   return 1;

  if (n <= 1) // this use when n==2 f(2-1)=f(1)=1 and f(2-2)=f(0)=0
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
  // int last=fibonacci(n-1);
  // int slast=fibonacci(n-2);
  // return last+slast;
}
int main()
{
  int n;
  cin >> n;
  // printNames(1, n);
  // printNumber(1, n);
  // reverseNumber(n, n);
  // printNumber1(n, n);
  // reverseNumber1(1, n);
  // sum(n, 0);
  // int a = add1(n);
  // cout << a << endl;
  // cout << factorial(n) << endl;
  // int arr[n];
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> arr[i];
  // }
  // // reverseArray(0, n - 1, arr);
  // reverse(0, arr, n);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << arr[i] << endl;
  // }
  // string s = "abba";
  // cout << palindrome(s, 0, s.length()) << endl;
  // string z;
  // cin >> z;
  // cout << palindrome(z, 0, z.length()) << endl;
  cout << fibonacci(n) << endl;
  return 0;
}
