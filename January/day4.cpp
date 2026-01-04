//1390. Four Divisors
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
int maxn;
    int sumFourDivisors(vector<int>& nums) {
        maxn=*max_element(nums.begin(),nums.end());
        vector<bool> isprime(maxn+1,true);
        isprime[0]=false; isprime[1]=false;
        int i,j,ans=0;
        for(i=2;i*i<=maxn;i++)
        {
            if(isprime[i])
            for(j=i*i;j<=maxn;j+=i)
            {
             isprime[j]=false;
            }
        }
        for(int n:nums)
        {
            int p=round(cbrt(n));
            if(p*p*p==n && isprime[p])
           { ans+=1+p+p*p+n;
            continue;}
            for(int d=2;d*d<=n;d++)
            {
                if(n%d==0)
                {
                    int q=n/d;
                    if(d!=q && isprime[d] && isprime[q])
                    ans+=1+d+q+n;
                    break;
                }
            }
        }
        return ans;
    }
};