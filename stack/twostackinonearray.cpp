#include<iostream>
#include<stack>
using namespace std;


class Twostack{
public:
int *arr;
int top1;
int top2;
int size;

Twostack(int s){
    this->size=s;
    top1=-1;
    top2=s;
    arr=new int[s];
}

void push1(int num1){
    if(top2-top1>1){
        top1++;
        arr[top1]=num1;
    }
    else{
        cout<<"Stack is overflow"<<endl;
    }
}
void push2(int num2){
    if(top2-top1>1){
        top2--;
        arr[top2]=num2;
    }
    else{
        cout<<"Stack is overflow"<<endl;
    }
}
int pop1(){
    if(top1>=0){
        int ans=arr[top1];
        top1--;
        return ans;
    }
    else{
        cout<<"Stack is underflow"<<endl;
    }
}
int pop2(){
    if(top2<size){
        int ans=arr[top2];
        top2++;
        return ans;
    }
    else{
        cout<<"Stack is underflow"<<endl;
    }
}


};
int main(){
Twostack st(5);
st.push1(2);
st.push1(3);
st.push1(4);
st.push2(7);
st.push2(1);


}