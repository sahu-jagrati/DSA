// An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

// Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

// Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

// Example 1:

// Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
// Output: true
// Example 2:

// Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
// Output: false
// Example 3:

// Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
// Output: false

// Constraints:

// rec1.length == 4
// rec2.length == 4
// -10^9 <= rec1[i], rec2[i] <= 10^9
// rec1 and rec2 represent a valid rectangle with a non-zero area.

#include <bits/stdc++.h>
using namespace std;

// here we have to check either given two rectangles are overlap or not

// two rectangles are overlap if they are intersect means having common area and then if area of that part is positive then they are overlap.

// if they only touch at the corner or edges then they do not overlap.

// Now we have to given that bottom-left and top-right coordinates of two rectangles.

// we have to check either they overlap or not

// so easiest way is to check whether they overlap on both the X-axis and Y-axis  means for overlapping/intersecting they have to overlap both from X-axis and Y-axis.

// Suppose:
// Rectangle1:
// bottom-left=(x1,y1)
// top-right=(x2,y2)

// Rectangle2:
// bottom-left=(x3,y3)
// top-right=(x4,y4)

// as coordinates given are bottom-left and top-right so
// assuming x1<x2, y1<y2, x3<x4, y3<y4  because bottom-left and top-right are diagonal points

// First we check X-axis overlap:
// The rectangles overlap horizontally if:
//  x1<x4 && x3<x2

// Why?
// R1 occupies [x1,x2]
// R2 occupies [x3,x4]

// If: x2<=x3
// then R1 is completely to the left of R2 -> no intersection.

// If x4<=x1
// then R2 is completely to the left of R1 -> no intersection.

// So horizontal overlap requires:
// x1<x4 && x3<x2

// Check Y-axis overlap
// Similarly, the rectangles overlap vertically if:
// y1< y4 && y3<y2

// If:
// y2<=y3
// R1 is completely below R2.

// If:
// y4<=y1
// R2 is completely below R1.

// So vertical overlap requires:
// y1<y4 && y3<y2

// Therefore, the rectangles have a positive-area intersection if:
// bool intersect- (x1<x4&&x3<x2)&&(y1<y4&&y3<y2)

// and common region is: (x3,y3) to (x2,y2)
// so the intersection area is : (x2-x3)*(y2-y3)

// Example:
// R1:
// BL=(1,1)
// TR=(5,5)

// R2:
// BL=(3,3)
// TR=(7,6)

// X-axis: 1<7 && 3<5
// Y-axis: 1<6 && 3<5
// Therefore, they intersect.

// The common region is :
// (3,3) to (5,5)
// so the intersection area is:
// (5-3)*(5-3)=4

// Important thing:
// If the rectangles just touch at an edge or corner, for example:
// R1: (1,1)->(3,3)
// R2: (3,1)->(5,3)
// then they have no positive-area intersection

// positive means > 0 not even  equal to 0

// that's why we use < rather than <=

// t.c-O(4)=O(1)
// s.c-O(1)
bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
  // we get coordinates of both rectangles
  int x1 = rec1[0];
  int y1 = rec1[1];
  int x2 = rec1[2];
  int y2 = rec1[3];
  int x3 = rec2[0];
  int y3 = rec2[1];
  int x4 = rec2[2];
  int y4 = rec2[3];
  // check either they intersect or not
  if ((x1 < x4 && x3 < x2) && (y1 < y4 && y3 < y2))
  {

    long long length = x2 - x3;
    long long height = y2 - y3;
    // common region area
    long long intersectingArea = length * height;
    // check area is positive or not
    if (intersectingArea > 0)
      return true;
  }
  // otherwise return false
  return false;
}

int main()
{
  vector<int> rec1(4);
  vector<int> rec2(4);
  for (int i = 0; i < 4; i++)
  {
    cin >> rec1[i];
  }
  for (int i = 0; i < 4; i++)
  {
    cin >> rec2[i];
  }
  cout << isRectangleOverlap(rec1, rec2);
  return 0;
}