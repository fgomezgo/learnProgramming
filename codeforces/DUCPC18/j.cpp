#include<bits/stdc++.h>
using namespace std;

int l1,r1,p1,d1;
int l2,r2,p2,d2;
int k;
int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d%d",&l1,&r1,&p1,&d1);
        scanf("%d%d%d%d",&l2,&r2,&p2,&d2);
        scanf("%d",&k);

        if(d1 == 0) --d1;
        if(d2 == 0) --d2;
        int sum = 0;
        for(int i = 0; i <= k; ++i){
            if(p1 == p2)
                ++sum;
            p1 += d1;
            if(p1 > r1 || p1 < l1){
                p1 -= d1;
                d1 *= -1;
                p1 += d1;
            }
            p2 += d2;
            if(p2 > r2 || p2 < l2){
                p2 -= d2;
                d2 *= -1;
                p2 += d2;
            }
        }
        printf("%d\n",sum);

    }

    return 0;
}