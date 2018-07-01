//http://acm.timus.ru/problem.aspx?space=1&num=1553
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fst first
#define snd second
const int N = 1e5+5;
int n,Q;
vector<int> ady[N];
int parent[N];
int height[N];
int path[N];
int heavy[N];
int renum[N];
int tree[(1<<18)+5];
vector <int> head; 

//Segment Tree
void update(int nodo, int ini, int fin, int pos, int val){
    if(ini == fin){
        tree[nodo] += val;
        return;
    }
    int mid = (ini+fin)>>1;
    if(pos <= mid)
        update(nodo<<1,ini,mid,pos,val);
    else
        update(nodo<<1|1,mid+1,fin,pos,val);
    tree[nodo] = max(tree[nodo<<1],tree[nodo<<1|1]);
}
int query(int nodo, int ini, int fin, int b, int e){
    if(b > e){
        return INT_MIN;
    }
    if(ini == b && fin == e){
        return tree[nodo];
    }
    int mid = (ini+fin)>>1;
    return max(query(nodo<<1,ini,mid,b,min(mid,e)),query(nodo<<1|1,mid+1,fin,max(mid+1,b),e));
}

//HDL
int dfs(int nodo){
    int sum = 1;
    int maxi = INT_MIN;
    for(int v : ady[nodo]){
        if(v != parent[nodo]){
            parent[v] = nodo;
            height[v] = height[nodo]+1;
            int result = dfs(v);
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
int nn = 1;
void hdl(int nodo){
    renum[nodo] = nn++;
    if(path[nodo] == 0){
        path[nodo] = pos;
        head.pb(nodo);
        ++pos;
    }
    if(heavy[nodo] != 0){
        path[heavy[nodo]] = path[nodo];
        hdl(heavy[nodo]);
    }
    for(int v : ady[nodo]){
        if(v != parent[nodo] && v != heavy[nodo]){
            hdl(v);
        }
    }
}
int maxVal(int u, int v){
    int maxi = INT_MIN;
    while(path[u] != path[v]){
        if(height[head[path[u]]] < height[head[path[v]]]){
            swap(u,v);
        }
        maxi = max(maxi,query(1,1,n,renum[head[path[u]]],renum[u]));
        u = parent[head[path[u]]];
    }
    if(renum[u] > renum[v])
        swap(u,v);
    maxi = max(maxi,query(1,1,n,renum[u],renum[v]));
    return maxi;
}

int main(){
    scanf("%d",&n);
    int u,v;
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d",&u,&v);
        ady[u].pb(v);
        ady[v].pb(u);
    }
    height[1] = 1;
    dfs(1);
    head.pb(0);
    hdl(1);
    scanf("%d",&Q);
    char str[5];
    while(Q--){
        scanf("%s",str);
        if(str[0] == 'G'){
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",maxVal(u,v));
        } else{
            int u, val;
            scanf("%d%d",&u,&val);
            update(1,1,n,renum[u],val);
        }
    }
    return 0;
}