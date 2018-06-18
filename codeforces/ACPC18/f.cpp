#include<bits/stdc++.h>
using namespace std;
int criva[1000005];
int n;
int arr[100005];

int main(){
    int test;
    scanf("%d", &test);

    while(test--){
        memset(criva,0,sizeof criva);
        scanf("%d", &n);
        int maxi = -1;
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
            maxi = max(maxi,arr[i]);
        }
        sort(arr,arr+n);
        for(int i = 0; i < n; ++i){
            if(criva[arr[i]] == 0){
                for(int j = arr[i]; j <= maxi; j += arr[i]){
                    if(criva[j] == 0)
                        criva[j] = arr[i];
                }
            } else{
                arr[i] = criva[arr[i]];
            }
        }
        long long sum = 0;
        for(int i = 0; i < n; ++i){
            sum += (long long)arr[i];
        }
        printf("%lld\n",sum);
    }

    return 0;
}