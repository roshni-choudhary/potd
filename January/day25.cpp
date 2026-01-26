//1984. Minimum Difference Between Highest and Lowest of K Scores
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0; 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
         ans=min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};