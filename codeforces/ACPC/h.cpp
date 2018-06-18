#include<bits/stdc++.h>
using namespace std;
int arr[2005];

int main(){
    int test;
    scanf("%d", &test);
    int n;
    
    while(test--){
        scanf("%d", &n);
        for(int i = 1; i <= 2*n; ++i){
            scanf("%d", &arr[i]);
        }
        int sol = -1;
        for(int i = 1; i <= n; ++i){
            sol = max(sol,arr[i]+arr[2*n-i+1]);
        }
        printf("%d\n",sol);
    }


    return 0;
}