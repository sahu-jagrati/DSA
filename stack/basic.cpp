#include <iostream>
#include <stack>
using namespace std;

int main()
{

    // creation of stack using stl
    stack<int> s;
    // insert element in stack
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(1);
    // remove element from stack
    s.pop();
    cout << "Printing top element is " << s.top()<<endl;

    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}
