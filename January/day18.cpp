// Problem: Largest Magic Square
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i,j,ans=1;
        vector<vector<int>> row(n,vector<int>(m));
        vector<vector<int>> col(n,vector<int>(m));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                row[i][j]=grid[i][j]+((j>0)?row[i][j-1]:0);
                col[i][j]=grid[i][j]+((i>0)?col[i-1][j]:0);
            }
        }
        for(int k=min(n,m);k>=2;k--)
        {
            for(i=0;i<=(n-k);i++)
            {
                for(j=0;j<=(m-k);j++)
                {
                    int targets=row[i][j+k-1]-((j>0)?row[i][j-1]:0);
                    int sum=0; bool poss=true;
                    for(int r=1;r<k;r++)
                    {
                        sum=row[i+r][j+k-1]-((j>0)?row[r+i][j-1]:0);
                        if(sum!=targets)
                        {
                            poss=false;
                            break;
                        }
                    }
                    if(!poss) continue;
                    for(int c=1;c<k;c++)
                    {
                        sum=col[i+k-1][j+c]-((i>0)?col[i-1][c+j]:0);
                        if(sum!=targets)
                        {
                            poss=false;
                            break;
                        }
                    }
                    if(!poss) continue;
                    int diag=0,adiag=0;
                    for(int d=0;d<k;d++)
                    {
                        diag+=grid[i+d][j+d];
                        adiag+=grid[i+d][j+k-1-d];
                    }
                    if (diag != targets || adiag != targets) continue;
                    return k;
                }
            }
        }
        return 1;
    }
};