#include <iostream>
#include <algorithm>
using namespace std;

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
    sort(arr, arr + size); // arr is the name of the array which also acts as a pointer to the first element of the array.
                           // n is the size of the array.
    PrintArray(arr, size);
    return 0;
}