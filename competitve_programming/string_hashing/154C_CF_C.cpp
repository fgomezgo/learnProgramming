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
map<unsigned long long, long long> mp;
unsigned long long pot[1000005];

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
    pot[0] = 1;
    for(int i = 1; i <= maxLen; ++i)
        pot[i] = pot[i-1]*p;

    for(int i = 1; i <= n; ++i){
        ady[i].pb(i);
        sort(ady[i].begin(),ady[i].end());
        unsigned long long hash1 = 0;
        unsigned long long hash2 = 0;
        int c1 = 0, c2 = 0;
        for(auto j : ady[i]){
            hash1 += (unsigned long long)j*pot[c1];
            ++c1;
            if(j == i) continue;
            hash2 += (unsigned long long)j*pot[c2];
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