//1653. Minimum Deletions to Make String Balanced
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        if(s.size()<=1) return 0;
        int n=s.size();
        vector<int> pref(n),suff(n+1);
        suff[n]=0;
        pref[0]=(s[0]=='b')?1:0;
        suff[n-1]=(s[n-1]=='a')?1:0;
        int i,j;
        for(i=1;i<n;i++)
        {
            pref[i]=(s[i]=='b')?1:0;
            pref[i]+=pref[i-1];
        }
        for(i=n-2;i>=0;i--)
        {
            suff[i]=(s[i]=='a')?1:0;
            suff[i]+=suff[i+1];
        }
        if(pref[n-1]==n||suff[0]==n) return 0;
        int ans =suff[0];;
         for(i=0;i<n;i++)
        {
            ans=min(ans,pref[i]+suff[i+1]);
        }
        return ans;
    }
};