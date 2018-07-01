#include<bits/stdc++.h>
using namespace std;

int n;
int arr[20];

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int sum[2];
    sum[0] = sum[1] = 0;
    int idx = 0;
    for(int i = n-1; i >= 0; --i){
        sum[idx] += arr[i];
        idx = 1-idx;
    }
    printf("%d %d\n",sum[0],sum[1]);
    return 0;
}