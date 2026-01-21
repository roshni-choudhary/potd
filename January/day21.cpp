//3314. Construct the Minimum Bitwise Array I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)
            ans[i]=-1;
            else
            {
                int j=0;
                while(nums[i]&(1<<j)) j++;
                ans[i]=nums[i]&~(1<<(j-1));
            }
        }
        return ans;
    }
};