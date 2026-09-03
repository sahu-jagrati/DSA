#include<iostream>
using namespace std;

// int duplicateElement(int arr[],int size,int element){
//     for(int i=0;i<size;i++){
//         if(arr[i]==element){
//             cout<<arr[i]<<endl;
//         }
//     }
// }

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
    //  cout<<"Enter the element to search"<<endl;
    // int element;
    // cin>>element;
    // duplicateElement(arr,size,element);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                cout<<endl<<arr[i];
            }
        }
    }
    return 0;
}