#include <iostream>
using namespace std;

int *printDivisors(int n, int &size)
{
  size = 0;               // Initialize size
  int *temp = new int[n]; // Allocate memory for storing divisors

  for (int i = 1; i <= n; i++)
  {
    if (n % i == 0)
    {
      temp[size++] = i; // Store divisor and increase size
    }
  }

  int *divisors = new int[size]; // Allocate exact-sized array
  for (int i = 0; i < size; i++)
  {
    divisors[i] = temp[i];
  }
  delete[] temp; // Free temporary array

  return divisors;
}

int main()
{
  int n, size;
  cout << "Enter a number: ";
  cin >> n;

  int *divisors = printDivisors(n, size);

  cout << "Divisors: ";
  for (int i = 0; i < size; i++)
  {
    cout << divisors[i] << " ";
  }
  cout << endl;

  delete[] divisors; // Free allocated memory

  return 0;
}