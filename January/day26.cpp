//1200. Minimum Absolute Difference
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        int i;
        int diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(i=0;i<n-1;i++)
        {
         diff=min(diff,arr[i+1]-arr[i]);
        }
        for(i=0;i<n-1;i++)
        {
         if(arr[i+1]-arr[i]==diff)
         ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};