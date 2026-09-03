// You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

// The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

// Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.

// Example 1:

// Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
// Output: [3,3,4]
// Explanation:
// - 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
// - 2nd query updates s = "bbbccc".
//   The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
// - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
// Thus, we return [3,3,4].
// Example 2:

// Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
// Output: [2,3]
// Explanation:
// - 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
// - 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
// Thus, we return [2,3].

// Constraints:

// 1 <= s.length <= 10^5
// s consists of lowercase English letters.
// k == queryCharacters.length == queryIndices.length
// 1 <= k <= 10^5
// queryCharacters consists of lowercase English letters.
// 0 <= queryIndices[i] < s.length

// Hint 1
// Use a segment tree to perform fast point updates and range queries.
// Hint 2
// We need each segment tree node to store the length of the longest substring of that segment consisting of only 1 repeating character.
// Hint 3
// We will also have each segment tree node store the leftmost and rightmost character of the segment, the max length of a prefix substring consisting of only 1 repeating character, and the max length of a suffix substring consisting of only 1 repeating character.
// Hint 4
// Use this information to properly merge the two segment tree nodes together.

#include <bits/stdc++.h>
using namespace std;

// 1. What makes this problem difficult?
// Suppose : s="babacc"
// After every update, we need: the longest consecutive sequence of the same character.
// for example: bbbacc,  answer=3

// A simple approach would be:
// for every query:
// update s
// scan the entire string
// find longest same character substring
// but n<=10^5
// k<=10^5
// so in worst case : 10^5 queries*10^6 string scan=10^10 operations
// too slow

// so here we use Segment Tree

// 2.  First Undersatnd what a segment tree does

// A segment tree divides an array into ranges.
// for example:
// s="babacc"
// index:  0   1   2  3  4  5
//         b   a   b  a  c  c
// we can divide it like:

// by index
//          [0...5]
//         /       \
        //     [0...2]     [3...5]
//     /   \       /    \
        //  [0...1] [2]  [3...4] [5]

// each node represents a range.
// for example:
// [0..2]="bab"
// [3..5]="acc"

// The important idea is:

// Instead of recalculating the whole string after every update, we update only the nodes whose ranges contain the changed index.

// That's only O(log n) nodes.

// 3.  But what should each node store?

// Imagine a segment:"aaabbba"
// We want to know the longest repeating substring.
// for this segment:
// answer is 3 , substring can be "aaa" or "bbb"

// But when we combine two segments, knowing only their answers isn't enough.
// consider:
// left="aaa"
// right="aa"
// left's answer=3
// right's answer=2
// but combined: "aaaaa"
// answer:5  ,so we need some additional information

// 4.  Information stored in every node

// For every segment, we will store 5 things:
// struct Node{
// int len;  // length of this segemnt
// char leftChar;  // first character
// char rightChar; //  last character

// int prefix;  // longest same character prefix length
// in suffix; // longest same character suffix length

// int best;  longest same character substring anywhere
//};

// let's understand each one.

// leftChar:  first character of the segment
// for: "aaabbc"
// we have: leftChar='a'

// rightChar:  last character of the segment
// for: "aaabbc"
// we have: rightChar='c'

// prefix:
// longest repeating substring starting from the left boundary
// for: "aaabbc"
// we have: "aaa"
// therefore: prefix=3

// suffix:
// longest repeating substring ending at the right boundary
// for: "aaabbc"
// we have only: 'c'
// so suffix=1

// best:
// longest repeating substring anywhere.
// for: "aaabbc"
// it's: "aaa"
// therefor: best=3

// 5. Why do we need prefix and suffix?
// this is the trickiest part.

// Suppose:
// left="aaab"
// right="bbbc"

// we have:
// left: aaab
// right: bbbc

// The left segment's suffix is: b
// and right segment's prefix is: bbb
// when we combine them: aaabbbbc
// we get: 1+3=4
// so the answer can cross the boundary.
// that's why we need:
// left.suffix
// right.prefix

