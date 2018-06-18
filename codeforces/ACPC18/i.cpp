#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int x,n;
        scanf("%d%d", &x, &n);
        int div = x/n;
        if(div == 0){
            puts("-1");
            continue;
        }
        int mod = x%n;
        for(int i = 0; i < n-mod; ++i)
            printf("%d ",div);
        for(int i = 0; i < mod; ++i)
            printf("%d ",div+1);
        puts("");
    }
    return 0;
}