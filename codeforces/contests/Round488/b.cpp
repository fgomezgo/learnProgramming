#include<bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
const int N = 1e5+5;
int n,k;
long long res[N];
pair< int,pair<int,int> > arr[N];
priority_queue< int, vector<int>, greater<int> > Q;
long long sum = 0;
void add(pair< int,pair<int,int> > p){
    if(k == 0) return;
    if(Q.size() == k){
        if(p.snd.fst <= Q.top())
            return;
        sum -= Q.top();
        Q.pop();
    }
    sum += (long long)p.snd.fst;
    Q.push(p.snd.fst);
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&arr[i].fst);
        arr[i].snd.snd = i;
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d",&arr[i].snd.fst);
    }
    sort(arr+1,arr+n+1);
    int ins = 1;
    for(int i = 1; i <= n; ++i){
        while(arr[i].fst > arr[ins].fst)
            add(arr[ins++]);
        res[arr[i].snd.snd] = sum+(long long)arr[i].snd.fst; 
    } 
    for(int i = 1; i <= n; ++i)
        printf("%lld ",res[i]); puts("");
    return 0;
}