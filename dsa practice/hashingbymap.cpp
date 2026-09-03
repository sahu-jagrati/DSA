#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// now time compl. is (n+n) not (n*n)

// in map<key,value> key can be any data type like int,char,sring etc and value can be int,string,vectoe etc but in unorederd map key can be only int or string but not char because it does not convert character to integer automatically

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // // precomputation
  // map<int, int> mp;
  // for (int i = 0; i < n; i++)
  // {
  //   mp[arr[i]]++;
  // }
  // // map store value in sorted order
  // // iteration we use auto loop
  // for (auto it : mp)
  // {
  //   cout << it.first << " " << it.second << endl;
  // }

  // int q;
  // cin >> q;
  // while (q--)
  // {
  //   int number;
  //   cin >> number;
  //   // fetch
  //   cout << mp[number] << endl;
  // }
  // we can also use map in character hashing
  // but map does not convert character to integer automatically here we see we get value of that character i.e its frequency
  string s;
  cin >> s;
  map<char, int> mp1; // <key,value>
  for (int i = 0; i < s.size(); i++)
  {
    mp1[s[i]]++;
  }
  for (auto it : mp1)
  {
    cout << it.first << " " << it.second << endl;
  }
  int q1;
  cin >> q1;
  while (q1--)
  {
    char ch;
    cin >> ch;
    cout << mp1[ch] << endl;
  }

  // unordered map
  unordered_map<int, int> ump;
  for (int i = 0; i < n; i++)
  {
    ump[arr[i]]++;
  }
  for (auto it : ump)
  {
    cout << it.first << " " << it.second << endl;
  }
  int q2;
  cin >> q2;
  while (q2--)
  {
    int number;
    cin >> number;
    // fetch
    cout << ump[number] << endl;
  }

  // in unoredered map, worst case time complexity is O(n) but in map it is O(log n) so generally unordered map is used because it is faster than map but in some very rare/minor cases we need to use map beacuse in unorderd map  time complexity is O(n^2)  because O(n) for each query and O(n) because of for loop running n times so it is O(n^2) but in map it is O(log n) for each query and O(n) for for loop so it is O(n log n) so in some cases we use map

  // first prefernce is for unorderd map if there is occur time limit exceed then we use map and it is occur due to internal collision in unorederd map

  // collision is generally occur when we have larger number of elements but we have less space i.e i have to store 139 but i have space of 100 so in this type of case we use following method -
  // division method
  // folding method
  // mid square method

  // these cases occurs also in hashing because we have limited size of array

  // collision -  in division method, example - when in an array all  number is ended with 8 like then 8,18,28,38,----,1008  we internally use method to know how many times that number occurs so collision occurs when we have same hash value for different keys
  // collosion  is the worst case in unordered map which is very-very minor case   because it takes O(n) time to find the value of that key and also worst case in map
  return 0;
}