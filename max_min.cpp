#include<iostream>
#include<climits>
using namespace std;

int getMax(int arr[],int size){
    int MAX=INT_MIN;
    int MAXI=INT_MIN;
    // int MAX =0; // this is not use because if we give negative integers then it does not work

    for(int i=0;i<size;i++){
        MAXI=max(MAXI,arr[i]);
        // if(arr[i]>MAX){
        //     MAX=arr[i];

        // }
    }
    return MAXI;
}
int getMin(int arr[],int size){
    // int MAX= INT_MIN ;
    int MIN=INT_MAX;

    for(int i=0;i<size;i++){
        if(arr[i]<MIN){
            MIN=arr[i];

        }
    }
    return MIN;
}


int main(){
    int size;
    cout<<"Enter the size "<<endl;

    cin >> size;
    int arr[100];
    cout<<"Enter the values in an array"<<endl;
    for(int i=0;i<size;i++){
        cin >> arr[i];

    }
    cout<<endl;
    cout<<"PRint the array"<<endl;
    for(int i=0;i<size;i++){
       cout<<arr[i]<<" ";
    }

   cout<<endl<< getMax(arr,size);
   cout<<endl<<getMin(arr,size);
    return 0;
}