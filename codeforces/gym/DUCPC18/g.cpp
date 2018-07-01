#include<bits/stdc++.h>
using namespace std;

int arr[100005];
int G[100005];
int L[100005];
int n,x,y;

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d",&n,&x,&y);
        for(int i = 0; i < n; ++i)
            scanf("%d",&arr[i]);
        if(n == 1){
            if(x != y){
                puts("-1");
                continue;
            }
            if(x == arr[0]){
                puts("0");
                continue;
            }
            puts("1");
            continue;
        }
        if(y%x != 0){
            puts("-1");
            continue;
        }
        int cont = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i]%x == 0 && y%arr[i] == 0){
                G[i] = arr[i]/x;
                L[i] = y/arr[i];
            } else{
                ++cont;
            }
        }
        if(cont >= 2){
            printf("%d\n",cont);
            continue;
        }
        int G1 = __gcd(G[0],G[1]);
        int L1 = __gcd(L[0],L[1]);
        for(int i = 2; i < n; ++i){
            G1 = __gcd(G1,G[i]);
            L1 = __gcd(L1,L[i]);
        }
        if(G1 == 1 && L1 == 1){
            printf("%d\n",cont);
            continue;
        }
        if(G1 != 1 && L1 != 1){
            puts("2");
            continue;
        }
        puts("1");
    }
    return 0;
}