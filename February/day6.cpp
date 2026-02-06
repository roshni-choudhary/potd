#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        sort(nums.begin(),nums.end());
        int len=INT_MIN;
        while(j<n)
        {
         while(i<=j && nums[j]>1LL*k*nums[i])
         {
          i++;
         }
         len=max(len,j-i+1);
         j++;
        }
        return(n-len);
    }
};