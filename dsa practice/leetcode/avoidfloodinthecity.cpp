// The story:

// There are infinitely many lakes — Lake 1, Lake 2, Lake 3, and so on.
// Each day, something happens — either it rains on a lake or the day is dry.
// Input meaning (rains array):

// If rains[i] > 0 → it rains on lake number rains[i] that day.
// That lake becomes full of water.
// If it rains again on the same full lake, there will be a flood (❌).

// If rains[i] == 0 → it’s a dry day.
// On this day, you can choose one lake and dry it (make it empty again).
// You can choose any lake — even one that’s already empty (it just does nothing).
// Your goal:

// Avoid floods — that means:

// No lake should get rained on while it’s already full

// What to return:

// You must return an array ans with the same length as rains:

// If it rains that day (rains[i] > 0) → write -1 (you can’t dry anything that day).

// If it’s dry that day (rains[i] == 0) → write the lake number you decide to dry.

// If it’s impossible to avoid a flood no matter what, return an empty array.

// Input: rains = [1,2,3,4]
// Output: [-1,-1,-1,-1]
// Explanation: After the first day full lakes are [1]
// After the second day full lakes are [1,2]
// After the third day full lakes are [1,2,3]
// After the fourth day full lakes are [1,2,3,4]
// There's no day to dry any lake and there is no flood in any lake.
// Example 2:

// Input: rains = [1,2,0,0,2,1]
// Output: [-1,-1,2,1,-1,-1]
// Explanation: After the first day full lakes are [1]
// After the second day full lakes are [1,2]
// After the third day, we dry lake 2. Full lakes are [1]
// After the fourth day, we dry lake 1. There is no full lakes.
// After the fifth day, full lakes are [2].
// After the sixth day, full lakes are [1,2].
// It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.

#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int> &rains)
{
  int n = rains.size();
  vector<int> ans(n, 1);        // Default 1 for dry days, will replace later
  unordered_map<int, int> full; // lake -> last day it rained
  set<int> dryDays;             // store indices of dry days

  for (int i = 0; i < n; i++)
  {
    if (rains[i] == 0)
    {
      // Dry day: we can dry one lake later
      dryDays.insert(i);
    }
    else
    {
      int lake = rains[i];
      ans[i] = -1; // It’s raining, can’t dry anything today

      // Check if this lake was already full before
      if (full.find(lake) != full.end())
      {
        int lastRainDay = full[lake]; // The day it got filled last time

        // We must find a dry day AFTER lastRainDay to dry this lake
        auto dry = dryDays.lower_bound(lastRainDay);
        if (dry == dryDays.end())
        {
          // No available dry day -> flood happens
          return {};
        }

        // Use that dry day to dry this lake
        ans[*dry] = lake;
        dryDays.erase(dry); // Remove that dry day (used)
      }

      // Update last rain day for this lake
      full[lake] = i;
    }
  }

  return ans;
}

int main()
{
  vector<int> rains = {1, 2, 0, 1, 2};
  vector<int> result = avoidFlood(rains);

  if (result.empty())
  {
    cout << "[] (Flood unavoidable)\n";
  }
  else
  {
    for (int x : result)
      cout << x << " ";
    cout << endl;
  }
}
