// if we want to search number in an array that how many times it will come then by for loop generally we can find like
// int countNumberTime(int number,int arr[],int n){
//   int count=0;
// for(int i=0;i<n;i++){
// if(arr[i]==number){
//   count++ ;
// }
// }
// return count;
// }

// example if we have array like [1,2,4,2,1] then 1 comes 2 times, 3 comes 0 times,10 comes 0 times
// so if we have 10^5 numbers and array size 10^5 then it will run for loop 10^10 times because for 1 number it will run 10^5 times so for 10^5 numbers it will run for loop 10^10 times , so it will take time 100sec because 10^8 takes 1 sec so 10^10 will take 100 sec
// so we  use hashing technique to do in faster way
// hashing is used to redue that time otherwise it take 1 and half minute for 100 sec
// hashing - it has a array in which we do precalculation and store the no. of times that number comes in given array so in hash array at index 1 we will store 2 because 1 comes 2 times in the array and at index 2 we will store 2 because 2 comes 2 times in the array and so on

// similarly  we can do in string which also cause time complexity of very high for q character time complexity is O(q*n) where n is size of string so we use character hashing
// string s = "abcdabefc";
// int charCount(char ch, string s)
// {
//   int count = 0;
//   for (int i = 0; i < s.size(); i++)
//   {
//     if (s[i] == ch)
//     {
//       count++;
//     }
//   }
//   return count;
// }

#include <iostream>
using namespace std;
// globally declarartion of array and in this initially garbage value store at every index is zero so you don't have to give zero value
// int arr[1e7]; // 10^7

int main()
{
  // size of array
  // int n;
  // cin >> n;
  // int arr[n];
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> arr[i];
  // }
  // precomputation
  // int hash[1000001]; // 10^6+1 because we have to store 0 to 10^6
  // maximum size goes to 12 means index 0 to index 12
  // but for problem you can go any size
  // int hash[13] = {0}; // 0 to 12
  // for (int i = 0; i < n; i++)
  // {
  //   hash[arr[i]]++; // here we can see arr[i] if gives 1 at index 0 then at index 1 of hash array it give 1 if in arr[i] 1 comes again then at index 1 of hash array it give 2
  //}

  // number of queries
  // int q;
  // cin >> q;
  // while (q--)
  // {
  // number denotes which we want to search
  //   int number;
  //   cin >> number;
  //   // fetching the number of times
  //   cout << hash[number] << endl;
  // }
  // in interger you can declare maximum siz of array is 10^6 so if you store 10^7 then it does not allocate memory but if you declare array of 10^7 globally then it will work

  // in case of boolean array will go upto maximum size of 10^7 and globally it will work upto 10^8

  // similary we can go with character hashing
  // here we discuss for string of lower case letters otherwise total ascii are 256 values so we can also take array of 256 size
  // we know there are total 26 characters in english so in character hashing we can go upto 26 size of array so index 0 denotes for character a, index 1 for b and so on so now question is how to visualize it? we visiualized it by ascii values

  int x = 'a';       // x=97
  int y = 'f' - 'a'; // y=5
  // in ascii  a=97 and z = 122
  // 'a'-'a'=0
  // 'b'-'a'=1
  // so formula is char-'a'
  // take string
  string s;
  cin >> s;
  // precomputation

  // when we does not want any other character and only want lower case then we used size = 26
  int charhash[26] = {0};
  // int charhash[256] = {0};  // in this case no subtraction required 
  for (int i = 0; i < s.size(); i++)
  {
    charhash[s[i] - 'a']++;
  }
  // number of queries
  int q;
  cin >> q;
  while (q--)
  {
    char ch;
    cin >> ch;
    // fetching
    cout << charhash[ch - 'a'] << endl;
  }
// se here we get some conclusion also that in number hashing array can have size of max - 10^7 but in character hashing there is only 256 characters so we can have that much size

// in hashing bracket that is hash[] in this only integer allow so when we give character it will automatically convert in integer


// in number hashing for number greater than 10^7 we use in cpp - map or unorderd map and in java we can use collections by using hash map


  return 0;
}