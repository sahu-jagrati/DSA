// A complex number can be represented as a string on the form "real+imaginaryi" where:

// real is the real part and is an integer in the range [-100, 100].
// imaginary is the imaginary part and is an integer in the range [-100, 100].
// i2 == -1.
// Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

// Example 1:

// Input: num1 = "1+1i", num2 = "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
// Example 2:

// Input: num1 = "1+-1i", num2 = "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.

// Constraints:

// num1 and num2 are valid complex numbers.

#include <bits/stdc++.h>
using namespace std;

// complex number multiplication is: (a+bi)(c+di)=(ac-bd)+i(ad+bc)
void complexNumberMultiplication(string num1, string num2)
{
  char a,b,c,d;
  for (int i = 0; i < num1.size(); i++)
  {
    if(num1[i]=='-'){
      
    }
  }
}
int main()
{
  string num1, num2;
  cin >> num1 >> num2;
  complexNumberMultiplication(num1, num2);
  return 0;
}