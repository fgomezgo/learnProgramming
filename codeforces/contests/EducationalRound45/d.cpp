#include<bits/stdc++.h>
using namespace std;

int mat[1005][1005];
int n,a,b;


int main(){
    scanf("%d%d%d",&n,&a,&b);
    if(min(a,b) > 1 || (a==1&&b==1&&(n==2||n==3))){
        puts("NO");
        return 0;
    }
    puts("YES");
    bool fl = (a<b);
    if(!fl) swap(a,b);
    for(int i = 0; i < n-b; ++i){
        mat[i][i+1] = 1;
        mat[i+1][i] = 1;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(fl){
                if(i == j)
                    printf("0");
                else
                    printf("%d",1-mat[i][j]);
            }
            else
                printf("%d",mat[i][j]);
        }
        puts("");
    }

    return 0;
}