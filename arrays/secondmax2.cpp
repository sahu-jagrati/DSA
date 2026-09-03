#include<iostream>
using namespace std;
 
 // find second largest by traversing the array twice
int secondLargest(int arr[], int n) {
    int largest = 0, secondLargest = -1;

    // finding the largest element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largest])
            largest = i;
    }

    // finding the largest element in the array excluding 
    // the largest element calculated above
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[largest]) {
            // first change the value of second largest 
            // as soon as the next element is found
            if (secondLargest == -1)
                secondLargest = i;
            else if (arr[i] > arr[secondLargest])
                secondLargest = i;
        }
    }
    return secondLargest;
}
int main(){
    int arr[10];
    cout << "Enter the size of an array" << endl;
    int size;
    cin >> size;
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int second_Largest = secondLargest(arr, size);
    if (second_Largest == -1)
        cout << "Second largest didn't exit\n";
    else
        cout << "Second largest : " << arr[second_Largest];
        return 0;
}