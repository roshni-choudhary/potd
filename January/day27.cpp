//3650. Minimum Cost Path with Edge Reversals
/*
#include<bits/stdc++.h>
using namespace std;      
class Solution {
public:
const long long inf=1e18;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges)
        {
          int u = e[0];
          int v = e[1];
          int wt = e[2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,2*wt});
        }
        vector<long long> dist(n,inf);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,    int>>> pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto [d,u]=pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto[v,wt]:adj[u])
            {
                if(dist[u] + wt < dist[v])
                {
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[n-1]==inf?-1:dist[n-1];
    }
};
*/