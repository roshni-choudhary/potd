//1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        int i,j;
        vector<vector<int>> p(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                p[i][j]=mat[i][j];
                if(i-1>=0)
                p[i][j]+=p[i-1][j];
                if(j-1>=0)
                p[i][j]+=p[i][j-1];
                if(i-1>=0&&j-1>=0)
                p[i][j]-=p[i-1][j-1];

            }
        }
        auto helper=[&](int k)->bool
        {
           for(i=0;i<=(n-k);i++)
        {
            for(j=0;j<=(m-k);j++)
            {
                 int r = i + k - 1, c = j + k - 1;
                    int sum = p[r][c]
                            - (i > 0 ? p[i-1][c] : 0)
                            - (j > 0 ? p[r][j-1] : 0)
                            + (i > 0 && j > 0 ? p[i-1][j-1] : 0);
                    if (sum <= threshold) return true;
            }
        }
        return false;
        };
        int low=1,high=min(n,m),ans=0;
       while (low <= high) {
    int mid = (low + high) / 2;
    if (helper(mid)) {
        ans = mid;
        low = mid + 1;
    } else {
        high = mid - 1; 
    }
}
return ans;
    }
};
//Time Complexity: O(n*m*log(min(n,m))) n*m for helper function and log(min(n,m)) for binary search
//Space Complexity: O(n*m) 