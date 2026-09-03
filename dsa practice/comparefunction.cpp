// how to compare a 2D array (or vector of vectors) by the second element using a compare function 👍
// This is super common in C++ sorting.

// Case 1: vector<vector<int>>

// Suppose you have this 2D array:

// vector<vector<int>> arr = {
//     {1, 3},
//     {2, 1},
//     {4, 2}
// };

// ✅ Comparator to compare by 2nd element
// bool cmp(vector<int>& a, vector<int>& b) {
//     return a[1] < b[1];   // compare second element
// }

// ✅ Sort call
// sort(arr.begin(), arr.end(), cmp);

// Result after sorting
// {2,1}
// {4,2}
// {1,3}

// Case 2: Using pair<int,int> (better & cleaner)

// If your data is like (id, value) or (x, y) — use pair.

// vector<pair<int,int>> arr = {
//     {1, 3},
//     {2, 1},
//     {4, 2}
// };

// Comparator
// bool cmp(pair<int,int>& a, pair<int,int>& b) {
//     return a.second < b.second;
// }

// Sort
// sort(arr.begin(), arr.end(), cmp);

// Case 3: Using lambda function (short & modern 🔥)

// No need to write a separate function:

// sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
//     return a[1] < b[1];
// });

// or for pair:

// sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
//     return a.second < b.second;
// });

// Important rule for compare function ⚠️

// Must return true if a should come before b

// ❌ Never use <= or >=

// ✔ Correct:

// return a[1] < b[1];

// ❌ Wrong:

// return a[1] <= b[1];

// ❌ Why this error happens

// If your code looks like this:

// class Solution {
// public:
//     bool compare(vector<int>& a, vector<int>& b) {
//         return a[1] < b[1];
//     }

//     void solve(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), compare);
//     }
// };

// 👉 compare belongs to an object of Solution, but std::sort expects a free function or static function.

// That’s why the compiler says:

// reference to non-static member function must be called

// ✅ Fix 1: Make compare static (most common in LeetCode)
// class Solution {
// public:
//     static bool compare(vector<int>& a, vector<int>& b) {
//         return a[1] < b[1];
//     }

//     void solve(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), compare);
//     }
// };

// ✔ Works because static functions don’t need an object

// ✅ Fix 2: Use a lambda function (clean & modern ⭐)
// sort(intervals.begin(), intervals.end(),
//      [](vector<int>& a, vector<int>& b) {
//          return a[1] < b[1];
//      });

// ✔ Best practice
// ✔ No extra function needed
// ✔ Very readable

// ✅ Fix 3: Use a separate compare function (outside class)
// bool compare(vector<int>& a, vector<int>& b) {
//     return a[1] < b[1];
// }

// sort(intervals.begin(), intervals.end(), compare);

// ✔ Works but not preferred in LeetCode-style classes

// 🔑 Quick rule to remember

// std::sort ❌ cannot use non-static member functions
// Use static, lambda, or outside function