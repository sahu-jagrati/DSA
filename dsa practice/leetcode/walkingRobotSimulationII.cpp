// A width x height grid is on an XY-plane with the bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). The grid is aligned with the four cardinal directions ("North", "East", "South", and "West"). A robot is initially at cell (0, 0) facing direction "East".

// The robot can be instructed to move for a specific number of steps. For each step, it does the following.

// Attempts to move forward one cell in the direction it is facing.
// If the cell the robot is moving to is out of bounds, the robot instead turns 90 degrees counterclockwise and retries the step.
// After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

// Implement the Robot class:

// Robot(int width, int height) Initializes the width x height grid with the robot at (0, 0) facing "East".
// void step(int num) Instructs the robot to move forward num steps.
// int[] getPos() Returns the current cell the robot is at, as an array of length 2, [x, y].
// String getDir() Returns the current direction of the robot, "North", "East", "South", or "West".

// Example 1:

// example-1
// Input
// ["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
// [[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
// Output
// [null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

// Explanation
// Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
// robot.step(2);  // It moves two steps East to (2, 0), and faces East.
// robot.step(2);  // It moves two steps East to (4, 0), and faces East.
// robot.getPos(); // return [4, 0]
// robot.getDir(); // return "East"
// robot.step(2);  // It moves one step East to (5, 0), and faces East.
//                 // Moving the next step East would be out of bounds, so it turns and faces North.
//                 // Then, it moves one step North to (5, 1), and faces North.
// robot.step(1);  // It moves one step North to (5, 2), and faces North (not West).
// robot.step(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
//                 // Then, it moves four steps West to (1, 2), and faces West.
// robot.getPos(); // return [1, 2]
// robot.getDir(); // return "West"

// Constraints:

// 2 <= width, height <= 100
// 1 <= num <= 105
// At most 104 calls in total will be made to step, getPos, and getDir.

#include <bits/stdc++.h>
using namespace std;

// i write my own code but it is wrong in steps function
// correct logic
// Robot moves along the perimeter like this:
// East->North->West->South->repeat
// so movement depends on position:
// Direction           Condition
// East               y==0&&x<xBound
// North              x==xBound&&y<yBound
// West               y==yBound&&x>0
// South              x==0 && y>0

// optimized approach:
// instead of simulating every step, use cycle length:
// perimeter=2*(width+height-2)

// Key Improvements

// ✔ Fixed direction conditions
// ✔ No wrong boundary checks
// ✔ Uses modulo → faster for large inputs
// ✔ Clean and readable logic

// If:

// num % perimeter == 0

// 👉 Robot should face South (edge case many people miss)

// When:
// num % perimeter == 0
// 👉 Your code does:

// num %= perimeter; // becomes 0

// So:

// while(num > 0) never runs
// Position stays same ✅
// BUT direction remains unchanged ❌
// 🔥 What Should Happen?

// If robot completes a full cycle, it should face:

// 👉 "South" (as per problem requirement)

class Robot
{
  int x = 0, y = 0; // initially at (0,0)
  int xBound, yBound;
  string direc = "East"; // initially in east
public:
  Robot(int width, int height)
  {
    xBound = width - 1;
    yBound = height - 1;
  }
  void steps(int num)
  {
    int perimeter = 2 * (xBound + yBound);
    num %= perimeter;
    // edge case
    if (num == 0)
    {
      if (x == 0 && y == 0)
      {
        direc = "South";
      }
      return;
    }
    while (num > 0)
    {
      if (direc == "East")
      {
        if (x < xBound)
        {
          x++;
          num--;
        }
        else
        {
          direc = "North";
        }
      }
      else if (direc == "North")
      {
        if (y < yBound)
        {
          y++;
          num--;
        }
        else
        {
          direc = "West";
        }
      }
      else if (direc == "West")
      {
        if (x > 0)
        {
          x--;
          num--;
        }
        else
        {
          direc = "South";
        }
      }
      else
      {
        // South
        if (y > 0)
        {
          y--;
          num--;
        }
        else
        {
          direc = "East";
        }
      }
    }
  }
  vector<int> getPos()
  {
    return {x, y}; // current position return
  }
  string getDir()
  {
    return direc;
  }
};

int main()
{
  Robot *obj = new Robot(6, 3);
  obj->steps(2);
  obj->steps(2);
  vector<int> ans = obj->getPos();
  cout << ans[0] << " " << ans[1];
  cout << obj->getDir();
  return 0;
}