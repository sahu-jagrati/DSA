#include<bits/stdc++.h>
using namespace std;
  vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct=1;
        int n=nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=1;
        suffix[n-1]=1;
        int i=1,j=n-2;
        while(i<n||j>=0){
            if(i<n){
               prefix[i]=prefix[i-1]*nums[i-1];
               i++; 
            }
            if(j>=0){
                suffix[j]=suffix[j+1]*nums[j+1];
                j--;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
           ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }

    int main(){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<int>ans=productExceptSelf(nums);
        for(auto it:ans){
            cout<<it<<" ";
        }
        return 0;
    }