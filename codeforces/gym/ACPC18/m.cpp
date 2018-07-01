//http://codeforces.com/gym/101810/problem/M
#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n;
vector < pair<int, pair<int,int> > > ady[100005];
int parent[100005];
int height[100005];
int w1[100005];
int w2[100005]; 
int f[100005][18];

void dfs(int nodo){
    for(pair<int, pair<int,int> > v : ady[nodo]){
        if(v.fst != parent[nodo]){
            parent[v.fst] = nodo;
            height[v.fst] = height[nodo] + 1;
            w1[v.fst] = w1[nodo] + v.snd.fst;
            w2[v.fst] = w2[nodo] + v.snd.snd; 
            dfs(v.fst);
        }
    }
}
int LCA(int u, int v){
    if(height[v]>height[u])
        swap(u,v);  
    for(int i = 17; i >= 0; --i){
        if(height[f[u][i]] >= height[v])
            u = f[u][i];
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

int main(){
    int test;
    scanf("%d", &test);
    height[0] = -1;
    while(test--){
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i) ady[i].clear();
        int sum1 = 0, sum2 = 0;
        int u,v,c1,c2;
        for(int i = 0;i < n-1; ++i){
            scanf("%d%d%d%d", &u,&v,&c1,&c2);
            sum1 += c1;
            sum2 += c2;
            ady[u].pb({v,{c1,c2}});
            ady[v].pb({u,{c2,c1}});
        }
        dfs(1);
        for(int u = 1; u <= n; ++u)
            f[u][0] = parent[u];
        for(int i = 1; i < 18; ++i){
            for(int u = 1; u <= n; ++u){
                f[u][i] = f[f[u][i-1]][i-1];
            }
        }
        int q,x,y;
        scanf("%d", &q);
        while(q--){
            scanf("%d%d",&x,&y);
            int L = LCA(x,y);
            int sum = sum1+sum2-(w1[x]-w1[L])-(w2[y]-w2[L]);
            printf("%d\n",sum);
        }
    }

    return 0;
}