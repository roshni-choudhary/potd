//N-Repeated Element in Size 2N Array
#include <vector>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i+1<n;i++)
        {
            if(nums[i]==nums[i+1])
            return nums[i];        }
             for(int i=0;i+2<n;i++)
        {
            if(nums[i]==nums[i+2])
            return nums[i];        }
             for(int i=0;i+3<n;i++)
        {
            if(nums[i]==nums[i+3])
            return nums[i];        }
    return 0;
    }
};