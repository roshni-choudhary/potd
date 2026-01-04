//1411. Number of Ways to Paint N × 3 Grid
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<string> comb;
//T(n) = O(3³) = O(27) = O(1)
void generate(int ind,string curr,char prev)
{
    if(ind==3)
    {
        comb.push_back(curr);
        return;
    }
    for(char c:{'R','Y','G'})
    {
        if(c==prev)
        continue;
        generate(ind+1,curr+c,c);
    }
}
bool compatible(string &a,string &b)
{
    for(int i=0;i<3;i++)
    {
        if(a[i]==b[i])
        return false;
    }
    return true;
}
    int numOfWays(int n) {
         const int MOD = 1e9 + 7;
         generate(0,"",'#');
         int states=comb.size();
         vector<vector<int>> dp(n,vector<int>(states,0));
         int i,j,k;
         for(int j = 0; j < states; j++)
         dp[0][j] = 1;
         for(i=1;i<n;i++)
         {
            for(j=0;j<states;j++)
            {
                for(k=0;k<states;k++)
                {
                    if(j==k) continue;
                    if(compatible(comb[j],comb[k]))
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
            }
         }
         int ans=0;
         for(auto a:dp[n-1])
         ans=(ans+a)%MOD;
         return ans;
    }
};
//sc O(12n) = O(n)
//tc O(12*12*n) = O(n)