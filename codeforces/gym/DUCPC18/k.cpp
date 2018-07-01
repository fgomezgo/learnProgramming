//http://codeforces.com/gym/101808/problem/K
#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;
const int N = 1e5+5;
int n,q;
vector < pair<int,int> > ady[N];
int bu, bv, bw;
int parent[N], height[N], visit[N];
long long val[N];
int target = 0;
int f[N][18];

void dfs(int nodo){
    for(pair<int,int> v : ady[nodo]){
        if(parent[nodo] != v.fst){
            if(visit[v.fst] != target){
                visit[v.fst] = target;
                parent[v.fst] = nodo;
                height[v.fst] = height[nodo] + 1;
                val[v.fst] = val[nodo] + (long long)v.snd;
                dfs(v.fst);
            } else{
                bu = nodo;
                bv = v.fst;
                bw = v.snd;
            }
        }
    }
}
int LCA(int u, int v){
    if(height[v] > height[u])
        swap(u,v); 
    for(int i = 17; i >= 0; --i){
        if(height[f[u][i]] >= height[v]){
            u = f[u][i];
        }
    }
    if(u == v) return v;
    for(int i = 17; i >= 0; --i){
        if(f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return parent[u];
}
long long path(int u, int v){
    int L = LCA(u,v);
    return val[u]+val[v]-2*val[L];
}

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d",&n,&q);
        int u,v,w;
        for(int i = 1; i <= n; ++i)
            ady[i].clear();
        for(int i = 1; i <= n; ++i){
            scanf("%d%d%d", &u,&v,&w);
            ady[u].pb({v,w});
            ady[v].pb({u,w});
        }
        ++target;
        height[1] = 1;
        visit[1] = target;
        dfs(1);
        for(int i = 1; i <= n; ++i)
            f[i][0] = parent[i];
        for(int j = 1; j < 18; ++j){
            for(int i = 1; i <= n; ++i){
                f[i][j] = f[f[i][j-1]][j-1];
            }
        }
        int x,y;
        while(q--){
            scanf("%d%d",&x,&y);
            int L = LCA(x,y);
            long long ans = path(x,y);
            ans = min(ans,path(x,bu)+(long long)bw+path(bv,y));
            ans = min(ans,path(x,bv)+(long long)bw+path(bu,y));
            printf("%lld\n",ans);
        }
    }
    return 0;
}