// 6. How do we merge two nodes?
// this is the heart of the problem.

// suppose we have:
// L=left node
// R=right node

// we want to construct:
// parent=merge(L,R)

// Step 1: Basic Information

// Length:
// parent.len=L.len+R.len;

// First character:
// parent.leftChar=L.leftChar;

// Last character:
// parent.rightChar=R.rightChar;

// 7.  Calculate best

// initially:
// parent.best=max(L.best,R.best)
// because the best answer could already be completely inside either half.

// But there is one more possibility:
// L.suffix+R.prefix;

// this happens when:
// L.rightChar==R.leftChar

// example:
// L="aaab"
// R="bbbc"
// L.suffix=1
// R.prefix=3
// combined=4

// therefore:
// if(L.rightChar==R.leftChar){
// parent.best=max(parent.best,L.suffix+R.prefix);
//}

// 8.  Calculate prefix

// Normally:
// parent.prefix=L.prefix;

// because the prefix of the entire segment starts in the left segemnt.

// but there is a special case.
// suppose:
// L="aaa"
// R="aabb"

// then: L=aaa
// R=aabb
// Entire combined string: aaaaa bb
// The prefix becomes:
// L.len+R.prefix=3+2=5
// this happens when: L.prefix==L.len
// means : The entire left segment consists of one character.
// And: L.rightChar==R.leftChar
// So:
// if(L.rightChar==R.leftChar&&L.prefix==L.len){
// parent.prefix=L.len+R.prefix;
//}
// else{
// parent.prefix=L.prefix
//}

// 9. Calculate suffix:

// Symmetric Logic.
// Normally:
// parent.suffix=R.suffix;
// But if the entire right segment consists of one characterand it matches the left suffix.

// if(L.rightChar==R.leftChar&&R.suffix==R.len){
// parent.suffix=R.len+L.suffix;
//}
// else{
// parent.suffix=R.suffix;
//}

// 10. Let's manually merge "aaa" and "aabb"

// Left: aaa
// Node:
// len=3
// leftChar=a
// rightChar=a
// prefix=3
// suffix=3
// best=3

// Right: aabb
// Node:
// len=2
// leftChar=a
// rightChar=b
// prefix=2
// suffix=2
// best=2

// Now:
// L.rightChar==R.leftChar
// a==a
// So they connect.
// best=max(3,2,3+2)=5

// prefix
// Entire left is a:
// L.prefix=L.len -> 3==3
// therfore:
// prefix=3+2=5

// suffix:
// right doesn't consist entirely of one character:
// R.suffix!=R.len
// therefore:
// suffix=2

// result: "aaaaa bb"
// Node:
// len=7
// prefix=5
// suffix=2
// best=5
// correct.

// 11.  Now let's build the segment tree
// We need a tree like:
//        [0,5]
//       /     \
          //    [0,2]   [3,5]
//    /  \     /  \
          // [0,1] [2] [3,4] [5]

// At a leaf, there is only one character.
// for example:
// 'b'
// Its node is:
// len=1
// leftChar='b'
// rightChar='b'
// prefix=1
// suffix=1
// best=1
// so building the tree is straightforward.

// Now we write complete solution:

// building the tree: O(n)
// each update: O(logn) because either we fo left side or right side so we don't travel whole
// there are k updates: O(klogn)
// total t.c-O(n+klogn)
// s.c-O(n) for tree+O(k)(for ans array which is required)

class Solution
{
public:
  // what node store
  struct Node
  {
    int len;        // length of this segment
    char leftChar;  // first character of the segment
    char rightChar; // last character of the segment

    // Longest repeating substring starting from the left boundary
    int prefix; // longest same-character prefix

    // Longest repeating substring ending at the right boundary.
    int suffix; // longest same-character suffix

    int best; // longest same-character substring anywhere in the entire string
  };
  vector<Node> tree;

