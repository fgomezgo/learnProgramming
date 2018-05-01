//http://codeforces.com/problemset/problem/154/C
//String Hashing

#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define LL long long
using namespace std;

int n,m;
vector< vector<int> > ady;
LL p1 = 1000003LL;
LL p2 = 1000033LL;
LL mod = 1000000009LL;
map< pair<LL,LL> , LL> mp;
pair<LL,LL> pot[1000005];

int main(){
    scanf("%d%d",&n,&m);
    ady.resize(n+1);
    int u,v;
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&u,&v);
        ady[u].pb(v);
        ady[v].pb(u);
    }
    int maxLen = 0;
    for(int i = 1; i <= n; ++i)
        maxLen = max(maxLen, (int)ady[i].size());
    
    pot[0] = {1,1};
    for(int i = 1; i <= maxLen; ++i){
        pot[i].fst = (pot[i-1].fst*p1)%mod;
        pot[i].snd = (pot[i-1].snd*p2)%mod;
    }
    for(int i = 1; i <= n; ++i){
        ady[i].pb(i);
        sort(ady[i].begin(),ady[i].end());
        pair<LL,LL> hash1 = {0,0};
        pair<LL,LL> hash2 = {0,0};
        int c1 = 0, c2 = 0;
        for(auto j : ady[i]){
            hash1 = {(hash1.fst+((LL)j*pot[c1].fst)%mod)%mod,(hash1.snd+((LL)j*pot[c1].snd)%mod)%mod};
            ++c1;
            if(j == i) continue;
            hash2 = {(hash2.fst+((LL)j*pot[c2].fst)%mod)%mod,(hash2.snd+((LL)j*pot[c2].snd)%mod)%mod};
            ++c2;
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