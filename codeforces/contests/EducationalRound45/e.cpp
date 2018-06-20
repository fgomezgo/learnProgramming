#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int block[1000005];
int nb[1000005];
int pw[1000005];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < m; ++i)
        scanf("%d", &block[i]);
    if(m != 0 && block[0] == 0){
        puts("-1");
        return 0;
    }
    nb[0] = 0;
    int idx = 0;
    int pos = 0;
    for(int i = 0; i < m; ++i){
        for(int j = pos+1; j < block[i]; ++j){
            if(nb[j] == 0){
                nb[j] = j;
                idx = j;
            }
            pos = j;
        }
        nb[block[i]] = idx;
        ++pos;
    }
    for(int i = (m==0)?0:block[m-1]+1; i < n; ++i)
        nb[i] = i;

    for(int i = 0 ; i < k; ++i)
        scanf("%d", &pw[i]);
    long long ans = LLONG_MAX;
    for(int mid = 1; mid <= k; ++mid){
        bool fl = true;
        int cont = 0;
        for(int i = 0; i < n; ++i){
            if(nb[i] == i){
                i += mid;
                --i;
                ++cont;
                continue;
            }
            if(nb[i] == -1){
                fl = false;
                break;
            }
            int tmpi = nb[i];
            tmpi += mid;
            --tmpi;
            if(tmpi+1 <= i){
                fl = false;
                break;
            }
            i = tmpi;
            ++cont;
        }
        if(fl) ans = min(ans,(long long)cont*pw[mid-1]);
    }
    if(ans == LLONG_MAX)
        puts("-1");
    else
        printf("%lld\n",ans);


    return 0;
}