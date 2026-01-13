//Separate Squares I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=1e18,high=-1e8;
        for(auto &s:squares)
        {
            low=min(low,(double)s[1]);
            high=max(high,(double)(s[1]+s[2]));
        }
        auto helper=[&](double mid)->double{
            double above=0.0,below=0.0;
            for(auto &s:squares)
            {
                double bottom=s[1],top=s[1]+s[2],l=s[2];
                if(mid<=bottom) above+=l*l;
                else if(mid>=top) below+=l*l;
                else
                {
                    below+=(mid-bottom)*l;
                    above+=(top-mid)*l;
                }
            }
            return above-below;
        };
        while(high-low>1e-6)
        {
            double mid=(low+high)/2;
            if(helper(mid)>0)
            low=mid;
            else
            high=mid;
        }
        return low;
    }
};