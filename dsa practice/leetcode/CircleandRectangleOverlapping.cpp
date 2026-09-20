// You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

// Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

// Example 1:

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
// Output: true
// Explanation: Circle and rectangle share the point (1,0).
// Example 2:

// Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
// Output: false
// Example 3:

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
// Output: true

// Constraints:

// 1 <= radius <= 2000
// -10^4 <= xCenter, yCenter <= 10^4
// -10^4 <= x1 < x2 <= 10^4
// -10^4 <= y1 < y2 <= 10^4

#include <bits/stdc++.h>
using namespace std;

// here we have to check whether the given circle and a rectangle overlapped or not

// overlapped means here there exists any point (xi,yi) that belongs to the circle as well as the rectangle at the same time or even touch both means share edge.

// we are given a cirle with its centre (xCenter,yCenter) and its radius r and a rectangle with two coordinates: i) (x1,y1) represents the bottom-left corner and ii) (x2,y2) represents the top-right corner of the rectangle.

// A circle and an axis-aligned rectangle overlap when the shortest distance from the circle's center to any point inside or on the rectangle is less than or equal to the circle's radius.

// Why we say shortest distance is less than or equal to radius? because if distance is less than or equal to radius it means the point is also lie inside or on the circle because we atke distance from circle's center to the pointe that is already inside or on the rectangle now we check that point is inside or on the circle or not so we check the shortest distance is less than or equal to radius or not.

// How to check for overlap

// We can use the closest point method:

// i) Find the closest point: For a circle with center (xCenter,yCenter) and a rectangle with bottom-left(x1,y1) and top-right(x2,y2), find the point on the rectangle closest to the circle's center by clamping(means fasten two things together with a clamp ) the center coordinates:

// for more clearance draw circle and rectangle then compare given points to know how we get closestX and closestY:
// we take min(xCenter,x2) because these coordinates are about to above x1 so we take min and then max with x1 , similarly with y coordinates , understand with diagram
// closestX=max(x1,min(xCenter,x2))
// closestY=max(y1,min(yCenter,y2))

// ii) Calculate the distance: find the distance between the circle' center and the closest point (closestX,closestY)
// we use distance formula between two points:
// distanceX=(xCenter-closestX)
// distanceY=(yCenter-closestY)
// dist= sqrt(((distanceX)^2)+((distanceY)^2))

// iii) Compare with the radius: If the distance dist is less than or equal to the radius, means circle and rectangle are overlapped.

// t.c-O(1)
// s.c-O(1)
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
{
  // i) closest point
  int closestX = max(x1, min(xCenter, x2));
  int closestY = max(y1, min(yCenter, y2));

  // ii) calculate the distance: we can take  absolute or not  because after we also do square so it already become positive
  // horizontal distance
  int distX = abs(xCenter - closestX);
  // vertical distance
  int distY = abs(yCenter - closestY);

  // iii) compare with the radius: dist^2 <= radius^2 , we check with square, so no need of sqrt
  return ((distX * distX) + (distY * distY)) <= (radius * radius);
}

int main()
{
  int radius, xCenter, yCenter;
  cout << "Enter circle: ";
  cin >> radius >> xCenter >> yCenter;
  int x1, y1, x2, y2;
  cout << "Enter rectnagle: ";
  cin >> x1 >> y1 >> x2 >> y2;
  cout << checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2);
  return 0;
}