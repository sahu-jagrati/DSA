#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

int main(){
    int arr1[10],arr2[10],arr3[20];
    int n1,n2,n3;
    cout<<"Enter the size of first array"<<endl;
    cin>>n1;
    cout<<endl;
    cout<<"Enter the size of second array"<<endl;
    cin>>n2;
    cout<<endl;
    cout<<"Enter the size of third array"<<endl;
    cin>>n3;
    cout<<endl;
    cout<<"Printing the first array"<<endl;
    printArray(arr1,n1);
    cout<<"Printing the second array"<<endl;
    printArray(arr2,n2);
    for(int i=0;i<n1;i++){
        arr3[i]=arr1[i];
    }
    for(int i=0;i<n2;i++){
        arr3[n1+i]=arr2[i];
    }
    cout<<endl<<"The merging array is "<<endl;
    for(int i=0;i<n3;i++){
        cout<<arr3[i]<<" ";
    }
    return 0;


}