#include<iostream>
using namespace std;

int main(){
    // declaraing an array
    int x[3][4];
    // initialisation of an array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            x[i][j]=i+j;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
        cout<<endl<<x[i][j]<<endl;
        }
    }

    return 0;
}