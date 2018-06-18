#include<bits/stdc++.h>
using namespace std;

int n;
char a[100005];
char b[100005];

int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%s%s",a,b);
        n = strlen(a);
        int sum = 0;
        bool fl = true;
        for(int i = 0; i <= n/2; ++i){
            char a1 = a[i], a2 = a[n-1-i], b1 = b[i], b2 = b[n-1-i];
            if(sum % 2 == 0){
                if(a1 == b1 && a2 == b2){

                } else if(a1 == b2 && a2 == b1){
                    ++sum;
                } else{
                    fl = false;
                    break;
                }
            } else{
                if(a1 == b2 && a2 == b1){

                } else if(a1 == b1 && a2 == b2){
                    ++sum;
                } else{
                    fl = false;
                    break;
                }
            }
        }
        if(!fl) puts("-1");
        else printf("%d\n",sum);

    }    

    return 0;
}