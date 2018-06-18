//Codeforces
//https://codeforces.com/contest/979/problem/E
#include<bits/stdc++.h>
using namespace std;
int n,p;
int arr[55];
long long dp[55][55][55]; //i ow ob
const long long mod = 1000000007LL;

long long bin_exp(long long base, long long pot){
    if(pot == 0LL) return 1LL;
    if(pot == 1LL) return base;
    long long r = bin_exp(base,pot/2LL);
    r = (r*r)%mod;
    if(pot%2LL == 1LL)
        r = (r*base)%mod;
    return r;
}

long long dfs(int i, int ow, int ob){
    long long &ans = dp[i][ow][ob];
    if(ans != -1) return ans;
    if(ow < 0 || ob < 0) return ans = 0;
    if(i == 0) return ans = 0;
    if(i == 1){
        //white node
        if((arr[i] == 0 || arr[i] == -1) && ow == 1)
            return ans = 1;
        //black node
        if((arr[i] == 1 || arr[i] == -1) && ob == 1)
            return ans = 1;
    }
    long long ans1 = 0, ans2 = 0;
    //white node
    if(arr[i] == 0  || arr[i] == -1){
        long long r1 = bin_exp(2LL,(long long)(i-ob-1));
        if(ob == 0)
            ans1 = (r1*dfs(i-1,ow-1,ob))%mod;
        else{
            long long r2 = (dfs(i-1,ow,ob)*bin_exp(2LL,(long long)(ob-1)))%mod;
            long long r3 = (dfs(i-1,ow-1,ob)*bin_exp(2LL,(long long)(ob-1)))%mod;
            ans1 = (r1*((r2+r3)%mod))%mod;
        }
    }
    //black node
    if(arr[i] == 1  || arr[i] == -1){
        long long r1 = bin_exp(2LL,(long long)(i-ow-1));
        if(ow == 0)
            ans2 = (r1*dfs(i-1,ow,ob-1))%mod;
        else{
            long long r2 = (dfs(i-1,ow,ob)*bin_exp(2LL,(long long)(ow-1)))%mod;
            long long r3 = (dfs(i-1,ow,ob-1)*bin_exp(2LL,(long long)(ow-1)))%mod;
            ans2 = (r1*((r2+r3)%mod))%mod;
        }
    }
    return ans = (ans1+ans2)%mod;
}

int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d%d",&n,&p);
    for(int i = 1; i <= n; ++i)
        scanf("%d",&arr[i]);
    long long sum = 0;
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            if((i+j)%2 == p)
                sum = (sum+dfs(n,i,j))%mod;
    printf("%lld\n",sum);
    return 0;
}
