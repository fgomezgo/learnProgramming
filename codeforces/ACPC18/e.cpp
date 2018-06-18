#include<bits/stdc++.h>
using namespace std;

int n;
long long arr[100005];
long long previ[100005];
long long succ[100005];
const long long mod = 1000000007LL;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%lld",&arr[i]);
        previ[0] = previ[n+1] = succ[0] = succ[n+1] = 1;
        for(int i = 1; i <= n; ++i)
            previ[i] = (previ[i-1]*arr[i])%mod;
        for(int i = n; i >= 1; --i)
            succ[i] = (succ[i+1]*arr[i])%mod;
        long long ans = 0;
        for(int i = 1; i <= n; ++i){
            long long tmp = arr[i]-1;
            tmp = (tmp*previ[i-1])%mod;
            tmp = (tmp*succ[i+1])%mod;
            ans = (ans+tmp)%mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}