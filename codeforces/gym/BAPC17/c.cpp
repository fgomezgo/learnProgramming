#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 5e5+5;
int n;
long long arr[N];
vector<long long> D[2];
set<long long> res;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld",&arr[i]);
    D[0].pb(arr[0]);
    res.insert(arr[0]);
    for(int i = 1; i < n; ++i){
        for(long long v : D[0]){
            long long g = __gcd(arr[i],v); 
            D[1].pb(g);
            res.insert(g);
        }
        D[1].pb(arr[i]);
        res.insert(arr[i]);
        D[0] = D[1];
        D[1].clear();
    }
    printf("%d\n",(int)res.size());
    return 0;
}