//http://codeforces.com/contest/990/problem/F
#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int N = 2e5+5;
int n;
int arr[N];
int m;
vector< pair<int, int > > ady[N];
int forest[N], parent[N], rank_[N], val[N];

int belong(int nodo){
    if(forest[nodo] != nodo)
        return forest[nodo] = belong(forest[nodo]);
    return nodo;
}
bool DSU(int u, int v){
    int pu = belong(u);
    int pv = belong(v);
    if(pu == pv) return false;
    if(rank_[pu] < rank_[pv])
        swap(pu,pv);
    forest[pv] = pu;
    if(rank_[u] == rank_[v])
        rank_[pu]++;
    return true;
}
void dfs(int nodo){
    int sum = 0, pi = 0;
    for(pair<int,int> v : ady[nodo]){
        if(v.fst != parent[nodo]){
            parent[v.fst] = nodo;
            dfs(v.fst);
            if(v.snd > 0)
                sum -= val[v.snd];
            else
                sum += val[abs(v.snd)];
        } else
            pi = v.snd;
    }
    int diff = sum-arr[nodo];
    if(pi > 0)
        val[pi] = diff;
    else
        val[abs(pi)] = -diff;

}

int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    if(sum != 0){
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    scanf("%d", &m);
    int u,v;
    for(int i = 1; i <= n; ++i)
        forest[i] = i;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d",&u,&v);
        if(DSU(u,v)){
            ady[u].pb({v,i});
            ady[v].pb({u,-i});
        }
    }
    int maxD = -1;
    int root = 0;
    for(int i = 1; i <= n; ++i){
        if((int)ady[i].size() > maxD){
            maxD = ady[i].size();
            root = i;
        }
    }
    dfs(root);
    for(int i = 1; i <= m; ++i)
        printf("%d\n",val[i]);
    
    return 0;
}

