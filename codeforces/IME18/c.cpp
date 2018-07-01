#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n, a;
char str[25][25][25];
int ady[25][25];
int dp[(1<<18)+5][25];
pair<int,int> previ[(1<<18)+5][25];
int b[25];
bool restart[25][25];

int main(){
    scanf("%d%d", &n, &a);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 21; ++j)
            scanf("%s",str[i][j]);
    }
    memset(dp,-1,sizeof dp);
    queue < pair<int,int> > Q;
    for(int i = 0; i < n; ++i){
        for(int ni = 0; ni < 21; ++ni){
            for(int nj = 0; nj < 21; ++nj){
                if(str[i][ni][nj] == '1')
                    ++b[i];
            }
        }
        dp[(1<<i)][i] = b[i];
        Q.push({(1<<i),i});
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                int sum = 0;
                for(int ni = 0; ni < 21; ++ni){
                    for(int nj = 0; nj < 21; ++nj){
                        if(str[j][ni][nj] != str[i][ni][nj])
                            ++sum;
                    }
                }
                if(a+b[j] < sum)
                    restart[i][j] = true;
                ady[i][j] = min(a+b[j],sum);
            }
        }
    }
    
    pair<int,int> curr;
    int mini = INT_MAX;
    vector <int> res;
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        int mask = curr.fst;
        int i = curr.snd;
        if(mask == (1<<n)-1){
            if(dp[mask][i] < mini){
                mini = dp[mask][i];
                res.clear();
                int nxt = i;
                while(mask){
                    res.pb(nxt);
                    pair<int,int> p = previ[mask][nxt];
                    if(restart[p.snd][nxt])
                        res.pb(-1);
                    mask = p.fst;
                    nxt = p.snd;
                }
            }
            continue;
        }
        for(int j = 0; j < n; ++j){
            if((mask&(1<<j))==0){
                int nmask = mask | (1<<j);
                if(dp[nmask][j] == -1)
                    Q.push({nmask,j});
                if(dp[nmask][j] == -1 || (dp[mask][i]+ady[i][j])<dp[nmask][j]){
                    dp[nmask][j] = dp[mask][i]+ady[i][j];
                    previ[nmask][j] = {mask,i};
                }
            }
        }

    }
    printf("%d\n",mini);
    int len = res.size();
    bool one = false;
    for(int i = len-1; i >= 0; --i){
        if(res[i] == -1){
            if(one)
                puts("*");
        }
        else{
            one = true;
            printf("%d\n",res[i]+1);
        }
    }  
    return 0;
}