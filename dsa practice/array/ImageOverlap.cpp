// You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

// We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

// Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

// Return the largest possible overlap.

// Example 1:

// Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
// Output: 3
// Explanation: We translate img1 to right by 1 unit and down by 1 unit.

// The number of positions that have a 1 in both images is 3 (shown in red).

// Example 2:

// Input: img1 = [[1]], img2 = [[1]]
// Output: 1
// Example 3:

// Input: img1 = [[0]], img2 = [[0]]
// Output: 0

// Constraints:

// n == img1.length == img1[i].length
// n == img2.length == img2[i].length
// 1 <= n <= 30
// img1[i][j] is either 0 or 1.
// img2[i][j] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;

// first we understand the question : What it want to say?

// here questions is asking to move one binary matrix over the other without rotating it and find the position where the maximum number of 1's overlap.

// What does "Translate" mean?
// Suppose:
// img1:
// 1 1 0
// 0 1 0
// 0 1 0

// We are allowed to move the whole image:
// left
// right
// up
// down
// or diagonally, e.g right+down or right+up or left+up or left+down

// But you cannot rotate it.
// For example, moving img1 right by 1 means every 1 moves one column right.

// i.e Column0 move to colum1 , column1 move to column2 and column2 disappears because it go outside the matrix so it disappears, here column2 not go to column0 because we cannot rotate it so column2 disappears and column0 have all value = 0 because there is nothing.

// WHat is overlap?
// AFter moving img1, put it on top of img2.
// At every position, check: img1=1 and img2=1
// if both are 1, that's one overlap.

// For example:
// img1:     1 1 0
//           0 1 0
//           0 1 0

// img2:     0 0 0
//           0 1 1
//           0 0 1

// If we shift img1 right by 1 then we get:
// 0 1 1
// 0 0 1
// 0 0 1
// then down by 1 means row0 move to row1, row1 move to row2, row2 disappear and then row0=0
// so we get
// 0 0 0
// 0 1 1
// 0 0 1

// now we check shifted img1 with img2 where we get overlap 1
// shifted img1:  0 0 0
//                0 1 1
//                0 0 1

// img2:          0 0 0
//                0 1 1
//                0 0 1

// Every 1 overlaps.
// So overlap=3
// Therefore answer=3

// What exactly do we need to find?
// We need to try different transaltions of one matrix and calculate the overlap of each transaltion.
// Means in above example we first do translation by shift img1 right by 1 so here we do one transalation so after that we have to check how many 1's are overlap and compare it each time to get maximum number of overlap 1's

// then we do translation in img1 by down by 1 then we againg check overlap 1's and compare it with previous getting overlap 1's so we get maximum overlap 1's

// for example:
// move right 1 - overlap=2
// move right 2 - overlap=1
// move left 1 - overlap=0
// move down 1 - overlap=1
// move right 1 + down 1 - overlap=3
// ...
// then returns the maximum so here if we check we get max overlap=3

// So the main idea is:
// Try every possible position of img1, count how many 1's match with img2, and return the maximum count.

// Important: We don't actually need to move the matrix
// We don't necessarily have to physically create a shifted matrix.

// We can think of a transaltion as a pair:
// (row shift, column shift)

// for example:
// (1,1)
// means:
// move down by 1 means row shift
// move right by 1 means column shift
// Then compare the corresponding cells.

// What are the possible shifts?
// Since the matrix is n*n, the useful shifts are:
// row shift:  -(n-1)...0...+(n-1)
// column shift: -(n-1)...0...+(n-1)

// For n=3:
// row shift: -2,-1,0,1,2
// column shift: -2,-1,0,1,2

// i.e for n=3
// i)  either we don't shift row and column both means (0,0) and simply comapre img1 with img2
// ii) or we shift row by 1 down and don't shift column means (1,0)
// iii) or we shift row by 1 up and don't shift column means (-1,0) why -1 because when we shift row0 up then it go out of matrix row-1
// iv) or we shift column by 1 right and don't shift row then (0,1)
// v) or we shift column right by 2 and don't shift row then (0,2)
// and so on trnasitions

// so there are total 5*5=25 possible transitions for above example when n=3

// and after every transition we calculate the overlap and keep the largest

// so what we have to do: move img1 in every possible direction, compare it with img2, count positions where both contain 1 , and return the maximum count.

// here You might have a question that : Should we try to make img1 equal to img2 or img2 equal to img1?
// No, we don't need to convert img1 into exactly img2 or vice-versa.  We simply transalte(shift) one image relative to the other and count how many 1's overlap.

// i.e  we are trying to get one possible structure of img1 which when we compare with img2 we get maximum number of overlap 1's by shifting img1 and keep img2 fixed or we do vice-versa fixed img1 and try to shift img2 to get maximum count of overlap 1's

// We can choose either:
// keep img2 fixed and shift img1, or
// keep img1 fixed and shift img2.

// Both approaches give the same maximum answer.

// Important point:
// We are not trying to make the entire img1 equal to img2.
// We are asking:
// If I slide one image around, what is the maximum number of positions where both images have 1?
// so there may be cases where we get maximum count of overlap 1's when img1==img2 but not always that maximum number of overlap 1's when img1=img2 , there can be a case when we get maximum number of overlap 1's when img1 != img2

// Overlap- does not mean the two images are completely equal.
// It means : At a particular position, if both images have 1 in the same cell, that is one overlap.

// For example:
// img1:       1 1 0
//             0 1 0
//             0 1 0

