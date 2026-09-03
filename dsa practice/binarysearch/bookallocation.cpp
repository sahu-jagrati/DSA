// that array represnts no.of pages in books like 0th index has 25 pages in 1st book, index 1 has 46 pages in 2nd book and so on, I have to distribut these books to student
// condition-
// each student get atleast one book
// each book should be allocated to only one student
// book allocation should be in contiguous manner
// so you have to allocate books to 'm' student such that the maximium number of pages assigned to a student is minimum
// if the allocation of books is not possible return -1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numberOfStudents(vector<int> &arr, int pages)
{
  int n = arr.size();
  int countStudent = 1;
  long long pagesStudent = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] + pagesStudent <= pages)
      pagesStudent += arr[i];
    else
    {
      countStudent += 1;
      pagesStudent = arr[i];
    }
  }
  return countStudent;
}
// brute-linear search- we have answer range -[max(arr) to sum(arr)], thinking of range is in notes and also you can think of it
// time complexity-O(sum-maxi+1)*O(n)+O(n)(for sum loop)
int bookAllocation(vector<int> &arr, int student)
{
  int n = arr.size();
  // edge case
  if (student > n)
    return -1;
  int maxi = *max_element(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  for (int i = maxi; i <= sum; i++)
  {
    int numberOfstudent = numberOfStudents(arr, i);
    if (numberOfstudent == student)
      return i;
  }
}

// optimize- binary search-why?
// we have to find maximum-minimum
// we have range of answer
// we can do elimination
// time complexity-O(log (sum-maxi+1)(base 2))*O(n)+O(n)(for sum loop)
int BookAllocation(vector<int> &arr, int student)
{
  int n = arr.size();
  if (student > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  int high = sum;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (numberOfStudents(arr, mid) > student)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low; // because low go from non-possible to possible polarity
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
  int student;
  cin >> student;
  // int result = bookAllocation(arr, student);
  int result = BookAllocation(arr, student);
  cout << result << endl;
  return 0;
}