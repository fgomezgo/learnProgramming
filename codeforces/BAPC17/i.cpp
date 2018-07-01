#include<bits/stdc++.h>
using namespace std;

int p,q;
int dp[101][101][2][2];
bool visit[101][101][2][2];

int dfs(int row, int col, int b, int nw){
    int &ans = dp[row][col][b][nw];
    if(visit[row][col][b][nw])
        return ans;
    visit[row][col][b][nw] = true;
    if(row == 0 || col == 0)
        return ans = 0;
    if(b == 0){
        ans = INT_MIN;
        for(int i = 1; i <= col; ++i){
            int offset = 0;
            int nnw;
            if(row%2 == 1 && i%2 == 1){
                if(nw)  offset = 1;
                else    offset = -1;
            }
            if(i%2 == 1)
                nnw = 1-nw;
            else
                nnw = nw;
            ans = max(ans,offset+dfs(row,col-i,1-b,nnw));
        }
        return ans;
    }
    if(b == 1){
        ans = INT_MAX;
        for(int i = 1; i <= row; ++i){
            int offset = 0;
            if(col%2 == 1 && i%2 == 1){
                if(nw)  offset = -1;
                else    offset = 1;
            }
            ans = min(ans,offset+dfs(row-i,col,1-b,nw));
        }
        return ans;
    }
}


int main(){
    scanf("%d%d",&p,&q);
    printf("%d\n",dfs(p,q,0,1));/*
    for(int i = 0; i <= p; ++i){
        for(int j = 0; j <= q; ++j){
            for(int b = 0; b < 2; ++b){
                for(int nw = 0; nw < 2; ++nw){
                    cout<<i<<" "<<j<<" "<<b<<" "<<nw<<": "<<dp[i][j][b][nw]<<endl;
                }
            }
        }
    }*/
    return 0;
}