// img2:       0 1 1
//             0 1 0
//             1 0 0

// if we compare here cell by cell:
// we get 2 overlapping 1's - i) at (1,1) ii) at (0,1)
// The matrices are clearly not equal, but the overlap is still 2.

// Think of it as img1 may be equal img2 when we get maximum number of overlap 1's or may not be equal , we only want maximum number of overlap 1's

// Think of it as AND
// At each position:
// img1=1
// img2=1
// means:
// 1 AND 1= 1 count it
// But:
// 1 AND 0 = 0
// 0 AND 1 = 0
// 0 AND 0 = 0
// don't count.

// In this problem
// We shift img1 in differnet ways and ask each time:
// How many (1,1) positions do I get after each shift?
// Then take the maximum.

// SO even if the two images aren't completely equal, we can have a large overlap.

// In the example, after shifting:
// shifted img1:    0 0 0
//                  0 1 1
//                  0 0 1

// img2:            0 0 0
//                  0 1 1
//                  0 0 1
// they happen to become equal, so overlap=3.
// But equality is not required to have overlap.

// So The approach is:
// here we keep img2 fixed, shift img1 in every possible direction, and count the overlapping 1's.

// What are we going to try?
// Suppose n=3:
// We can shift img1:
// row shift: -2,-1,0,1,2
// column shift: -2,-1,0,1,2

// here we don't apply operation/translation on cells, we apply operations/translation on row and column

// A pair (dr,dc) represents one translation.
// For example:
// (dr=1,dc=1)
// means:
// down 1
// right 1

// SO we will use two loops:
// for having each row shift with each column shift and check overlap 1's for each translation

// for(int dr=-(n-1);dr<=(n-1);dr++){
// for(int dc=-(n-1);dc<=(n-1);dc++){
// we try every possible translation
// calculate overlap for this shift
//}}

// How do we calculate overlap for one shift?
// This is the most important part:
// Suppose:

// img1:

// 1 1 0
// 0 1 0
// 0 1 0

// and:

// img2:

// 0 0 0
// 0 1 1
// 0 0 1

// Let's say: dr=1, dc=1
// meaning move img1 down 1 and right 1.

// Instead of actually creating a new matrix, we can calculate where each img1[i][j] goes.

// Original position: (i,j)
// After shifting: (i+dr,j+dc)
// So:
// newRow=i+dr
// newCol=j+dc

// Example of the coordinates
// The 1's in img1 are at:
// (0,0)
// (0,1)
// (1,1)
// (2,1)
// For: dr=1 and dc=1
// they become:
// (0,0) → (1,1)
// (0,1) → (1,2)
// (1,1) → (2,2)
// (2,1) → (3,2)
// But: (3,2) is outside the matrix because valid row indices are: 0,1,2
// so that 1 disappears.

// Now check overlap
// For every 1 in img1, we check the new position in img2 because we do translation in img1 so we get new position of 1 in img1 so we compare new position of img1 in img2

// For example:
// img1[0][0]=1
// After shifting:
// it becomes (0,0)->(1,1)
// so now we check img2[1][1]
// if it's 1
// Therefore:
// overlap++
// Next: img1[0][1]=1
// moves to (1,2)
// check: img2[1][2]
// it's 1
// so: overlap++
// Next:
// img1[1][1] = 1
// moves to:
// (2,2)
// img2[2][2] = 1.
// So:
// overlap++
// Thus:
// overlap = 3

// This we get on translation (dr,dc)=(1,1) means moving img1 down1 and right1 , similarly we do each translation and get maximum overlap

// We are NOT doing:

// img1 == img2

// We're doing:

// img1's shifted 1
//         ↓
// Does img2 have 1 at the same position?
//         ↓
// Yes → overlap++

// So the core condition is:

// img1[i][j] == 1 && img2[newRow][newCol] == 1

// That's the heart of this problem.

// t.c-
// (2n-1)*(2n-1) translations, and for each translation we check n^2 cells.
// so time . c- O(n^4)
// s.c-O(1)
// since n<=30 so this is completely fine.
int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
{
  int n = img1.size(); // both img1 and img2 are n*n
  int ans = 0;         // maximum overlap 1's
  // try every row shift
  for (int dr = -(n - 1); dr <= (n - 1); dr++)
  {
    // try every column shift
    for (int dc = -(n - 1); dc <= (n - 1); dc++)
    {
      // for every pair of (dr,dc) we calculate total overlap and comapre it with ans to get maximum overlap 1's
      int overlap = 0; // for current pair of(dr,dc)
      // check every cell of img1 having img1[i][j]==1
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          // if it is 1
          // we check only for 1 because we want only overlap 1's
          if (img1[i][j] == 1)
          {
            // then new position for that cell after translation
            int newRow = i + dr;
            int newCol = j + dc;
            // check if translated position is inside matrix or not i.e valid or not
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n)
            {
              // then check that newposition in img2 has 1 or not, if it is then there is overlap
              if (img2[newRow][newCol] == 1)
              {
                overlap++;
              }
            }
          }
        }
      }
      // now after go with each 1 in img1 for current pair of (dr,dc) then we compare overlap
      ans = max(ans, overlap);
    }
  }
  return ans; // maximum overlap 1's
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> img1(n, vector<int>(n));
  vector<vector<int>> img2(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> img1[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> img2[i][j];
    }
  }
  cout << largestOverlap(img1, img2);
  return 0;
}