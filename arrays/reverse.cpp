#include <iostream>
using namespace std;

void reverseArray(int arr[], int size)
{
    int reverseArray[size];
    for (int i = 0; i < size; i++)
    {
        reverseArray[i]=arr[size-1-i];
    }
    cout<<"The reverse array is"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout  << reverseArray[i] << endl;
    }
}
// void reverseArray(int arr[],int size){
//     int start=0;
//     int end=size-1;
//     while(start<=end){
//         swap(arr[start]=arr[end]);
//         start++;
//         end--;
//     }
//     cout<<"The reverse array is"<<endl;
//     for (int i = 0; i < size; i++)
//     {
//         cout  << arr[i] << endl;
//     }
// }

int main()
{
    int arr[10];
    int size;
    cout << "Enter the size of an array" << endl;
    cin >> size;
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    reverseArray(arr, size);
    return 0;
}