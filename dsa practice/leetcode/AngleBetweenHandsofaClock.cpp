// Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

// Answers within 10-5 of the actual value will be accepted as correct.

// Example 1:

// Input: hour = 12, minutes = 30
// Output: 165
// Example 2:

// Input: hour = 3, minutes = 30
// Output: 75
// Example 3:

// Input: hour = 3, minutes = 15
// Output: 7.5

// Constraints:

// 1 <= hour <= 12
// 0 <= minutes <= 59

#include <bits/stdc++.h>
using namespace std;

// there is 6 degrees in 1 minute
// Minute hand's angle with respect to the line at 12 o'clock is: Angle(minutes)= (6 degree * Number of minutes)

// Hour hand's angle with respect to the line at 12 o'clock is: Angle(hours)= (30 degree * Number of hours)+(0.5 * Number of minutes)

// The first angle between the clock hands(i.e hoursand minute hands )is: abs(Angle(hours)-Angle(minutes))=abs(30*number of hours - 5.5*number of minutes)

// The second angle between the clock hands is: 360 degree - First angle

// Step-by-Step Method:
// Minute Hand Angle: Multiply the minutes by 6 degree (since 360 degree / 60 min = 6 degree per minute)

// Hour Hand Angle: Multiply the hours by 30 degree(since 360 degree / 12 hrs= 30 degree per hour), and add 0.5 degree for every minute that has passed means like time is 4hr30minutes so for 4hr it is 30 degree/hr means 4*30=120 now we have extra 30 minutes also so for that in one hour it is 30 degree and in 1 hr we have 60 minutes so in 1 minute we have 30/60=0.5 so for 30 minutes we have 0.5*30=15 so total is 120+15=135 degree

// Difference: Subtract the smaller angle from the larger angle. If your result is greater than 180 degree, subtract it from 360 degree to get the smaller (acute) angle.

// example at 3:30-
// minute hand: 30*6=180 degree
// hour hand= (3*30)+(30*0.5)=105 degree
// angle: abs(180 degree - 105 degree)=75 degree

// similarly if we want Second Hand Angle: in 360 degree in clock we have 12 hrs and in 1 hr we have 60 minutes and in 1 minute we have 60 seconds so in 360 degree we have 12*60*60=43200 seconds so 360 degree/43200=0.0083333 degree

// t.c-O(1)
// s.c-O(1)
double angleClock(int hour, int minutes)
{
  double firstAngle = abs(30 * hour - 5.5 * minutes);
  double secondAngle = 360 - firstAngle;
  return min(firstAngle, secondAngle);
}

int main()
{
  int hour, minutes;
  cin >> hour >> minutes;
  cout << angleClock(hour, minutes);
  return 0;
}