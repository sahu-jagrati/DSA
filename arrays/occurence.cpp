#include<iostream>
using namespace std;

int OccurenceCount(int arr[],int size,int element){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            count++;

        }
    }
    cout<<endl<<"The no. of time element occur is "<<count<<endl;
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
    OccurenceCount(arr,size,element);
    return 0;
}