#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,k;
int arr[N];

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++i){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int tot = n;
    for(int i = 0; i < n; ++i){
        int ini = i+1, fin = n-1, mid, sol = -1;
        while(ini <= fin){
            int mid = (ini+fin)>>1;
            if(arr[mid] > arr[i]){
                fin = mid-1;
                sol = mid;
            } else
                ini = mid+1;
        }
        if(sol != -1 && arr[sol] <= arr[i]+k) --tot;
    }
    printf("%d\n",tot);


    return 0;
}