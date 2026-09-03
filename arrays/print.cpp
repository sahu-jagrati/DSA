#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    cout<<"Printing the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
}
cout<<endl;
cout<<"Printing is complete"<<endl;
}
void printArray1(char arr[],int size){
    cout<<"Printing the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
}
}

int main(){
    int arr[5]={1,2,3,4,5};
printArray(arr,5);
int totalsize=sizeof(arr);
cout<<endl<<totalsize<<endl; // o/p is 20
int length=sizeof(arr)/sizeof(int);
cout<<length<<endl; //o/p is 5

int a[15]={2,7};
int size=sizeof(a)/sizeof(int);
cout<<size<<endl;  // o/p is 15 , we cannot find size = 2 so that's why we giving size in function

// character aaray
char ch[5]={'a','b','c','d','e'};
printArray1(ch,5);

// boolean array
bool b[4];
return 0;
}