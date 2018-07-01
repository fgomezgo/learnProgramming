#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fst first
#define snd second
const int N = 5e5+5;
int n;
vector< pair<int, pair<int,int> > > ady[N];
pair<int,int> parent[N];
pair< int,pair<int,int> > cant[N]; //max son and weight
int path[N]; //path belongs
pair<int,int> p_path[N]; //parent and w of path
int height[N];
int renum[N]; //node renumeration
int edge[N]; //remap from i to nn
long long tree[(1<<20)+5];

void update(int nodo, int ini, int fin, int pos, long long val){
    if(ini == fin){
        tree[nodo] = val;
        return;
    }
    int mid = (ini+fin)>>1;
    if(pos <= mid)
        update(nodo<<1,ini,mid,pos,val);
    else
        update(nodo<<1|1,mid+1,fin,pos,val);
    tree[nodo] = tree[nodo<<1]+tree[nodo<<1|1];
}
long long query(int nodo, int ini, int fin, int b, int e){
    if(b > e)
        return 0LL;
    if(ini == b && fin == e)
        return tree[nodo];
    int mid = (ini+fin)>>1;
    return query(nodo<<1,ini,mid,b,min(mid,e))+query(nodo<<1|1,mid+1,fin,max(b,mid+1),e);
}

int dfs(int nodo){
    int sum = 1;
    int maxi = INT_MIN;
    for(pair< int,pair<int,int> > v : ady[nodo]){
        if(v.fst != parent[nodo].fst){
            parent[v.fst] = make_pair(nodo,v.snd.fst);
            height[v.fst] = height[nodo]+1;
            int tmp = dfs(v.fst);
            sum += tmp;
            if(tmp > maxi){
                maxi = tmp;
                cant[nodo] = v;
            }
        }
    }
    return sum;
}

int pos = 1;
int nn = 1;

void hdl(int nodo){
    renum[nodo] = nn++;
    if(path[nodo] == 0){
        path[nodo] = pos;
        p_path[pos] = {nodo,parent[nodo].snd};
        ++pos;
    }
    if(cant[nodo].fst != 0){
        path[cant[nodo].fst] = path[nodo];
        update(1,1,n,renum[nodo],cant[nodo].snd.fst);
        edge[cant[nodo].snd.snd] = renum[nodo];
        hdl(cant[nodo].fst);
    }
    for(pair< int,pair<int,int> > v : ady[nodo]){
        if(v.fst != parent[nodo].fst && v.fst != cant[nodo].fst){
            hdl(v.fst);
        }
    }
}

long long dist(int u, int v){
    long long sum = 0;
    while(path[u] != path[v]){
        if(height[p_path[path[u]].fst] < height[p_path[path[v]].fst])
            swap(u,v);
        sum += query(1,1,n,renum[p_path[path[u]].fst],renum[u]-1);
        sum += p_path[path[u]].snd;
        u = parent[p_path[u].fst].fst;
    }
    if(u > v)
        swap(u,v);
    sum += query(1,1,n,renum[u],renum[v]-1);
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
    hdl(1);

    int Q;
    scanf("%d", &Q);
    int t;
    while(Q--){
        scanf("%d",&t);
        int i,l;
        if(t == 2){
            scanf("%d%d",&i,&l);
            update(1,1,n,edge[i],l);
        }
        if(t == 1){
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