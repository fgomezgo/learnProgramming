//http://codeforces.com/problemset/problem/154/C
//String Hashing

#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define pb push_back
#define fst first
#define snd second
using namespace std;
//using namespace boost::multiprecision;


int n,m;
vector< vector<int> > ady;
__int128 p =    __int128(1000003);
__int128 mod =  __int128(2305843009213693951);
__int128 pot[1000005];

map<__int128, long long> mp;

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
        pot[i] = (pot[i-1]*p)%mod;

    for(int i = 1; i <= n; ++i){
        ady[i].pb(i);
        sort(ady[i].begin(),ady[i].end());
        __int128 hash1 = 0;
        __int128 hash2 = 0;
        int c1 = 0, c2 = 0;
        for(auto j : ady[i]){
            hash1 = (hash1+((__int128)j*pot[c1])%mod)%mod;
            ++c1;
            if(j == i) continue;
            hash2 = (hash2+((__int128)j*pot[c2])%mod)%mod;
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