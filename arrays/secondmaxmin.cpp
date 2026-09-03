#include<iostream>
#include<algorithm>
using namespace std;

// if array is sorted
void PrintSecondLargest(int arr[],int size){
    // sorting the array in descending order
    // greater<int>() is used as an third argument
    sort(arr,arr+size,greater<int>());
    for(int i=1;i<size;i++){
        if(arr[i]!=arr[0]){
            cout<<"THe second largest element of an array is "<<arr[i]<<endl;
        }
        return;
    }
    cout<<"The second element does not exist"<<endl;
}

int main(){
    int arr[10];
    int size;
    cout << "Enter the size of an array" << endl;
    cin >> size;
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    PrintSecondLargest(arr,size);
    return 0;
}