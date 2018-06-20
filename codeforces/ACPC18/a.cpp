#include<bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

pair< pair<int,int>,int > arr[100005];
long long dp[100005];
int m,k;

int LB(int pos){
    int ini = 1, fin = m, mid, sol = -1;
    while(ini <= fin){
        mid = (ini+fin)>>1;
        if(arr[mid].fst.fst <= pos){
            sol = mid;
            ini = mid+1;
        } else
            fin = mid-1;
    }
    return sol;
}

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&m,&k);
        int l,r,v;
        long long ans = 0;
        for(int i = 1; i <= m; ++i){
            scanf("%d%d%d",&l,&r,&v);
            arr[i] = {{l,r},v};
            dp[i] = dp[i-1]+(long long)(r-l+1)*(long long)v;
        }
        sort(arr+1,arr+m+1);
        //segment end
        for(int i = 1; i <= m; ++i){
            int pos = arr[i].fst.snd-k+1;
            int tmp = LB(pos);
            if(tmp == -1)
                ans = max(ans,dp[i]);
            else
                ans = max(ans,dp[i]-dp[tmp-1]-((long long)min(pos-arr[tmp].fst.fst,arr[tmp].fst.snd-arr[tmp].fst.fst+1))*(long long)arr[tmp].snd);
        }
        //segment begin
        for(int i = 1; i <= m; ++i){
            int pos = arr[i].fst.fst+k-1;
            int tmp = LB(pos);
            ans = max(ans,dp[tmp]-dp[i-1]-max((long long)(arr[tmp].fst.snd-pos)*(long long)arr[tmp].snd,0LL));
        }
        printf("%lld\n",ans);
    }

    return 0;
}