  Node merge(Node L, Node R)
  {         // L for left node and R for right node
    Node P; // parent node
    // L and R are left and right node

    P.len = L.len + R.len;

    P.leftChar = L.leftChar;
    P.rightChar = R.rightChar;

    // initially, prefix and suffix
    P.prefix = L.prefix;
    P.suffix = R.suffix;

    // Best is atleast the best of either side
    P.best = max(L.best, R.best);

    // Can the two parts join?
    if (L.rightChar == R.leftChar)
    {
      // longest substring crossing the boundary
      P.best = max(P.best, L.suffix + R.prefix);

      // prefix can extend into R
      if (L.prefix == L.len)
      {
        P.prefix = L.len + R.prefix;
      }
      // suffix can extend into L
      if (R.suffix == R.len)
      {
        P.suffix = L.suffix + R.len;
      }
    }
    return P; // parent node after merge
  }

  // build the tree
  //   When we see:

  // build(s, node, l, r)

  // think:

  // "I am currently at tree node node, and this node represents the range [l,r]."
  void build(string &s, int node, int l, int r)
  {
    // leaf node base case, At a leaf, there is only one character.
    if (l == r)
    {
      tree[node] = {1, s[l], s[l], 1, 1, 1};
      return;
    }
    // when it is not a leaf node
    int mid = l + (r - l) / 2;
    // left subtree
    build(s, 2 * node, l, mid);
    // right subtree
    build(s, 2 * node + 1, mid + 1, r);
    // merge left node and right node
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  // update the string for query
  // node denotes the range where the query index lie
  // index is the index of string that has to be changed with ch

  void update(int node, int l, int r, int index, char ch)
  {
    // found the character
    if (l == r)
    {
      tree[node] = {1, ch, ch, 1, 1, 1}; // we put the s[l]=ch here i.e update the string
      return;
    }
    // if not found
    int mid = l + (r - l) / 2;
    // if the index that we want to change its value with new ch lie in left subtree
    if (index <= mid)
    {
      update(2 * node, l, mid, index, ch);
    }
    // if the index that we want to change its value with new ch lie in right subtree
    else
    {
      update(2 * node + 1, mid + 1, r, index, ch);
    }
    // recalculate current node after update
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
  }

  // main function
  // left child=2*node
  // right child=2*node+1
  vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
  {
    int n = s.size();
    // because we can store the entire tree inside a normal array/vector
    // tree[1]=root
    // tree[2]=left child of root
    // tree[3]=right child of root
    //     Why don't we pass node = 0?

    // We could, but the standard implementation starts from 1.

    // Because with 1-based indexing:

    // left child  = 2 * node
    // right child = 2 * node + 1
    // If we started with 0, we'd have to use a different indexing formula.

    tree.resize(4 * n);
    // build the tree
    // node =1 is just the root of the segment tree
    // 1 means : Start building from the root of the segment tree.
    // 0 : left boundary
    // n-1 : right boundary
    // s: original string
    build(s, 1, 0, n - 1); // it means:"Start at the root node (1), which represents the entire array (0 to n-1)."
    vector<int> ans;
    // go for every query
    for (int i = 0; i < queryCharacters.size(); i++)
    {
      // index where we want change
      int index = queryIndices[i];
      // change with this char
      char ch = queryCharacters[i];
      // update the string with ch char at index
      // in update node=1 means "Start searching for index 1 from the root". root represents the whole string
      update(1, 0, n - 1, index, ch); // means: "Start from the root and travel down the tree to find the node representing index." So 1 is not the array index and it is not the character index.// It's simply the index of the root node inside the tree vector.
      ans.push_back(tree[1].best);    // after each update best answer store at root. Why tree[1].best gives the answer? because the root represents the entire string : [0...n-1]
    }
    return ans;
  }
};

int main()
{
  string s;
  cin >> s;
  string queryCharacters;
  cin >> queryCharacters;
  int k;
  cin >> k;
  vector<int> queryIndices(k);
  for (int i = 0; i < k; i++)
  {
    cin >> queryIndices[i];
  }
  Solution sol;
  vector<int> ans = sol.longestRepeating(s, queryCharacters, queryIndices);

  for (int x : ans)
  {
    cout << x << " ";
  }
  return 0;
}

// Let's understand update() carefully

// This is where segment trees become useful.

// Suppose:

// s = "babacc"

// and we update:

// index = 1
// 'b'

// So:

// babacc
//  ^

// becomes:

// bbbacc

// We don't rebuild the entire tree.

// We start at:

// [0,5]

// Index 1 lies in:

// [0,2]

// So go there.

// Then:

// [0,2]

// Index 1 lies in:

// [0,1]

// Then:

// [0,1]

// Index 1 lies in:

// [1,1]

// Update that leaf.

// Then we go back upward and merge:

// [1,1]
//    ↓
// [0,1]
//    ↓
// [0,2]
//    ↓
// [0,5]

// Only O(log n) nodes are changed.

// 14. Why tree[1].best gives the answer

// The root represents the entire string:

// [0 ... n-1]

// And its:

// best

// means:

// Longest repeating-character substring anywhere in the entire string.

// Therefore after every update:

// ans.push_back(tree[1].best);

// That's all we need.

// 15. Walk through Example 1

// Initial:

// s = "babacc"

// Query 1:

// index = 1
// character = b

// String becomes:

// bbbacc

// Segment tree root calculates:

// best = 3

// Answer:

// [3]

// Query 2:

// index = 3
// character = c

// String:

// bbbccc

// There are two longest groups:

// bbb
// ccc

// So:

// best = 3

// Answer:

// [3, 3]

// Query 3:

// index = 3
// character = b

// String:

// bbbbcc

// Now:

// bbbb

// So:

// best = 4

// Final:

// [3,3,4]
// 16. The most important segment-tree concept here

// Don't memorize the code.

// Understand this pattern:

// Every node stores enough information to describe its range.

// Here:

// Node
//  ├── leftChar
//  ├── rightChar
//  ├── prefix
//  ├── suffix
//  └── best

// Then:

// parent = merge(leftChild, rightChild)

// This is the fundamental idea of many segment-tree problems.

// 17. Why can't we store only best?

// This is a very important interview question.

// Suppose:

// left  = "aaab"
// right = "bbbc"

// If we only know:

// left.best = 3
// right.best = 3

// then we'd calculate:

// max(3,3) = 3

// But the actual answer is:

// aaabbbbc
//    ^^^^

// which is:

// 4

// To calculate that 4, we need:

// left.suffix = 1
// right.prefix = 3

// Therefore:

// crossing answer =
// left.suffix + right.prefix

// That's exactly why the node stores prefix and suffix.

// node = 1 is just the root of the segment tree

// When we write:

// build(s, 1, 0, n - 1);

// the arguments are:

// build(
//     s,          // original string
//     1,          // node number
//     0,          // left boundary
//     n-1         // right boundary
// )

// The 1 means:

// "Start building from the root of the segment tree."

// Think of the tree like this:

//                     node 1
//                   [0 ........ 5]
//                  /              \
//               node 2            node 3
//              [0..2]            [3..5]
//             /     \            /    \
//         node 4   node 5     node 6  node 7
//         [0..1]    [2]       [3..4]   [5]

// So:

// node = 1

// is simply a label/number assigned to the root.

// 2. Why do we number the nodes?

// Because we can store the entire tree inside a normal array/vector.

// For example:

// vector<Node> tree(4 * n);

// Then:

// tree[1] → root
// tree[2] → left child of root
// tree[3] → right child of root

// And the children follow a very useful rule:

// left child  = 2 * node
// right child = 2 * node + 1

// So if:

// node = 1

// then:

// left child  = 2 * 1     = 2
// right child = 2 * 1 + 1 = 3

// Therefore:

//              1
//            /   \
//           2     3
//         /  \   /  \
//        4    5 6    7

// This is why you see:

// tree[2 * node]
// tree[2 * node + 1]

// in the code.

// 3. Why does build() start with node 1?

// Suppose:

// string s = "babacc";

// We call:

// build(s, 1, 0, 5);

// This means:

// Build the segment tree for the entire range [0,5] and store this range at tree[1].

// So:

// tree[1]
//    ↓
// [0 ........ 5]

// Then build() splits it:

// int mid = (0 + 5) / 2;

// So:

// [0........5]
//      ↓
// [0..2] [3..5]

// and calls:

// build(s, 2, 0, 2);
// build(s, 3, 3, 5);

// Notice:

// 1 → [0..5]
// 2 → [0..2]
// 3 → [3..5]

// Then node 2 splits:

// build(s, 4, 0, 1);
// build(s, 5, 2, 2);

// So:

//                     1 [0..5]
//                    /        \
//              2 [0..2]      3 [3..5]
//               /    \         /    \
//          4 [0..1] 5 [2]  6 [3..4] 7 [5]
// 4. Then why does update() also start with node = 1?

// This is a really good question.

// Suppose we want to update:

// index = 1

// We call:

// update(1, 0, 5, 1, 'b');

// The first 1 means:

// Start searching for index 1 from the root.

// Remember, the root represents the whole string:

// node 1
// [0........5]

// We don't know where index 1 is yet.

// So we start at the root and move down.

// Step-by-step

// We're at:

// node 1 → [0..5]

// Middle:

// mid = 2

// Index 1 is:

// 1 <= 2

// Therefore go left:

// node 2 → [0..2]

// Then:

// [0..2]
// mid = 1

// Index 1 is:

// 1 <= 1

// Go left:

// node 4 → [0..1]

// Again:

// [0..1]
// mid = 0

// Index 1 is:

// 1 > 0

// Go right:

// node 5 → [1..1]

// Now:

// l == r

// We've found the exact position.

// node 5
// [1]

// Update that node.

// 5. Think of node as "where am I in the tree?"

// This is probably the easiest way to remember it.

// When you see:

// build(s, node, l, r)

// think:

// "I am currently at tree node node, and this node represents the range [l,r]."

// For example:

// build(s, 1, 0, 5)

// node = 1
// range = [0,5]

// Then:

// build(s, 2, 0, 2)

// node = 2
// range = [0,2]

// Then:

// build(s, 4, 0, 1)

// node = 4
// range = [0,1]
// 6. Why don't we pass node = 0?

// We could, but the standard implementation starts from 1.

// Because with 1-based indexing:

// left child  = 2 * node
// right child = 2 * node + 1

// This gives:

//         1
//        / \
//       2   3
//      / \ / \
//     4  5 6  7

// Very convenient.

// If we started with 0, we'd have to use a different indexing formula.

// 7. One more important distinction

// Don't confuse:

// node

// with:

// l, r

// They represent two different things.

// node

// Tells us where this segment is stored in the tree array.

// node = 4

// means:

// tree[4]
// l, r

// Tell us which part of the original string this node represents.

// For example:

// node = 4
// l = 0
// r = 1

// means:

// tree[4] represents s[0..1]

// So:

//              node
//               ↓
//         tree[4]
//           ↓
//        [0....1]
//         ↑    ↑
//         l    r
// 8. In one sentence

// When you see:

// build(s, 1, 0, n-1);

// it means:

// "Start at the root node (1), which represents the entire array (0 to n-1)."

// And:

// update(1, 0, n-1, idx, c);

// means:

// "Start from the root and travel down the tree to find the node representing idx."

// So 1 is not the array index and it is not the character index.

// It's simply the index of the root node inside the tree vector.