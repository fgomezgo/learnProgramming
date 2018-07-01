#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool mark[10];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i)
        scanf("%d",&arr[i]);
    int num;
    for(int i = 0; i < m; ++i){
        scanf("%d", &num);
        mark[num] = true;
    }
    for(int i = 0; i < n; ++i)
        if(mark[arr[i]])
            printf("%d ",arr[i]);
    puts("");
    return 0;
}