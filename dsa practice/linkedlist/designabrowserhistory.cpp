// You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:

// BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
// void visit(string url) Visits url from the current page. It clears up all the forward history.
// string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
// string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps

// we design a browser in which the first query always be the constructor homepage and this will only be called once, right at  the starting of all queries
// browser(homepage)-contructor which telle me that this is my initial page
// visit(url)- by this we going forward
// back(steps) and forward(steps) are two functions that return a string which is basically the url that say where I'm currently standing at.

// three case-
// visit(url)- by this we visiting a new page so we are getting into new pages and we don't know the length so we cann;t use something like an array
// back(steps)- we need to come back as well
// forward(steps)-we need to go forward as well
// so we cann't use array

// so which data structure allow us to go back,go front & at the samtime allows us to keep adding new pages? - doubly ;inked list, not singly linked list because it does not allow to go back
// so, DLL that we use
// instead of integer data we store the data in terms of string a url of the page

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  string data;
  Node *back;
  Node *next;
  Node()
  {
    data = " ";
    next = nullptr;
    back = nullptr;
  }
  Node(string x)
  {
    data = x;
    next = nullptr;
    back = nullptr;
  }
  Node(string x, Node *next1, Node *back1)
  {
    data = x;
    next = next1;
    back = back1;
  }
};

class Browser
{
  Node *currentPage; // private
public:
  // construtor that will be the first query always and this will only be called once,right at  the starting of all queries

  // take O(1) time
  Browser(string homepage) // can be any url
  {
    currentPage = new Node(homepage); // new tab create
  }

  // take O(1) time
  void visit(string url)
  {
    Node *newNode = new Node(url);
    currentPage->next = newNode;
    newNode->back = currentPage;
    currentPage = newNode;
  }

  // this takes O(no.of steps)how many steps you go back
  string back(int steps)
  {
    while (steps > 0)
    {
      if (currentPage->back)
      {
        currentPage = currentPage->back;
      }
      else
      {
        break;
      }
      steps--;
    }
    return currentPage->data;
  }

  // this take O(no.of steps) how many steps you go next
  string forward(int steps)
  {
    while (steps > 0)
    {
      if (currentPage->next)
      {
        currentPage = currentPage->next;
      }
      else
      {
        break;
      }
      steps--;
    }
    return currentPage->data;
  }
};

// queries like-
// first always constructor
// browser(takeuforward.org) can be any url - open new tab and in this open takeuforward
// visit(google.com)- on same tab open google
// visit(instagram.com)- on same tab open instagram
// visit(facebook.com)- on same tab open facebook
// back(1)- return instagram
// back(1)-return google
// forward(1)-instagram
// visit(takeuforward.org)- when we open this page on same tab so now facebook is not be there
// forward(2)- after takeuforward there is nothing so it return takeuforward
// back(2)-return google
// back(7)- return takeuforward homepage, here at max we can go one step because we reach in one step to homepage so return takeuforward which is at homepage

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main()
{

  Browser *browserHistory = new Browser("leetcode.com");
  browserHistory->visit("google.com");
  browserHistory->visit("facebook.com");
  browserHistory->visit("instagram.com");
  cout << browserHistory->back(1) << endl;
  cout << browserHistory->back(1) << endl;
  cout << browserHistory->forward(1) << endl;
  browserHistory->visit("leetcode.com");
  cout << browserHistory->forward(2) << endl;
  cout << browserHistory->back(2) << endl;
  cout << browserHistory->back(7) << endl;
  return 0;
}

// Input : [ "BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back" ]
//             [["leetcode.com"], ["google.com"], ["facebook.com"], ["youtube.com"], [1], [1], [1], ["linkedin.com"], [2], [2], [7]] Output : [ null, null, null, null, "facebook.com", "google.com", "facebook.com", null, "linkedin.com", "google.com", "leetcode.com" ]

//                                                                                                                                            Explanation : BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
// browserHistory.visit("google.com");   // You are in "leetcode.com". Visit "google.com"
// browserHistory.visit("facebook.com"); // You are in "google.com". Visit "facebook.com"
// browserHistory.visit("youtube.com");  // You are in "facebook.com". Visit "youtube.com"
// browserHistory.back(1);               // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
// browserHistory.back(1);               // You are in "facebook.com", move back to "google.com" return "google.com"
// browserHistory.forward(1);            // You are in "google.com", move forward to "facebook.com" return "facebook.com"
// browserHistory.visit("linkedin.com"); // You are in "facebook.com". Visit "linkedin.com"
// browserHistory.forward(2);            // You are in "linkedin.com", you cannot move forward any steps.
// browserHistory.back(2);               // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
// browserHistory.back(7);               // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"