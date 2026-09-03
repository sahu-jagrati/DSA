#include<iostream>
using namespace std;

int main(){
    int x,y,z;
    cout<<"Enter the value of x,y,z"<<endl;
    cin>>x>>y>>z;
    cout<<endl;
    int arr[x][y][z]; // where x represent no of 2D arrays
    // y represent no of rows in each 2D arrays
    // z represnt no of columns in each 2D arrays
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                arr[i][j][k]=i+j+k;
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                cout<<endl<<arr[i][j][k]<<" ";
            }
        }
    }


}