#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            // cout << "Search is complete" << endl;
            return 1; 
        }
    
    }
    return 0;
}

int main()
{
    int arr[10];
    int size;
    cout<<"Enter the size"<<endl;
    cin >> size;
    cout<<"Printing the array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "The number searching is " << endl;
    int num;
    cin >> num;
     bool search = LinearSearch(arr, size, num);
     cout<<endl<<search<<endl;
}