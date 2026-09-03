#include <bits/stdc++.h>
using namespace std;

// t.c-O(n)
// s.c-O(n) for answer string
string restoreString(string s, vector<int> &indices)
{
  int n = s.size();
  string answer(n, ' '); // for getting index of answer so we start with empty string of n size
  // and we cannot chang in s directly because after i=n/2 we s is change for half size and for next i it get change s[i] so get wrong answer
  for (int i = 0; i < n; i++)
  {
    answer[indices[i]] = s[i];
  }
  return answer;
}

int main()
{
  int n;
  cout << "Enter the size: ";
  cin >> n;
  vector<int> indices(n);
  cout << "Enter indices array: ";
  for (int i = 0; i < n; i++)
  {
    cin >> indices[i];
  }
  string s;
  cout << "Enter the string: ";
  cin >> s;

  string answer = restoreString(s, indices);
  cout << answer << endl;
  return 0;
}