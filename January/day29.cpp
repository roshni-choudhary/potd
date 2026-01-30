//2976. Minimum Cost to Convert String I
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long inf=1e18;
        vector<vector<long long>> dist(26,vector<long long>(26,inf));
        int i,j,k;
        for(i=0;i<26;i++)
        dist[i][i]=0;
        for(i=0;i<original.size();i++)
        {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            dist[u][v]=min(dist[u][v],(long long)cost[i]);
        }
        for(k=0;k<26;k++)
        {
            for(i=0;i<26;i++)
            {
                for(j=0;j<26;j++)
                {
                    if(dist[i][k]<inf && dist[k][j]<inf)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        long long ans=0;
        for(i=0;i<source.size();i++)
        {
            int s=source[i]-'a';
            int t=target[i]-'a';
            if(dist[s][t]==inf) return -1;
            ans+=dist[s][t];
        }
        return ans;
    }
};