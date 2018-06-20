#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n,m,a,b;
    scanf("%lld%lld%lld%lld", &n,&m,&a,&b);
    long long mod = n%m;
    long long ans = min(mod*b,(m-mod)*a);
    printf("%lld\n",ans);

    return 0;
}