#include <iostream>
#include <algorithm>

using namespace std;

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
    sort(arr, arr + size);
    cout << "The smallest element is " << arr[0] << endl;
    cout << "THe second smallest element is " << arr[1];
    return 0;
}
