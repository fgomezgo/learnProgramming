#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    scanf("%d", &test);

    while(test--){
        int n,m;
        scanf("%d%d", &n,&m);
        if(m>n)
            swap(n,m);
        if(m == 1 && n != 1){
            printf("%d\n",n-1);
            continue;
        }
        
        long long sum = ((n+1)/2) * (m/2+(m/2 != 0)) + (m/2) * ((n+1)/2+((n+1)/2 != 0));
        /*
        for(int i = 0;i <= m; ++i){
            if(i%2 == 0){
                sum += (long long)(n/2);
            } else{
                sum += (long long)((n+1)/2);
            }
        } */
        printf("%lld\n",sum);
    }

    return 0;
}