#include <iostream>
#include <algorithm>
using namespace std;

void sortedArray(int arr[], int size)
{
    int temp=0;
    for (int i = 0; i <size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
        else{
            
        }
    }
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[10];
    cout << "Enter the size of an array" << endl;
    int size;
    cin >> size;
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    PrintArray(arr, size);
    cout<<endl;
    sortedArray(arr, size);
    cout<<endl;
    PrintArray(arr, size);
    cout<<endl;
    return 0;
}