// Problem: Minimum Pair Removal to Sort Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        auto sorted=[&]()
        {
          for(int i=1;i<nums.size();i++)
          {
            if(nums[i-1]>nums[i])
            return false;
          }
          return true;
        };
        int cnt=0;
        bool s=sorted();
        while(!s)
        {
            long long mins = LLONG_MAX;
            int ind;
            for(int i=0;i<nums.size()-1;i++)
            {
                long long sum = (long long)nums[i] + nums[i+1];
                if(sum < mins) {
                    mins = sum;
                    ind=i;
                }
            }
            nums[ind]=mins;
            nums.erase(nums.begin()+ind+1);
            s=sorted();
            cnt++;
        }
        return cnt;
    }
};