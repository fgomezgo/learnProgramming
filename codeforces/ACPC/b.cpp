#include<bits/stdc++.h>
using namespace std;
long long arr[1005];

int main(){
    int test;
    scanf("%d", &test);
    long long x,n;
    while(test--){
        scanf("%lld%lld",&x,&n);
        if(n == 1){
            printf("%lld\n",x);
            continue;
        }
        memset(arr,0,sizeof arr);
        for(int i = 1; i <= n; ++i){
            if(x){
                --x;
                arr[i] = 1;
            }
        }
        if(!x){
            for(int i = 1; i <= n; ++i)
                printf("%lld ", arr[i]);
            puts("");
            continue;
        }
        long long div = x/(long long)(n-1);
        arr[1] += (div+1)/2;
        arr[n] += div/2;
        for(int i = 2; i < n; ++i)
            arr[i] += div;
        long long mod = x%(long long)(n-1);
        if(div % 2 == 0){
            for(int i = n-1; i >= 1; --i){
                if(mod){
                    --mod;
                    ++arr[i];
                }
            }
        } else{
            for(int i = 2; i <= n; ++i){
                if(mod){
                    --mod;
                    ++arr[i];
                }
            }
        }
        for(int i = 1; i <= n; ++i)
                printf("%lld ", arr[i]);
        puts("");
    }

    return 0;
}