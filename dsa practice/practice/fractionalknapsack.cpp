#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int index;
  int value;
  int weight;
  double ratio; // value/weight
};

// time complexity-O(nlogn)(for sorting)+O(n)(for selection)=O(nlogn)
// space complexity-O(n)

// Comparison: sort in descending order of ratio
bool cmp(Item a, Item b)
{
  return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<int> &values, vector<int> &weights)
{
  int n = values.size();
  vector<Item> items(n);

  for (int i = 0; i < n; i++)
  {
    items[i] = {i + 1, values[i], weights[i], (double)values[i] / weights[i]};
  }

  // Sort by value/weight ratio
  sort(items.begin(), items.end(), cmp);

  double totalValue = 0.0;
  int remainingCapacity = W;

  cout << "\nItems taken in the Knapsack:\n";
  cout << "--------------------------------------------\n";
  cout << "Item\tValue\tWeight\tFraction Taken\n";
  cout << "--------------------------------------------\n";

  for (int i = 0; i < n; i++)
  {
    if (remainingCapacity == 0)
      break;

    if (items[i].weight <= remainingCapacity)
    {
      // Take the whole item
      totalValue += items[i].value;
      remainingCapacity -= items[i].weight;

      cout << items[i].index << "\t"
           << items[i].value << "\t"
           << items[i].weight << "\t"
           << "1.00\n";
    }
    else
    {
      // Take fractional part
      double fraction = (double)remainingCapacity / items[i].weight;
      totalValue += items[i].value * fraction;

      cout << items[i].index << "\t"
           << items[i].value << "\t"
           << items[i].weight << "\t"
           << fixed << setprecision(2) << fraction << "\n";

      remainingCapacity = 0; // Knapsack full
    }
  }

  cout << "--------------------------------------------\n";
  return totalValue;
}

int main()
{
  int W = 50;
  vector<int> values = {60, 100, 120};
  vector<int> weights = {10, 20, 30};

  cout << "Knapsack capacity: " << W << "\n";
  double maxValue = fractionalKnapsack(W, values, weights);

  cout << "\nMaximum total value in Knapsack = "
       << fixed << setprecision(2) << maxValue << endl;

  return 0;
}
