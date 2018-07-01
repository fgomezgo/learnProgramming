#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5+5;
int n,m;
vector <int> ady[N];
int parent[N];
int dp[N][2];

void dfs_parent(int nodo){
    for(int v: ady[nodo]){
        if(v != parent[nodo]){
            parent[v] = nodo;
            dfs_parent(v);
        }
    }
}

int dfs(int nodo, int c){
    int &ans = dp[nodo][c];
    if(ans != -1) return ans;
    if(c == 0)
        ans = 0;
    else
        ans = 1;
    for(int v: ady[nodo]){
        if(v != parent[nodo]){
            if(c == 0)
                ans += max(dfs(v,0),dfs(v,1));
            else
                ans += dfs(v,0);
        }
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    assert(m == n-1);
    memset(dp,-1,sizeof dp);
    int u,v;
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&u,&v);
        ady[u].pb(v);
        ady[v].pb(u);
    }
    dfs_parent(1);
    printf("%d\n",max(dfs(1,0),dfs(1,1)));
    return 0;
}