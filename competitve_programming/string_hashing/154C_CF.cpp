//http://codeforces.com/problemset/problem/154/C
//String Hashing

#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

int n,m;
vector< vector<int> > ady;
unsigned long long p = 1000003LL;
//long long mod = 1000000009LL;
map<unsigned long long, long long> mp;


int main(){
    scanf("%d%d",&n,&m);
    ady.resize(n+1);
    int u,v;
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&u,&v);
        ady[u].pb(v);
        ady[v].pb(u);
    }
    for(int i = 1; i <= n; ++i){
        ady[i].pb(i);
        sort(ady[i].begin(),ady[i].end());
        unsigned long long hash1 = 0;
        unsigned long long hash2 = 0;
        unsigned long long tmp1 = 1;
        unsigned long long tmp2 = 1;
        for(auto j : ady[i]){
            //hash1 = (hash1+((unsigned long long)j*tmp1)%mod)%mod;
            //tmp1 = (tmp1*p)%mod;
            hash1 += (unsigned long long)j*tmp1;
            tmp1 *= p;
            if(j == i) continue;
            //hash2 = (hash2+((unsigned long long)j*tmp2)%mod)%mod;
            //tmp2 = (tmp2*p)%mod;
            hash2 += (unsigned long long)j*tmp2;
            tmp2 *= p;
        }
        mp[hash1]++;
        mp[hash2]++;
    }
    
    long long sum = 0;
    for(auto i : mp)
        sum += (i.snd*(i.snd-1LL))/2LL;
    printf("%lld\n",sum);

    return 0;
}