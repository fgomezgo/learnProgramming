#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
char mat[1005][1005];
int parent[1005];
bool visit[1005];
vector <int> res;
int cont = 1;
void dfs(int nodo){
    for(int i = 0; i < n; ++i){
        if(mat[nodo][i] == '1' && !visit[i]){
            visit[i] = true;
            ++cont;
            parent[i] = nodo;
            dfs(i);
        }
    }
    res.pb(nodo);
}


int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%s",mat[i]);
    visit[0] = true;
    dfs(0);
    if(cont != n){
        puts("impossible");
        return 0;
    }
    for(int v : res)
        printf("%d ",v);
    puts("");
    return 0;
}