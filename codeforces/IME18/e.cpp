#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;
const int N = 1005;
int n;
vector< pair< int, pair<int,int> > > arr;
vector<int> ady[N];
int forest[N], rankin[N];
int parent[N];

int find(int nodo){
    if(forest[nodo] != nodo)
        return forest[nodo] = find(forest[nodo]);
    return nodo;
}
bool dsu(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(pu == pv) return false;
    if(rankin[pu] < rankin[pv])
        swap(pu,pv);
    forest[pv] = pu;
    if(rankin[pu] == rankin[pv])
        rankin[pu]++;
    return true;
}
void dfs(int nodo){
    for(int v : ady[nodo]){
        if(v != parent[nodo]){
            parent[v] = nodo;
            dfs(v);
        }
    }
}

int main(){
    scanf("%d",&n);
    int num;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            scanf("%d", &num);
            arr.pb({num,{i,j}});
        }
    }
    
    sort(arr.begin(),arr.end());
    
    for(int i = 1; i <= n; ++i){
        forest[i] = i;
    }
    int len = arr.size();
    int sum = 0;
    for(int i = len-1; i >= 0; --i){
        int u = arr[i].snd.fst;
        int v = arr[i].snd.snd;
        if(dsu(u,v)){
            ady[u].pb(v);
            ady[v].pb(u);
            sum += arr[i].fst;
        }
    }

    dfs(1);

    printf("%d\n",sum);
    for(int i = 2; i <= n; ++i)
        printf("%d\n",parent[i]);

    return 0;
}
