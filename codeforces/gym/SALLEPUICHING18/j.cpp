//https://codeforces.com/gym/101807/problem/J
#include<bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
#define pb push_back

const int N = 5e5+5;
int n,Q;
vector < pair<int, pair<int,int> > > ady[N];
int parent[N];
int height[N];
int renum[N];
int edge[N];
pair<int, pair<int,int> > heavy[N];
int path[N]; 
vector <int> head;
long long tree[(1<<20)+5];
//ST
void update(int nodo, int ini, int fin, int idx, long long val){
    if(ini == fin){
        tree[nodo] = val;
        return;
    }
    int mid = (ini+fin)>>1;
    if(idx <= mid)
        update(nodo<<1,ini,mid,idx,val);
    else
        update(nodo<<1|1,mid+1,fin,idx,val);
    tree[nodo] = tree[nodo<<1]+tree[nodo<<1|1];
}
long long query(int nodo, int ini, int fin, int b, int e){
    if(b>e)
        return 0;
    if(ini == b && fin == e)
        return tree[nodo];
    int mid = (ini+fin)>>1;
    return query(nodo<<1,ini,mid,b,min(e,mid))+query(nodo<<1|1,mid+1,fin,max(b,mid+1),e);
}
//HDL
int dfs(int nodo){
    int sum = 1;
    int maxi = INT_MIN;
    for(pair<int, pair<int,int> > v : ady[nodo]){
        if(v.fst != parent[nodo]){
            parent[v.fst] = nodo;
            height[v.fst] = height[nodo]+1;
            int result = dfs(v.fst);
            sum += result;
            if(result > maxi){
                maxi = result;
                heavy[nodo] = v;
            }
        }
    }
    return sum;
}
int pos = 1;
int nn = 1, ne = 1;
void hdl(int nodo){
    renum[nodo] = nn++;
    if(path[nodo] == 0){
        path[nodo] = pos;
        head.pb(nodo);
        ++pos;
    } 
    if(heavy[nodo].fst != 0){
        path[heavy[nodo].fst] = path[nodo];
        edge[heavy[nodo].snd.snd] = ne++;
        update(1,1,n-1,edge[heavy[nodo].snd.snd],(long long)heavy[nodo].snd.fst);
        hdl(heavy[nodo].fst);
    }
    for(pair<int, pair<int,int> > v : ady[nodo]){
        if(v.fst != parent[nodo] && v != heavy[nodo]){
            edge[v.snd.snd] = ne++;
            update(1,1,n-1,edge[v.snd.snd],(long long)v.snd.fst);
            hdl(v.fst);
        }
    }
}
long long dist(int u, int v){
    long long sum = 0;
    while(path[u] != path[v]){
        if(height[head[path[u]]] < height[head[path[v]]]){
            swap(u,v);
        }
        sum += query(1,1,n-1,max(1,renum[head[path[u]]]-1),renum[u]-1);
        u = parent[head[path[u]]];
    }
    if(renum[u] < renum[v])
        swap(u,v);
    sum += query(1,1,n-1,renum[v],renum[u]-1);
    return sum;
}


int main(){
    scanf("%d",&n);
    int u,v,w;
    for(int i = 1; i <= n-1; ++i){
        scanf("%d%d%d",&u,&v,&w);
        ady[u].pb({v,{w,i}});
        ady[v].pb({u,{w,i}});
    }
    height[1] = 1;
    dfs(1);
    head.pb(0);
    hdl(1);
    scanf("%d",&Q);
    int t;
    while(Q--){
        scanf("%d", &t);
        if(t == 2){
            int i,l;
            scanf("%d%d",&i,&l);
            update(1,1,n-1,edge[i],(long long)l);
        } else{
            int u,v;
            scanf("%d%d",&u,&v);
            long long d = dist(u,v);
            if(d&1){
                puts("WE NEED BLACK PANDA");
            } else
                puts("JAKANDA FOREVER");
        }
    }

    return 0;
}