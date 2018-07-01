#include<bits/stdc++.h>
using namespace std;

int n,q;
double tree[100005];
double arr[100005];

double read(int idx){
    double sum = 0.0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx&-idx);
    }
    return sum;
}
void update(int idx, double val){
    while(idx <= n){
        tree[idx] += val;
        idx += (idx&-idx);
    }
}

int main(){
    scanf("%d",&n);
    double tmp;
    for(int i = 1; i <= n; ++i){
        scanf("%lf",&arr[i]);
        update(i,arr[i]);
    }
    scanf("%d",&q);
    int type, e;
    double v;
    int l,r;
    while(q--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d%lf",&e,&v);
            update(e,-arr[e]);
            arr[e] = v;
            update(e,arr[e]);
        } else{
            scanf("%d%d",&l,&r);
            double sum = read(r)-read(l-1);
            printf("%.8lf\n",sum/(double)(r-l+1));
        }
    }

    return 0;
}

