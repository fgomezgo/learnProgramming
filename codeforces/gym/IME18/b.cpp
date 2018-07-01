#include<bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

int w,m,n;
char str[1005][15];
int weight[1005]; 
int dp[1005][2005];
pair<int,int> previ[1005][2005];
int target = 0;

void dfs(pair<int,int> curr,int sum){
    if(curr.fst == 0){
        printf("%d ",sum);
        return;
    }
    if(curr.snd != previ[curr.fst][curr.snd].snd){
        dfs(previ[curr.fst][curr.snd],sum+1);
        printf("%s ",str[curr.fst]);
    } else{
        dfs(previ[curr.fst][curr.snd],sum);
    }
}

int main(){
    scanf("%d%d",&w,&m);
    for(int i = 1; i <= m; ++i){
        scanf("%s%d",str[i],&weight[i]);
    }
    scanf("%d",&n);
    int s;
    queue< pair<int,int> > Q;
    
    while(n--){
        int mini = INT_MAX;
        pair<int,int> pi;
        ++target;
        scanf("%d",&s);
        dp[0][w] = target;
        Q.push({0,w});
        pair<int,int> curr;
        while(!Q.empty()){
            curr = Q.front();
            //cout<<"state: "<<curr.fst<<" "<<curr.snd<<" "<<previ[curr.fst][curr.snd].fst<<" "<<previ[curr.fst][curr.snd].snd<<endl;
            Q.pop();
            if(curr.snd >= (s/2)+(s%2==1)){
                if(curr.snd < mini){
                    mini = curr.snd;
                    pi = curr;
                }
                continue;
            }
            if(curr.fst == m)
                continue;
            if(dp[curr.fst+1][curr.snd] != target){
                dp[curr.fst+1][curr.snd] = target;
                previ[curr.fst+1][curr.snd] = {curr.fst,curr.snd};
                Q.push({curr.fst+1,curr.snd});
            }
            if(dp[curr.fst+1][curr.snd+weight[curr.fst+1]] != target){
                dp[curr.fst+1][curr.snd+weight[curr.fst+1]] = target;
                previ[curr.fst+1][curr.snd+weight[curr.fst+1]] = {curr.fst,curr.snd};
                Q.push({curr.fst+1,curr.snd+weight[curr.fst+1]});
            }
        }
        if(mini == INT_MAX){
            puts("-1");
            continue;
        }
        dfs(pi,0);
        puts("");
    }

    return 0;
}