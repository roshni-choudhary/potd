//1975. Maximum Matrix Sum
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int i,j,cnt,mine=INT_MAX;
        int n=matrix.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
             if(matrix[i][j]<0)
             cnt++;
             mine=min(mine,abs(matrix[i][j]));
             sum+=abs(matrix[i][j]);
            }
        }
        if(cnt%2==0) return sum;
        else
        return sum-2*mine;
    }
};