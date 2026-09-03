#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern2(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern3(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << (j + 1) << " ";
    }
    cout << endl;
  }
}
void pattern4(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << (i + 1) << " ";
    }
    cout << endl;
  }
}
void pattern5(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = n; j > i; j--)
    {
      cout << "* ";
    }
    cout << endl;
  }
}
void pattern6(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
void pattern7(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++)
    {
      cout << "*";
    }
    for (int l = 0; l < n - i - 1; l++)
    {
      cout << " ";
    }
    cout << endl;
  }
}
void pattern8(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }
    for (int k = 0; k < 2 * n - 2 * i - 1; k++)
    {
      cout << "*";
    }
    for (int l = 0; l < i; l++)
    {
      cout << " ";
    }
    cout << endl;
  }
}
void pattern9(int n)
{
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int star = i;
    if (i > n)
    {
      star = 2 * n - i;
    }
    {
      for (int j = 1; j <= star; j++)
      {
        cout << "*";
      }
      cout << endl;
    }
  }
}
void pattern10(int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      for (int j = 1; j <= i; j++)
      {
        if (j % 2 == 0)
        {
          cout << "1";
        }
        else
        {
          cout << "0";
        }
      }
    }
    if (i % 2 != 0)
    {
      for (int j = 1; j <= i; j++)
      {
        if (j % 2 != 0)
        {
          cout << "1";
        }
        else
        {
          cout << "0";
        }
      }
    }
    cout << endl;
  }
}
void pattern11(int n)
{
  int space = 2 * (n - 1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j;
    }

    for (int k = 1; k <= space; k++)
    {
      cout << " ";
    }
    for (int l = i; l >= 1; l--)
    {
      cout << l;
    }
    cout << endl;
    space -= 2;
  }
}
void pattern12(int n)
{
  int num = 1;
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= i; j++)
    {
      cout << num << " ";
      num += 1;
    }
    cout << endl;
  }
}
void pattern13(int n)
{

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << (char)(j + 64) << " ";
    }
    cout << endl;
  }
}
// void pattern14(int n)
// {

//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = n; j >= i; j--)
//     {
//       cout << (char)(j + 64)<<" ";
//     }
//     cout << endl;
//   }
// }
void pattern14(int n)
{

  for (int i = n; i >= 1; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << (char)(j + 64) << " ";
    }
    cout << endl;
  }
}
void pattern15(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << (char)(i + 64) << " ";
    }
    cout << endl;
  }
}
// void pattern16(int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < n - 1 - i; j++)
//     {
//       cout << " ";
//     }
//     for (int j = 1; j <= 2 * i + 1; j++)
//     {
//       cout << (char)(j + 64);
//     }
//     for (int j = 0; j < n - 1 - i; j++)
//     {
//       cout << " ";
//     }
//     cout << endl;
//   }
// }
void pattern16(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      cout << " ";
    }
    char ch = 'A';
    int breakpoint = (2 * i + 1) / 2;
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << ch << " ";
      if (j <= breakpoint)
      {
        ch++;
      }
      else
      {
        ch--;
      }
    }
    for (int j = 0; j < n - 1 - i; j++)
    {
      cout << " ";
    }
    cout << endl;
  }
}
void pattern17(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << (char)(65 + (n - j - 1)) << " ";
    }
    cout << endl;
  }
}
void pattern18(int n)
{
  int firstHalfSpace = 0; // initialspace
  for (int i = 0; i < n; i++)
  {
    // stars
    for (int j = 1; j <= n - i; j++)
    {
      cout << "*";
    }
    // spaces

    for (int j = 1; j <= firstHalfSpace; j++)
    {
      cout << " ";
    }
    for (int j = 1; j <= n - i; j++)
    {
      cout << "*";
    }
    firstHalfSpace += 2;
    cout << endl;
  }
  int secondHalfSpace = 2 * n - 2;
  for (int i = 1; i <= n; i++)
  {
    // stars
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    // space
    for (int j = 0; j < secondHalfSpace; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    secondHalfSpace -= 2;
    cout << endl;
  }
}
void pattern19(int n)
{
  int space = 2 * n - 2;
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int star = i;
    if (i > n)
    {
      star = 2 * n - i;
    }
    // stars
    for (int j = 1; j <= star; j++)
    {
      cout << "*";
    }
    // spaces
    for (int j = 1; j <= space; j++)
    {
      cout << " ";
    }
    // stars
    for (int j = 1; j <= star; j++)
    {
      cout << "*";
    }
    cout << endl;
    if (i < n)
    {
      space -= 2;
    }
    else
    {
      space += 2;
    }
  }
}
void pattern20(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == 1 || i == n || j == 1 || j == n)
      {
        cout << "*" << " ";
      }
      else
      {
        cout << " " << " ";
      }
    }
    cout << endl;
  }
}
void pattern21(int n)
{
  for (int i = 0; i < 2 * n - 1; i++)
  {
    for (int j = 0; j < 2 * n - 1; j++)
    {
      int top = i;
      int left = j;
      int right = (2 * n - 2) - j;
      int bottom = (2 * n - 2) - i;
      cout << (n - min(min(top, bottom), min(left, right)));
    }
    cout << endl;
  }
}
int main()
{
  // in online compiler there is so many test cases so here t denote test case
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n1;
    cin >> n1;
    // pattern1(n1);
    pattern2(n1);
    // pattern3(n1);
    // pattern4(n1);
    // pattern5(n1);
    // pattern6(n1);
    // pattern7(n1);
    // pattern8(n1);
    // pattern9(n1);
    // pattern10(n1);
    // pattern11(n1);
    // pattern12(n1);
    // pattern13(n1);
    // pattern14(n1);
    // pattern15(n1);
    // pattern16(n1);
    // pattern17(n1);
    // pattern18(n1);
    // pattern19(n1);
    // pattern20(n1);
    // pattern21(n1);
  }

  return 0;
}