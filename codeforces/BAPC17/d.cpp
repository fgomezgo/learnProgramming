#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define pb push_back
#define ull unsigned long long
const int N = 1e5+5;
vector< pair<int,int> > ady[N];
ull dist[N];
priority_queue< pair<ull,int>, vector<pair<ull,int>>, greater<pair<ull,int>> > Q;
queue<int> cola;
int n,m;
bool visit[N];
int parent[N];
vector<int> res;

void dfs(int nodo){
    if(parent[nodo] != 0)
        dfs(parent[nodo]);
    res.pb(nodo);
}

int main(){
    memset(dist, -1, sizeof dist);
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d",&u,&v,&w);
        ady[u].pb({v,w});
        ady[v].pb({u,w});
    }
    dist[1] = 0;
    Q.push({0,1});
    pair<ull,int> curr;
    while(!Q.empty()){
        curr = Q.top();
        Q.pop();
        int u = curr.snd;
        ull w = curr.fst;
        for(pair<int,int> v: ady[u]){
            ull tot = w+(ull)v.snd;
            if(tot < dist[v.fst]){
                dist[v.fst] = tot;
                Q.push({tot,v.fst});
            }
        }
    }

    res.pb(0);
    visit[0] = true;
    cola.push(0);
    int nodo;
    long long diff;
    while(!cola.empty()){
        nodo = cola.front();
        cola.pop();
        for(pair<int,int> v : ady[nodo]){
            diff = dist[v.fst];
            diff -= (long long)dist[nodo];
            if(!visit[v.fst] && diff != (long long)-v.snd){
                visit[v.fst] = true;
                parent[v.fst] = nodo;
                cola.push(v.fst);
            }
        }
    }
    if(visit[1]){
        dfs(1);
        int len = res.size();
        printf("%d ",len);
        for(int i = 0; i < len; ++i)   
            printf("%d ",res[i]);
        puts("");
    } else 
        puts("impossible");



    return 0;
}