//3047. Find the Largest Area of Square Inside Two Rectangles
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int i,j;
        long long area=LLONG_MIN;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int leftw=max(bottomLeft[i][0],bottomLeft[j][0]);
                int rightw=min(topRight[i][0],topRight[j][0]);
                int width=rightw-leftw;
                if(width<=0) continue;
                int downh=max(bottomLeft[i][1],bottomLeft[j][1]);
                int uph=min(topRight[i][1],topRight[j][1]);
                int height=uph-downh;
                if(height<=0) continue;
                long long side=min(height,width);
                area=max(area,side*side);
            }
        }
        if(area==LLONG_MIN)
        return 0;
        return area;
    }
};