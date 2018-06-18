#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n,q;
int forest[100005];
int parent[100005];
vector< pair<int,int> > ady[100005];
int black[100005];
pair<int,long long> black_dist[100005];
int euler_node[100005];
int euler_node_inv[100005];
int euler_is[100005];
int eulerian[200005];
int eulerian_sz;
int tree[(1<<19)+5];
long long ring[100005];
long long acum[100005];

int pnt(int nodo){
    if(nodo != forest[nodo])
        return forest[nodo] = pnt(forest[nodo]);
    return nodo;
}
void euler_dfs(int nodo){
    eulerian[eulerian_sz] = euler_node[nodo];
    euler_is[nodo] = eulerian_sz++;
    for(pair<int,int> v : ady[nodo]){
        if(v.fst != parent[nodo]){
            euler_dfs(v.fst);
            eulerian[eulerian_sz] = euler_node[nodo];
            euler_is[nodo] = eulerian_sz++;
        }
    }
}
void build(int nodo, int ini, int fin){
    if(ini == fin){
        tree[nodo] = eulerian[ini];
        return;
    }
    int mid = (ini+fin)>>1;
    build(nodo<<1,ini,mid);
    build(nodo<<1|1,mid+1,fin);
    tree[nodo] = min(tree[nodo<<1],tree[nodo<<1|1]);
}
int query(int nodo, int ini, int fin, int b, int e){
    if(b > e)
        return INT_MAX;
    if(ini == b && fin == e)
        return tree[nodo];
    int mid = (ini+fin)>>1;
    return min(query(nodo<<1,ini,mid,b,min(mid,e)),query(nodo<<1|1,mid+1,fin,max(b,mid+1),e));
}
long long look_pnt(int nodo){
    for(pair<int,int> v : ady[nodo]){
        if(parent[nodo] == v.fst)
            return (long long)v.snd;
    }

}
void dfs_acum(int nodo){
    for(pair<int,int> v : ady[nodo]){
        if(parent[nodo] != v.fst){
            acum[v.fst] = acum[nodo] + (long long)v.snd;
            dfs_acum(v.fst);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d",&n,&q);
        memset(black,0,sizeof black);
        memset(black_dist,0,sizeof black_dist);
        for(int i = 1; i <= n; ++i){
            forest[i] = i;
            ady[i].clear();
        }
        int u,v,w,bu,bv,bw;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d%d",&u,&v,&w);
            ady[u].pb({v,w});
            ady[v].pb({u,w});
            int pu = pnt(u);
            int pv = pnt(v);
            if(pu != pv){
                if(pu < pv){
                    forest[pv] = pu;
                    parent[v] = u;
                } else{
                    forest[pu] = pv;
                    parent[u] = v;
                }
            } else{
                //black nodes
                bu = u;
                bv = v;
                bw = w;
                ady[u].pop_back();
                ady[v].pop_back();
            }
        }
        queue <int> Q;
        int cnt = 1;
        euler_node[1] = cnt;
        euler_node_inv[cnt++] = 1;
        Q.push(1);
        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();
            for(pair<int,int> v: ady[curr]){
                if(v.fst != parent[curr]){
                    euler_node[v.fst] = cnt;
                    euler_node_inv[cnt++] = v.fst;
                    Q.push(v.fst);
                }
            }
        }
        eulerian_sz = 0;
        euler_dfs(1);
        build(1,0,eulerian_sz-1);
        //LCA
        int lca = query(1,0,eulerian_sz-1,min(euler_is[bu],euler_is[bv]),max(euler_is[bu],euler_is[bv]));
        lca = euler_node_inv[lca];
        cnt = 1;
        ring[cnt] = look_pnt(bu);
        black[bu] = cnt++;
        int tmp_node = bu;
        while(parent[tmp_node] != lca){
            ring[cnt] = look_pnt(parent[tmp_node]);
            black[parent[tmp_node]] = cnt++;
            tmp_node = parent[tmp_node];
        }
        stack < pair<int,int> > simple;
        simple.push({bv,look_pnt(bv)});
        tmp_node = bv;
        while(parent[tmp_node] != lca){
            simple.push({parent[tmp_node],look_pnt(parent[tmp_node])});
            tmp_node = parent[tmp_node];
        }
        simple.push({lca,0});
        while(!simple.empty()){
            pair<int,int> curr = simple.top();
            simple.pop();
            if(curr.fst != lca)
                ring[cnt-1] = (long long)curr.snd;
            black[curr.fst] = cnt++;
        }
        --cnt;
        ring[cnt] = bw;
        for(int i = 1; i <= cnt; ++i)
            ring[i] += ring[i-1];
        for(int i = 1; i <= n; ++i){
            if(black[i] != 0){
                black_dist[i] = {black[i],0};
                Q.push(i);
                while(!Q.empty()){
                    int curr = Q.front();
                    Q.pop();
                    for(pair<int,int> v : ady[curr]){
                        if(black[v.fst] == 0 && black_dist[v.fst].fst == 0){
                            black_dist[v.fst] = {black[i],(long long)(black_dist[curr].snd+v.snd)};
                            Q.push(v.fst);
                        }
                    }
                }
            }
        }
        dfs_acum(1);

        int x,y;
        while(q--){
            scanf("%d%d",&x,&y);
            long long res = 0;
            if(black_dist[x].fst == black_dist[y].fst){
                lca = query(1,0,eulerian_sz-1,min(euler_is[x],euler_is[y]),max(euler_is[x],euler_is[y]));
                lca = euler_node_inv[lca];
                res = acum[x]+acum[y]-2*acum[lca];
            } else{
                res = black_dist[x].snd+black_dist[y].snd;
                int r1 = min(black_dist[x].fst,black_dist[y].fst);
                int r2 = max(black_dist[x].fst,black_dist[y].fst);
                //cout<<"bx "<<black_dist[x].fst<<endl;
                //cout<<"by "<<black_dist[y].fst<<endl;
                //cout<<"r "<<r1<<" "<<r2<<endl;
                long long m1 = ring[r2-1]-ring[r1-1];
                long long m2 = ring[cnt] - m1;
                //cout<<"m "<<m1<<" "<<m2<<endl;
                res += min(m1,m2);
            }
            printf("%lld\n",res);
        }
        
    }
    return 0;
}