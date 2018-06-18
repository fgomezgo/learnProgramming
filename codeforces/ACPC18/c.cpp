#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);
    int n,m;
    while(test--){
        scanf("%d",&n);
        m = n-1;
        int sol = __builtin_popcount(n^m);
        printf("%d\n",sol);

    }
    return 0;
}