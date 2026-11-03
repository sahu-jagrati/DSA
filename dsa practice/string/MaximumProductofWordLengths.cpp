#include<bits/stdc++.h>
using namespace std;

   bool common(string str1,string str2){
        unordered_set<char>st;
        for(char ch:str1){
            st.insert(ch);
        }
        for(char ch:str2){
            if(st.count(ch)){
                return true;
            }
        }
        return false;
    }

    // brute force solution
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int length=INT_MIN;
        for(int i=0;i<n;i++){
            string str1=words[i];
            for(int j=i+1;j<n;j++){
                string str2=words[j];
                if(!common(str1,str2)){
                    int size=str1.size()*str2.size();
                    length=max(length,size);
                }
            }
        }
        if(length==INT_MIN)return 0;
        return length;
    }

    // optimized solution
    int MaxProduct(vector<string>&words){
        int n=words.size();

        vector<int>mask(n);
        for(int i=0;i<n;i++){
            int m=words[i].size();
            for(int j=0;j<m;j++){
                mask[i]|=(1<<(words[i][j]-'a'));

            }
        }
        int length=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    int size=words[i].size()*words[j].size();
                    length=max(length,size);
                }
            }
        }
        if(length==INT_MIN)return 0;
        return length;
    }

    int main(){
        int n;
        cin>>n;
        vector<string>words(n);
        for(int i=0;i<n;i++){
            cin>>words[i];
        }
        cout<<maxProduct(words)<<endl;
        cout<<MaxProduct(words)<<endl;
        return 0;
    }