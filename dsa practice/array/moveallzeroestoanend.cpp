
#include <iostream>
#include <vector>
using namespace std;

//  brute approach- time complexity is O(n+sizeoftemp+n-sizeoftemp)=O(2n) and space complexity is O(sizeoftemp) which is in worst case can be equal to O(n)
// void moveAllZeroesToAnEnd(vector<int> &arr, int n)
// {
//   vector<int> temp;
//   for (int i = 0; i < n; i++)
//   {
//     if (arr[i] != 0)
//     {
//       temp.push_back(arr[i]);
//     }
//   }
//   int sizeOfTemp = temp.size();
//   for (int i = 0; i < sizeOfTemp; i++)
//   {
//     arr[i] = temp[i];
//   }
//   for (int i = sizeOfTemp; i < n; i++)
//   {
//     arr[i] = 0;
//   }
// }

// optimal approach- time copmlexity is if we find j at index x then O(x+n-x-1)=O(n+1) and space complexity is O(1)
vector<int> moveZeroes(vector<int> arr, int n)
{
  int j = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
  {
    return arr;
  }
  // we start i =j+1 because we know at j we have arr[j]=0 so we want non-zero elt from where i can swap
  for (int i = j + 1; i < n; i++)
  {
    if (arr[i] != 0)
    {
      // we can directly use swap(arr[i],arr[j]); // that is swap non-zero elt with zero elt
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j++;
    }
  }
  return arr;
}
int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // moveAllZeroesToAnEnd(arr, n);
  vector<int> result = moveZeroes(arr, n);
  for (int i : result)
  {
    cout << i << " ";
  }
  return 0;
}

// when void function void moveZeroes(vector<int>& nums) {
//    void moveZeroes(vector<int>& nums) {

//     int j=-1;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==0){
//             j=i;
//             break;
//         }
//     }
//     if(j!=-1){
//     for(int i=j+1;i<nums.size();i++){
//         if(nums[i]!=0){
//             swap(nums[i],nums[j]);
//             j++;
//         }
//     }
//     }
// }

// more easy chatgpt solution-
void movezeroes(vector<int> &arr)
{
  int j = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}