// Problem: Maximize Square Hole Area
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int i,j;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int x=hBars.size(),y=vBars.size();
        int cntx=1,cnty=1,mcntx=1,mcnty=1;
        for(i=1;i<x;i++)
        {
         if(hBars[i]==(hBars[i-1]+1))
         cntx++;
         else cntx=1;
         mcntx=max(cntx,mcntx);
        }
        for(i=1;i<y;i++)
        {
         if(vBars[i]==(vBars[i-1]+1))
         cnty++;
         else cnty=1;
         mcnty=max(cnty,mcnty);
        }
        int side=min(mcntx+1,mcnty+1);
        return side*side;
    }
};