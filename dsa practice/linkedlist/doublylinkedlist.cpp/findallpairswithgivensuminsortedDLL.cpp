// given sorted doubly linked list
// find all pairs with given sum in any order

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *back;
  Node(int data1, Node *next1, Node *back1)
  {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArrToDLL(vector<int> &arr)
{
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++)
  {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void traverseDLL(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// extreme naive solution- we put one pointer fix and move second pointer once for whole DLL then move first pointer one step and again for this second pointer move from next of first pointer and so on

// t.c- approx.O(N^2) where N is length of DLL
// s.c-O(1)
vector<pair<int, int>> findallPairs(Node *head, int sum)
{
  Node *temp1 = head;
  vector<pair<int, int>> ans;
  while (temp1 != NULL)
  {
    Node *temp2 = temp1->next; // start from next of first pointer
    while (temp2 != NULL && temp1->data + temp2->data <= sum)
    { // if >sum then no need to move forward because we have sorted DLL
      if (temp1->data + temp2->data == sum)
      {
        ans.push_back({temp1->data, temp2->data});
      }

      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return ans;
}

// optimized solution-we have sorted DLL and we have back pointer also
// so we use two pointer approach
// for getting right pointer we first traverse DLL to get tail

Node *findTail(Node *head)
{
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  return tail;
}

// t.c-O(N)(for finding tail)+O(N)(while loop beacuse both left and right together traverse whole DLL)=O(2N) where N is length of DLL
// s.c-O(1)
vector<pair<int, int>> findAllPairs(Node *head, int sum)
{
  vector<pair<int, int>> ans;
  Node *left = head;
  Node *right = findTail(head); // get both pointer
  // we don't take = to because want pair
  while (left->data < right->data)
  {
    if (left->data + right->data == sum)
    {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->back;
    }
    else if (left->data + right->data < sum)
    {
      left = left->next;
    }
    else
    {
      right = right->back;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 9}; // sorted
  Node *head = convertArrToDLL(arr);
  int sum;
  cout << "Enter the value of sum: ";
  cin >> sum;
  cout << "Pairs with given sum: ";
  // vector<pair<int, int>> answer = findallPairs(head, sum);
  vector<pair<int, int>> answer = findAllPairs(head, sum);
  for (auto it : answer)
  {
    cout << it.first << " " << it.second << endl;
  }
  cout << endl;
  return 0;
}