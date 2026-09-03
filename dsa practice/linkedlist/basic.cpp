// in linked list head is the starting point of LL and tail is end point of LL so
// head is the pointer point to first elt and head->next gives second elt and tail point to last elt and tail->next=nullptr

// in linked list we can have duplicates in different address like in array in different index we have
#include <bits/stdc++.h>
using namespace std;

// in linked list we store two things- one is data itself and other is pointer to the next but there is no datatype that store both so we have to declare self defined datatype that store both

// using struct cann't use OOPS concept like abstraction/encapsulation/inheritance for this we have to use class in same manner for OOPS concept
// both are same only difference is OOPS concept availablity
// if using class then define data and next pointer public and the constructor also
struct Node
{
  // here we have singly linked list because we know only what is next does not what we have previous
  int data;
  Node *next; // pointer to the next
  // constructor
  Node(int data1, Node *next1)
  {
    data = data1;
    next = next1;
  }
  Node(int data1)
  {
    data = data1;
    next = nullptr;
  }
  Node()
  {
    data = 0;
    next = nullptr;
  }
};

int main()
{
  // technically use this
  Node *x = new Node(2, nullptr);
  cout << x << endl;                         // give address, pointer to the memory location
  cout << x->data << " " << x->next << endl; // return 2 and nullptr
  // cout<<x.data; // give error

  Node y = Node(3, nullptr); // this also correct but use first one
  // cout<<y; // give error
  cout << y.data << " " << y.next << endl; // give 3 and nullptr
  Node *z = &y;
  cout << z; // give address of y which we can also  do in one line
  // Node*y =new Node(3,nullptr); // automatically stores a pointer to the memory location
  return 0;
}