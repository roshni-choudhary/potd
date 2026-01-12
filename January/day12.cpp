#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int i;
        int time=0;
        for(i=1;i<n;i++)
        {
            int dx=abs(points[i][0]-points[i-1][0]);
            int dy=abs(points[i][1]-points[i-1][1]);
            time+=(min(dx,dy)+abs(dx-dy));
        }
        return time;
    }
};