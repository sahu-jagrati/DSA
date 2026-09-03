#include<iostream>
using namespace std;

int BinarySearch(int arr[],int size,int element){
int low=0;
int high=size-1;
while(low<=high){
    int mid=(low+high)/2;
    if(arr[low]==element){
        return low;
    }
    if(arr[high]==element){
        return high;
    }
    if (arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        low=mid+1;

    }
    else{
        high=mid-1;
    }
}
return -1;
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
    cout<<"Enter the element to search"<<endl;
    int element;
    cin>>element;
    int search=BinarySearch(arr,size,element);
    cout<<endl<<search<<endl;
    return 0;
}